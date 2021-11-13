#ifndef __SXX_DEFS_H__
#define __SXX_DEFS_H__

// export lib
#ifdef WIN32
#ifdef SXX_STATIC_LIB
#define SXX_DECLARE(type)   type __stdcall
#else
#ifdef SXX_DYNAMIC_LIB
#define SXX_DECLARE(type)   __declspec(dllexport) type __stdcall
#else
#define SXX_DECLARE(type)   __declspec(dllimport) type __stdcall
#endif
#endif
#else
#define SXX_DECLARE(type) type
#endif

// extern c
#ifdef __cplusplus
#define SXX_EXTERN_C_BEGIN       extern "C" {
#define SXX_EXTERN_C_END         }
#else
#define SXX_EXTERN_C_BEGIN
#define SXX_EXTERN_C_END
#endif

// inline
#ifndef sxx_inline
#define sxx_inline      inline
#endif

// unused
#ifndef SXX_UNUSED_ARG
#define SXX_UNUSED_ARG(arg)  (void)arg
#endif

#endif // !__SXX_DEFS_H__
