/*
 * File: _coder_CTC_dec_p_api.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_CTC_dec_p_api.h"
#include "_coder_CTC_dec_p_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131419U, NULL, "CTC_dec_p",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *state_update_table, const char_T *identifier))[32];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[32];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *modulation_table, const char_T *identifier))[24];
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[24];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sigma_w,
  const char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *p_input_table, const char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[32];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[24];
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *state_update_table
 *                const char_T *identifier
 * Return Type  : real_T (*)[32]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *state_update_table, const char_T *identifier))[32]
{
  real_T (*y)[32];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(state_update_table), &thisId);
  emlrtDestroyArray(&state_update_table);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[32]
 */
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[32]
{
  real_T (*y)[32];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *modulation_table
 *                const char_T *identifier
 * Return Type  : real_T (*)[24]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *modulation_table, const char_T *identifier))[24]
{
  real_T (*y)[24];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(modulation_table), &thisId);
  emlrtDestroyArray(&modulation_table);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *r
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
  static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(r), &thisId, y_data, y_size);
  emlrtDestroyArray(&r);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[24]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[24]
{
  real_T (*y)[24];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *sigma_w
 *                const char_T *identifier
 * Return Type  : real_T
 */
  static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sigma_w,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(sigma_w), &thisId);
  emlrtDestroyArray(&sigma_w);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *p_input_table
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *p_input_table, const char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(p_input_table), &thisId, y_data, y_size);
  emlrtDestroyArray(&p_input_table);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[1]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  int32_T iv1[1];
  boolean_T bv0[1] = { true };

  static const int32_T dims[1] = { 3840 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv1);
  ret_size[0] = iv1[0];
  *ret_data = (real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[32]
 */
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[32]
{
  real_T (*ret)[32];
  static const int32_T dims[2] = { 8, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[32])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[24]
 */
  static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[24]
{
  real_T (*ret)[24];
  static const int32_T dims[2] = { 8, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[24])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  int32_T iv2[2];
  boolean_T bv1[2] = { false, true };

  static const int32_T dims[2] = { 4, 960 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv2);
  ret_size[0] = iv2[0];
  ret_size[1] = iv2[1];
  *ret_data = (real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray *prhs[11]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void CTC_dec_p_api(const mxArray *prhs[11], const mxArray *plhs[1])
{
  emxArray_real_T *u_hat;
  int32_T r_size[1];
  real_T (*r_data)[3840];
  real_T (*state_update_table)[32];
  real_T (*output_table)[32];
  real_T (*neighbours_table)[32];
  real_T (*modulation_table)[24];
  real_T sigma_w;
  real_T N;
  real_T n_it;
  int32_T p_input_table_size[2];
  real_T (*p_input_table_data)[3840];
  int32_T p_step_table_size[2];
  real_T (*p_step_table_data)[3840];
  int32_T puncturing_pattern_size[1];
  real_T (*puncturing_pattern_data)[3840];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &u_hat, 1, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, 3840);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, false, -1);
  prhs[3] = emlrtProtectR2012b(prhs[3], 3, false, -1);
  prhs[4] = emlrtProtectR2012b(prhs[4], 4, false, -1);
  prhs[8] = emlrtProtectR2012b(prhs[8], 8, false, 3840);
  prhs[9] = emlrtProtectR2012b(prhs[9], 9, false, 3840);
  prhs[10] = emlrtProtectR2012b(prhs[10], 10, false, 3840);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "r", (real_T **)&r_data, r_size);
  state_update_table = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]),
    "state_update_table");
  output_table = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "output_table");
  neighbours_table = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]),
    "neighbours_table");
  modulation_table = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]),
    "modulation_table");
  sigma_w = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "sigma_w");
  N = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "N");
  n_it = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "n_it");
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "p_input_table", (real_T **)
                     &p_input_table_data, p_input_table_size);
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "p_step_table", (real_T **)
                     &p_step_table_data, p_step_table_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "puncturing_pattern", (real_T **)
                   &puncturing_pattern_data, puncturing_pattern_size);

  /* Invoke the target function */
  CTC_dec_p(*r_data, r_size, *state_update_table, *output_table,
            *neighbours_table, *modulation_table, sigma_w, N, n_it,
            *p_input_table_data, p_input_table_size, *p_step_table_data,
            p_step_table_size, *puncturing_pattern_data, puncturing_pattern_size,
            u_hat);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(u_hat);
  u_hat->canFreeData = false;
  emxFree_real_T(&u_hat);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CTC_dec_p_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  CTC_dec_p_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CTC_dec_p_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CTC_dec_p_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_CTC_dec_p_api.c
 *
 * [EOF]
 */
