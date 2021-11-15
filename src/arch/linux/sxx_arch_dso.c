#include <dlfcn.h>
#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_arch_dso.h"

SXX_DECLARE(sxx_dso_handle_t *) sxx_dso_create(sxx_memory_pool_t *pool, sxx_const_char_t *path)
{
    sxx_dso_handle_t *dh = sxx_memory_calloc(pool, sxx_sizeof(sxx_dso_handle_t));
    sxx_assert_return_val(dh, NULL);

    dh->pool = pool;
    sxx_string_null(&dh->error);
    sxx_string_assign_cstr(pool, &dh->path, (sxx_char_t*)path);
    dh->handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
    sxx_assert_on_fail(dh->handle, sxx_string_assign_cstr(pool, &dh->error, dlerror()));

    return dh;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_handle_t *handle, sxx_const_char_t *symname, sxx_dso_sym_t *sym)
{
    sxx_dso_sym_t _sym = dlsym(handle->handle, symname);
    if (_sym == NULL) {
        sxx_assert_return_val(sxx_string_assign_cstr(handle->pool, &handle->error, dlerror()), SXX_ERROR);
    }
    *sym = _sym;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_handle_t *handle)
{
    if (dlclose(handle) != 0) {
        sxx_assert_return_val(sxx_string_assign_cstr(handle->pool, &handle->error, dlerror()), SXX_ERROR); 
    }

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_handle_t *handle, sxx_string_t *error)
{
    sxx_assert_return_val(sxx_string_assign(handle->pool, error, &handle->error), NULL);

    return sxx_string_buffer(error);
}

