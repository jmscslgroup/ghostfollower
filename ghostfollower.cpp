//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghostfollower.cpp
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
#include "ghostfollower.h"
#include "ghostfollower_private.h"

// Block signals (default storage)
B_ghostfollower_T ghostfollower_B;

// Continuous states
X_ghostfollower_T ghostfollower_X;

// Block states (default storage)
DW_ghostfollower_T ghostfollower_DW;

// Real-time model
RT_MODEL_ghostfollower_T ghostfollower_M_ = RT_MODEL_ghostfollower_T();
RT_MODEL_ghostfollower_T *const ghostfollower_M = &ghostfollower_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  ghostfollower_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ghostfollower_step();
  ghostfollower_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ghostfollower_step();
  ghostfollower_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void ghostfollower_step(void)
{
  SL_Bus_ghostfollower_std_msgs_Float64 rtb_BusAssignment1_d;
  SL_Bus_ghostfollower_std_msgs_Float64 rtb_BusAssignment1_i;
  SL_Bus_ghostfollower_std_msgs_UInt8 rtb_BusAssignment1;
  real_T rtb_Subtract2;
  real_T value;
  real_T value_0;
  real_T x1_tmp;
  real_T x3;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(ghostfollower_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&ghostfollower_M->solverInfo,
                          ((ghostfollower_M->Timing.clockTick0+1)*
      ghostfollower_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(ghostfollower_M)) {
    ghostfollower_M->Timing.t[0] = rtsiGetT(&ghostfollower_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ghostfollower_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S8>/SourceBlock' incorporates:
    //   Inport: '<S16>/In1'

    b_varargout_1 = Sub_ghostfollower_207.getLatestMessage
      (&ghostfollower_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S16>/Enable'

    if (b_varargout_1) {
      ghostfollower_B.In1_b = ghostfollower_B.BusAssignment;
    }

    // End of MATLABSystem: '<S8>/SourceBlock'
    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'
  }

  // MATLABSystem: '<Root>/Get Parameter2'
  ParamGet_ghostfollower_236.get_parameter(&value);

  // Integrator: '<Root>/Integrator' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter2'

  if (ghostfollower_DW.Integrator_IWORK != 0) {
    ghostfollower_X.Integrator_CSTATE = value;
  }

  // Sum: '<Root>/Subtract2' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Integrator: '<Root>/Integrator'
  //   Integrator: '<Root>/Integrator1'
  //   Sum: '<Root>/Subtract1'

  rtb_Subtract2 = (ghostfollower_X.Integrator_CSTATE -
                   ghostfollower_X.Integrator1_CSTATE) -
    ghostfollower_P.Constant1_Value;
  if (rtmIsMajorTimeStep(ghostfollower_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   Inport: '<S17>/In1'

    b_varargout_1 = Sub_ghostfollower_41.getLatestMessage
      (&ghostfollower_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S17>/Enable'

    if (b_varargout_1) {
      ghostfollower_B.In1 = ghostfollower_B.BusAssignment;
    }

    // End of MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // Sum: '<Root>/Subtract'
    ghostfollower_B.Subtract = ghostfollower_B.In1_b.Linear.X -
      ghostfollower_B.In1.Linear.X;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S15>/In1'

    b_varargout_1 = Sub_ghostfollower_187.getLatestMessage
      (&ghostfollower_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S15>/Enable'

    if (b_varargout_1) {
      ghostfollower_B.In1_a = ghostfollower_B.BusAssignment;
    }

    // End of MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'
  }

  // MATLABSystem: '<S3>/Get Parameter2'
  ParamGet_ghostfollower_226.get_parameter(&value);

  // MATLABSystem: '<S3>/Get Parameter1'
  ParamGet_ghostfollower_228.get_parameter(&ghostfollower_B.x2);

  // MATLABSystem: '<S3>/Get Parameter3'
  ParamGet_ghostfollower_230.get_parameter(&x3);

  // MATLABSystem: '<S3>/Get Parameter4'
  ParamGet_ghostfollower_245.get_parameter(&value_0);

  // MATLAB Function: '<S3>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S3>/Get Parameter1'
  //   MATLABSystem: '<S3>/Get Parameter2'
  //   MATLABSystem: '<S3>/Get Parameter3'
  //   MATLABSystem: '<S3>/Get Parameter4'

  ghostfollower_B.x1 = ghostfollower_B.Subtract;
  if (ghostfollower_B.Subtract >= 0.0) {
    ghostfollower_B.x1 = 0.0;
  }

  x1_tmp = ghostfollower_B.x1 * ghostfollower_B.x1 * 0.5;
  ghostfollower_B.x1 = (x1_tmp / 1.5 + value_0) + value *
    ghostfollower_B.In1.Linear.X;
  ghostfollower_B.x2 = ((value_0 + 6.0) / 2.0 + x1_tmp) + ghostfollower_B.x2 *
    ghostfollower_B.In1.Linear.X;
  x3 = (x1_tmp / 0.5 + 6.0) + x3 * ghostfollower_B.In1.Linear.X;
  value_0 = ghostfollower_B.In1_b.Linear.X;
  if (ghostfollower_B.In1_b.Linear.X < 0.0) {
    value_0 = 0.0;
  }

  if (ghostfollower_B.In1_b.Linear.X > ghostfollower_B.In1_a.Linear.X) {
    value_0 = ghostfollower_B.In1_a.Linear.X;
  }

  x1_tmp = 0.0;
  if (rtb_Subtract2 > x3) {
    x1_tmp = ghostfollower_B.In1_a.Linear.X;
  }

  if ((rtb_Subtract2 > ghostfollower_B.x2) && (rtb_Subtract2 <= x3)) {
    x1_tmp = (ghostfollower_B.In1_a.Linear.X - value_0) * (rtb_Subtract2 -
      ghostfollower_B.x2) / (x3 - ghostfollower_B.x2) + value_0;
  }

  if ((rtb_Subtract2 > ghostfollower_B.x1) && (rtb_Subtract2 <=
       ghostfollower_B.x2)) {
    x1_tmp = (rtb_Subtract2 - ghostfollower_B.x1) * value_0 /
      (ghostfollower_B.x2 - ghostfollower_B.x1);
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S1>/Constant'
  //   MATLAB Function: '<S3>/MATLAB Function1'

  ghostfollower_B.BusAssignment = ghostfollower_P.Constant_Value;
  ghostfollower_B.BusAssignment.Linear.X = x1_tmp;
  ghostfollower_B.BusAssignment.Angular.Z = ghostfollower_P.Constant_Value_b;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_ghostfollower_37.publish(&ghostfollower_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // MATLAB Function: '<S3>/MATLAB Function1'
  if (rtb_Subtract2 > x3) {
    // BusAssignment: '<S5>/Bus Assignment1'
    rtb_BusAssignment1.Data = 0U;
  } else if ((rtb_Subtract2 > ghostfollower_B.x2) && (rtb_Subtract2 <= x3)) {
    // BusAssignment: '<S5>/Bus Assignment1'
    rtb_BusAssignment1.Data = 1U;
  } else if ((rtb_Subtract2 > ghostfollower_B.x1) && (rtb_Subtract2 <=
              ghostfollower_B.x2)) {
    // BusAssignment: '<S5>/Bus Assignment1'
    rtb_BusAssignment1.Data = 2U;
  } else {
    // BusAssignment: '<S5>/Bus Assignment1'
    rtb_BusAssignment1.Data = 3U;
  }

  // Outputs for Atomic SubSystem: '<S5>/Publish1'
  // MATLABSystem: '<S14>/SinkBlock'
  Pub_ghostfollower_165.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<S5>/Publish1'

  // BusAssignment: '<S3>/Bus Assignment1' incorporates:
  //   MATLABSystem: '<S3>/Get Parameter2'

  rtb_BusAssignment1_d.Data = value;

  // Outputs for Atomic SubSystem: '<S3>/Publish1'
  // MATLABSystem: '<S12>/SinkBlock'
  Pub_ghostfollower_234.publish(&rtb_BusAssignment1_d);

  // End of Outputs for SubSystem: '<S3>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment1'
  rtb_BusAssignment1_i.Data = rtb_Subtract2;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_ghostfollower_223.publish(&rtb_BusAssignment1_i);

  // End of Outputs for SubSystem: '<Root>/Publish1'
  if (rtmIsMajorTimeStep(ghostfollower_M)) {
    // Update for Integrator: '<Root>/Integrator'
    ghostfollower_DW.Integrator_IWORK = 0;
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(ghostfollower_M)) {
    rt_ertODEUpdateContinuousStates(&ghostfollower_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++ghostfollower_M->Timing.clockTick0;
    ghostfollower_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ghostfollower_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.02s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.02, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      ghostfollower_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void ghostfollower_derivatives(void)
{
  XDot_ghostfollower_T *_rtXdot;
  _rtXdot = ((XDot_ghostfollower_T *) ghostfollower_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = ghostfollower_B.In1_b.Linear.X;

  // Derivatives for Integrator: '<Root>/Integrator1'
  _rtXdot->Integrator1_CSTATE = ghostfollower_B.In1.Linear.X;
}

// Model initialize function
void ghostfollower_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ghostfollower_M->solverInfo,
                          &ghostfollower_M->Timing.simTimeStep);
    rtsiSetTPtr(&ghostfollower_M->solverInfo, &rtmGetTPtr(ghostfollower_M));
    rtsiSetStepSizePtr(&ghostfollower_M->solverInfo,
                       &ghostfollower_M->Timing.stepSize0);
    rtsiSetdXPtr(&ghostfollower_M->solverInfo, &ghostfollower_M->derivs);
    rtsiSetContStatesPtr(&ghostfollower_M->solverInfo, (real_T **)
                         &ghostfollower_M->contStates);
    rtsiSetNumContStatesPtr(&ghostfollower_M->solverInfo,
      &ghostfollower_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ghostfollower_M->solverInfo,
      &ghostfollower_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ghostfollower_M->solverInfo,
      &ghostfollower_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ghostfollower_M->solverInfo,
      &ghostfollower_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ghostfollower_M->solverInfo, (&rtmGetErrorStatus
      (ghostfollower_M)));
    rtsiSetRTModelPtr(&ghostfollower_M->solverInfo, ghostfollower_M);
  }

  rtsiSetSimTimeStep(&ghostfollower_M->solverInfo, MAJOR_TIME_STEP);
  ghostfollower_M->intgData.y = ghostfollower_M->odeY;
  ghostfollower_M->intgData.f[0] = ghostfollower_M->odeF[0];
  ghostfollower_M->intgData.f[1] = ghostfollower_M->odeF[1];
  ghostfollower_M->intgData.f[2] = ghostfollower_M->odeF[2];
  ghostfollower_M->contStates = ((X_ghostfollower_T *) &ghostfollower_X);
  rtsiSetSolverData(&ghostfollower_M->solverInfo, static_cast<void *>
                    (&ghostfollower_M->intgData));
  rtsiSetSolverName(&ghostfollower_M->solverInfo,"ode3");
  rtmSetTPtr(ghostfollower_M, &ghostfollower_M->Timing.tArray[0]);
  ghostfollower_M->Timing.stepSize0 = 0.02;
  rtmSetFirstInitCond(ghostfollower_M, 1);

  {
    int32_T i;
    char_T b_zeroDelimTopic_4[12];
    char_T b_zeroDelimTopic[11];
    char_T b_zeroDelimName[9];
    char_T b_zeroDelimTopic_2[8];
    char_T b_zeroDelimTopic_3[7];
    char_T b_zeroDelimTopic_1[6];
    char_T b_zeroDelimTopic_0[4];
    char_T b_zeroDelimName_0[3];
    static const char_T tmp[10] = { 'l', 'e', 'a', 'd', 'e', 'r', '_', 'v', 'e',
      'l' };

    static const char_T tmp_0[5] = { 'v', '_', 'r', 'e', 'f' };

    static const char_T tmp_1[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[6] = { 'r', 'e', 'g', 'i', 'o', 'n' };

    static const char_T tmp_3[11] = { 't', 'i', 'm', 'h', 'e', 'a', 'd', 'w',
      'a', 'y', '1' };

    static const char_T tmp_4[11] = { 'h', 'e', 'a', 'd', 'w', 'a', 'y', '_',
      'e', 's', 't' };

    static const char_T tmp_5[8] = { 'i', 'n', 'i', 't', '_', 'g', 'a', 'p' };

    // InitializeConditions for Integrator: '<Root>/Integrator'
    if (rtmIsFirstInitCond(ghostfollower_M)) {
      ghostfollower_X.Integrator_CSTATE = 0.0;
    }

    ghostfollower_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<Root>/Integrator'

    // InitializeConditions for Integrator: '<Root>/Integrator1'
    ghostfollower_X.Integrator1_CSTATE = ghostfollower_P.Integrator1_IC;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1' incorporates:
    //   Inport: '<S16>/In1'

    ghostfollower_B.In1_b = ghostfollower_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    ghostfollower_DW.obj_f.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_ghostfollower_207.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghostfollower_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S17>/Out1' incorporates:
    //   Inport: '<S17>/In1'

    ghostfollower_B.In1 = ghostfollower_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    ghostfollower_DW.obj_l.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_l.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'v';
    b_zeroDelimTopic_0[1] = 'e';
    b_zeroDelimTopic_0[2] = 'l';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_ghostfollower_41.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ghostfollower_DW.obj_l.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1' incorporates:
    //   Inport: '<S15>/In1'

    ghostfollower_B.In1_a = ghostfollower_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    ghostfollower_DW.obj_dm.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_dm.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[5] = '\x00';
    Sub_ghostfollower_187.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    ghostfollower_DW.obj_dm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    ghostfollower_DW.obj_o.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_2[i] = tmp_1[i];
    }

    b_zeroDelimTopic_2[7] = '\x00';
    Pub_ghostfollower_37.createPublisher(&b_zeroDelimTopic_2[0], 1);
    ghostfollower_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S5>/Publish1'
    // Start for MATLABSystem: '<S14>/SinkBlock'
    ghostfollower_DW.obj_d.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_3[i] = tmp_2[i];
    }

    b_zeroDelimTopic_3[6] = '\x00';
    Pub_ghostfollower_165.createPublisher(&b_zeroDelimTopic_3[0], 1);
    ghostfollower_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S3>/Publish1'
    // Start for MATLABSystem: '<S12>/SinkBlock'
    ghostfollower_DW.obj_kl.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_kl.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_4[i] = tmp_3[i];
    }

    b_zeroDelimTopic_4[11] = '\x00';
    Pub_ghostfollower_234.createPublisher(&b_zeroDelimTopic_4[0], 1);
    ghostfollower_DW.obj_kl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    ghostfollower_DW.obj_g.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_4[i] = tmp_4[i];
    }

    b_zeroDelimTopic_4[11] = '\x00';
    Pub_ghostfollower_223.createPublisher(&b_zeroDelimTopic_4[0], 1);
    ghostfollower_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // Start for MATLABSystem: '<Root>/Get Parameter2'
    ghostfollower_DW.obj.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimName[i] = tmp_5[i];
    }

    b_zeroDelimName[8] = '\x00';
    ParamGet_ghostfollower_236.initialize(&b_zeroDelimName[0]);
    ParamGet_ghostfollower_236.initialize_error_codes(0, 1, 2, 3);
    ParamGet_ghostfollower_236.set_initial_value(30.0);
    ghostfollower_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter2'

    // Start for MATLABSystem: '<S3>/Get Parameter2'
    ghostfollower_DW.obj_k.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_k.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 't';
    b_zeroDelimTopic_0[1] = 'h';
    b_zeroDelimTopic_0[2] = '1';
    b_zeroDelimTopic_0[3] = '\x00';
    ParamGet_ghostfollower_226.initialize(&b_zeroDelimTopic_0[0]);
    ParamGet_ghostfollower_226.initialize_error_codes(0, 1, 2, 3);
    ParamGet_ghostfollower_226.set_initial_value(0.4);
    ghostfollower_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Get Parameter1'
    ghostfollower_DW.obj_c.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_c.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 't';
    b_zeroDelimTopic_0[1] = 'h';
    b_zeroDelimTopic_0[2] = '2';
    b_zeroDelimTopic_0[3] = '\x00';
    ParamGet_ghostfollower_228.initialize(&b_zeroDelimTopic_0[0]);
    ParamGet_ghostfollower_228.initialize_error_codes(0, 1, 2, 3);
    ParamGet_ghostfollower_228.set_initial_value(1.2);
    ghostfollower_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Get Parameter3'
    ghostfollower_DW.obj_n.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_n.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 't';
    b_zeroDelimTopic_0[1] = 'h';
    b_zeroDelimTopic_0[2] = '3';
    b_zeroDelimTopic_0[3] = '\x00';
    ParamGet_ghostfollower_230.initialize(&b_zeroDelimTopic_0[0]);
    ParamGet_ghostfollower_230.initialize_error_codes(0, 1, 2, 3);
    ParamGet_ghostfollower_230.set_initial_value(1.8);
    ghostfollower_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Get Parameter4'
    ghostfollower_DW.obj_j.matlabCodegenIsDeleted = false;
    ghostfollower_DW.obj_j.isInitialized = 1;
    b_zeroDelimName_0[0] = 'w';
    b_zeroDelimName_0[1] = '1';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_ghostfollower_245.initialize(&b_zeroDelimName_0[0]);
    ParamGet_ghostfollower_245.initialize_error_codes(0, 1, 2, 3);
    ParamGet_ghostfollower_245.set_initial_value(4.5);
    ghostfollower_DW.obj_j.isSetupComplete = true;
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(ghostfollower_M)) {
    rtmSetFirstInitCond(ghostfollower_M, 0);
  }
}

// Model terminate function
void ghostfollower_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!ghostfollower_DW.obj_f.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for MATLABSystem: '<Root>/Get Parameter2'
  if (!ghostfollower_DW.obj.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!ghostfollower_DW.obj_l.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!ghostfollower_DW.obj_dm.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_dm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for MATLABSystem: '<S3>/Get Parameter2'
  if (!ghostfollower_DW.obj_k.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter2'

  // Terminate for MATLABSystem: '<S3>/Get Parameter1'
  if (!ghostfollower_DW.obj_c.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter1'

  // Terminate for MATLABSystem: '<S3>/Get Parameter3'
  if (!ghostfollower_DW.obj_n.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter3'

  // Terminate for MATLABSystem: '<S3>/Get Parameter4'
  if (!ghostfollower_DW.obj_j.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter4'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!ghostfollower_DW.obj_o.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<S5>/Publish1'
  // Terminate for MATLABSystem: '<S14>/SinkBlock'
  if (!ghostfollower_DW.obj_d.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish1'

  // Terminate for Atomic SubSystem: '<S3>/Publish1'
  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!ghostfollower_DW.obj_kl.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_kl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!ghostfollower_DW.obj_g.matlabCodegenIsDeleted) {
    ghostfollower_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
