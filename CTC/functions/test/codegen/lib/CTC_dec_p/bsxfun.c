/*
 * File: bsxfun.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "bsxfun.h"
#include "CTC_dec_p_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *a
 *                const emxArray_real_T *b
 *                emxArray_real_T *c
 * Return Type  : void
 */
void b_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
              emxArray_real_T *c)
{
  int k;
  int i2;
  int asub;
  int bsub;
  int ak;
  int bk;
  int ck;
  double av[8];
  double b_b;
  double cv[8];
  if (a->size[1] <= b->size[1]) {
    k = a->size[1];
  } else {
    k = b->size[1];
  }

  i2 = c->size[0] * c->size[1];
  c->size[0] = 8;
  c->size[1] = k;
  emxEnsureCapacity((emxArray__common *)c, i2, (int)sizeof(double));
  if (c->size[1] == 0) {
  } else {
    asub = 1;
    bsub = 1;
    ak = 0;
    bk = 0;
    i2 = (c->size[1] << 3) - 8;
    for (ck = 0; ck <= i2; ck += 8) {
      for (k = 0; k < 8; k++) {
        av[k] = a->data[ak + k];
      }

      b_b = b->data[bk];
      for (k = 0; k < 8; k++) {
        cv[k] = av[k] - b_b;
      }

      for (k = 0; k < 8; k++) {
        c->data[ck + k] = cv[k];
      }

      if (asub < a->size[1]) {
        ak += 8;
        bk++;
        bsub++;
        asub++;
      } else if (bsub < b->size[1]) {
        bk++;
        bsub++;
      } else {
        asub = 1;
        bsub = 1;
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                const emxArray_real_T *b
 *                emxArray_real_T *c
 * Return Type  : void
 */
void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b, emxArray_real_T *
            c)
{
  int k;
  int i1;
  int asub;
  int bsub;
  int ak;
  int bk;
  int ck;
  double av[4];
  double b_b;
  double cv[4];
  if (a->size[1] <= b->size[1]) {
    k = a->size[1];
  } else {
    k = b->size[1];
  }

  i1 = c->size[0] * c->size[1];
  c->size[0] = 4;
  c->size[1] = k;
  emxEnsureCapacity((emxArray__common *)c, i1, (int)sizeof(double));
  if (c->size[1] == 0) {
  } else {
    asub = 1;
    bsub = 1;
    ak = 0;
    bk = 0;
    i1 = (c->size[1] << 2) - 4;
    for (ck = 0; ck <= i1; ck += 4) {
      for (k = 0; k < 4; k++) {
        av[k] = a->data[ak + k];
      }

      b_b = b->data[bk];
      for (k = 0; k < 4; k++) {
        cv[k] = av[k] - b_b;
      }

      for (k = 0; k < 4; k++) {
        c->data[ck + k] = cv[k];
      }

      if (asub < a->size[1]) {
        ak += 4;
        bk++;
        bsub++;
        asub++;
      } else if (bsub < b->size[1]) {
        bk++;
        bsub++;
      } else {
        asub = 1;
        bsub = 1;
      }
    }
  }
}

/*
 * File trailer for bsxfun.c
 *
 * [EOF]
 */
