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
