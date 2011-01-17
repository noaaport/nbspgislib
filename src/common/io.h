/*
 * Copyright (c) 2005-2007 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: io.h 814 2010-12-27 22:05:49Z jfnieves $
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
