/*
 * Copyright (c) 2010 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: dcgini_asc.c 843 2011-01-11 13:47:03Z jfnieves $
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "err.h"
#include "dcgini.h"

static int dcgini_asc_write_data(FILE *fp, struct dcgini_grid_map_st *gm);

int dcgini_asc_write(char *file, struct dcgini_grid_map_st *gm){

  FILE *fp;
  int status;

  if(strcmp(file, "-") == 0)
    fp = stdout;
  else{
    fp = fopen(file, "w");
    if(fp == NULL)
      log_err(1, "Cannot open %s", file);
  }

  status = dcgini_asc_write_data(fp, gm);

  if(fp != stdout)
    fclose(fp);

  if(status != 0)
    log_err(1, "Cannot write to %s", file);

  return(0);
}

static int dcgini_asc_write_data(FILE *fp, struct dcgini_grid_map_st *gm){
  /*
   * Output the data in asc format.
   *
   * ncols 157
   * nrows 171
   * xllcorner -156.08749650000
   * yllcorner 18.870890200000
   * cellsize 0.00833300
   * nodata_value -99     (optional)
   * 0 0 1 1 1 2 3 3 5 6 8 9 12 14 18 21 25 30 35 41 47 53
   * 59 66 73 79 86 92 97 102 106 109 112 113 113 113 111 109 106
   * 103 98 94 89 83 78 72 67 61 56 51 46 41 37 32 29 25 22 19
   * etc...
   */
  int *datap = gm->level;
  size_t i, j;
  int n;
  int c;

  n = fprintf(fp, "ncols %zu\n", gm->nlon);
  if(n > 0)
    n = fprintf(fp, "nrows %zu\n", gm->nlat);

  if(n > 0)
    n = fprintf(fp, "xllcorner %f\n", gm->lon1_deg);

  if(n > 0)
    n = fprintf(fp, "yllcorner %f\n", gm->lat1_deg);

  if(n > 0)
    n = fprintf(fp, "cellsize %f\n", gm->cellsize_deg);

  if(n > 0)
    n = fprintf(fp, "nodata_value %d\n", DCGINI_GRID_MAP_NODATA);

  if(n < 0)
    return(-1);

  /*
   * Here we assume that the data has been saved in the gm->level array
   * in the 'asc" format order (which is the way it is done in the
   * function dcgini_regrid_data_asc()).
   */
  for(j = 0; j < gm->nlat; ++j){
    c = ' ';
    for(i = 0; i < gm->nlon; ++i){
      if(i == gm->nlon - 1)
	c = '\n';

      if(fprintf(fp, "%d%c", *datap, c) < 0)
	return(-1);
      
      ++datap;
    }
  }

  return(0);
}
