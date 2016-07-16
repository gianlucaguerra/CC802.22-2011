/*
 * _coder_CTC_dec_p_mex.c
 *
 * Code generation for function '_coder_CTC_dec_p_mex'
 *
 */

/* Include files */
#include "CTC_dec_p.h"
#include "_coder_CTC_dec_p_mex.h"
#include "CTC_dec_p_terminate.h"
#include "_coder_CTC_dec_p_api.h"
#include "CTC_dec_p_initialize.h"
#include "CTC_dec_p_data.h"

/* Function Declarations */
static void CTC_dec_p_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[11]);

/* Function Definitions */
static void CTC_dec_p_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[11])
{
  int32_T n;
  const mxArray *inputs[11];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        9, "CTC_dec_p");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "CTC_dec_p");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  CTC_dec_p_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  CTC_dec_p_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(CTC_dec_p_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  CTC_dec_p_initialize();

  /* Dispatch the entry-point. */
  CTC_dec_p_mexFunction(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_CTC_dec_p_mex.c) */
