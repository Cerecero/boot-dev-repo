#include <stdlib.h>
#include <string.h>

#include "snekobject.h"

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
    if (a == NULL || b == NULL){
        return NULL;
    }
    if (a->kind == INTEGER){
        if(b->kind == INTEGER){
            int sum = a->data.v_int + b->data.v_int;
            return new_snek_integer(sum);
        }
        else if(b->kind == FLOAT){
            float sum = a->data.v_int + b->data.v_float;
            return new_snek_float(sum);
        }
        else{
            return NULL;
        }
    }
    if (a->kind == FLOAT){
        if(b->kind == INTEGER){
            float sum = a->data.v_float + b->data.v_int;
            return new_snek_float(sum);
        }
        else if(b->kind == FLOAT){
            float sum = a->data.v_float + b->data.v_float;
            return new_snek_float(sum);
        }
        else{
            return NULL;
        }
    }
    if (a->kind == STRING){
        if(b->kind != STRING){
            return NULL;
        }
        int len_a = strlen(a->data.v_string);
        int len_b = strlen(b->data.v_string);
        char *combined_string = calloc(len_a + len_b + 1, sizeof(char));
        if (combined_string == NULL) {
          return NULL;
        }
        strcat(combined_string, a->data.v_string);
        strcat(combined_string, b->data.v_string);
        snek_object_t *result = new_snek_string(combined_string);
        free(combined_string);
        return result;
    }
    if (a->kind == ARRAY){
        if (b->kind != ARRAY){
            return NULL;
        }
        size_t length = a->data.v_array.size + b->data.v_array.size;
        snek_object_t *new_array = new_snek_array(length);
        if (new_array == NULL){
            return NULL;
        }
        for (size_t i = 0; i < a->data.v_array.size; i++) {
          snek_array_set(new_array, i, snek_array_get(a, i));
        }
        for (size_t j = 0; j < b->data.v_array.size; j++) {
          snek_array_set(new_array, a->data.v_array.size + j, snek_array_get(b, j));
        }

        return new_array;
    }
    if (a->kind == VECTOR3){
        if (b->kind != VECTOR3){
            return NULL;
        }
        snek_object_t *x_sum = snek_add(a->data.v_vector3.x, b->data.v_vector3.x);
        snek_object_t *y_sum = snek_add(a->data.v_vector3.y, b->data.v_vector3.y);
        snek_object_t *z_sum = snek_add(a->data.v_vector3.z, b->data.v_vector3.z);
        if (x_sum == NULL || y_sum == NULL || z_sum == NULL) {
          free(x_sum); free(y_sum); free(z_sum);
          return NULL;
        }
        return new_snek_vector3(x_sum, y_sum, z_sum);
    }
    return NULL;
}

// don't touch below this line

int snek_length(snek_object_t *obj) {
  if (obj == NULL) {
    return -1;
  }

  switch (obj->kind) {
  case INTEGER:
    return 1;
  case FLOAT:
    return 1;
  case STRING:
    return strlen(obj->data.v_string);
  case VECTOR3:
    return 3;
  case ARRAY:
    return obj->data.v_array.size;
  default:
    return -1;
  }
}

snek_object_t *new_snek_array(size_t size) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array = (snek_array_t){.size = size, .elements = elements};
  return obj;
}

bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value) {
  if (array == NULL || value == NULL) {
    return false;
  }

  if (array->kind != ARRAY) {
    return false;
  }

  if (index >= array->data.v_array.size) {
    return false;
  }

  // Set the value directly now (already checked size constraint)
  array->data.v_array.elements[index] = value;
  return true;
}

snek_object_t *snek_array_get(snek_object_t *array, size_t index) {
  if (array == NULL) {
    return NULL;
  }

  if (array->kind != ARRAY) {
    return NULL;
  }

  if (index >= array->data.v_array.size) {
    return NULL;
  }

  // Set the value directly now (already checked size constraint)
  return array->data.v_array.elements[index];
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

  return obj;
}

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}


// Another solution
// snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
  // Handle NULL inputs
//   if (a == NULL || b == NULL) {
//     return NULL;
//   }
//
//   switch (a->kind) {
//     case INTEGER:
//       if (b->kind == INTEGER) {
//         return new_snek_integer(a->data.v_int + b->data.v_int);
//       } else if (b->kind == FLOAT) {
//         return new_snek_float(a->data.v_int + b->data.v_float);
//       }
//       break;
//
//     case FLOAT:
//       if (b->kind == INTEGER) {
//         return new_snek_float(a->data.v_float + b->data.v_int);
//       } else if (b->kind == FLOAT) {
//         return new_snek_float(a->data.v_float + b->data.v_float);
//       }
//       break;
//
//     case STRING:
//       if (b->kind == STRING) {
//         int len_a = strlen(a->data.v_string);
//         int len_b = strlen(b->data.v_string);
//         char *combined_string = calloc(len_a + len_b + 1, sizeof(char));
//         if (combined_string == NULL) {
//           return NULL;
//         }
//         strcat(combined_string, a->data.v_string);
//         strcat(combined_string, b->data.v_string);
//         snek_object_t *result = new_snek_string(combined_string);
//         free(combined_string);
//         return result;
//       }
//       break;
//
//     case VECTOR3:
//       if (b->kind == VECTOR3) {
//         snek_object_t *x_sum = snek_add(a->data.v_vector3.x, b->data.v_vector3.x);
//         snek_object_t *y_sum = snek_add(a->data.v_vector3.y, b->data.v_vector3.y);
//         snek_object_t *z_sum = snek_add(a->data.v_vector3.z, b->data.v_vector3.z);
//         if (x_sum == NULL || y_sum == NULL || z_sum == NULL) {
//           free(x_sum); free(y_sum); free(z_sum);
//           return NULL;
//         }
//         return new_snek_vector3(x_sum, y_sum, z_sum);
//       }
//       break;
//
//     case ARRAY:
//       if (b->kind == ARRAY) {
//         size_t combined_size = a->data.v_array.size + b->data.v_array.size;
//         snek_object_t *result = new_snek_array(combined_size);
//         if (result == NULL) {
//           return NULL;
//         }
//
//         for (size_t i = 0; i < a->data.v_array.size; i++) {
//           snek_array_set(result, i, snek_array_get(a, i));
//         }
//         for (size_t j = 0; j < b->data.v_array.size; j++) {
//           snek_array_set(result, a->data.v_array.size + j, snek_array_get(b, j));
//         }
//
//         return result;
//       }
//       break;
//
//     default:
//       break;
//   }
//
//   // If we reach here, the operation is invalid
//   return NULL;
// }
