#include <assert.h>

#ifdef _MSC_VER
#pragma warning(disable: 4100 4127 4244)
#endif
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#undef BZ2_STATICLIB
#define BZ2_STATICLIB
#define register

#include "./blocksort.c"
#include "./huffman.c"
#include "./crctable.c"
#include "./randtable.c"
#include "./compress.c"
#include "./decompress.c"
#include "./bzlib.c"

#if !defined(BUILD_MONOLITHIC)

// required when compiling with BZ_NO_STDIO
void bz_internal_error(int errcode)
{
    assert(0 && errcode);
}

#endif

