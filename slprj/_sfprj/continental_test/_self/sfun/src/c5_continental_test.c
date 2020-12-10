/* Include files */

#include <stddef.h>
#include "blas.h"
#include "continental_test_sfun.h"
#include "c5_continental_test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "continental_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[9] = { "i", "j", "nargin", "nargout",
  "CAR", "CAR2", "N", "CAR3", "car_a" };

/* Function Declarations */
static void initialize_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance);
static void initialize_params_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance);
static void enable_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance);
static void disable_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance);
static void set_sim_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance);
static void sf_gateway_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance);
static void initSimStructsc5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_car_a, const char_T *c5_identifier, real_T
  c5_y[3]);
static void c5_b_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_CAR3, const char_T *c5_identifier, real_T
  c5_y[24]);
static void c5_d_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[24]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_e_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_f_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_g_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_continental_test, const
  char_T *c5_identifier);
static uint8_T c5_h_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_continental_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_continental_test = 0U;
}

static void initialize_params_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[24];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i1;
  real_T c5_b_u[3];
  const mxArray *c5_c_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T (*c5_car_a)[3];
  real_T (*c5_CAR3)[24];
  c5_car_a = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_CAR3 = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(3, 1), false);
  for (c5_i0 = 0; c5_i0 < 24; c5_i0++) {
    c5_u[c5_i0] = (*c5_CAR3)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 8), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    c5_b_u[c5_i1] = (*c5_car_a)[c5_i1];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_continental_test;
  c5_c_u = c5_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[24];
  int32_T c5_i2;
  real_T c5_dv1[3];
  int32_T c5_i3;
  real_T (*c5_CAR3)[24];
  real_T (*c5_car_a)[3];
  c5_car_a = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_CAR3 = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                        "CAR3", c5_dv0);
  for (c5_i2 = 0; c5_i2 < 24; c5_i2++) {
    (*c5_CAR3)[c5_i2] = c5_dv0[c5_i2];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
                      "car_a", c5_dv1);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    (*c5_car_a)[c5_i3] = c5_dv1[c5_i3];
  }

  chartInstance->c5_is_active_c5_continental_test = c5_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
     "is_active_c5_continental_test");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_continental_test(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_continental_test(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  int32_T c5_i4;
  int32_T c5_i5;
  real_T c5_hoistedGlobal;
  int32_T c5_i6;
  real_T c5_CAR[24];
  int32_T c5_i7;
  real_T c5_CAR2[24];
  real_T c5_N;
  uint32_T c5_debug_family_var_map[9];
  real_T c5_i;
  real_T c5_j;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 2.0;
  real_T c5_CAR3[24];
  real_T c5_car_a[3];
  real_T c5_b_N;
  int32_T c5_i8;
  int32_T c5_b_i;
  real_T c5_c_N;
  int32_T c5_i9;
  int32_T c5_b_j;
  int32_T c5_c_j;
  int32_T c5_c_i;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  real_T *c5_d_N;
  real_T (*c5_b_CAR3)[24];
  real_T (*c5_b_car_a)[3];
  real_T (*c5_b_CAR2)[24];
  real_T (*c5_b_CAR)[24];
  c5_b_car_a = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_d_N = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_CAR3 = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_CAR2 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_CAR = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i4 = 0; c5_i4 < 24; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_CAR)[c5_i4], 0U);
  }

  for (c5_i5 = 0; c5_i5 < 24; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_CAR2)[c5_i5], 1U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_d_N;
  for (c5_i6 = 0; c5_i6 < 24; c5_i6++) {
    c5_CAR[c5_i6] = (*c5_b_CAR)[c5_i6];
  }

  for (c5_i7 = 0; c5_i7 < 24; c5_i7++) {
    c5_CAR2[c5_i7] = (*c5_b_CAR2)[c5_i7];
  }

  c5_N = c5_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 2U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_CAR, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_CAR2, 5U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_N, 6U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_CAR3, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_car_a, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_b_N = c5_N;
  c5_i8 = (int32_T)c5_b_N;
  _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c5_b_N, mxDOUBLE_CLASS, c5_i8);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i <= c5_i8 - 1) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
    c5_c_N = c5_N;
    c5_i9 = (int32_T)c5_c_N;
    _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c5_c_N, mxDOUBLE_CLASS, c5_i9);
    c5_j = 1.0;
    c5_b_j = 0;
    while (c5_b_j <= c5_i9 - 1) {
      c5_j = 1.0 + (real_T)c5_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
      if (CV_EML_IF(0, 1, 0, c5_CAR2[_SFD_EML_ARRAY_BOUNDS_CHECK("CAR2",
            (int32_T)_SFD_INTEGER_CHECK("i", c5_i), 1, 3, 1, 0) + 17] ==
                    c5_CAR[_SFD_EML_ARRAY_BOUNDS_CHECK("CAR", (int32_T)
            _SFD_INTEGER_CHECK("j", c5_j), 1, 3, 1, 0) + 17])) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
        c5_c_j = _SFD_EML_ARRAY_BOUNDS_CHECK("CAR", (int32_T)_SFD_INTEGER_CHECK(
          "j", c5_j), 1, 3, 1, 0) - 1;
        c5_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("CAR2", (int32_T)_SFD_INTEGER_CHECK
          ("i", c5_i), 1, 3, 1, 0) - 1;
        for (c5_i10 = 0; c5_i10 < 8; c5_i10++) {
          c5_CAR[c5_c_j + 3 * c5_i10] = c5_CAR2[c5_c_i + 3 * c5_i10];
        }
      }

      c5_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i11 = 0; c5_i11 < 24; c5_i11++) {
    c5_CAR3[c5_i11] = c5_CAR[c5_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_car_a[c5_i12] = c5_CAR3[c5_i12 + 6];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i13 = 0; c5_i13 < 24; c5_i13++) {
    (*c5_b_CAR3)[c5_i13] = c5_CAR3[c5_i13];
  }

  for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
    (*c5_b_car_a)[c5_i14] = c5_car_a[c5_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_continental_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i15 = 0; c5_i15 < 24; c5_i15++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_CAR3)[c5_i15], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_d_N, 3U);
  for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_car_a)[c5_i16], 4U);
  }
}

