#ifndef __SXX_TOOLBOX_ASSERT_H__
#define __SXX_TOOLBOX_ASSERT_H__
#include <assert.h>

#ifndef sxx_assert
#define sxx_assert(expr)   assert(expr)
#endif

#ifndef sxx_assert_return
#define sxx_assert_return(expr) \
    do { \
        if (!(expr)) { sxx_assert(expr); return; } \
    } while (0)
#endif

#ifndef sxx_assert_return_val
#define sxx_assert_return_val(expr, retval) \
    do { \
        if (!(expr)) { sxx_assert(expr); return (retval); } \
    } while (0)
#endif

#ifndef sxx_assert_on_fail
#define sxx_assert_on_fail(expr, func) \
    do { \
        if (!(expr)) { sxx_assert(expr); func; } \
    } while (0)
#endif

#ifndef sxx_assert_goto
#define sxx_assert_goto(expr, pos) \
    do { \
        if (!(expr)) { sxx_assert(expr); goto pos; } \
    } while (0)
#endif

#endif //! __SXX_TOOLBOX_ASSERT_H__
