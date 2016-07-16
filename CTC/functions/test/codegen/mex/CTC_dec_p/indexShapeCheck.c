/*
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = { 18, "indexShapeCheck",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 85, 5, "indexShapeCheck",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"
};

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gb_emlrtRSI;
  if (!!(matrixSize != 1)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &cb_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
