/*
 * File: CTC_dec_p.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

#ifndef __CTC_DEC_P_H__
#define __CTC_DEC_P_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "CTC_dec_p_types.h"

/* Function Declarations */
extern void CTC_dec_p(const double r_data[], const int r_size[1], const double
                      state_update_table[32], const double output_table[32],
                      const double neighbours_table[32], const double
                      modulation_table[24], double sigma_w, double N, double
                      n_it, const double p_input_table_data[], const int
                      p_input_table_size[2], const double p_step_table_data[],
                      const int p_step_table_size[2], const double
                      puncturing_pattern_data[], const int
                      puncturing_pattern_size[1], emxArray_real_T *u_hat);

#endif

/*
 * File trailer for CTC_dec_p.h
 *
 * [EOF]
 */
