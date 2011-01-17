/*
 * Copyright (c) 2008 Jose F. Nieves <nieves@ltp.upr.clu.edu>
 *
 * See LICENSE
 *
 * $Id: config.h,v ff74993871f7 2011/01/17 22:56:45 nieves $
 */
#ifndef CONFIG_H
#define CONFIG_H

/*
 * defaults (FreeBSD)
 */
#define HAVE_OPTRESET
#define HAVE_ERR

#if defined __linux__
  #undef HAVE_OPTRESET
#elif defined __sun__
  #undef HAVE_OPTRESET
  #undef HAVE_ERR
#endif
 
#endif
