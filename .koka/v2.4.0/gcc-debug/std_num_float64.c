// Koka generated module: "std/num/float64", koka version: 2.4.0, platform: 64-bit
#include "std_num_float64.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static inline int64_t kk_double_to_bits( double d, kk_context_t* ctx ) {
  kk_unused(ctx);
  return (int64_t)kk_bits_from_double(d);
}

static inline double kk_double_from_bits( int64_t i, kk_context_t* ctx ) {
  kk_unused(ctx);
  return kk_bits_to_double((uint64_t)i);
}

static inline double kk_prim_parse_double( kk_string_t str, kk_context_t* ctx) {
  const char* s = kk_string_cbuf_borrow(str,NULL);
  char* end;
  double d = strtod(s,&end);
  kk_string_drop(str,ctx);  
  return d;
}

 
// The maximum of a list of absolute values.


// lift anonymous function
struct kk_std_num_float64_abs_max_fun4817__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_abs_max_fun4817_1(kk_function_t _fself, kk_box_t _b_4252, kk_box_t _b_4253, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_abs_max_fun4817_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_abs_max_fun4817_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_abs_max_fun4817_1(kk_function_t _fself, kk_box_t _b_4252, kk_box_t _b_4253, kk_context_t* _ctx) {
  kk_unused(_fself);
  double m_4257 = kk_double_unbox(_b_4252, _ctx); /*float64*/;
  double x_4258 = kk_double_unbox(_b_4253, _ctx); /*float64*/;
  double x0_3958 = kk_double_abs(x_4258); /*float64*/;
  double _x4818;
  bool _match_4812 = (x0_3958 >= m_4257); /*bool*/;
  if (_match_4812) {
    _x4818 = x0_3958; /*float64*/
  }
  else {
    _x4818 = m_4257; /*float64*/
  }
  return kk_double_box(_x4818, _ctx);
}

double kk_std_num_float64_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  kk_box_t _x4816 = kk_std_core_foldl(xs, kk_double_box(0.0, _ctx), kk_std_num_float64_new_abs_max_fun4817_1(_ctx), _ctx); /*12365*/
  return kk_double_unbox(_x4816, _ctx);
}
 
// The area hyperbolic cosine of `d`

double kk_std_num_float64_acosh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return acosh(d);
}
 
// The area hyperbolic sine of `d`

double kk_std_num_float64_asinh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return asinh(d);
}
 
// The area hyperbolic tangent of `d`

double kk_std_num_float64_atanh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return atanh(d);
}
 
// Low-level: return the bits of a 64-bit `:float64` as in `:int64`

int64_t kk_std_num_float64_float64_to_bits(double d, kk_context_t* _ctx) { /* (d : float64) -> int64 */ 
  return kk_double_to_bits(d,kk_context());
}
 
// Extend a `:float32` to a `:float64`

double kk_std_num_float64_float64(float f, kk_context_t* _ctx) { /* (f : float32) -> float64 */ 
  return (double)(f);
}
 
// Low-level: create a `:float64` from the given 64-bit integer.

double kk_std_num_float64_float64_from_bits(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> float64 */ 
  return kk_double_from_bits(i,kk_context());
}

double kk_std_num_float64_make_neginf(kk_context_t* _ctx) { /* () -> float64 */ 
  return -HUGE_VAL;
}

double kk_std_num_float64_make_posinf(kk_context_t* _ctx) { /* () -> float64 */ 
  return HUGE_VAL;
}
 
// Round a `:float64` to a `:float32`

float kk_std_num_float64_float32(double f, kk_context_t* _ctx) { /* (f : float64) -> float32 */ 
  return (float)(f);
}

kk_integer_t kk_std_num_float64_flt_max_prec;
 
// fused multiply-add. Computes `(x*y)+z` as if to infinite precision
// with only the final result rounded back to a `:float64`.

double kk_std_num_float64_fmadd(double x, double y, double z, kk_context_t* _ctx) { /* (x : float64, y : float64, z : float64) -> float64 */ 
  return fma(x,y,z);
}
 
// Return the sum of a list of floats.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.


// lift anonymous function
struct kk_std_num_float64_sum_fun4822__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_unit_t kk_std_num_float64_sum_fun4822(kk_function_t _fself, kk_box_t _b_4281, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_sum_fun4822(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_std_num_float64_sum_fun4822__t* _self = kk_function_alloc_as(struct kk_std_num_float64_sum_fun4822__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_sum_fun4822, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_unit_t kk_std_num_float64_sum_fun4822(kk_function_t _fself, kk_box_t _b_4281, kk_context_t* _ctx) {
  struct kk_std_num_float64_sum_fun4822__t* _self = kk_function_as(struct kk_std_num_float64_sum_fun4822__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<670,float64> */
  kk_ref_t loc0 = _self->loc0; /* local-var<670,float64> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double x_4286 = kk_double_unbox(_b_4281, _ctx); /*float64*/;
  double t;
  double _x4823;
  kk_box_t _x4824;
  kk_ref_t _x4825 = kk_ref_dup(loc); /*local-var<670,float64>*/
  _x4824 = kk_ref_get(_x4825,kk_context()); /*260*/
  _x4823 = kk_double_unbox(_x4824, _ctx); /*float64*/
  t = (_x4823 + x_4286); /*float64*/
  double c;
  bool _match_4809;
  double _x4826;
  double _x4827;
  kk_box_t _x4828;
  kk_ref_t _x4829 = kk_ref_dup(loc); /*local-var<670,float64>*/
  _x4828 = kk_ref_get(_x4829,kk_context()); /*260*/
  _x4827 = kk_double_unbox(_x4828, _ctx); /*float64*/
  _x4826 = kk_double_abs(_x4827); /*float64*/
  double _x4830 = kk_double_abs(x_4286); /*float64*/
  _match_4809 = (_x4826 >= _x4830); /*bool*/
  if (_match_4809) {
    double _x4831;
    double _x4832;
    kk_box_t _x4833;
    kk_ref_t _x4834 = kk_ref_dup(loc); /*local-var<670,float64>*/
    _x4833 = kk_ref_get(_x4834,kk_context()); /*260*/
    _x4832 = kk_double_unbox(_x4833, _ctx); /*float64*/
    _x4831 = (_x4832 - t); /*float64*/
    c = (_x4831 + x_4286); /*float64*/
  }
  else {
    double _x4835 = (x_4286 - t); /*float64*/
    double _x4836;
    kk_box_t _x4837;
    kk_ref_t _x4838 = kk_ref_dup(loc); /*local-var<670,float64>*/
    _x4837 = kk_ref_get(_x4838,kk_context()); /*260*/
    _x4836 = kk_double_unbox(_x4837, _ctx); /*float64*/
    c = (_x4835 + _x4836); /*float64*/
  }
  double _b_4275_4273;
  double _x4839;
  kk_box_t _x4840;
  kk_ref_t _x4841 = kk_ref_dup(loc0); /*local-var<670,float64>*/
  _x4840 = kk_ref_get(_x4841,kk_context()); /*260*/
  _x4839 = kk_double_unbox(_x4840, _ctx); /*float64*/
  _b_4275_4273 = (_x4839 + c); /*float64*/
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_4808 = kk_Unit;
  kk_ref_set_borrow(loc0,(kk_double_box(_b_4275_4273, _ctx)),kk_context());
  kk_ref_drop(loc0, _ctx);
  _brw_4808;
  kk_unit_t _brw_4807 = kk_Unit;
  kk_ref_set_borrow(loc,(kk_double_box(t, _ctx)),kk_context());
  kk_ref_drop(loc, _ctx);
  return _brw_4807;
}

double kk_std_num_float64_sum(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  kk_ref_t loc = kk_ref_alloc((kk_double_box(0.0, _ctx)),kk_context()); /*local-var<670,float64>*/;
  kk_ref_t loc0 = kk_ref_alloc((kk_double_box(0.0, _ctx)),kk_context()); /*local-var<670,float64>*/;
  kk_unit_t __0 = kk_Unit;
  kk_function_t _x4821;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x4821 = kk_std_num_float64_new_sum_fun4822(loc, loc0, _ctx); /*(11054) -> 11055 ()*/
  kk_std_core_foreach(xs, _x4821, _ctx);
  double res0;
  double _x4842;
  kk_box_t _x4843;
  kk_ref_t _x4844 = kk_ref_dup(loc); /*local-var<670,float64>*/
  _x4843 = kk_ref_get(_x4844,kk_context()); /*260*/
  _x4842 = kk_double_unbox(_x4843, _ctx); /*float64*/
  double _x4845;
  kk_box_t _x4846;
  kk_ref_t _x4847 = kk_ref_dup(loc0); /*local-var<670,float64>*/
  _x4846 = kk_ref_get(_x4847,kk_context()); /*260*/
  _x4845 = kk_double_unbox(_x4846, _ctx); /*float64*/
  res0 = (_x4842 + _x4845); /*float64*/
  double res;
  kk_box_t _x4848 = kk_std_core_hnd_prompt_local_var(loc0, kk_double_box(res0, _ctx), _ctx); /*10459*/
  res = kk_double_unbox(_x4848, _ctx); /*float64*/
  kk_box_t _x4849 = kk_std_core_hnd_prompt_local_var(loc, kk_double_box(res, _ctx), _ctx); /*10459*/
  return kk_double_unbox(_x4849, _ctx);
}
 
// Is this value equal to negative or positive infinity ?

bool kk_std_num_float64_is_inf(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  return isinf(d);
}

double kk_std_num_float64_make_nan(kk_context_t* _ctx) { /* () -> float64 */ 
  return (double)NAN;
}
 
// Return `nan` on failure

double kk_std_num_float64_prim_parse_float64(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> float64 */ 
  return kk_prim_parse_double(s,kk_context());
}
 
// Compare floats using a total ordering on the `:float64`.
// The ordering follows the `totalOrder` predicate as defined in IEEE 754-2008 exactly.
// The values are ordered in following order:
// - negative quiet nan
// - negative signaling nan
// - `neginf`
// - -finite
// - -0.0
// - +0.0
// - finite
// - `posinf`
// - signaling nan
// - quiet nan
//

kk_std_core_types__order kk_std_num_float64_compare(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> order */ 
  int64_t bx = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
  int64_t by = kk_std_num_float64_float64_to_bits(y, _ctx); /*int64*/;
  int64_t i_3961;
  int64_t _x4853 = (KK_I64(63)); /*int64*/
  i_3961 = kk_sar64(bx,_x4853); /*int64*/
  int64_t ix;
  int64_t _x4854;
  int64_t _x4855 = (KK_I64(1)); /*int64*/
  _x4854 = (int64_t)kk_shr64(i_3961,_x4855); /*int64*/
  ix = _x4854 ^ bx; /*int64*/
  int64_t i1_3965;
  int64_t _x4856 = (KK_I64(63)); /*int64*/
  i1_3965 = kk_sar64(by,_x4856); /*int64*/
  int64_t iy;
  int64_t _x4857;
  int64_t _x4858 = (KK_I64(1)); /*int64*/
  _x4857 = (int64_t)kk_shr64(i1_3965,_x4858); /*int64*/
  iy = _x4857 ^ by; /*int64*/
  bool _match_4804 = (ix < iy); /*bool*/;
  if (_match_4804) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  {
    bool _match_4805 = (ix > iy); /*bool*/;
    if (_match_4805) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}
 
// decode a normalized float64 (i.e. not subnormal)

kk_std_core_types__tuple2_ kk_std_num_float64_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx) { /* (d : float64, e-adjust : optional<int>) -> (int, int) */ 
  int64_t i = kk_std_num_float64_float64_to_bits(d, _ctx); /*int64*/;
  int64_t exp;
  int64_t _x4859;
  int64_t _x4860;
  int64_t _x4861 = (KK_I64(52)); /*int64*/
  _x4860 = (int64_t)kk_shr64(i,_x4861); /*int64*/
  int64_t _x4862 = (KK_I64(2047)); /*int64*/
  _x4859 = _x4860 & _x4862; /*int64*/
  int64_t _x4863 = (KK_I64(1043)); /*int64*/
  exp = (int64_t)((uint64_t)_x4859 - (uint64_t)_x4863); /*int64*/
  int64_t man;
  int64_t _x4864;
  int64_t _x4865 = (KK_I64(4503599627370495)); /*int64*/
  _x4864 = i & _x4865; /*int64*/
  int64_t _x4866 = (KK_I64(4503599627370496)); /*int64*/
  man = (int64_t)((uint64_t)_x4864 + (uint64_t)_x4866); /*int64*/
  kk_integer_t x0_3976 = kk_integer_from_int64(exp,kk_context()); /*int*/;
  kk_integer_t x_3974 = kk_integer_add_small_const(x0_3976, -32, _ctx); /*int*/;
  kk_integer_t _b_4302_4300;
  int64_t _x4867;
  bool _match_4803 = 0 > i; /*bool*/;
  if (_match_4803) {
    int64_t _x4868 = (KK_I64(0)); /*int64*/
    _x4867 = (int64_t)((uint64_t)_x4868 - (uint64_t)man); /*int64*/
  }
  else {
    _x4867 = man; /*int64*/
  }
  _b_4302_4300 = kk_integer_from_int64(_x4867,kk_context()); /*int*/
  kk_integer_t _b_4303_4301;
  kk_integer_t _x4869;
  if (kk_std_core_types__is_Optional(e_adjust)) {
    kk_box_t _box_x4299 = e_adjust._cons.Optional.value;
    kk_integer_t _e_adjust_804 = kk_integer_unbox(_box_x4299);
    _x4869 = _e_adjust_804; /*int*/
  }
  else {
    _x4869 = kk_integer_from_small(0); /*int*/
  }
  _b_4303_4301 = kk_integer_add(x_3974,_x4869,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_4302_4300), kk_integer_box(_b_4303_4301), _ctx);
}
 
// Decode a float64 `d` into a tuple `(m,e)` of a mantissa `m` and exponent `e`
// such that `m`&middot;2^`e`^ =  `d` exactly. The mantissa `m` is
// always either 0 or in the range [2^52^, 2^53^). See also `frexp`.

kk_std_core_types__tuple2_ kk_std_num_float64_decode(double d, kk_context_t* _ctx) { /* (d : float64) -> (int, int) */ 
  bool _match_4799 = (d == (0.0)); /*bool*/;
  if (_match_4799) {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(kk_integer_from_small(0)), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
  {
    bool _match_4800 = (d != (0.0)); /*bool*/;
    if (_match_4800) {
      bool _match_4801;
      double _x4872 = kk_double_abs(d); /*float64*/
      _match_4801 = (_x4872 < (2.2250738585072014e-308)); /*bool*/
      if (_match_4801) {
        double _x4873 = (d * (1.8014398509481984e16)); /*float64*/
        kk_std_core_types__optional _x4874 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(-54)), _ctx); /*optional<112>*/
        return kk_std_num_float64_decode_normalized(_x4873, _x4874, _ctx);
      }
      {
        kk_std_core_types__optional _x4875 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<112>*/
        return kk_std_num_float64_decode_normalized(d, _x4875, _ctx);
      }
    }
    {
      kk_std_core_types__optional _x4876 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<112>*/
      return kk_std_num_float64_decode_normalized(d, _x4876, _ctx);
    }
  }
}

double kk_std_num_float64_rad2deg;

double kk_std_num_float64_deg2rad;
 
// Calculate 2&middot;^`e`^ for an integer `e`.
// Uses efficient bit conversion for exponents between  -1022 and 1023 and
// otherwise falls back to the regular `exp2` function converting `e` to a float64.

double kk_std_num_float64_exp2_1(kk_integer_t e, kk_context_t* _ctx) { /* (e : int) -> float64 */ 
  bool _match_4797 = kk_integer_gte_borrow(e,(kk_integer_from_small(-1022)),kk_context()); /*bool*/;
  if (_match_4797) {
    bool _match_4798 = kk_integer_lte_borrow(e,(kk_integer_from_small(1023)),kk_context()); /*bool*/;
    if (_match_4798) {
      int64_t i_3979;
      kk_integer_t _x4877 = kk_integer_add_small_const(e, 1023, _ctx); /*int*/
      i_3979 = kk_std_core_int64(_x4877, _ctx); /*int64*/
      int64_t _x4878;
      int64_t _x4879 = (KK_I64(52)); /*int64*/
      _x4878 = kk_shl64(i_3979,_x4879); /*int64*/
      return kk_std_num_float64_float64_from_bits(_x4878, _ctx);
    }
    {
      double _x4880 = kk_integer_as_double(e,kk_context()); /*float64*/
      return exp2(_x4880);
    }
  }
  {
    double _x4881 = kk_integer_as_double(e,kk_context()); /*float64*/
    return exp2(_x4881);
  }
}
 
// Negative infinity

double kk_std_num_float64_neginf;
 
// Positive infinity

double kk_std_num_float64_posinf;
 
// 'Load exponent': returns `x`&middot;2^`e`^ for a `is-finite` `x` and
// otherwise `x` itself. See also `encode` which loads an integer mantissa.

double kk_std_num_float64_ldexp(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : float64, e : int) -> float64 */ 
  bool b_3983 = isfinite(x); /*bool*/;
  if (b_3983) {
    bool _match_4789 = kk_integer_gte_borrow(e,(kk_integer_from_small(-1022)),kk_context()); /*bool*/;
    if (_match_4789) {
      bool _match_4793 = kk_integer_lte_borrow(e,(kk_integer_from_small(1023)),kk_context()); /*bool*/;
      if (_match_4793) {
        double _x4883 = kk_std_num_float64_exp2_1(e, _ctx); /*float64*/
        return (x * _x4883);
      }
      {
        bool _match_4794 = kk_integer_lte_borrow(e,(kk_integer_from_small(2046)),kk_context()); /*bool*/;
        if (_match_4794) {
          double x1_3986 = (x * (8.98846567431158e307)); /*float64*/;
          kk_integer_t e1_3987 = kk_integer_add_small_const(e, -1023, _ctx); /*int*/;
          double _x4884 = kk_std_num_float64_exp2_1(e1_3987, _ctx); /*float64*/
          return (x1_3986 * _x4884);
        }
        {
          bool _match_4795 = kk_integer_lte_borrow(e,(kk_integer_from_small(3069)),kk_context()); /*bool*/;
          if (_match_4795) {
            double x3_3990;
            double _x4885 = (x * (8.98846567431158e307)); /*float64*/
            x3_3990 = (_x4885 * (8.98846567431158e307)); /*float64*/
            kk_integer_t e2_3991 = kk_integer_add_small_const(e, -2046, _ctx); /*int*/;
            double _x4886 = kk_std_num_float64_exp2_1(e2_3991, _ctx); /*float64*/
            return (x3_3990 * _x4886);
          }
          {
            kk_integer_drop(e, _ctx);
            bool _match_4796 = (x < (0.0)); /*bool*/;
            if (_match_4796) {
              return kk_std_num_float64_neginf;
            }
            {
              return kk_std_num_float64_posinf;
            }
          }
        }
      }
    }
    {
      bool _match_4790 = kk_integer_gte_borrow(e,(kk_integer_from_small(-2044)),kk_context()); /*bool*/;
      if (_match_4790) {
        double x5_3994 = (x * (2.2250738585072014e-308)); /*float64*/;
        kk_integer_t e3_3995 = kk_integer_add_small_const(e, 1022, _ctx); /*int*/;
        double _x4887 = kk_std_num_float64_exp2_1(e3_3995, _ctx); /*float64*/
        return (x5_3994 * _x4887);
      }
      {
        bool _match_4791 = kk_integer_gte_borrow(e,(kk_integer_from_small(-3066)),kk_context()); /*bool*/;
        if (_match_4791) {
          double x7_3998;
          double _x4888 = (x * (2.2250738585072014e-308)); /*float64*/
          x7_3998 = (_x4888 * (2.2250738585072014e-308)); /*float64*/
          kk_integer_t e4_3999 = kk_integer_add_small_const(e, 2044, _ctx); /*int*/;
          double _x4889 = kk_std_num_float64_exp2_1(e4_3999, _ctx); /*float64*/
          return (x7_3998 * _x4889);
        }
        {
          kk_integer_drop(e, _ctx);
          bool _match_4792 = (x < (0.0)); /*bool*/;
          if (_match_4792) {
            return -0.0;
          }
          {
            return 0.0;
          }
        }
      }
    }
  }
  {
    kk_integer_drop(e, _ctx);
    return x;
  }
}
 
// 'Fraction/exponent': return the normalized fraction `f` and exponent `exp`
// for a number `x` such that `x == f`&middot;2^`exp`^.
// The absolute value of the fraction `f` is always in the range [0.5, 1.0), or
// one of `0.0`, `-0.0`, `neginf`, `posinf`, or `nan`.
// See also `decode` which  decodes to an integer mantissa.

kk_std_core_types__tuple2_ kk_std_num_float64_frexp(double x, kk_context_t* _ctx) { /* (x : float64) -> (float64, int) */ 
  bool b_4003 = isfinite(x); /*bool*/;
  if (b_4003) {
    bool _match_4784 = (x == (0.0)); /*bool*/;
    if (_match_4784) {
      bool _match_4786;
      double _x4893 = ((1.0) / x); /*float64*/
      _match_4786 = (isinf(_x4893) && signbit(_x4893)); /*bool*/
      if (_match_4786) {
        return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(x, _ctx), kk_integer_box(kk_integer_from_small(0)), _ctx);
      }
      {
        kk_std_core_types__tuple2_ _match_4787 = kk_std_num_float64_decode(x, _ctx); /*(int, int)*/;
        {
          kk_box_t _box_x4316 = _match_4787.fst;
          kk_box_t _box_x4317 = _match_4787.snd;
          kk_integer_t m = kk_integer_unbox(_box_x4316);
          kk_integer_t e = kk_integer_unbox(_box_x4317);
          kk_integer_dup(e);
          kk_integer_dup(m);
          kk_std_core_types__tuple2__drop(_match_4787, _ctx);
          double _b_4328_4318;
          double _x4896 = kk_integer_as_double(m,kk_context()); /*float64*/
          _b_4328_4318 = (_x4896 * (1.1102230246251565e-16)); /*float64*/
          kk_integer_t _b_4329_4319 = kk_integer_add_small_const(e, 53, _ctx); /*int*/;
          return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(_b_4328_4318, _ctx), kk_integer_box(_b_4329_4319), _ctx);
        }
      }
    }
    {
      kk_std_core_types__tuple2_ _match_4785 = kk_std_num_float64_decode(x, _ctx); /*(int, int)*/;
      {
        kk_box_t _box_x4320 = _match_4785.fst;
        kk_box_t _box_x4321 = _match_4785.snd;
        kk_integer_t m0 = kk_integer_unbox(_box_x4320);
        kk_integer_t e0 = kk_integer_unbox(_box_x4321);
        kk_integer_dup(e0);
        kk_integer_dup(m0);
        kk_std_core_types__tuple2__drop(_match_4785, _ctx);
        double _b_4330_4322;
        double _x4899 = kk_integer_as_double(m0,kk_context()); /*float64*/
        _b_4330_4322 = (_x4899 * (1.1102230246251565e-16)); /*float64*/
        kk_integer_t _b_4331_4323 = kk_integer_add_small_const(e0, 53, _ctx); /*int*/;
        return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(_b_4330_4322, _ctx), kk_integer_box(_b_4331_4323), _ctx);
      }
    }
  }
  {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(x, _ctx), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
}
 
