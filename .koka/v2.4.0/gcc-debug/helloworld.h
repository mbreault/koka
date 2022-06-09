#pragma once
#ifndef kk_helloworld_H
#define kk_helloworld_H
// Koka generated module: "helloworld", koka version: 2.4.0, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"

// type declarations

// value declarations

static inline kk_unit_t kk_helloworld_main(kk_context_t* _ctx) { /* () -> console () */ 
  kk_string_t _x27;
  kk_define_string_literal(, _s28, 12, "Hello world!")
  _x27 = kk_string_dup(_s28); /*string*/
  kk_std_core_printsln(_x27, _ctx); return kk_Unit;
}

void kk_helloworld__init(kk_context_t* _ctx);


void kk_helloworld__done(kk_context_t* _ctx);

#endif // header
