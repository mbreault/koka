#pragma once
#ifndef kk_std_num_float64_H
#define kk_std_num_float64_H
// Koka generated module: "std/num/float64", koka version: 2.4.0, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_text_parse.h"
#include "std_num_int64.h"

// type declarations

// value declarations
 
// The maximum of the absolute values.

static inline double kk_std_num_float64_abs_max(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  double x0_3956 = kk_double_abs(x); /*float64*/;
  double y0_3957 = kk_double_abs(y); /*float64*/;
  bool _match_4813 = (x0_3956 >= y0_3957); /*bool*/;
  if (_match_4813) {
    return x0_3956;
  }
  {
    return y0_3957;
  }
}

double kk_std_num_float64_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

double kk_std_num_float64_acosh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

double kk_std_num_float64_asinh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

double kk_std_num_float64_atanh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

int64_t kk_std_num_float64_float64_to_bits(double d, kk_context_t* _ctx); /* (d : float64) -> int64 */ 
 
// Smallest positive normalized float64 value
#define kk_std_num_float64_flt_min ((double)(2.2250738585072014e-308))
 
// &pi;
#define kk_std_num_float64_pi ((double)(3.141592653589793))

double kk_std_num_float64_float64(float f, kk_context_t* _ctx); /* (f : float32) -> float64 */ 

double kk_std_num_float64_float64_from_bits(int64_t i, kk_context_t* _ctx); /* (i : int64) -> float64 */ 

double kk_std_num_float64_make_neginf(kk_context_t* _ctx); /* () -> float64 */ 
#define kk_std_num_float64_one_m1022 ((double)(2.2250738585072014e-308))
#define kk_std_num_float64_one_p1023 ((double)(8.98846567431158e307))

double kk_std_num_float64_make_posinf(kk_context_t* _ctx); /* () -> float64 */ 
 
// The natural logarithm of 2
#define kk_std_num_float64_flt_ln2 ((double)(0.6931471805599453))

float kk_std_num_float64_float32(double f, kk_context_t* _ctx); /* (f : float64) -> float32 */ 
 
// Return the 'floored' fraction of `d`, always greater or equal to zero.
// `d.floor + d.ffraction === d`
// `(-2.4).ffraction === 0.6`

static inline double kk_std_num_float64_ffraction(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  double _x4819 = floor(d); /*float64*/
  return (d - _x4819);
}
 
// The [_e_](https://en.wikipedia.org/wiki/E_(mathematical_constant)) constant.
#define kk_std_num_float64_flt_e ((double)(2.718281828459045))
 
// Machine epsilon: the difference between 1.0 and the next representable `:float64` value.
#define kk_std_num_float64_flt_epsilon ((double)(2.220446049250313e-16))
 
// [Euler's constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant)
#define kk_std_num_float64_flt_euler ((double)(0.5772156649015329))
 
// The natural logarithm of 10
#define kk_std_num_float64_flt_ln10 ((double)(2.302585092994046))
 
// The base-10 logarithm of _e_.
#define kk_std_num_float64_flt_log10e ((double)(0.4342944819032518))
 
// The base-2 logarithm of _e_.
#define kk_std_num_float64_flt_log2e ((double)(1.4426950408889634))
 
// Maximum float64 value
#define kk_std_num_float64_flt_max ((double)(1.7976931348623157e308))
 
// maximal precision in decimal digits of a `:float64`.

extern kk_integer_t kk_std_num_float64_flt_max_prec;
 
// &pi;/2
#define kk_std_num_float64_flt_pi2 ((double)(1.5707963267948966))
 
// 3&pi;/4
#define kk_std_num_float64_flt_pi34 ((double)(2.356194490192345))
 
// &pi;/4
#define kk_std_num_float64_flt_pi4 ((double)(0.7853981633974483))
 
// `1.0 / sqrt(2.0)`  (= `sqrt(0.5)`)
#define kk_std_num_float64_flt_sqrt12 ((double)(0.7071067811865476))
 
// The square-root of 2
#define kk_std_num_float64_flt_sqrt2 ((double)(1.4142135623730951))
 
// Smallest positive subnormal value (i.e. [``DBL_TRUE_MIN``](http://en.cppreference.com/w/cpp/types/climits))
#define kk_std_num_float64_flt_true_min ((double)(5.0e-324))
 
// 2&pi;
#define kk_std_num_float64_flt_twopi ((double)(6.283185307179586))

double kk_std_num_float64_fmadd(double x, double y, double z, kk_context_t* _ctx); /* (x : float64, y : float64, z : float64) -> float64 */ 
 
// Return the integral part of a `:float64` `d` .
// If `d >= 0.0` , return the largest integer equal or less to `d` ,
// If `d < 0.0` , return the smallest integer equal or larger to `d` .

static inline double kk_std_num_float64_truncate(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  bool _match_4811 = (d >= (0.0)); /*bool*/;
  if (_match_4811) {
    return floor(d);
  }
  {
    return ceil(d);
  }
}
 
// Is this a negative zero value?

