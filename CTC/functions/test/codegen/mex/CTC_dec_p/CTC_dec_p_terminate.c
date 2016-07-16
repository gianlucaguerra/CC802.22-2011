/*
 * CTC_dec_p_terminate.c
 *
 * Code generation for function 'CTC_dec_p_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "CTC_dec_p_terminate.h"
#include "_coder_CTC_dec_p_mex.h"
#include "CTC_dec_p_data.h"

/* Function Definitions */
void CTC_dec_p_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void CTC_dec_p_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (CTC_dec_p_terminate.c) */
