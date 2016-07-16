/*
 * File: CTC_dec_p.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "sum.h"
#include "power.h"
#include "abs.h"
#include "mod.h"
#include "bsxfun.h"
#include "CTC_dec_p_emxutil.h"
#include "fix.h"
#include "log.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * CTC_DECODER: Basic CTC decoding through message passing
 * Arguments    : const double r_data[]
 *                const int r_size[1]
 *                const double state_update_table[32]
 *                const double output_table[32]
 *                const double neighbours_table[32]
 *                const double modulation_table[24]
 *                double sigma_w
 *                double N
 *                double n_it
 *                const double p_input_table_data[]
 *                const int p_input_table_size[2]
 *                const double p_step_table_data[]
 *                const int p_step_table_size[2]
 *                const double puncturing_pattern_data[]
 *                const int puncturing_pattern_size[1]
 *                emxArray_real_T *u_hat
 * Return Type  : void
 */
void CTC_dec_p(const double r_data[], const int r_size[1], const double
               state_update_table[32], const double output_table[32], const
               double neighbours_table[32], const double modulation_table[24],
               double sigma_w, double N, double n_it, const double
               p_input_table_data[], const int p_input_table_size[2], const
               double p_step_table_data[], const int p_step_table_size[2], const
               double puncturing_pattern_data[], const int
               puncturing_pattern_size[1], emxArray_real_T *u_hat)
{
  emxArray_real_T *r_dep;
  int iy;
  int itmp;
  double index_r;
  double index_p;
  int i;
  int j;
  emxArray_real_T *r0;
  emxArray_real_T *q;
  emxArray_real_T *maxval;
  int ix;
  int b_ix;
  double mtmp;
  int c_ix;
  boolean_T exitg12;
  emxArray_real_T *b_q;
  emxArray_real_T *g1;
  emxArray_real_T *g2;
  emxArray_real_T *r1;
  int cindx;
  emxArray_real_T *r2;
  int l;
  int y;
  double mod_y[3];
  double b_r1[3];
  double dv0[3];
  double dv1[3];
  boolean_T exitg11;
  emxArray_real_T *b_g1;
  boolean_T exitg10;
  emxArray_real_T *b_g2;
  emxArray_real_T *E2;
  emxArray_real_T *E1;
  int cont;
  emxArray_real_T *backward_matrix;
  emxArray_real_T *forward_matrix;
  emxArray_real_T *extrinsic_matrix;
  emxArray_real_T *b_E2;
  emxArray_real_T *c_E2;
  boolean_T exitg9;
  double d0;
  double b_index;
  int s;
  double summ;
  int u;
  double index2;
  boolean_T exitg8;
  int u_p;
  boolean_T exitg7;
  double index_b;
  double index_f;
  boolean_T exitg6;
  boolean_T exitg5;
  boolean_T exitg4;
  boolean_T exitg3;
  boolean_T exitg2;
  unsigned int uv0[2];
  emxArray_int32_T *indx;
  boolean_T exitg1;
  (void)r_size;
  (void)puncturing_pattern_size;
  emxInit_real_T(&r_dep, 2);

  /*  CRSC code component params */
  /* crsc_k = size(CRSC.P,2); */
  /* crsc_n = size(CRSC.P,1); */
  /* crsc_v = length(CRSC.G); */
  /*    piece_const = log(1+exp(-(0:5)));% TO IMPLEMENT AND SEE THE DIFFERENCE! */
  /*  De-puncturing of the received sequence in a N x (2n-k) matrix */
  iy = r_dep->size[0] * r_dep->size[1];
  r_dep->size[0] = (int)N;
  r_dep->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)r_dep, iy, (int)sizeof(double));
  itmp = (int)N << 2;
  for (iy = 0; iy < itmp; iy++) {
    r_dep->data[iy] = 0.0;
  }

  index_r = 0.0;
  index_p = 0.0;
  for (i = 0; i < (int)((N - 1.0) + 1.0); i++) {
    for (j = 0; j < 4; j++) {
      if (puncturing_pattern_data[(int)(index_p + 1.0) - 1] == 1.0) {
        r_dep->data[i + r_dep->size[0] * j] = r_data[(int)(index_r + 1.0) - 1];
        index_r++;
      } else {
        r_dep->data[i + r_dep->size[0] * j] = 0.0;
      }

      index_p++;
    }
  }

  emxInit_real_T(&r0, 2);

  /*  MESSAGE PASSING DECODING ALGORITHM */
  /*  1. INITIALIZATION */
  /*  1.1 The q vector is initialized to the a priori probability, */
  iy = r0->size[0] * r0->size[1];
  r0->size[0] = 4;
  r0->size[1] = (int)N;
  emxEnsureCapacity((emxArray__common *)r0, iy, (int)sizeof(double));
  itmp = (int)N << 2;
  for (iy = 0; iy < itmp; iy++) {
    r0->data[iy] = 1.0;
  }

  emxInit_real_T(&q, 2);
  emxInit_real_T(&maxval, 2);
  rdivide(r0, q);
  b_log(q);

  /*  Row: input  | Column: step l */
  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = q->size[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
  ix = 4;
  iy = -1;
  i = 1;
  emxFree_real_T(&r0);
  while (i <= q->size[1]) {
    b_ix = ix - 3;
    mtmp = q->data[ix - 4];
    if (rtIsNaN(q->data[ix - 4])) {
      c_ix = ix - 2;
      exitg12 = false;
      while ((!exitg12) && (c_ix <= ix)) {
        b_ix = c_ix;
        if (!rtIsNaN(q->data[c_ix - 1])) {
          mtmp = q->data[c_ix - 1];
          exitg12 = true;
        } else {
          c_ix++;
        }
      }
    }

    if (b_ix < ix) {
      while (b_ix + 1 <= ix) {
        if (q->data[b_ix] > mtmp) {
          mtmp = q->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += 4;
    i++;
  }

  emxInit_real_T(&b_q, 2);
  iy = b_q->size[0] * b_q->size[1];
  b_q->size[0] = 4;
  b_q->size[1] = q->size[1];
  emxEnsureCapacity((emxArray__common *)b_q, iy, (int)sizeof(double));
  itmp = q->size[0] * q->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_q->data[iy] = q->data[iy];
  }

  emxInit_real_T(&g1, 2);
  bsxfun(b_q, maxval, q);

  /*  Normalization */
  /*  1.2 Two g vectors: g1 for the upper code and g2 for the lower one */
  iy = g1->size[0] * g1->size[1];
  g1->size[0] = 8;
  g1->size[1] = (int)N;
  emxEnsureCapacity((emxArray__common *)g1, iy, (int)sizeof(double));
  itmp = (int)N << 3;
  emxFree_real_T(&b_q);
  for (iy = 0; iy < itmp; iy++) {
    g1->data[iy] = 0.0;
  }

  emxInit_real_T(&g2, 2);

  /*  Row: output | Column: step l in blocks */
  iy = g2->size[0] * g2->size[1];
  g2->size[0] = 8;
  g2->size[1] = (int)N;
  emxEnsureCapacity((emxArray__common *)g2, iy, (int)sizeof(double));
  itmp = (int)N << 3;
  for (iy = 0; iy < itmp; iy++) {
    g2->data[iy] = 0.0;
  }

  emxInit_real_T(&r1, 2);

  /*  Row: output | Column: step l in blocks    */
  /*  To compute g2 we use must rebuild the part due to the lower encoder */
  /*  using the inverse of the permutation matrix P^-1 = P^T */
  itmp = r_dep->size[0];
  iy = r1->size[0] * r1->size[1];
  r1->size[0] = itmp;
  r1->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)r1, iy, (int)sizeof(double));
  for (iy = 0; iy < 3; iy++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      r1->data[cindx + r1->size[0] * iy] = r_dep->data[cindx + r_dep->size[0] *
        iy];
    }
  }

  emxInit_real_T1(&r2, 1);

  /* r2 = [reshape(P*(reshape(r_dep(:,[1,2]).', 1,[]).'),2,[]).',r_dep(:, crsc_n+1:end)]; */
  itmp = r_dep->size[0];
  iy = r2->size[0];
  r2->size[0] = itmp;
  emxEnsureCapacity((emxArray__common *)r2, iy, (int)sizeof(double));
  for (iy = 0; iy < itmp; iy++) {
    r2->data[iy] = r_dep->data[iy + r_dep->size[0] * 3];
  }

  for (l = 0; l < (int)((N - 1.0) + 1.0); l++) {
    for (y = 0; y < 8; y++) {
      mtmp = (double)l * 4.0;
      for (iy = 0; iy < 3; iy++) {
        mod_y[iy] = modulation_table[y + (iy << 3)] * puncturing_pattern_data
          [(int)(mtmp + (1.0 + (double)iy)) - 1];
      }

      for (iy = 0; iy < 3; iy++) {
        b_r1[iy] = r1->data[l + r1->size[0] * iy] - mod_y[iy];
      }

      b_abs(b_r1, dv0);
      power(dv0, dv1);
      g1->data[y + g1->size[0] * l] = sum(dv1);
      mtmp = fabs(r2->data[l] - mod_y[2]);
      g2->data[y + g2->size[0] * l] = mtmp * mtmp;
    }
  }

  emxFree_real_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&r_dep);
  mtmp = -1.0 / (2.0 * (sigma_w * sigma_w));
  iy = g1->size[0] * g1->size[1];
  g1->size[0] = 8;
  emxEnsureCapacity((emxArray__common *)g1, iy, (int)sizeof(double));
  cindx = g1->size[0];
  itmp = g1->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    g1->data[iy] *= mtmp;
  }

  mtmp = -1.0 / (2.0 * (sigma_w * sigma_w));
  iy = g2->size[0] * g2->size[1];
  g2->size[0] = 8;
  emxEnsureCapacity((emxArray__common *)g2, iy, (int)sizeof(double));
  cindx = g2->size[0];
  itmp = g2->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    g2->data[iy] *= mtmp;
  }

  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = g1->size[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
  ix = 8;
  iy = -1;
  for (i = 1; i <= g1->size[1]; i++) {
    b_ix = ix - 7;
    mtmp = g1->data[ix - 8];
    if (rtIsNaN(g1->data[ix - 8])) {
      c_ix = ix - 6;
      exitg11 = false;
      while ((!exitg11) && (c_ix <= ix)) {
        b_ix = c_ix;
        if (!rtIsNaN(g1->data[c_ix - 1])) {
          mtmp = g1->data[c_ix - 1];
          exitg11 = true;
        } else {
          c_ix++;
        }
      }
    }

    if (b_ix < ix) {
      while (b_ix + 1 <= ix) {
        if (g1->data[b_ix] > mtmp) {
          mtmp = g1->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += 8;
  }

  emxInit_real_T(&b_g1, 2);
  iy = b_g1->size[0] * b_g1->size[1];
  b_g1->size[0] = 8;
  b_g1->size[1] = g1->size[1];
  emxEnsureCapacity((emxArray__common *)b_g1, iy, (int)sizeof(double));
  itmp = g1->size[0] * g1->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_g1->data[iy] = g1->data[iy];
  }

  b_bsxfun(b_g1, maxval, g1);

  /*  Normalization */
  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = g2->size[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
  ix = 8;
  iy = -1;
  i = 1;
  emxFree_real_T(&b_g1);
  while (i <= g2->size[1]) {
    b_ix = ix - 7;
    mtmp = g2->data[ix - 8];
    if (rtIsNaN(g2->data[ix - 8])) {
      c_ix = ix - 6;
      exitg10 = false;
      while ((!exitg10) && (c_ix <= ix)) {
        b_ix = c_ix;
        if (!rtIsNaN(g2->data[c_ix - 1])) {
          mtmp = g2->data[c_ix - 1];
          exitg10 = true;
        } else {
          c_ix++;
        }
      }
    }

    if (b_ix < ix) {
      while (b_ix + 1 <= ix) {
        if (g2->data[b_ix] > mtmp) {
          mtmp = g2->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    maxval->data[iy] = mtmp;
    ix += 8;
    i++;
  }

  emxInit_real_T(&b_g2, 2);
  iy = b_g2->size[0] * b_g2->size[1];
  b_g2->size[0] = 8;
  b_g2->size[1] = g2->size[1];
  emxEnsureCapacity((emxArray__common *)b_g2, iy, (int)sizeof(double));
  itmp = g2->size[0] * g2->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_g2->data[iy] = g2->data[iy];
  }

  emxInit_real_T(&E2, 2);
  b_bsxfun(b_g2, maxval, g2);

  /*  Normalization */
  iy = E2->size[0] * E2->size[1];
  E2->size[0] = 4;
  E2->size[1] = (int)N;
  emxEnsureCapacity((emxArray__common *)E2, iy, (int)sizeof(double));
  itmp = (int)N << 2;
  emxFree_real_T(&b_g2);
  for (iy = 0; iy < itmp; iy++) {
    E2->data[iy] = 0.0;
  }

  emxInit_real_T(&E1, 2);
  iy = E1->size[0] * E1->size[1];
  E1->size[0] = 4;
  E1->size[1] = (int)N;
  emxEnsureCapacity((emxArray__common *)E1, iy, (int)sizeof(double));
  itmp = (int)N << 2;
  for (iy = 0; iy < itmp; iy++) {
    E1->data[iy] = 0.0;
  }

  cont = 0;
  emxInit_real_T(&backward_matrix, 2);
  emxInit_real_T(&forward_matrix, 2);
  emxInit_real_T(&extrinsic_matrix, 2);
  emxInit_real_T(&b_E2, 2);
  emxInit_real_T(&c_E2, 2);
  while (cont <= (int)n_it - 1) {
    /*  2 BCJR ALGORITHM ON THE UPPER CODE */
    /*  2.0 BCJR initialization  */
    iy = backward_matrix->size[0] * backward_matrix->size[1];
    backward_matrix->size[0] = 8;
    backward_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)backward_matrix, iy, (int)sizeof
                      (double));
    itmp = (int)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      backward_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: state  | Column: step l */
    iy = forward_matrix->size[0] * forward_matrix->size[1];
    forward_matrix->size[0] = 8;
    forward_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)forward_matrix, iy, (int)sizeof(double));
    itmp = (int)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      forward_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: state  | Column: step l */
    iy = extrinsic_matrix->size[0] * extrinsic_matrix->size[1];
    extrinsic_matrix->size[0] = 4;
    extrinsic_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)extrinsic_matrix, iy, (int)sizeof
                      (double));
    itmp = (int)N << 2;
    for (iy = 0; iy < itmp; iy++) {
      extrinsic_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: input  | Column: step l */
    iy = E2->size[0] * E2->size[1];
    E2->size[0] = 4;
    emxEnsureCapacity((emxArray__common *)E2, iy, (int)sizeof(double));
    cindx = E2->size[0];
    itmp = E2->size[1];
    itmp *= cindx;
    for (iy = 0; iy < itmp; iy++) {
      E2->data[iy] += q->data[iy];
    }

    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = E2->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
    ix = 4;
    iy = -1;
    for (i = 1; i <= E2->size[1]; i++) {
      b_ix = ix - 3;
      mtmp = E2->data[ix - 4];
      if (rtIsNaN(E2->data[ix - 4])) {
        c_ix = ix - 2;
        exitg9 = false;
        while ((!exitg9) && (c_ix <= ix)) {
          b_ix = c_ix;
          if (!rtIsNaN(E2->data[c_ix - 1])) {
            mtmp = E2->data[c_ix - 1];
            exitg9 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (b_ix < ix) {
        while (b_ix + 1 <= ix) {
          if (E2->data[b_ix] > mtmp) {
            mtmp = E2->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      maxval->data[iy] = mtmp;
      ix += 4;
    }

    iy = c_E2->size[0] * c_E2->size[1];
    c_E2->size[0] = 4;
    c_E2->size[1] = E2->size[1];
    emxEnsureCapacity((emxArray__common *)c_E2, iy, (int)sizeof(double));
    itmp = E2->size[0] * E2->size[1];
    for (iy = 0; iy < itmp; iy++) {
      c_E2->data[iy] = E2->data[iy];
    }

    bsxfun(c_E2, maxval, E2);

    /*  Normalization */
    /*  2.1 Backward messages update */
    backward_matrix->data[backward_matrix->size[0] * (backward_matrix->size[1] -
      1)] = 0.0;

    /*  Starting with B_(N-1)(s_0) = 0  */
    d0 = 2.0 * N - 1.0;
    for (l = 0; l < (int)-(1.0 + (-1.0 - d0)); l++) {
      /*  This is a matlab matrix index */
      b_index = b_mod(d0 + -(double)l, N);
      for (s = 0; s < 8; s++) {
        /*  s_l */
        summ = rtMinusInf;

        /*  Sum over u  */
        for (u = 0; u < 4; u++) {
          /*  s_(l+1) */
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((backward_matrix->data[((int)
            (state_update_table[s + (u << 3)] + 1.0) + backward_matrix->size[0] *
            ((int)(b_index + 1.0) - 1)) - 1] + g1->data[((int)(output_table[s +
            (u << 3)] + 1.0) + g1->size[0] * ((int)(b_index + 1.0) - 1)) - 1]) +
                      E2->data[u + E2->size[0] * ((int)(b_index + 1.0) - 1)]));
        }

        if (b_index == 0.0) {
          index2 = N;
        } else {
          index2 = b_index;
        }

        backward_matrix->data[s + backward_matrix->size[0] * ((int)index2 - 1)] =
          summ;
      }

      cindx = 1;
      mtmp = backward_matrix->data[backward_matrix->size[0] * ((int)index2 - 1)];
      if (rtIsNaN(backward_matrix->data[backward_matrix->size[0] * ((int)index2
            - 1)])) {
        ix = 2;
        exitg8 = false;
        while ((!exitg8) && (ix < 9)) {
          cindx = ix;
          if (!rtIsNaN(backward_matrix->data[(ix + backward_matrix->size[0] *
                ((int)index2 - 1)) - 1])) {
            mtmp = backward_matrix->data[(ix + backward_matrix->size[0] * ((int)
              index2 - 1)) - 1];
            exitg8 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (backward_matrix->data[cindx + backward_matrix->size[0] * ((int)
               index2 - 1)] > mtmp) {
            mtmp = backward_matrix->data[cindx + backward_matrix->size[0] *
              ((int)index2 - 1)];
          }

          cindx++;
        }
      }

      for (iy = 0; iy < 8; iy++) {
        backward_matrix->data[iy + backward_matrix->size[0] * ((int)index2 - 1)]
          -= mtmp;
      }

      /*  Normalization */
    }

    /*  2.2 Forward messages update */
    forward_matrix->data[0] = 0.0;

    /*  Starting with F_0 (s_0) = 0 */
    d0 = 2.0 * N;
    for (l = 0; l < (int)(d0 + -1.0); l++) {
      /*  This is a matlab matrix index */
      b_index = b_mod((2.0 + (double)l) - 1.0, N);
      if (b_index == 0.0) {
        index2 = N;
      } else {
        index2 = b_index;
      }

      for (s = 0; s < 8; s++) {
        /*  s_(l+1) */
        summ = rtMinusInf;

        /*  Sum over the neighbours of s */
        for (u_p = 0; u_p < 4; u_p++) {
          /*  s_l */
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((forward_matrix->data[((int)
            (neighbours_table[s + (u_p << 3)] + 1.0) + forward_matrix->size[0] *
            ((int)index2 - 1)) - 1] + g1->data[((int)(output_table[((int)
            (neighbours_table[s + (u_p << 3)] + 1.0) + (u_p << 3)) - 1] + 1.0) +
            g1->size[0] * ((int)index2 - 1)) - 1]) + E2->data[u_p + E2->size[0] *
                      ((int)index2 - 1)]));
        }

        forward_matrix->data[s + forward_matrix->size[0] * ((int)(b_index + 1.0)
          - 1)] = summ;
      }

      cindx = 1;
      mtmp = forward_matrix->data[forward_matrix->size[0] * ((int)(b_index + 1.0)
        - 1)];
      if (rtIsNaN(forward_matrix->data[forward_matrix->size[0] * ((int)(b_index
             + 1.0) - 1)])) {
        ix = 2;
        exitg7 = false;
        while ((!exitg7) && (ix < 9)) {
          cindx = ix;
          if (!rtIsNaN(forward_matrix->data[(ix + forward_matrix->size[0] *
                ((int)(b_index + 1.0) - 1)) - 1])) {
            mtmp = forward_matrix->data[(ix + forward_matrix->size[0] * ((int)
              (b_index + 1.0) - 1)) - 1];
            exitg7 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (forward_matrix->data[cindx + forward_matrix->size[0] * ((int)
               (b_index + 1.0) - 1)] > mtmp) {
            mtmp = forward_matrix->data[cindx + forward_matrix->size[0] * ((int)
              (b_index + 1.0) - 1)];
          }

          cindx++;
        }
      }

      for (iy = 0; iy < 8; iy++) {
        forward_matrix->data[iy + forward_matrix->size[0] * ((int)(b_index + 1.0)
          - 1)] -= mtmp;
      }

      /*  Normalization */
    }

    /*  2.3 Extrinsic message update */
    index_b = 1.0;
    index_f = 1.0;
    for (l = 0; l < (int)N; l++) {
      /*  This is a matlab index! */
      for (u = 0; u < 4; u++) {
        summ = rtMinusInf;
        for (s = 0; s < 8; s++) {
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((forward_matrix->data[s +
            forward_matrix->size[0] * ((int)index_f - 1)] +
            backward_matrix->data[((int)(state_update_table[s + (u << 3)] + 1.0)
            + backward_matrix->size[0] * ((int)index_b - 1)) - 1]) + g1->data
                      [((int)(output_table[s + (u << 3)] + 1.0) + g1->size[0] *
                        l) - 1]));
        }

        extrinsic_matrix->data[u + extrinsic_matrix->size[0] * l] = summ;
      }

      index_f++;
      index_b++;

      /*  index_b = mod(index_b + 1, N);         */
    }

    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = extrinsic_matrix->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
    ix = 4;
    iy = -1;
    for (i = 1; i <= extrinsic_matrix->size[1]; i++) {
      b_ix = ix - 3;
      mtmp = extrinsic_matrix->data[ix - 4];
      if (rtIsNaN(extrinsic_matrix->data[ix - 4])) {
        c_ix = ix - 2;
        exitg6 = false;
        while ((!exitg6) && (c_ix <= ix)) {
          b_ix = c_ix;
          if (!rtIsNaN(extrinsic_matrix->data[c_ix - 1])) {
            mtmp = extrinsic_matrix->data[c_ix - 1];
            exitg6 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (b_ix < ix) {
        while (b_ix + 1 <= ix) {
          if (extrinsic_matrix->data[b_ix] > mtmp) {
            mtmp = extrinsic_matrix->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      maxval->data[iy] = mtmp;
      ix += 4;
    }

    bsxfun(extrinsic_matrix, maxval, E1);

    /*  Normalization */
    /*  2.4 Message from the equality factor update */
    iy = E2->size[0] * E2->size[1];
    E2->size[0] = 4;
    E2->size[1] = E1->size[1];
    emxEnsureCapacity((emxArray__common *)E2, iy, (int)sizeof(double));
    itmp = E1->size[0] * E1->size[1];
    for (iy = 0; iy < itmp; iy++) {
      E2->data[iy] = E1->data[iy] + q->data[iy];
    }

    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = E2->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
    ix = 4;
    iy = -1;
    for (i = 1; i <= E2->size[1]; i++) {
      b_ix = ix - 3;
      mtmp = E2->data[ix - 4];
      if (rtIsNaN(E2->data[ix - 4])) {
        c_ix = ix - 2;
        exitg5 = false;
        while ((!exitg5) && (c_ix <= ix)) {
          b_ix = c_ix;
          if (!rtIsNaN(E2->data[c_ix - 1])) {
            mtmp = E2->data[c_ix - 1];
            exitg5 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (b_ix < ix) {
        while (b_ix + 1 <= ix) {
          if (E2->data[b_ix] > mtmp) {
            mtmp = E2->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      maxval->data[iy] = mtmp;
      ix += 4;
    }

    iy = b_E2->size[0] * b_E2->size[1];
    b_E2->size[0] = 4;
    b_E2->size[1] = E2->size[1];
    emxEnsureCapacity((emxArray__common *)b_E2, iy, (int)sizeof(double));
    itmp = E2->size[0] * E2->size[1];
    for (iy = 0; iy < itmp; iy++) {
      b_E2->data[iy] = E2->data[iy];
    }

    bsxfun(b_E2, maxval, E2);

    /*  Normalization */
    /*  3 BCJR ALGORITHM ON THE LOWER CODE */
    /*  3.0 BCJR matrices initialization  */
    iy = backward_matrix->size[0] * backward_matrix->size[1];
    backward_matrix->size[0] = 8;
    backward_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)backward_matrix, iy, (int)sizeof
                      (double));
    itmp = (int)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      backward_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: state  | Column: step l */
    iy = forward_matrix->size[0] * forward_matrix->size[1];
    forward_matrix->size[0] = 8;
    forward_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)forward_matrix, iy, (int)sizeof(double));
    itmp = (int)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      forward_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: state  | Column: step l */
    iy = extrinsic_matrix->size[0] * extrinsic_matrix->size[1];
    extrinsic_matrix->size[0] = 4;
    extrinsic_matrix->size[1] = (int)N;
    emxEnsureCapacity((emxArray__common *)extrinsic_matrix, iy, (int)sizeof
                      (double));
    itmp = (int)N << 2;
    for (iy = 0; iy < itmp; iy++) {
      extrinsic_matrix->data[iy] = rtMinusInf;
    }

    /*  Row: input  | Column: step l */
    /*  3.1 Backward message update */
    backward_matrix->data[backward_matrix->size[0] * (backward_matrix->size[1] -
      1)] = 0.0;

    /*  Starting with B_(N-1)(s_0) = 0  */
    d0 = 2.0 * N - 1.0;
    for (l = 0; l < (int)-(1.0 + (-1.0 - d0)); l++) {
      /*  This is a matlab matrix index */
      b_index = b_mod(d0 + -(double)l, N);
      for (s = 0; s < 8; s++) {
        /*  s_l */
        summ = rtMinusInf;

        /*  Sum over u  */
        for (u = 0; u < 4; u++) {
          /*  s_(l+1) */
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((backward_matrix->data[((int)
            (state_update_table[s + (u << 3)] + 1.0) + backward_matrix->size[0] *
            ((int)(b_index + 1.0) - 1)) - 1] + g2->data[((int)(output_table[s +
            (u << 3)] + 1.0) + g2->size[0] * ((int)(b_index + 1.0) - 1)) - 1]) +
                      E2->data[((int)(p_input_table_data[u + p_input_table_size
            [0] * ((int)(b_index + 1.0) - 1)] + 1.0) + E2->size[0] * ((int)
            (p_step_table_data[u + p_step_table_size[0] * ((int)(b_index + 1.0)
            - 1)] + 1.0) - 1)) - 1]));
        }

        if (b_index == 0.0) {
          index2 = N;
        } else {
          index2 = b_index;
        }

        backward_matrix->data[s + backward_matrix->size[0] * ((int)index2 - 1)] =
          summ;
      }

      cindx = 1;
      mtmp = backward_matrix->data[backward_matrix->size[0] * ((int)index2 - 1)];
      if (rtIsNaN(backward_matrix->data[backward_matrix->size[0] * ((int)index2
            - 1)])) {
        ix = 2;
        exitg4 = false;
        while ((!exitg4) && (ix < 9)) {
          cindx = ix;
          if (!rtIsNaN(backward_matrix->data[(ix + backward_matrix->size[0] *
                ((int)index2 - 1)) - 1])) {
            mtmp = backward_matrix->data[(ix + backward_matrix->size[0] * ((int)
              index2 - 1)) - 1];
            exitg4 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (backward_matrix->data[cindx + backward_matrix->size[0] * ((int)
               index2 - 1)] > mtmp) {
            mtmp = backward_matrix->data[cindx + backward_matrix->size[0] *
              ((int)index2 - 1)];
          }

          cindx++;
        }
      }

      for (iy = 0; iy < 8; iy++) {
        backward_matrix->data[iy + backward_matrix->size[0] * ((int)index2 - 1)]
          -= mtmp;
      }

      /*  Normalization */
    }

    /*  3.2 Forward messages update */
    forward_matrix->data[0] = 0.0;

    /*  Starting with F_0 (s_0) = 0 */
    d0 = 2.0 * N;
    for (l = 0; l < (int)(d0 + -1.0); l++) {
      /*  This is a matlab matrix index */
      b_index = b_mod((2.0 + (double)l) - 1.0, N);
      if (b_index == 0.0) {
        index2 = N;
      } else {
        index2 = b_index;
      }

      for (s = 0; s < 8; s++) {
        /*  s_(l+1) */
        summ = rtMinusInf;

        /*  Sum over the neighbours of s */
        for (u_p = 0; u_p < 4; u_p++) {
          /*  s_l */
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((forward_matrix->data[((int)
            (neighbours_table[s + (u_p << 3)] + 1.0) + forward_matrix->size[0] *
            ((int)index2 - 1)) - 1] + g2->data[((int)(output_table[((int)
            (neighbours_table[s + (u_p << 3)] + 1.0) + (u_p << 3)) - 1] + 1.0) +
            g2->size[0] * ((int)index2 - 1)) - 1]) + E2->data[((int)
            (p_input_table_data[u_p + p_input_table_size[0] * ((int)index2 - 1)]
             + 1.0) + E2->size[0] * ((int)(p_step_table_data[u_p +
            p_step_table_size[0] * ((int)index2 - 1)] + 1.0) - 1)) - 1]));
        }

        forward_matrix->data[s + forward_matrix->size[0] * ((int)(b_index + 1.0)
          - 1)] = summ;
      }

      cindx = 1;
      mtmp = forward_matrix->data[forward_matrix->size[0] * ((int)(b_index + 1.0)
        - 1)];
      if (rtIsNaN(forward_matrix->data[forward_matrix->size[0] * ((int)(b_index
             + 1.0) - 1)])) {
        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix < 9)) {
          cindx = ix;
          if (!rtIsNaN(forward_matrix->data[(ix + forward_matrix->size[0] *
                ((int)(b_index + 1.0) - 1)) - 1])) {
            mtmp = forward_matrix->data[(ix + forward_matrix->size[0] * ((int)
              (b_index + 1.0) - 1)) - 1];
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (forward_matrix->data[cindx + forward_matrix->size[0] * ((int)
               (b_index + 1.0) - 1)] > mtmp) {
            mtmp = forward_matrix->data[cindx + forward_matrix->size[0] * ((int)
              (b_index + 1.0) - 1)];
          }

          cindx++;
        }
      }

      for (iy = 0; iy < 8; iy++) {
        forward_matrix->data[iy + forward_matrix->size[0] * ((int)(b_index + 1.0)
          - 1)] -= mtmp;
      }

      /*  Normalization */
    }

    /*  3.3 Extrinsic message update */
    index_b = 1.0;
    index_f = 1.0;
    for (l = 0; l < (int)N; l++) {
      /*  This is a matlab index! */
      for (u = 0; u < 4; u++) {
        summ = rtMinusInf;
        for (s = 0; s < 8; s++) {
          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          summ = log(exp(summ) + exp((forward_matrix->data[s +
            forward_matrix->size[0] * ((int)index_f - 1)] +
            backward_matrix->data[((int)(state_update_table[s + (u << 3)] + 1.0)
            + backward_matrix->size[0] * ((int)index_b - 1)) - 1]) + g2->data
                      [((int)(output_table[s + (u << 3)] + 1.0) + g2->size[0] *
                        l) - 1]));
        }

        /* extrinsic_matrix(u+1, l) = summ; */
        extrinsic_matrix->data[((int)(p_input_table_data[u + p_input_table_size
          [0] * l] + 1.0) + extrinsic_matrix->size[0] * ((int)
          (p_step_table_data[u + p_step_table_size[0] * l] + 1.0) - 1)) - 1] =
          summ;
      }

      index_f++;
      index_b++;

      /*  index_b = mod(index_b + 1, N);         */
    }

    iy = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = extrinsic_matrix->size[1];
    emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
    ix = 4;
    iy = -1;
    for (i = 1; i <= extrinsic_matrix->size[1]; i++) {
      b_ix = ix - 3;
      mtmp = extrinsic_matrix->data[ix - 4];
      if (rtIsNaN(extrinsic_matrix->data[ix - 4])) {
        c_ix = ix - 2;
        exitg2 = false;
        while ((!exitg2) && (c_ix <= ix)) {
          b_ix = c_ix;
          if (!rtIsNaN(extrinsic_matrix->data[c_ix - 1])) {
            mtmp = extrinsic_matrix->data[c_ix - 1];
            exitg2 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (b_ix < ix) {
        while (b_ix + 1 <= ix) {
          if (extrinsic_matrix->data[b_ix] > mtmp) {
            mtmp = extrinsic_matrix->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      maxval->data[iy] = mtmp;
      ix += 4;
    }

    bsxfun(extrinsic_matrix, maxval, E2);

    /*  Normalization */
    cont++;
  }

  emxFree_real_T(&c_E2);
  emxFree_real_T(&b_E2);
  emxFree_real_T(&extrinsic_matrix);
  emxFree_real_T(&forward_matrix);
  emxFree_real_T(&backward_matrix);
  emxFree_real_T(&g2);
  emxFree_real_T(&g1);

  /*  Maximum a posteriori estimate */
  iy = E2->size[0] * E2->size[1];
  E2->size[0] = 4;
  emxEnsureCapacity((emxArray__common *)E2, iy, (int)sizeof(double));
  cindx = E2->size[0];
  itmp = E2->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    E2->data[iy] = (E2->data[iy] + q->data[iy]) + E1->data[iy];
  }

  emxFree_real_T(&E1);
  emxFree_real_T(&q);
  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = E2->size[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
  for (iy = 0; iy < 2; iy++) {
    uv0[iy] = (unsigned int)maxval->size[iy];
  }

  emxInit_int32_T(&indx, 2);
  iy = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)indx, iy, (int)sizeof(int));
  itmp = (int)uv0[1];
  for (iy = 0; iy < itmp; iy++) {
    indx->data[iy] = 1;
  }

  ix = 4;
  iy = -1;
  for (i = 1; i <= E2->size[1]; i++) {
    b_ix = ix - 3;
    mtmp = E2->data[ix - 4];
    itmp = 1;
    cindx = 1;
    if (rtIsNaN(E2->data[ix - 4])) {
      c_ix = ix - 2;
      exitg1 = false;
      while ((!exitg1) && (c_ix <= ix)) {
        cindx++;
        b_ix = c_ix;
        if (!rtIsNaN(E2->data[c_ix - 1])) {
          mtmp = E2->data[c_ix - 1];
          itmp = cindx;
          exitg1 = true;
        } else {
          c_ix++;
        }
      }
    }

    if (b_ix < ix) {
      while (b_ix + 1 <= ix) {
        cindx++;
        if (E2->data[b_ix] > mtmp) {
          mtmp = E2->data[b_ix];
          itmp = cindx;
        }

        b_ix++;
      }
    }

    iy++;
    indx->data[iy] = itmp;
    ix += 4;
  }

  emxFree_real_T(&E2);
  iy = maxval->size[0] * maxval->size[1];
  maxval->size[0] = 1;
  maxval->size[1] = indx->size[1];
  emxEnsureCapacity((emxArray__common *)maxval, iy, (int)sizeof(double));
  itmp = indx->size[0] * indx->size[1];
  for (iy = 0; iy < itmp; iy++) {
    maxval->data[iy] = indx->data[iy];
  }

  emxFree_int32_T(&indx);
  iy = u_hat->size[0];
  u_hat->size[0] = (int)((double)maxval->size[1] * 2.0);
  emxEnsureCapacity((emxArray__common *)u_hat, iy, (int)sizeof(double));
  itmp = (int)((double)maxval->size[1] * 2.0);
  for (iy = 0; iy < itmp; iy++) {
    u_hat->data[iy] = 0.0;
  }

  /* num2input = @(i) mod(fix(i./(2.^(crsc_k-1:-1:0)).'),2); */
  for (i = 0; i < maxval->size[1]; i++) {
    /*  From u_hat_num to u_hat */
    /* u_hat(crsc_k*i+1:crsc_k*i+crsc_k) = num2input(u_hat_num(i+1)-1); */
    u_hat->data[(int)((unsigned int)i << 1) + 1] = b_mod(maxval->data[i] - 1.0,
      2.0);
    d0 = (maxval->data[i] - 1.0) / 2.0;
    b_fix(&d0);
    u_hat->data[(int)((unsigned int)i << 1)] = b_mod(d0, 2.0);
  }

  emxFree_real_T(&maxval);
}

/*
 * File trailer for CTC_dec_p.c
 *
 * [EOF]
 */
