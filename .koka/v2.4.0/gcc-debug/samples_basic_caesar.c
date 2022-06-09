// Koka generated module: "samples/basic/caesar", koka version: 2.4.0, platform: 64-bit
#include "samples_basic_caesar.h"


// lift anonymous function
struct kk_samples_basic_caesar_encode_fun1456__t {
  struct kk_function_s _base;
  kk_std_core_types__optional shift;
};
static kk_char_t kk_samples_basic_caesar_encode_fun1456(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_encode_fun1456(kk_std_core_types__optional shift, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_encode_fun1456__t* _self = kk_function_alloc_as(struct kk_samples_basic_caesar_encode_fun1456__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_samples_basic_caesar_encode_fun1456, kk_context());
  _self->shift = shift;
  return &_self->_base;
}

static kk_char_t kk_samples_basic_caesar_encode_fun1456(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_encode_fun1456__t* _self = kk_function_as(struct kk_samples_basic_caesar_encode_fun1456__t*, _fself);
  kk_std_core_types__optional shift = _self->shift; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(shift);}, {}, _ctx)
  bool _match_1454 = (c < ('a')); /*bool*/;
  if (_match_1454) {
    kk_std_core_types__optional_drop(shift, _ctx);
    return c;
  }
  {
    bool _match_1455 = (c > ('z')); /*bool*/;
    if (_match_1455) {
      kk_std_core_types__optional_drop(shift, _ctx);
      return c;
    }
    {
      kk_integer_t x_16956 = kk_integer_from_int(c,kk_context()); /*int*/;
      kk_integer_t y_16957 = kk_integer_from_int(('a'),kk_context()); /*int*/;
      kk_integer_t base;
      kk_char_t _x1457;
      kk_integer_t _x1458 = kk_integer_sub(x_16956,y_16957,kk_context()); /*int*/
      _x1457 = kk_integer_clamp32(_x1458,kk_context()); /*char*/
      base = kk_integer_from_int(_x1457,kk_context()); /*int*/
      kk_integer_t rot;
      kk_integer_t _x1459;
      kk_integer_t _x1460;
      if (kk_std_core_types__is_Optional(shift)) {
        kk_box_t _box_x1275 = shift._cons.Optional.value;
        kk_integer_t _shift_36 = kk_integer_unbox(_box_x1275);
        _x1460 = _shift_36; /*int*/
      }
      else {
        _x1460 = kk_integer_from_small(3); /*int*/
      }
      _x1459 = kk_integer_add(base,_x1460,kk_context()); /*int*/
      rot = kk_integer_mod(_x1459,(kk_integer_from_small(26)),kk_context()); /*int*/
      kk_char_t c1_1252 = kk_integer_clamp32(rot,kk_context()); /*char*/;
      kk_integer_t x_16954 = kk_integer_from_int(c1_1252,kk_context()); /*int*/;
      kk_integer_t y_16955 = kk_integer_from_int(('a'),kk_context()); /*int*/;
      kk_integer_t _x1462 = kk_integer_add(x_16954,y_16955,kk_context()); /*int*/
      return kk_integer_clamp32(_x1462,kk_context());
    }
  }
}

kk_string_t kk_samples_basic_caesar_encode(kk_string_t s, kk_std_core_types__optional shift, kk_context_t* _ctx) { /* (s : string, shift : optional<int>) -> string */ 
  return kk_std_core_map_6(s, kk_samples_basic_caesar_new_encode_fun1456(shift, _ctx), _ctx);
}
 
// Calculate how well two frequency tables match according
// to the _chi-square_ statistic.


