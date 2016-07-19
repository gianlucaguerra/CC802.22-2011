/*
 * CTC_dec_minsum.c
 *
 * Code generation for function 'CTC_dec_minsum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "CTC_dec_minsum.h"
#include "mpower.h"
#include "power.h"
#include "rdivide.h"
#include "CTC_dec_minsum_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "abs.h"
#include "mod.h"
#include "bsxfun.h"
#include "fix.h"
#include "log.h"
#include "CTC_dec_minsum_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 38, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo b_emlrtRSI = { 39, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo c_emlrtRSI = { 53, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo d_emlrtRSI = { 55, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo e_emlrtRSI = { 58, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo f_emlrtRSI = { 59, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo g_emlrtRSI = { 60, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo h_emlrtRSI = { 61, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo i_emlrtRSI = { 76, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo j_emlrtRSI = { 155, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo k_emlrtRSI = { 159, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo l_emlrtRSI = { 246, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo m_emlrtRSI = { 250, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRSInfo o_emlrtRSI = { 49, "power",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo s_emlrtRSI = { 16, "min",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo t_emlrtRSI = { 18, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo u_emlrtRSI = { 160, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo v_emlrtRSI = { 163, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo w_emlrtRSI = { 308, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo x_emlrtRSI = { 281, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRSInfo y_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo ab_emlrtRSI = { 15, "minOrMax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 22, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 18, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 38, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 42, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 43, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 46, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 48, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 63, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 64, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 71, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 72, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 73, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo emlrtDCI = { 18, 19, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  4 };

static emlrtDCInfo b_emlrtDCI = { 18, 19, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtRTEInfo p_emlrtRTEI = { 21, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 49, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 53, 32, "r1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 55, 32, "r2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtRTEInfo r_emlrtRTEI = { 66, 5, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtECInfo emlrtECI = { 2, 75, 17, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 80, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo c_emlrtDCI = { 85, 39, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 85, 39, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 87, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo d_emlrtBCI = { 1, 8, 87, 31, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 87, 36, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 87, 36, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 79, 27, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 89, 43, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo g_emlrtBCI = { 1, 8, 89, 43, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 89, 50, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 89, 50, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 101, 60, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 102, 51, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 102, 51, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 101, 31, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtRTEInfo t_emlrtRTEI = { 107, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo i_emlrtDCI = { 117, 41, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 117, 41, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 119, 38, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo m_emlrtBCI = { 1, 8, 119, 38, "output_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 120, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo n_emlrtBCI = { 1, 8, 120, 31, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 120, 36, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 106, 26, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 121, 42, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo q_emlrtBCI = { 1, 8, 121, 42, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 121, 49, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 128, 60, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 128, 60, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 129, 47, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 129, 47, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 128, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 128, 31, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtRTEInfo u_emlrtRTEI = { 135, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo p_emlrtDCI = { 141, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo v_emlrtBCI = { 1, 8, 141, 31, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 141, 36, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 142, 45, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 143, 41, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo y_emlrtBCI = { 1, 8, 143, 41, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 143, 48, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtECInfo b_emlrtECI = { 2, 158, 17, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 170, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo r_emlrtDCI = { 175, 34, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo bb_emlrtBCI = { 1, 4, 175, 34, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 175, 65, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 175, 65, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo t_emlrtDCI = { 177, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo db_emlrtBCI = { 1, 8, 177, 31, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo u_emlrtDCI = { 177, 36, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 177, 36, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 169, 27, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo v_emlrtDCI = { 179, 43, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo gb_emlrtBCI = { 1, 8, 179, 43, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo w_emlrtDCI = { 179, 50, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 179, 50, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 191, 61, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo x_emlrtDCI = { 192, 51, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 192, 51, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 191, 32, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtRTEInfo w_emlrtRTEI = { 197, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo y_emlrtDCI = { 207, 34, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo lb_emlrtBCI = { 1, 4, 207, 34, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo ab_emlrtDCI = { 207, 65, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 207, 65, "mu_eq", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo bb_emlrtDCI = { 209, 38, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo nb_emlrtBCI = { 1, 8, 209, 38, "output_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 210, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo ob_emlrtBCI = { 1, 8, 210, 31, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 210, 36, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 210, 36, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 196, 26, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 211, 42, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo rb_emlrtBCI = { 1, 8, 211, 42, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 211, 49, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 218, 60, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 218, 60, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 219, 47, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 219, 47, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 218, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 218, 31, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtRTEInfo x_emlrtRTEI = { 225, 9, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtDCInfo ib_emlrtDCI = { 231, 31, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo wb_emlrtBCI = { 1, 8, 231, 31, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 231, 36, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 232, 45, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 233, 41, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo ac_emlrtBCI = { 1, 8, 233, 41, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 233, 48, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtECInfo c_emlrtECI = { 2, 250, 29, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m"
};

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 255, 22, "u_hat_num",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 256, 8, "u_hat", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 257, 8, "u_hat", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { 1, 4, 239, 34, "extrinsic_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 239, 34, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo gc_emlrtBCI = { 1, 864, 239, 52, "p_input_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 239, 58, "extrinsic_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo lb_emlrtDCI = { 239, 58, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo ic_emlrtBCI = { 1, 864, 239, 75, "p_step_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 216, 37, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 216, 37, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo kc_emlrtBCI = { 1, 864, 207, 54, "p_input_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 207, 54, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo lc_emlrtBCI = { 1, 864, 207, 84, "p_step_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo ob_emlrtDCI = { 207, 84, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 189, 38, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo pb_emlrtDCI = { 189, 38, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo nc_emlrtBCI = { 1, 864, 175, 53, "p_input_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo qb_emlrtDCI = { 175, 53, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo oc_emlrtBCI = { 1, 864, 175, 82, "p_step_table",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo rb_emlrtDCI = { 175, 82, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 148, 39, "extrinsic_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 126, 37, "forward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo sb_emlrtDCI = { 126, 37, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 99, 38, "backward_matrix",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtDCInfo tb_emlrtDCI = { 99, 38, "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  1 };

static emlrtBCInfo sc_emlrtBCI = { 1, 3456, 51, 45, "puncturing_pattern",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 52, 21, "g1", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 54, 21, "g2", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { 1, 3456, 23, 17, "puncturing_pattern",
  "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 27, 24, "r_dep", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { 1, 3456, 24, 36, "r", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 24, 24, "r_dep", "CTC_dec_minsum",
  "C:\\Users\\Gianluca\\Dropbox\\Channel Coding\\Project\\CTC\\functions\\test\\CTC_dec_minsum.m",
  0 };

/* Function Definitions */
void CTC_dec_minsum(const emlrtStack *sp, const real_T r[3456], const real_T
                    state_update_table[32], const real_T output_table[32], const
                    real_T neighbours_table[32], const real_T modulation_table
                    [24], real_T sigma_w, real_T N, real_T n_it, const real_T
                    p_input_table[3456], const real_T p_step_table[3456], const
                    real_T puncturing_pattern[3456], emxArray_real_T *u_hat)
{
  emxArray_real_T *r_dep;
  int32_T iy;
  real_T d0;
  int32_T itmp;
  real_T index_r;
  real_T index_p;
  int32_T i;
  int32_T j;
  int32_T cindx;
  emxArray_real_T *r0;
  emxArray_real_T *q;
  emxArray_real_T *indx;
  int32_T ix;
  boolean_T overflow;
  int32_T b_ix;
  real_T mtmp;
  boolean_T c_ix;
  int32_T d_ix;
  boolean_T exitg10;
  boolean_T e_ix;
  emxArray_real_T *b_q;
  emxArray_real_T *g1;
  emxArray_real_T *g2;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  int32_T l;
  int32_T y;
  real_T mod_y[3];
  real_T b_r1[3];
  real_T dv0[3];
  real_T dv1[3];
  boolean_T f_ix;
  boolean_T exitg9;
  boolean_T g_ix;
  emxArray_real_T *b_g1;
  boolean_T h_ix;
  boolean_T exitg8;
  boolean_T i_ix;
  emxArray_real_T *b_g2;
  emxArray_real_T *E2;
  emxArray_real_T *E1;
  int32_T cont;
  emxArray_real_T *backward_matrix;
  emxArray_real_T *forward_matrix;
  emxArray_real_T *extrinsic_matrix;
  emxArray_real_T *b_E2;
  emxArray_real_T *c_E2;
  int32_T d_E2[2];
  int32_T c_q[2];
  boolean_T j_ix;
  boolean_T exitg7;
  boolean_T k_ix;
  real_T b_index;
  int32_T s;
  real_T minimum;
  int32_T u;
  real_T varargin_1_idx_1;
  real_T index2;
  boolean_T exitg6;
  real_T b_forward_matrix[8];
  int32_T u_p;
  boolean_T exitg5;
  real_T index_b;
  real_T index_f;
  boolean_T l_ix;
  int32_T b_E1[2];
  int32_T d_q[2];
  boolean_T m_ix;
  boolean_T exitg4;
  boolean_T n_ix;
  boolean_T exitg3;
  boolean_T exitg2;
  boolean_T o_ix;
  int32_T e_E2[2];
  int32_T e_q[2];
  int32_T f_E2[2];
  int32_T c_E1[2];
  emxArray_int32_T *iindx;
  boolean_T p_ix;
  boolean_T exitg1;
  boolean_T q_ix;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &r_dep, 2, &b_emlrtRTEI, true);

  /*  CTC_DECODER: Basic CTC decoding through message passing  */
  /*  CRSC code component params */
  /* crsc_k = size(CRSC.P,2); */
  /* crsc_n = size(CRSC.P,1); */
  /* crsc_v = length(CRSC.G); */
  /*    piece_const = log(1+exp(-(0:5)));% TO IMPLEMENT AND SEE THE DIFFERENCE! */
  /*  De-puncturing of the received sequence in a N x (2n-k) matrix */
  iy = r_dep->size[0] * r_dep->size[1];
  if (!(N > 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &emlrtDCI, sp);
  }

  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &b_emlrtDCI, sp);
  }

  r_dep->size[0] = (int32_T)N;
  r_dep->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)r_dep, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (!(N > 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &emlrtDCI, sp);
  }

  d0 = N;
  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &b_emlrtDCI, sp);
  }

  itmp = (int32_T)d0 << 2;
  for (iy = 0; iy < itmp; iy++) {
    r_dep->data[iy] = 0.0;
  }

  index_r = 0.0;
  index_p = 0.0;
  emlrtForLoopVectorCheckR2012b(0.0, 1.0, N - 1.0, mxDOUBLE_CLASS, (int32_T)((N
    - 1.0) + 1.0), &p_emlrtRTEI, sp);
  i = 1;
  while (i - 1 <= (int32_T)((N - 1.0) + 1.0) - 1) {
    j = 0;
    while (j < 4) {
      iy = (int32_T)(index_p + 1.0);
      if (!((iy >= 1) && (iy <= 3456))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, 3456, &vc_emlrtBCI, sp);
      }

      if (puncturing_pattern[iy - 1] == 1.0) {
        iy = (int32_T)(index_r + 1.0);
        if (!((iy >= 1) && (iy <= 3456))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, 3456, &xc_emlrtBCI, sp);
        }

        cindx = r_dep->size[0];
        if (!((i >= 1) && (i <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, cindx, &yc_emlrtBCI, sp);
        }

        r_dep->data[(i + r_dep->size[0] * j) - 1] = r[iy - 1];
        index_r++;
      } else {
        iy = r_dep->size[0];
        if (!((i >= 1) && (i <= iy))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, iy, &wc_emlrtBCI, sp);
        }

        r_dep->data[(i + r_dep->size[0] * j) - 1] = 0.0;
      }

      index_p++;
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);

  /*  MESSAGE PASSING DECODING ALGORITHM */
  /*  1. INITIALIZATION */
  /*  1.1 The q vector is initialized to the a priori probability, */
  iy = r0->size[0] * r0->size[1];
  r0->size[0] = 4;
  r0->size[1] = (int32_T)N;
  emxEnsureCapacity(sp, (emxArray__common *)r0, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)N << 2;
  for (iy = 0; iy < itmp; iy++) {
    r0->data[iy] = 1.0;
  }

  emxInit_real_T(sp, &q, 2, &c_emlrtRTEI, true);
  rdivide(sp, r0, q);
  st.site = &emlrtRSI;
  b_log(&st, q);
  iy = q->size[0] * q->size[1];
  q->size[0] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)q, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = q->size[0];
  cindx = q->size[1];
  itmp *= cindx;
  emxFree_real_T(&r0);
  for (iy = 0; iy < itmp; iy++) {
    q->data[iy] = -q->data[iy];
  }

  emxInit_real_T(sp, &indx, 2, &emlrtRTEI, true);

  /*  Row: input  | Column: step l */
  st.site = &b_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  iy = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = q->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ix = 4;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  if (1 > q->size[1]) {
    overflow = false;
  } else {
    overflow = (q->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= q->size[1]; i++) {
    d_st.site = &v_emlrtRSI;
    b_ix = ix - 3;
    mtmp = q->data[ix - 4];
    if (muDoubleScalarIsNaN(q->data[ix - 4])) {
      e_st.site = &x_emlrtRSI;
      if (ix - 2 > ix) {
        c_ix = false;
      } else {
        c_ix = (ix > 2147483646);
      }

      if (c_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      d_ix = ix - 2;
      exitg10 = false;
      while ((!exitg10) && (d_ix <= ix)) {
        b_ix = d_ix;
        if (!muDoubleScalarIsNaN(q->data[d_ix - 1])) {
          mtmp = q->data[d_ix - 1];
          exitg10 = true;
        } else {
          d_ix++;
        }
      }
    }

    if (b_ix < ix) {
      e_st.site = &w_emlrtRSI;
      if (b_ix + 1 > ix) {
        e_ix = false;
      } else {
        e_ix = (ix > 2147483646);
      }

      if (e_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (b_ix + 1 <= ix) {
        if (q->data[b_ix] < mtmp) {
          mtmp = q->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    indx->data[iy] = mtmp;
    ix += 4;
  }

  emxInit_real_T(&c_st, &b_q, 2, &emlrtRTEI, true);
  iy = b_q->size[0] * b_q->size[1];
  b_q->size[0] = 4;
  b_q->size[1] = q->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_q, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = q->size[0] * q->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_q->data[iy] = q->data[iy];
  }

  emxInit_real_T(sp, &g1, 2, &d_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  bsxfun(&st, b_q, indx, q);

  /*  Normalization */
  /*  1.2 Two g vectors: g1 for the upper code and g2 for the lower one */
  iy = g1->size[0] * g1->size[1];
  g1->size[0] = 8;
  g1->size[1] = (int32_T)N;
  emxEnsureCapacity(sp, (emxArray__common *)g1, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)N << 3;
  emxFree_real_T(&b_q);
  for (iy = 0; iy < itmp; iy++) {
    g1->data[iy] = 0.0;
  }

  emxInit_real_T(sp, &g2, 2, &e_emlrtRTEI, true);

  /*  Row: output | Column: step l in blocks */
  iy = g2->size[0] * g2->size[1];
  g2->size[0] = 8;
  g2->size[1] = (int32_T)N;
  emxEnsureCapacity(sp, (emxArray__common *)g2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)N << 3;
  for (iy = 0; iy < itmp; iy++) {
    g2->data[iy] = 0.0;
  }

  emxInit_real_T(sp, &r1, 2, &f_emlrtRTEI, true);

  /*  Row: output | Column: step l in blocks    */
  /*  To compute g2 we use must rebuild the part due to the lower encoder */
  /*  using the inverse of the permutation matrix P^-1 = P^T */
  itmp = r_dep->size[0];
  iy = r1->size[0] * r1->size[1];
  r1->size[0] = itmp;
  r1->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)r1, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (iy = 0; iy < 3; iy++) {
    for (cindx = 0; cindx < itmp; cindx++) {
      r1->data[cindx + r1->size[0] * iy] = r_dep->data[cindx + r_dep->size[0] *
        iy];
    }
  }

  emxInit_real_T1(sp, &r2, 1, &g_emlrtRTEI, true);

  /* r2 = [reshape(P*(reshape(r_dep(:,[1,2]).', 1,[]).'),2,[]).',r_dep(:, crsc_n+1:end)]; */
  itmp = r_dep->size[0];
  iy = r2->size[0];
  r2->size[0] = itmp;
  emxEnsureCapacity(sp, (emxArray__common *)r2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (iy = 0; iy < itmp; iy++) {
    r2->data[iy] = r_dep->data[iy + r_dep->size[0] * 3];
  }

  emlrtForLoopVectorCheckR2012b(0.0, 1.0, N - 1.0, mxDOUBLE_CLASS, (int32_T)((N
    - 1.0) + 1.0), &q_emlrtRTEI, sp);
  l = 0;
  while (l <= (int32_T)((N - 1.0) + 1.0) - 1) {
    y = 0;
    while (y < 8) {
      mtmp = (real_T)l * 4.0;
      for (iy = 0; iy < 3; iy++) {
        cindx = (int32_T)(mtmp + (1.0 + (real_T)iy));
        if (!((cindx >= 1) && (cindx <= 3456))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, 3456, &sc_emlrtBCI, sp);
        }

        mod_y[iy] = modulation_table[y + (iy << 3)] * puncturing_pattern[cindx -
          1];
      }

      iy = r_dep->size[0];
      cindx = l + 1;
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &emlrtBCI, sp);
      }

      for (iy = 0; iy < 3; iy++) {
        b_r1[iy] = r1->data[l + r1->size[0] * iy] - mod_y[iy];
      }

      b_abs(b_r1, dv0);
      st.site = &c_emlrtRSI;
      power(dv0, dv1);
      iy = g1->size[1];
      if (!((l + 1 >= 1) && (l + 1 <= iy))) {
        emlrtDynamicBoundsCheckR2012b(l + 1, 1, iy, &tc_emlrtBCI, sp);
      }

      g1->data[y + g1->size[0] * l] = sum(dv1);
      iy = r_dep->size[0];
      cindx = l + 1;
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &b_emlrtBCI, sp);
      }

      mtmp = muDoubleScalarAbs(r2->data[l] - mod_y[2]);
      st.site = &d_emlrtRSI;
      b_st.site = &o_emlrtRSI;
      iy = g2->size[1];
      if (!((l + 1 >= 1) && (l + 1 <= iy))) {
        emlrtDynamicBoundsCheckR2012b(l + 1, 1, iy, &uc_emlrtBCI, sp);
      }

      g2->data[y + g2->size[0] * l] = mtmp * mtmp;
      y++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    l++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&r_dep);
  st.site = &e_emlrtRSI;
  mtmp = 2.0 * mpower(sigma_w);
  mtmp = 1.0 / mtmp;
  iy = g1->size[0] * g1->size[1];
  g1->size[0] = 8;
  emxEnsureCapacity(sp, (emxArray__common *)g1, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = g1->size[0];
  cindx = g1->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    g1->data[iy] *= mtmp;
  }

  st.site = &f_emlrtRSI;
  mtmp = 2.0 * mpower(sigma_w);
  mtmp = 1.0 / mtmp;
  iy = g2->size[0] * g2->size[1];
  g2->size[0] = 8;
  emxEnsureCapacity(sp, (emxArray__common *)g2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = g2->size[0];
  cindx = g2->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    g2->data[iy] *= mtmp;
  }

  st.site = &g_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  iy = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = g1->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ix = 8;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  if (1 > g1->size[1]) {
    overflow = false;
  } else {
    overflow = (g1->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= g1->size[1]; i++) {
    d_st.site = &v_emlrtRSI;
    b_ix = ix - 7;
    mtmp = g1->data[ix - 8];
    if (muDoubleScalarIsNaN(g1->data[ix - 8])) {
      e_st.site = &x_emlrtRSI;
      if (ix - 6 > ix) {
        f_ix = false;
      } else {
        f_ix = (ix > 2147483646);
      }

      if (f_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      d_ix = ix - 6;
      exitg9 = false;
      while ((!exitg9) && (d_ix <= ix)) {
        b_ix = d_ix;
        if (!muDoubleScalarIsNaN(g1->data[d_ix - 1])) {
          mtmp = g1->data[d_ix - 1];
          exitg9 = true;
        } else {
          d_ix++;
        }
      }
    }

    if (b_ix < ix) {
      e_st.site = &w_emlrtRSI;
      if (b_ix + 1 > ix) {
        g_ix = false;
      } else {
        g_ix = (ix > 2147483646);
      }

      if (g_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (b_ix + 1 <= ix) {
        if (g1->data[b_ix] < mtmp) {
          mtmp = g1->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    indx->data[iy] = mtmp;
    ix += 8;
  }

  emxInit_real_T(&c_st, &b_g1, 2, &emlrtRTEI, true);
  iy = b_g1->size[0] * b_g1->size[1];
  b_g1->size[0] = 8;
  b_g1->size[1] = g1->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_g1, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = g1->size[0] * g1->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_g1->data[iy] = g1->data[iy];
  }

  st.site = &g_emlrtRSI;
  b_bsxfun(&st, b_g1, indx, g1);

  /*  Normalization */
  st.site = &h_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  iy = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = g2->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ix = 8;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  emxFree_real_T(&b_g1);
  if (1 > g2->size[1]) {
    overflow = false;
  } else {
    overflow = (g2->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= g2->size[1]; i++) {
    d_st.site = &v_emlrtRSI;
    b_ix = ix - 7;
    mtmp = g2->data[ix - 8];
    if (muDoubleScalarIsNaN(g2->data[ix - 8])) {
      e_st.site = &x_emlrtRSI;
      if (ix - 6 > ix) {
        h_ix = false;
      } else {
        h_ix = (ix > 2147483646);
      }

      if (h_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      d_ix = ix - 6;
      exitg8 = false;
      while ((!exitg8) && (d_ix <= ix)) {
        b_ix = d_ix;
        if (!muDoubleScalarIsNaN(g2->data[d_ix - 1])) {
          mtmp = g2->data[d_ix - 1];
          exitg8 = true;
        } else {
          d_ix++;
        }
      }
    }

    if (b_ix < ix) {
      e_st.site = &w_emlrtRSI;
      if (b_ix + 1 > ix) {
        i_ix = false;
      } else {
        i_ix = (ix > 2147483646);
      }

      if (i_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (b_ix + 1 <= ix) {
        if (g2->data[b_ix] < mtmp) {
          mtmp = g2->data[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    indx->data[iy] = mtmp;
    ix += 8;
  }

  emxInit_real_T(&c_st, &b_g2, 2, &emlrtRTEI, true);
  iy = b_g2->size[0] * b_g2->size[1];
  b_g2->size[0] = 8;
  b_g2->size[1] = g2->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_g2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = g2->size[0] * g2->size[1];
  for (iy = 0; iy < itmp; iy++) {
    b_g2->data[iy] = g2->data[iy];
  }

  emxInit_real_T(sp, &E2, 2, &h_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  b_bsxfun(&st, b_g2, indx, g2);

  /*  Normalization */
  iy = E2->size[0] * E2->size[1];
  E2->size[0] = 4;
  E2->size[1] = (int32_T)N;
  emxEnsureCapacity(sp, (emxArray__common *)E2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)N << 2;
  emxFree_real_T(&b_g2);
  for (iy = 0; iy < itmp; iy++) {
    E2->data[iy] = 0.0;
  }

  emxInit_real_T(sp, &E1, 2, &i_emlrtRTEI, true);
  iy = E1->size[0] * E1->size[1];
  E1->size[0] = 4;
  E1->size[1] = (int32_T)N;
  emxEnsureCapacity(sp, (emxArray__common *)E1, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)N << 2;
  for (iy = 0; iy < itmp; iy++) {
    E1->data[iy] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n_it, mxDOUBLE_CLASS, (int32_T)n_it,
    &r_emlrtRTEI, sp);
  cont = 0;
  emxInit_real_T(sp, &backward_matrix, 2, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &forward_matrix, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &extrinsic_matrix, 2, &l_emlrtRTEI, true);
  emxInit_real_T(sp, &b_E2, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &c_E2, 2, &emlrtRTEI, true);
  while (cont <= (int32_T)n_it - 1) {
    /*  2 BCJR ALGORITHM ON THE UPPER CODE */
    /*  2.0 BCJR initialization  */
    iy = backward_matrix->size[0] * backward_matrix->size[1];
    backward_matrix->size[0] = 8;
    backward_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)backward_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      backward_matrix->data[iy] = rtInf;
    }

    /*  Row: state  | Column: step l */
    iy = forward_matrix->size[0] * forward_matrix->size[1];
    forward_matrix->size[0] = 8;
    forward_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)forward_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      forward_matrix->data[iy] = rtInf;
    }

    /*  Row: state  | Column: step l */
    iy = extrinsic_matrix->size[0] * extrinsic_matrix->size[1];
    extrinsic_matrix->size[0] = 4;
    extrinsic_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)extrinsic_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 2;
    for (iy = 0; iy < itmp; iy++) {
      extrinsic_matrix->data[iy] = rtInf;
    }

    /*  Row: input  | Column: step l */
    for (iy = 0; iy < 2; iy++) {
      d_E2[iy] = E2->size[iy];
    }

    for (iy = 0; iy < 2; iy++) {
      c_q[iy] = q->size[iy];
    }

    if ((d_E2[0] != c_q[0]) || (d_E2[1] != c_q[1])) {
      emlrtSizeEqCheckNDR2012b(&d_E2[0], &c_q[0], &emlrtECI, sp);
    }

    iy = E2->size[0] * E2->size[1];
    E2->size[0] = 4;
    emxEnsureCapacity(sp, (emxArray__common *)E2, iy, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    itmp = E2->size[0];
    cindx = E2->size[1];
    itmp *= cindx;
    for (iy = 0; iy < itmp; iy++) {
      E2->data[iy] += q->data[iy];
    }

    st.site = &i_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    iy = indx->size[0] * indx->size[1];
    indx->size[0] = 1;
    indx->size[1] = E2->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = 4;
    iy = -1;
    d_st.site = &u_emlrtRSI;
    if (1 > E2->size[1]) {
      overflow = false;
    } else {
      overflow = (E2->size[1] > 2147483646);
    }

    if (overflow) {
      e_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 1; i <= E2->size[1]; i++) {
      d_st.site = &v_emlrtRSI;
      b_ix = ix - 3;
      mtmp = E2->data[ix - 4];
      if (muDoubleScalarIsNaN(E2->data[ix - 4])) {
        e_st.site = &x_emlrtRSI;
        if (ix - 2 > ix) {
          j_ix = false;
        } else {
          j_ix = (ix > 2147483646);
        }

        if (j_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        d_ix = ix - 2;
        exitg7 = false;
        while ((!exitg7) && (d_ix <= ix)) {
          b_ix = d_ix;
          if (!muDoubleScalarIsNaN(E2->data[d_ix - 1])) {
            mtmp = E2->data[d_ix - 1];
            exitg7 = true;
          } else {
            d_ix++;
          }
        }
      }

      if (b_ix < ix) {
        e_st.site = &w_emlrtRSI;
        if (b_ix + 1 > ix) {
          k_ix = false;
        } else {
          k_ix = (ix > 2147483646);
        }

        if (k_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (b_ix + 1 <= ix) {
          if (E2->data[b_ix] < mtmp) {
            mtmp = E2->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      indx->data[iy] = mtmp;
      ix += 4;
    }

    iy = c_E2->size[0] * c_E2->size[1];
    c_E2->size[0] = 4;
    c_E2->size[1] = E2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)c_E2, iy, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    itmp = E2->size[0] * E2->size[1];
    for (iy = 0; iy < itmp; iy++) {
      c_E2->data[iy] = E2->data[iy];
    }

    st.site = &i_emlrtRSI;
    bsxfun(&st, c_E2, indx, E2);

    /*  Normalization */
    /*  2.1 Backward messages update */
    iy = (int32_T)N;
    cindx = (int32_T)N;
    if (!((cindx >= 1) && (cindx <= iy))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &f_emlrtBCI, sp);
    }

    backward_matrix->data[backward_matrix->size[0] * (cindx - 1)] = 0.0;

    /*  Starting with B_(N-1)(s_0) = 0  */
    d0 = 2.0 * N - 1.0;
    emlrtForLoopVectorCheckR2012b(d0, -1.0, 1.0, mxDOUBLE_CLASS, (int32_T)-(1.0
      + (-1.0 - d0)), &s_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)-(1.0 + (-1.0 - d0)) - 1) {
      /*  This is a matlab matrix index */
      b_index = b_mod(d0 + -(real_T)l, N);
      s = 0;
      while (s < 8) {
        /*  s_l */
        minimum = rtInf;

        /*  Sum over u  */
        u = 0;
        while (u < 4) {
          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &c_emlrtDCI, sp);
          }

          iy = E2->size[1];
          cindx = (int32_T)(b_index + 1.0);
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &c_emlrtBCI, sp);
          }

          mtmp = output_table[s + (u << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &d_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &d_emlrtBCI, sp);
          }

          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &e_emlrtDCI, sp);
          }

          iy = g1->size[1];
          cindx = (int32_T)(b_index + 1.0);
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &e_emlrtBCI, sp);
          }

          /*  s_(l+1) */
          mtmp = state_update_table[s + (u << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &f_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &g_emlrtBCI, sp);
          }

          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &g_emlrtDCI, sp);
          }

          iy = backward_matrix->size[1];
          cindx = (int32_T)(b_index + 1.0);
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &h_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (backward_matrix->data[((int32_T)
            (state_update_table[s + (u << 3)] + 1.0) + backward_matrix->size[0] *
            ((int32_T)(b_index + 1.0) - 1)) - 1] + g1->data[((int32_T)
            (output_table[s + (u << 3)] + 1.0) + g1->size[0] * ((int32_T)
            (b_index + 1.0) - 1)) - 1]) + E2->data[u + E2->size[0] * ((int32_T)
            (b_index + 1.0) - 1)];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          u++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        if (b_index == 0.0) {
          index2 = N;
        } else {
          index2 = b_index;
        }

        iy = backward_matrix->size[1];
        if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
          emlrtIntegerCheckR2012b(index2, &tb_emlrtDCI, sp);
        }

        cindx = (int32_T)index2;
        if (!((cindx >= 1) && (cindx <= iy))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &rc_emlrtBCI, sp);
        }

        backward_matrix->data[s + backward_matrix->size[0] * (cindx - 1)] =
          minimum;
        s++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
        emlrtIntegerCheckR2012b(index2, &h_emlrtDCI, sp);
      }

      iy = backward_matrix->size[1];
      cindx = (int32_T)index2;
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &j_emlrtBCI, sp);
      }

      cindx = 1;
      mtmp = backward_matrix->data[backward_matrix->size[0] * ((int32_T)index2 -
        1)];
      if (muDoubleScalarIsNaN(backward_matrix->data[backward_matrix->size[0] *
                              ((int32_T)index2 - 1)])) {
        ix = 2;
        exitg6 = false;
        while ((!exitg6) && (ix < 9)) {
          cindx = ix;
          if (!muDoubleScalarIsNaN(backward_matrix->data[(ix +
                backward_matrix->size[0] * ((int32_T)index2 - 1)) - 1])) {
            mtmp = backward_matrix->data[(ix + backward_matrix->size[0] *
              ((int32_T)index2 - 1)) - 1];
            exitg6 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (backward_matrix->data[cindx + backward_matrix->size[0] * ((int32_T)
               index2 - 1)] < mtmp) {
            mtmp = backward_matrix->data[cindx + backward_matrix->size[0] *
              ((int32_T)index2 - 1)];
          }

          cindx++;
        }
      }

      itmp = backward_matrix->size[1];
      iy = (int32_T)index2;
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &i_emlrtBCI, sp);
      }

      itmp = backward_matrix->size[1];
      iy = (int32_T)index2;
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &k_emlrtBCI, sp);
      }

      for (iy = 0; iy < 8; iy++) {
        b_forward_matrix[iy] = backward_matrix->data[iy + backward_matrix->size
          [0] * ((int32_T)index2 - 1)] - mtmp;
      }

      for (iy = 0; iy < 8; iy++) {
        backward_matrix->data[iy + backward_matrix->size[0] * ((int32_T)index2 -
          1)] = b_forward_matrix[iy];
      }

      /*  Normalization */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  2.2 Forward messages update */
    iy = (int32_T)N;
    if (!(1 <= iy)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, iy, &p_emlrtBCI, sp);
    }

    forward_matrix->data[0] = 0.0;

    /*  Starting with F_0 (s_0) = 0 */
    d0 = 2.0 * N;
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)(d0 +
      -1.0), &t_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)(d0 + -1.0) - 1) {
      /*  This is a matlab matrix index */
      b_index = b_mod((2.0 + (real_T)l) - 1.0, N);
      if (b_index == 0.0) {
        index2 = N;
      } else {
        index2 = b_index;
      }

      s = 0;
      while (s < 8) {
        /*  s_(l+1) */
        minimum = rtInf;

        /*  Sum over the neighbours of s */
        u_p = 0;
        while (u_p < 4) {
          if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
            emlrtIntegerCheckR2012b(index2, &i_emlrtDCI, sp);
          }

          iy = E2->size[1];
          cindx = (int32_T)index2;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &l_emlrtBCI, sp);
          }

          /*  s_l */
          mtmp = neighbours_table[s + (u_p << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &j_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &m_emlrtBCI, sp);
          }

          mtmp = output_table[((int32_T)(neighbours_table[s + (u_p << 3)] + 1.0)
                               + (u_p << 3)) - 1] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &k_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &n_emlrtBCI, sp);
          }

          iy = g1->size[1];
          cindx = (int32_T)index2;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &o_emlrtBCI, sp);
          }

          mtmp = neighbours_table[s + (u_p << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &l_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &q_emlrtBCI, sp);
          }

          iy = forward_matrix->size[1];
          cindx = (int32_T)index2;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &r_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (forward_matrix->data[((int32_T)(neighbours_table[s
            + (u_p << 3)] + 1.0) + forward_matrix->size[0] * ((int32_T)index2 -
            1)) - 1] + g1->data[((int32_T)(output_table[((int32_T)
            (neighbours_table[s + (u_p << 3)] + 1.0) + (u_p << 3)) - 1] + 1.0) +
            g1->size[0] * ((int32_T)index2 - 1)) - 1]) + E2->data[u_p + E2->
            size[0] * ((int32_T)index2 - 1)];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          u_p++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        iy = forward_matrix->size[1];
        if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
          emlrtIntegerCheckR2012b(b_index + 1.0, &sb_emlrtDCI, sp);
        }

        cindx = (int32_T)(b_index + 1.0);
        if (!((cindx >= 1) && (cindx <= iy))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &qc_emlrtBCI, sp);
        }

        forward_matrix->data[s + forward_matrix->size[0] * (cindx - 1)] =
          minimum;
        s++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &n_emlrtDCI, sp);
      }

      iy = forward_matrix->size[1];
      cindx = (int32_T)(b_index + 1.0);
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &t_emlrtBCI, sp);
      }

      cindx = 1;
      mtmp = forward_matrix->data[forward_matrix->size[0] * ((int32_T)(b_index +
        1.0) - 1)];
      if (muDoubleScalarIsNaN(forward_matrix->data[forward_matrix->size[0] *
                              ((int32_T)(b_index + 1.0) - 1)])) {
        ix = 2;
        exitg5 = false;
        while ((!exitg5) && (ix < 9)) {
          cindx = ix;
          if (!muDoubleScalarIsNaN(forward_matrix->data[(ix +
                forward_matrix->size[0] * ((int32_T)(b_index + 1.0) - 1)) - 1]))
          {
            mtmp = forward_matrix->data[(ix + forward_matrix->size[0] *
              ((int32_T)(b_index + 1.0) - 1)) - 1];
            exitg5 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (forward_matrix->data[cindx + forward_matrix->size[0] * ((int32_T)
               (b_index + 1.0) - 1)] < mtmp) {
            mtmp = forward_matrix->data[cindx + forward_matrix->size[0] *
              ((int32_T)(b_index + 1.0) - 1)];
          }

          cindx++;
        }
      }

      itmp = forward_matrix->size[1];
      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &m_emlrtDCI, sp);
      }

      iy = (int32_T)(b_index + 1.0);
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &s_emlrtBCI, sp);
      }

      itmp = forward_matrix->size[1];
      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &o_emlrtDCI, sp);
      }

      iy = (int32_T)(b_index + 1.0);
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &u_emlrtBCI, sp);
      }

      for (iy = 0; iy < 8; iy++) {
        b_forward_matrix[iy] = forward_matrix->data[iy + forward_matrix->size[0]
          * ((int32_T)(b_index + 1.0) - 1)] - mtmp;
      }

      for (iy = 0; iy < 8; iy++) {
        forward_matrix->data[iy + forward_matrix->size[0] * ((int32_T)(b_index +
          1.0) - 1)] = b_forward_matrix[iy];
      }

      /*  Normalization */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  2.3 Extrinsic message update */
    index_b = 1.0;
    index_f = 1.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, N, mxDOUBLE_CLASS, (int32_T)N,
      &u_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)N - 1) {
      /*  This is a matlab index! */
      u = 0;
      while (u < 4) {
        minimum = rtInf;
        s = 0;
        while (s < 8) {
          d0 = output_table[s + (u << 3)] + 1.0;
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &p_emlrtDCI, sp);
          }

          iy = (int32_T)d0;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &v_emlrtBCI, sp);
          }

          iy = g1->size[1];
          cindx = l + 1;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &w_emlrtBCI, sp);
          }

          iy = forward_matrix->size[1];
          cindx = (int32_T)index_f;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &x_emlrtBCI, sp);
          }

          d0 = state_update_table[s + (u << 3)] + 1.0;
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &q_emlrtDCI, sp);
          }

          iy = (int32_T)d0;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &y_emlrtBCI, sp);
          }

          iy = backward_matrix->size[1];
          cindx = (int32_T)index_b;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &ab_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (forward_matrix->data[s + forward_matrix->size[0] *
                              ((int32_T)index_f - 1)] + backward_matrix->data
                              [((int32_T)(state_update_table[s + (u << 3)] + 1.0)
                                + backward_matrix->size[0] * ((int32_T)index_b -
            1)) - 1]) + g1->data[((int32_T)(output_table[s + (u << 3)] + 1.0) +
            g1->size[0] * l) - 1];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          s++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        iy = extrinsic_matrix->size[1];
        if (!((l + 1 >= 1) && (l + 1 <= iy))) {
          emlrtDynamicBoundsCheckR2012b(l + 1, 1, iy, &pc_emlrtBCI, sp);
        }

        extrinsic_matrix->data[u + extrinsic_matrix->size[0] * l] = minimum;
        u++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      index_f++;
      index_b++;

      /*  index_b = mod(index_b + 1, N);         */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    st.site = &j_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    iy = indx->size[0] * indx->size[1];
    indx->size[0] = 1;
    indx->size[1] = extrinsic_matrix->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = 4;
    iy = -1;
    d_st.site = &u_emlrtRSI;
    if (1 > extrinsic_matrix->size[1]) {
      overflow = false;
    } else {
      overflow = (extrinsic_matrix->size[1] > 2147483646);
    }

    if (overflow) {
      e_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 1; i <= extrinsic_matrix->size[1]; i++) {
      d_st.site = &v_emlrtRSI;
      mtmp = extrinsic_matrix->data[ix - 4];
      if (ix - 3 < ix) {
        e_st.site = &w_emlrtRSI;
        if (ix - 2 > ix) {
          l_ix = false;
        } else {
          l_ix = (ix > 2147483646);
        }

        if (l_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (d_ix = ix - 3; d_ix + 1 <= ix; d_ix++) {
          if (extrinsic_matrix->data[d_ix] < mtmp) {
            mtmp = extrinsic_matrix->data[d_ix];
          }
        }
      }

      iy++;
      indx->data[iy] = mtmp;
      ix += 4;
    }

    st.site = &j_emlrtRSI;
    bsxfun(&st, extrinsic_matrix, indx, E1);

    /*  Normalization */
    /*  2.4 Message from the equality factor update */
    for (iy = 0; iy < 2; iy++) {
      b_E1[iy] = E1->size[iy];
    }

    for (iy = 0; iy < 2; iy++) {
      d_q[iy] = q->size[iy];
    }

    if ((b_E1[0] != d_q[0]) || (b_E1[1] != d_q[1])) {
      emlrtSizeEqCheckNDR2012b(&b_E1[0], &d_q[0], &b_emlrtECI, sp);
    }

    iy = E2->size[0] * E2->size[1];
    E2->size[0] = 4;
    E2->size[1] = E1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)E2, iy, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    itmp = E1->size[0] * E1->size[1];
    for (iy = 0; iy < itmp; iy++) {
      E2->data[iy] = E1->data[iy] + q->data[iy];
    }

    st.site = &k_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    iy = indx->size[0] * indx->size[1];
    indx->size[0] = 1;
    indx->size[1] = E2->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = 4;
    iy = -1;
    d_st.site = &u_emlrtRSI;
    if (1 > E2->size[1]) {
      overflow = false;
    } else {
      overflow = (E2->size[1] > 2147483646);
    }

    if (overflow) {
      e_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 1; i <= E2->size[1]; i++) {
      d_st.site = &v_emlrtRSI;
      b_ix = ix - 3;
      mtmp = E2->data[ix - 4];
      if (muDoubleScalarIsNaN(E2->data[ix - 4])) {
        e_st.site = &x_emlrtRSI;
        if (ix - 2 > ix) {
          m_ix = false;
        } else {
          m_ix = (ix > 2147483646);
        }

        if (m_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        d_ix = ix - 2;
        exitg4 = false;
        while ((!exitg4) && (d_ix <= ix)) {
          b_ix = d_ix;
          if (!muDoubleScalarIsNaN(E2->data[d_ix - 1])) {
            mtmp = E2->data[d_ix - 1];
            exitg4 = true;
          } else {
            d_ix++;
          }
        }
      }

      if (b_ix < ix) {
        e_st.site = &w_emlrtRSI;
        if (b_ix + 1 > ix) {
          n_ix = false;
        } else {
          n_ix = (ix > 2147483646);
        }

        if (n_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (b_ix + 1 <= ix) {
          if (E2->data[b_ix] < mtmp) {
            mtmp = E2->data[b_ix];
          }

          b_ix++;
        }
      }

      iy++;
      indx->data[iy] = mtmp;
      ix += 4;
    }

    iy = b_E2->size[0] * b_E2->size[1];
    b_E2->size[0] = 4;
    b_E2->size[1] = E2->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_E2, iy, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    itmp = E2->size[0] * E2->size[1];
    for (iy = 0; iy < itmp; iy++) {
      b_E2->data[iy] = E2->data[iy];
    }

    st.site = &k_emlrtRSI;
    bsxfun(&st, b_E2, indx, E2);

    /*  Normalization */
    /*  3 BCJR ALGORITHM ON THE LOWER CODE */
    /*  3.0 BCJR matrices initialization  */
    iy = backward_matrix->size[0] * backward_matrix->size[1];
    backward_matrix->size[0] = 8;
    backward_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)backward_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      backward_matrix->data[iy] = rtInf;
    }

    /*  Row: state  | Column: step l */
    iy = forward_matrix->size[0] * forward_matrix->size[1];
    forward_matrix->size[0] = 8;
    forward_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)forward_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 3;
    for (iy = 0; iy < itmp; iy++) {
      forward_matrix->data[iy] = rtInf;
    }

    /*  Row: state  | Column: step l */
    iy = extrinsic_matrix->size[0] * extrinsic_matrix->size[1];
    extrinsic_matrix->size[0] = 4;
    extrinsic_matrix->size[1] = (int32_T)N;
    emxEnsureCapacity(sp, (emxArray__common *)extrinsic_matrix, iy, (int32_T)
                      sizeof(real_T), &emlrtRTEI);
    itmp = (int32_T)N << 2;
    for (iy = 0; iy < itmp; iy++) {
      extrinsic_matrix->data[iy] = rtInf;
    }

    /*  Row: input  | Column: step l */
    /*  3.1 Backward message update */
    iy = (int32_T)N;
    cindx = (int32_T)N;
    if (!((cindx >= 1) && (cindx <= iy))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &fb_emlrtBCI, sp);
    }

    backward_matrix->data[backward_matrix->size[0] * (cindx - 1)] = 0.0;

    /*  Starting with B_(N-1)(s_0) = 0  */
    d0 = 2.0 * N - 1.0;
    emlrtForLoopVectorCheckR2012b(d0, -1.0, 1.0, mxDOUBLE_CLASS, (int32_T)-(1.0
      + (-1.0 - d0)), &v_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)-(1.0 + (-1.0 - d0)) - 1) {
      /*  This is a matlab matrix index */
      b_index = b_mod(d0 + -(real_T)l, N);
      s = 0;
      while (s < 8) {
        /*  s_l */
        minimum = rtInf;

        /*  Sum over u  */
        u = 0;
        while (u < 4) {
          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &qb_emlrtDCI, sp);
          }

          iy = (int32_T)(b_index + 1.0);
          if (!((iy >= 1) && (iy <= 864))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 864, &nc_emlrtBCI, sp);
          }

          mtmp = p_input_table[u + ((iy - 1) << 2)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &r_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 4))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 4, &bb_emlrtBCI, sp);
          }

          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &rb_emlrtDCI, sp);
          }

          iy = (int32_T)(b_index + 1.0);
          if (!((iy >= 1) && (iy <= 864))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 864, &oc_emlrtBCI, sp);
          }

          mtmp = p_step_table[u + ((iy - 1) << 2)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &s_emlrtDCI, sp);
          }

          iy = E2->size[1];
          cindx = (int32_T)mtmp;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &cb_emlrtBCI, sp);
          }

          mtmp = output_table[s + (u << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &t_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &db_emlrtBCI, sp);
          }

          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &u_emlrtDCI, sp);
          }

          iy = g2->size[1];
          cindx = (int32_T)(b_index + 1.0);
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &eb_emlrtBCI, sp);
          }

          /*  s_(l+1) */
          mtmp = state_update_table[s + (u << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &v_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &gb_emlrtBCI, sp);
          }

          if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
            emlrtIntegerCheckR2012b(b_index + 1.0, &w_emlrtDCI, sp);
          }

          iy = backward_matrix->size[1];
          cindx = (int32_T)(b_index + 1.0);
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &hb_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (backward_matrix->data[((int32_T)
            (state_update_table[s + (u << 3)] + 1.0) + backward_matrix->size[0] *
            ((int32_T)(b_index + 1.0) - 1)) - 1] + g2->data[((int32_T)
            (output_table[s + (u << 3)] + 1.0) + g2->size[0] * ((int32_T)
            (b_index + 1.0) - 1)) - 1]) + E2->data[((int32_T)(p_input_table[u +
            (((int32_T)(b_index + 1.0) - 1) << 2)] + 1.0) + E2->size[0] *
            ((int32_T)(p_step_table[u + (((int32_T)(b_index + 1.0) - 1) << 2)] +
                       1.0) - 1)) - 1];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          u++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        if (b_index == 0.0) {
          index2 = N;
        } else {
          index2 = b_index;
        }

        iy = backward_matrix->size[1];
        if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
          emlrtIntegerCheckR2012b(index2, &pb_emlrtDCI, sp);
        }

        cindx = (int32_T)index2;
        if (!((cindx >= 1) && (cindx <= iy))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &mc_emlrtBCI, sp);
        }

        backward_matrix->data[s + backward_matrix->size[0] * (cindx - 1)] =
          minimum;
        s++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
        emlrtIntegerCheckR2012b(index2, &x_emlrtDCI, sp);
      }

      iy = backward_matrix->size[1];
      cindx = (int32_T)index2;
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &jb_emlrtBCI, sp);
      }

      cindx = 1;
      mtmp = backward_matrix->data[backward_matrix->size[0] * ((int32_T)index2 -
        1)];
      if (muDoubleScalarIsNaN(backward_matrix->data[backward_matrix->size[0] *
                              ((int32_T)index2 - 1)])) {
        ix = 2;
        exitg3 = false;
        while ((!exitg3) && (ix < 9)) {
          cindx = ix;
          if (!muDoubleScalarIsNaN(backward_matrix->data[(ix +
                backward_matrix->size[0] * ((int32_T)index2 - 1)) - 1])) {
            mtmp = backward_matrix->data[(ix + backward_matrix->size[0] *
              ((int32_T)index2 - 1)) - 1];
            exitg3 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (backward_matrix->data[cindx + backward_matrix->size[0] * ((int32_T)
               index2 - 1)] < mtmp) {
            mtmp = backward_matrix->data[cindx + backward_matrix->size[0] *
              ((int32_T)index2 - 1)];
          }

          cindx++;
        }
      }

      itmp = backward_matrix->size[1];
      iy = (int32_T)index2;
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &ib_emlrtBCI, sp);
      }

      itmp = backward_matrix->size[1];
      iy = (int32_T)index2;
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &kb_emlrtBCI, sp);
      }

      for (iy = 0; iy < 8; iy++) {
        b_forward_matrix[iy] = backward_matrix->data[iy + backward_matrix->size
          [0] * ((int32_T)index2 - 1)] - mtmp;
      }

      for (iy = 0; iy < 8; iy++) {
        backward_matrix->data[iy + backward_matrix->size[0] * ((int32_T)index2 -
          1)] = b_forward_matrix[iy];
      }

      /*  Normalization */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  3.2 Forward messages update */
    iy = (int32_T)N;
    if (!(1 <= iy)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, iy, &qb_emlrtBCI, sp);
    }

    forward_matrix->data[0] = 0.0;

    /*  Starting with F_0 (s_0) = 0 */
    d0 = 2.0 * N;
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)(d0 +
      -1.0), &w_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)(d0 + -1.0) - 1) {
      /*  This is a matlab matrix index */
      b_index = b_mod((2.0 + (real_T)l) - 1.0, N);
      if (b_index == 0.0) {
        index2 = N;
      } else {
        index2 = b_index;
      }

      s = 0;
      while (s < 8) {
        /*  s_(l+1) */
        minimum = rtInf;

        /*  Sum over the neighbours of s */
        u_p = 0;
        while (u_p < 4) {
          if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
            emlrtIntegerCheckR2012b(index2, &nb_emlrtDCI, sp);
          }

          iy = (int32_T)index2;
          if (!((iy >= 1) && (iy <= 864))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 864, &kc_emlrtBCI, sp);
          }

          mtmp = p_input_table[u_p + ((iy - 1) << 2)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &y_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 4))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 4, &lb_emlrtBCI, sp);
          }

          if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
            emlrtIntegerCheckR2012b(index2, &ob_emlrtDCI, sp);
          }

          iy = (int32_T)index2;
          if (!((iy >= 1) && (iy <= 864))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 864, &lc_emlrtBCI, sp);
          }

          mtmp = p_step_table[u_p + ((iy - 1) << 2)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &ab_emlrtDCI, sp);
          }

          iy = E2->size[1];
          cindx = (int32_T)mtmp;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &mb_emlrtBCI, sp);
          }

          /*  s_l */
          mtmp = neighbours_table[s + (u_p << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &bb_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &nb_emlrtBCI, sp);
          }

          mtmp = output_table[((int32_T)(neighbours_table[s + (u_p << 3)] + 1.0)
                               + (u_p << 3)) - 1] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &cb_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &ob_emlrtBCI, sp);
          }

          if (index2 != (int32_T)muDoubleScalarFloor(index2)) {
            emlrtIntegerCheckR2012b(index2, &db_emlrtDCI, sp);
          }

          iy = g2->size[1];
          cindx = (int32_T)index2;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &pb_emlrtBCI, sp);
          }

          mtmp = neighbours_table[s + (u_p << 3)] + 1.0;
          if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
            emlrtIntegerCheckR2012b(mtmp, &eb_emlrtDCI, sp);
          }

          iy = (int32_T)mtmp;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &rb_emlrtBCI, sp);
          }

          iy = forward_matrix->size[1];
          cindx = (int32_T)index2;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &sb_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (forward_matrix->data[((int32_T)(neighbours_table[s
            + (u_p << 3)] + 1.0) + forward_matrix->size[0] * ((int32_T)index2 -
            1)) - 1] + g2->data[((int32_T)(output_table[((int32_T)
            (neighbours_table[s + (u_p << 3)] + 1.0) + (u_p << 3)) - 1] + 1.0) +
            g2->size[0] * ((int32_T)index2 - 1)) - 1]) + E2->data[((int32_T)
            (p_input_table[u_p + (((int32_T)index2 - 1) << 2)] + 1.0) + E2->
            size[0] * ((int32_T)(p_step_table[u_p + (((int32_T)index2 - 1) << 2)]
            + 1.0) - 1)) - 1];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          u_p++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        iy = forward_matrix->size[1];
        if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
          emlrtIntegerCheckR2012b(b_index + 1.0, &mb_emlrtDCI, sp);
        }

        cindx = (int32_T)(b_index + 1.0);
        if (!((cindx >= 1) && (cindx <= iy))) {
          emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &jc_emlrtBCI, sp);
        }

        forward_matrix->data[s + forward_matrix->size[0] * (cindx - 1)] =
          minimum;
        s++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &gb_emlrtDCI, sp);
      }

      iy = forward_matrix->size[1];
      cindx = (int32_T)(b_index + 1.0);
      if (!((cindx >= 1) && (cindx <= iy))) {
        emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &ub_emlrtBCI, sp);
      }

      cindx = 1;
      mtmp = forward_matrix->data[forward_matrix->size[0] * ((int32_T)(b_index +
        1.0) - 1)];
      if (muDoubleScalarIsNaN(forward_matrix->data[forward_matrix->size[0] *
                              ((int32_T)(b_index + 1.0) - 1)])) {
        ix = 2;
        exitg2 = false;
        while ((!exitg2) && (ix < 9)) {
          cindx = ix;
          if (!muDoubleScalarIsNaN(forward_matrix->data[(ix +
                forward_matrix->size[0] * ((int32_T)(b_index + 1.0) - 1)) - 1]))
          {
            mtmp = forward_matrix->data[(ix + forward_matrix->size[0] *
              ((int32_T)(b_index + 1.0) - 1)) - 1];
            exitg2 = true;
          } else {
            ix++;
          }
        }
      }

      if (cindx < 8) {
        while (cindx + 1 < 9) {
          if (forward_matrix->data[cindx + forward_matrix->size[0] * ((int32_T)
               (b_index + 1.0) - 1)] < mtmp) {
            mtmp = forward_matrix->data[cindx + forward_matrix->size[0] *
              ((int32_T)(b_index + 1.0) - 1)];
          }

          cindx++;
        }
      }

      itmp = forward_matrix->size[1];
      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &fb_emlrtDCI, sp);
      }

      iy = (int32_T)(b_index + 1.0);
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &tb_emlrtBCI, sp);
      }

      itmp = forward_matrix->size[1];
      if (b_index + 1.0 != (int32_T)muDoubleScalarFloor(b_index + 1.0)) {
        emlrtIntegerCheckR2012b(b_index + 1.0, &hb_emlrtDCI, sp);
      }

      iy = (int32_T)(b_index + 1.0);
      if (!((iy >= 1) && (iy <= itmp))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &vb_emlrtBCI, sp);
      }

      for (iy = 0; iy < 8; iy++) {
        b_forward_matrix[iy] = forward_matrix->data[iy + forward_matrix->size[0]
          * ((int32_T)(b_index + 1.0) - 1)] - mtmp;
      }

      for (iy = 0; iy < 8; iy++) {
        forward_matrix->data[iy + forward_matrix->size[0] * ((int32_T)(b_index +
          1.0) - 1)] = b_forward_matrix[iy];
      }

      /*  Normalization */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  3.3 Extrinsic message update */
    index_b = 1.0;
    index_f = 1.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, N, mxDOUBLE_CLASS, (int32_T)N,
      &x_emlrtRTEI, sp);
    l = 0;
    while (l <= (int32_T)N - 1) {
      /*  This is a matlab index! */
      u = 0;
      while (u < 4) {
        minimum = rtInf;
        s = 0;
        while (s < 8) {
          d0 = output_table[s + (u << 3)] + 1.0;
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &ib_emlrtDCI, sp);
          }

          iy = (int32_T)d0;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &wb_emlrtBCI, sp);
          }

          iy = g2->size[1];
          cindx = l + 1;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &xb_emlrtBCI, sp);
          }

          iy = forward_matrix->size[1];
          cindx = (int32_T)index_f;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &yb_emlrtBCI, sp);
          }

          d0 = state_update_table[s + (u << 3)] + 1.0;
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &jb_emlrtDCI, sp);
          }

          iy = (int32_T)d0;
          if (!((iy >= 1) && (iy <= 8))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, 8, &ac_emlrtBCI, sp);
          }

          iy = backward_matrix->size[1];
          cindx = (int32_T)index_b;
          if (!((cindx >= 1) && (cindx <= iy))) {
            emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &bc_emlrtBCI, sp);
          }

          /*  TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION */
          varargin_1_idx_1 = (forward_matrix->data[s + forward_matrix->size[0] *
                              ((int32_T)index_f - 1)] + backward_matrix->data
                              [((int32_T)(state_update_table[s + (u << 3)] + 1.0)
                                + backward_matrix->size[0] * ((int32_T)index_b -
            1)) - 1]) + g2->data[((int32_T)(output_table[s + (u << 3)] + 1.0) +
            g2->size[0] * l) - 1];
          mtmp = minimum;
          if (varargin_1_idx_1 < minimum) {
            mtmp = varargin_1_idx_1;
          }

          minimum = mtmp;
          s++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        /* extrinsic_matrix(u+1, l) = summ; */
        if (!((l + 1 >= 1) && (l + 1 <= 864))) {
          emlrtDynamicBoundsCheckR2012b(l + 1, 1, 864, &gc_emlrtBCI, sp);
        }

        d0 = p_input_table[u + (l << 2)] + 1.0;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &kb_emlrtDCI, sp);
        }

        iy = (int32_T)d0;
        if (!((iy >= 1) && (iy <= 4))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, 4, &fc_emlrtBCI, sp);
        }

        cindx = extrinsic_matrix->size[1];
        if (!((l + 1 >= 1) && (l + 1 <= 864))) {
          emlrtDynamicBoundsCheckR2012b(l + 1, 1, 864, &ic_emlrtBCI, sp);
        }

        d0 = p_step_table[u + (l << 2)] + 1.0;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &lb_emlrtDCI, sp);
        }

        itmp = (int32_T)d0;
        if (!((itmp >= 1) && (itmp <= cindx))) {
          emlrtDynamicBoundsCheckR2012b(itmp, 1, cindx, &hc_emlrtBCI, sp);
        }

        extrinsic_matrix->data[(iy + extrinsic_matrix->size[0] * (itmp - 1)) - 1]
          = minimum;
        u++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      index_f++;
      index_b++;

      /*  index_b = mod(index_b + 1, N);         */
      l++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    st.site = &l_emlrtRSI;
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    iy = indx->size[0] * indx->size[1];
    indx->size[0] = 1;
    indx->size[1] = extrinsic_matrix->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)indx, iy, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = 4;
    iy = -1;
    d_st.site = &u_emlrtRSI;
    if (1 > extrinsic_matrix->size[1]) {
      overflow = false;
    } else {
      overflow = (extrinsic_matrix->size[1] > 2147483646);
    }

    if (overflow) {
      e_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (i = 1; i <= extrinsic_matrix->size[1]; i++) {
      d_st.site = &v_emlrtRSI;
      mtmp = extrinsic_matrix->data[ix - 4];
      if (ix - 3 < ix) {
        e_st.site = &w_emlrtRSI;
        if (ix - 2 > ix) {
          o_ix = false;
        } else {
          o_ix = (ix > 2147483646);
        }

        if (o_ix) {
          f_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (d_ix = ix - 3; d_ix + 1 <= ix; d_ix++) {
          if (extrinsic_matrix->data[d_ix] < mtmp) {
            mtmp = extrinsic_matrix->data[d_ix];
          }
        }
      }

      iy++;
      indx->data[iy] = mtmp;
      ix += 4;
    }

    st.site = &l_emlrtRSI;
    bsxfun(&st, extrinsic_matrix, indx, E2);

    /*  Normalization */
    cont++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_E2);
  emxFree_real_T(&b_E2);
  emxFree_real_T(&extrinsic_matrix);
  emxFree_real_T(&forward_matrix);
  emxFree_real_T(&backward_matrix);
  emxFree_real_T(&g2);
  emxFree_real_T(&g1);

  /*  Maximum a posteriori estimate */
  for (iy = 0; iy < 2; iy++) {
    e_E2[iy] = E2->size[iy];
  }

  for (iy = 0; iy < 2; iy++) {
    e_q[iy] = q->size[iy];
  }

  if ((e_E2[0] != e_q[0]) || (e_E2[1] != e_q[1])) {
    emlrtSizeEqCheckNDR2012b(&e_E2[0], &e_q[0], &c_emlrtECI, sp);
  }

  for (iy = 0; iy < 2; iy++) {
    f_E2[iy] = E2->size[iy];
  }

  for (iy = 0; iy < 2; iy++) {
    c_E1[iy] = E1->size[iy];
  }

  if ((f_E2[0] != c_E1[0]) || (f_E2[1] != c_E1[1])) {
    emlrtSizeEqCheckNDR2012b(&f_E2[0], &c_E1[0], &c_emlrtECI, sp);
  }

  st.site = &m_emlrtRSI;
  iy = E2->size[0] * E2->size[1];
  E2->size[0] = 4;
  emxEnsureCapacity(&st, (emxArray__common *)E2, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = E2->size[0];
  cindx = E2->size[1];
  itmp *= cindx;
  for (iy = 0; iy < itmp; iy++) {
    E2->data[iy] = (E2->data[iy] + q->data[iy]) + E1->data[iy];
  }

  emxFree_real_T(&E1);
  emxFree_real_T(&q);
  emxInit_int32_T(&st, &iindx, 2, &emlrtRTEI, true);
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  varargin_1_idx_1 = (uint32_T)E2->size[1];
  iy = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  iindx->size[1] = (int32_T)varargin_1_idx_1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, iy, (int32_T)sizeof
                    (int32_T), &emlrtRTEI);
  itmp = (int32_T)varargin_1_idx_1;
  for (iy = 0; iy < itmp; iy++) {
    iindx->data[iy] = 1;
  }

  ix = 4;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  if (1 > E2->size[1]) {
    overflow = false;
  } else {
    overflow = (E2->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (i = 1; i <= E2->size[1]; i++) {
    d_st.site = &v_emlrtRSI;
    b_ix = ix - 3;
    mtmp = E2->data[ix - 4];
    itmp = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(E2->data[ix - 4])) {
      e_st.site = &x_emlrtRSI;
      if (ix - 2 > ix) {
        p_ix = false;
      } else {
        p_ix = (ix > 2147483646);
      }

      if (p_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      d_ix = ix - 2;
      exitg1 = false;
      while ((!exitg1) && (d_ix <= ix)) {
        cindx++;
        b_ix = d_ix;
        if (!muDoubleScalarIsNaN(E2->data[d_ix - 1])) {
          mtmp = E2->data[d_ix - 1];
          itmp = cindx;
          exitg1 = true;
        } else {
          d_ix++;
        }
      }
    }

    if (b_ix < ix) {
      e_st.site = &w_emlrtRSI;
      if (b_ix + 1 > ix) {
        q_ix = false;
      } else {
        q_ix = (ix > 2147483646);
      }

      if (q_ix) {
        f_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (b_ix + 1 <= ix) {
        cindx++;
        if (E2->data[b_ix] < mtmp) {
          mtmp = E2->data[b_ix];
          itmp = cindx;
        }

        b_ix++;
      }
    }

    iy++;
    iindx->data[iy] = itmp;
    ix += 4;
  }

  emxFree_real_T(&E2);
  iy = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)indx, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = iindx->size[0] * iindx->size[1];
  for (iy = 0; iy < itmp; iy++) {
    indx->data[iy] = iindx->data[iy];
  }

  emxFree_int32_T(&iindx);
  iy = u_hat->size[0];
  u_hat->size[0] = (int32_T)((real_T)indx->size[1] * 2.0);
  emxEnsureCapacity(sp, (emxArray__common *)u_hat, iy, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  itmp = (int32_T)((real_T)indx->size[1] * 2.0);
  for (iy = 0; iy < itmp; iy++) {
    u_hat->data[iy] = 0.0;
  }

  /* num2input = @(i) mod(fix(i./(2.^(crsc_k-1:-1:0)).'),2); */
  i = 0;
  while (i <= indx->size[1] - 1) {
    /*  From u_hat_num to u_hat */
    /* u_hat(crsc_k*i+1:crsc_k*i+crsc_k) = num2input(u_hat_num(i+1)-1); */
    iy = indx->size[1];
    cindx = i + 1;
    if (!((cindx >= 1) && (cindx <= iy))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &cc_emlrtBCI, sp);
    }

    iy = u_hat->size[0];
    cindx = (int32_T)(((uint32_T)i << 1) + 2U);
    if (!((cindx >= 1) && (cindx <= iy))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &dc_emlrtBCI, sp);
    }

    u_hat->data[cindx - 1] = b_mod(indx->data[i] - 1.0, 2.0);
    d0 = (indx->data[i] - 1.0) / 2.0;
    b_fix(&d0);
    iy = u_hat->size[0];
    cindx = (int32_T)(((uint32_T)i << 1) + 1U);
    if (!((cindx >= 1) && (cindx <= iy))) {
      emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &ec_emlrtBCI, sp);
    }

    u_hat->data[cindx - 1] = b_mod(d0, 2.0);
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&indx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (CTC_dec_minsum.c) */
