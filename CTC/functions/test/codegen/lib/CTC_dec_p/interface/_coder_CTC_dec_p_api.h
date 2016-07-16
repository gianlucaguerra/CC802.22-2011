/*
 * File: _coder_CTC_dec_p_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

#ifndef ___CODER_CTC_DEC_P_API_H__
#define ___CODER_CTC_DEC_P_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_CTC_dec_p_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CTC_dec_p(real_T r_data[], int32_T r_size[1], real_T
                      state_update_table[32], real_T output_table[32], real_T
                      neighbours_table[32], real_T modulation_table[24], real_T
                      sigma_w, real_T N, real_T n_it, real_T p_input_table_data[],
                      int32_T p_input_table_size[2], real_T p_step_table_data[],
                      int32_T p_step_table_size[2], real_T
                      puncturing_pattern_data[], int32_T
                      puncturing_pattern_size[1], emxArray_real_T *u_hat);
extern void CTC_dec_p_api(const mxArray *prhs[11], const mxArray *plhs[1]);
extern void CTC_dec_p_atexit(void);
extern void CTC_dec_p_initialize(void);
extern void CTC_dec_p_terminate(void);
extern void CTC_dec_p_xil_terminate(void);

#endif

/*
 * File trailer for _coder_CTC_dec_p_api.h
 *
 * [EOF]
 */
