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

#endif // !__SXX_DEFS_H__
