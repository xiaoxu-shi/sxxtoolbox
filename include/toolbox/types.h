#ifndef __SXX_TYPES_H__
#define __SXX_TYPES_H__

typedef int sxx_status_t;

#define SXX_SUCCESS 0
#define SXX_ERROR -1
#define SXX_SUCCESSED(status) ((status) == SXX_SUCCESS)
#define SXX_ERRORED(status) ((status) == SXX_FAILED)

typedef int sxx_bool_t;

#define SXX_TRUE  1
#define SXX_FALSE 0

#endif // !__SXX_TYPES_H__ 
