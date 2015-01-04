/*
 * Copyright (c) 2005 Jose F. Nieves <nieves@ltp.uprrp..edu>
 *
 * See LICENSE
 *
 * $Id: unz.h,v 79a0587444a1 2015/01/02 23:28:10 nieves $
 */
#ifndef UNZ_H
#define UNZ_H

int unz(char *out, int *outlen, char *in, int inlen);
int zip(char **out, int *outlen, char *in, int inlen, int level);

#endif
