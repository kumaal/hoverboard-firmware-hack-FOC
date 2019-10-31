/*
 * File: BLDC_controller.c
 *
 * Code generated for Simulink model 'BLDC_controller'.
 *
 * Model version                  : 1.1197
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Oct 31 21:29:42 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "BLDC_controller.h"

/* Named constants for Chart: '<S4>/F03_02_Control_Mode_Manager' */
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_OPEN                        ((uint8_T)2U)
#define IN_SPEED_MODE                  ((uint8_T)1U)
#define IN_TORQUE_MODE                 ((uint8_T)2U)
#define IN_VOLTAGE_MODE                ((uint8_T)3U)
#define OPEN_MODE                      ((uint8_T)0U)
#define SPD_MODE                       ((uint8_T)2U)
#define TRQ_MODE                       ((uint8_T)3U)
#define VLT_MODE                       ((uint8_T)1U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if 0

/* Skip this size verification because of preprocessor limitation */
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

uint8_T plook_u8u16_evencka(uint16_T u, uint16_T bp0, uint16_T bpSpace, uint32_T
  maxIndex);
uint8_T plook_u8s16_evencka(int16_T u, int16_T bp0, uint16_T bpSpace, uint32_T
  maxIndex);
uint8_T plook_u8s16u8n6_evenc_s(int16_T u, int16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint8_T *fraction);
int16_T intrp1d_s16s32s32u8u8n6l_s(uint8_T bpIndex, uint8_T frac, const int16_T
  table[]);
extern void Counter_Init(DW_Counter *localDW, int16_T rtp_z_cntInit);
extern int16_T Counter(int16_T rtu_inc, int16_T rtu_max, boolean_T rtu_rst,
  DW_Counter *localDW);
extern void PI_clamp_fixdt_Reset(DW_PI_clamp_fixdt *localDW);
extern void PI_clamp_fixdt(int16_T rtu_err, uint16_T rtu_P, uint16_T rtu_I,
  int16_T rtu_satMax, int16_T rtu_satMin, int32_T rtu_ext_limProt, int16_T
  *rty_out, DW_PI_clamp_fixdt *localDW);
extern void Low_Pass_Filter_Reset(DW_Low_Pass_Filter *localDW);
extern void Low_Pass_Filter(const int16_T rtu_u[2], uint16_T rtu_coef, int16_T
  rty_y[2], DW_Low_Pass_Filter *localDW);
extern void PI_clamp_fixdt_n_Reset(DW_PI_clamp_fixdt_c *localDW);
extern int16_T PI_clamp_fixdt_n(int16_T rtu_err, uint16_T rtu_P, uint16_T rtu_I,
  int16_T rtu_satMax, int16_T rtu_satMin, int16_T rtu_ext_limProt,
  DW_PI_clamp_fixdt_c *localDW);
extern void Counter_b_Init(DW_Counter_l *localDW, uint16_T rtp_z_cntInit);
extern uint16_T Counter_i(uint16_T rtu_inc, uint16_T rtu_max, boolean_T rtu_rst,
  DW_Counter_l *localDW);
extern void either_edge_Reset(DW_either_edge *localDW);
extern boolean_T either_edge(boolean_T rtu_u, DW_either_edge *localDW);
extern void Debounce_Filter_Init(DW_Debounce_Filter *localDW);
extern void Debounce_Filter_Reset(DW_Debounce_Filter *localDW);
extern void Debounce_Filter(boolean_T rtu_u, uint16_T rtu_tAcv, uint16_T
  rtu_tDeacv, boolean_T *rty_y, DW_Debounce_Filter *localDW);
