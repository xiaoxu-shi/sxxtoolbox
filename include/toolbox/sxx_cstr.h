#ifndef __SXX_CSTR_H__
#define __SXX_CSTR_H__
#include <string.h>
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

#define sxx_sizeof(b)       sizeof(b)
#define sxx_strlen(s)       strlen(s)
#define sxx_strncpy(d,s,n)  strncpy(d,s,n)

SXX_EXTERN_C_END

#endif // ! __SXX_CSTR_H__
