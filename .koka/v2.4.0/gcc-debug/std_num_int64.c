// Koka generated module: "std/num/int64", koka version: 2.4.0, platform: 64-bit
#include "std_num_int64.h"
 
// Show an `:int64` in hexadecimal notation
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_num_int64_show_hex(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_integer_t _x1812 = kk_integer_from_int64(i,kk_context()); /*int*/
  kk_std_core_types__optional _x1813;
  kk_box_t _x1814;
  kk_integer_t _x1815;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x1694 = width._cons.Optional.value;
    kk_integer_t _width_173 = kk_integer_unbox(_box_x1694);
    _x1815 = _width_173; /*int*/
  }
  else {
    _x1815 = kk_integer_from_small(1); /*int*/
  }
  _x1814 = kk_integer_box(_x1815); /*112*/
  _x1813 = kk_std_core_types__new_Optional(_x1814, _ctx); /*optional<112>*/
  kk_std_core_types__optional _x1817;
  kk_box_t _x1818;
  bool _x1819;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x1696 = use_capitals._cons.Optional.value;
    bool _use_capitals_177 = kk_bool_unbox(_box_x1696);
    _x1819 = _use_capitals_177; /*bool*/
  }
  else {
    _x1819 = true; /*bool*/
  }
  _x1818 = kk_bool_box(_x1819); /*112*/
  _x1817 = kk_std_core_types__new_Optional(_x1818, _ctx); /*optional<112>*/
  kk_std_core_types__optional _x1821;
  kk_box_t _x1822;
  kk_string_t _x1823;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x1698 = pre._cons.Optional.value;
    kk_string_t _pre_181 = kk_string_unbox(_box_x1698);
    _x1823 = _pre_181; /*string*/
  }
  else {
    kk_define_string_literal(, _s1825, 2, "0x")
    _x1823 = kk_string_dup(_s1825); /*string*/
  }
  _x1822 = kk_string_box(_x1823); /*112*/
  _x1821 = kk_std_core_types__new_Optional(_x1822, _ctx); /*optional<112>*/
  return kk_std_core_show_hex(_x1812, _x1813, _x1817, _x1821, _ctx);
}

int64_t kk_std_num_int64_one;

int64_t kk_std_num_int64_zero;
 
// The maximal integer value before overflow happens

int64_t kk_std_num_int64_max_int64;
 
// Convert an `:int` to `:int64` but interpret the `int` as an unsigned 64-bit value.
// `i` is clamped between `0` and `0xFFFF_FFFF_FFFF_FFFF`.
// `0x7FFF_FFFF_FFFF_FFFF.uint64 == 0x7FFF_FFFF_FFFF_FFFF.int64 == max-int64`
// `0x8000_0000_0000_0000.uint64 == -0x8000_0000_0000_0000.int64 == min-int64`
// `0xFFFF_FFFF_FFFF_FFFF.uint64 == -1.int64`

int64_t kk_std_num_int64_uint64_1(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int64 */ 
  kk_integer_t _x1830;
  bool _match_1802;
  kk_integer_t _brw_1803 = kk_integer_from_int64(kk_std_num_int64_max_int64,kk_context()); /*int*/;
  bool _brw_1804 = kk_integer_gt_borrow(i,_brw_1803,kk_context()); /*bool*/;
  kk_integer_drop(_brw_1803, _ctx);
  _match_1802 = _brw_1804; /*bool*/
  if (_match_1802) {
    _x1830 = kk_integer_sub(i,(kk_integer_from_str("18446744073709551616", _ctx)),kk_context()); /*int*/
  }
  else {
    _x1830 = i; /*int*/
  }
  return kk_std_core_int64(_x1830, _ctx);
}
 
// The minimal integer value before underflow happens

int64_t kk_std_num_int64_min_int64;
 
// Euclidean-0 modulus. See `(/):(x : int64, y : int64) -> int64` division for more information.

