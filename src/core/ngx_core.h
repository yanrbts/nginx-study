/*
 * Copyright (C) yanruibinghxu@gmail.com
 */

#ifndef _NGX_CORE_H_INCLUDED_
#define _NGX_CORE_H_INCLUDED_

typedef struct ngx_pool_s        ngx_pool_t;
typedef struct ngx_log_s         ngx_log_t;

#define  NGX_OK          0
#define  NGX_ERROR      -1
#define  NGX_AGAIN      -2
#define  NGX_BUSY       -3
#define  NGX_DONE       -4
#define  NGX_DECLINED   -5
#define  NGX_ABORT      -6

#include <ngx_string.h>
#include <ngx_log.h>
#include <ngx_alloc.h>
#include <ngx_palloc.h>

#define LF     (u_char) 10
#define CR     (u_char) 13
#define CRLF   "\x0d\x0a"

#endif