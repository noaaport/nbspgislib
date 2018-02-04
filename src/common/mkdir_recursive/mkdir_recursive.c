#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "mkdir_recursive.h"

static int exists(char *path);
  
static int exists(char *path) {
  /*
   * Returns:
   *
   *  0 => directory exists
   * -1 => path does not exist
   *  1 => path exists but it is not a directory
   */
  struct stat sb;
  int status = 0;
  int r = 0;  /* directory exists */

  status = stat(path, &sb);
  if(status != 0) {
    /* path does not exist */
    return(-1);
  }

  if((sb.st_mode & S_IFMT) != S_IFDIR) {
    /* exists but not a directory */
     r = 1;
  }
    
  return(r);
}

int mkdir_recursive(char *path, mode_t path_mode) {
  /*
   * path is modified, so it should be a (writeable) copy of the directory
   * name. Returns:
   *
   *  0 => no error
   *  1 => a component of path exists but it is not a directory. 
   * -1 => error from mkdir() creating some component.
   *
   * In case of an error, path contains the name of the component
   * that caused the error.
   */
  char *p;
  int status = 0;

  p = strchr(path, '/');
  while(p != NULL) {
    p[0] = '\0';
    status = exists(path);
    if(status == 1) {
      /* errx(1, "%s exists but is not a directory", path); */
      return(1);
    } else if(status == -1)
      status = mkdir(path, path_mode);

    if(status != 0)
      break;

    p[0] = '/';
    p = strchr(++p, '/');
  }

  if(status == 0)
    status = mkdir(path, path_mode);

  /*
    if(status != 0)
    err(1, "%s", strerror(errno));
  */

  return(status);
}

#if 0
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <errno.h>
#include "mkdir_recursive.h"

#define DIRMODE 0777

int main(int argc, char ** argv) {

  int status = 0;
  char *input = NULL;
  char *path = NULL;

  if(argc != 2) {
    errx(1, "Needs input.");
  }

  input = argv[1];
  path = malloc(strlen(input) + 1);
  if(path == NULL)
    err(1, "%s", strerror(errno));
  
  strncpy(path, input, strlen(input) + 1);
  /* fprintf(stdout, "%s\n", path); */

  status = mkdir_recursive(path, DIRMODE);
  if(status == 1)
    errx(1, "%s exists but is not a directory", path);
  else if(status != 0)
    err(1, "%s", strerror(errno));

  if(path != NULL)
    free(path);
  
  return(0);
}
#endif
