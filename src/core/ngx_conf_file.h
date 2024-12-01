/*
 * Copyright (C) yanruibinghxu@gmail.com
 */
#ifndef _NGX_HTTP_CONF_FILE_H_INCLUDED_
#define _NGX_HTTP_CONF_FILE_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>

struct ngx_command_s {
    ngx_str_t     name;
    int           type;
    char       *(*set)(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
    int           conf;
    int           offset;
    void         *post;
};

#define ngx_null_command   { ngx_null_string, 0, NULL, 0, 0, NULL }

struct ngx_open_file_s {
    ngx_fd_t   fd;
    ngx_str_t  name;
#if 0
    /* e.g. append mode, error_log */
    int        flags;
    /* e.g. reopen db file */
    int      (*handler)(void *data, ngx_open_file_t *file);
    void      *data;
#endif
};

struct ngx_module_s {
    ngx_uint_t       ctx_index;
    ngx_uint_t       index;
    void            *ctx;
    ngx_command_t   *commands;
    ngx_uint_t       type;
    ngx_int_t      (*init_module)(ngx_cycle_t *cycle);
    ngx_int_t      (*init_process)(ngx_cycle_t *cycle);
#if 0
    ngx_int_t      (*init_thread)(ngx_cycle_t *cycle);
#endif
};

struct ngx_conf_s {
};

#endif