/*
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef __SUM_H__
#define __SUM_H__

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
extern real_T sum(const real_T x[3]);

#ifdef __WATCOMC__

#pragma aux sum value [8087];

#endif
#endif

/* End of code generation (sum.h) */