static inline bool kk_std_num_float64_is_negzero(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  bool _match_4810 = (d == (0.0)); /*bool*/;
  if (_match_4810) {
    double _x4820 = ((1.0) / d); /*float64*/
    return (isinf(_x4820) && signbit(_x4820));
  }
  {
    return false;
  }
}
 
// The square of a float64

static inline double kk_std_num_float64_sqr(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  return (x * x);
}

double kk_std_num_float64_sum(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

bool kk_std_num_float64_is_inf(double d, kk_context_t* _ctx); /* (d : float64) -> bool */ 
 
// Return the logarithm in base `base` of a `:float64` `f`

static inline double kk_std_num_float64_log(double f, double base, kk_context_t* _ctx) { /* (f : float64, base : float64) -> float64 */ 
  double _x4850 = log(f); /*float64*/
  double _x4851 = log(base); /*float64*/
  return (_x4850 / _x4851);
}

double kk_std_num_float64_make_nan(kk_context_t* _ctx); /* () -> float64 */ 

double kk_std_num_float64_prim_parse_float64(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> float64 */ 
 
// Return `x` with the sign of `y`.

static inline double kk_std_num_float64_with_sign_of(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_4806 = (y < (0.0)); /*bool*/;
  if (_match_4806) {
    double _x4852 = kk_double_abs(x); /*float64*/
    return (-_x4852);
  }
  {
    return kk_double_abs(x);
  }
}

kk_std_core_types__order kk_std_num_float64_compare(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> order */ 

kk_std_core_types__tuple2_ kk_std_num_float64_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx); /* (d : float64, e-adjust : optional<int>) -> (int, int) */ 
 
// Is this a [subnormal](https://en.wikipedia.org/wiki/Denormal_number) value?
// (i.e. `0 < d.abs < flt-min`)

static inline bool kk_std_num_float64_is_subnormal(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  bool _match_4802 = (d != (0.0)); /*bool*/;
  if (_match_4802) {
    double _x4871 = kk_double_abs(d); /*float64*/
    return (_x4871 < (2.2250738585072014e-308));
  }
  {
    return false;
  }
}

kk_std_core_types__tuple2_ kk_std_num_float64_decode(double d, kk_context_t* _ctx); /* (d : float64) -> (int, int) */ 

extern double kk_std_num_float64_rad2deg;
 
// Convert radians to degrees.

static inline double kk_std_num_float64_deg(double rad0, kk_context_t* _ctx) { /* (rad : float64) -> float64 */ 
  return (rad0 * kk_std_num_float64_rad2deg);
}

extern double kk_std_num_float64_deg2rad;

double kk_std_num_float64_exp2_1(kk_integer_t e, kk_context_t* _ctx); /* (e : int) -> float64 */ 

static inline double kk_std_num_float64_mul_exp2(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : float64, e : int) -> float64 */ 
  double _x4882 = kk_std_num_float64_exp2_1(e, _ctx); /*float64*/
  return (x * _x4882);
}

extern double kk_std_num_float64_neginf;

extern double kk_std_num_float64_posinf;

double kk_std_num_float64_ldexp(double x, kk_integer_t e, kk_context_t* _ctx); /* (x : float64, e : int) -> float64 */ 
 
// Create a float64 `d` given a mantissa `man` and exponent `exp`
// such that `man`&middot;2^`exp`^ =  `d` exactly (if it is representable
// by a `:float64`). See also `ldexp`.

static inline double kk_std_num_float64_encode(kk_integer_t man, kk_integer_t exp, kk_context_t* _ctx) { /* (man : int, exp : int) -> float64 */ 
  double _x4890 = kk_integer_as_double(man,kk_context()); /*float64*/
  return kk_std_num_float64_ldexp(_x4890, exp, _ctx);
}

static inline double kk_std_num_float64_exp2m1(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  double _x4891 = ((0.6931471805599453) * x); /*float64*/
  return expm1(_x4891);
}
 
// Short version of `float32` for convenience, e.g. `1.337.f32`. For example:
// ```
// > 1.337.show-hex ++ " != " ++ 1.337.f32.float64.show-hex
// "0x1.5645A1CAC0831p+0 != 0x1.5645A2p+0"
// ```

static inline float kk_std_num_float64_f32(double f, kk_context_t* _ctx) { /* (f : float64) -> float32 */ 
  return kk_std_num_float64_float32(f, _ctx);
}
 
// &pi;
#define kk_std_num_float64_flt_pi ((double)(3.141592653589793))
 
// Return the fractional part of a `:float64` `d`.
// `d.truncate + d.fraction === d`
// `(-2.4).fraction === -0.4`

static inline double kk_std_num_float64_fraction(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  double _x4892;
  bool _match_4788 = (d >= (0.0)); /*bool*/;
  if (_match_4788) {
    _x4892 = floor(d); /*float64*/
  }
  else {
    _x4892 = ceil(d); /*float64*/
  }
  return (d - _x4892);
}

kk_std_core_types__tuple2_ kk_std_num_float64_frexp(double x, kk_context_t* _ctx); /* (x : float64) -> (float64, int) */ 

double kk_std_num_float64_hypot(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

double kk_std_num_float64_hypot_1(double x, double y, double z, kk_context_t* _ctx); /* (x : float64, y : float64, z : float64) -> float64 */ 

double kk_std_num_float64_hypot_2(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

double kk_std_num_float64_lnaddexp(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

static inline double kk_std_num_float64_log2p1(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  double _x4928 = log1p(x); /*float64*/
  return ((1.4426950408889634) * _x4928);
}

double kk_std_num_float64_logaddexp2(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

extern double kk_std_num_float64_nan;

bool kk_std_num_float64_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx); /* (x : float64, y : float64, epsilon : optional<float64>) -> bool */ 

double kk_std_num_float64_next_down(double x, kk_context_t* _ctx); /* (x : float64) -> float64 */ 

double kk_std_num_float64_next_up(double x, kk_context_t* _ctx); /* (x : float64) -> float64 */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_float64__mlift4090_pdecdouble(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

double kk_std_num_float64__mlift4091_pdecdouble(kk_std_core__sslice cur, kk_integer_t exp, kk_context_t* _ctx); /* (cur : sslice, exp : int) -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline kk_string_t kk_std_num_float64__mlift4092_pdecdouble(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits0(_ctx);
}

double kk_std_num_float64__mlift4093_pdecdouble(kk_std_core__sslice cur, kk_string_t _y_4054, kk_context_t* _ctx); /* (cur : sslice, string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift4094_pdecdouble(kk_std_core__sslice cur, kk_string_t man, kk_context_t* _ctx); /* (cur : sslice, man : string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift4095_pdecdouble(kk_std_core__sslice cur, kk_context_t* _ctx); /* (cur : sslice) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_pdecdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_float64__mlift4096_phexdouble(kk_char_t wild__2, kk_context_t* _ctx) { /* (wild_2 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

double kk_std_num_float64__mlift4097_phexdouble(kk_string_t frac, kk_string_t man, kk_integer_t exp, kk_context_t* _ctx); /* (frac : string, man : string, exp : int) -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline kk_string_t kk_std_num_float64__mlift4098_phexdouble(kk_char_t wild__1, kk_context_t* _ctx) { /* (wild_1 : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_hex_digits(_ctx);
}

double kk_std_num_float64__mlift4099_phexdouble(kk_string_t man, kk_string_t _y_4063, kk_context_t* _ctx); /* (man : string, string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift4100_phexdouble(kk_string_t man, kk_context_t* _ctx); /* (man : string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift4101_phexdouble(kk_char_t wild__0, kk_context_t* _ctx); /* (wild_0 : char) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift4102_phexdouble(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_phexdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline double kk_std_num_float64__mlift4103_pspecial(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__, _ctx);
  return kk_std_num_float64_nan;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift4104_pspecial(kk_string_t wild__0, kk_context_t* _ctx) { /* (wild_0 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__0, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift4105_pspecial(kk_string_t wild__1, kk_context_t* _ctx) { /* (wild_1 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__1, _ctx);
  return kk_std_num_float64_posinf;
}

double kk_std_num_float64_pspecial(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline double kk_std_num_float64__mlift4106_pdouble(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__, _ctx);
  return kk_std_num_float64_nan;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift4107_pdouble(kk_string_t wild__0, kk_context_t* _ctx) { /* (wild_0 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__0, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift4108_pdouble(kk_string_t wild__1, kk_context_t* _ctx) { /* (wild_1 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__1, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift4109_pdouble(bool neg, double d, kk_context_t* _ctx) { /* (neg : bool, d : float64) -> std/text/parse/parse float64 */ 
  if (neg) {
    return (-d);
  }
  {
    return d;
  }
}

double kk_std_num_float64__mlift4110_pdouble(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_pdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline double kk_std_num_float64__mlift4111_parse_float64(double x, kk_unit_t wild__, kk_context_t* _ctx) { /* (x : float64, wild_ : ()) -> std/text/parse/parse float64 */ 
  return x;
}

double kk_std_num_float64__mlift4112_parse_float64(double x, kk_context_t* _ctx); /* (x : float64) -> std/text/parse/parse float64 */ 

kk_std_core_types__maybe kk_std_num_float64_parse_float64(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<float64> */ 
 
// Convert degrees to radians.

static inline double kk_std_num_float64_rad(double deg0, kk_context_t* _ctx) { /* (deg : float64) -> float64 */ 
  return (deg0 * kk_std_num_float64_deg2rad);
}

double kk_std_num_float64_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx); /* (d : float64, prec : int) -> float64 */ 

kk_string_t kk_std_num_float64_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (d : float64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Return if two floats are nearly equal with respect to an `epsilon` of `8*flt-epsilon`.
// See also `nearly-eq` which takes an explicit `epsilon`.

static inline bool kk_std_num_float64__lp__tilde__eq__rp_(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> bool */ 
  return kk_std_num_float64_nearly_eq(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

void kk_std_num_float64__init(kk_context_t* _ctx);


void kk_std_num_float64__done(kk_context_t* _ctx);

#endif // header
