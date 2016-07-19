/*
 * bsxfun.h
 *
 * Code generation for function 'bsxfun'
 *
 */

#ifndef __BSXFUN_H__
#define __BSXFUN_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "CTC_dec_minsum_types.h"

/* Function Declarations */
extern void b_bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
                     emxArray_real_T *b, emxArray_real_T *c);
extern void bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
                   emxArray_real_T *b, emxArray_real_T *c);

#endif

/* End of code generation (bsxfun.h) */
