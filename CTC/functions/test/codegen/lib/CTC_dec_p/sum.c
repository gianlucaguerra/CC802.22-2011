/*
 * File: sum.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[3]
 * Return Type  : double
 */
double sum(const double x[3])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 2; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
