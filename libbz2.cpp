#include <assert.h>

#ifdef _MSC_VER
#pragma warning(disable: 4100 4127 4244)
#endif
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#define BZ2_STATICLIB
#define register

#include "../ext/bzip2/blocksort.c"
#include "../ext/bzip2/huffman.c"
#include "../ext/bzip2/crctable.c"
#include "../ext/bzip2/randtable.c"
#include "../ext/bzip2/compress.c"
#include "../ext/bzip2/decompress.c"
#include "../ext/bzip2/bzlib.c"

// required when compiling with BZ_NO_STDIO
void bz_internal_error(int errcode)
{
    assert(0 && errcode);
}