static void initSimStructsc5_continental_test
  (SFc5_continental_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i17;
  real_T c5_b_inData[3];
  int32_T c5_i18;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i17 = 0; c5_i17 < 3; c5_i17++) {
    c5_b_inData[c5_i17] = (*(real_T (*)[3])c5_inData)[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_u[c5_i18] = c5_b_inData[c5_i18];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_car_a, const char_T *c5_identifier, real_T
  c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_car_a), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_car_a);
}

static void c5_b_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv2[3];
  int32_T c5_i19;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c5_i19 = 0; c5_i19 < 3; c5_i19++) {
    c5_y[c5_i19] = c5_dv2[c5_i19];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_car_a;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i20;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_car_a = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_car_a), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_car_a);
  for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
    (*(real_T (*)[3])c5_outData)[c5_i20] = c5_y[c5_i20];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  real_T c5_b_inData[24];
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  real_T c5_u[24];
  const mxArray *c5_y = NULL;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i21 = 0;
  for (c5_i22 = 0; c5_i22 < 8; c5_i22++) {
    for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
      c5_b_inData[c5_i23 + c5_i21] = (*(real_T (*)[24])c5_inData)[c5_i23 +
        c5_i21];
    }

    c5_i21 += 3;
  }

  c5_i24 = 0;
  for (c5_i25 = 0; c5_i25 < 8; c5_i25++) {
    for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
      c5_u[c5_i26 + c5_i24] = c5_b_inData[c5_i26 + c5_i24];
    }

    c5_i24 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 8), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_CAR3, const char_T *c5_identifier, real_T
  c5_y[24])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_CAR3), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_CAR3);
}

