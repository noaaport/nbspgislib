/*
 * Copyright (c) 2005 Jose F. Nieves <nieves@ltp.uprrp..edu>
 *
 * See LICENSE
 *
 * $Id$
 */
#ifndef UNZ_H
#define UNZ_H

int unz(char *out, int *outlen, char *in, int inlen);
int zip(char **out, int *outlen, char *in, int inlen, int level);

#endif
