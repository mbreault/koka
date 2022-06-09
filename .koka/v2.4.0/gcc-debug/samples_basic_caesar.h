#pragma once
#ifndef kk_samples_basic_caesar_H
#define kk_samples_basic_caesar_H
// Koka generated module: "samples/basic/caesar", koka version: 2.4.0, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_float64.h"

// type declarations

// value declarations

kk_string_t kk_samples_basic_caesar_encode(kk_string_t s, kk_std_core_types__optional shift, kk_context_t* _ctx); /* (s : string, shift : optional<int>) -> string */ 

double kk_samples_basic_caesar_chisqr(kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx); /* (xs : list<float64>, ys : list<float64>) -> float64 */ 

extern kk_std_core__list kk_samples_basic_caesar_english;
 
// Small helper functions

static inline double kk_samples_basic_caesar_percent(kk_integer_t n, kk_integer_t m, kk_context_t* _ctx) { /* (n : int, m : int) -> float64 */ 
  double _x1493;
  double _x1494 = kk_integer_as_double(n,kk_context()); /*float64*/
  double _x1495 = kk_integer_as_double(m,kk_context()); /*float64*/
  _x1493 = (_x1494 / _x1495); /*float64*/
  return ((100.0) * _x1493);
}

static inline kk_std_core__list kk_samples_basic_caesar_rotate(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core__list xs0_1254;
  kk_std_core__list _x1496 = kk_std_core__list_dup(xs); /*list<578>*/
  kk_integer_t _x1497 = kk_integer_dup(n); /*int*/
  xs0_1254 = kk_std_core_drop(_x1496, _x1497, _ctx); /*list<578>*/
  kk_std_core__list ys_1255 = kk_std_core_take(xs, n, _ctx); /*list<578>*/;
  return kk_std_core_append(xs0_1254, ys_1255, _ctx);
}

static inline kk_string_t kk_samples_basic_caesar_caesar(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_types__optional _x1498 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<1035>*/
  return kk_samples_basic_caesar_encode(s, _x1498, _ctx);
}

kk_std_core__list kk_samples_basic_caesar_freqs(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> list<float64> */ 

kk_string_t kk_samples_basic_caesar_uncaesar(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_unit_t kk_samples_basic_caesar_main(kk_context_t* _ctx); /* () -> console () */ 

static inline kk_unit_t kk_samples_basic_caesar_test_uncaesar(kk_context_t* _ctx) { /* () -> console () */ 
  kk_string_t s_1274;
  kk_string_t _x1563;
  kk_define_string_literal(, _s1564, 22, "nrnd lv d ixq odqjxdjh")
  _x1563 = kk_string_dup(_s1564); /*string*/
  s_1274 = kk_samples_basic_caesar_uncaesar(_x1563, _ctx); /*string*/
  kk_std_core_printsln(s_1274, _ctx); return kk_Unit;
}

void kk_samples_basic_caesar__init(kk_context_t* _ctx);


void kk_samples_basic_caesar__done(kk_context_t* _ctx);

#endif // header
