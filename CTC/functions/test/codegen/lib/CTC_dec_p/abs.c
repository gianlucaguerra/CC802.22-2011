/*
 * File: abs.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const double x[3]
 *                double y[3]
 * Return Type  : void
 */
void b_abs(const double x[3], double y[3])
{
  int k;
  for (k = 0; k < 3; k++) {
    y[k] = fabs(x[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
