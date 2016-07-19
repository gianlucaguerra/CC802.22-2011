/*
 * CTC_dec_minsum.h
 *
 * Code generation for function 'CTC_dec_minsum'
 *
 */

#ifndef __CTC_DEC_MINSUM_H__
#define __CTC_DEC_MINSUM_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "CTC_dec_minsum_types.h"

/* Function Declarations */
extern void CTC_dec_minsum(const emlrtStack *sp, const real_T r[3456], const
  real_T state_update_table[32], const real_T output_table[32], const real_T
  neighbours_table[32], const real_T modulation_table[24], real_T sigma_w,
  real_T N, real_T n_it, const real_T p_input_table[3456], const real_T
  p_step_table[3456], const real_T puncturing_pattern[3456], emxArray_real_T
  *u_hat);

#endif

/* End of code generation (CTC_dec_minsum.h) */
