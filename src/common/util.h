/*
 * Copyright (c) 2005 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: util.h,v ff74993871f7 2011/01/17 22:56:45 nieves $
 */
#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

int strto_int(char *s, int *val);
int strto_uint(char *s, unsigned int *val);
int strto_double(char *s, double *val);
int strto_u16(char *s, uint16_t *val);
int strto_u32(char *s, uint32_t *val);

#endif
