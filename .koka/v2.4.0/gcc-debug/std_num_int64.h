#pragma once
#ifndef kk_std_num_int64_H
#define kk_std_num_int64_H
// Koka generated module: "std/num/int64", koka version: 2.4.0, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"

// type declarations

// value declarations
 
// Take the bitwise _xor_ of two `:int64`s

static inline int64_t kk_std_num_int64__lp__hat__rp_(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> int64 */ 
  return x ^ y;
}

static inline kk_std_core_types__order kk_std_num_int64_compare(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> order */ 
  bool _match_1810 = (x < y); /*bool*/;
  if (_match_1810) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  {
    bool _match_1811 = (x > y); /*bool*/;
    if (_match_1811) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}
 
// Return the maximum of two integers

static inline int64_t kk_std_num_int64_max(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> int64 */ 
  bool _match_1809 = (i >= j); /*bool*/;
  if (_match_1809) {
    return i;
  }
  {
    return j;
  }
}
 
// Return the minimum of two integers

static inline int64_t kk_std_num_int64_min(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> int64 */ 
  bool _match_1808 = (i <= j); /*bool*/;
  if (_match_1808) {
    return i;
  }
  {
    return j;
  }
}

kk_string_t kk_std_num_int64_show_hex(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (i : int64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Convert an `:int64` to an `:int` but interpret the `:int64` as a 64-bit unsigned value.

static inline kk_integer_t kk_std_num_int64_uint(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int */ 
  bool _match_1807 = 0 > i; /*bool*/;
  if (_match_1807) {
    kk_integer_t y_1654 = kk_integer_from_int64(i,kk_context()); /*int*/;
    return kk_integer_add((kk_integer_from_str("18446744073709551616", _ctx)),y_1654,kk_context());
  }
  {
    return kk_integer_from_int64(i,kk_context());
  }
}

static inline kk_std_core_types__order kk_std_num_int64_sign(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> order */ 
  bool _match_1805 = 0 < i; /*bool*/;
  if (_match_1805) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  {
    bool _match_1806 = 0 > i; /*bool*/;
    if (_match_1806) {
      return kk_std_core_types__new_Lt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}

extern int64_t kk_std_num_int64_one;

extern int64_t kk_std_num_int64_zero;
 
// Convert a boolean to an `:int64`.

static inline int64_t kk_std_num_int64_int64_1(bool b, kk_context_t* _ctx) { /* (b : bool) -> int64 */ 
  if (b) {
    return kk_std_num_int64_one;
  }
  {
    return kk_std_num_int64_zero;
  }
}
 
// Shift an `:int64` `i` to the left by `n % 64` bits.

static inline int64_t kk_std_num_int64_shl(int64_t i, kk_integer_t shift, kk_context_t* _ctx) { /* (i : int64, shift : int) -> int64 */ 
  int64_t _x1826 = kk_std_core_int64(shift, _ctx); /*int64*/
  return kk_shl64(i,_x1826);
}
 
// Create an `:int64` `i` from the bits of `lo` and `hi` such
// that `i.int = hi.int * 0x1_0000_0000 + lo.uint`.

static inline int64_t kk_std_num_int64_int64_2(int32_t lo, int32_t hi, kk_context_t* _ctx) { /* (lo : int32, hi : int32) -> int64 */ 
  int64_t i_1655 = (int64_t)(hi); /*int64*/;
  int64_t _x1827;
  int64_t _x1828 = (KK_I64(32)); /*int64*/
  _x1827 = kk_shl64(i_1655,_x1828); /*int64*/
  int64_t _x1829 = (int64_t)((uint32_t)(lo)); /*int64*/
  return _x1827 | _x1829;
}

extern int64_t kk_std_num_int64_max_int64;

int64_t kk_std_num_int64_uint64_1(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int64 */ 

extern int64_t kk_std_num_int64_min_int64;

int64_t kk_std_num_int64__lp__perc__rp_(int64_t x, int64_t y, kk_context_t* _ctx); /* (x : int64, y : int64) -> int64 */ 
 
// Decrement a 64-bit integer.

static inline int64_t kk_std_num_int64_dec(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int64 */ 
  int64_t _x1837 = (KK_I64(1)); /*int64*/
  return (int64_t)((uint64_t)i - (uint64_t)_x1837);
}
 
// Increment a 64-bit integer.

static inline int64_t kk_std_num_int64_inc(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int64 */ 
  int64_t _x1838 = (KK_I64(1)); /*int64*/
  return (int64_t)((uint64_t)i + (uint64_t)_x1838);
}

int64_t kk_std_num_int64__lp__fs__rp_(int64_t x, int64_t y, kk_context_t* _ctx); /* (x : int64, y : int64) -> int64 */ 
 
// Negate a 64-bit integer

static inline int64_t kk_std_num_int64_negate(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int64 */ 
  int64_t _x1849 = (KK_I64(0)); /*int64*/
  return (int64_t)((uint64_t)_x1849 - (uint64_t)i);
}

int64_t kk_std_num_int64_abs(int64_t i, kk_context_t* _ctx); /* (i : int64) -> exn int64 */ 

int64_t kk_std_num_int64_abs0(int64_t i, kk_context_t* _ctx); /* (i : int64) -> int64 */ 

extern int64_t kk_std_num_int64_bits_int64;
 
// Convert an `:int64` to a boolean.

static inline bool kk_std_num_int64_bool(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> bool */ 
  return (i != kk_std_num_int64_zero);
}

int64_t kk_std_num_int64_cdiv(int64_t i, int64_t j, kk_context_t* _ctx); /* (i : int64, j : int64) -> exn int64 */ 

int64_t kk_std_num_int64_cmod(int64_t i, int64_t j, kk_context_t* _ctx); /* (i : int64, j : int64) -> exn int64 */ 

kk_std_core_types__tuple2_ kk_std_num_int64_divmod(int64_t x, int64_t y, kk_context_t* _ctx); /* (x : int64, y : int64) -> (int64, int64) */ 
 
// Convert an 64-bit integer to a `:float64`.

static inline double kk_std_num_int64_float64(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> float64 */ 
  kk_integer_t _x1881 = kk_integer_from_int64(i,kk_context()); /*int*/
  return kk_integer_as_double(_x1881,kk_context());
}

kk_box_t kk_std_num_int64__mlift1689_fold_int64(int64_t end, kk_function_t f, int64_t start, kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (end : int64, f : (int64, a) -> e a, start : int64, x : a) -> e a */ 

kk_box_t kk_std_num_int64_fold_int64(int64_t start0, int64_t end0, kk_box_t init, kk_function_t f0, kk_context_t* _ctx); /* forall<a,e> (start : int64, end : int64, init : a, f : (int64, a) -> e a) -> e a */ 
 
// Returns `true` if the integer `i`  is an even number.

static inline bool kk_std_num_int64_is_even(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> bool */ 
  int64_t _x1888 = i & kk_std_num_int64_one; /*int64*/
  return (_x1888 == kk_std_num_int64_zero);
}
 
// Returns `true` if the integer `i`  is an odd number.

static inline bool kk_std_num_int64_is_odd(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> bool */ 
  int64_t _x1889 = i & kk_std_num_int64_one; /*int64*/
  return (_x1889 == kk_std_num_int64_one);
}
 
// Bitwise rotate an `:int64` `n % 64` bits to the left.

static inline int64_t kk_std_num_int64_rotl(int64_t i, kk_integer_t shift, kk_context_t* _ctx) { /* (i : int64, shift : int) -> int64 */ 
  int64_t _x1890 = kk_std_core_int64(shift, _ctx); /*int64*/
  return (int64_t)kk_bits_rotl64(i,_x1890);
}
 
// Bitwise rotate an `:int64` `n % 64` bits to the right.

static inline int64_t kk_std_num_int64_rotr(int64_t i, kk_integer_t shift, kk_context_t* _ctx) { /* (i : int64, shift : int) -> int64 */ 
  int64_t _x1891 = kk_std_core_int64(shift, _ctx); /*int64*/
  return (int64_t)kk_bits_rotr64(i,_x1891);
}
 
// Arithmetic shift an `:int64` to the right by `n % 64` bits. Shift in the sign bit from the left.

static inline int64_t kk_std_num_int64_sar(int64_t i, kk_integer_t shift, kk_context_t* _ctx) { /* (i : int64, shift : int) -> int64 */ 
  int64_t _x1892 = kk_std_core_int64(shift, _ctx); /*int64*/
  return kk_sar64(i,_x1892);
}
 
// Convert an `:int64` to a string

static inline kk_string_t kk_std_num_int64_show(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> string */ 
  kk_integer_t _x1893 = kk_integer_from_int64(i,kk_context()); /*int*/
  return kk_std_core_show(_x1893, _ctx);
}

kk_string_t kk_std_num_int64_show_hex64(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (i : int64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Logical shift an `:int64` to the right by `n % 64` bits. Shift in zeros from the left.

static inline int64_t kk_std_num_int64_shr(int64_t i, kk_integer_t shift, kk_context_t* _ctx) { /* (i : int64, shift : int) -> int64 */ 
  int64_t _x1908 = kk_std_core_int64(shift, _ctx); /*int64*/
  return (int64_t)kk_shr64(i,_x1908);
}
 
// Negate an 64-bit integer

static inline int64_t kk_std_num_int64__lp__tilde__rp_(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> total int64 */ 
  int64_t _x1909 = (KK_I64(0)); /*int64*/
  return (int64_t)((uint64_t)_x1909 - (uint64_t)i);
}

void kk_std_num_int64__init(kk_context_t* _ctx);


void kk_std_num_int64__done(kk_context_t* _ctx);

#endif // header
