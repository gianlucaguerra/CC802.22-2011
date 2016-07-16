/*
 * CTC_dec_p.h
 *
 * Code generation for function 'CTC_dec_p'
 *
 */

#ifndef __CTC_DEC_P_H__
#define __CTC_DEC_P_H__

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
#include "CTC_dec_p_types.h"

/* Function Declarations */
extern void CTC_dec_p(const emlrtStack *sp, const real_T r_data[], const int32_T
                      r_size[1], const real_T state_update_table[32], const
                      real_T output_table[32], const real_T neighbours_table[32],
                      const real_T modulation_table[24], real_T sigma_w, real_T
                      N, real_T n_it, const real_T p_input_table_data[], const
                      int32_T p_input_table_size[2], const real_T
                      p_step_table_data[], const int32_T p_step_table_size[2],
                      const real_T puncturing_pattern_data[], const int32_T
                      puncturing_pattern_size[1], emxArray_real_T *u_hat);

#endif

/* End of code generation (CTC_dec_p.h) */
