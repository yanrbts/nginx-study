/*
 * Copyright (C) yanruibinghxu@gmail.com
 */
#ifndef _NGX_HTTP_CONF_FILE_H_INCLUDED_
#define _NGX_HTTP_CONF_FILE_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>

/*
 *        AAAA  number of agruments
 *      FF      command flags
 *    TT        command type, i.e. HTTP "location" or "server" command
 */

#define NGX_CONF_NOARGS      0x00000001
#define NGX_CONF_TAKE1       0x00000002
#define NGX_CONF_TAKE2       0x00000004
#define NGX_CONF_TAKE3       0x00000008
#define NGX_CONF_TAKE4       0x00000010
#define NGX_CONF_TAKE5       0x00000020
#define NGX_CONF_TAKE6       0x00000040
#define NGX_CONF_TAKE7       0x00000080

#define NGX_CONF_TAKE12      (NGX_CONF_TAKE1|NGX_CONF_TAKE2)
#define NGX_CONF_TAKE13      (NGX_CONF_TAKE1|NGX_CONF_TAKE3)

#define NGX_CONF_TAKE23      (NGX_CONF_TAKE2|NGX_CONF_TAKE3)

#define NGX_CONF_TAKE1234    (NGX_CONF_TAKE1|NGX_CONF_TAKE2|NGX_CONF_TAKE3   \
                              |NGX_CONF_TAKE4)

#define NGX_CONF_ARGS_NUMBER 0x000000ff
#define NGX_CONF_BLOCK       0x00000100
#define NGX_CONF_FLAG        0x00000200
#define NGX_CONF_ANY         0x00000400
#define NGX_CONF_1MORE       0x00000800
#define NGX_CONF_2MORE       0x00001000

#define NGX_DIRECT_CONF      0x00010000

#define NGX_MAIN_CONF        0x01000000
#define NGX_ANY_CONF         0x0F000000



#define NGX_CONF_UNSET       -1
#define NGX_CONF_UNSET_UINT  (ngx_uint_t) -1
#define NGX_CONF_UNSET_PTR   (void *) -1
#define NGX_CONF_UNSET_SIZE  (size_t) -1
#define NGX_CONF_UNSET_MSEC  (ngx_msec_t) -1


#define NGX_CONF_OK          NULL
#define NGX_CONF_ERROR       (void *) -1

#define NGX_CONF_BLOCK_DONE  1
#define NGX_CONF_FILE_DONE   2

#define NGX_MODULE           0, 0

#define NGX_CORE_MODULE      0x45524F43  /* "CORE" */
#define NGX_CONF_MODULE      0x464E4F43  /* "CONF" */


#define NGX_MAX_CONF_ERRSTR  256

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

typedef struct {
    ngx_str_t       name;
    void           *(*create_conf)(ngx_cycle_t *cycle);
    char           *(*init_conf)(ngx_cycle_t *cycle, void *conf);
} ngx_core_module_t;

struct ngx_conf_s {
};

#endif