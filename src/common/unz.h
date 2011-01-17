/*
 * Copyright (c) 2005 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: unz.h,v ff74993871f7 2011/01/17 22:56:45 nieves $
 */
#ifndef UNZ_H
#define UNZ_h

int unz(char *out, int *outlen, char *in, int inlen);
int zip(char **out, int *outlen, char *in, int inlen, int level);

#endif