uint8_T plook_u8u16_evencka(uint16_T u, uint16_T bp0, uint16_T bpSpace, uint32_T
  maxIndex)
{
  uint8_T bpIndex;
  uint16_T fbpIndex;

  /* Prelookup - Index only
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
  } else {
    fbpIndex = (uint16_T)((uint32_T)(uint16_T)((uint32_T)u - bp0) / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint8_T)fbpIndex;
    } else {
      bpIndex = (uint8_T)maxIndex;
    }
  }

  return bpIndex;
}

uint8_T plook_u8s16_evencka(int16_T u, int16_T bp0, uint16_T bpSpace, uint32_T
  maxIndex)
{
  uint8_T bpIndex;
  uint16_T fbpIndex;

  /* Prelookup - Index only
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
  } else {
    fbpIndex = (uint16_T)((uint32_T)(uint16_T)(u - bp0) / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint8_T)fbpIndex;
    } else {
      bpIndex = (uint8_T)maxIndex;
    }
  }

  return bpIndex;
}

uint8_T plook_u8s16u8n6_evenc_s(int16_T u, int16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint8_T *fraction)
{
  uint8_T bpIndex;
  uint16_T uAdjust;
  uint16_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0U;
  } else {
    uAdjust = (uint16_T)(u - bp0);
    fbpIndex = (uint16_T)((uint32_T)uAdjust / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint8_T)fbpIndex;
      *fraction = (uint8_T)(((uint32_T)(uint16_T)((uint32_T)uAdjust - (uint16_T)
        ((uint32_T)bpIndex * bpSpace)) << 6) / bpSpace);
    } else {
      bpIndex = (uint8_T)(maxIndex - 1U);
      *fraction = 64U;
    }
  }

  return bpIndex;
}

int16_T intrp1d_s16s32s32u8u8n6l_s(uint8_T bpIndex, uint8_T frac, const int16_T
  table[])
{
  uint32_T offset_0d;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_0d = bpIndex;
  return (int16_T)((int16_T)(((table[offset_0d + 1U] - table[offset_0d]) * frac)
    >> 6) + table[offset_0d]);
}

/* System initialize for atomic system: '<S11>/Counter' */
void Counter_Init(DW_Counter *localDW, int16_T rtp_z_cntInit)
{
  /* InitializeConditions for UnitDelay: '<S17>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtp_z_cntInit;
}

/* Output and update for atomic system: '<S11>/Counter' */
int16_T Counter(int16_T rtu_inc, int16_T rtu_max, boolean_T rtu_rst, DW_Counter *
                localDW)
{
  int16_T rtu_rst_0;
  int16_T rty_cnt_0;

  /* Switch: '<S17>/Switch1' incorporates:
   *  Constant: '<S17>/Constant23'
   *  UnitDelay: '<S17>/UnitDelay'
   */
  if (rtu_rst) {
    rtu_rst_0 = 0;
  } else {
    rtu_rst_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Sum: '<S15>/Sum1' */
  rty_cnt_0 = (int16_T)(rtu_inc + rtu_rst_0);

  /* MinMax: '<S15>/MinMax' */
  if (rty_cnt_0 < rtu_max) {
    /* Update for UnitDelay: '<S17>/UnitDelay' */
    localDW->UnitDelay_DSTATE = rty_cnt_0;
  } else {
    /* Update for UnitDelay: '<S17>/UnitDelay' */
    localDW->UnitDelay_DSTATE = rtu_max;
  }

  /* End of MinMax: '<S15>/MinMax' */
  return rty_cnt_0;
}

/*
 * System reset for atomic system:
 *    '<S40>/PI_clamp_fixdt_id'
 *    '<S39>/PI_clamp_fixdt_iq'
 */
void PI_clamp_fixdt_Reset(DW_PI_clamp_fixdt *localDW)
{
  /* InitializeConditions for UnitDelay: '<S62>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = false;

  /* InitializeConditions for UnitDelay: '<S65>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0;
}

/*
 * Output and update for atomic system:
 *    '<S40>/PI_clamp_fixdt_id'
 *    '<S39>/PI_clamp_fixdt_iq'
 */
void PI_clamp_fixdt(int16_T rtu_err, uint16_T rtu_P, uint16_T rtu_I, int16_T
                    rtu_satMax, int16_T rtu_satMin, int32_T rtu_ext_limProt,
                    int16_T *rty_out, DW_PI_clamp_fixdt *localDW)
{
  boolean_T rtb_LowerRelop1_e;
  boolean_T rtb_UpperRelop_f;
  int32_T rtb_Sum1_b4;
  int32_T q0;
  int32_T tmp;
  int16_T tmp_0;

  /* Sum: '<S62>/Sum2' incorporates:
   *  Product: '<S62>/Divide2'
   */
  q0 = rtu_err * rtu_I;
  if ((q0 < 0) && (rtu_ext_limProt < MIN_int32_T - q0)) {
    q0 = MIN_int32_T;
  } else if ((q0 > 0) && (rtu_ext_limProt > MAX_int32_T - q0)) {
    q0 = MAX_int32_T;
  } else {
    q0 += rtu_ext_limProt;
  }

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/a_elecPeriod1'
   *  Sum: '<S62>/Sum2'
   *  UnitDelay: '<S62>/UnitDelay1'
   */
  if (localDW->UnitDelay1_DSTATE) {
    tmp = 0;
  } else {
    tmp = q0;
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Sum: '<S65>/Sum1' incorporates:
   *  UnitDelay: '<S65>/UnitDelay'
   */
  rtb_Sum1_b4 = tmp + localDW->UnitDelay_DSTATE;

  /* Product: '<S62>/Divide5' */
  tmp = (rtu_err * rtu_P) >> 11;
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  /* Sum: '<S62>/Sum1' incorporates:
   *  DataTypeConversion: '<S65>/Data Type Conversion1'
   *  Product: '<S62>/Divide5'
   */
  tmp = (((rtb_Sum1_b4 >> 16) << 1) + tmp) >> 1;
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  /* RelationalOperator: '<S66>/LowerRelop1' incorporates:
   *  Sum: '<S62>/Sum1'
   */
  rtb_LowerRelop1_e = ((int16_T)tmp > rtu_satMax);

  /* RelationalOperator: '<S66>/UpperRelop' incorporates:
   *  Sum: '<S62>/Sum1'
   */
  rtb_UpperRelop_f = ((int16_T)tmp < rtu_satMin);

  /* Switch: '<S66>/Switch1' incorporates:
   *  Sum: '<S62>/Sum1'
   *  Switch: '<S66>/Switch3'
   */
  if (rtb_LowerRelop1_e) {
    *rty_out = rtu_satMax;
  } else if (rtb_UpperRelop_f) {
    /* Switch: '<S66>/Switch3' */
    *rty_out = rtu_satMin;
  } else {
    *rty_out = (int16_T)tmp;
  }

  /* End of Switch: '<S66>/Switch1' */

  /* Signum: '<S64>/SignDeltaU2' incorporates:
   *  Sum: '<S62>/Sum2'
   */
  if (q0 < 0) {
    q0 = -1;
  } else {
    q0 = (q0 > 0);
  }

  /* End of Signum: '<S64>/SignDeltaU2' */

  /* Signum: '<S64>/SignDeltaU3' incorporates:
   *  Sum: '<S62>/Sum1'
   */
  if ((int16_T)tmp < 0) {
    tmp_0 = -1;
  } else {
    tmp_0 = (int16_T)((int16_T)tmp > 0);
  }

  /* End of Signum: '<S64>/SignDeltaU3' */

  /* Update for UnitDelay: '<S62>/UnitDelay1' incorporates:
   *  DataTypeConversion: '<S64>/DataTypeConv4'
   *  Logic: '<S62>/AND1'
   *  Logic: '<S64>/AND1'
   *  RelationalOperator: '<S64>/Equal1'
   */
  localDW->UnitDelay1_DSTATE = ((q0 == tmp_0) && (rtb_LowerRelop1_e ||
    rtb_UpperRelop_f));

  /* Update for UnitDelay: '<S65>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtb_Sum1_b4;
}

/* System reset for atomic system: '<S31>/Low_Pass_Filter' */
void Low_Pass_Filter_Reset(DW_Low_Pass_Filter *localDW)
{
  /* InitializeConditions for UnitDelay: '<S44>/UnitDelay3' */
  localDW->UnitDelay3_DSTATE[0] = 0;
  localDW->UnitDelay3_DSTATE[1] = 0;
}

/* Output and update for atomic system: '<S31>/Low_Pass_Filter' */
void Low_Pass_Filter(const int16_T rtu_u[2], uint16_T rtu_coef, int16_T rty_y[2],
                     DW_Low_Pass_Filter *localDW)
{
  uint16_T rtb_Sum5;

  /* Sum: '<S44>/Sum5' */
  rtb_Sum5 = (uint16_T)(65535U - rtu_coef);

  /* Sum: '<S44>/Sum1' incorporates:
   *  Product: '<S44>/Divide1'
   *  Product: '<S44>/Divide2'
   *  UnitDelay: '<S44>/UnitDelay3'
   */
  rty_y[0] = (int16_T)(((rtu_u[0] * rtu_coef) >> 16) +
                       ((localDW->UnitDelay3_DSTATE[0] * rtb_Sum5) >> 16));

  /* Update for UnitDelay: '<S44>/UnitDelay3' */
  localDW->UnitDelay3_DSTATE[0] = rty_y[0];

  /* Sum: '<S44>/Sum1' incorporates:
   *  Product: '<S44>/Divide1'
   *  Product: '<S44>/Divide2'
   *  UnitDelay: '<S44>/UnitDelay3'
   */
  rty_y[1] = (int16_T)(((rtu_u[1] * rtu_coef) >> 16) +
                       ((localDW->UnitDelay3_DSTATE[1] * rtb_Sum5) >> 16));

  /* Update for UnitDelay: '<S44>/UnitDelay3' */
  localDW->UnitDelay3_DSTATE[1] = rty_y[1];
}

/* System reset for atomic system: '<S38>/PI_clamp_fixdt_n' */
void PI_clamp_fixdt_n_Reset(DW_PI_clamp_fixdt_c *localDW)
{
  /* InitializeConditions for UnitDelay: '<S53>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = false;

  /* InitializeConditions for UnitDelay: '<S55>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0;
}

/* Output and update for atomic system: '<S38>/PI_clamp_fixdt_n' */
int16_T PI_clamp_fixdt_n(int16_T rtu_err, uint16_T rtu_P, uint16_T rtu_I,
  int16_T rtu_satMax, int16_T rtu_satMin, int16_T rtu_ext_limProt,
  DW_PI_clamp_fixdt_c *localDW)
{
  boolean_T rtb_LowerRelop1_ge;
  boolean_T rtb_UpperRelop_cm;
  int32_T rtb_Sum1_mz;
  int32_T q0;
  int32_T q1;
  int16_T tmp;
  int16_T rty_out_0;

  /* Sum: '<S53>/Sum2' incorporates:
   *  Product: '<S53>/Divide2'
   */
  q0 = rtu_err * rtu_I;
  q1 = rtu_ext_limProt << 10;
  if ((q0 < 0) && (q1 < MIN_int32_T - q0)) {
    q0 = MIN_int32_T;
  } else if ((q0 > 0) && (q1 > MAX_int32_T - q0)) {
    q0 = MAX_int32_T;
  } else {
    q0 += q1;
  }

  /* Switch: '<S53>/Switch1' incorporates:
   *  Constant: '<S53>/a_elecPeriod1'
   *  Sum: '<S53>/Sum2'
   *  UnitDelay: '<S53>/UnitDelay1'
   */
  if (localDW->UnitDelay1_DSTATE) {
    q1 = 0;
  } else {
    q1 = q0;
  }

  /* End of Switch: '<S53>/Switch1' */

  /* Sum: '<S55>/Sum1' incorporates:
   *  UnitDelay: '<S55>/UnitDelay'
   */
  rtb_Sum1_mz = q1 + localDW->UnitDelay_DSTATE;

  /* Product: '<S53>/Divide5' */
  q1 = (rtu_err * rtu_P) >> 11;
  if (q1 > 32767) {
    q1 = 32767;
  } else {
    if (q1 < -32768) {
      q1 = -32768;
    }
  }

  /* Sum: '<S53>/Sum1' incorporates:
   *  DataTypeConversion: '<S55>/Data Type Conversion1'
   *  Product: '<S53>/Divide5'
   */
  q1 = (((rtb_Sum1_mz >> 16) << 1) + q1) >> 1;
  if (q1 > 32767) {
    q1 = 32767;
  } else {
    if (q1 < -32768) {
      q1 = -32768;
    }
  }

  /* RelationalOperator: '<S56>/LowerRelop1' incorporates:
   *  Sum: '<S53>/Sum1'
   */
  rtb_LowerRelop1_ge = ((int16_T)q1 > rtu_satMax);

  /* RelationalOperator: '<S56>/UpperRelop' incorporates:
   *  Sum: '<S53>/Sum1'
   */
  rtb_UpperRelop_cm = ((int16_T)q1 < rtu_satMin);

  /* Switch: '<S56>/Switch1' incorporates:
   *  Sum: '<S53>/Sum1'
   *  Switch: '<S56>/Switch3'
   */
  if (rtb_LowerRelop1_ge) {
    rty_out_0 = rtu_satMax;
  } else if (rtb_UpperRelop_cm) {
    /* Switch: '<S56>/Switch3' */
    rty_out_0 = rtu_satMin;
  } else {
    rty_out_0 = (int16_T)q1;
  }

  /* End of Switch: '<S56>/Switch1' */

  /* Signum: '<S54>/SignDeltaU2' incorporates:
   *  Sum: '<S53>/Sum2'
   */
  if (q0 < 0) {
    q0 = -1;
  } else {
    q0 = (q0 > 0);
  }

  /* End of Signum: '<S54>/SignDeltaU2' */

  /* Signum: '<S54>/SignDeltaU3' incorporates:
   *  Sum: '<S53>/Sum1'
   */
  if ((int16_T)q1 < 0) {
    tmp = -1;
  } else {
    tmp = (int16_T)((int16_T)q1 > 0);
  }

  /* End of Signum: '<S54>/SignDeltaU3' */

  /* Update for UnitDelay: '<S53>/UnitDelay1' incorporates:
   *  DataTypeConversion: '<S54>/DataTypeConv4'
   *  Logic: '<S53>/AND1'
   *  Logic: '<S54>/AND1'
   *  RelationalOperator: '<S54>/Equal1'
   */
  localDW->UnitDelay1_DSTATE = ((q0 == tmp) && (rtb_LowerRelop1_ge ||
    rtb_UpperRelop_cm));

  /* Update for UnitDelay: '<S55>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtb_Sum1_mz;
  return rty_out_0;
}

/*
 * System initialize for atomic system:
 *    '<S22>/Counter'
 *    '<S21>/Counter'
 */
void Counter_b_Init(DW_Counter_l *localDW, uint16_T rtp_z_cntInit)
{
  /* InitializeConditions for UnitDelay: '<S27>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtp_z_cntInit;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Counter'
 *    '<S21>/Counter'
 */
uint16_T Counter_i(uint16_T rtu_inc, uint16_T rtu_max, boolean_T rtu_rst,
                   DW_Counter_l *localDW)
{
  uint16_T rtu_rst_0;
  uint16_T rty_cnt_0;

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant23'
   *  UnitDelay: '<S27>/UnitDelay'
   */
  if (rtu_rst) {
    rtu_rst_0 = 0U;
  } else {
    rtu_rst_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Sum: '<S26>/Sum1' */
  rty_cnt_0 = (uint16_T)((uint32_T)rtu_inc + rtu_rst_0);

  /* MinMax: '<S26>/MinMax' */
  if (rty_cnt_0 < rtu_max) {
    /* Update for UnitDelay: '<S27>/UnitDelay' */
    localDW->UnitDelay_DSTATE = rty_cnt_0;
  } else {
    /* Update for UnitDelay: '<S27>/UnitDelay' */
    localDW->UnitDelay_DSTATE = rtu_max;
  }

  /* End of MinMax: '<S26>/MinMax' */
  return rty_cnt_0;
}

/*
 * System reset for atomic system:
 *    '<S18>/either_edge'
 *    '<S3>/either_edge'
 */
void either_edge_Reset(DW_either_edge *localDW)
{
  /* InitializeConditions for UnitDelay: '<S23>/UnitDelay' */
  localDW->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S18>/either_edge'
 *    '<S3>/either_edge'
 */
boolean_T either_edge(boolean_T rtu_u, DW_either_edge *localDW)
{
  boolean_T rty_y_0;

  /* RelationalOperator: '<S23>/Relational Operator' incorporates:
   *  UnitDelay: '<S23>/UnitDelay'
   */
  rty_y_0 = (rtu_u != localDW->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S23>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtu_u;
  return rty_y_0;
}

/* System initialize for atomic system: '<S3>/Debounce_Filter' */
void Debounce_Filter_Init(DW_Debounce_Filter *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S18>/Qualification' */

  /* SystemInitialize for Atomic SubSystem: '<S22>/Counter' */
  Counter_b_Init(&localDW->Counter_i0, 0U);

  /* End of SystemInitialize for SubSystem: '<S22>/Counter' */

  /* End of SystemInitialize for SubSystem: '<S18>/Qualification' */

  /* SystemInitialize for IfAction SubSystem: '<S18>/Dequalification' */

  /* SystemInitialize for Atomic SubSystem: '<S21>/Counter' */
  Counter_b_Init(&localDW->Counter_h, 0U);

  /* End of SystemInitialize for SubSystem: '<S21>/Counter' */

  /* End of SystemInitialize for SubSystem: '<S18>/Dequalification' */
}

/* System reset for atomic system: '<S3>/Debounce_Filter' */
void Debounce_Filter_Reset(DW_Debounce_Filter *localDW)
{
  /* InitializeConditions for UnitDelay: '<S18>/UnitDelay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemReset for Atomic SubSystem: '<S18>/either_edge' */
  either_edge_Reset(&localDW->either_edge_k);

  /* End of SystemReset for SubSystem: '<S18>/either_edge' */
}

/* Output and update for atomic system: '<S3>/Debounce_Filter' */
void Debounce_Filter(boolean_T rtu_u, uint16_T rtu_tAcv, uint16_T rtu_tDeacv,
                     boolean_T *rty_y, DW_Debounce_Filter *localDW)
{
  uint16_T rtb_Sum1_l;
  boolean_T rtb_RelationalOperator_f;

  /* Outputs for Atomic SubSystem: '<S18>/either_edge' */
  rtb_RelationalOperator_f = either_edge(rtu_u, &localDW->either_edge_k);

  /* End of Outputs for SubSystem: '<S18>/either_edge' */

  /* If: '<S18>/If2' incorporates:
   *  Constant: '<S21>/Constant6'
   *  Constant: '<S22>/Constant6'
   *  Inport: '<S20>/yPrev'
   *  Logic: '<S18>/Logical Operator1'
   *  Logic: '<S18>/Logical Operator2'
   *  Logic: '<S18>/Logical Operator3'
   *  Logic: '<S18>/Logical Operator4'
   *  UnitDelay: '<S18>/UnitDelay'
   */
  if (rtu_u && (!localDW->UnitDelay_DSTATE)) {
    /* Outputs for IfAction SubSystem: '<S18>/Qualification' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */

    /* Outputs for Atomic SubSystem: '<S22>/Counter' */
    rtb_Sum1_l = (uint16_T) Counter_i(1U, rtu_tAcv, rtb_RelationalOperator_f,
      &localDW->Counter_i0);

    /* End of Outputs for SubSystem: '<S22>/Counter' */

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant6'
     *  RelationalOperator: '<S22>/Relational Operator2'
     */
    *rty_y = ((rtb_Sum1_l > rtu_tAcv) || localDW->UnitDelay_DSTATE);

    /* End of Outputs for SubSystem: '<S18>/Qualification' */
  } else if ((!rtu_u) && localDW->UnitDelay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S18>/Dequalification' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */

    /* Outputs for Atomic SubSystem: '<S21>/Counter' */
    rtb_Sum1_l = (uint16_T) Counter_i(1U, rtu_tDeacv, rtb_RelationalOperator_f,
      &localDW->Counter_h);

    /* End of Outputs for SubSystem: '<S21>/Counter' */

    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/Constant6'
     *  RelationalOperator: '<S21>/Relational Operator2'
     */
    *rty_y = ((!(rtb_Sum1_l > rtu_tDeacv)) && localDW->UnitDelay_DSTATE);

    /* End of Outputs for SubSystem: '<S18>/Dequalification' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/Default' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    *rty_y = localDW->UnitDelay_DSTATE;

    /* End of Outputs for SubSystem: '<S18>/Default' */
  }

  /* End of If: '<S18>/If2' */

  /* Update for UnitDelay: '<S18>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_y;
}

/* Model step function */
void BLDC_controller_step(RT_MODEL *const rtM)
{
  P *rtP = ((P *) rtM->defaultParam);
  DW *rtDW = ((DW *) rtM->dwork);
  ExtU *rtU = (ExtU *) rtM->inputs;
  ExtY *rtY = (ExtY *) rtM->outputs;
  uint8_T rtb_Sum;
  boolean_T rtb_LogicalOperator;
  int8_T rtb_Sum2_h;
  boolean_T rtb_RelationalOperator4_d;
  boolean_T rtb_RelationalOperator1_m;
  uint8_T rtb_Sum_l;
  uint8_T rtb_r_fieldWeak_XA_o1;
  int16_T rtb_Merge;
  int16_T rtb_Switch2_fv;
  int16_T rtb_Abs5;
  int16_T rtb_Switch1_l;
  int16_T rtb_Switch2_d;
  uint16_T rtb_Divide2_h;
  int16_T rtb_Saturation;
  int16_T rtb_toNegative;
  int16_T rtb_Gain4;
  uint8_T rtb_r_fieldWeak_XA_o2;
  int16_T rtb_Gain2_f;
  int16_T rtb_id_fieldWeak_M1;
  int16_T rtb_MinMax2;
  int16_T rtb_TmpSignalConversionAtLow_Pa[2];
  int32_T rtb_DataTypeConversion;
  int32_T rtb_Switch1;
  int32_T rtb_Sum1;
  int32_T rtb_Gain3;
  int16_T tmp[4];
  int8_T UnitDelay3;

  /* Outputs for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/g_Ha'
   *  Gain: '<S9>/g_Hb'
   *  Inport: '<Root>/b_hallA '
   *  Inport: '<Root>/b_hallB'
   *  Inport: '<Root>/b_hallC'
   */
  rtb_Sum = (uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU->b_hallA << 2)
    + (uint8_T)(rtU->b_hallB << 1)) + rtU->b_hallC);

  /* Saturate: '<S1>/Saturation2' incorporates:
   *  Inport: '<Root>/r_inpTgt'
   */
  rtb_Gain3 = rtU->r_inpTgt << 4;

  /* If: '<S7>/If1' incorporates:
   *  Constant: '<S1>/z_ctrlTypSel1'
   *  Inport: '<Root>/r_inpTgt'
   *  Inport: '<S13>/r_inpTgt'
   *  Saturate: '<S1>/Saturation2'
   */
  if (rtP->z_ctrlTypSel == 1) {
    /* Outputs for IfAction SubSystem: '<S7>/FOC_Control_Type' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* SignalConversion: '<S14>/TmpSignal ConversionAtSelectorInport1' incorporates:
     *  Constant: '<S14>/Vd_max'
     *  Constant: '<S14>/constant1'
     *  Constant: '<S14>/i_max'
     *  Constant: '<S14>/n_max'
     */
    tmp[0] = 0;
    tmp[1] = rtP->Vd_max;
    tmp[2] = rtP->n_max;
    tmp[3] = rtP->i_max;

    /* End of Outputs for SubSystem: '<S7>/FOC_Control_Type' */

    /* Saturate: '<S1>/Saturation2' incorporates:
     *  Inport: '<Root>/r_inpTgt'
     */
    if (rtb_Gain3 >= 16000) {
      rtb_Gain4 = 16000;
    } else if (rtb_Gain3 <= -16000) {
      rtb_Gain4 = -16000;
    } else {
      rtb_Gain4 = (int16_T)(rtU->r_inpTgt << 4);
    }

    /* Outputs for IfAction SubSystem: '<S7>/FOC_Control_Type' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Product: '<S14>/Divide1' incorporates:
     *  Inport: '<Root>/z_ctrlModReq'
     *  Product: '<S14>/Divide4'
     *  Selector: '<S14>/Selector'
     */
    rtb_Merge = (int16_T)(((uint16_T)((tmp[rtU->z_ctrlModReq] << 5) / 125) *
      rtb_Gain4) >> 12);

    /* End of Outputs for SubSystem: '<S7>/FOC_Control_Type' */
  } else if (rtb_Gain3 >= 16000) {
    /* Outputs for IfAction SubSystem: '<S7>/Commutation_Control_Type' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Saturate: '<S1>/Saturation2' incorporates:
     *  Inport: '<S13>/r_inpTgt'
     */
    rtb_Merge = 16000;

    /* End of Outputs for SubSystem: '<S7>/Commutation_Control_Type' */
  } else if (rtb_Gain3 <= -16000) {
    /* Outputs for IfAction SubSystem: '<S7>/Commutation_Control_Type' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Saturate: '<S1>/Saturation2' incorporates:
     *  Inport: '<S13>/r_inpTgt'
     */
    rtb_Merge = -16000;

    /* End of Outputs for SubSystem: '<S7>/Commutation_Control_Type' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/Commutation_Control_Type' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    rtb_Merge = (int16_T)(rtU->r_inpTgt << 4);

    /* End of Outputs for SubSystem: '<S7>/Commutation_Control_Type' */
  }

  /* End of If: '<S7>/If1' */

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Inport: '<Root>/b_hallA '
   *  Inport: '<Root>/b_hallB'
   *  Inport: '<Root>/b_hallC'
   *  UnitDelay: '<S8>/UnitDelay1'
   *  UnitDelay: '<S8>/UnitDelay2'
   *  UnitDelay: '<S8>/UnitDelay3'
   */
  rtb_LogicalOperator = (boolean_T)((rtU->b_hallA != 0) ^ (rtU->b_hallB != 0) ^
    (rtU->b_hallC != 0) ^ (rtDW->UnitDelay3_DSTATE_fy != 0) ^
    (rtDW->UnitDelay1_DSTATE != 0)) ^ (rtDW->UnitDelay2_DSTATE_f != 0);

  /* If: '<S11>/If2' incorporates:
   *  If: '<S2>/If2'
   *  Inport: '<S16>/z_counterRawPrev'
   *  UnitDelay: '<S11>/UnitDelay3'
   */
  if (rtb_LogicalOperator) {
    /* Outputs for IfAction SubSystem: '<S2>/F01_04_Direction_Detection' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* UnitDelay: '<S10>/UnitDelay3' */
    UnitDelay3 = rtDW->Switch2;

    /* Sum: '<S10>/Sum2' incorporates:
     *  Constant: '<S9>/vec_hallToPos'
     *  Selector: '<S9>/Selector'
     *  UnitDelay: '<S10>/UnitDelay2'
     */
    rtb_Sum2_h = (int8_T)(rtConstP.vec_hallToPos_Value[rtb_Sum] -
                          rtDW->UnitDelay2_DSTATE_b);

    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant20'
     *  Constant: '<S10>/Constant23'
     *  Constant: '<S10>/Constant24'
     *  Constant: '<S10>/Constant8'
     *  Logic: '<S10>/Logical Operator3'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S10>/Relational Operator6'
     */
    if ((rtb_Sum2_h == 1) || (rtb_Sum2_h == -5)) {
      rtDW->Switch2 = 1;
    } else {
      rtDW->Switch2 = -1;
    }

    /* End of Switch: '<S10>/Switch2' */

    /* Update for UnitDelay: '<S10>/UnitDelay2' incorporates:
     *  Constant: '<S9>/vec_hallToPos'
     *  Selector: '<S9>/Selector'
     */
    rtDW->UnitDelay2_DSTATE_b = rtConstP.vec_hallToPos_Value[rtb_Sum];

    /* End of Outputs for SubSystem: '<S2>/F01_04_Direction_Detection' */

    /* Outputs for IfAction SubSystem: '<S11>/Raw_Motor_Speed_Estimation' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    rtDW->z_counterRawPrev = rtDW->UnitDelay3_DSTATE;

    /* Sum: '<S16>/Sum7' incorporates:
     *  Inport: '<S16>/z_counterRawPrev'
     *  UnitDelay: '<S11>/UnitDelay3'
     *  UnitDelay: '<S16>/UnitDelay4'
     */
    rtb_Switch2_fv = (int16_T)(rtDW->z_counterRawPrev -
      rtDW->UnitDelay4_DSTATE_p);

    /* Abs: '<S16>/Abs2' */
    if (rtb_Switch2_fv < 0) {
      rtb_Switch1_l = (int16_T)-rtb_Switch2_fv;
    } else {
      rtb_Switch1_l = rtb_Switch2_fv;
    }

    /* End of Abs: '<S16>/Abs2' */

    /* Relay: '<S16>/dz_cntTrnsDet' */
    if (rtb_Switch1_l >= rtP->dz_cntTrnsDetHi) {
      rtDW->dz_cntTrnsDet_Mode = true;
    } else {
      if (rtb_Switch1_l <= rtP->dz_cntTrnsDetLo) {
        rtDW->dz_cntTrnsDet_Mode = false;
      }
    }

    rtDW->dz_cntTrnsDet = rtDW->dz_cntTrnsDet_Mode;

    /* End of Relay: '<S16>/dz_cntTrnsDet' */

    /* RelationalOperator: '<S16>/Relational Operator4' */
    rtb_RelationalOperator4_d = (rtDW->Switch2 != UnitDelay3);

    /* Switch: '<S16>/Switch3' incorporates:
     *  Constant: '<S16>/Constant4'
     *  Logic: '<S16>/Logical Operator1'
     *  Switch: '<S16>/Switch1'
     *  Switch: '<S16>/Switch2'
     *  UnitDelay: '<S16>/UnitDelay1'
     */
    if (rtb_RelationalOperator4_d && rtDW->UnitDelay1_DSTATE_n) {
      rtb_Switch1_l = 0;
    } else if (rtb_RelationalOperator4_d) {
      /* Switch: '<S16>/Switch2' incorporates:
       *  UnitDelay: '<S11>/UnitDelay4'
       */
      rtb_Switch1_l = rtDW->UnitDelay4_DSTATE_e;
    } else if (rtDW->dz_cntTrnsDet) {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Constant: '<S16>/cf_speedCoef'
       *  Product: '<S16>/Divide14'
       *  Switch: '<S16>/Switch2'
       */
      rtb_Switch1_l = (int16_T)((rtP->cf_speedCoef << 4) /
        rtDW->z_counterRawPrev);
    } else {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Constant: '<S16>/cf_speedCoef'
       *  Gain: '<S16>/g_Ha'
       *  Product: '<S16>/Divide13'
       *  Sum: '<S16>/Sum13'
       *  Switch: '<S16>/Switch2'
       *  UnitDelay: '<S16>/UnitDelay2'
       *  UnitDelay: '<S16>/UnitDelay3'
       *  UnitDelay: '<S16>/UnitDelay5'
       */
      rtb_Switch1_l = (int16_T)(((uint16_T)(rtP->cf_speedCoef << 2) << 4) /
        (int16_T)(((rtDW->UnitDelay2_DSTATE + rtDW->UnitDelay3_DSTATE_o) +
                   rtDW->UnitDelay5_DSTATE) + rtDW->z_counterRawPrev));
    }

    /* End of Switch: '<S16>/Switch3' */

    /* Product: '<S16>/Divide11' */
    rtDW->Divide11 = (int16_T)(rtb_Switch1_l * rtDW->Switch2);

    /* Update for UnitDelay: '<S16>/UnitDelay4' */
    rtDW->UnitDelay4_DSTATE_p = rtDW->z_counterRawPrev;

    /* Update for UnitDelay: '<S16>/UnitDelay2' incorporates:
     *  UnitDelay: '<S16>/UnitDelay3'
     */
    rtDW->UnitDelay2_DSTATE = rtDW->UnitDelay3_DSTATE_o;

    /* Update for UnitDelay: '<S16>/UnitDelay3' incorporates:
     *  UnitDelay: '<S16>/UnitDelay5'
     */
    rtDW->UnitDelay3_DSTATE_o = rtDW->UnitDelay5_DSTATE;

    /* Update for UnitDelay: '<S16>/UnitDelay5' */
    rtDW->UnitDelay5_DSTATE = rtDW->z_counterRawPrev;

    /* Update for UnitDelay: '<S16>/UnitDelay1' */
    rtDW->UnitDelay1_DSTATE_n = rtb_RelationalOperator4_d;

    /* End of Outputs for SubSystem: '<S11>/Raw_Motor_Speed_Estimation' */
  }

  /* End of If: '<S11>/If2' */

  /* Outputs for Atomic SubSystem: '<S11>/Counter' */

  /* Constant: '<S11>/Constant6' incorporates:
   *  Constant: '<S11>/z_maxCntRst2'
   */
  rtb_Switch1_l = (int16_T) Counter(1, rtP->z_maxCntRst, rtb_LogicalOperator,
    &rtDW->Counter_e);

  /* End of Outputs for SubSystem: '<S11>/Counter' */

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/z_maxCntRst'
   *  RelationalOperator: '<S11>/Relational Operator2'
   */
  if (rtb_Switch1_l > rtP->z_maxCntRst) {
    rtb_Switch2_fv = 0;
  } else {
    rtb_Switch2_fv = rtDW->Divide11;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Abs: '<S11>/Abs5' */
  if (rtb_Switch2_fv < 0) {
    rtb_Abs5 = (int16_T)-rtb_Switch2_fv;
  } else {
    rtb_Abs5 = rtb_Switch2_fv;
  }

  /* End of Abs: '<S11>/Abs5' */

  /* Relay: '<S11>/n_commDeacv' */
  if (rtb_Abs5 >= rtP->n_commDeacvHi) {
    rtDW->n_commDeacv_Mode = true;
  } else {
    if (rtb_Abs5 <= rtP->n_commAcvLo) {
      rtDW->n_commDeacv_Mode = false;
    }
  }

  /* Logic: '<S11>/Logical Operator2' incorporates:
   *  Constant: '<S11>/CTRL_COMM'
   *  Constant: '<S1>/z_ctrlTypSel1'
   *  Logic: '<S11>/Logical Operator1'
   *  RelationalOperator: '<S11>/Relational Operator3'
   *  Relay: '<S11>/n_commDeacv'
   */
  rtb_LogicalOperator = ((rtP->z_ctrlTypSel == 1) && rtDW->n_commDeacv_Mode && (
    !rtDW->dz_cntTrnsDet));

  /* RelationalOperator: '<S11>/Relational Operator9' incorporates:
   *  Constant: '<S11>/n_stdStillDet'
   */
  rtb_RelationalOperator4_d = (rtb_Abs5 < rtP->n_stdStillDet);

  /* If: '<S1>/If2' incorporates:
   *  Constant: '<S1>/b_diagEna'
   *  Constant: '<S3>/CTRL_COMM2'
   *  Constant: '<S3>/t_errDequal'
   *  Constant: '<S3>/t_errQual'
   *  RelationalOperator: '<S3>/Relational Operator2'
   */
  rtb_Sum2_h = rtDW->If2_ActiveSubsystem;
  UnitDelay3 = -1;
  if (rtP->b_diagEna) {
    UnitDelay3 = 0;
  }

  rtDW->If2_ActiveSubsystem = UnitDelay3;
  if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
    /* Disable for Outport: '<Root>/z_errCode' incorporates:
     *  Outport: '<S3>/z_errCode '
     */
    rtY->z_errCode = 0U;

    /* Disable for Outport: '<S3>/b_errFlag' */
    rtDW->Merge_n = false;
  }

  if (UnitDelay3 == 0) {
    if (0 != rtb_Sum2_h) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/F02_Diagnostics' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* InitializeConditions for If: '<S1>/If2' incorporates:
       *  UnitDelay: '<S3>/UnitDelay'
       */
      rtDW->UnitDelay_DSTATE_c = 0U;

      /* End of InitializeConditions for SubSystem: '<S1>/F02_Diagnostics' */

      /* SystemReset for IfAction SubSystem: '<S1>/F02_Diagnostics' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */

      /* SystemReset for Atomic SubSystem: '<S3>/Debounce_Filter' */

      /* SystemReset for If: '<S1>/If2' */
      Debounce_Filter_Reset(&rtDW->Debounce_Filter_f);

      /* End of SystemReset for SubSystem: '<S3>/Debounce_Filter' */

      /* SystemReset for Atomic SubSystem: '<S3>/either_edge' */
      either_edge_Reset(&rtDW->either_edge_a);

      /* End of SystemReset for SubSystem: '<S3>/either_edge' */

      /* End of SystemReset for SubSystem: '<S1>/F02_Diagnostics' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/F02_Diagnostics' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Switch: '<S3>/Switch3' incorporates:
     *  Abs: '<S3>/Abs4'
     *  Constant: '<S3>/CTRL_COMM4'
     *  Constant: '<S3>/r_errInpTgtThres'
     *  Logic: '<S3>/Logical Operator1'
     *  RelationalOperator: '<S3>/Relational Operator7'
     *  S-Function (sfix_bitop): '<S3>/Bitwise Operator1'
     *  UnitDelay: '<S3>/UnitDelay'
     *  UnitDelay: '<S6>/UnitDelay4'
     */
    if ((rtDW->UnitDelay_DSTATE_c & 4) != 0) {
      rtb_RelationalOperator1_m = true;
    } else {
      if (rtDW->UnitDelay4_DSTATE < 0) {
        /* Abs: '<S3>/Abs4' incorporates:
         *  UnitDelay: '<S6>/UnitDelay4'
         */
        rtb_Gain4 = (int16_T)-rtDW->UnitDelay4_DSTATE;
      } else {
        /* Abs: '<S3>/Abs4' incorporates:
         *  UnitDelay: '<S6>/UnitDelay4'
         */
        rtb_Gain4 = rtDW->UnitDelay4_DSTATE;
      }

      rtb_RelationalOperator1_m = ((rtb_Gain4 > rtP->r_errInpTgtThres) &&
        rtb_RelationalOperator4_d);
    }

    /* End of Switch: '<S3>/Switch3' */

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/CTRL_COMM'
     *  Constant: '<S3>/CTRL_COMM1'
     *  DataTypeConversion: '<S3>/Data Type Conversion3'
     *  Gain: '<S3>/g_Hb'
     *  Gain: '<S3>/g_Hb1'
     *  RelationalOperator: '<S3>/Relational Operator1'
     *  RelationalOperator: '<S3>/Relational Operator3'
     */
    rtb_Sum_l = (uint8_T)(((uint32_T)((rtb_Sum == 7) << 1) + (rtb_Sum == 0)) +
                          (rtb_RelationalOperator1_m << 2));

    /* Outputs for Atomic SubSystem: '<S3>/Debounce_Filter' */
    Debounce_Filter(rtb_Sum_l != 0, rtP->t_errQual, rtP->t_errDequal,
                    &rtDW->Merge_n, &rtDW->Debounce_Filter_f);

    /* End of Outputs for SubSystem: '<S3>/Debounce_Filter' */

    /* Outputs for Atomic SubSystem: '<S3>/either_edge' */
    rtb_RelationalOperator1_m = either_edge(rtDW->Merge_n, &rtDW->either_edge_a);

    /* End of Outputs for SubSystem: '<S3>/either_edge' */

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/CTRL_COMM2'
     *  Constant: '<S3>/t_errDequal'
     *  Constant: '<S3>/t_errQual'
     *  RelationalOperator: '<S3>/Relational Operator2'
     */
    if (rtb_RelationalOperator1_m) {
      /* Outport: '<Root>/z_errCode' */
      rtY->z_errCode = rtb_Sum_l;
    } else {
      /* Outport: '<Root>/z_errCode' incorporates:
       *  UnitDelay: '<S3>/UnitDelay'
       */
      rtY->z_errCode = rtDW->UnitDelay_DSTATE_c;
    }

    /* End of Switch: '<S3>/Switch1' */

    /* Update for UnitDelay: '<S3>/UnitDelay' incorporates:
     *  Outport: '<Root>/z_errCode'
     */
    rtDW->UnitDelay_DSTATE_c = rtY->z_errCode;

    /* End of Outputs for SubSystem: '<S1>/F02_Diagnostics' */
  }

  /* End of If: '<S1>/If2' */

  /* Logic: '<S28>/Logical Operator4' incorporates:
   *  Constant: '<S28>/constant2'
   *  Constant: '<S28>/constant8'
   *  Inport: '<Root>/b_motEna'
   *  Inport: '<Root>/z_ctrlModReq'
   *  Logic: '<S28>/Logical Operator1'
   *  Logic: '<S28>/Logical Operator7'
   *  RelationalOperator: '<S28>/Relational Operator10'
   *  RelationalOperator: '<S28>/Relational Operator11'
   *  RelationalOperator: '<S28>/Relational Operator2'
   *  UnitDelay: '<S4>/UnitDelay1'
   */
  rtb_RelationalOperator1_m = ((!rtU->b_motEna) || rtDW->Merge_n ||
    (rtU->z_ctrlModReq == 0) || ((rtU->z_ctrlModReq != rtDW->UnitDelay1_DSTATE_p)
    && (rtDW->UnitDelay1_DSTATE_p != 0)));

  /* Chart: '<S4>/F03_02_Control_Mode_Manager' incorporates:
   *  Constant: '<S28>/constant'
   *  Constant: '<S28>/constant1'
   *  Constant: '<S28>/constant5'
   *  Constant: '<S28>/constant6'
   *  Constant: '<S28>/constant7'
   *  Inport: '<Root>/z_ctrlModReq'
   *  Logic: '<S28>/Logical Operator3'
   *  Logic: '<S28>/Logical Operator6'
   *  Logic: '<S28>/Logical Operator9'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  RelationalOperator: '<S28>/Relational Operator3'
   *  RelationalOperator: '<S28>/Relational Operator4'
   *  RelationalOperator: '<S28>/Relational Operator5'
   *  RelationalOperator: '<S28>/Relational Operator6'
   */
  if (rtDW->is_active_c1_BLDC_controller == 0U) {
    rtDW->is_active_c1_BLDC_controller = 1U;
    rtDW->is_c1_BLDC_controller = IN_OPEN;
    rtb_Sum_l = OPEN_MODE;
  } else if (rtDW->is_c1_BLDC_controller == IN_ACTIVE) {
    if (rtb_RelationalOperator1_m) {
      rtDW->is_ACTIVE = IN_NO_ACTIVE_CHILD;
      rtDW->is_c1_BLDC_controller = IN_OPEN;
      rtb_Sum_l = OPEN_MODE;
    } else {
      switch (rtDW->is_ACTIVE) {
       case IN_SPEED_MODE:
        rtb_Sum_l = SPD_MODE;
        break;

       case IN_TORQUE_MODE:
        rtb_Sum_l = TRQ_MODE;
        break;

       default:
        rtb_Sum_l = VLT_MODE;
        break;
      }
    }
  } else {
    rtb_Sum_l = OPEN_MODE;
    if ((!rtb_RelationalOperator1_m) && ((rtU->z_ctrlModReq == 1) ||
         (rtU->z_ctrlModReq == 2) || (rtU->z_ctrlModReq == 3)) &&
        rtb_RelationalOperator4_d) {
      rtDW->is_c1_BLDC_controller = IN_ACTIVE;
      if (rtU->z_ctrlModReq == 3) {
        rtDW->is_ACTIVE = IN_TORQUE_MODE;
        rtb_Sum_l = TRQ_MODE;
      } else if (rtU->z_ctrlModReq == 2) {
        rtDW->is_ACTIVE = IN_SPEED_MODE;
        rtb_Sum_l = SPD_MODE;
      } else {
        rtDW->is_ACTIVE = IN_VOLTAGE_MODE;
        rtb_Sum_l = VLT_MODE;
      }
    }
  }

  /* End of Chart: '<S4>/F03_02_Control_Mode_Manager' */

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S12>/Constant16'
   *  Product: '<S12>/Divide1'
   *  Product: '<S12>/Divide3'
   *  RelationalOperator: '<S12>/Relational Operator7'
   *  Sum: '<S12>/Sum3'
   *  Switch: '<S12>/Switch3'
   */
  if (rtb_LogicalOperator) {
    /* MinMax: '<S12>/MinMax' */
    rtb_Switch2_d = rtb_Switch1_l;
    if (!(rtb_Switch2_d < rtDW->z_counterRawPrev)) {
      rtb_Switch2_d = rtDW->z_counterRawPrev;
    }

    /* End of MinMax: '<S12>/MinMax' */

    /* Switch: '<S12>/Switch3' incorporates:
     *  Constant: '<S12>/Constant16'
     *  Constant: '<S9>/vec_hallToPos'
     *  RelationalOperator: '<S12>/Relational Operator7'
     *  Selector: '<S9>/Selector'
     *  Sum: '<S12>/Sum1'
     */
    if (rtDW->Switch2 == 1) {
      rtb_Sum2_h = rtConstP.vec_hallToPos_Value[rtb_Sum];
    } else {
      rtb_Sum2_h = (int8_T)(rtConstP.vec_hallToPos_Value[rtb_Sum] + 1);
    }

    rtb_Switch2_d = (int16_T)(((int16_T)((int16_T)((rtb_Switch2_d << 14) /
      rtDW->z_counterRawPrev) * rtDW->Switch2) + (rtb_Sum2_h << 14)) >> 2);
  } else {
    if (rtDW->Switch2 == 1) {
      /* Switch: '<S12>/Switch3' incorporates:
       *  Constant: '<S9>/vec_hallToPos'
       *  Selector: '<S9>/Selector'
       */
      rtb_Sum2_h = rtConstP.vec_hallToPos_Value[rtb_Sum];
    } else {
      /* Switch: '<S12>/Switch3' incorporates:
       *  Constant: '<S9>/vec_hallToPos'
       *  Selector: '<S9>/Selector'
       *  Sum: '<S12>/Sum1'
       */
      rtb_Sum2_h = (int8_T)(rtConstP.vec_hallToPos_Value[rtb_Sum] + 1);
    }

    rtb_Switch2_d = (int16_T)(rtb_Sum2_h << 12);
  }

  /* End of Switch: '<S12>/Switch2' */

  /* MinMax: '<S12>/MinMax1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (!(rtb_Switch2_d > 0)) {
    rtb_Switch2_d = 0;
  }

  /* End of MinMax: '<S12>/MinMax1' */

  /* Product: '<S12>/Divide2' */
  rtb_Divide2_h = (uint16_T)((15 * rtb_Switch2_d) >> 4);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/i_phaAB'
   */
  rtb_Gain3 = rtU->i_phaAB << 4;
  if (rtb_Gain3 >= 32000) {
    rtb_Saturation = 32000;
  } else if (rtb_Gain3 <= -32000) {
    rtb_Saturation = -32000;
  } else {
    rtb_Saturation = (int16_T)(rtU->i_phaAB << 4);
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Inport: '<Root>/i_phaBC'
   */
  rtb_Gain3 = rtU->i_phaBC << 4;
  if (rtb_Gain3 >= 32000) {
    rtb_Switch2_d = 32000;
  } else if (rtb_Gain3 <= -32000) {
    rtb_Switch2_d = -32000;
  } else {
    rtb_Switch2_d = (int16_T)(rtU->i_phaBC << 4);
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* If: '<S1>/If1' incorporates:
   *  Constant: '<S1>/z_ctrlTypSel1'
   */
  rtb_Sum2_h = rtDW->If1_ActiveSubsystem;
  UnitDelay3 = -1;
  if (rtP->z_ctrlTypSel == 1) {
    UnitDelay3 = 0;
  }

  rtDW->If1_ActiveSubsystem = UnitDelay3;
  if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
    /* Disable for If: '<S5>/If2' */
    if (rtDW->If2_ActiveSubsystem_a == 0) {
      /* Disable for Outport: '<S31>/iq' */
      rtDW->Sum1[0] = 0;

      /* Disable for Outport: '<S31>/id' */
      rtDW->Sum1[1] = 0;
    }

    rtDW->If2_ActiveSubsystem_a = -1;

    /* End of Disable for If: '<S5>/If2' */

    /* Disable for If: '<S5>/If1' */
    if (rtDW->If1_ActiveSubsystem_e == 0) {
      /* Disable for Outport: '<S40>/Vd' */
      rtDW->Switch1 = 0;
    }

    rtDW->If1_ActiveSubsystem_e = -1;

    /* End of Disable for If: '<S5>/If1' */

    /* Disable for If: '<S35>/If1' */
    if (rtDW->If1_ActiveSubsystem_f == 0) {
      /* Disable for Outport: '<S45>/iq_limProt' */
      rtDW->Divide4 = 0;
    }

    rtDW->If1_ActiveSubsystem_f = -1;

    /* End of Disable for If: '<S35>/If1' */

    /* Disable for If: '<S35>/If2' */
    if (rtDW->If2_ActiveSubsystem_c == 0) {
      /* Disable for Outport: '<S46>/n_limProt' */
      rtDW->Divide1 = 0;
    }

    rtDW->If2_ActiveSubsystem_c = -1;

    /* End of Disable for If: '<S35>/If2' */

    /* Disable for SwitchCase: '<S5>/Switch Case' */
    rtDW->SwitchCase_ActiveSubsystem = -1;

    /* Disable for Outport: '<S5>/r_phaA' */
    rtDW->Gain4[0] = 0;

    /* Disable for Outport: '<S5>/r_phaB' */
    rtDW->Gain4[1] = 0;

    /* Disable for Outport: '<S5>/r_phaC ' */
    rtDW->Gain4[2] = 0;

    /* Disable for Outport: '<S5>/Vq' */
    rtDW->Merge = 0;

    /* Disable for Outport: '<S5>/r_devSignal1' */
    rtDW->Sum1[0] = 0;

    /* Disable for Outport: '<S5>/r_devSignal2' */
    rtDW->Sum1[1] = 0;
  }

  if (UnitDelay3 == 0) {
    if (0 != rtb_Sum2_h) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/F04_Field_Oriented_Control' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for If: '<S1>/If1' incorporates:
       *  UnitDelay: '<S5>/UnitDelay4'
       */
      rtDW->UnitDelay4_DSTATE_er = 0;

      /* End of InitializeConditions for SubSystem: '<S1>/F04_Field_Oriented_Control' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/F04_Field_Oriented_Control' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Relay: '<S32>/n_fieldWeakAuth' */
    if (rtb_Abs5 >= rtP->n_fieldWeakAuthHi) {
      rtDW->n_fieldWeakAuth_Mode = true;
    } else {
      if (rtb_Abs5 <= rtP->n_fieldWeakAuthLo) {
        rtDW->n_fieldWeakAuth_Mode = false;
      }
    }

    /* Switch: '<S32>/Switch1' incorporates:
     *  Constant: '<S32>/a_elecPeriod1'
     *  Constant: '<S32>/b_fieldWeakEna'
     *  Logic: '<S32>/Logical Operator2'
     *  Relay: '<S32>/n_fieldWeakAuth'
     */
    if (rtP->b_fieldWeakEna && rtDW->n_fieldWeakAuth_Mode) {
      /* Abs: '<S32>/Abs5' */
      if (rtb_Merge < 0) {
        rtb_id_fieldWeak_M1 = (int16_T)-rtb_Merge;
      } else {
        rtb_id_fieldWeak_M1 = rtb_Merge;
      }

      /* End of Abs: '<S32>/Abs5' */

      /* PreLookup: '<S32>/r_fieldWeak_XA' */
      rtb_r_fieldWeak_XA_o1 = plook_u8s16u8n6_evenc_s(rtb_id_fieldWeak_M1,
        rtP->r_fieldWeak_XA[0], (uint16_T)(rtP->r_fieldWeak_XA[1] -
        rtP->r_fieldWeak_XA[0]), 11U, &rtb_r_fieldWeak_XA_o2);

      /* Interpolation_n-D: '<S32>/id_fieldWeak_M1' */
      rtb_id_fieldWeak_M1 = intrp1d_s16s32s32u8u8n6l_s(rtb_r_fieldWeak_XA_o1,
        rtb_r_fieldWeak_XA_o2, rtP->id_fieldWeak_M1);
    } else {
      rtb_id_fieldWeak_M1 = 0;
    }

    /* End of Switch: '<S32>/Switch1' */

    /* Gain: '<S32>/toNegative' */
    rtb_toNegative = (int16_T)-rtb_id_fieldWeak_M1;

    /* Gain: '<S35>/Gain4' incorporates:
     *  Constant: '<S35>/i_max'
     */
    rtb_Gain4 = (int16_T)-rtP->i_max;

    /* If: '<S30>/If1' incorporates:
     *  Constant: '<S30>/b_selPhaABCurrMeas'
     */
    if (rtP->b_selPhaABCurrMeas) {
      /* Outputs for IfAction SubSystem: '<S30>/Clarke_PhasesAB' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Gain: '<S42>/Gain4' */
      rtb_Gain3 = 18919 * rtb_Saturation;

      /* Gain: '<S42>/Gain2' */
      rtb_DataTypeConversion = 18919 * rtb_Switch2_d;

      /* Sum: '<S42>/Sum1' incorporates:
       *  Gain: '<S42>/Gain2'
       *  Gain: '<S42>/Gain4'
       */
      rtb_Gain3 = (((rtb_Gain3 < 0 ? 32767 : 0) + rtb_Gain3) >> 15) + (int16_T)
        (((rtb_DataTypeConversion < 0 ? 16383 : 0) + rtb_DataTypeConversion) >>
         14);
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      rtb_Gain2_f = (int16_T)rtb_Gain3;

      /* End of Sum: '<S42>/Sum1' */
      /* End of Outputs for SubSystem: '<S30>/Clarke_PhasesAB' */
    } else {
      /* Outputs for IfAction SubSystem: '<S30>/Clarke_PhasesBC' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* Sum: '<S43>/Sum3' */
      rtb_Gain3 = rtb_Saturation - rtb_Switch2_d;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Gain: '<S43>/Gain2' incorporates:
       *  Sum: '<S43>/Sum3'
       */
      rtb_Gain3 *= 18919;
      rtb_Gain2_f = (int16_T)(((rtb_Gain3 < 0 ? 32767 : 0) + rtb_Gain3) >> 15);

      /* Sum: '<S43>/Sum1' */
      rtb_Gain3 = -rtb_Saturation - rtb_Switch2_d;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      rtb_Saturation = (int16_T)rtb_Gain3;

      /* End of Sum: '<S43>/Sum1' */
      /* End of Outputs for SubSystem: '<S30>/Clarke_PhasesBC' */
    }

    /* End of If: '<S30>/If1' */

    /* PreLookup: '<S32>/a_elecAngle_XA' */
    rtb_r_fieldWeak_XA_o1 = plook_u8u16_evencka(rtb_Divide2_h, 0U, 128U, 180U);

    /* Interpolation_n-D: '<S32>/r_sin_M1' */
    rtb_MinMax2 = rtConstP.r_sin_M1_Table[rtb_r_fieldWeak_XA_o1];

    /* Interpolation_n-D: '<S32>/r_cos_M1' */
    rtb_Switch2_d = rtConstP.r_cos_M1_Table[rtb_r_fieldWeak_XA_o1];

    /* If: '<S5>/If2' incorporates:
     *  Constant: '<S31>/cf_currFilt'
     *  Inport: '<Root>/b_motEna'
     */
    rtb_Sum2_h = rtDW->If2_ActiveSubsystem_a;
    UnitDelay3 = -1;
    if (rtU->b_motEna) {
      UnitDelay3 = 0;
    }

    rtDW->If2_ActiveSubsystem_a = UnitDelay3;
    if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
      /* Disable for Outport: '<S31>/iq' */
      rtDW->Sum1[0] = 0;

      /* Disable for Outport: '<S31>/id' */
      rtDW->Sum1[1] = 0;
    }

    if (UnitDelay3 == 0) {
      if (0 != rtb_Sum2_h) {
        /* SystemReset for IfAction SubSystem: '<S5>/Current_Filtering' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */

        /* SystemReset for Atomic SubSystem: '<S31>/Low_Pass_Filter' */

        /* SystemReset for If: '<S5>/If2' */
        Low_Pass_Filter_Reset(&rtDW->Low_Pass_Filter_m);

        /* End of SystemReset for SubSystem: '<S31>/Low_Pass_Filter' */

        /* End of SystemReset for SubSystem: '<S5>/Current_Filtering' */
      }

      /* Sum: '<S37>/Sum6' incorporates:
       *  Interpolation_n-D: '<S32>/r_cos_M1'
       *  Interpolation_n-D: '<S32>/r_sin_M1'
       *  Product: '<S37>/Divide1'
       *  Product: '<S37>/Divide4'
       */
      rtb_Gain3 = (int16_T)((rtb_Gain2_f *
        rtConstP.r_cos_M1_Table[rtb_r_fieldWeak_XA_o1]) >> 14) - (int16_T)
        ((rtb_Saturation * rtConstP.r_sin_M1_Table[rtb_r_fieldWeak_XA_o1]) >> 14);
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Outputs for IfAction SubSystem: '<S5>/Current_Filtering' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SignalConversion: '<S31>/TmpSignal ConversionAtLow_Pass_FilterInport1' incorporates:
       *  Sum: '<S37>/Sum6'
       */
      rtb_TmpSignalConversionAtLow_Pa[0] = (int16_T)rtb_Gain3;

      /* End of Outputs for SubSystem: '<S5>/Current_Filtering' */

      /* Sum: '<S37>/Sum1' incorporates:
       *  Interpolation_n-D: '<S32>/r_cos_M1'
       *  Interpolation_n-D: '<S32>/r_sin_M1'
       *  Product: '<S37>/Divide2'
       *  Product: '<S37>/Divide3'
       */
      rtb_Gain3 = (int16_T)((rtb_Saturation *
        rtConstP.r_cos_M1_Table[rtb_r_fieldWeak_XA_o1]) >> 14) + (int16_T)
        ((rtb_Gain2_f * rtConstP.r_sin_M1_Table[rtb_r_fieldWeak_XA_o1]) >> 14);
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Outputs for IfAction SubSystem: '<S5>/Current_Filtering' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SignalConversion: '<S31>/TmpSignal ConversionAtLow_Pass_FilterInport1' incorporates:
       *  Sum: '<S37>/Sum1'
       */
      rtb_TmpSignalConversionAtLow_Pa[1] = (int16_T)rtb_Gain3;

      /* Outputs for Atomic SubSystem: '<S31>/Low_Pass_Filter' */
      Low_Pass_Filter(rtb_TmpSignalConversionAtLow_Pa, rtP->cf_currFilt,
                      rtDW->Sum1, &rtDW->Low_Pass_Filter_m);

      /* End of Outputs for SubSystem: '<S31>/Low_Pass_Filter' */

      /* End of Outputs for SubSystem: '<S5>/Current_Filtering' */
    }

    /* End of If: '<S5>/If2' */

    /* If: '<S5>/If1' incorporates:
     *  Constant: '<S35>/Vd_max1'
     *  Constant: '<S40>/cf_idKi1'
     *  Constant: '<S40>/cf_idKp1'
     *  Constant: '<S40>/constant1'
     *  Gain: '<S35>/Gain3'
     *  Sum: '<S40>/Sum3'
     */
    rtb_Sum2_h = rtDW->If1_ActiveSubsystem_e;
    UnitDelay3 = -1;
    if (rtb_LogicalOperator) {
      UnitDelay3 = 0;
    }

    rtDW->If1_ActiveSubsystem_e = UnitDelay3;
    if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
      /* Disable for Outport: '<S40>/Vd' */
      rtDW->Switch1 = 0;
    }

    if (UnitDelay3 == 0) {
      if (0 != rtb_Sum2_h) {
        /* SystemReset for IfAction SubSystem: '<S5>/Vd_Calculation' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */

        /* SystemReset for Atomic SubSystem: '<S40>/PI_clamp_fixdt_id' */

        /* SystemReset for If: '<S5>/If1' */
        PI_clamp_fixdt_Reset(&rtDW->PI_clamp_fixdt_id);

        /* End of SystemReset for SubSystem: '<S40>/PI_clamp_fixdt_id' */

        /* End of SystemReset for SubSystem: '<S5>/Vd_Calculation' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Vd_Calculation' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      /* Switch: '<S63>/Switch2' incorporates:
       *  Constant: '<S35>/i_max'
       *  RelationalOperator: '<S63>/LowerRelop1'
       *  RelationalOperator: '<S63>/UpperRelop'
       *  Switch: '<S63>/Switch'
       */
      if (rtb_toNegative > rtP->i_max) {
        rtb_toNegative = rtP->i_max;
      } else {
        if (rtb_toNegative < rtb_Gain4) {
          /* Switch: '<S63>/Switch' */
          rtb_toNegative = rtb_Gain4;
        }
      }

      /* End of Switch: '<S63>/Switch2' */

      /* Sum: '<S40>/Sum3' */
      rtb_Gain3 = rtb_toNegative - rtDW->Sum1[1];
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Outputs for Atomic SubSystem: '<S40>/PI_clamp_fixdt_id' */
      PI_clamp_fixdt((int16_T)rtb_Gain3, rtP->cf_idKp, rtP->cf_idKi, rtP->Vd_max,
                     (int16_T)-rtP->Vd_max, 0, &rtDW->Switch1,
                     &rtDW->PI_clamp_fixdt_id);

      /* End of Outputs for SubSystem: '<S40>/PI_clamp_fixdt_id' */

      /* End of Outputs for SubSystem: '<S5>/Vd_Calculation' */
    }

    /* End of If: '<S5>/If1' */

    /* Abs: '<S35>/Abs5' */
    if (rtDW->Switch1 < 0) {
      rtb_Gain4 = (int16_T)-rtDW->Switch1;
    } else {
      rtb_Gain4 = rtDW->Switch1;
    }

    /* End of Abs: '<S35>/Abs5' */

    /* PreLookup: '<S35>/Vq_max_XA' */
    rtb_r_fieldWeak_XA_o1 = plook_u8s16_evencka(rtb_Gain4, rtP->Vq_max_XA[0],
      (uint16_T)(rtP->Vq_max_XA[1] - rtP->Vq_max_XA[0]), 45U);

    /* Interpolation_n-D: '<S35>/Vq_max_M1' */
    rtb_Gain2_f = rtP->Vq_max_M1[rtb_r_fieldWeak_XA_o1];

    /* Gain: '<S35>/Gain5' incorporates:
     *  Interpolation_n-D: '<S35>/Vq_max_M1'
     */
    rtb_Saturation = (int16_T)-rtP->Vq_max_M1[rtb_r_fieldWeak_XA_o1];

    /* PreLookup: '<S35>/iq_max_XA' */
    rtb_r_fieldWeak_XA_o1 = plook_u8s16_evencka(rtb_id_fieldWeak_M1,
      rtP->iq_max_XA[0], (uint16_T)(rtP->iq_max_XA[1] - rtP->iq_max_XA[0]), 50U);

    /* MinMax: '<S35>/MinMax' incorporates:
     *  Constant: '<S35>/i_max'
     *  Interpolation_n-D: '<S35>/iq_max_M1'
     */
    if (rtP->i_max < rtP->iq_max_M1[rtb_r_fieldWeak_XA_o1]) {
      rtb_id_fieldWeak_M1 = rtP->i_max;
    } else {
      rtb_id_fieldWeak_M1 = rtP->iq_max_M1[rtb_r_fieldWeak_XA_o1];
    }

    /* End of MinMax: '<S35>/MinMax' */

    /* Gain: '<S35>/Gain1' */
    rtb_toNegative = (int16_T)-rtb_id_fieldWeak_M1;

    /* If: '<S35>/If1' incorporates:
     *  Constant: '<S35>/CTRL_COMM'
     *  Constant: '<S35>/CTRL_COMM1'
     *  Logic: '<S35>/Logical Operator2'
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  RelationalOperator: '<S35>/Relational Operator2'
     */
    rtb_Sum2_h = rtDW->If1_ActiveSubsystem_f;
    UnitDelay3 = -1;
    if ((rtb_Sum_l == 1) || (rtb_Sum_l == 2)) {
      UnitDelay3 = 0;
    }

    rtDW->If1_ActiveSubsystem_f = UnitDelay3;
    if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
      /* Disable for Outport: '<S45>/iq_limProt' */
      rtDW->Divide4 = 0;
    }

    if (UnitDelay3 == 0) {
      /* Outputs for IfAction SubSystem: '<S35>/Current_Limit_Protection' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Switch: '<S47>/Switch2' incorporates:
       *  RelationalOperator: '<S47>/LowerRelop1'
       *  RelationalOperator: '<S47>/UpperRelop'
       *  Switch: '<S47>/Switch'
       */
      if (rtDW->Sum1[0] > rtb_id_fieldWeak_M1) {
        rtb_Gain4 = rtb_id_fieldWeak_M1;
      } else if (rtDW->Sum1[0] < rtb_toNegative) {
        /* Switch: '<S47>/Switch' */
        rtb_Gain4 = rtb_toNegative;
      } else {
        rtb_Gain4 = rtDW->Sum1[0];
      }

      /* End of Switch: '<S47>/Switch2' */

      /* Product: '<S45>/Divide4' incorporates:
       *  Constant: '<S45>/cf_iqKpLimProt'
       *  Sum: '<S45>/Sum3'
       */
      rtb_Gain3 = ((int16_T)(rtb_Gain4 - rtDW->Sum1[0]) * rtP->cf_iqKpLimProt) >>
        8;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      rtDW->Divide4 = (int16_T)rtb_Gain3;

      /* End of Product: '<S45>/Divide4' */
      /* End of Outputs for SubSystem: '<S35>/Current_Limit_Protection' */
    }

    /* End of If: '<S35>/If1' */

    /* Gain: '<S35>/Gain6' incorporates:
     *  Constant: '<S35>/n_max1'
     */
    rtb_Gain4 = (int16_T)-rtP->n_max;

    /* If: '<S35>/If2' incorporates:
     *  Constant: '<S35>/CTRL_COMM2'
     *  Constant: '<S35>/CTRL_COMM3'
     *  Logic: '<S35>/Logical Operator1'
     *  RelationalOperator: '<S35>/Relational Operator3'
     *  RelationalOperator: '<S35>/Relational Operator4'
     */
    rtb_Sum2_h = rtDW->If2_ActiveSubsystem_c;
    UnitDelay3 = -1;
    if ((rtb_Sum_l == 1) || (rtb_Sum_l == 3)) {
      UnitDelay3 = 0;
    }

    rtDW->If2_ActiveSubsystem_c = UnitDelay3;
    if ((rtb_Sum2_h != UnitDelay3) && (rtb_Sum2_h == 0)) {
      /* Disable for Outport: '<S46>/n_limProt' */
      rtDW->Divide1 = 0;
    }

    if (UnitDelay3 == 0) {
      /* Outputs for IfAction SubSystem: '<S35>/Speed_Limit_Protection' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      /* Switch: '<S48>/Switch2' incorporates:
       *  Constant: '<S35>/n_max1'
       *  RelationalOperator: '<S48>/LowerRelop1'
       *  RelationalOperator: '<S48>/UpperRelop'
       *  Switch: '<S48>/Switch'
       */
      if (rtb_Switch2_fv > rtP->n_max) {
        rtb_Gain4 = rtP->n_max;
      } else {
        if (!(rtb_Switch2_fv < rtb_Gain4)) {
          rtb_Gain4 = rtb_Switch2_fv;
        }
      }

      /* End of Switch: '<S48>/Switch2' */

      /* Product: '<S46>/Divide1' incorporates:
       *  Constant: '<S46>/cf_nKpLimProt'
       *  Sum: '<S46>/Sum1'
       */
      rtb_Gain3 = ((int16_T)(rtb_Gain4 - rtb_Switch2_fv) * rtP->cf_nKpLimProt) >>
        8;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      rtDW->Divide1 = (int16_T)rtb_Gain3;

      /* End of Product: '<S46>/Divide1' */
      /* End of Outputs for SubSystem: '<S35>/Speed_Limit_Protection' */
    }

    /* End of If: '<S35>/If2' */

    /* SwitchCase: '<S5>/Switch Case' incorporates:
     *  Constant: '<S38>/cf_iqKiLimProt'
     *  Constant: '<S38>/cf_nKi'
     *  Constant: '<S38>/cf_nKp'
     *  Product: '<S38>/Divide1'
     *  SignalConversion: '<S38>/Signal Conversion2'
     *  Sum: '<S38>/Sum3'
     */
    rtb_Sum2_h = rtDW->SwitchCase_ActiveSubsystem;
    switch (rtb_Sum_l) {
     case 1:
      UnitDelay3 = 0;
      break;

     case 2:
      UnitDelay3 = 1;
      break;

     case 3:
      UnitDelay3 = 2;
      break;

     default:
      UnitDelay3 = 3;
      break;
    }

    rtDW->SwitchCase_ActiveSubsystem = UnitDelay3;
    switch (UnitDelay3) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S5>/Voltage_Mode' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      /* Sum: '<S41>/Sum3' */
      rtb_Gain3 = (rtb_Merge + rtDW->Divide4) + rtDW->Divide1;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Switch: '<S67>/Switch2' incorporates:
       *  RelationalOperator: '<S67>/LowerRelop1'
       *  RelationalOperator: '<S67>/UpperRelop'
       *  Sum: '<S41>/Sum3'
       *  Switch: '<S67>/Switch'
       */
      if ((int16_T)rtb_Gain3 > rtb_Gain2_f) {
        /* SignalConversion: '<S41>/Signal Conversion2' */
        rtDW->Merge = rtb_Gain2_f;
      } else if ((int16_T)rtb_Gain3 < rtb_Saturation) {
        /* Switch: '<S67>/Switch' incorporates:
         *  SignalConversion: '<S41>/Signal Conversion2'
         */
        rtDW->Merge = rtb_Saturation;
      } else {
        /* SignalConversion: '<S41>/Signal Conversion2' */
        rtDW->Merge = (int16_T)rtb_Gain3;
      }

      /* End of Switch: '<S67>/Switch2' */
      /* End of Outputs for SubSystem: '<S5>/Voltage_Mode' */
      break;

     case 1:
      if (UnitDelay3 != rtb_Sum2_h) {
        /* SystemReset for IfAction SubSystem: '<S5>/Speed_Mode' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */

        /* SystemReset for Atomic SubSystem: '<S38>/PI_clamp_fixdt_n' */

        /* SystemReset for SwitchCase: '<S5>/Switch Case' */
        PI_clamp_fixdt_n_Reset(&rtDW->PI_clamp_fixdt_n_o);

        /* End of SystemReset for SubSystem: '<S38>/PI_clamp_fixdt_n' */

        /* End of SystemReset for SubSystem: '<S5>/Speed_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Speed_Mode' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Sum: '<S38>/Sum3' */
      rtb_Gain3 = rtb_Merge - rtb_Switch2_fv;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Outputs for Atomic SubSystem: '<S38>/PI_clamp_fixdt_n' */
      rtDW->Merge = (int16_T) PI_clamp_fixdt_n((int16_T)rtb_Gain3, rtP->cf_nKp,
        rtP->cf_nKi, rtb_Gain2_f, rtb_Saturation, (int16_T)((rtDW->Divide4 *
        rtP->cf_iqKiLimProt) >> 10), &rtDW->PI_clamp_fixdt_n_o);

      /* End of Outputs for SubSystem: '<S38>/PI_clamp_fixdt_n' */

      /* End of Outputs for SubSystem: '<S5>/Speed_Mode' */
      break;

     case 2:
      if (UnitDelay3 != rtb_Sum2_h) {
        /* SystemReset for IfAction SubSystem: '<S5>/Torque_Mode' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */

        /* SystemReset for Atomic SubSystem: '<S39>/PI_clamp_fixdt_iq' */

        /* SystemReset for SwitchCase: '<S5>/Switch Case' */
        PI_clamp_fixdt_Reset(&rtDW->PI_clamp_fixdt_iq);

        /* End of SystemReset for SubSystem: '<S39>/PI_clamp_fixdt_iq' */

        /* End of SystemReset for SubSystem: '<S5>/Torque_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Torque_Mode' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* Sum: '<S39>/Sum2' */
      rtb_Gain3 = rtb_Merge + rtDW->Divide1;
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Switch: '<S58>/Switch2' incorporates:
       *  RelationalOperator: '<S58>/LowerRelop1'
       *  Sum: '<S39>/Sum2'
       */
      if (!((int16_T)rtb_Gain3 > rtb_id_fieldWeak_M1)) {
        /* Switch: '<S58>/Switch' incorporates:
         *  RelationalOperator: '<S58>/UpperRelop'
         */
        if ((int16_T)rtb_Gain3 < rtb_toNegative) {
          rtb_id_fieldWeak_M1 = rtb_toNegative;
        } else {
          rtb_id_fieldWeak_M1 = (int16_T)rtb_Gain3;
        }

        /* End of Switch: '<S58>/Switch' */
      }

      /* End of Switch: '<S58>/Switch2' */

      /* Sum: '<S39>/Sum1' */
      rtb_Gain3 = rtb_id_fieldWeak_M1 - rtDW->Sum1[0];
      if (rtb_Gain3 > 32767) {
        rtb_Gain3 = 32767;
      } else {
        if (rtb_Gain3 < -32768) {
          rtb_Gain3 = -32768;
        }
      }

      /* Outputs for Atomic SubSystem: '<S39>/PI_clamp_fixdt_iq' */

      /* SignalConversion: '<S39>/Signal Conversion2' incorporates:
       *  Constant: '<S39>/cf_iqKi'
       *  Constant: '<S39>/cf_iqKp'
       *  Constant: '<S39>/constant'
       *  Sum: '<S39>/Sum1'
       */
      PI_clamp_fixdt((int16_T)rtb_Gain3, rtP->cf_iqKp, rtP->cf_iqKi, rtb_Gain2_f,
                     rtb_Saturation, 0, &rtDW->Merge, &rtDW->PI_clamp_fixdt_iq);

      /* End of Outputs for SubSystem: '<S39>/PI_clamp_fixdt_iq' */

      /* End of Outputs for SubSystem: '<S5>/Torque_Mode' */
      break;

     case 3:
      if (UnitDelay3 != rtb_Sum2_h) {
        /* SystemReset for IfAction SubSystem: '<S5>/Open_Mode' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        /* SystemReset for Atomic SubSystem: '<S36>/rising_edge_init' */
        /* SystemReset for SwitchCase: '<S5>/Switch Case' incorporates:
         *  UnitDelay: '<S50>/UnitDelay'
         *  UnitDelay: '<S51>/UnitDelay'
         */
        rtDW->UnitDelay_DSTATE_g = true;

        /* End of SystemReset for SubSystem: '<S36>/rising_edge_init' */

        /* SystemReset for Atomic SubSystem: '<S36>/Rate_Limiter' */
        rtDW->UnitDelay_DSTATE = 0;

        /* End of SystemReset for SubSystem: '<S36>/Rate_Limiter' */
        /* End of SystemReset for SubSystem: '<S5>/Open_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Open_Mode' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* DataTypeConversion: '<S36>/Data Type Conversion' incorporates:
       *  UnitDelay: '<S5>/UnitDelay4'
       */
      rtb_Gain3 = rtDW->UnitDelay4_DSTATE_er << 12;
      rtb_DataTypeConversion = (rtb_Gain3 & 134217728) != 0 ? rtb_Gain3 |
        -134217728 : rtb_Gain3 & 134217727;

      /* Outputs for Atomic SubSystem: '<S36>/rising_edge_init' */
      /* UnitDelay: '<S50>/UnitDelay' */
      rtb_RelationalOperator4_d = rtDW->UnitDelay_DSTATE_g;

      /* Update for UnitDelay: '<S50>/UnitDelay' incorporates:
       *  Constant: '<S50>/Constant'
       */
      rtDW->UnitDelay_DSTATE_g = false;

      /* End of Outputs for SubSystem: '<S36>/rising_edge_init' */

      /* Outputs for Atomic SubSystem: '<S36>/Rate_Limiter' */
      /* Switch: '<S51>/Switch1' incorporates:
       *  UnitDelay: '<S51>/UnitDelay'
       */
      if (rtb_RelationalOperator4_d) {
        rtb_Switch1 = rtb_DataTypeConversion;
      } else {
        rtb_Switch1 = rtDW->UnitDelay_DSTATE;
      }

      /* End of Switch: '<S51>/Switch1' */

      /* Sum: '<S49>/Sum1' */
      rtb_Gain3 = -rtb_Switch1;
      rtb_Sum1 = (rtb_Gain3 & 134217728) != 0 ? rtb_Gain3 | -134217728 :
        rtb_Gain3 & 134217727;

      /* Switch: '<S52>/Switch2' incorporates:
       *  Constant: '<S36>/dV_openRate'
       *  RelationalOperator: '<S52>/LowerRelop1'
       */
      if (rtb_Sum1 > rtP->dV_openRate) {
        rtb_Sum1 = rtP->dV_openRate;
      } else {
        /* Gain: '<S36>/Gain3' */
        rtb_Gain3 = -rtP->dV_openRate;
        rtb_Gain3 = (rtb_Gain3 & 134217728) != 0 ? rtb_Gain3 | -134217728 :
          rtb_Gain3 & 134217727;

        /* Switch: '<S52>/Switch' incorporates:
         *  RelationalOperator: '<S52>/UpperRelop'
         */
        if (rtb_Sum1 < rtb_Gain3) {
          rtb_Sum1 = rtb_Gain3;
        }

        /* End of Switch: '<S52>/Switch' */
      }

      /* End of Switch: '<S52>/Switch2' */

      /* Sum: '<S49>/Sum2' */
      rtb_Gain3 = rtb_Sum1 + rtb_Switch1;
      rtb_Switch1 = (rtb_Gain3 & 134217728) != 0 ? rtb_Gain3 | -134217728 :
        rtb_Gain3 & 134217727;

      /* Switch: '<S51>/Switch2' */
      if (rtb_RelationalOperator4_d) {
        /* Update for UnitDelay: '<S51>/UnitDelay' */
        rtDW->UnitDelay_DSTATE = rtb_DataTypeConversion;
      } else {
        /* Update for UnitDelay: '<S51>/UnitDelay' */
        rtDW->UnitDelay_DSTATE = rtb_Switch1;
      }

      /* End of Switch: '<S51>/Switch2' */
      /* End of Outputs for SubSystem: '<S36>/Rate_Limiter' */

      /* DataTypeConversion: '<S36>/Data Type Conversion1' */
      rtDW->Merge = (int16_T)(rtb_Switch1 >> 12);

      /* End of Outputs for SubSystem: '<S5>/Open_Mode' */
      break;
    }

    /* End of SwitchCase: '<S5>/Switch Case' */

    /* Sum: '<S34>/Sum6' incorporates:
     *  Product: '<S34>/Divide1'
     *  Product: '<S34>/Divide4'
     */
    rtb_Gain3 = (int16_T)((rtDW->Switch1 * rtb_Switch2_d) >> 14) - (int16_T)
      ((rtDW->Merge * rtb_MinMax2) >> 14);
    if (rtb_Gain3 > 32767) {
      rtb_Gain3 = 32767;
    } else {
      if (rtb_Gain3 < -32768) {
        rtb_Gain3 = -32768;
      }
    }

    /* Sum: '<S34>/Sum1' incorporates:
     *  Product: '<S34>/Divide2'
     *  Product: '<S34>/Divide3'
     */
    rtb_DataTypeConversion = (int16_T)((rtDW->Switch1 * rtb_MinMax2) >> 14) +
      (int16_T)((rtDW->Merge * rtb_Switch2_d) >> 14);
    if (rtb_DataTypeConversion > 32767) {
      rtb_DataTypeConversion = 32767;
    } else {
      if (rtb_DataTypeConversion < -32768) {
        rtb_DataTypeConversion = -32768;
      }
    }

    /* Gain: '<S33>/Gain1' incorporates:
     *  Sum: '<S34>/Sum1'
     */
    rtb_DataTypeConversion = 14189 * (int16_T)rtb_DataTypeConversion;

    /* Sum: '<S33>/Sum6' incorporates:
     *  Gain: '<S33>/Gain1'
     *  Gain: '<S33>/Gain3'
     *  Sum: '<S34>/Sum6'
     */
    rtb_DataTypeConversion = (((rtb_DataTypeConversion < 0 ? 16383 : 0) +
      rtb_DataTypeConversion) >> 14) - ((int16_T)(((int16_T)rtb_Gain3 < 0) +
      (int16_T)rtb_Gain3) >> 1);
    if (rtb_DataTypeConversion > 32767) {
      rtb_DataTypeConversion = 32767;
    } else {
      if (rtb_DataTypeConversion < -32768) {
        rtb_DataTypeConversion = -32768;
      }
    }

    /* Sum: '<S33>/Sum2' incorporates:
     *  Sum: '<S33>/Sum6'
     *  Sum: '<S34>/Sum6'
     */
    rtb_Switch1 = -(int16_T)rtb_Gain3 - (int16_T)rtb_DataTypeConversion;
    if (rtb_Switch1 > 32767) {
      rtb_Switch1 = 32767;
    } else {
      if (rtb_Switch1 < -32768) {
        rtb_Switch1 = -32768;
      }
    }

    /* MinMax: '<S33>/MinMax1' incorporates:
     *  Sum: '<S33>/Sum2'
     *  Sum: '<S33>/Sum6'
     *  Sum: '<S34>/Sum6'
     */
    rtb_Switch2_d = (int16_T)rtb_Gain3;
    if (!((int16_T)rtb_Gain3 < (int16_T)rtb_DataTypeConversion)) {
      rtb_Switch2_d = (int16_T)rtb_DataTypeConversion;
    }

    if (!(rtb_Switch2_d < (int16_T)rtb_Switch1)) {
      rtb_Switch2_d = (int16_T)rtb_Switch1;
    }

    /* MinMax: '<S33>/MinMax2' incorporates:
     *  Sum: '<S33>/Sum2'
     *  Sum: '<S33>/Sum6'
     *  Sum: '<S34>/Sum6'
     */
    rtb_Saturation = (int16_T)rtb_Gain3;
    if (!((int16_T)rtb_Gain3 > (int16_T)rtb_DataTypeConversion)) {
      rtb_Saturation = (int16_T)rtb_DataTypeConversion;
    }

    if (!(rtb_Saturation > (int16_T)rtb_Switch1)) {
      rtb_Saturation = (int16_T)rtb_Switch1;
    }

    /* Sum: '<S33>/Add' incorporates:
     *  MinMax: '<S33>/MinMax1'
     *  MinMax: '<S33>/MinMax2'
     */
    rtb_Sum1 = rtb_Switch2_d + rtb_Saturation;
    if (rtb_Sum1 > 32767) {
      rtb_Sum1 = 32767;
    } else {
      if (rtb_Sum1 < -32768) {
        rtb_Sum1 = -32768;
      }
    }

    /* Gain: '<S33>/Gain2' incorporates:
     *  Sum: '<S33>/Add'
     */
    rtb_Gain2_f = (int16_T)(rtb_Sum1 >> 1);

    /* Sum: '<S33>/Add1' incorporates:
     *  Sum: '<S34>/Sum6'
     */
    rtb_Gain3 = (int16_T)rtb_Gain3 - rtb_Gain2_f;
    if (rtb_Gain3 > 32767) {
      rtb_Gain3 = 32767;
    } else {
      if (rtb_Gain3 < -32768) {
        rtb_Gain3 = -32768;
      }
    }

    /* Gain: '<S33>/Gain4' incorporates:
     *  Sum: '<S33>/Add1'
     */
    rtDW->Gain4[0] = (int16_T)((18919 * rtb_Gain3) >> 18);

    /* Sum: '<S33>/Add1' incorporates:
     *  Sum: '<S33>/Sum6'
     */
    rtb_Gain3 = (int16_T)rtb_DataTypeConversion - rtb_Gain2_f;
    if (rtb_Gain3 > 32767) {
      rtb_Gain3 = 32767;
    } else {
      if (rtb_Gain3 < -32768) {
        rtb_Gain3 = -32768;
      }
    }

    /* Gain: '<S33>/Gain4' incorporates:
     *  Sum: '<S33>/Add1'
     */
    rtDW->Gain4[1] = (int16_T)((18919 * rtb_Gain3) >> 18);

    /* Sum: '<S33>/Add1' incorporates:
     *  Sum: '<S33>/Sum2'
     */
    rtb_Gain3 = (int16_T)rtb_Switch1 - rtb_Gain2_f;
    if (rtb_Gain3 > 32767) {
      rtb_Gain3 = 32767;
    } else {
      if (rtb_Gain3 < -32768) {
        rtb_Gain3 = -32768;
      }
    }

    /* Gain: '<S33>/Gain4' incorporates:
     *  Sum: '<S33>/Add1'
     */
    rtDW->Gain4[2] = (int16_T)((18919 * rtb_Gain3) >> 18);

    /* Update for UnitDelay: '<S5>/UnitDelay4' */
    rtDW->UnitDelay4_DSTATE_er = rtDW->Merge;

    /* End of Outputs for SubSystem: '<S1>/F04_Field_Oriented_Control' */
  }

  /* End of If: '<S1>/If1' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S1>/z_ctrlTypSel1'
   *  Constant: '<S6>/CTRL_COMM1'
   *  DataTypeConversion: '<S1>/Data Type Conversion10'
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  RelationalOperator: '<S6>/Relational Operator6'
   */
  if (rtP->z_ctrlTypSel == 1) {
    rtb_Merge = (int16_T)(rtDW->Merge >> 4);
  } else {
    rtb_Merge = (int16_T)(rtb_Merge >> 4);
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S9>/vec_hallToPos'
   *  LookupNDDirect: '<S6>/z_commutMap_M1'
   *  Product: '<S6>/Divide2'
   *  Selector: '<S9>/Selector'
   *
   * About '<S6>/z_commutMap_M1':
   *  2-dimensional Direct Look-Up returning a Column
   */
  if (rtb_LogicalOperator) {
    rtb_Switch2_d = rtDW->Gain4[0];
    rtb_Saturation = rtDW->Gain4[1];
    rtb_id_fieldWeak_M1 = rtDW->Gain4[2];
  } else {
    if (rtConstP.vec_hallToPos_Value[rtb_Sum] > 5) {
      /* LookupNDDirect: '<S6>/z_commutMap_M1'
       *
       * About '<S6>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = 5;
    } else if (rtConstP.vec_hallToPos_Value[rtb_Sum] < 0) {
      /* LookupNDDirect: '<S6>/z_commutMap_M1'
       *
       * About '<S6>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = 0;
    } else {
      /* LookupNDDirect: '<S6>/z_commutMap_M1' incorporates:
       *  Constant: '<S9>/vec_hallToPos'
       *  Selector: '<S9>/Selector'
       *
       * About '<S6>/z_commutMap_M1':
       *  2-dimensional Direct Look-Up returning a Column
       */
      rtb_Sum2_h = rtConstP.vec_hallToPos_Value[rtb_Sum];
    }

    /* LookupNDDirect: '<S6>/z_commutMap_M1' incorporates:
     *  Constant: '<S9>/vec_hallToPos'
     *  Selector: '<S9>/Selector'
     *
     * About '<S6>/z_commutMap_M1':
     *  2-dimensional Direct Look-Up returning a Column
     */
    rtb_DataTypeConversion = rtb_Sum2_h * 3;
    rtb_Switch2_d = (int16_T)(rtb_Merge *
      rtConstP.z_commutMap_M1_table[rtb_DataTypeConversion]);
    rtb_Saturation = (int16_T)(rtConstP.z_commutMap_M1_table[1 +
      rtb_DataTypeConversion] * rtb_Merge);
    rtb_id_fieldWeak_M1 = (int16_T)(rtConstP.z_commutMap_M1_table[2 +
      rtb_DataTypeConversion] * rtb_Merge);
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Update for UnitDelay: '<S8>/UnitDelay3' incorporates:
   *  Inport: '<Root>/b_hallA '
   */
  rtDW->UnitDelay3_DSTATE_fy = rtU->b_hallA;

  /* Update for UnitDelay: '<S8>/UnitDelay1' incorporates:
   *  Inport: '<Root>/b_hallB'
   */
  rtDW->UnitDelay1_DSTATE = rtU->b_hallB;

  /* Update for UnitDelay: '<S8>/UnitDelay2' incorporates:
   *  Inport: '<Root>/b_hallC'
   */
  rtDW->UnitDelay2_DSTATE_f = rtU->b_hallC;

  /* Update for UnitDelay: '<S11>/UnitDelay3' */
  rtDW->UnitDelay3_DSTATE = rtb_Switch1_l;

  /* Update for UnitDelay: '<S11>/UnitDelay4' */
  rtDW->UnitDelay4_DSTATE_e = rtb_Abs5;

  /* Update for UnitDelay: '<S6>/UnitDelay4' */
  rtDW->UnitDelay4_DSTATE = rtb_Merge;

  /* Update for UnitDelay: '<S4>/UnitDelay1' */
  rtDW->UnitDelay1_DSTATE_p = rtb_Sum_l;

  /* End of Outputs for SubSystem: '<Root>/BLDC_controller' */

  /* Outport: '<Root>/DC_phaA' */
  rtY->DC_phaA = rtb_Switch2_d;

  /* Outport: '<Root>/DC_phaB' */
  rtY->DC_phaB = rtb_Saturation;

  /* Outport: '<Root>/DC_phaC' */
  rtY->DC_phaC = rtb_id_fieldWeak_M1;

  /* Outputs for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Outport: '<Root>/n_mot' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtY->n_mot = (int16_T)(rtb_Switch2_fv >> 4);

  /* Outport: '<Root>/a_elecAngle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   */
  rtY->a_elecAngle = (int16_T)((uint32_T)rtb_Divide2_h >> 6);

  /* Outport: '<Root>/r_devSignal1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   */
  rtY->r_devSignal1 = (int16_T)(rtDW->Sum1[0] >> 4);

  /* Outport: '<Root>/r_devSignal2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  rtY->r_devSignal2 = (int16_T)(rtDW->Sum1[1] >> 4);

  /* End of Outputs for SubSystem: '<Root>/BLDC_controller' */
}

/* Model initialize function */
void BLDC_controller_initialize(RT_MODEL *const rtM)
{
  P *rtP = ((P *) rtM->defaultParam);
  DW *rtDW = ((DW *) rtM->dwork);

  /* Start for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* Start for If: '<S1>/If2' */
  rtDW->If2_ActiveSubsystem = -1;

  /* Start for If: '<S1>/If1' */
  rtDW->If1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S1>/F04_Field_Oriented_Control' */
  /* Start for If: '<S5>/If2' */
  rtDW->If2_ActiveSubsystem_a = -1;

  /* Start for If: '<S5>/If1' */
  rtDW->If1_ActiveSubsystem_e = -1;

  /* Start for If: '<S35>/If1' */
  rtDW->If1_ActiveSubsystem_f = -1;

  /* Start for If: '<S35>/If2' */
  rtDW->If2_ActiveSubsystem_c = -1;

  /* Start for SwitchCase: '<S5>/Switch Case' */
  rtDW->SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S1>/F04_Field_Oriented_Control' */
  /* End of Start for SubSystem: '<Root>/BLDC_controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/BLDC_controller' */
  /* InitializeConditions for UnitDelay: '<S11>/UnitDelay3' */
  rtDW->UnitDelay3_DSTATE = rtP->z_maxCntRst;

  /* SystemInitialize for IfAction SubSystem: '<S11>/Raw_Motor_Speed_Estimation' */
  /* SystemInitialize for Outport: '<S16>/z_counter' */
  rtDW->z_counterRawPrev = rtP->z_maxCntRst;

  /* End of SystemInitialize for SubSystem: '<S11>/Raw_Motor_Speed_Estimation' */

  /* SystemInitialize for Atomic SubSystem: '<S11>/Counter' */
  Counter_Init(&rtDW->Counter_e, rtP->z_maxCntRst);

  /* End of SystemInitialize for SubSystem: '<S11>/Counter' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/F02_Diagnostics' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Debounce_Filter' */
  Debounce_Filter_Init(&rtDW->Debounce_Filter_f);

  /* End of SystemInitialize for SubSystem: '<S3>/Debounce_Filter' */

  /* End of SystemInitialize for SubSystem: '<S1>/F02_Diagnostics' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/F04_Field_Oriented_Control' */
  /* SystemInitialize for IfAction SubSystem: '<S5>/Open_Mode' */
  /* SystemInitialize for Atomic SubSystem: '<S36>/rising_edge_init' */
  /* InitializeConditions for UnitDelay: '<S50>/UnitDelay' */
  rtDW->UnitDelay_DSTATE_g = true;

  /* End of SystemInitialize for SubSystem: '<S36>/rising_edge_init' */
  /* End of SystemInitialize for SubSystem: '<S5>/Open_Mode' */
  /* End of SystemInitialize for SubSystem: '<S1>/F04_Field_Oriented_Control' */
  /* End of SystemInitialize for SubSystem: '<Root>/BLDC_controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
