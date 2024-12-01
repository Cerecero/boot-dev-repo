#include "snekobject.h"
#include "stack.h"

void snek_object_free(snek_object_t *obj) {
  switch (obj->kind) {
    case INTEGER:
    case FLOAT:
      break;
    case STRING:
      break;
    case VECTOR3: {
      break;
    }
    case ARRAY: {
       stack_free(obj->data.v_array.elements);
      break;
    }
  }
  free(obj);
}
