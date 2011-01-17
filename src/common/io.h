/*
 * Copyright (c) 2005-2007 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: io.h,v ff74993871f7 2011/01/17 22:56:45 nieves $
 */
#ifndef IO_H
#define IO_H

#include <stdio.h>

FILE *fopen_input(char *path);
FILE *fopen_output(char *path, char *mode);
int read_page(FILE *fp, void *page, int page_size);
int write_page(FILE *fp, void *page, int page_size);

ssize_t readf(int fd, void *buf, size_t nbytes);

#endif