// lift anonymous function
struct kk_samples_basic_caesar_chisqr_fun1464__t {
  struct kk_function_s _base;
};
static kk_box_t kk_samples_basic_caesar_chisqr_fun1464(kk_function_t _fself, kk_box_t _b_1279, kk_box_t _b_1280, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_chisqr_fun1464(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_samples_basic_caesar_chisqr_fun1464, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_samples_basic_caesar_chisqr_fun1464(kk_function_t _fself, kk_box_t _b_1279, kk_box_t _b_1280, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x1465;
  double x_1284 = kk_double_unbox(_b_1279, _ctx); /*float64*/;
  double y_1285 = kk_double_unbox(_b_1280, _ctx); /*float64*/;
  double _x1466;
  double _x1467 = (x_1284 - y_1285); /*float64*/
  _x1466 = pow(_x1467,(2.0)); /*float64*/
  _x1465 = (_x1466 / y_1285); /*float64*/
  return kk_double_box(_x1465, _ctx);
}

double kk_samples_basic_caesar_chisqr(kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* (xs : list<float64>, ys : list<float64>) -> float64 */ 
  kk_std_core__list _x1463 = kk_std_core_zipwith(xs, ys, kk_samples_basic_caesar_new_chisqr_fun1464(_ctx), _ctx); /*list<1003>*/
  return kk_std_num_float64_sum(_x1463, _ctx);
}
 
// The letter frequency table for English

kk_std_core__list kk_samples_basic_caesar_english;
 
// Calculate a frequency table for a string


// lift anonymous function
struct kk_samples_basic_caesar_freqs_fun1501__t {
  struct kk_function_s _base;
};
static kk_box_t kk_samples_basic_caesar_freqs_fun1501(kk_function_t _fself, kk_box_t _b_1394, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_freqs_fun1501(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_samples_basic_caesar_freqs_fun1501, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_samples_basic_caesar_freqs_fun1501(kk_function_t _fself, kk_box_t _b_1394, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t _x1502;
  kk_integer_t _x1503 = kk_integer_unbox(_b_1394); /*int*/
  _x1502 = kk_integer_clamp32(_x1503,kk_context()); /*char*/
  return kk_char_box(_x1502, _ctx);
}


// lift anonymous function
struct kk_samples_basic_caesar_freqs_fun1504__t {
  struct kk_function_s _base;
  kk_string_t s;
};
static kk_box_t kk_samples_basic_caesar_freqs_fun1504(kk_function_t _fself, kk_box_t _b_1399, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_freqs_fun1504(kk_string_t s, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_freqs_fun1504__t* _self = kk_function_alloc_as(struct kk_samples_basic_caesar_freqs_fun1504__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_samples_basic_caesar_freqs_fun1504, kk_context());
  _self->s = s;
  return &_self->_base;
}

static kk_box_t kk_samples_basic_caesar_freqs_fun1504(kk_function_t _fself, kk_box_t _b_1399, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_freqs_fun1504__t* _self = kk_function_as(struct kk_samples_basic_caesar_freqs_fun1504__t*, _fself);
  kk_string_t s = _self->s; /* string */
  kk_drop_match(_self, {kk_string_dup(s);}, {}, _ctx)
  kk_integer_t _x1505;
  kk_string_t _x1506;
  kk_char_t _x1507 = kk_char_unbox(_b_1399, _ctx); /*char*/
  _x1506 = kk_std_core_string(_x1507, _ctx); /*string*/
  _x1505 = kk_string_count_pattern(s,_x1506,kk_context()); /*int*/
  return kk_integer_box(_x1505);
}


// lift anonymous function
struct kk_samples_basic_caesar_freqs_fun1510__t {
  struct kk_function_s _base;
};
static kk_box_t kk_samples_basic_caesar_freqs_fun1510(kk_function_t _fself, kk_box_t _b_1406, kk_box_t _b_1407, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_freqs_fun1510(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_samples_basic_caesar_freqs_fun1510, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_samples_basic_caesar_freqs_fun1510(kk_function_t _fself, kk_box_t _b_1406, kk_box_t _b_1407, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x1511;
  kk_integer_t _x1512 = kk_integer_unbox(_b_1406); /*int*/
  kk_integer_t _x1513 = kk_integer_unbox(_b_1407); /*int*/
  _x1511 = kk_std_core__lp__plus__4_rp_(_x1512, _x1513, _ctx); /*int*/
  return kk_integer_box(_x1511);
}


// lift anonymous function
struct kk_samples_basic_caesar_freqs_fun1514__t {
  struct kk_function_s _base;
  kk_integer_t total;
};
static kk_box_t kk_samples_basic_caesar_freqs_fun1514(kk_function_t _fself, kk_box_t _b_1413, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_freqs_fun1514(kk_integer_t total, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_freqs_fun1514__t* _self = kk_function_alloc_as(struct kk_samples_basic_caesar_freqs_fun1514__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_samples_basic_caesar_freqs_fun1514, kk_context());
  _self->total = total;
  return &_self->_base;
}

static kk_box_t kk_samples_basic_caesar_freqs_fun1514(kk_function_t _fself, kk_box_t _b_1413, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_freqs_fun1514__t* _self = kk_function_as(struct kk_samples_basic_caesar_freqs_fun1514__t*, _fself);
  kk_integer_t total = _self->total; /* int */
  kk_drop_match(_self, {kk_integer_dup(total);}, {}, _ctx)
  kk_integer_t i_1416 = kk_integer_unbox(_b_1413); /*int*/;
  double _x1515;
  double _x1516;
  double _x1517 = kk_integer_as_double(i_1416,kk_context()); /*float64*/
  double _x1518 = kk_integer_as_double(total,kk_context()); /*float64*/
  _x1516 = (_x1517 / _x1518); /*float64*/
  _x1515 = ((100.0) * _x1516); /*float64*/
  return kk_double_box(_x1515, _ctx);
}

kk_std_core__list kk_samples_basic_caesar_freqs(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> list<float64> */ 
  kk_std_core__list _b_1395_1392;
  kk_integer_t _x1499 = kk_integer_from_int(('a'),kk_context()); /*int*/
  kk_integer_t _x1500 = kk_integer_from_int(('z'),kk_context()); /*int*/
  _b_1395_1392 = kk_std_core_list(_x1499, _x1500, _ctx); /*list<int>*/
  kk_std_core__list lowers = kk_std_core_map_5(_b_1395_1392, kk_samples_basic_caesar_new_freqs_fun1501(_ctx), _ctx); /*list<char>*/;
  kk_std_core__list occurs = kk_std_core_map_5(lowers, kk_samples_basic_caesar_new_freqs_fun1504(s, _ctx), _ctx); /*list<int>*/;
  kk_integer_t total;
  kk_box_t _x1508;
  kk_std_core__list _x1509 = kk_std_core__list_dup(occurs); /*list<int>*/
  _x1508 = kk_std_core_foldl(_x1509, kk_integer_box(kk_integer_from_small(0)), kk_samples_basic_caesar_new_freqs_fun1510(_ctx), _ctx); /*1002*/
  total = kk_integer_unbox(_x1508); /*int*/
  return kk_std_core_map_5(occurs, kk_samples_basic_caesar_new_freqs_fun1514(total, _ctx), _ctx);
}
 
// Crack a Caesar encoded string


// lift anonymous function
struct kk_samples_basic_caesar_uncaesar_fun1520__t {
  struct kk_function_s _base;
  kk_std_core__list table;
};
static kk_box_t kk_samples_basic_caesar_uncaesar_fun1520(kk_function_t _fself, kk_box_t _b_1424, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_uncaesar_fun1520(kk_std_core__list table, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_uncaesar_fun1520__t* _self = kk_function_alloc_as(struct kk_samples_basic_caesar_uncaesar_fun1520__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_samples_basic_caesar_uncaesar_fun1520, kk_context());
  _self->table = table;
  return &_self->_base;
}



// lift anonymous function
struct kk_samples_basic_caesar_uncaesar_fun1528__t {
  struct kk_function_s _base;
};
static kk_box_t kk_samples_basic_caesar_uncaesar_fun1528(kk_function_t _fself, kk_box_t _b_1420, kk_box_t _b_1421, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_uncaesar_fun1528(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_samples_basic_caesar_uncaesar_fun1528, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_samples_basic_caesar_uncaesar_fun1528(kk_function_t _fself, kk_box_t _b_1420, kk_box_t _b_1421, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x1529;
  double _x1530;
  double _x1531;
  double _x1532 = kk_double_unbox(_b_1420, _ctx); /*float64*/
  double _x1533;
  kk_box_t _x1534 = kk_box_dup(_b_1421); /*1002*/
  _x1533 = kk_double_unbox(_x1534, _ctx); /*float64*/
  _x1531 = (_x1532 - _x1533); /*float64*/
  _x1530 = pow(_x1531,(2.0)); /*float64*/
  double _x1535 = kk_double_unbox(_b_1421, _ctx); /*float64*/
  _x1529 = (_x1530 / _x1535); /*float64*/
  return kk_double_box(_x1529, _ctx);
}
static kk_box_t kk_samples_basic_caesar_uncaesar_fun1520(kk_function_t _fself, kk_box_t _b_1424, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_uncaesar_fun1520__t* _self = kk_function_as(struct kk_samples_basic_caesar_uncaesar_fun1520__t*, _fself);
  kk_std_core__list table = _self->table; /* list<float64> */
  kk_drop_match(_self, {kk_std_core__list_dup(table);}, {}, _ctx)
  kk_std_core__list xs1_1265;
  kk_std_core__list _x1521 = kk_std_core__list_dup(table); /*list<float64>*/
  kk_integer_t _x1522;
  kk_box_t _x1523 = kk_box_dup(_b_1424); /*1001*/
  _x1522 = kk_integer_unbox(_x1523); /*int*/
  xs1_1265 = kk_std_core_drop(_x1521, _x1522, _ctx); /*list<float64>*/
  kk_std_core__list ys0_1266;
  kk_integer_t _x1524 = kk_integer_unbox(_b_1424); /*int*/
  ys0_1266 = kk_std_core_take(table, _x1524, _ctx); /*list<float64>*/
  kk_std_core__list xs_1261 = kk_std_core_append(xs1_1265, ys0_1266, _ctx); /*list<float64>*/;
  double _x1525;
  kk_std_core__list _x1526;
  kk_std_core__list _x1527 = kk_std_core__list_dup(kk_samples_basic_caesar_english); /*list<float64>*/
  _x1526 = kk_std_core_zipwith(xs_1261, _x1527, kk_samples_basic_caesar_new_uncaesar_fun1528(_ctx), _ctx); /*list<1003>*/
  _x1525 = kk_std_num_float64_sum(_x1526, _ctx); /*float64*/
  return kk_double_box(_x1525, _ctx);
}


// lift anonymous function
struct kk_samples_basic_caesar_uncaesar_fun1539__t {
  struct kk_function_s _base;
};
static kk_box_t kk_samples_basic_caesar_uncaesar_fun1539(kk_function_t _fself, kk_box_t _b_1435, kk_box_t _b_1436, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_uncaesar_fun1539(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_samples_basic_caesar_uncaesar_fun1539, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_samples_basic_caesar_uncaesar_fun1539(kk_function_t _fself, kk_box_t _b_1435, kk_box_t _b_1436, kk_context_t* _ctx) {
  kk_unused(_fself);
  double _x1540;
  double _x1541 = kk_double_unbox(_b_1435, _ctx); /*float64*/
  double _x1542 = kk_double_unbox(_b_1436, _ctx); /*float64*/
  _x1540 = kk_std_core_min_1(_x1541, _x1542, _ctx); /*float64*/
  return kk_double_box(_x1540, _ctx);
}


// lift anonymous function
struct kk_samples_basic_caesar_uncaesar_fun1543__t {
  struct kk_function_s _base;
  double min;
};
static bool kk_samples_basic_caesar_uncaesar_fun1543(kk_function_t _fself, kk_box_t _b_1442, kk_context_t* _ctx);
static kk_function_t kk_samples_basic_caesar_new_uncaesar_fun1543(double min, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_uncaesar_fun1543__t* _self = kk_function_alloc_as(struct kk_samples_basic_caesar_uncaesar_fun1543__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_samples_basic_caesar_uncaesar_fun1543, kk_context());
  _self->min = min;
  return &_self->_base;
}

static bool kk_samples_basic_caesar_uncaesar_fun1543(kk_function_t _fself, kk_box_t _b_1442, kk_context_t* _ctx) {
  struct kk_samples_basic_caesar_uncaesar_fun1543__t* _self = kk_function_as(struct kk_samples_basic_caesar_uncaesar_fun1543__t*, _fself);
  double min = _self->min; /* float64 */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x1544 = kk_double_unbox(_b_1442, _ctx); /*float64*/
  return (_x1544 == min);
}

kk_string_t kk_samples_basic_caesar_uncaesar(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core__list table;
  kk_string_t _x1519 = kk_string_dup(s); /*string*/
  table = kk_samples_basic_caesar_freqs(_x1519, _ctx); /*list<float64>*/
  kk_std_core__list _b_1425_1422 = kk_std_core_list(kk_integer_from_small(0), kk_integer_from_small(25), _ctx); /*list<int>*/;
  kk_std_core__list chitab = kk_std_core_map_5(_b_1425_1422, kk_samples_basic_caesar_new_uncaesar_fun1520(table, _ctx), _ctx); /*list<float64>*/;
  double min;
  if (kk_std_core__is_Nil(chitab)) {
    min = 0.0; /*float64*/
  }
  else {
    struct kk_std_core_Cons* _con1536 = kk_std_core__as_Cons(chitab);
    kk_box_t _box_x1431 = _con1536->head;
    kk_std_core__list xx = _con1536->tail;
    double x0 = kk_double_unbox(_box_x1431, NULL);
    kk_std_core__list_dup(xx);
    kk_box_t _x1538 = kk_std_core_foldl(xx, kk_double_box(x0, _ctx), kk_samples_basic_caesar_new_uncaesar_fun1539(_ctx), _ctx); /*1002*/
    min = kk_double_unbox(_x1538, _ctx); /*float64*/
  }
  kk_integer_t i_1268 = kk_std_core_index_of(chitab, kk_samples_basic_caesar_new_uncaesar_fun1543(min, _ctx), _ctx); /*int*/;
  kk_integer_t shift = kk_integer_neg(i_1268,kk_context()); /*int*/;
  kk_std_core_types__optional _x1545 = kk_std_core_types__new_Optional(kk_integer_box(shift), _ctx); /*optional<1035>*/
  return kk_samples_basic_caesar_encode(s, _x1545, _ctx);
}

kk_unit_t kk_samples_basic_caesar_main(kk_context_t* _ctx) { /* () -> console () */ 
  kk_string_t s_1269;
  kk_string_t _x1546;
  kk_define_string_literal(, _s1547, 9, "plain  : ")
  _x1546 = kk_string_dup(_s1547); /*string*/
  kk_string_t _x1548;
  kk_define_string_literal(, _s1549, 29, "Koka is a well-typed language")
  _x1548 = kk_string_dup(_s1549); /*string*/
  s_1269 = kk_std_core__lp__plus__plus__1_rp_(_x1546, _x1548, _ctx); /*string*/
  kk_unit_t __ = kk_Unit;
  kk_std_core_printsln(s_1269, _ctx);
  kk_string_t s0_1270;
  kk_string_t _x1550;
  kk_define_string_literal(, _s1551, 9, "encoded: ")
  _x1550 = kk_string_dup(_s1551); /*string*/
  kk_string_t _x1552;
  kk_string_t _x1553;
  kk_define_string_literal(, _s1554, 29, "Koka is a well-typed language")
  _x1553 = kk_string_dup(_s1554); /*string*/
  kk_std_core_types__optional _x1555 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<1035>*/
  _x1552 = kk_samples_basic_caesar_encode(_x1553, _x1555, _ctx); /*string*/
  s0_1270 = kk_std_core__lp__plus__plus__1_rp_(_x1550, _x1552, _ctx); /*string*/
  kk_unit_t __0 = kk_Unit;
  kk_std_core_printsln(s0_1270, _ctx);
  kk_string_t s2_1272;
  kk_string_t _x1556;
  kk_define_string_literal(, _s1557, 9, "cracked: ")
  _x1556 = kk_string_dup(_s1557); /*string*/
  kk_string_t _x1558;
  kk_string_t _x1559;
  kk_string_t _x1560;
  kk_define_string_literal(, _s1561, 29, "Koka is a well-typed language")
  _x1560 = kk_string_dup(_s1561); /*string*/
  kk_std_core_types__optional _x1562 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<1035>*/
  _x1559 = kk_samples_basic_caesar_encode(_x1560, _x1562, _ctx); /*string*/
  _x1558 = kk_samples_basic_caesar_uncaesar(_x1559, _ctx); /*string*/
  s2_1272 = kk_std_core__lp__plus__plus__1_rp_(_x1556, _x1558, _ctx); /*string*/
  kk_std_core_printsln(s2_1272, _ctx); return kk_Unit;
}

// main exit
static void _kk_main_exit(void) {
  kk_context_t* _ctx = kk_get_context();
  kk_samples_basic_caesar__done(_ctx);
}

// main entry
int main(int argc, char** argv) {
  kk_assert(sizeof(size_t)==8 && sizeof(void*)==8);
  kk_context_t* _ctx = kk_main_start(argc, argv);
  kk_samples_basic_caesar__init(_ctx);
  atexit(&_kk_main_exit);
  kk_samples_basic_caesar_main(_ctx);
  kk_samples_basic_caesar__done(_ctx);
  kk_main_end(_ctx);
  return 0;
}

// initialization
void kk_samples_basic_caesar__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core__list _x1468;
    kk_std_core__list _x1469;
    kk_std_core__list _x1470;
    kk_std_core__list _x1471;
    kk_std_core__list _x1472;
    kk_std_core__list _x1473;
    kk_std_core__list _x1474;
    kk_std_core__list _x1475;
    kk_std_core__list _x1476;
    kk_std_core__list _x1477;
    kk_std_core__list _x1478;
    kk_std_core__list _x1479;
    kk_std_core__list _x1480;
    kk_std_core__list _x1481;
    kk_std_core__list _x1482;
    kk_std_core__list _x1483;
    kk_std_core__list _x1484;
    kk_std_core__list _x1485;
    kk_std_core__list _x1486;
    kk_std_core__list _x1487;
    kk_std_core__list _x1488;
    kk_std_core__list _x1489;
    kk_std_core__list _x1490;
    kk_std_core__list _x1491;
    kk_std_core__list _x1492 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0.1, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<1009>*/
    _x1491 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.0, _ctx), _x1492, _ctx); /*list<1009>*/
    _x1490 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0.2, _ctx), _x1491, _ctx); /*list<1009>*/
    _x1489 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.4, _ctx), _x1490, _ctx); /*list<1009>*/
    _x1488 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(1.0, _ctx), _x1489, _ctx); /*list<1009>*/
    _x1487 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.8, _ctx), _x1488, _ctx); /*list<1009>*/
    _x1486 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(9.1, _ctx), _x1487, _ctx); /*list<1009>*/
    _x1485 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(6.3, _ctx), _x1486, _ctx); /*list<1009>*/
    _x1484 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(6.0, _ctx), _x1485, _ctx); /*list<1009>*/
    _x1483 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0.1, _ctx), _x1484, _ctx); /*list<1009>*/
    _x1482 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(1.9, _ctx), _x1483, _ctx); /*list<1009>*/
    _x1481 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(7.5, _ctx), _x1482, _ctx); /*list<1009>*/
    _x1480 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(6.7, _ctx), _x1481, _ctx); /*list<1009>*/
    _x1479 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.4, _ctx), _x1480, _ctx); /*list<1009>*/
    _x1478 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(4.0, _ctx), _x1479, _ctx); /*list<1009>*/
    _x1477 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0.8, _ctx), _x1478, _ctx); /*list<1009>*/
    _x1476 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0.2, _ctx), _x1477, _ctx); /*list<1009>*/
    _x1475 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(7.0, _ctx), _x1476, _ctx); /*list<1009>*/
    _x1474 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(6.1, _ctx), _x1475, _ctx); /*list<1009>*/
    _x1473 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.0, _ctx), _x1474, _ctx); /*list<1009>*/
    _x1472 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.2, _ctx), _x1473, _ctx); /*list<1009>*/
    _x1471 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(12.7, _ctx), _x1472, _ctx); /*list<1009>*/
    _x1470 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(4.3, _ctx), _x1471, _ctx); /*list<1009>*/
    _x1469 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(2.8, _ctx), _x1470, _ctx); /*list<1009>*/
    _x1468 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(1.5, _ctx), _x1469, _ctx); /*list<1009>*/
    kk_samples_basic_caesar_english = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(8.2, _ctx), _x1468, _ctx); /*list<float64>*/
  }
}

// termination
void kk_samples_basic_caesar__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__list_drop(kk_samples_basic_caesar_english, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_core_types__done(_ctx);
}
