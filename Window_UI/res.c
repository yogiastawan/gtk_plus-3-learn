#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.res"), aligned (8)))
#else
# define SECTION
#endif

#ifdef _MSC_VER
static const SECTION union { const guint8 data[481]; const double alignment; void * const ptr;}  res_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0254, 0000, 0000, 0000, 0000, 0000, 0000, 0050, 0005, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 0002, 0000, 0000, 0000, 0004, 0000, 0000, 0000, 
  0004, 0000, 0000, 0000, 0135, 0201, 0333, 0112, 0004, 0000, 0000, 0000, 0254, 0000, 0000, 0000, 
  0011, 0000, 0114, 0000, 0270, 0000, 0000, 0000, 0274, 0000, 0000, 0000, 0324, 0265, 0002, 0000, 
  0377, 0377, 0377, 0377, 0274, 0000, 0000, 0000, 0001, 0000, 0114, 0000, 0300, 0000, 0000, 0000, 
  0304, 0000, 0000, 0000, 0302, 0257, 0211, 0013, 0001, 0000, 0000, 0000, 0304, 0000, 0000, 0000, 
  0004, 0000, 0114, 0000, 0310, 0000, 0000, 0000, 0314, 0000, 0000, 0000, 0301, 0337, 0360, 0215, 
  0000, 0000, 0000, 0000, 0314, 0000, 0000, 0000, 0011, 0000, 0166, 0000, 0330, 0000, 0000, 0000, 
  0315, 0001, 0000, 0000, 0130, 0154, 0041, 0113, 0002, 0000, 0000, 0000, 0315, 0001, 0000, 0000, 
  0014, 0000, 0114, 0000, 0334, 0001, 0000, 0000, 0340, 0001, 0000, 0000, 0167, 0151, 0156, 0144, 
  0157, 0167, 0165, 0151, 0057, 0000, 0000, 0000, 0003, 0000, 0000, 0000, 0057, 0000, 0000, 0000, 
  0002, 0000, 0000, 0000, 0143, 0157, 0155, 0057, 0004, 0000, 0000, 0000, 0167, 0151, 0156, 0144, 
  0157, 0167, 0056, 0165, 0151, 0000, 0000, 0000, 0013, 0002, 0000, 0000, 0001, 0000, 0000, 0000, 
  0170, 0332, 0225, 0221, 0313, 0116, 0303, 0060, 0020, 0105, 0367, 0375, 0212, 0301, 0133, 0344, 
  0046, 0210, 0255, 0343, 0356, 0170, 0110, 0054, 0101, 0135, 0042, 0307, 0236, 0222, 0241, 0123, 
  0273, 0330, 0116, 0003, 0177, 0017, 0251, 0151, 0051, 0042, 0022, 0260, 0263, 0356, 0234, 0361, 
  0325, 0321, 0250, 0305, 0353, 0206, 0141, 0207, 0061, 0121, 0360, 0215, 0270, 0230, 0327, 0142, 
  0241, 0147, 0212, 0174, 0306, 0270, 0062, 0026, 0365, 0014, 0100, 0235, 0111, 0011, 0307, 0104, 
  0106, 0174, 0351, 0051, 0142, 0202, 0247, 0274, 0076, 0207, 0313, 0171, 0015, 0122, 0356, 0261, 
  0320, 0076, 0243, 0315, 0100, 0256, 0021, 0003, 0171, 0027, 0006, 0001, 0226, 0115, 0112, 0215, 
  0270, 0316, 0353, 0145, 0111, 0106, 0360, 0003, 0335, 0306, 0260, 0305, 0230, 0337, 0300, 0233, 
  0015, 0066, 0142, 0107, 0211, 0132, 0106, 0241, 0357, 0143, 0217, 0252, 0072, 0114, 0247, 0341, 
  0114, 0171, 0104, 0313, 0207, 0360, 0160, 0373, 0033, 0337, 0206, 0350, 0060, 0312, 0201, 0134, 
  0356, 0204, 0256, 0177, 0340, 0266, 0043, 0166, 0345, 0375, 0135, 0242, 0103, 0346, 0300, 0246, 
  0105, 0076, 0025, 0271, 0333, 0007, 0007, 0376, 0237, 0056, 0123, 0013, 0245, 0101, 0337, 0214, 
  0155, 0260, 0014, 0221, 0335, 0137, 0266, 0254, 0361, 0217, 0253, 0140, 0373, 0044, 0364, 0225, 
  0341, 0064, 0321, 0244, 0252, 0342, 0362, 0251, 0131, 0035, 0075, 0277, 0006, 0252, 0072, 0071, 
  0364, 0073, 0117, 0224, 0247, 0054, 0000, 0050, 0165, 0165, 0141, 0171, 0051, 0171, 0157, 0147, 
  0151, 0141, 0163, 0164, 0141, 0167, 0141, 0156, 0057, 0000, 0000, 0000, 0000, 0000, 0000, 0000
} };
#else /* _MSC_VER */
static const SECTION union { const guint8 data[481]; const double alignment; void * const ptr;}  res_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\254\000\000\000\000\000\000\050\005\000\000\000"
  "\000\000\000\000\002\000\000\000\002\000\000\000\004\000\000\000"
  "\004\000\000\000\135\201\333\112\004\000\000\000\254\000\000\000"
  "\011\000\114\000\270\000\000\000\274\000\000\000\324\265\002\000"
  "\377\377\377\377\274\000\000\000\001\000\114\000\300\000\000\000"
  "\304\000\000\000\302\257\211\013\001\000\000\000\304\000\000\000"
  "\004\000\114\000\310\000\000\000\314\000\000\000\301\337\360\215"
  "\000\000\000\000\314\000\000\000\011\000\166\000\330\000\000\000"
  "\315\001\000\000\130\154\041\113\002\000\000\000\315\001\000\000"
  "\014\000\114\000\334\001\000\000\340\001\000\000\167\151\156\144"
  "\157\167\165\151\057\000\000\000\003\000\000\000\057\000\000\000"
  "\002\000\000\000\143\157\155\057\004\000\000\000\167\151\156\144"
  "\157\167\056\165\151\000\000\000\013\002\000\000\001\000\000\000"
  "\170\332\225\221\313\116\303\060\020\105\367\375\212\301\133\344"
  "\046\210\255\343\356\170\110\054\101\135\042\307\236\222\241\123"
  "\273\330\116\003\177\017\251\151\051\042\022\260\263\356\234\361"
  "\325\321\250\305\353\206\141\207\061\121\360\215\270\230\327\142"
  "\241\147\212\174\306\270\062\026\365\014\100\235\111\011\307\104"
  "\106\174\351\051\142\202\247\274\076\207\313\171\015\122\356\261"
  "\320\076\243\315\100\256\021\003\171\027\006\001\226\115\112\215"
  "\270\316\353\145\111\106\360\003\335\306\260\305\230\337\300\233"
  "\015\066\142\107\211\132\106\241\357\143\217\252\072\114\247\341"
  "\114\171\104\313\207\360\160\373\033\337\206\350\060\312\201\134"
  "\356\204\256\177\340\266\043\166\345\375\135\242\103\346\300\246"
  "\105\076\025\271\333\007\007\376\237\056\123\013\245\101\337\214"
  "\155\260\014\221\335\137\266\254\361\217\253\140\373\044\364\225"
  "\341\064\321\244\252\342\362\251\131\035\075\277\006\252\072\071"
  "\364\073\117\224\247\054\000\050\165\165\141\171\051\171\157\147"
  "\151\141\163\164\141\167\141\156\057\000\000\000\000\000\000\000"
  "" };
#endif /* !_MSC_VER */

static GStaticResource static_resource = { res_resource_data.data, sizeof (res_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };
extern GResource *res_get_resource (void);
GResource *res_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a usable way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for Win32 (x86) and x64 programs, as symbols on Win32 are prefixed
 * with an underscore but symbols on x64 are not.
 */
#ifdef _WIN64
#define G_MSVC_SYMBOL_PREFIX ""
#else
#define G_MSVC_SYMBOL_PREFIX "_"
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
