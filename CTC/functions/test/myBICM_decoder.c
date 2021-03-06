/*==========================================================
 * BICM_decoder.c 
 *
 * This is a MEX-file for MATLAB.
 * Copyright 2007-2012 The MathWorks, Inc.
 *
 *========================================================*/

#include "mex.h"
#include <complex.h>    /* Standard Library of Complex Numbers */
#include <math.h>
#include <float.h>
#include "matrix.h"

/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    if (nrhs != 15){
        mexErrMsgTxt("One input required.");
    }
    
    /* VARIABLES DECLARATIONS */    
    double complex *r;                   /* received sequence */
    int M;                               /* number of constellation symbols */
    double sigma_w;                      /* variance of the noise */
    double complex *constellation_table; /* constellation fo the modulation */
    int codeword_length;                 /* Length of the codeword */
    int N;                               /* Number of input pairs at decoder */
    int **conform_table;                  /* Conform table to solve the w nodes */ 
    int *bit_p_table;                    /* Array for the de-interleaving */
    int *puncturing_pattern;             /* puncturing_pattern od the code */
    int **output_table;                   /* output table for the crsc code */
    int **state_update_table;             /* state update table for the crsc code */
    int **neighbours_table;               /* neighbours table fot the crsac code */
    int **p_input_table;                  /* Intra-pair CTC de-interleaver */
    int **p_step_table;                   /* Inter-pait CTC de-interleaver */
    int n_it;                            /* Number of iteration for the decoding */
            
    /* CRSC CODE CONSTANTS DEFINITION */
    static const int crsc_k = 2;
    static const int crsc_n = 3;
    static const int crsc_v = 3;
    
    /* VARIABLES INITIALIZATION */
    r = mxGetData(prhs[0]);
    M = mxGetScalar(prhs[1]);
    sigma_w = mxGetScalar(prhs[2]);
    constellation_table = mxGetData(prhs[3]);
    codeword_length = mxGetScalar(prhs[4]);
    N = mxGetScalar(prhs[5]);
    conform_table = mxGetData(prhs[6]);
    bit_p_table = mxGetData(prhs[7]);
    puncturing_pattern = mxGetData(prhs[8]);
    output_table = mxGetData(prhs[9]);
    state_update_table = mxGetData(prhs[10]);
    neighbours_table = mxGetData(prhs[11]);
    p_input_table = mxGetData(prhs[12]);
    p_step_table = mxGetData(prhs[13]);
    n_it = mxGetScalar(prhs[14]);
    
    int r_length = codeword_length/log2(M);
    int puncturing_length = mxGetN(prhs[8]);
    
    int con_col = mxGetN(prhs[6]);
    int out_col = mxGetN(prhs[9]);
    int state_col = mxGetN(prhs[10]);
    int neigh_col = mxGetN(prhs[11]);
    int input_col = mxGetN(prhs[12]);
    int step_col = mxGetN(prhs[13]);
    
    
    
    
    
    
    
    
    
    /* OUTPUT VARIABLE */
    plhs[0] = mxCreateDoubleMatrix((mwSize)crsc_k*N,1,mxREAL);
    double *u_hat = mxGetPr(plhs[0]);
    
    
    /* MESSAGE PASSING DECODING ALGORITHM */
    /* 1. INITIALIZATION  */
    /* 1.1 The q vector is initialized to the a priori probability */
    double q[(int)pow(2,crsc_k)][N];
    double max; 
    int l;
    int u;
    for (l = 0; l < N; l = l + 1){
        max = -DBL_MAX;
        for(u = 0; u <= 3; u = u + 1){
            q[u][l]=log(1/pow(2, crsc_k));
            if (q[u][l] > max){
                max = q[u][l];
            }
        }
        for(u = 0; u <= 3; u = u + 1){
            q[u][l] = q[u][l] - max;
        }
    }
    
    /* 1.2 The g vector is initialized using the received symbol sequence */
    double g[M][r_length];
    double value;
    int s;
    for (l = 0; l < r_length; l = l+1){
        max = -DBL_MAX;
        for (s = 0; s < M; s = s + 1){
            value = pow(cabs(r[l]-constellation_table[s]),2);
            value = -value/(2*pow(sigma_w,2));
            g[s][l] = value;
            if (g[s][l] > max){
                max = g[s][l];
            }
        }
        for (s = 0; s < M; s = s + 1){
            g[s][l] = g[s][l] - max;
        }
    }
    
    /* 1.3 Output message from the conform node to the BICM interleaver and
           viceversa */
    double mu_w2d[2][codeword_length];
    double mu_d2w[2][codeword_length];
    /* mu_d2w initialization */
    for (l = 0; l < codeword_length; l = l + 1){
        max = -DBL_MAX;
        for(u = 0; u <= 1; u = u + 1){
            mu_d2w[u][l]=log(1/2);
            if (mu_d2w[u][l] > max){
                max = mu_d2w[u][l];
            }
        }
        for(u = 0; u <= 1; u = u + 1){
            mu_d2w[u][l] = mu_d2w[u][l] - max;
        }
    }
    
    /* 2. CONFORM NODE EVALUATION */
    double input_msg[2][(int)log2(M)-1];
    int index;
    int index1;
    int index2;
    int d;
    int i;
    int m;
    double add;
    double summ;
    for (l = 0; l < r_length; l = l + 1){
        for (m = 0; m < log2(M); m = m + 1){
            index1 = 0;
            for (index = 0; index < log2(M); index = index + 1){
                if (index != m){
                    input_msg[0][index1]=mu_d2w[0][l*(int)log2(M)+index];
                    input_msg[1][index1]=mu_d2w[1][l*(int)log2(M)+index];
                    index1 = index1 + 1;        
                }                
            }
            for (d = 0; d<=1; d = d + 1){
                summ = -DBL_MAX;
                for (i = 0; i < M/2; i = i + 1){
                    index = conform_table[(2*m+d)+con_col*i];
                    add = g[index][l];
                    for (index1 = (int)log2(M) - 2; index1 >= 0; index1 = index1 -1 ){
                        index2 = ((int)(i/pow(2,index1))) % 2;
                        add = add + input_msg[index2][(int)log2(M)-index1];
                    }
                   summ = log(exp(summ)+exp(add));
                }
               index = bit_p_table[(int)(l*log2(M))+m];
               mexPrintf("%d\n", index);
               mu_w2d[d][index] = summ;            
            } /* normalization */
          /*  if (mu_w2d[0][bit_p_table[(int)(l*log2(M))+m]]>=mu_w2d[1][bit_p_table[(int)(l*log2(M))+m]]){
                mu_w2d[0][bit_p_table[(int)(l*log2(M))+m]] = 0;
                mu_w2d[1][bit_p_table[(int)(l*log2(M))+m]] = mu_w2d[1][bit_p_table[(int)(l*log2(M))+m]] - mu_w2d[0][bit_p_table[(int)(l*log2(M))+m]];
            }else{
                mu_w2d[1][bit_p_table[(int)(l*log2(M))+m]] = 0;
                mu_w2d[0][bit_p_table[(int)(l*log2(M))+m]] = mu_w2d[0][bit_p_table[(int)(l*log2(M))+m]] - mu_w2d[1][bit_p_table[(int)(l*log2(M))+m]];
            }*/
        }
    }
    
    /* 3 SISTEMATIC PART, CODE1 OUTPUT, CODE2 OUTPUT and DEPUNCTURING */
