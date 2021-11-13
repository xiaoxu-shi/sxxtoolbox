#ifndef __SXX_TOOLBOX_ASSERT_H__
#define __SXX_TOOLBOX_ASSERT_H__

#ifndef sxx_assert
#define sxx_assert(expr)   assert(expr)
#endif

#ifndef sxx_assert_return
#define sxx_assert_return(expr, retval) \
    do { \
        if (!(expr)) { sxx_assert(expr); return (retval); } \
    } while (0)
#endif

#endif //! __SXX_TOOLBOX_ASSERT_H__
