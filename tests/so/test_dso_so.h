#include "sxx_toolbox.h"


// export lib
#ifdef WIN32
#ifdef SXX_DSO_LIB
#define SXX_DSO_DECLARE(type)   __declspec(dllexport) type __stdcall
#else
#define SXX_DSO_DECLARE(type)   __declspec(dllimport) type __stdcall
#endif
#else
#define SXX_DSO_DECLARE(type) type
#endif

// extern c
#ifdef __cplusplus
extern "C" {
#endif

SXX_DSO_DECLARE(sxx_int32_t) sxx_test_dso_add(sxx_int32_t n1, sxx_int32_t n2);

#ifdef __cplusplus
}
#endif
