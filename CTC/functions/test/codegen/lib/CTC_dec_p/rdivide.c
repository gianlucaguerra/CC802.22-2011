/*
 * File: rdivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "rdivide.h"
#include "CTC_dec_p_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *z
 * Return Type  : void
 */
void rdivide(const emxArray_real_T *x, emxArray_real_T *z)
{
  int i0;
  int loop_ub;
  i0 = z->size[0] * z->size[1];
  z->size[0] = 4;
  z->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)z, i0, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    z->data[i0] = x->data[i0] / 4.0;
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