int64_t kk_std_num_int64__lp__perc__rp_(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> int64 */ 
  bool _match_1795;
  int64_t _x1831 = (KK_I64(0)); /*int64*/
  _match_1795 = (y == _x1831); /*bool*/
  if (_match_1795) {
    return x;
  }
  {
    bool _match_1796;
    int64_t _x1832 = (KK_I64(-1)); /*int64*/
    _match_1796 = (y == _x1832); /*bool*/
    if (_match_1796) {
      bool _match_1799 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_1799) {
        return (KK_I64(0));
      }
      {
        int64_t r = x % y; /*int64*/;
        bool _match_1800;
        int64_t _x1833 = (KK_I64(0)); /*int64*/
        _match_1800 = (r >= _x1833); /*bool*/
        if (_match_1800) {
          return r;
        }
        {
          bool _match_1801;
          int64_t _x1834 = (KK_I64(0)); /*int64*/
          _match_1801 = (y > _x1834); /*bool*/
          if (_match_1801) {
            return (int64_t)((uint64_t)r + (uint64_t)y);
          }
          {
            return (int64_t)((uint64_t)r - (uint64_t)y);
          }
        }
      }
    }
    {
      int64_t r0 = x % y; /*int64*/;
      bool _match_1797;
      int64_t _x1835 = (KK_I64(0)); /*int64*/
      _match_1797 = (r0 >= _x1835); /*bool*/
      if (_match_1797) {
        return r0;
      }
      {
        bool _match_1798;
        int64_t _x1836 = (KK_I64(0)); /*int64*/
        _match_1798 = (y > _x1836); /*bool*/
        if (_match_1798) {
          return (int64_t)((uint64_t)r0 + (uint64_t)y);
        }
        {
          return (int64_t)((uint64_t)r0 - (uint64_t)y);
        }
      }
    }
  }
}
 
/*
Euclidean-0 division.
Euclidean division is defined as: For any `D`  and `d`  where `d!=0` , we have:
1. `D == d*(D/d) + (D%d)`
2. `D%d`  is always positive where `0 <= D%d < abs(d)`
Moreover, Euclidean-0 is a total function, for the case where `d==0`  we have
that `D%0 == D`  and `D/0 == 0` . So property (1) still holds, but not property (2).
Useful laws that hold for Euclidean-0 division:
* `D/(-d) == -(D/d)`
* `D%(-d) == D%d`
* `D/(2^n) == sar(D,n)         `  (with `0 <= n <= 31`)
* `D%(2^n) == D & ((2^n) - 1)  `  (with `0 <= n <= 31`)
Note that an interesting edge case is `min-int64 / -1` which equals `min-int64` since in modulo 64-bit
arithmetic `min-int64 == -1 * min-int64 == -1 * (min-int64 / -1) + (min-int64 % -1)` satisfying property (1).
Of course `(min-int64 + 1) / -1` is again positive (namely `max-int64`).
See also _Division and modulus for computer scientists, Daan Leijen, 2001_
[pdf](http://research.microsoft.com/pubs/151917/divmodnote.pdf) .
*/

int64_t kk_std_num_int64__lp__fs__rp_(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> int64 */ 
  bool _match_1788;
  int64_t _x1839 = (KK_I64(0)); /*int64*/
  _match_1788 = (y == _x1839); /*bool*/
  if (_match_1788) {
    return (KK_I64(0));
  }
  {
    bool _match_1789;
    int64_t _x1840 = (KK_I64(-1)); /*int64*/
    _match_1789 = (y == _x1840); /*bool*/
    if (_match_1789) {
      bool _match_1792 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_1792) {
        return x;
      }
      {
        int64_t q = x / y; /*int64*/;
        int64_t r = x % y; /*int64*/;
        bool _match_1793;
        int64_t _x1841 = (KK_I64(0)); /*int64*/
        _match_1793 = (r >= _x1841); /*bool*/
        if (_match_1793) {
          return q;
        }
        {
          bool _match_1794;
          int64_t _x1842 = (KK_I64(0)); /*int64*/
          _match_1794 = (y > _x1842); /*bool*/
          if (_match_1794) {
            int64_t _x1843 = (KK_I64(1)); /*int64*/
            return (int64_t)((uint64_t)q - (uint64_t)_x1843);
          }
          {
            int64_t _x1844 = (KK_I64(1)); /*int64*/
            return (int64_t)((uint64_t)q + (uint64_t)_x1844);
          }
        }
      }
    }
    {
      int64_t q0 = x / y; /*int64*/;
      int64_t r0 = x % y; /*int64*/;
      bool _match_1790;
      int64_t _x1845 = (KK_I64(0)); /*int64*/
      _match_1790 = (r0 >= _x1845); /*bool*/
      if (_match_1790) {
        return q0;
      }
      {
        bool _match_1791;
        int64_t _x1846 = (KK_I64(0)); /*int64*/
        _match_1791 = (y > _x1846); /*bool*/
        if (_match_1791) {
          int64_t _x1847 = (KK_I64(1)); /*int64*/
          return (int64_t)((uint64_t)q0 - (uint64_t)_x1847);
        }
        {
          int64_t _x1848 = (KK_I64(1)); /*int64*/
          return (int64_t)((uint64_t)q0 + (uint64_t)_x1848);
        }
      }
    }
  }
}
 
