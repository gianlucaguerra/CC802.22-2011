/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "rdivide.h"
#include "CTC_dec_p_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = { 1, 14, "rdivide",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

/* Function Definitions */
void rdivide(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *z)
{
  int32_T i0;
  int32_T loop_ub;
  i0 = z->size[0] * z->size[1];
  z->size[0] = 4;
  z->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)z, i0, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    z->data[i0] = x->data[i0] / 4.0;
  }
}

/* End of code generation (rdivide.c) */
