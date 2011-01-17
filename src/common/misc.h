/*
 * Copyright (c) 2005-2010 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: misc.h,v 7b89a4bfdaf1 2011/01/17 00:15:52 nieves $
 */
#ifndef MISC_H
#define MISC_H

#include <sys/types.h>

int read_skip_count(int fd, size_t count, char *buffer, size_t buffer_size);

#endif