/*    double systematic_out1[2][crsc_n*N];
    double out2[2][(crsc_n-crsc_k)*N];
    int index3 = 0;
    index = 0;
    index1 = 0;
    index2 = 0;
    while (index <= puncturing_length - 4){
        systematic_out1[0][index1] = mu_w2d[0][index2];
        systematic_out1[1][index1] = mu_w2d[1][index2];
        systematic_out1[0][index1+1] = mu_w2d[0][index2+1];
        systematic_out1[1][index1+1] = mu_w2d[1][index2+1];
        if(puncturing_pattern[index+2] == 0){
            systematic_out1[0][index1+2] = 0;
            systematic_out1[1][index1+2] = 0;
            out2[0][index3] = 0;
            out2[1][index3] = 0;
            index2 = index2 + 2;
        }else{
            systematic_out1[0][index1+2] = mu_w2d[0][index2+2];
            systematic_out1[1][index1+2] = mu_w2d[1][index2+2];
            out2[0][index3] = mu_w2d[0][index2+3];
            out2[1][index3] = mu_w2d[1][index2+3];
            index2 = index2 + 4;
        }
        index = index + 4;
        index1 = index1 + 3;
        index3 = index3 + 1;
    }
    
    /* 4. ALPHA NODES EVALUATION */
/*    int y;
    double mu_alpha2y[(int)pow(2, crsc_n)][N];
    for (l = 0; l < N; l = l + 1){
        for (y = 0; y < (int)pow(2, crsc_n); y = y +1){
            for (index1 = crsc_n-1; index1 >= 0; index1 = index1 -1 ){
                index2 = ((int)(i/pow(2,index1))) % 2;
                mu_alpha2y[y][l] = mu_alpha2y[y][l] + systematic_out1[index2][crsc_n*l+crsc_n-index1-1];
            }
        }
    }
    
    /* 5. BCJR ALGORITHM ON THE UPPER CODE */
    /* 5.0 BCJR ALGORITHM INITIALIZATION */
 /*   double E2[(int)pow(2, crsc_k)][N];
    double E1[(int)pow(2, crsc_k)][N];
    for (index = 0; index < N; index = index + 1){
        for (index1 = 0; index1 < (int)pow(2, crsc_k); index1 = index1 + 1){
            E2[index1][index] = 0;
            E1[index1][index] = 0;
        }
    }
    double backward_matrix[(int)pow(2, crsc_v)][N];
    double forward_matrix[(int)pow(2, crsc_v)][N];
    double extrinsic_matrix[(int)pow(2, crsc_k)][N];
    double mu_eq[(int)pow(2, crsc_k)][N];
    
 /* FOR LOOP OVER THE DECODING ITERATIONS */
  /*  int cont;
    double ql_u;
    double gl_y;
    int s_n;
    double B_n;
    int u_p;
    double F_p;
    int s_p;
    int p_step;
    int p_input;
    
    for (cont = 1; cont <= n_it; cont = cont + 1){
        /* initialization of back, forw, ext and mu_eq */
   /*     for (index = 0; index < N; index = index + 1){
            for (index1 = 0; index1 < (int)pow(2, crsc_v); index1 = index1 + 1){
                backward_matrix[index1][index] = -DBL_MAX;
                forward_matrix[index1][index] = -DBL_MAX;
            }
            max = -DBL_MAX;
            for (index1 = 0; index1 < (int)pow(2, crsc_k); index1 = index1 + 1){
                extrinsic_matrix[index1][index] = -DBL_MAX;
                mu_eq[index1][index] = q[index1][index] + E2[index1][index];
                if (mu_eq[index1][index] > max){
                    max = mu_eq[index1][index];
                }
            }
            for (index1 = 0; index1 < (int)pow(2, crsc_k); index1 = index1 + 1){
                mu_eq[index1][index] = mu_eq[index1][index] - max;
            }            
        } 
        /* 5.1 BACKWARD MESSAGES UPDATE */
   /*     backward_matrix[0][N-1] = 0;
        for (l = 2*N-1; l > 0; l = l-1){
            index = l % N;
            if (index == 0){
                    index2 = N;
            }else{
                    index2 = index;
            }
            max = -DBL_MAX;
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                summ = -DBL_MAX;
                for (u = 0; u < (int)pow(2, crsc_k); u = u + 1){
                  ql_u = mu_eq[u][index];
                  y = output_table[s][u];
                  gl_y = mu_alpha2y[y][index];
                  s_n = state_update_table[s][u];
                  B_n = backward_matrix[s_n][index];
                  add = B_n + gl_y + ql_u;
                  summ = log(exp(summ)+exp(add));
                }
                backward_matrix[s][index2 - 1] = summ;
                if (summ > max){
                    max = summ;
                }
            }
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                backward_matrix[s][index2] = backward_matrix[s][index2] - max; 
            }
        }
        
        /* 5.2 FORWARD MESSAGES UPDATE */
   /*     forward_matrix[0][0] = 0;
        for (l = 1; l < 2*N; l = l + 1 ){
            index = l % N;
            if (index == 0){
                index2 = N;
            }else{
                index2 = index;
            }
            max = -DBL_MAX;
            for (s = 0; s < (int)pow(2,crsc_v); s = s + 1){
                summ = -DBL_MAX;
                for (u_p = 0; u_p < (int)pow(2,crsc_k); u_p = u_p + 1){
                    ql_u = mu_eq[u_p][index2-1];
                    s_p = neighbours_table[s][u_p];
                    y = output_table[s_p][u_p];
                    gl_y = mu_alpha2y[y][index2-1];
                    F_p = forward_matrix[s_p][index2-1];
                    add = F_p + gl_y + ql_u;
                    summ = log(exp(summ)+exp(add));
                }
                forward_matrix[s][index] = summ;
                if (summ > max){
                    max = summ;
                }
            }
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                forward_matrix[s][index] = forward_matrix[s][index] - max; 
            }
        }
        
        /* 5.3 EXTRINSIC MESSAGES UPDATE */
   /*     for (l = 0; l < N; l = l + 1 ){
            max = -DBL_MAX;
            for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
                summ = -DBL_MAX;
                for (s = 0; s < (int)pow(2,crsc_v); s = s + 1){
                    s_n = state_update_table[s][u];
                    y = output_table[s][u];
                    gl_y = mu_alpha2y[y][l];
                    F_p = forward_matrix[s][l];
                    B_n = backward_matrix[s][l];
                    add = F_p + B_n + gl_y;
                    summ = log(exp(summ)+exp(add));
                }
                extrinsic_matrix[u][l] = summ;
                mu_eq[u][l] = extrinsic_matrix[u][l] + q[u][l];
                if (mu_eq[u][l] > max){
                    max = mu_eq[u][l];
                }
            }
            for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
                mu_eq[u][l] = mu_eq[u][l] - max;
            }
        }
        
       
        /* 6. BCJR ALGORITHM ON THE LOWER CODE */
        /* initialization of back, forw, ext */
   /*     for (index = 0; index < N; index = index + 1){
            for (index1 = 0; index1 < (int)pow(2, crsc_v); index1 = index1 + 1){
                backward_matrix[index1][index] = -DBL_MAX;
                forward_matrix[index1][index] = -DBL_MAX;
            }
            for (index1 = 0; index1 < (int)pow(2, crsc_k); index1 = index1 + 1){
                extrinsic_matrix[index1][index] = -DBL_MAX;
            }                              
        }
        
        /* 6.1 BACKWARD MESSAGES UPDATE */
  /*      backward_matrix[0][N-1] = 0;
        for (l = 2*N-1; l > 0; l = l-1){
            index = l % N;
            if (index == 0){
                    index2 = N;
            }else{
                    index2 = index;
            }
            max = -DBL_MAX;
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                summ = -DBL_MAX;
                for (u = 0; u < (int)pow(2, crsc_k); u = u + 1){
                  p_step = p_input_table[u][index];
                  p_input = p_step_table[u][index];
                  ql_u = mu_eq[p_input][p_step];
                  y = (output_table[s][u]) % 2;
                  gl_y = out2[y][index];
                  s_n = state_update_table[s][u];
                  B_n = backward_matrix[s_n][index];
                  add = B_n + gl_y + ql_u;
                  summ = log(exp(summ)+exp(add));
                }
                backward_matrix[s][index2 - 1] = summ;
                if (summ > max){
                    max = summ;
                }
            }
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                backward_matrix[s][index2] = backward_matrix[s][index2] - max; 
            }
        }
        
        /* 6.2 FORWARD MESSAGE UPDATE */
  /*      forward_matrix[0][0] = 0;
        for (l = 1; l < 2*N; l = l + 1 ){
            index = l % N;
            if (index == 0){
                index2 = N;
            }else{
                index2 = index;
            }
            max = -DBL_MAX;
            for (s = 0; s < (int)pow(2,crsc_v); s = s + 1){
                summ = -DBL_MAX;
                for (u_p = 0; u_p < (int)pow(2,crsc_k); u_p = u_p + 1){
                    p_step = p_input_table[u][index2-1];
                    p_input = p_step_table[u][index2-1];
                    ql_u = mu_eq[p_input][p_step];
                    s_p = neighbours_table[s][u_p];
                    y = (output_table[s_p][u_p]) % 2;
                    gl_y = out2[y][index2-1];
                    F_p = forward_matrix[s_p][index2-1];
                    add = F_p + gl_y + ql_u;
                    summ = log(exp(summ)+exp(add));
                }
                forward_matrix[s][index] = summ;
                if (summ > max){
                    max = summ;
                }
            }
            for (s = 0; s < (int)pow(2,crsc_k); s = s + 1){
                forward_matrix[s][index] = forward_matrix[s][index] - max; 
            }
        }
        
        /* 6.3 EXTRINSIC MESSAGE UPDATE */
  /*      for (l = 0; l < N; l = l + 1 ){
            for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
                summ = -DBL_MAX;
                for (s = 0; s < (int)pow(2,crsc_v); s = s + 1){
                    s_n = state_update_table[s][u];
                    y = (output_table[s][u]) % 2;
                    gl_y = out2[y][l];
                    F_p = forward_matrix[s][l];
                    B_n = backward_matrix[s][l];
                    add = F_p + B_n + gl_y;
                    summ = log(exp(summ)+exp(add));
                }
                p_step = p_input_table[u][l];
                p_input = p_step_table[u][l];
                extrinsic_matrix[p_input][p_step] = summ;
            }            
        }
        
          
        for (l = 0; l < N; l = l + 1){
            max = -DBL_MAX;
            for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
                if (extrinsic_matrix[u][l] > max){
                    max = extrinsic_matrix[u][l];
                }
            }
            for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
                E2[u][l] = extrinsic_matrix[u][l] - max;
            }
        }        
    } /* END FOR LOOP */
    
    /* "MAP" ESTIMATE */
  /*  index = 0;
    double LLR[(int)pow(2,crsc_k)][N];
    int u_hat_num = -1;
    for (l = 0; l < N; l = l + 1 ){
        max = -DBL_MAX;
        u_hat_num = -1;
        for (u = 0; u < (int)pow(2,crsc_k); u = u + 1){
            LLR[u][l] = E2[u][l] + E1[u][l] + q[u][l];
            if (LLR[u][l] > max){
                max = LLR[u][l];
                u_hat_num = u;
            }
        }
        if (u_hat_num == 0){
            u_hat[index] = 0;
            u_hat[index+1] = 0;
        }
        if (u_hat_num == 1){
            u_hat[index] = 0;
            u_hat[index+1] = 1;
        }
        if (u_hat_num == 2){
            u_hat[index] = 1;
            u_hat[index+1] = 0;
        }
        if (u_hat_num == 3){
            u_hat[index] = 1;
            u_hat[index+1] = 1;
        } 
        index = index + 2;
    }
    
    
    
    
    */
    
}    