// The hypotenuse of `x` and `y`: `sqrt(x*x + y*y)`.
// Prevents overflow for large numbers.

double kk_std_num_float64_hypot(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  double xx = kk_double_abs(x); /*float64*/;
  double yy = kk_double_abs(y); /*float64*/;
  double lo;
  bool _match_4783 = (xx <= yy); /*bool*/;
  if (_match_4783) {
    lo = xx; /*float64*/
  }
  else {
    lo = yy; /*float64*/
  }
  double hi;
  bool _match_4782 = (xx >= yy); /*bool*/;
  if (_match_4782) {
    hi = xx; /*float64*/
  }
  else {
    hi = yy; /*float64*/
  }
  bool _match_4781 = (hi == (0.0)); /*bool*/;
  if (_match_4781) {
    return 0.0;
  }
  {
    double z = (lo / hi); /*float64*/;
    double _x4900;
    double _x4901;
    double _x4902 = (z * z); /*float64*/
    _x4901 = ((1.0) + _x4902); /*float64*/
    _x4900 = sqrt(_x4901); /*float64*/
    return (hi * _x4900);
  }
}
 
// The square root of the sum of the squares of three floats.
// Prevents overflow for large numbers.

double kk_std_num_float64_hypot_1(double x, double y, double z, kk_context_t* _ctx) { /* (x : float64, y : float64, z : float64) -> float64 */ 
  double xx = kk_double_abs(x); /*float64*/;
  double yy = kk_double_abs(y); /*float64*/;
  double zz = kk_double_abs(z); /*float64*/;
  double x0_4011;
  bool _match_4780 = (xx >= yy); /*bool*/;
  if (_match_4780) {
    x0_4011 = xx; /*float64*/
  }
  else {
    x0_4011 = yy; /*float64*/
  }
  double hi;
  bool _match_4779 = (x0_4011 >= zz); /*bool*/;
  if (_match_4779) {
    hi = x0_4011; /*float64*/
  }
  else {
    hi = zz; /*float64*/
  }
  bool _match_4778 = (hi == (0.0)); /*bool*/;
  if (_match_4778) {
    return 0.0;
  }
  {
    double x4_4017 = (zz / hi); /*float64*/;
    double x2_4015 = (xx / hi); /*float64*/;
    double x3_4016 = (yy / hi); /*float64*/;
    double _x4903;
    double _x4904;
    double _x4905;
    double _x4906 = (x2_4015 * x2_4015); /*float64*/
    double _x4907 = (x3_4016 * x3_4016); /*float64*/
    _x4905 = (_x4906 + _x4907); /*float64*/
    double _x4908 = (x4_4017 * x4_4017); /*float64*/
    _x4904 = (_x4905 + _x4908); /*float64*/
    _x4903 = sqrt(_x4904); /*float64*/
    return (hi * _x4903);
  }
}
 
// The square root of the sum of squares of a list of floats.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.


