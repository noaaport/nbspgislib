/*
 * Copyright (c) 2010 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: dcnids_info.h 803 2010-12-19 17:08:14Z jfnieves $
 */
#include <inttypes.h>
#include <stdio.h>

#ifndef DCNIDS_INFO_H
#define DCNIDS_INFO_H

#include "dcnids_decode.h"

int dcnids_info_write(char *infofile, struct nids_data_st *nd);

#endif