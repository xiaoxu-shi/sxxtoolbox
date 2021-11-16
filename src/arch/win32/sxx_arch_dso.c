#include <windows.h>
#include "sxx_cstr.h"
#include "sxx_assert.h"
#include "sxx_string.h"
#include "sxx_dso.h"

struct sxx_dso_handle_t {
    sxx_memory_pool_t*  pool;
    HINSTANCE           handle;
    sxx_string_t        path;
    sxx_string_t        error;
};

static sxx_status_t sxx_dlerror(sxx_dso_handle_t *dh)
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

SXX_DECLARE(sxx_status_t) sxx_dso_create(sxx_memory_pool_t* pool, sxx_const_char_t* path, sxx_dso_handle_t** handle)
{
    sxx_dso_handle_t *dh = sxx_memory_calloc(pool, sxx_sizeof(sxx_dso_handle_t));
    sxx_assert_return_val(dh, SXX_ERROR);

    dh->pool = pool;
    sxx_string_null(&dh->error);
    sxx_string_assign_cstr(pool, &dh->path, (sxx_char_t*)path);
    dh->handle = LoadLibraryEx(path, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!dh->handle) { 
        dh->handle = LoadLibraryEx(path, NULL, 0);
        sxx_assert_on_fail(dh->handle, sxx_dlerror(dh));
    }
    *handle = dh;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_sym(sxx_dso_handle_t *handle, sxx_const_char_t *symname, sxx_dso_sym_t *sym)
{
    sxx_dso_sym_t _sym = GetProcAddress(handle->handle, symname);
    sxx_assert_on_fail_and_retval(_sym, sxx_dlerror(handle), SXX_ERROR);
    *sym = _sym;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_status_t) sxx_dso_destory(sxx_dso_handle_t *handle)
{
    if (handle->handle != NULL && !FreeLibrary(handle->handle)) {
        sxx_dlerror(handle);
        return SXX_ERROR;
    }
    handle->handle = NULL;

    return SXX_SUCCESS;
}

SXX_DECLARE(sxx_const_char_t *) sxx_dso_error(sxx_dso_handle_t *handle, sxx_string_t *error)
{
    sxx_assert_return_val(sxx_string_assign(handle->pool, error, &handle->error), NULL);

    return sxx_string_buffer(error);
}