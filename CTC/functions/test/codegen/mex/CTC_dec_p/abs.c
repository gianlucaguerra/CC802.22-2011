/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const real_T x[3], real_T y[3])
{
  int32_T k;
  for (k = 0; k < 3; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

/* End of code generation (abs.c) */