// Return the absolute value of an integer.
// Raises an exception if the `:int64` is `min-int64`
// (since the negation of `min-int64` equals itself and is still negative)


// lift anonymous function
struct kk_std_num_int64_abs_fun1851__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_int64_abs_fun1851(kk_function_t _fself, kk_box_t _b_1705, kk_context_t* _ctx);
static kk_function_t kk_std_num_int64_new_abs_fun1851(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_int64_abs_fun1851, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_int64_abs_fun1851(kk_function_t _fself, kk_box_t _b_1705, kk_context_t* _ctx) {
  kk_unused(_fself);
  bool _x1852;
  bool b_1712 = kk_bool_unbox(_b_1705); /*bool*/;
  if (b_1712) {
    _x1852 = false; /*bool*/
  }
  else {
    _x1852 = true; /*bool*/
  }
  return kk_bool_box(_x1852);
}

int64_t kk_std_num_int64_abs(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> exn int64 */ 
  bool _x1_1688 = 0 > i; /*bool*/;
  bool _match_1786;
  kk_box_t _x1850 = kk_std_core_hnd__open_none1(kk_std_num_int64_new_abs_fun1851(_ctx), kk_bool_box(_x1_1688), _ctx); /*3357*/
  _match_1786 = kk_bool_unbox(_x1850); /*bool*/
  if (_match_1786) {
    return i;
  }
  {
    bool _match_1787 = (i > kk_std_num_int64_min_int64); /*bool*/;
    if (_match_1787) {
      int64_t _x1853 = (KK_I64(0)); /*int64*/
      return (int64_t)((uint64_t)_x1853 - (uint64_t)i);
    }
    {
      kk_box_t _x1854;
      kk_string_t _x1855;
      kk_define_string_literal(, _s1856, 79, "std/num/int64/abs: cannot make min-int64 into a positive int64 without overflow")
      _x1855 = kk_string_dup(_s1856); /*string*/
      _x1854 = kk_std_core_throw(_x1855, kk_std_core_types__new_None(_ctx), _ctx); /*11728*/
      return kk_int64_unbox(_x1854, _ctx);
    }
  }
}
 
// Return the absolute value of an integer.
// Returns 0 if the `:int64` is `min-int64`
// (since the negation of `min-int64` equals itself and is still negative)

int64_t kk_std_num_int64_abs0(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int64 */ 
  bool b_1663 = 0 > i; /*bool*/;
  if (b_1663) {
    bool _match_1785 = (i > kk_std_num_int64_min_int64); /*bool*/;
    if (_match_1785) {
      int64_t _x1857 = (KK_I64(0)); /*int64*/
      return (int64_t)((uint64_t)_x1857 - (uint64_t)i);
    }
    {
      return (KK_I64(0));
    }
  }
  {
    return i;
  }
}
 
// The number of bits in an `:int64` (always 64)

int64_t kk_std_num_int64_bits_int64;
 
// Truncated division (as in C). See also `(/):(x : int64, y : int64) -> int64`.

int64_t kk_std_num_int64_cdiv(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> exn int64 */ 
  bool _match_1782 = 0 == j; /*bool*/;
  if (_match_1782) {
    kk_box_t _x1858;
    kk_string_t _x1859;
    kk_define_string_literal(, _s1860, 36, "std/num/int64/cdiv: division by zero")
    _x1859 = kk_string_dup(_s1860); /*string*/
    _x1858 = kk_std_core_throw(_x1859, kk_std_core_types__new_None(_ctx), _ctx); /*11728*/
    return kk_int64_unbox(_x1858, _ctx);
  }
  {
    bool _match_1783;
    int64_t _x1861 = (KK_I64(-1)); /*int64*/
    _match_1783 = (j == _x1861); /*bool*/
    if (_match_1783) {
      bool _match_1784 = (i == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_1784) {
        kk_box_t _x1862;
        kk_string_t _x1863;
        kk_define_string_literal(, _s1864, 66, "std/num/int64/cdiv: division overflow in cdiv(min-int64, -1.int64)")
        _x1863 = kk_string_dup(_s1864); /*string*/
        _x1862 = kk_std_core_throw(_x1863, kk_std_core_types__new_None(_ctx), _ctx); /*11728*/
        return kk_int64_unbox(_x1862, _ctx);
      }
      {
        return i / j;
      }
    }
    {
      return i / j;
    }
  }
}
 
// Truncated modulus (as in C). See also `(%):(x : int64, y : int64) -> int64`.

int64_t kk_std_num_int64_cmod(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> exn int64 */ 
  bool _match_1779 = 0 == j; /*bool*/;
  if (_match_1779) {
    kk_box_t _x1865;
    kk_string_t _x1866;
    kk_define_string_literal(, _s1867, 35, "std/num/int64/cmod: modulus by zero")
    _x1866 = kk_string_dup(_s1867); /*string*/
    _x1865 = kk_std_core_throw(_x1866, kk_std_core_types__new_None(_ctx), _ctx); /*11728*/
    return kk_int64_unbox(_x1865, _ctx);
  }
  {
    bool _match_1780;
    int64_t _x1868 = (KK_I64(-1)); /*int64*/
    _match_1780 = (j == _x1868); /*bool*/
    if (_match_1780) {
      bool _match_1781 = (i == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_1781) {
        kk_box_t _x1869;
        kk_string_t _x1870;
        kk_define_string_literal(, _s1871, 65, "std/num/int64/cmod: modulus overflow in cmod(min-int64, -1.int64)")
        _x1870 = kk_string_dup(_s1871); /*string*/
        _x1869 = kk_std_core_throw(_x1870, kk_std_core_types__new_None(_ctx), _ctx); /*11728*/
        return kk_int64_unbox(_x1869, _ctx);
      }
      {
        return i % j;
      }
    }
    {
      return i % j;
    }
  }
}

kk_std_core_types__tuple2_ kk_std_num_int64_divmod(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> (int64, int64) */ 
  bool _match_1772 = 0 == y; /*bool*/;
  if (_match_1772) {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(kk_std_num_int64_zero, _ctx), kk_int64_box(x, _ctx), _ctx);
  }
  {
    bool _match_1773;
    int64_t _x1872 = (KK_I64(-1)); /*int64*/
    _match_1773 = (y == _x1872); /*bool*/
    if (_match_1773) {
      bool _match_1776 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_1776) {
        int64_t _b_1748_1732 = (KK_I64(0)); /*int64*/;
        return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(x, _ctx), kk_int64_box(_b_1748_1732, _ctx), _ctx);
      }
      {
        int64_t q = x / y; /*int64*/;
        int64_t r = x % y; /*int64*/;
        bool _match_1777;
        int64_t _x1873 = (KK_I64(0)); /*int64*/
        _match_1777 = (r >= _x1873); /*bool*/
        if (_match_1777) {
          return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(q, _ctx), kk_int64_box(r, _ctx), _ctx);
        }
        {
          bool _match_1778;
          int64_t _x1874 = (KK_I64(0)); /*int64*/
          _match_1778 = (y > _x1874); /*bool*/
          if (_match_1778) {
            int64_t _b_1751_1735;
            int64_t _x1875 = (KK_I64(1)); /*int64*/
            _b_1751_1735 = (int64_t)((uint64_t)q - (uint64_t)_x1875); /*int64*/
            int64_t _b_1752_1736 = (int64_t)((uint64_t)r + (uint64_t)y); /*int64*/;
            return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(_b_1751_1735, _ctx), kk_int64_box(_b_1752_1736, _ctx), _ctx);
          }
          {
            int64_t _b_1753_1737;
            int64_t _x1876 = (KK_I64(1)); /*int64*/
            _b_1753_1737 = (int64_t)((uint64_t)q + (uint64_t)_x1876); /*int64*/
            int64_t _b_1754_1738 = (int64_t)((uint64_t)r - (uint64_t)y); /*int64*/;
            return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(_b_1753_1737, _ctx), kk_int64_box(_b_1754_1738, _ctx), _ctx);
          }
        }
      }
    }
    {
      int64_t q0 = x / y; /*int64*/;
      int64_t r0 = x % y; /*int64*/;
      bool _match_1774;
      int64_t _x1877 = (KK_I64(0)); /*int64*/
      _match_1774 = (r0 >= _x1877); /*bool*/
      if (_match_1774) {
        return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(q0, _ctx), kk_int64_box(r0, _ctx), _ctx);
      }
      {
        bool _match_1775;
        int64_t _x1878 = (KK_I64(0)); /*int64*/
        _match_1775 = (y > _x1878); /*bool*/
        if (_match_1775) {
          int64_t _b_1757_1741;
          int64_t _x1879 = (KK_I64(1)); /*int64*/
          _b_1757_1741 = (int64_t)((uint64_t)q0 - (uint64_t)_x1879); /*int64*/
          int64_t _b_1758_1742 = (int64_t)((uint64_t)r0 + (uint64_t)y); /*int64*/;
          return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(_b_1757_1741, _ctx), kk_int64_box(_b_1758_1742, _ctx), _ctx);
        }
        {
          int64_t _b_1759_1743;
          int64_t _x1880 = (KK_I64(1)); /*int64*/
          _b_1759_1743 = (int64_t)((uint64_t)q0 + (uint64_t)_x1880); /*int64*/
          int64_t _b_1760_1744 = (int64_t)((uint64_t)r0 - (uint64_t)y); /*int64*/;
          return kk_std_core_types__new_dash__lp__comma__rp_(kk_int64_box(_b_1759_1743, _ctx), kk_int64_box(_b_1760_1744, _ctx), _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_box_t kk_std_num_int64__mlift1689_fold_int64(int64_t end, kk_function_t f, int64_t start, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (end : int64, f : (int64, a) -> e a, start : int64, x : a) -> e a */ 
  int64_t _x1882;
  int64_t _x1883 = (KK_I64(1)); /*int64*/
  _x1882 = (int64_t)((uint64_t)start + (uint64_t)_x1883); /*int64*/
  return kk_std_num_int64_fold_int64(_x1882, end, x, f, _ctx);
}


// lift anonymous function
struct kk_std_num_int64_fold_int64_fun1885__t {
  struct kk_function_s _base;
  kk_function_t f0;
  int64_t end0;
  int64_t start0;
};
static kk_box_t kk_std_num_int64_fold_int64_fun1885(kk_function_t _fself, kk_box_t x1, kk_context_t* _ctx);
static kk_function_t kk_std_num_int64_new_fold_int64_fun1885(kk_function_t f0, int64_t end0, int64_t start0, kk_context_t* _ctx) {
  struct kk_std_num_int64_fold_int64_fun1885__t* _self = kk_function_alloc_as(struct kk_std_num_int64_fold_int64_fun1885__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_int64_fold_int64_fun1885, kk_context());
  _self->f0 = f0;
  _self->end0 = end0;
  _self->start0 = start0;
  return &_self->_base;
}

static kk_box_t kk_std_num_int64_fold_int64_fun1885(kk_function_t _fself, kk_box_t x1, kk_context_t* _ctx) {
  struct kk_std_num_int64_fold_int64_fun1885__t* _self = kk_function_as(struct kk_std_num_int64_fold_int64_fun1885__t*, _fself);
  kk_function_t f0 = _self->f0; /* (int64, 1428) -> 1429 1428 */
  int64_t end0 = _self->end0; /* int64 */
  int64_t start0 = _self->start0; /* int64 */
  kk_drop_match(_self, {kk_function_dup(f0);;;}, {}, _ctx)
  return kk_std_num_int64__mlift1689_fold_int64(end0, f0, start0, x1, _ctx);
}

kk_box_t kk_std_num_int64_fold_int64(int64_t start0, int64_t end0, kk_box_t init, kk_function_t f0, kk_context_t* _ctx) { /* forall<a,e> (start : int64, end : int64, init : a, f : (int64, a) -> e a) -> e a */ 
  kk__tailcall: ;
  bool _match_1770 = (start0 >= end0); /*bool*/;
  if (_match_1770) {
    kk_function_drop(f0, _ctx);
    return init;
  }
  {
    kk_box_t x0_1690;
    kk_function_t _x1884 = kk_function_dup(f0); /*(int64, 1428) -> 1429 1428*/
    x0_1690 = kk_function_call(kk_box_t, (kk_function_t, int64_t, kk_box_t, kk_context_t*), _x1884, (_x1884, start0, init, _ctx)); /*1428*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_1690, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_num_int64_new_fold_int64_fun1885(f0, end0, start0, _ctx), _ctx);
    }
    { // tailcall
      int64_t _x1886;
      int64_t _x1887 = (KK_I64(1)); /*int64*/
      _x1886 = (int64_t)((uint64_t)start0 + (uint64_t)_x1887); /*int64*/
      start0 = _x1886;
      init = x0_1690;
      goto kk__tailcall;
    }
  }
}
 
// Show an `:int64` in hexadecimal notation interpreted as an unsigned 64-bit value.
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number.

kk_string_t kk_std_num_int64_show_hex64(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int64, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_integer_t _x1894 = kk_std_num_int64_uint(i, _ctx); /*int*/
  kk_std_core_types__optional _x1895;
  kk_box_t _x1896;
  kk_integer_t _x1897;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x1761 = width._cons.Optional.value;
    kk_integer_t _width_1578 = kk_integer_unbox(_box_x1761);
    _x1897 = _width_1578; /*int*/
  }
  else {
    _x1897 = kk_integer_from_small(16); /*int*/
  }
  _x1896 = kk_integer_box(_x1897); /*112*/
  _x1895 = kk_std_core_types__new_Optional(_x1896, _ctx); /*optional<112>*/
  kk_std_core_types__optional _x1899;
  kk_box_t _x1900;
  bool _x1901;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x1763 = use_capitals._cons.Optional.value;
    bool _use_capitals_1582 = kk_bool_unbox(_box_x1763);
    _x1901 = _use_capitals_1582; /*bool*/
  }
  else {
    _x1901 = true; /*bool*/
  }
  _x1900 = kk_bool_box(_x1901); /*112*/
  _x1899 = kk_std_core_types__new_Optional(_x1900, _ctx); /*optional<112>*/
  kk_std_core_types__optional _x1903;
  kk_box_t _x1904;
  kk_string_t _x1905;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x1765 = pre._cons.Optional.value;
    kk_string_t _pre_1586 = kk_string_unbox(_box_x1765);
    _x1905 = _pre_1586; /*string*/
  }
  else {
    kk_define_string_literal(, _s1907, 2, "0x")
    _x1905 = kk_string_dup(_s1907); /*string*/
  }
  _x1904 = kk_string_box(_x1905); /*112*/
  _x1903 = kk_std_core_types__new_Optional(_x1904, _ctx); /*optional<112>*/
  return kk_std_core_show_hex(_x1894, _x1895, _x1899, _x1903, _ctx);
}

// initialization
void kk_std_num_int64__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_int64_one = (KK_I64(1)); /*int64*/
  }
  {
    kk_std_num_int64_zero = (KK_I64(0)); /*int64*/
  }
  {
    kk_std_num_int64_max_int64 = (KK_I64(9223372036854775807)); /*int64*/
  }
  {
    kk_std_num_int64_min_int64 = (INT64_MIN); /*int64*/
  }
  {
    kk_std_num_int64_bits_int64 = (KK_I64(64)); /*int64*/
  }
}

// termination
void kk_std_num_int64__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
