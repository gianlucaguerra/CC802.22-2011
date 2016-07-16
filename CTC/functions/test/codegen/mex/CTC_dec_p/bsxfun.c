/*
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "bsxfun.h"
#include "CTC_dec_p_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 1, 14, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo ab_emlrtRTEI = { 19, 15, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo bb_emlrtRTEI = { 21, 15, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

/* Function Definitions */
void b_bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
              emxArray_real_T *b, emxArray_real_T *c)
{
  boolean_T p;
  int32_T k;
  int32_T i2;
  int32_T asub;
  int32_T bsub;
  int32_T ak;
  int32_T bk;
  int32_T ck;
  real_T av[8];
  real_T b_b;
  real_T cv[8];
  if ((a->size[1] != 1) && (b->size[1] != 1) && (a->size[1] != b->size[1])) {
    p = false;
  } else {
    p = true;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ab_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  p = !(a->size[1] != b->size[1]);
  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &bb_emlrtRTEI,
      "Coder:toolbox:bsxfun_dynamicExpansion", 0);
  }

  if (a->size[1] <= b->size[1]) {
    k = a->size[1];
  } else {
    k = b->size[1];
  }

  i2 = c->size[0] * c->size[1];
  c->size[0] = 8;
  c->size[1] = k;
  emxEnsureCapacity(sp, (emxArray__common *)c, i2, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
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

void bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
            emxArray_real_T *b, emxArray_real_T *c)
{
  boolean_T p;
  int32_T k;
  int32_T i1;
  int32_T asub;
  int32_T bsub;
  int32_T ak;
  int32_T bk;
  int32_T ck;
  real_T av[4];
  real_T b_b;
  real_T cv[4];
  if ((a->size[1] != 1) && (b->size[1] != 1) && (a->size[1] != b->size[1])) {
    p = false;
  } else {
    p = true;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ab_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  p = !(a->size[1] != b->size[1]);
  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &bb_emlrtRTEI,
      "Coder:toolbox:bsxfun_dynamicExpansion", 0);
  }

  if (a->size[1] <= b->size[1]) {
    k = a->size[1];
  } else {
    k = b->size[1];
  }

  i1 = c->size[0] * c->size[1];
  c->size[0] = 4;
  c->size[1] = k;
  emxEnsureCapacity(sp, (emxArray__common *)c, i1, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
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

/* End of code generation (bsxfun.c) */
