#include <cstdio>

#if defined(_WIN32)
#define ARCH "Windows"
#elif defined(__linux__)
#define ARCH "Linux"
#else
#define ARCH "Unknown"
#endif

#if defined(__AVX512F__)
#define SIMD "AVX-512"
#elif defined(__AVX2__)
#define SIMD "AVX2"
#elif defined(__AVX__)
#define SIMD "AVX"
#elif defined(__SSE4_2__)
#define SIMD "SSE 4.2"
#elif defined(__SSE4_1__)
#define SIMD "SSE 4.1"
#elif defined(__SSSE3__)
#define SIMD "SSSE 3"
#elif defined(__SSE3__)
#define SIMD "SSE 3"
#elif defined(__SSE2__) or (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
#define SIMD "SSE 2"
#elif defined(__SSE__) or (defined(_M_IX86_FP) && _M_IX86_FP >= 1)
#define SIMD "SSE"
#elif defined(__MMX__)
#define SIMD "MMX"
#else
#define SIMD "none/unknown"
#endif

void env_check(FILE* fout) {
#if defined(__GNUC__)
  std::fprintf(fout, "GCC version: %d.%d.%d\n",
               __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_FULL_VER)
  std::fprintf(fout, "MSVC version: %d\n", int(_MSC_FULL_VER));
#endif
  std::fprintf(fout, "Architecture: %s %d-bit\n", ARCH, int(8 * sizeof(void*)));
  std::fprintf(fout, "SIMD: %s\n", SIMD);
}

int main() {
  env_check(stdout);
}
