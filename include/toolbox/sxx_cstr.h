#ifndef __SXX_CSTR_H__
#define __SXX_CSTR_H__
#include <string.h>
#include "toolbox/sxx_defs.h"
#include "toolbox/sxx_types.h"

SXX_EXTERN_C_BEGIN

#define SXX_USE_ANSI

#define sxx_ansi_strcmp		    strcmp
#define sxx_ansi_strncmp	    strncmp
#define sxx_ansi_strlen		    strlen
#define sxx_ansi_sizeof		    sizeof
#define sxx_ansi_strcpy		    strcpy
#define sxx_ansi_strncpy	    strncpy
#define sxx_ansi_strcat		    strcat
#define sxx_ansi_strstr		    strstr
#define sxx_ansi_strchr		    strchr
#define sxx_ansi_strcasecmp	    strcasecmp
#define sxx_ansi_stricmp	    strcasecmp
#define sxx_ansi_strncasecmp    strncasecmp
#define sxx_ansi_strnicmp	    strncasecmp
#define sxx_ansi_sprintf	    sprintf
#define sxx_ansi_snprintf	    snprintf
#define sxx_ansi_vsprintf	    vsprintf
#define sxx_ansi_vsnprintf	    vsnprintf

#ifdef SXX_USE_ANSI
#define sxx_sizeof(b)       sxx_ansi_sizeof(b)
#define sxx_strlen(s)       sxx_ansi_strlen(s)
#define sxx_strcpy(d,s)     sxx_ansi_strcpy(d,s)
#define sxx_strncpy(d,s,n)  sxx_ansi_strncpy(d,s,n)
#define sxx_strcmp(s1,s2)   sxx_ansi_strcmp(s1,s2)
#define sxx_strncmp(s1,s2)  sxx_ansi_strncmp(s1,s2)
#endif

SXX_EXTERN_C_END

#endif // ! __SXX_CSTR_H__