static void c5_d_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[24])
{
  real_T c5_dv3[24];
  int32_T c5_i27;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 2, 3, 8);
  for (c5_i27 = 0; c5_i27 < 24; c5_i27++) {
    c5_y[c5_i27] = c5_dv3[c5_i27];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_CAR3;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[24];
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_CAR3 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_CAR3), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_CAR3);
  c5_i28 = 0;
  for (c5_i29 = 0; c5_i29 < 8; c5_i29++) {
    for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
      (*(real_T (*)[24])c5_outData)[c5_i30 + c5_i28] = c5_y[c5_i30 + c5_i28];
    }

    c5_i28 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_e_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_continental_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_f_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i31;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i31, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i31;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_continental_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_continental_testInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_continental_test, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_continental_test), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_continental_test);
  return c5_y;
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_continental_testInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_continental_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c5_continental_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1231125159U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2311567679U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3046319762U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(850190239U);
}

mxArray *sf_c5_continental_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AYq9XK2aK81glmAbLOEdkE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(8);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(8);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(8);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_continental_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_continental_test_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_continental_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"CAR3\",},{M[1],M[8],T\"car_a\",},{M[8],M[0],T\"is_active_c5_continental_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_continental_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_continental_testInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_continental_testInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _continental_testMachineNumber_,
           5,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_continental_testMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_continental_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _continental_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"CAR");
          _SFD_SET_DATA_PROPS(1,1,1,0,"CAR2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"CAR3");
          _SFD_SET_DATA_PROPS(3,1,1,0,"N");
          _SFD_SET_DATA_PROPS(4,2,0,1,"car_a");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,175);
        _SFD_CV_INIT_EML_IF(0,1,0,70,92,-1,132);
        _SFD_CV_INIT_EML_FOR(0,1,0,41,51,143);
        _SFD_CV_INIT_EML_FOR(0,1,1,54,64,139);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          real_T *c5_N;
          real_T (*c5_CAR)[24];
          real_T (*c5_CAR2)[24];
          real_T (*c5_CAR3)[24];
          real_T (*c5_car_a)[3];
          c5_car_a = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c5_N = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_CAR3 = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_CAR2 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 1);
          c5_CAR = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_CAR);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_CAR2);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_CAR3);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_N);
          _SFD_SET_DATA_VALUE_PTR(4U, *c5_car_a);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _continental_testMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "pGXlvqjNnLWGLZUKgBDTBC";
}

static void sf_opaque_initialize_c5_continental_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_continental_testInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
  initialize_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_continental_test(void *chartInstanceVar)
{
  enable_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_continental_test(void *chartInstanceVar)
{
  disable_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_continental_test(void *chartInstanceVar)
{
  sf_gateway_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_continental_test(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_continental_test
    ((SFc5_continental_testInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_continental_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_continental_test(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_continental_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_continental_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_continental_test(S);
}

static void sf_opaque_set_sim_state_c5_continental_test(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_continental_test(S, st);
}

static void sf_opaque_terminate_c5_continental_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_continental_testInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_continental_test_optimization_info();
    }

    finalize_c5_continental_test((SFc5_continental_testInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_continental_test((SFc5_continental_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_continental_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c5_continental_test((SFc5_continental_testInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_continental_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_continental_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4200976620U));
  ssSetChecksum1(S,(1333394981U));
  ssSetChecksum2(S,(1376426981U));
  ssSetChecksum3(S,(3142748069U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_continental_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_continental_test(SimStruct *S)
{
  SFc5_continental_testInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_continental_testInstanceStruct *)utMalloc(sizeof
    (SFc5_continental_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_continental_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_continental_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_continental_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_continental_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_continental_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_continental_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_continental_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_continental_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_continental_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_continental_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_continental_test;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_continental_test;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_continental_test_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_continental_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_continental_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_continental_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_continental_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
