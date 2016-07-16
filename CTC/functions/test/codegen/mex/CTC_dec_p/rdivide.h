/*
 * rdivide.h
 *
 * Code generation for function 'rdivide'
 *
 */

#ifndef __RDIVIDE_H__
#define __RDIVIDE_H__

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
#include "CTC_dec_p_types.h"

/* Function Declarations */
extern void rdivide(const emlrtStack *sp, const emxArray_real_T *x,
                    emxArray_real_T *z);

#endif

/* End of code generation (rdivide.h) */
