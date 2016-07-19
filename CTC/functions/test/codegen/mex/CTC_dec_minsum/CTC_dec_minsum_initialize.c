/*
 * CTC_dec_minsum_initialize.c
 *
 * Code generation for function 'CTC_dec_minsum_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_minsum.h"
#include "CTC_dec_minsum_initialize.h"
#include "_coder_CTC_dec_minsum_mex.h"
#include "CTC_dec_minsum_data.h"

/* Function Definitions */
void CTC_dec_minsum_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (CTC_dec_minsum_initialize.c) */
