//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghostfollower.h
//
// Code generated for Simulink model 'ghostfollower'.
//
// Model version                  : 3.38
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 14 16:00:27 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ghostfollower_h_
#define RTW_HEADER_ghostfollower_h_
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ghostfollower_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_ghostfollower_T {
  SL_Bus_ghostfollower_geometry_msgs_Twist In1;// '<S17>/In1'
  SL_Bus_ghostfollower_geometry_msgs_Twist In1_b;// '<S16>/In1'
  SL_Bus_ghostfollower_geometry_msgs_Twist In1_a;// '<S15>/In1'
  SL_Bus_ghostfollower_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  real_T Subtract;                     // '<Root>/Subtract'
  real_T x1;
  real_T x2;
};

// Block states (default storage) for system '<Root>'
struct DW_ghostfollower_T {
  ros_slros_internal_block_GetP_T obj; // '<Root>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_j;// '<S3>/Get Parameter4'
  ros_slros_internal_block_GetP_T obj_n;// '<S3>/Get Parameter3'
  ros_slros_internal_block_GetP_T obj_k;// '<S3>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_c;// '<S3>/Get Parameter1'
  ros_slroscpp_internal_block_P_T obj_g;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_d;// '<S14>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_o;// '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_kl;// '<S12>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_l;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_dm;// '<S7>/SourceBlock'
  int_T Integrator_IWORK;              // '<Root>/Integrator'
};

// Continuous states (default storage)
struct X_ghostfollower_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
};

// State derivatives (default storage)
struct XDot_ghostfollower_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
  real_T Integrator1_CSTATE;           // '<Root>/Integrator1'
};

// State disabled
struct XDis_ghostfollower_T {
  boolean_T Integrator_CSTATE;         // '<Root>/Integrator'
  boolean_T Integrator1_CSTATE;        // '<Root>/Integrator1'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_ghostfollower_T_ {
  SL_Bus_ghostfollower_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S1>/Constant'

  SL_Bus_ghostfollower_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S15>/Out1'

  SL_Bus_ghostfollower_geometry_msgs_Twist Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                               //  Referenced by: '<S7>/Constant'

  SL_Bus_ghostfollower_geometry_msgs_Twist Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                        //  Referenced by: '<S16>/Out1'

  SL_Bus_ghostfollower_geometry_msgs_Twist Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                               //  Referenced by: '<S8>/Constant'

  SL_Bus_ghostfollower_geometry_msgs_Twist Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                        //  Referenced by: '<S17>/Out1'

  SL_Bus_ghostfollower_geometry_msgs_Twist Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S9>/Constant'

  SL_Bus_ghostfollower_std_msgs_Float64 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                            //  Referenced by: '<S2>/Constant'

  SL_Bus_ghostfollower_std_msgs_Float64 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                            //  Referenced by: '<S10>/Constant'

  SL_Bus_ghostfollower_std_msgs_UInt8 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                          //  Referenced by: '<S13>/Constant'

  real_T Integrator1_IC;               // Expression: 0
                                          //  Referenced by: '<Root>/Integrator1'

  real_T Constant1_Value;              // Expression: 4
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<Root>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_ghostfollower_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ghostfollower_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ghostfollower_T ghostfollower_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_ghostfollower_T ghostfollower_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_ghostfollower_T ghostfollower_X;

// Block states (default storage)
extern struct DW_ghostfollower_T ghostfollower_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ghostfollower_initialize(void);
  extern void ghostfollower_step(void);
  extern void ghostfollower_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ghostfollower_T *const ghostfollower_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ghostfollower'
//  '<S1>'   : 'ghostfollower/Blank Message'
//  '<S2>'   : 'ghostfollower/Blank Message1'
//  '<S3>'   : 'ghostfollower/Follower Stopper Switch Control'
//  '<S4>'   : 'ghostfollower/Publish'
//  '<S5>'   : 'ghostfollower/Publish Region'
//  '<S6>'   : 'ghostfollower/Publish1'
//  '<S7>'   : 'ghostfollower/Subscribe1'
//  '<S8>'   : 'ghostfollower/Subscribe2'
//  '<S9>'   : 'ghostfollower/Subscribe3'
//  '<S10>'  : 'ghostfollower/Follower Stopper Switch Control/Blank Message1'
//  '<S11>'  : 'ghostfollower/Follower Stopper Switch Control/MATLAB Function1'
//  '<S12>'  : 'ghostfollower/Follower Stopper Switch Control/Publish1'
//  '<S13>'  : 'ghostfollower/Publish Region/Blank Message1'
//  '<S14>'  : 'ghostfollower/Publish Region/Publish1'
//  '<S15>'  : 'ghostfollower/Subscribe1/Enabled Subsystem'
//  '<S16>'  : 'ghostfollower/Subscribe2/Enabled Subsystem'
//  '<S17>'  : 'ghostfollower/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghostfollower_h_

//
// File trailer for generated code.
//
// [EOF]
//
