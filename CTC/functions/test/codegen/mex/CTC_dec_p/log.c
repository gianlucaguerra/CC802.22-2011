/*
 * log.c
 *
 * Code generation for function 'log'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "log.h"
#include "eml_int_forloop_overflow_check.h"
#include "CTC_dec_p_data.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 16, "log",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" };

static emlrtRSInfo x_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"
};

/* Function Definitions */
void b_log(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T b0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1] << 2;
  b_st.site = &x_emlrtRSI;
  if (1 > nx) {
    b0 = false;
  } else {
    b0 = (nx > 2147483646);
  }

  if (b0) {
    c_st.site = &y_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarLog(x->data[k]);
  }
}

void c_log(real_T *x)
{
  *x = muDoubleScalarLog(*x);
}

/* End of code generation (log.c) */
