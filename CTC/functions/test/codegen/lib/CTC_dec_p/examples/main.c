/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Jul-2016 13:26:50
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "CTC_dec_p.h"
#include "main.h"
#include "CTC_dec_p_terminate.h"
#include "CTC_dec_p_emxAPI.h"
#include "CTC_dec_p_initialize.h"

/* Function Declarations */
static void argInit_4xd960_real_T(double result_data[], int result_size[2]);
static void argInit_8x3_real_T(double result[24]);
static void argInit_8x4_real_T(double result[32]);
static void argInit_d3840x1_real_T(double result_data[], int result_size[1]);
static double argInit_real_T(void);
static void main_CTC_dec_p(void);

/* Function Definitions */

/*
 * Arguments    : double result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_4xd960_real_T(double result_data[], int result_size[2])
{
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 4;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result_data[idx0 + 4 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[24]
 * Return Type  : void
 */
static void argInit_8x3_real_T(double result[24])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 8; idx0++) {
    for (idx1 = 0; idx1 < 3; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 3)] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[32]
 * Return Type  : void
 */
static void argInit_8x4_real_T(double result[32])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 8; idx0++) {
    for (idx1 = 0; idx1 < 4; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 3)] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result_data[]
 *                int result_size[1]
 * Return Type  : void
 */
static void argInit_d3840x1_real_T(double result_data[], int result_size[1])
{
  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CTC_dec_p(void)
{
  emxArray_real_T *u_hat;
  int r_size[1];
  double r_data[3840];
  double state_update_table[32];
  double output_table[32];
  double neighbours_table[32];
  double modulation_table[24];
  double sigma_w;
  double N;
  double n_it;
  int p_input_table_size[2];
  double p_input_table_data[3840];
  int p_step_table_size[2];
  double p_step_table_data[3840];
  int puncturing_pattern_size[1];
  double puncturing_pattern_data[3840];
  emxInitArray_real_T(&u_hat, 1);

  /* Initialize function 'CTC_dec_p' input arguments. */
  /* Initialize function input argument 'r'. */
  argInit_d3840x1_real_T(r_data, r_size);

  /* Initialize function input argument 'state_update_table'. */
  argInit_8x4_real_T(state_update_table);

  /* Initialize function input argument 'output_table'. */
  argInit_8x4_real_T(output_table);

  /* Initialize function input argument 'neighbours_table'. */
  argInit_8x4_real_T(neighbours_table);

  /* Initialize function input argument 'modulation_table'. */
  argInit_8x3_real_T(modulation_table);
  sigma_w = argInit_real_T();
  N = argInit_real_T();
  n_it = argInit_real_T();

  /* Initialize function input argument 'p_input_table'. */
  argInit_4xd960_real_T(p_input_table_data, p_input_table_size);

  /* Initialize function input argument 'p_step_table'. */
  argInit_4xd960_real_T(p_step_table_data, p_step_table_size);

  /* Initialize function input argument 'puncturing_pattern'. */
  argInit_d3840x1_real_T(puncturing_pattern_data, puncturing_pattern_size);

  /* Call the entry-point 'CTC_dec_p'. */
  CTC_dec_p(r_data, r_size, state_update_table, output_table, neighbours_table,
            modulation_table, sigma_w, N, n_it, p_input_table_data,
            p_input_table_size, p_step_table_data, p_step_table_size,
            puncturing_pattern_data, puncturing_pattern_size, u_hat);
  emxDestroyArray_real_T(u_hat);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  CTC_dec_p_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CTC_dec_p();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CTC_dec_p_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
