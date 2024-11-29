/*
 * Copyright (C) yanruibinghxu@gmail.com
 */

#ifndef _NGX_LOG_H_INCLUDED_
#define _NGX_LOG_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>

#define NGX_LOG_STDERR            0
#define NGX_LOG_EMERG             1
#define NGX_LOG_ALERT             2
#define NGX_LOG_CRIT              3
#define NGX_LOG_ERR               4
#define NGX_LOG_WARN              5
#define NGX_LOG_NOTICE            6
#define NGX_LOG_INFO              7
#define NGX_LOG_DEBUG             8

#define NGX_LOG_DEBUG_CORE        0x010
#define NGX_LOG_DEBUG_ALLOC       0x020
#define NGX_LOG_DEBUG_MUTEX       0x040
#define NGX_LOG_DEBUG_EVENT       0x080
#define NGX_LOG_DEBUG_HTTP        0x100
#define NGX_LOG_DEBUG_IMAP        0x200

/*
 * do not forget to update debug_levels[] in src/core/ngx_log.c
 * after the adding a new debug level
 */

#define NGX_LOG_DEBUG_FIRST       NGX_LOG_DEBUG_CORE
#define NGX_LOG_DEBUG_LAST        NGX_LOG_DEBUG_IMAP
#define NGX_LOG_DEBUG_CONNECTION  0x80000000
#define NGX_LOG_DEBUG_ALL         0x7ffffff0


typedef size_t  (*ngx_log_handler_pt) (void *ctx, char *buf, size_t len);


struct ngx_log_s {
    ngx_uint_t           log_level;
    void                *data;
    ngx_log_handler_pt   handler;
};

#endif