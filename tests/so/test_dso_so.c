#include "test_dso_so.h"

SXX_DSO_DECLARE(sxx_int32_t) sxx_test_dso_add(sxx_int32_t n1, sxx_int32_t n2)
{
    return n1 + n2;
}
