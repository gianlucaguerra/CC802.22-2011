/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "power.h"

/* Function Definitions */
void power(const real_T a[3], real_T y[3])
{
  int32_T k;
  for (k = 0; k < 3; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
