#include <sys/types.h>

/*
 * int mkdir_recursive(char *path, mode_t path_mode);
 *
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
int mkdir_recursive(char *path, mode_t path_mode);
