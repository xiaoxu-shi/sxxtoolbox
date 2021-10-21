#ifndef __SXX_DEFS_H__
#define __SXX_DEFS_H__

#ifdef _MSC_VER
	#ifdef SXXTB_STATIC
		#define SXXTB_EXPORT
	#else
		#ifdef SXXTB_EXPORTS
			#define SXXTB_EXPORT __declspec(dllexport)
		#else
			#define SXXTB_EXPORT __declspec(dllimport)
		#endif
	#endif
#else
	#define SXXTB_EXPORT
#endif


typedef int sxxtb_status_t

#define SXXTB_SUCCESS 0
#define SXXTB_IS_SUCCESS(status) ((status) == SXXTB_SUCCESS)

#endif // !__SXX_DEFS_H__
