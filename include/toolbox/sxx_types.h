#ifndef __SXX_TYPES_H__
#define __SXX_TYPES_H__
#include <stdio.h>

typedef int sxx_status_t;

#define SXX_SUCCESS 0
#define SXX_ERROR -1
#define SXX_SUCCESSED(status) ((status) == SXX_SUCCESS)
#define SXX_ERRORED(status) ((status) == SXX_FAILED)

typedef int sxx_bool_t;

#define SXX_TRUE  1
#define SXX_FALSE 0

typedef void sxx_void_t;

typedef void* sxx_ptr_t;

typedef unsigned int sxx_size_t;

typedef char sxx_char_t;
typedef unsigned char sxx_uchar_t;

typedef char    sxx_int8_t;
typedef short   sxx_int16_t;
typedef int     sxx_int32_t;
typedef long    sxx_int64_t;
typedef unsigned char   sxx_uint8_t;
typedef unsigned short  sxx_uint16_t;
typedef unsigned int    sxx_uint32_t;
typedef unsigned long   sxx_uint64_t;

#endif // !__SXX_TYPES_H__ 
