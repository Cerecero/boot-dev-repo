#include "coord.h"

struct Coordinate new_coord(int x, int y, int z) { // fucntion declaration (or prototype)
    return (struct Coordinate) { .x = x, .y = y, .z = z };
    // struct Coordinate c = {
    // .x = x,
    // .y = y,
    // .z = z
    // };
    // return c;
}