// lift anonymous function
struct kk_std_num_float64_hypot_fun4911__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_hypot_fun4911_2(kk_function_t _fself, kk_box_t _b_4337, kk_box_t _b_4338, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_hypot_fun4911_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_hypot_fun4911_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_hypot_fun4911_2(kk_function_t _fself, kk_box_t _b_4337, kk_box_t _b_4338, kk_context_t* _ctx) {
  kk_unused(_fself);
  double x0_3958;
  double _x4912 = kk_double_unbox(_b_4338, _ctx); /*float64*/
  x0_3958 = kk_double_abs(_x4912); /*float64*/
  double _x4913;
  bool _match_4777;
  double _x4914;
  kk_box_t _x4915 = kk_box_dup(_b_4337); /*12365*/
  _x4914 = kk_double_unbox(_x4915, _ctx); /*float64*/
  _match_4777 = (x0_3958 >= _x4914); /*bool*/
  if (_match_4777) {
    kk_box_drop(_b_4337, _ctx);
    _x4913 = x0_3958; /*float64*/
  }
  else {
    _x4913 = kk_double_unbox(_b_4337, _ctx); /*float64*/
  }
  return kk_double_box(_x4913, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_hypot_fun4917__t_2 {
  struct kk_function_s _base;
  double hi;
};
static double kk_std_num_float64_hypot_fun4917_2(kk_function_t _fself, double x0, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_hypot_fun4917_2(double hi, kk_context_t* _ctx) {
  struct kk_std_num_float64_hypot_fun4917__t_2* _self = kk_function_alloc_as(struct kk_std_num_float64_hypot_fun4917__t_2, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_hypot_fun4917_2, kk_context());
  _self->hi = hi;
  return &_self->_base;
}

static double kk_std_num_float64_hypot_fun4917_2(kk_function_t _fself, double x0, kk_context_t* _ctx) {
  struct kk_std_num_float64_hypot_fun4917__t_2* _self = kk_function_as(struct kk_std_num_float64_hypot_fun4917__t_2*, _fself);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {;}, {}, _ctx)
  double x0_4018 = (x0 / hi); /*float64*/;
  return (x0_4018 * x0_4018);
}


// lift anonymous function
struct kk_std_num_float64_hypot_fun4920__t_2 {
  struct kk_function_s _base;
  kk_function_t _b_4348_4345;
};
static kk_box_t kk_std_num_float64_hypot_fun4920_2(kk_function_t _fself, kk_box_t _b_4346, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_hypot_fun4920_2(kk_function_t _b_4348_4345, kk_context_t* _ctx) {
  struct kk_std_num_float64_hypot_fun4920__t_2* _self = kk_function_alloc_as(struct kk_std_num_float64_hypot_fun4920__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_hypot_fun4920_2, kk_context());
  _self->_b_4348_4345 = _b_4348_4345;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_hypot_fun4920_2(kk_function_t _fself, kk_box_t _b_4346, kk_context_t* _ctx) {
  struct kk_std_num_float64_hypot_fun4920__t_2* _self = kk_function_as(struct kk_std_num_float64_hypot_fun4920__t_2*, _fself);
  kk_function_t _b_4348_4345 = _self->_b_4348_4345; /* (x0 : float64) -> float64 */
  kk_drop_match(_self, {kk_function_dup(_b_4348_4345);}, {}, _ctx)
  double _x4921;
  double _x4922 = kk_double_unbox(_b_4346, _ctx); /*float64*/
  _x4921 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _b_4348_4345, (_b_4348_4345, _x4922, _ctx)); /*float64*/
  return kk_double_box(_x4921, _ctx);
}

double kk_std_num_float64_hypot_2(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  double hi;
  kk_box_t _x4909;
  kk_std_core__list _x4910 = kk_std_core__list_dup(xs); /*list<float64>*/
  _x4909 = kk_std_core_foldl(_x4910, kk_double_box(0.0, _ctx), kk_std_num_float64_new_hypot_fun4911_2(_ctx), _ctx); /*12365*/
  hi = kk_double_unbox(_x4909, _ctx); /*float64*/
  bool _match_4776 = (hi == (0.0)); /*bool*/;
  if (_match_4776) {
    kk_std_core__list_drop(xs, _ctx);
    return 0.0;
  }
  {
    double _x4916;
    kk_std_core__list _b_4347_4344 = xs; /*list<float64>*/;
    kk_function_t _b_4348_4345 = kk_std_num_float64_new_hypot_fun4917_2(hi, _ctx); /*(x0 : float64) -> float64*/;
    double _x4918;
    kk_std_core__list _x4919 = kk_std_core_map_5(_b_4347_4344, kk_std_num_float64_new_hypot_fun4920_2(_b_4348_4345, _ctx), _ctx); /*list<6195>*/
    _x4918 = kk_std_num_float64_sum(_x4919, _ctx); /*float64*/
    _x4916 = sqrt(_x4918); /*float64*/
    return (hi * _x4916);
  }
}
 
// Returns `ln(exp(x) + exp(y))`.
// Avoids overlow/underflow errors.

double kk_std_num_float64_lnaddexp(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_4774 = (x == y); /*bool*/;
  if (_match_4774) {
    return (x + (0.6931471805599453));
  }
  {
    double z = (x - y); /*float64*/;
    bool _match_4775 = (z > (0.0)); /*bool*/;
    if (_match_4775) {
      double _x4923;
      double _x4924;
      double _x4925 = (-z); /*float64*/
      _x4924 = exp(_x4925); /*float64*/
      _x4923 = log1p(_x4924); /*float64*/
      return (x + _x4923);
    }
    {
      double _x4926;
      double _x4927 = exp(z); /*float64*/
      _x4926 = log1p(_x4927); /*float64*/
      return (y + _x4926);
    }
  }
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overlow/underflow errors.

double kk_std_num_float64_logaddexp2(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_4772 = (x == y); /*bool*/;
  if (_match_4772) {
    return (x + (1.0));
  }
  {
    double z = (x - y); /*float64*/;
    bool _match_4773 = (z > (0.0)); /*bool*/;
    if (_match_4773) {
      double x0_4019;
      double _x4929 = (-z); /*float64*/
      x0_4019 = exp2(_x4929); /*float64*/
      double _x4930;
      double _x4931 = log1p(x0_4019); /*float64*/
      _x4930 = ((1.4426950408889634) * _x4931); /*float64*/
      return (x + _x4930);
    }
    {
      double x1_4020 = exp2(z); /*float64*/;
      double _x4932;
      double _x4933 = log1p(x1_4020); /*float64*/
      _x4932 = ((1.4426950408889634) * _x4933); /*float64*/
      return (y + _x4932);
    }
  }
}
 
// Represents a value that is _not a number_ (NaN)

double kk_std_num_float64_nan;
 
// Return if two floats are nearly equal with respect to some `epsilon` (=`8*flt-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for subnormal numbers.

bool kk_std_num_float64_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : float64, y : float64, epsilon : optional<float64>) -> bool */ 
  double _epsilon_2570;
  if (kk_std_core_types__is_Optional(epsilon)) {
    kk_box_t _box_x4349 = epsilon._cons.Optional.value;
    double _epsilon_2571 = kk_double_unbox(_box_x4349, NULL);
    kk_std_core_types__optional_drop(epsilon, _ctx);
    _epsilon_2570 = _epsilon_2571; /*float64*/
  }
  else {
    _epsilon_2570 = ((8.0) * (2.220446049250313e-16)); /*float64*/
  }
  bool _match_4767 = (x == y); /*bool*/;
  if (_match_4767) {
    return true;
  }
  {
    double diff;
    double _x4935 = (x - y); /*float64*/
    diff = kk_double_abs(_x4935); /*float64*/
    bool _match_4768 = (x == (0.0)); /*bool*/;
    if (_match_4768) {
      double _x4936 = ((2.0) * diff); /*float64*/
      double _x4937 = (_epsilon_2570 * (2.2250738585072014e-308)); /*float64*/
      return (_x4936 < _x4937);
    }
    {
      bool _match_4769 = (y == (0.0)); /*bool*/;
      if (_match_4769) {
        double _x4938 = ((2.0) * diff); /*float64*/
        double _x4939 = (_epsilon_2570 * (2.2250738585072014e-308)); /*float64*/
        return (_x4938 < _x4939);
      }
      {
        bool _match_4770 = (diff < (2.2250738585072014e-308)); /*bool*/;
        if (_match_4770) {
          double _x4940 = ((2.0) * diff); /*float64*/
          double _x4941 = (_epsilon_2570 * (2.2250738585072014e-308)); /*float64*/
          return (_x4940 < _x4941);
        }
        {
          double sum0;
          double _x4942 = kk_double_abs(x); /*float64*/
          double _x4943 = kk_double_abs(y); /*float64*/
          sum0 = (_x4942 + _x4943); /*float64*/
          double _x4944;
          double _x4945 = ((2.0) * diff); /*float64*/
          double _x4946;
          bool _match_4771 = (sum0 > (1.7976931348623157e308)); /*bool*/;
          if (_match_4771) {
            _x4946 = 1.7976931348623157e308; /*float64*/
          }
          else {
            _x4946 = sum0; /*float64*/
          }
          _x4944 = (_x4945 / _x4946); /*float64*/
          return (_x4944 < _epsilon_2570);
        }
      }
    }
  }
}
 
// Returns the greatest `:float64` less than `x`.
// This behaves exactly as `nextDown` in the IEEE 754-2008 standard.
// The identity `x.next-down == ~next-down(~x)` holds for all `x`.
// When `x` is finite `x == x.next-down.next-up` also holds.

double kk_std_num_float64_next_down(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  bool _match_4763 = isnan(x); /*bool*/;
  if (_match_4763) {
    return x;
  }
  {
    bool _match_4764 = (isinf(x) && signbit(x)); /*bool*/;
    if (_match_4764) {
      return x;
    }
    {
      bool _match_4765 = (x == (0.0)); /*bool*/;
      if (_match_4765) {
        return (-(5.0e-324));
      }
      {
        int64_t i = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
        int64_t next;
        bool _match_4766 = 0 > i; /*bool*/;
        if (_match_4766) {
          int64_t _x4947 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i + (uint64_t)_x4947); /*int64*/
        }
        else {
          int64_t _x4948 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i - (uint64_t)_x4948); /*int64*/
        }
        return kk_std_num_float64_float64_from_bits(next, _ctx);
      }
    }
  }
}
 
// Returns the least `:float64` greater than `x`.
// This behaves exactly as `nextUp` in the IEEE 754-2008 standard.
// The identity `x.next-up == ~next-down(~x)` holds for all `x`.
// When `x` is finite `x == x.next-up.next-down` also holds.

double kk_std_num_float64_next_up(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  bool _match_4759 = isnan(x); /*bool*/;
  if (_match_4759) {
    return x;
  }
  {
    bool _match_4760 = (isinf(x) && !signbit(x)); /*bool*/;
    if (_match_4760) {
      return x;
    }
    {
      bool _match_4761 = (x == (0.0)); /*bool*/;
      if (_match_4761) {
        return 5.0e-324;
      }
      {
        int64_t i = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
        int64_t next;
        bool _match_4762 = 0 > i; /*bool*/;
        if (_match_4762) {
          int64_t _x4949 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i - (uint64_t)_x4949); /*int64*/
        }
        else {
          int64_t _x4950 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i + (uint64_t)_x4950); /*int64*/
        }
        return kk_std_num_float64_float64_from_bits(next, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4091_pdecdouble_fun4952__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4091_pdecdouble_fun4952(kk_function_t _fself, kk_box_t _b_4352, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4091_pdecdouble_fun4952(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4091_pdecdouble_fun4952, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4091_pdecdouble_fun4952(kk_function_t _fself, kk_box_t _b_4352, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x4953;
  kk_string_t _x4954 = kk_string_unbox(_b_4352); /*string*/
  _x4953 = kk_std_num_float64_prim_parse_float64(_x4954, _ctx); /*float64*/
  return kk_double_box(_x4953, _ctx);
}

double kk_std_num_float64__mlift4091_pdecdouble(kk_std_core__sslice cur, kk_integer_t exp, kk_context_t* _ctx) { /* (cur : sslice, exp : int) -> std/text/parse/parse float64 */ 
  kk_integer_drop(exp, _ctx);
  kk_string_t _x1_4085 = kk_std_core_string_3(cur, _ctx); /*string*/;
  kk_box_t _x4951 = kk_std_core_hnd__open_none1(kk_std_num_float64__new_mlift4091_pdecdouble_fun4952(_ctx), kk_string_box(_x1_4085), _ctx); /*3357*/
  return kk_double_unbox(_x4951, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4958__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4958(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4958(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4093_pdecdouble_fun4958, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4963__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4963(kk_function_t _fself, kk_box_t _b_4356, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4963(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4093_pdecdouble_fun4963, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4963(kk_function_t _fself, kk_box_t _b_4356, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x4964;
  kk_char_t _x4965 = kk_char_unbox(_b_4356, _ctx); /*char*/
  _x4964 = kk_std_num_float64__mlift4090_pdecdouble(_x4965, _ctx); /*int*/
  return kk_integer_box(_x4964);
}
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4958(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x0_4119;
  kk_string_t _x4959;
  kk_define_string_literal(, _s4960, 2, "eE")
  _x4959 = kk_string_dup(_s4960); /*string*/
  x0_4119 = kk_std_text_parse_one_of(_x4959, _ctx); /*char*/
  kk_integer_t _x4961;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4962 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4093_pdecdouble_fun4963(_ctx), _ctx); /*3926*/
    _x4961 = kk_integer_unbox(_x4962); /*int*/
  }
  else {
    _x4961 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x4961);
}


// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4966__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4966(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4966(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4093_pdecdouble_fun4966, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4966(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_integer_box(kk_integer_from_small(0));
}


// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4967__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static double kk_std_num_float64__mlift4093_pdecdouble_fun4967(kk_function_t _fself, kk_integer_t exp, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4967(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4093_pdecdouble_fun4967__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4093_pdecdouble_fun4967__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4093_pdecdouble_fun4967, kk_context());
  _self->cur = cur;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4969__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4969(kk_function_t _fself, kk_box_t _b_4364, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4969(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4093_pdecdouble_fun4969, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4969(kk_function_t _fself, kk_box_t _b_4364, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x4970;
  kk_string_t _x4971 = kk_string_unbox(_b_4364); /*string*/
  _x4970 = kk_std_num_float64_prim_parse_float64(_x4971, _ctx); /*float64*/
  return kk_double_box(_x4970, _ctx);
}
static double kk_std_num_float64__mlift4093_pdecdouble_fun4967(kk_function_t _fself, kk_integer_t exp, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4093_pdecdouble_fun4967__t* _self = kk_function_as(struct kk_std_num_float64__mlift4093_pdecdouble_fun4967__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  kk_integer_drop(exp, _ctx);
  kk_string_t _x1_4085 = kk_std_core_string_3(cur, _ctx); /*string*/;
  kk_box_t _x4968 = kk_std_core_hnd__open_none1(kk_std_num_float64__new_mlift4093_pdecdouble_fun4969(_ctx), kk_string_box(_x1_4085), _ctx); /*3357*/
  return kk_double_unbox(_x4968, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4093_pdecdouble_fun4973__t {
  struct kk_function_s _base;
  kk_function_t next_4118;
};
static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4973(kk_function_t _fself, kk_box_t _b_4368, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4093_pdecdouble_fun4973(kk_function_t next_4118, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4093_pdecdouble_fun4973__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4093_pdecdouble_fun4973__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4093_pdecdouble_fun4973, kk_context());
  _self->next_4118 = next_4118;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4093_pdecdouble_fun4973(kk_function_t _fself, kk_box_t _b_4368, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4093_pdecdouble_fun4973__t* _self = kk_function_as(struct kk_std_num_float64__mlift4093_pdecdouble_fun4973__t*, _fself);
  kk_function_t next_4118 = _self->next_4118; /* (int) -> std/text/parse/parse float64 */
  kk_drop_match(_self, {kk_function_dup(next_4118);}, {}, _ctx)
  double _x4974;
  kk_integer_t _x4975 = kk_integer_unbox(_b_4368); /*int*/
  _x4974 = kk_function_call(double, (kk_function_t, kk_integer_t, kk_context_t*), next_4118, (next_4118, _x4975, _ctx)); /*float64*/
  return kk_double_box(_x4974, _ctx);
}

double kk_std_num_float64__mlift4093_pdecdouble(kk_std_core__sslice cur, kk_string_t _y_4054, kk_context_t* _ctx) { /* (cur : sslice, string) -> std/text/parse/parse float64 */ 
  kk_string_t frac;
  kk_string_t _x4955;
  kk_define_string_literal(, _s4956, 1, "0")
  _x4955 = kk_string_dup(_s4956); /*string*/
  frac = kk_std_core_trim_right_1(_y_4054, _x4955, _ctx); /*string*/
  kk_string_drop(frac, _ctx);
  kk_integer_t x_4117;
  kk_box_t _x4957 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64__new_mlift4093_pdecdouble_fun4958(_ctx), kk_std_num_float64__new_mlift4093_pdecdouble_fun4966(_ctx), _ctx); /*944*/
  x_4117 = kk_integer_unbox(_x4957); /*int*/
  kk_function_t next_4118 = kk_std_num_float64__new_mlift4093_pdecdouble_fun4967(cur, _ctx); /*(int) -> std/text/parse/parse float64*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_4117, _ctx);
    kk_box_t _x4972 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4093_pdecdouble_fun4973(next_4118, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x4972, _ctx);
  }
  {
    return kk_function_call(double, (kk_function_t, kk_integer_t, kk_context_t*), next_4118, (next_4118, x_4117, _ctx));
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4094_pdecdouble_fun4977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4977(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4094_pdecdouble_fun4977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4094_pdecdouble_fun4977, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4094_pdecdouble_fun4980__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4980(kk_function_t _fself, kk_box_t _b_4371, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4094_pdecdouble_fun4980(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4094_pdecdouble_fun4980, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4980(kk_function_t _fself, kk_box_t _b_4371, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x4981;
  kk_char_t _x4982 = kk_char_unbox(_b_4371, _ctx); /*char*/
  _x4981 = kk_std_num_float64__mlift4092_pdecdouble(_x4982, _ctx); /*string*/
  return kk_string_box(_x4981);
}
static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4977(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x0_4125 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x4978;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4979 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4094_pdecdouble_fun4980(_ctx), _ctx); /*3926*/
    _x4978 = kk_string_unbox(_x4979); /*string*/
  }
  else {
    _x4978 = kk_std_text_parse_digits0(_ctx); /*string*/
  }
  return kk_string_box(_x4978);
}


// lift anonymous function
struct kk_std_num_float64__mlift4094_pdecdouble_fun4983__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4983(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4094_pdecdouble_fun4983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4094_pdecdouble_fun4983, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4983(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x4984 = kk_string_empty(); /*string*/
  return kk_string_box(_x4984);
}


// lift anonymous function
struct kk_std_num_float64__mlift4094_pdecdouble_fun4987__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4987(kk_function_t _fself, kk_box_t _b_4378, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4094_pdecdouble_fun4987(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4094_pdecdouble_fun4987__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4094_pdecdouble_fun4987__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4094_pdecdouble_fun4987, kk_context());
  _self->cur = cur;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4094_pdecdouble_fun4987(kk_function_t _fself, kk_box_t _b_4378, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4094_pdecdouble_fun4987__t* _self = kk_function_as(struct kk_std_num_float64__mlift4094_pdecdouble_fun4987__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  kk_string_t _y_4380_4054 = kk_string_unbox(_b_4378); /*string*/;
  double _x4988 = kk_std_num_float64__mlift4093_pdecdouble(cur, _y_4380_4054, _ctx); /*float64*/
  return kk_double_box(_x4988, _ctx);
}

double kk_std_num_float64__mlift4094_pdecdouble(kk_std_core__sslice cur, kk_string_t man, kk_context_t* _ctx) { /* (cur : sslice, man : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(man, _ctx);
  kk_string_t x_4123;
  kk_box_t _x4976 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64__new_mlift4094_pdecdouble_fun4977(_ctx), kk_std_num_float64__new_mlift4094_pdecdouble_fun4983(_ctx), _ctx); /*944*/
  x_4123 = kk_string_unbox(_x4976); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4123, _ctx);
    kk_box_t _x4986 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4094_pdecdouble_fun4987(cur, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x4986, _ctx);
  }
  {
    return kk_std_num_float64__mlift4093_pdecdouble(cur, x_4123, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4095_pdecdouble_fun4990__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift4095_pdecdouble_fun4990(kk_function_t _fself, kk_box_t _b_4382, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4095_pdecdouble_fun4990(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4095_pdecdouble_fun4990__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4095_pdecdouble_fun4990__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4095_pdecdouble_fun4990, kk_context());
  _self->cur = cur;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4095_pdecdouble_fun4990(kk_function_t _fself, kk_box_t _b_4382, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4095_pdecdouble_fun4990__t* _self = kk_function_as(struct kk_std_num_float64__mlift4095_pdecdouble_fun4990__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  kk_string_t man_4384 = kk_string_unbox(_b_4382); /*string*/;
  double _x4991 = kk_std_num_float64__mlift4094_pdecdouble(cur, man_4384, _ctx); /*float64*/
  return kk_double_box(_x4991, _ctx);
}

double kk_std_num_float64__mlift4095_pdecdouble(kk_std_core__sslice cur, kk_context_t* _ctx) { /* (cur : sslice) -> std/text/parse/parse float64 */ 
  kk_string_t x_4127 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4127, _ctx);
    kk_box_t _x4989 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4095_pdecdouble_fun4990(cur, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x4989, _ctx);
  }
  {
    return kk_std_num_float64__mlift4094_pdecdouble(cur, x_4127, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun4997__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun4997(kk_function_t _fself, kk_box_t _b_4392, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun4997(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun4997, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun4997(kk_function_t _fself, kk_box_t _b_4392, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x4998;
  kk_std_core__sslice _x4999 = kk_std_core__sslice_unbox(_b_4392, _ctx); /*sslice*/
  _x4998 = kk_std_num_float64__mlift4095_pdecdouble(_x4999, _ctx); /*float64*/
  return kk_double_box(_x4998, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5001__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_4129;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5001(kk_function_t _fself, kk_box_t _b_4394, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5001(kk_std_core__sslice x_4129, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5001__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun5001__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_pdecdouble_fun5001, kk_context());
  _self->x_4129 = x_4129;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5001(kk_function_t _fself, kk_box_t _b_4394, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5001__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun5001__t*, _fself);
  kk_std_core__sslice x_4129 = _self->x_4129; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_4129);}, {}, _ctx)
  kk_string_t man_4427 = kk_string_unbox(_b_4394); /*string*/;
  double _x5002 = kk_std_num_float64__mlift4094_pdecdouble(x_4129, man_4427, _ctx); /*float64*/
  return kk_double_box(_x5002, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5004__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5004(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5004(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5004, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5007__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5007(kk_function_t _fself, kk_box_t _b_4396, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5007(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5007, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5007(kk_function_t _fself, kk_box_t _b_4396, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5008;
  kk_char_t _x5009 = kk_char_unbox(_b_4396, _ctx); /*char*/
  _x5008 = kk_std_num_float64__mlift4092_pdecdouble(_x5009, _ctx); /*string*/
  return kk_string_box(_x5008);
}
static kk_box_t kk_std_num_float64_pdecdouble_fun5004(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x2_4140 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x5005;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5006 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun5007(_ctx), _ctx); /*3926*/
    _x5005 = kk_string_unbox(_x5006); /*string*/
  }
  else {
    _x5005 = kk_std_text_parse_digits0(_ctx); /*string*/
  }
  return kk_string_box(_x5005);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5010__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5010(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5010(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5010, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5010(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5011 = kk_string_empty(); /*string*/
  return kk_string_box(_x5011);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5014__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_4129;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5014(kk_function_t _fself, kk_box_t _b_4403, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5014(kk_std_core__sslice x_4129, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5014__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun5014__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_pdecdouble_fun5014, kk_context());
  _self->x_4129 = x_4129;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5014(kk_function_t _fself, kk_box_t _b_4403, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5014__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun5014__t*, _fself);
  kk_std_core__sslice x_4129 = _self->x_4129; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_4129);}, {}, _ctx)
  kk_string_t _y_4428_4054 = kk_string_unbox(_b_4403); /*string*/;
  double _x5015 = kk_std_num_float64__mlift4093_pdecdouble(x_4129, _y_4428_4054, _ctx); /*float64*/
  return kk_double_box(_x5015, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5019__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5019(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5019(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5019, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5024__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5024(kk_function_t _fself, kk_box_t _b_4405, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5024(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5024, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5024(kk_function_t _fself, kk_box_t _b_4405, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x5025;
  kk_char_t _x5026 = kk_char_unbox(_b_4405, _ctx); /*char*/
  _x5025 = kk_std_num_float64__mlift4090_pdecdouble(_x5026, _ctx); /*int*/
  return kk_integer_box(_x5025);
}
static kk_box_t kk_std_num_float64_pdecdouble_fun5019(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x4_4145;
  kk_string_t _x5020;
  kk_define_string_literal(, _s5021, 2, "eE")
  _x5020 = kk_string_dup(_s5021); /*string*/
  x4_4145 = kk_std_text_parse_one_of(_x5020, _ctx); /*char*/
  kk_integer_t _x5022;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5023 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun5024(_ctx), _ctx); /*3926*/
    _x5022 = kk_integer_unbox(_x5023); /*int*/
  }
  else {
    _x5022 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x5022);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5027__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5027(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5027(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5027, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5027(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_integer_box(kk_integer_from_small(0));
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5029__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_4129;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5029(kk_function_t _fself, kk_box_t _b_4415, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5029(kk_std_core__sslice x_4129, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5029__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun5029__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_pdecdouble_fun5029, kk_context());
  _self->x_4129 = x_4129;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5030__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5030(kk_function_t _fself, kk_box_t _b_4413, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5030(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5030, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5030(kk_function_t _fself, kk_box_t _b_4413, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5031;
  kk_string_t _x5032 = kk_string_unbox(_b_4413); /*string*/
  _x5031 = kk_std_num_float64_prim_parse_float64(_x5032, _ctx); /*float64*/
  return kk_double_box(_x5031, _ctx);
}
static kk_box_t kk_std_num_float64_pdecdouble_fun5029(kk_function_t _fself, kk_box_t _b_4415, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun5029__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun5029__t*, _fself);
  kk_std_core__sslice x_4129 = _self->x_4129; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_4129);}, {}, _ctx)
  kk_integer_t exp_4429 = kk_integer_unbox(_b_4415); /*int*/;
  kk_integer_drop(exp_4429, _ctx);
  kk_string_t _x1_4085 = kk_std_core_string_3(x_4129, _ctx); /*string*/;
  return kk_std_core_hnd__open_none1(kk_std_num_float64_new_pdecdouble_fun5030(_ctx), kk_string_box(_x1_4085), _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun5034__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun5034(kk_function_t _fself, kk_box_t _b_4418, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun5034(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun5034, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdecdouble_fun5034(kk_function_t _fself, kk_box_t _b_4418, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5035;
  kk_string_t _x5036 = kk_string_unbox(_b_4418); /*string*/
  _x5035 = kk_std_num_float64_prim_parse_float64(_x5036, _ctx); /*float64*/
  return kk_double_box(_x5035, _ctx);
}

double kk_std_num_float64_pdecdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_std_core_hnd__ev ev_4132;
  kk_ssize_t _x4992 = (KK_IZ(0)); /*ssize_t*/
  ev_4132 = kk_evv_at(_x4992,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_std_core__sslice x_4129;
  kk_box_t _x4993;
  {
    struct kk_std_core_hnd_Ev* _con4994 = kk_std_core_hnd__as_Ev(ev_4132);
    kk_std_core_hnd__marker m0 = _con4994->marker;
    kk_box_t _box_x4385 = _con4994->hnd;
    kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4385, NULL);
    kk_std_text_parse__hnd_parse_dup(h);
    kk_std_core_hnd__clause0 _match_4752;
    kk_std_core_hnd__clause0 _brw_4753 = kk_std_text_parse__select_current_input(h, _ctx); /*std/core/hnd/clause0<sslice,std/text/parse/.hnd-parse,373,374>*/;
    kk_std_text_parse__hnd_parse_drop(h, _ctx);
    _match_4752 = _brw_4753; /*std/core/hnd/clause0<sslice,std/text/parse/.hnd-parse,373,374>*/
    {
      kk_function_t _fun_unbox_x4388 = _match_4752.clause;
      _x4993 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x4388, (_fun_unbox_x4388, m0, ev_4132, _ctx)); /*37*/
    }
  }
  x_4129 = kk_std_core__sslice_unbox(_x4993, _ctx); /*sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x_4129, _ctx);
    kk_box_t _x4996 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun4997(_ctx), _ctx); /*3926*/
    return kk_double_unbox(_x4996, _ctx);
  }
  {
    kk_string_t x0_4134 = kk_std_text_parse_digits(_ctx); /*string*/;
    kk_string_drop(x0_4134, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x5000 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun5001(x_4129, _ctx), _ctx); /*3926*/
      return kk_double_unbox(_x5000, _ctx);
    }
    {
      kk_string_t x1_4137;
      kk_box_t _x5003 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64_new_pdecdouble_fun5004(_ctx), kk_std_num_float64_new_pdecdouble_fun5010(_ctx), _ctx); /*944*/
      x1_4137 = kk_string_unbox(_x5003); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x1_4137, _ctx);
        kk_box_t _x5013 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun5014(x_4129, _ctx), _ctx); /*3926*/
        return kk_double_unbox(_x5013, _ctx);
      }
      {
        kk_string_t frac;
        kk_string_t _x5016;
        kk_define_string_literal(, _s5017, 1, "0")
        _x5016 = kk_string_dup(_s5017); /*string*/
        frac = kk_std_core_trim_right_1(x1_4137, _x5016, _ctx); /*string*/
        kk_string_drop(frac, _ctx);
        kk_integer_t x3_4142;
        kk_box_t _x5018 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64_new_pdecdouble_fun5019(_ctx), kk_std_num_float64_new_pdecdouble_fun5027(_ctx), _ctx); /*944*/
        x3_4142 = kk_integer_unbox(_x5018); /*int*/
        kk_integer_drop(x3_4142, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x5028 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun5029(x_4129, _ctx), _ctx); /*3926*/
          return kk_double_unbox(_x5028, _ctx);
        }
        {
          kk_string_t _x1_40850 = kk_std_core_string_3(x_4129, _ctx); /*string*/;
          kk_box_t _x5033 = kk_std_core_hnd__open_none1(kk_std_num_float64_new_pdecdouble_fun5034(_ctx), kk_string_box(_x1_40850), _ctx); /*3357*/
          return kk_double_unbox(_x5033, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4097_phexdouble_fun5039__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4097_phexdouble_fun5039(kk_function_t _fself, kk_box_t _b_4435, kk_box_t _b_4436, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4097_phexdouble_fun5039(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4097_phexdouble_fun5039, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4097_phexdouble_fun5039(kk_function_t _fself, kk_box_t _b_4435, kk_box_t _b_4436, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe _x5040;
  kk_string_t _x5041;
  kk_string_t _x5042;
  kk_string_t _x5043 = kk_string_unbox(_b_4435); /*string*/
  _x5042 = kk_string_trim_left(_x5043,kk_context()); /*string*/
  _x5041 = kk_string_trim_right(_x5042,kk_context()); /*string*/
  bool _x5044;
  kk_std_core_types__optional _match_4745 = kk_std_core_types__optional_unbox(_b_4436, _ctx); /*optional<bool>*/;
  if (kk_std_core_types__is_Optional(_match_4745)) {
    kk_box_t _box_x4430 = _match_4745._cons.Optional.value;
    bool _hex_15544 = kk_bool_unbox(_box_x4430);
    _x5044 = _hex_15544; /*bool*/
  }
  else {
    _x5044 = false; /*bool*/
  }
  _x5040 = kk_std_core_xparse_int(_x5041, _x5044, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x5040, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4097_phexdouble_fun5051__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4097_phexdouble_fun5051(kk_function_t _fself, kk_box_t _b_4450, kk_box_t _b_4451, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4097_phexdouble_fun5051(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4097_phexdouble_fun5051, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4097_phexdouble_fun5051(kk_function_t _fself, kk_box_t _b_4450, kk_box_t _b_4451, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t man0_4455 = kk_integer_unbox(_b_4450); /*int*/;
  kk_integer_t exp0_4456 = kk_integer_unbox(_b_4451); /*int*/;
  double _x5052;
  double _x5053 = kk_integer_as_double(man0_4455,kk_context()); /*float64*/
  _x5052 = kk_std_num_float64_ldexp(_x5053, exp0_4456, _ctx); /*float64*/
  return kk_double_box(_x5052, _ctx);
}

double kk_std_num_float64__mlift4097_phexdouble(kk_string_t frac, kk_string_t man, kk_integer_t exp, kk_context_t* _ctx) { /* (frac : string, man : string, exp : int) -> std/text/parse/parse float64 */ 
  kk_string_t _x1_4086;
  kk_string_t _x5037 = kk_string_dup(frac); /*string*/
  _x1_4086 = kk_std_core__lp__plus__plus__1_rp_(man, _x5037, _ctx); /*string*/
  kk_std_core_types__maybe _b_4439_4437;
  kk_box_t _x5038;
  kk_box_t _x5046;
  kk_std_core_types__optional _x5047 = kk_std_core_types__new_Optional(kk_bool_box(true), _ctx); /*optional<112>*/
  _x5046 = kk_std_core_types__optional_box(_x5047, _ctx); /*3448*/
  _x5038 = kk_std_core_hnd__open_none2(kk_std_num_float64__new_mlift4097_phexdouble_fun5039(_ctx), kk_string_box(_x1_4086), _x5046, _ctx); /*3449*/
  _b_4439_4437 = kk_std_core_types__maybe_unbox(_x5038, _ctx); /*maybe<int>*/
  kk_integer_t m;
  kk_box_t _x5048 = kk_std_core_default(_b_4439_4437, kk_integer_box(kk_integer_from_small(0)), _ctx); /*2349*/
  m = kk_integer_unbox(_x5048); /*int*/
  kk_integer_t y_4083;
  kk_integer_t _x5049 = kk_std_core_count_1(frac, _ctx); /*int*/
  y_4083 = kk_integer_mul((kk_integer_from_small(4)),_x5049,kk_context()); /*int*/
  kk_integer_t e = kk_integer_sub(exp,y_4083,kk_context()); /*int*/;
  kk_box_t _x5050 = kk_std_core_hnd__open_none2(kk_std_num_float64__new_mlift4097_phexdouble_fun5051(_ctx), kk_integer_box(m), kk_integer_box(e), _ctx); /*3449*/
  return kk_double_unbox(_x5050, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4099_phexdouble_fun5057__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5057(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4099_phexdouble_fun5057(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4099_phexdouble_fun5057, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4099_phexdouble_fun5062__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5062(kk_function_t _fself, kk_box_t _b_4458, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4099_phexdouble_fun5062(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4099_phexdouble_fun5062, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5062(kk_function_t _fself, kk_box_t _b_4458, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x5063;
  kk_char_t _x5064 = kk_char_unbox(_b_4458, _ctx); /*char*/
  _x5063 = kk_std_num_float64__mlift4096_phexdouble(_x5064, _ctx); /*int*/
  return kk_integer_box(_x5063);
}
static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5057(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x0_4151;
  kk_string_t _x5058;
  kk_define_string_literal(, _s5059, 2, "pP")
  _x5058 = kk_string_dup(_s5059); /*string*/
  x0_4151 = kk_std_text_parse_one_of(_x5058, _ctx); /*char*/
  kk_integer_t _x5060;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5061 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4099_phexdouble_fun5062(_ctx), _ctx); /*3926*/
    _x5060 = kk_integer_unbox(_x5061); /*int*/
  }
  else {
    _x5060 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x5060);
}


// lift anonymous function
struct kk_std_num_float64__mlift4099_phexdouble_fun5065__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5065(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4099_phexdouble_fun5065(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4099_phexdouble_fun5065, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5065(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_integer_box(kk_integer_from_small(0));
}


// lift anonymous function
struct kk_std_num_float64__mlift4099_phexdouble_fun5067__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5067(kk_function_t _fself, kk_box_t _b_4465, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4099_phexdouble_fun5067(kk_string_t frac, kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4099_phexdouble_fun5067__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4099_phexdouble_fun5067__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4099_phexdouble_fun5067, kk_context());
  _self->frac = frac;
  _self->man = man;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4099_phexdouble_fun5067(kk_function_t _fself, kk_box_t _b_4465, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4099_phexdouble_fun5067__t* _self = kk_function_as(struct kk_std_num_float64__mlift4099_phexdouble_fun5067__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(man);}, {}, _ctx)
  kk_integer_t exp_4467 = kk_integer_unbox(_b_4465); /*int*/;
  double _x5068 = kk_std_num_float64__mlift4097_phexdouble(frac, man, exp_4467, _ctx); /*float64*/
  return kk_double_box(_x5068, _ctx);
}

double kk_std_num_float64__mlift4099_phexdouble(kk_string_t man, kk_string_t _y_4063, kk_context_t* _ctx) { /* (man : string, string) -> std/text/parse/parse float64 */ 
  kk_string_t frac;
  kk_string_t _x5054;
  kk_define_string_literal(, _s5055, 1, "0")
  _x5054 = kk_string_dup(_s5055); /*string*/
  frac = kk_std_core_trim_right_1(_y_4063, _x5054, _ctx); /*string*/
  kk_integer_t x_4149;
  kk_box_t _x5056 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64__new_mlift4099_phexdouble_fun5057(_ctx), kk_std_num_float64__new_mlift4099_phexdouble_fun5065(_ctx), _ctx); /*944*/
  x_4149 = kk_integer_unbox(_x5056); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_4149, _ctx);
    kk_box_t _x5066 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4099_phexdouble_fun5067(frac, man, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5066, _ctx);
  }
  {
    return kk_std_num_float64__mlift4097_phexdouble(frac, man, x_4149, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4100_phexdouble_fun5070__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5070(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4100_phexdouble_fun5070(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4100_phexdouble_fun5070, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4100_phexdouble_fun5073__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5073(kk_function_t _fself, kk_box_t _b_4469, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4100_phexdouble_fun5073(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4100_phexdouble_fun5073, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5073(kk_function_t _fself, kk_box_t _b_4469, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5074;
  kk_char_t _x5075 = kk_char_unbox(_b_4469, _ctx); /*char*/
  _x5074 = kk_std_num_float64__mlift4098_phexdouble(_x5075, _ctx); /*string*/
  return kk_string_box(_x5074);
}
static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5070(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x0_4155 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x5071;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5072 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4100_phexdouble_fun5073(_ctx), _ctx); /*3926*/
    _x5071 = kk_string_unbox(_x5072); /*string*/
  }
  else {
    _x5071 = kk_std_text_parse_hex_digits(_ctx); /*string*/
  }
  return kk_string_box(_x5071);
}


// lift anonymous function
struct kk_std_num_float64__mlift4100_phexdouble_fun5076__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5076(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4100_phexdouble_fun5076(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4100_phexdouble_fun5076, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5076(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5077 = kk_string_empty(); /*string*/
  return kk_string_box(_x5077);
}


// lift anonymous function
struct kk_std_num_float64__mlift4100_phexdouble_fun5080__t {
  struct kk_function_s _base;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5080(kk_function_t _fself, kk_box_t _b_4476, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4100_phexdouble_fun5080(kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4100_phexdouble_fun5080__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4100_phexdouble_fun5080__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4100_phexdouble_fun5080, kk_context());
  _self->man = man;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4100_phexdouble_fun5080(kk_function_t _fself, kk_box_t _b_4476, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4100_phexdouble_fun5080__t* _self = kk_function_as(struct kk_std_num_float64__mlift4100_phexdouble_fun5080__t*, _fself);
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(man);}, {}, _ctx)
  kk_string_t _y_4478_4063 = kk_string_unbox(_b_4476); /*string*/;
  double _x5081 = kk_std_num_float64__mlift4099_phexdouble(man, _y_4478_4063, _ctx); /*float64*/
  return kk_double_box(_x5081, _ctx);
}

double kk_std_num_float64__mlift4100_phexdouble(kk_string_t man, kk_context_t* _ctx) { /* (man : string) -> std/text/parse/parse float64 */ 
  kk_string_t x_4153;
  kk_box_t _x5069 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64__new_mlift4100_phexdouble_fun5070(_ctx), kk_std_num_float64__new_mlift4100_phexdouble_fun5076(_ctx), _ctx); /*944*/
  x_4153 = kk_string_unbox(_x5069); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4153, _ctx);
    kk_box_t _x5079 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4100_phexdouble_fun5080(man, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5079, _ctx);
  }
  {
    return kk_std_num_float64__mlift4099_phexdouble(man, x_4153, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4101_phexdouble_fun5083__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4101_phexdouble_fun5083(kk_function_t _fself, kk_box_t _b_4480, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4101_phexdouble_fun5083(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4101_phexdouble_fun5083, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4101_phexdouble_fun5083(kk_function_t _fself, kk_box_t _b_4480, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5084;
  kk_string_t _x5085 = kk_string_unbox(_b_4480); /*string*/
  _x5084 = kk_std_num_float64__mlift4100_phexdouble(_x5085, _ctx); /*float64*/
  return kk_double_box(_x5084, _ctx);
}

double kk_std_num_float64__mlift4101_phexdouble(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse float64 */ 
  kk_string_t x_4157 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4157, _ctx);
    kk_box_t _x5082 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4101_phexdouble_fun5083(_ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5082, _ctx);
  }
  {
    return kk_std_num_float64__mlift4100_phexdouble(x_4157, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4102_phexdouble_fun5089__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4102_phexdouble_fun5089(kk_function_t _fself, kk_box_t _b_4483, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4102_phexdouble_fun5089(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4102_phexdouble_fun5089, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4102_phexdouble_fun5089(kk_function_t _fself, kk_box_t _b_4483, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5090;
  kk_char_t _x5091 = kk_char_unbox(_b_4483, _ctx); /*char*/
  _x5090 = kk_std_num_float64__mlift4101_phexdouble(_x5091, _ctx); /*float64*/
  return kk_double_box(_x5090, _ctx);
}

double kk_std_num_float64__mlift4102_phexdouble(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse float64 */ 
  kk_char_t x_4159;
  kk_string_t _x5086;
  kk_define_string_literal(, _s5087, 2, "xX")
  _x5086 = kk_string_dup(_s5087); /*string*/
  x_4159 = kk_std_text_parse_one_of(_x5086, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x5088 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4102_phexdouble_fun5089(_ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5088, _ctx);
  }
  {
    return kk_std_num_float64__mlift4101_phexdouble(x_4159, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5093__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5093(kk_function_t _fself, kk_box_t _b_4486, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5093(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5093, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5093(kk_function_t _fself, kk_box_t _b_4486, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5094;
  kk_char_t _x5095 = kk_char_unbox(_b_4486, _ctx); /*char*/
  _x5094 = kk_std_num_float64__mlift4102_phexdouble(_x5095, _ctx); /*float64*/
  return kk_double_box(_x5094, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5099__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5099(kk_function_t _fself, kk_box_t _b_4488, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5099(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5099, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5099(kk_function_t _fself, kk_box_t _b_4488, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5100;
  kk_char_t _x5101 = kk_char_unbox(_b_4488, _ctx); /*char*/
  _x5100 = kk_std_num_float64__mlift4101_phexdouble(_x5101, _ctx); /*float64*/
  return kk_double_box(_x5100, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5103__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5103(kk_function_t _fself, kk_box_t _b_4490, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5103(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5103, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5103(kk_function_t _fself, kk_box_t _b_4490, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5104;
  kk_string_t _x5105 = kk_string_unbox(_b_4490); /*string*/
  _x5104 = kk_std_num_float64__mlift4100_phexdouble(_x5105, _ctx); /*float64*/
  return kk_double_box(_x5104, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5107__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5107(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5107(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5107, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5110__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5110(kk_function_t _fself, kk_box_t _b_4492, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5110(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5110, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5110(kk_function_t _fself, kk_box_t _b_4492, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5111;
  kk_char_t _x5112 = kk_char_unbox(_b_4492, _ctx); /*char*/
  _x5111 = kk_std_num_float64__mlift4098_phexdouble(_x5112, _ctx); /*string*/
  return kk_string_box(_x5111);
}
static kk_box_t kk_std_num_float64_phexdouble_fun5107(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x3_4173 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x5108;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5109 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5110(_ctx), _ctx); /*3926*/
    _x5108 = kk_string_unbox(_x5109); /*string*/
  }
  else {
    _x5108 = kk_std_text_parse_hex_digits(_ctx); /*string*/
  }
  return kk_string_box(_x5108);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5113__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5113(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5113(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5113, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5113(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x5114 = kk_string_empty(); /*string*/
  return kk_string_box(_x5114);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5117__t {
  struct kk_function_s _base;
  kk_string_t x1_4167;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5117(kk_function_t _fself, kk_box_t _b_4499, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5117(kk_string_t x1_4167, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun5117__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun5117__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_phexdouble_fun5117, kk_context());
  _self->x1_4167 = x1_4167;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_phexdouble_fun5117(kk_function_t _fself, kk_box_t _b_4499, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun5117__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun5117__t*, _fself);
  kk_string_t x1_4167 = _self->x1_4167; /* string */
  kk_drop_match(_self, {kk_string_dup(x1_4167);}, {}, _ctx)
  kk_string_t _y_4539_4063 = kk_string_unbox(_b_4499); /*string*/;
  double _x5118 = kk_std_num_float64__mlift4099_phexdouble(x1_4167, _y_4539_4063, _ctx); /*float64*/
  return kk_double_box(_x5118, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5122__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5122(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5122(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5122, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5127__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5127(kk_function_t _fself, kk_box_t _b_4501, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5127(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5127, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5127(kk_function_t _fself, kk_box_t _b_4501, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x5128;
  kk_char_t _x5129 = kk_char_unbox(_b_4501, _ctx); /*char*/
  _x5128 = kk_std_num_float64__mlift4096_phexdouble(_x5129, _ctx); /*int*/
  return kk_integer_box(_x5128);
}
static kk_box_t kk_std_num_float64_phexdouble_fun5122(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t x5_4178;
  kk_string_t _x5123;
  kk_define_string_literal(, _s5124, 2, "pP")
  _x5123 = kk_string_dup(_s5124); /*string*/
  x5_4178 = kk_std_text_parse_one_of(_x5123, _ctx); /*char*/
  kk_integer_t _x5125;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5126 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5127(_ctx), _ctx); /*3926*/
    _x5125 = kk_integer_unbox(_x5126); /*int*/
  }
  else {
    _x5125 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x5125);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5130__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5130(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5130, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5130(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_integer_box(kk_integer_from_small(0));
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5132__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x1_4167;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5132(kk_function_t _fself, kk_box_t _b_4508, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5132(kk_string_t frac, kk_string_t x1_4167, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun5132__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun5132__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_phexdouble_fun5132, kk_context());
  _self->frac = frac;
  _self->x1_4167 = x1_4167;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_phexdouble_fun5132(kk_function_t _fself, kk_box_t _b_4508, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun5132__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun5132__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x1_4167 = _self->x1_4167; /* string */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(x1_4167);}, {}, _ctx)
  kk_integer_t exp_4540 = kk_integer_unbox(_b_4508); /*int*/;
  double _x5133 = kk_std_num_float64__mlift4097_phexdouble(frac, x1_4167, exp_4540, _ctx); /*float64*/
  return kk_double_box(_x5133, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5136__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5136(kk_function_t _fself, kk_box_t _b_4514, kk_box_t _b_4515, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5136(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5136, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5136(kk_function_t _fself, kk_box_t _b_4514, kk_box_t _b_4515, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe _x5137;
  kk_string_t _x5138;
  kk_string_t _x5139;
  kk_string_t _x5140 = kk_string_unbox(_b_4514); /*string*/
  _x5139 = kk_string_trim_left(_x5140,kk_context()); /*string*/
  _x5138 = kk_string_trim_right(_x5139,kk_context()); /*string*/
  bool _x5141;
  kk_std_core_types__optional _match_4736 = kk_std_core_types__optional_unbox(_b_4515, _ctx); /*optional<bool>*/;
  if (kk_std_core_types__is_Optional(_match_4736)) {
    kk_box_t _box_x4509 = _match_4736._cons.Optional.value;
    bool _hex_15544 = kk_bool_unbox(_box_x4509);
    _x5141 = _hex_15544; /*bool*/
  }
  else {
    _x5141 = false; /*bool*/
  }
  _x5137 = kk_std_core_xparse_int(_x5138, _x5141, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x5137, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun5148__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun5148(kk_function_t _fself, kk_box_t _b_4529, kk_box_t _b_4530, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun5148(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun5148, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_phexdouble_fun5148(kk_function_t _fself, kk_box_t _b_4529, kk_box_t _b_4530, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t man0_4541 = kk_integer_unbox(_b_4529); /*int*/;
  kk_integer_t exp00_4542 = kk_integer_unbox(_b_4530); /*int*/;
  double _x5149;
  double _x5150 = kk_integer_as_double(man0_4541,kk_context()); /*float64*/
  _x5149 = kk_std_num_float64_ldexp(_x5150, exp00_4542, _ctx); /*float64*/
  return kk_double_box(_x5149, _ctx);
}

double kk_std_num_float64_phexdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_char_t x_4161 = kk_std_text_parse_char('0', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5092 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5093(_ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5092, _ctx);
  }
  {
    kk_char_t x0_4164;
    kk_string_t _x5096;
    kk_define_string_literal(, _s5097, 2, "xX")
    _x5096 = kk_string_dup(_s5097); /*string*/
    x0_4164 = kk_std_text_parse_one_of(_x5096, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x5098 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5099(_ctx), _ctx); /*3926*/
      return kk_double_unbox(_x5098, _ctx);
    }
    {
      kk_string_t x1_4167 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x1_4167, _ctx);
        kk_box_t _x5102 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5103(_ctx), _ctx); /*3926*/
        return kk_double_unbox(_x5102, _ctx);
      }
      {
        kk_string_t x2_4170;
        kk_box_t _x5106 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64_new_phexdouble_fun5107(_ctx), kk_std_num_float64_new_phexdouble_fun5113(_ctx), _ctx); /*944*/
        x2_4170 = kk_string_unbox(_x5106); /*string*/
        if (kk_yielding(kk_context())) {
          kk_string_drop(x2_4170, _ctx);
          kk_box_t _x5116 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5117(x1_4167, _ctx), _ctx); /*3926*/
          return kk_double_unbox(_x5116, _ctx);
        }
        {
          kk_string_t frac;
          kk_string_t _x5119;
          kk_define_string_literal(, _s5120, 1, "0")
          _x5119 = kk_string_dup(_s5120); /*string*/
          frac = kk_std_core_trim_right_1(x2_4170, _x5119, _ctx); /*string*/
          kk_integer_t x4_4175;
          kk_box_t _x5121 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_float64_new_phexdouble_fun5122(_ctx), kk_std_num_float64_new_phexdouble_fun5130(_ctx), _ctx); /*944*/
          x4_4175 = kk_integer_unbox(_x5121); /*int*/
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x4_4175, _ctx);
            kk_box_t _x5131 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun5132(frac, x1_4167, _ctx), _ctx); /*3926*/
            return kk_double_unbox(_x5131, _ctx);
          }
          {
            kk_string_t _x1_4086;
            kk_string_t _x5134 = kk_string_dup(frac); /*string*/
            _x1_4086 = kk_std_core__lp__plus__plus__1_rp_(x1_4167, _x5134, _ctx); /*string*/
            kk_std_core_types__maybe _b_4518_4516;
            kk_box_t _x5135;
            kk_box_t _x5143;
            kk_std_core_types__optional _x5144 = kk_std_core_types__new_Optional(kk_bool_box(true), _ctx); /*optional<112>*/
            _x5143 = kk_std_core_types__optional_box(_x5144, _ctx); /*3448*/
            _x5135 = kk_std_core_hnd__open_none2(kk_std_num_float64_new_phexdouble_fun5136(_ctx), kk_string_box(_x1_4086), _x5143, _ctx); /*3449*/
            _b_4518_4516 = kk_std_core_types__maybe_unbox(_x5135, _ctx); /*maybe<int>*/
            kk_integer_t m;
            kk_box_t _x5145 = kk_std_core_default(_b_4518_4516, kk_integer_box(kk_integer_from_small(0)), _ctx); /*2349*/
            m = kk_integer_unbox(_x5145); /*int*/
            kk_integer_t y_4083;
            kk_integer_t _x5146 = kk_std_core_count_1(frac, _ctx); /*int*/
            y_4083 = kk_integer_mul((kk_integer_from_small(4)),_x5146,kk_context()); /*int*/
            kk_integer_t e = kk_integer_sub(x4_4175,y_4083,kk_context()); /*int*/;
            kk_box_t _x5147 = kk_std_core_hnd__open_none2(kk_std_num_float64_new_phexdouble_fun5148(_ctx), kk_integer_box(m), kk_integer_box(e), _ctx); /*3449*/
            return kk_double_unbox(_x5147, _ctx);
          }
        }
      }
    }
  }
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun5153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5153(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5153, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun5158__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5158(kk_function_t _fself, kk_box_t _b_4544, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5158(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5158, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pspecial_fun5158(kk_function_t _fself, kk_box_t _b_4544, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5159;
  kk_string_t _x5160 = kk_string_unbox(_b_4544); /*string*/
  _x5159 = kk_std_num_float64__mlift4103_pspecial(_x5160, _ctx); /*float64*/
  return kk_double_box(_x5159, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun5153(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x_4180;
  kk_string_t _x5154;
  kk_define_string_literal(, _s5155, 3, "nan")
  _x5154 = kk_string_dup(_s5155); /*string*/
  x_4180 = kk_std_text_parse_pstring(_x5154, _ctx); /*string*/
  kk_string_drop(x_4180, _ctx);
  double _x5156;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5157 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun5158(_ctx), _ctx); /*3926*/
    _x5156 = kk_double_unbox(_x5157, _ctx); /*float64*/
  }
  else {
    _x5156 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x5156, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun5162__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5162(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5162(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5162, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun5167__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5167(kk_function_t _fself, kk_box_t _b_4546, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5167(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5167, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pspecial_fun5167(kk_function_t _fself, kk_box_t _b_4546, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5168;
  kk_string_t _x5169 = kk_string_unbox(_b_4546); /*string*/
  _x5168 = kk_std_num_float64__mlift4104_pspecial(_x5169, _ctx); /*float64*/
  return kk_double_box(_x5168, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun5162(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x0_4182;
  kk_string_t _x5163;
  kk_define_string_literal(, _s5164, 8, "infinity")
  _x5163 = kk_string_dup(_s5164); /*string*/
  x0_4182 = kk_std_text_parse_pstring(_x5163, _ctx); /*string*/
  kk_string_drop(x0_4182, _ctx);
  double _x5165;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5166 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun5167(_ctx), _ctx); /*3926*/
    _x5165 = kk_double_unbox(_x5166, _ctx); /*float64*/
  }
  else {
    _x5165 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5165, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun5171__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5171(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5171(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5171, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun5176__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun5176(kk_function_t _fself, kk_box_t _b_4548, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun5176(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun5176, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pspecial_fun5176(kk_function_t _fself, kk_box_t _b_4548, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5177;
  kk_string_t _x5178 = kk_string_unbox(_b_4548); /*string*/
  _x5177 = kk_std_num_float64__mlift4105_pspecial(_x5178, _ctx); /*float64*/
  return kk_double_box(_x5177, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun5171(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x1_4184;
  kk_string_t _x5172;
  kk_define_string_literal(, _s5173, 3, "inf")
  _x5172 = kk_string_dup(_s5173); /*string*/
  x1_4184 = kk_std_text_parse_pstring(_x5172, _ctx); /*string*/
  kk_string_drop(x1_4184, _ctx);
  double _x5174;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5175 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun5176(_ctx), _ctx); /*3926*/
    _x5174 = kk_double_unbox(_x5175, _ctx); /*float64*/
  }
  else {
    _x5174 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5174, _ctx);
}

double kk_std_num_float64_pspecial(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_box_t _x5151;
  kk_std_core__list _x5152;
  kk_std_core__list _x5161;
  kk_std_core__list _x5170 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pspecial_fun5171(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<61>*/
  _x5161 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pspecial_fun5162(_ctx)), _x5170, _ctx); /*list<61>*/
  _x5152 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pspecial_fun5153(_ctx)), _x5161, _ctx); /*list<61>*/
  _x5151 = kk_std_text_parse_choose(_x5152, _ctx); /*765*/
  return kk_double_unbox(_x5151, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5181__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5181(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5181(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5181, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5181(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5182 = kk_std_num_float64_phexdouble(_ctx); /*float64*/
  return kk_double_box(_x5182, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5184__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5184(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5184(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5184, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5184(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5185 = kk_std_num_float64_pdecdouble(_ctx); /*float64*/
  return kk_double_box(_x5185, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5187__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5187(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5187(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5187, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5189__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5189(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5189(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5189, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5194__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5194(kk_function_t _fself, kk_box_t _b_4570, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5194(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5194, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5194(kk_function_t _fself, kk_box_t _b_4570, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5195;
  kk_string_t _x5196 = kk_string_unbox(_b_4570); /*string*/
  _x5195 = kk_std_num_float64__mlift4106_pdouble(_x5196, _ctx); /*float64*/
  return kk_double_box(_x5195, _ctx);
}
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5189(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x0_4188;
  kk_string_t _x5190;
  kk_define_string_literal(, _s5191, 3, "nan")
  _x5190 = kk_string_dup(_s5191); /*string*/
  x0_4188 = kk_std_text_parse_pstring(_x5190, _ctx); /*string*/
  kk_string_drop(x0_4188, _ctx);
  double _x5192;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5193 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4110_pdouble_fun5194(_ctx), _ctx); /*3926*/
    _x5192 = kk_double_unbox(_x5193, _ctx); /*float64*/
  }
  else {
    _x5192 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x5192, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5198__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5198(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5198(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5198, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5203__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5203(kk_function_t _fself, kk_box_t _b_4572, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5203(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5203, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5203(kk_function_t _fself, kk_box_t _b_4572, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5204;
  kk_string_t _x5205 = kk_string_unbox(_b_4572); /*string*/
  _x5204 = kk_std_num_float64__mlift4107_pdouble(_x5205, _ctx); /*float64*/
  return kk_double_box(_x5204, _ctx);
}
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5198(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x1_4190;
  kk_string_t _x5199;
  kk_define_string_literal(, _s5200, 8, "infinity")
  _x5199 = kk_string_dup(_s5200); /*string*/
  x1_4190 = kk_std_text_parse_pstring(_x5199, _ctx); /*string*/
  kk_string_drop(x1_4190, _ctx);
  double _x5201;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5202 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4110_pdouble_fun5203(_ctx), _ctx); /*3926*/
    _x5201 = kk_double_unbox(_x5202, _ctx); /*float64*/
  }
  else {
    _x5201 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5201, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5207__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5207(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5207(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5207, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5212(kk_function_t _fself, kk_box_t _b_4574, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5212, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5212(kk_function_t _fself, kk_box_t _b_4574, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5213;
  kk_string_t _x5214 = kk_string_unbox(_b_4574); /*string*/
  _x5213 = kk_std_num_float64__mlift4108_pdouble(_x5214, _ctx); /*float64*/
  return kk_double_box(_x5213, _ctx);
}
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5207(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x2_4192;
  kk_string_t _x5208;
  kk_define_string_literal(, _s5209, 3, "inf")
  _x5208 = kk_string_dup(_s5209); /*string*/
  x2_4192 = kk_std_text_parse_pstring(_x5208, _ctx); /*string*/
  kk_string_drop(x2_4192, _ctx);
  double _x5210;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5211 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4110_pdouble_fun5212(_ctx), _ctx); /*3926*/
    _x5210 = kk_double_unbox(_x5211, _ctx); /*float64*/
  }
  else {
    _x5210 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5210, _ctx);
}
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5187(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core__list _x5188;
  kk_std_core__list _x5197;
  kk_std_core__list _x5206 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5207(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<61>*/
  _x5197 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5198(_ctx)), _x5206, _ctx); /*list<61>*/
  _x5188 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5189(_ctx)), _x5197, _ctx); /*list<61>*/
  return kk_std_text_parse_choose(_x5188, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5216__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5216(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5216(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift4110_pdouble_fun5216, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5216(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_double_box(0.0, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift4110_pdouble_fun5218__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5218(kk_function_t _fself, kk_box_t _b_4618, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4110_pdouble_fun5218(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4110_pdouble_fun5218__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4110_pdouble_fun5218__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4110_pdouble_fun5218, kk_context());
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4110_pdouble_fun5218(kk_function_t _fself, kk_box_t _b_4618, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4110_pdouble_fun5218__t* _self = kk_function_as(struct kk_std_num_float64__mlift4110_pdouble_fun5218__t*, _fself);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x5219;
  double d_4620 = kk_double_unbox(_b_4618, _ctx); /*float64*/;
  if (neg) {
    _x5219 = (-d_4620); /*float64*/
  }
  else {
    _x5219 = d_4620; /*float64*/
  }
  return kk_double_box(_x5219, _ctx);
}

double kk_std_num_float64__mlift4110_pdouble(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse float64 */ 
  double x_4186;
  kk_box_t _x5179;
  kk_std_core__list _x5180;
  kk_std_core__list _x5183;
  kk_std_core__list _x5186;
  kk_std_core__list _x5215 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5216(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<61>*/
  _x5186 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5187(_ctx)), _x5215, _ctx); /*list<61>*/
  _x5183 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5184(_ctx)), _x5186, _ctx); /*list<61>*/
  _x5180 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64__new_mlift4110_pdouble_fun5181(_ctx)), _x5183, _ctx); /*list<61>*/
  _x5179 = kk_std_text_parse_choose(_x5180, _ctx); /*765*/
  x_4186 = kk_double_unbox(_x5179, _ctx); /*float64*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x5217 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4110_pdouble_fun5218(neg, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5217, _ctx);
  }
  {
    double d_4621 = x_4186; /*float64*/;
    if (neg) {
      return (-d_4621);
    }
    {
      return d_4621;
    }
  }
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5221__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5221(kk_function_t _fself, kk_box_t _b_4623, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5221(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5221, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5221(kk_function_t _fself, kk_box_t _b_4623, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5222;
  bool _x5223 = kk_bool_unbox(_b_4623); /*bool*/
  _x5222 = kk_std_num_float64__mlift4110_pdouble(_x5223, _ctx); /*float64*/
  return kk_double_box(_x5222, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5226(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5226, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5226(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5227 = kk_std_num_float64_phexdouble(_ctx); /*float64*/
  return kk_double_box(_x5227, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5229__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5229(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5229(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5229, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5229(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5230 = kk_std_num_float64_pdecdouble(_ctx); /*float64*/
  return kk_double_box(_x5230, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5232__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5232(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5232(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5232, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun5234__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5234(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5234(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5234, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun5239__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5239(kk_function_t _fself, kk_box_t _b_4625, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5239(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5239, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5239(kk_function_t _fself, kk_box_t _b_4625, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5240;
  kk_string_t _x5241 = kk_string_unbox(_b_4625); /*string*/
  _x5240 = kk_std_num_float64__mlift4106_pdouble(_x5241, _ctx); /*float64*/
  return kk_double_box(_x5240, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun5234(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x1_4202;
  kk_string_t _x5235;
  kk_define_string_literal(, _s5236, 3, "nan")
  _x5235 = kk_string_dup(_s5236); /*string*/
  x1_4202 = kk_std_text_parse_pstring(_x5235, _ctx); /*string*/
  kk_string_drop(x1_4202, _ctx);
  double _x5237;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5238 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun5239(_ctx), _ctx); /*3926*/
    _x5237 = kk_double_unbox(_x5238, _ctx); /*float64*/
  }
  else {
    _x5237 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x5237, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5243__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5243(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5243(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5243, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun5248__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5248(kk_function_t _fself, kk_box_t _b_4627, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5248(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5248, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5248(kk_function_t _fself, kk_box_t _b_4627, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5249;
  kk_string_t _x5250 = kk_string_unbox(_b_4627); /*string*/
  _x5249 = kk_std_num_float64__mlift4107_pdouble(_x5250, _ctx); /*float64*/
  return kk_double_box(_x5249, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun5243(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x2_4204;
  kk_string_t _x5244;
  kk_define_string_literal(, _s5245, 8, "infinity")
  _x5244 = kk_string_dup(_s5245); /*string*/
  x2_4204 = kk_std_text_parse_pstring(_x5244, _ctx); /*string*/
  kk_string_drop(x2_4204, _ctx);
  double _x5246;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5247 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun5248(_ctx), _ctx); /*3926*/
    _x5246 = kk_double_unbox(_x5247, _ctx); /*float64*/
  }
  else {
    _x5246 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5246, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5252__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5252(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5252(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5252, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun5257__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5257(kk_function_t _fself, kk_box_t _b_4629, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5257(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5257, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5257(kk_function_t _fself, kk_box_t _b_4629, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5258;
  kk_string_t _x5259 = kk_string_unbox(_b_4629); /*string*/
  _x5258 = kk_std_num_float64__mlift4108_pdouble(_x5259, _ctx); /*float64*/
  return kk_double_box(_x5258, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun5252(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t x3_4206;
  kk_string_t _x5253;
  kk_define_string_literal(, _s5254, 3, "inf")
  _x5253 = kk_string_dup(_s5254); /*string*/
  x3_4206 = kk_std_text_parse_pstring(_x5253, _ctx); /*string*/
  kk_string_drop(x3_4206, _ctx);
  double _x5255;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5256 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun5257(_ctx), _ctx); /*3926*/
    _x5255 = kk_double_unbox(_x5256, _ctx); /*float64*/
  }
  else {
    _x5255 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x5255, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun5232(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core__list _x5233;
  kk_std_core__list _x5242;
  kk_std_core__list _x5251 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5252(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<61>*/
  _x5242 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5243(_ctx)), _x5251, _ctx); /*list<61>*/
  _x5233 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5234(_ctx)), _x5242, _ctx); /*list<61>*/
  return kk_std_text_parse_choose(_x5233, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun5261(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun5261, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_pdouble_fun5261(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_double_box(0.0, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun5263__t {
  struct kk_function_s _base;
  bool x_4196;
};
static kk_box_t kk_std_num_float64_pdouble_fun5263(kk_function_t _fself, kk_box_t _b_4673, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun5263(bool x_4196, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdouble_fun5263__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdouble_fun5263__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64_pdouble_fun5263, kk_context());
  _self->x_4196 = x_4196;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64_pdouble_fun5263(kk_function_t _fself, kk_box_t _b_4673, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdouble_fun5263__t* _self = kk_function_as(struct kk_std_num_float64_pdouble_fun5263__t*, _fself);
  bool x_4196 = _self->x_4196; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  double d_4676 = kk_double_unbox(_b_4673, _ctx); /*float64*/;
  double _x5264;
  if (x_4196) {
    _x5264 = (-d_4676); /*float64*/
  }
  else {
    _x5264 = d_4676; /*float64*/
  }
  return kk_double_box(_x5264, _ctx);
}

double kk_std_num_float64_pdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  bool x_4196 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5220 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun5221(_ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5220, _ctx);
  }
  {
    double x0_4199;
    kk_box_t _x5224;
    kk_std_core__list _x5225;
    kk_std_core__list _x5228;
    kk_std_core__list _x5231;
    kk_std_core__list _x5260 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5261(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<61>*/
    _x5231 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5232(_ctx)), _x5260, _ctx); /*list<61>*/
    _x5228 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5229(_ctx)), _x5231, _ctx); /*list<61>*/
    _x5225 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_float64_new_pdouble_fun5226(_ctx)), _x5228, _ctx); /*list<61>*/
    _x5224 = kk_std_text_parse_choose(_x5225, _ctx); /*765*/
    x0_4199 = kk_double_unbox(_x5224, _ctx); /*float64*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x5262 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun5263(x_4196, _ctx), _ctx); /*3926*/
      return kk_double_unbox(_x5262, _ctx);
    }
    if (x_4196) {
      return (-x0_4199);
    }
    {
      return x0_4199;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift4112_parse_float64_fun5266__t {
  struct kk_function_s _base;
  double x;
};
static kk_box_t kk_std_num_float64__mlift4112_parse_float64_fun5266(kk_function_t _fself, kk_box_t _b_4678, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift4112_parse_float64_fun5266(double x, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4112_parse_float64_fun5266__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift4112_parse_float64_fun5266__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_float64__mlift4112_parse_float64_fun5266, kk_context());
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_std_num_float64__mlift4112_parse_float64_fun5266(kk_function_t _fself, kk_box_t _b_4678, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift4112_parse_float64_fun5266__t* _self = kk_function_as(struct kk_std_num_float64__mlift4112_parse_float64_fun5266__t*, _fself);
  double x = _self->x; /* float64 */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t wild___4680 = kk_Unit;
  kk_unit_unbox(_b_4678);
  return kk_double_box(x, _ctx);
}

double kk_std_num_float64__mlift4112_parse_float64(double x, kk_context_t* _ctx) { /* (x : float64) -> std/text/parse/parse float64 */ 
  kk_unit_t x0_4210 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x5265 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift4112_parse_float64_fun5266(x, _ctx), _ctx); /*3926*/
    return kk_double_unbox(_x5265, _ctx);
  }
  {
    return x;
  }
}
 
// Parse a float64 number. Can be "NaN", "Inf(inity)" (case-insensitive),
// a fix-point number (`1.2`) or in scientific notation (`-2.3e-5`).
// Also allows floats in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41) (`0xA.Fp-10`) that can
// be represented precisely (and are the preferred _round trip_ format).


// lift anonymous function
struct kk_std_num_float64_parse_float64_fun5272__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_parse_float64_fun5272(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_parse_float64_fun5272(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_parse_float64_fun5272, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_float64_parse_float64_fun5275__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_parse_float64_fun5275(kk_function_t _fself, kk_box_t _b_4682, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_parse_float64_fun5275(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_parse_float64_fun5275, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_float64_parse_float64_fun5275(kk_function_t _fself, kk_box_t _b_4682, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x5276;
  double _x5277 = kk_double_unbox(_b_4682, _ctx); /*float64*/
  _x5276 = kk_std_num_float64__mlift4112_parse_float64(_x5277, _ctx); /*float64*/
  return kk_double_box(_x5276, _ctx);
}
static kk_box_t kk_std_num_float64_parse_float64_fun5272(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  double x_4214 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  double _x5273;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5274 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_parse_float64_fun5275(_ctx), _ctx); /*3926*/
    _x5273 = kk_double_unbox(_x5274, _ctx); /*float64*/
  }
  else {
    _x5273 = kk_std_num_float64__mlift4112_parse_float64(x_4214, _ctx); /*float64*/
  }
  return kk_double_box(_x5273, _ctx);
}

kk_std_core_types__maybe kk_std_num_float64_parse_float64(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<float64> */ 
  kk_string_t s0_4038;
  kk_string_t _x5267;
  kk_string_t _x5268 = kk_string_trim_left(s,kk_context()); /*string*/
  _x5267 = kk_string_trim_right(_x5268,kk_context()); /*string*/
  s0_4038 = kk_std_core_to_lower(_x5267, _ctx); /*string*/
  kk_std_core__sslice input_4036;
  kk_string_t _x5269 = kk_string_dup(s0_4038); /*string*/
  kk_ssize_t _x5270 = (KK_IZ(0)); /*ssize_t*/
  kk_ssize_t _x5271 = kk_string_len(s0_4038,kk_context()); /*ssize_t*/
  input_4036 = kk_std_core__new_Sslice(_x5269, _x5270, _x5271, _ctx); /*sslice*/
  kk_std_text_parse__parse_error perr_4035 = kk_std_text_parse_parse(input_4036, kk_std_num_float64_new_parse_float64_fun5272(_ctx), _ctx); /*std/text/parse/parse-error<float64>*/;
  if (kk_std_text_parse__is_ParseOk(perr_4035)) {
    struct kk_std_text_parse_ParseOk* _con5278 = kk_std_text_parse__as_ParseOk(perr_4035);
    kk_box_t _box_x4688 = _con5278->result;
    kk_std_core__sslice _pat00 = _con5278->rest;
    double x0 = kk_double_unbox(_box_x4688, NULL);
    if (kk_likely(kk_std_text_parse__parse_error_is_unique(perr_4035))) {
      kk_std_core__sslice_drop(_pat00, _ctx);
      kk_box_drop(_box_x4688, _ctx);
      kk_std_text_parse__parse_error_free(perr_4035, _ctx);
    }
    else {
      kk_std_text_parse__parse_error_decref(perr_4035, _ctx);
    }
    return kk_std_core_types__new_Just(kk_double_box(x0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con5280 = kk_std_text_parse__as_ParseError(perr_4035);
    kk_string_t msg = _con5280->msg;
    kk_std_core__sslice _pat5 = _con5280->rest;
    if (kk_likely(kk_std_text_parse__parse_error_is_unique(perr_4035))) {
      kk_string_drop(msg, _ctx);
      kk_std_core__sslice_drop(_pat5, _ctx);
      kk_std_text_parse__parse_error_free(perr_4035, _ctx);
    }
    else {
      kk_std_text_parse__parse_error_decref(perr_4035, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Round a float64 to a specified precision. Rounds to the  even number in case of a tie.
// `123.456.round-to-prec(2) == 123.46`
// `123.456.round-to-prec(-1) == 120.0`

double kk_std_num_float64_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx) { /* (d : float64, prec : int) -> float64 */ 
  bool _match_4716 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_4716) {
    kk_integer_drop(prec, _ctx);
    return kk_double_round_even(d,kk_context());
  }
  {
    double p;
    double _x5281 = kk_integer_as_double(prec,kk_context()); /*float64*/
    p = pow(10.0,_x5281); /*float64*/
    double _x5282;
    double _x5283 = (d * p); /*float64*/
    _x5282 = kk_double_round_even(_x5283,kk_context()); /*float64*/
    return (_x5282 / p);
  }
}
 
/* Show a float64 in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41).
An advantage of this format is that it precisely represents the `:float64` and can
reliably (and efficiently) be parsed back, i.e. `d.show-hex.parse-float64 == Just(d)`.
The significant is the _hexadecimal_ fraction while the
exponent after the `p` is the _decimal_ power of 2.
 For example, ``0xA.Fp-10`` = (10 + 15/16)&middot;2^-10^  (not 2^-16^!) = 0.01068115234375.
 Equivalently, ``0xA.Fp-10 == 0x5.78p-9 == 0x2.BCp-8 == 0x1.5Ep-7``.
```
> flt-min.show-hex
"0x1.0p-1022"
> 0.1.show-hex
"0x1.999999999999Ap-4"
> flt-max.show-hex
"0x1.FFFFFFFFFFFFFp+1023"
> -0.0.show-hex
"-0x0.0p+0"
> nan.show-hex
"NaN"
> 0.01068115234375.show-hex
"0x1.5Ep-7"
```
.
*/

kk_string_t kk_std_num_float64_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (d : float64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  bool b_4040 = isfinite(d); /*bool*/;
  if (b_4040) {
    kk_std_core_types__tuple2_ _match_4705 = kk_std_num_float64_decode(d, _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x4691 = _match_4705.fst;
      kk_box_t _box_x4692 = _match_4705.snd;
      kk_integer_t m = kk_integer_unbox(_box_x4691);
      kk_integer_t e = kk_integer_unbox(_box_x4692);
      kk_integer_dup(e);
      kk_integer_dup(m);
      kk_std_core_types__tuple2__drop(_match_4705, _ctx);
      kk_string_t man;
      kk_integer_t _x5286 = kk_integer_abs(m,kk_context()); /*int*/
      kk_std_core_types__optional _x5287 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<112>*/
      kk_std_core_types__optional _x5288;
      kk_box_t _x5289;
      bool _x5290;
      if (kk_std_core_types__is_Optional(use_capitals)) {
        kk_box_t _box_x4694 = use_capitals._cons.Optional.value;
        bool _use_capitals_3550 = kk_bool_unbox(_box_x4694);
        _x5290 = _use_capitals_3550; /*bool*/
      }
      else {
        _x5290 = true; /*bool*/
      }
      _x5289 = kk_bool_box(_x5290); /*112*/
      _x5288 = kk_std_core_types__new_Optional(_x5289, _ctx); /*optional<112>*/
      kk_std_core_types__optional _x5292;
      kk_box_t _x5293;
      kk_string_t _x5294 = kk_string_empty(); /*string*/
      _x5293 = kk_string_box(_x5294); /*112*/
      _x5292 = kk_std_core_types__new_Optional(_x5293, _ctx); /*optional<112>*/
      man = kk_std_core_show_hex(_x5286, _x5287, _x5288, _x5292, _ctx); /*string*/
      kk_integer_t x0_4043;
      kk_string_t _x5296 = kk_string_dup(man); /*string*/
      x0_4043 = kk_std_core_count_1(_x5296, _ctx); /*int*/
      kk_integer_t y_4042;
      kk_integer_t _x5297 = kk_integer_add_small_const(x0_4043, -1, _ctx); /*int*/
      y_4042 = kk_integer_mul((kk_integer_from_small(4)),_x5297,kk_context()); /*int*/
      kk_integer_t exp0 = kk_integer_add(e,y_4042,kk_context()); /*int*/;
      kk_string_t exp;
      kk_string_t _x5298;
      bool _match_4715 = kk_integer_gte_borrow(exp0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_4715) {
        kk_define_string_literal(, _s5299, 1, "+")
        _x5298 = kk_string_dup(_s5299); /*string*/
      }
      else {
        _x5298 = kk_string_empty(); /*string*/
      }
      kk_string_t _x5301 = kk_std_core_show(exp0, _ctx); /*string*/
      exp = kk_std_core__lp__plus__plus__1_rp_(_x5298, _x5301, _ctx); /*string*/
      kk_string_t frac;
      kk_string_t _own_4713;
      kk_string_t _x5302;
      kk_string_t _x5303 = kk_string_dup(man); /*string*/
      _x5302 = kk_std_core_tail_2(_x5303, _ctx); /*string*/
      kk_string_t _x5304;
      kk_define_string_literal(, _s5305, 1, "0")
      _x5304 = kk_string_dup(_s5305); /*string*/
      _own_4713 = kk_std_core_trim_right_1(_x5302, _x5304, _ctx); /*string*/
      kk_integer_t _brw_4712;
      bool _match_4709;
      kk_integer_t _brw_4710;
      if (kk_std_core_types__is_Optional(width)) {
        kk_box_t _box_x4700 = width._cons.Optional.value;
        kk_integer_t _width_3546 = kk_integer_unbox(_box_x4700);
        kk_integer_dup(_width_3546);
        _brw_4710 = _width_3546; /*int*/
      }
      else {
        _brw_4710 = kk_integer_from_small(1); /*int*/
      }
      bool _brw_4711 = kk_integer_gte_borrow((kk_integer_from_small(1)),_brw_4710,kk_context()); /*bool*/;
      kk_integer_drop(_brw_4710, _ctx);
      _match_4709 = _brw_4711; /*bool*/
      if (_match_4709) {
        kk_std_core_types__optional_drop(width, _ctx);
        _brw_4712 = kk_integer_from_small(1); /*int*/
      }
      else {
        if (kk_std_core_types__is_Optional(width)) {
          kk_box_t _box_x4701 = width._cons.Optional.value;
          kk_integer_t _width_35460 = kk_integer_unbox(_box_x4701);
          _brw_4712 = _width_35460; /*int*/
        }
        else {
          _brw_4712 = kk_integer_from_small(1); /*int*/
        }
      }
      kk_string_t _brw_4714;
      kk_std_core_types__optional _x5308 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<112>*/
      _brw_4714 = kk_std_core_pad_right(_own_4713, _brw_4712, _x5308, _ctx); /*string*/
      kk_integer_drop(_brw_4712, _ctx);
      frac = _brw_4714; /*string*/
      kk_string_t sign;
      bool _match_4706 = (d < (0.0)); /*bool*/;
      if (_match_4706) {
        kk_define_string_literal(, _s5309, 1, "-")
        sign = kk_string_dup(_s5309); /*string*/
      }
      else {
        bool _match_4707 = (d == (0.0)); /*bool*/;
        if (_match_4707) {
          bool _match_4708;
          double _x5310 = ((1.0) / d); /*float64*/
          _match_4708 = (isinf(_x5310) && signbit(_x5310)); /*bool*/
          if (_match_4708) {
            kk_define_string_literal(, _s5311, 1, "-")
            sign = kk_string_dup(_s5311); /*string*/
          }
          else {
            sign = kk_string_empty(); /*string*/
          }
        }
        else {
          sign = kk_string_empty(); /*string*/
        }
      }
      kk_string_t _x5314;
      kk_string_t _x5315;
      if (kk_std_core_types__is_Optional(pre)) {
        kk_box_t _box_x4704 = pre._cons.Optional.value;
        kk_string_t _pre_3554 = kk_string_unbox(_box_x4704);
        _x5315 = _pre_3554; /*string*/
      }
      else {
        kk_define_string_literal(, _s5317, 2, "0x")
        _x5315 = kk_string_dup(_s5317); /*string*/
      }
      kk_string_t _x5318;
      kk_string_t _x5319 = kk_std_core_head_3(man, _ctx); /*string*/
      kk_string_t _x5320;
      kk_string_t _x5321;
      kk_define_string_literal(, _s5322, 1, ".")
      _x5321 = kk_string_dup(_s5322); /*string*/
      kk_string_t _x5323;
      kk_string_t _x5324;
      kk_string_t _x5325;
      kk_define_string_literal(, _s5326, 1, "p")
      _x5325 = kk_string_dup(_s5326); /*string*/
      _x5324 = kk_std_core__lp__plus__plus__1_rp_(_x5325, exp, _ctx); /*string*/
      _x5323 = kk_std_core__lp__plus__plus__1_rp_(frac, _x5324, _ctx); /*string*/
      _x5320 = kk_std_core__lp__plus__plus__1_rp_(_x5321, _x5323, _ctx); /*string*/
      _x5318 = kk_std_core__lp__plus__plus__1_rp_(_x5319, _x5320, _ctx); /*string*/
      _x5314 = kk_std_core__lp__plus__plus__1_rp_(_x5315, _x5318, _ctx); /*string*/
      return kk_std_core__lp__plus__plus__1_rp_(sign, _x5314, _ctx);
    }
  }
  {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    return kk_std_core_show_1(d, kk_std_core_types__new_None(_ctx), _ctx);
  }
}

// initialization
void kk_std_num_float64__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_int64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_float64_flt_max_prec = kk_integer_from_small(15); /*int*/
  }
  {
    kk_std_num_float64_rad2deg = ((180.0) / (3.141592653589793)); /*float64*/
  }
  {
    kk_std_num_float64_deg2rad = ((3.141592653589793) / (180.0)); /*float64*/
  }
  {
    kk_std_num_float64_neginf = kk_std_num_float64_make_neginf(_ctx); /*float64*/
  }
  {
    kk_std_num_float64_posinf = kk_std_num_float64_make_posinf(_ctx); /*float64*/
  }
  {
    kk_std_num_float64_nan = kk_std_num_float64_make_nan(_ctx); /*float64*/
  }
}

// termination
void kk_std_num_float64__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_std_num_float64_flt_max_prec, _ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_text_parse__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
