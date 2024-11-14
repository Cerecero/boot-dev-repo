#include "exercise.h"

codefile_t change_filetype(codefile_t *f, int new_filetype) {
    codefile_t file = *f;
    file.filetype = new_filetype;
    return file;
  // codefile_t *new_f = &f;
  // new_f.filetype = new_filetype;
  // return new_f;
}
