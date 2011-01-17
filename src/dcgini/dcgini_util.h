/*
 * Copyright (c) 2005-2010 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: dcgini_util.h,v ff74993871f7 2011/01/17 22:56:45 nieves $
 */
#ifndef DCGINI_UTIL_H
#define DCGINI_UTIL_H

#include <sys/types.h>

unsigned int dcgini_unpack_uint16(void *p, size_t start);
unsigned int dcgini_unpack_uint24(void *p, size_t start);
unsigned int dcgini_unpack_uint32(void *p, size_t start);
int dcgini_unpack_int24(void *p, size_t start);

#endif
