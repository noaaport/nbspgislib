/*
 * Copyright (c) 2005 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: unz.h 2 2009-09-11 16:26:26Z nieves $
 */
#ifndef UNZ_H
#define UNZ_h

int unz(char *out, int *outlen, char *in, int inlen);
int zip(char **out, int *outlen, char *in, int inlen, int level);

#endif
