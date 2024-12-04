/*
 * Copyright (C) yanruibinghxu@gmail.com
 */

#include <ngx_config.h>
#include <ngx_core.h>

static void ngx_log_write(ngx_log_t *log, char *errstr, size_t len);
static char *ngx_set_error_log(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static ngx_command_t ngx_errlog_commands[] = {
    {
        ngx_string("error_log"),
        NGX_MAIN_CONF|NGX_CONF_1MORE,
        ngx_set_error_log,
        0,
        0,
        NULL
    },
    ngx_null_command
};

static ngx_core_module_t  ngx_errlog_module_ctx = {
    ngx_string("errlog"),
    NULL,                           
    NULL
};

ngx_module_t ngx_errlog_module = {
    NGX_MODULE,
    &ngx_errlog_module_ctx,                /* module context */
    ngx_errlog_commands,                   /* module directives */
    NGX_CORE_MODULE,                       /* module type */
    NULL,                                  /* init module */
    NULL                                   /* init child */
};

static ngx_log_t        ngx_log;
static ngx_open_file_t  ngx_stderr;

static const char *err_levels[] = {
    "stderr", "emerg", "alert", "crit", "error",
    "warn", "notice", "info", "debug"
};

static const char *debug_levels[] = {
    "debug_core", "debug_alloc", "debug_mutex", "debug_event",
    "debug_http", "debug_imap"
};

#if (HAVE_VARIADIC_MACROS)
void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t *err, 
                        const char *fmt, ...)
#else
void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
                        const char *fmt, va_list args)
#endif
{
    char    errstr[MAX_ERROR_STR];
    size_t  len, max;
#if (HAVE_VARIADIC_MACROS)
    va_list   args;
#endif

    if (log->file->fd == NGX_INVALID_FILE) {
        return;
    }

    ngx_memcpy();
}