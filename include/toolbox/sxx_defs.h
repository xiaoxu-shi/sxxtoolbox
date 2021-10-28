#ifndef __SXX_DEFS_H__
#define __SXX_DEFS_H__

#ifdef _MSC_VER
	#ifdef SXX_STATIC
		#define SXX_EXPORT
	#else
		#ifdef SXX_EXPORTS
			#define SXX_EXPORT __declspec(dllexport)
		#else
			#define SXX_EXPORT __declspec(dllimport)
		#endif
	#endif
#else
	#define SXX_EXPORT
#endif

#ifdef __cplusplus
#define SXX_EXTERN_C_BEGIN       extern "C" {
#define SXX_EXTERN_C_END         }
#else
#define SXX_EXTERN_C_BEGIN
#define SXX_EXTERN_C_END
#endif

#ifndef sxx_inline
#define sxx_inline      inline
#endif

#endif // !__SXX_DEFS_H__
