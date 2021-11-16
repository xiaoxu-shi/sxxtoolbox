#include <dlfcn.h>
#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_dso.h"

struct sxx_dso_t {
    sxx_memory_pool_t*  pool;
    sxx_ptr_t           handle;
    sxx_string_t        path;
    sxx_string_t        error;
};

SXX_DECLARE(sxx_status_t ) sxx_dso_create(sxx_memory_pool_t *pool, sxx_const_char_t *path, sxx_dso_t **dso)
{
    sxx_dso_t *dh = sxx_memory_calloc(pool, sxx_sizeof(sxx_dso_t));
    sxx_assert_return_val(dh, SXX_ERROR);

    dh->pool = pool;
    sxx_string_null(&dh->error);
    sxx_string_assign_cstr(pool, &dh->path, (sxx_char_t*)path);
    dh->handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
    sxx_assert_on_fail(dh->handle, sxx_string_assign_cstr(pool, &dh->error, dlerror()));
    *dso = dh;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_t *dso, sxx_const_char_t *symname, sxx_dso_sym_t *sym)
{
    sxx_dso_sym_t _sym = dlsym(dso->handle, symname);
    if (_sym == NULL) {
        sxx_assert_return_val(sxx_string_assign_cstr(dso->pool, &dso->error, dlerror()), SXX_ERROR);
    }
    *sym = _sym;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_t *dso)
{
    sxx_assert_return_val(dso, SXX_ERROR);

    if (dlclose(dso->handle) != 0) {
        sxx_assert_return_val(sxx_string_assign_cstr(dso->pool, &dso->error, dlerror()), SXX_ERROR); 
    }

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_t *dso, sxx_string_t *error)
{
    sxx_assert_return_val(sxx_string_assign(dso->pool, error, &dso->error), NULL);

    return sxx_string_buffer(error);
}

