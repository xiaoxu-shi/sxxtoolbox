#include <windows.h>
#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_string.h"
#include "sxx_dso.h"

struct sxx_dso_t {
    sxx_memory_pool_t*  pool;
    HINSTANCE           handle;
    sxx_string_t        path;
    sxx_string_t        error;
};

static sxx_status_t sxx_dlerror(sxx_dso_t *dh)
{
    LPSTR messageBuffer = NULL;
    DWORD errorMessageID = GetLastError();
    if(errorMessageID == 0)
        return SXX_SUCCESS;

    sxx_size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER
     | FORMAT_MESSAGE_FROM_SYSTEM
     | FORMAT_MESSAGE_IGNORE_INSERTS,
     NULL, errorMessageID,
     MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPSTR)&messageBuffer, 0, NULL);

    sxx_assert_on_fail(sxx_string_assign_cstr(dh->pool, &dh->error, messageBuffer), SXX_ERROR);

    LocalFree(messageBuffer);

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_create(sxx_memory_pool_t* pool, sxx_const_char_t* path, sxx_dso_t** dso)
{
    sxx_dso_t *dh = sxx_memory_calloc(pool, sxx_sizeof(sxx_dso_t));
    sxx_assert_return_val(dh, SXX_ERROR);

    dh->pool = pool;
    sxx_string_null(&dh->error);
    sxx_string_assign_cstr(pool, &dh->path, (sxx_char_t*)path);
    dh->handle = LoadLibraryEx(path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!dh->handle) { 
        dh->handle = LoadLibraryEx(path, NULL, 0);
        sxx_assert_on_fail(dh->handle, sxx_dlerror(dh));
    }
    *dso = dh;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_t *dso, sxx_const_char_t *symname, sxx_dso_sym_t *sym)
{
    sxx_dso_sym_t _sym = GetProcAddress(dso->handle, symname);
    sxx_assert_on_fail_and_retval(_sym, sxx_dlerror(dso), SXX_ERROR);
    *sym = _sym;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_t *dso)
{
    if (dso->handle != NULL && !FreeLibrary(dso->handle)) {
        sxx_dlerror(dso);
        return SXX_ERROR;
    }
    dso->handle = NULL;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_t *dso, sxx_string_t *error)
{
    sxx_assert_return_val(sxx_string_assign(dso->pool, error, &dso->error), NULL);

    return sxx_string_buffer(error);
}