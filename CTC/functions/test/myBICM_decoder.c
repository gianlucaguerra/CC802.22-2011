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

/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    
    /* VARIABLES DECLARATIONS */    
    int *u_hat;                          /* decoded output */
    
    double complex *r;                   /* received sequence */
    int M;                               /* number of constellation symbols */
    double sigma_w;                      /* variance of the noise */
    double complex *constellation_table; /* constellation fo the modulation */
    int codeword_length;                 /* Length of the codeword */
    int N;                               /* Number of input pairs at decoder */
    int *conform_table;                  /* Conform table to solve the w nodes */ 
    int *bit_p_table;                    /* Array for the de-interleaving */
    int *puncturing_pattern;             /* puncturing_pattern od the code */
    int *output_table;                   /* output table for the crsc code */
    int *state_update_table;             /* state update table for the crsc code */
    int *neighbours_table;               /* neighbours table fot the crsac code */
    int *p_input_table;                  /* Intra-pair CTC de-interleaver */
    int *p_step_table;                   /* Inter-pait CTC de-interleaver */
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
    n_it = mxGetScalar(prhs[13]);
    
    int r_length = codeword_length/log2(M);
    
    
    /* MESSAGE PASSING DECODING ALGORITHM */
    /* 1. INITIALIZATION  */
    /* 1.1 The q vector is initialized to the a priori probability */
    double q[(int)pow(2,crsc_k)][N];
    double max; 
    int l;
    int u;
    for(l = 0; l < r_length; l = l + 1 ){
        max = -DBL_MAX;
        for(u = 0; u <= 4; u = u + 1){
            q[u][l]=1/pow(2, crsc_k);
            if (q[u][l] > max){
                max = q[u][l];
            }
        }
        for(u = 0; u <= 4; u = u + 1){
            q[u][l] = q[u][l] - max;
        }
    }
    
    /* 1.2 The g vector is initialized using the received symbol sequence */
    double g[M][r_length];
    
    
    
}
