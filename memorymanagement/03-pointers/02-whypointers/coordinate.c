#include "coordinate.h"
coordinate_t new_coordinate(int x, int y, int z) {
    coordinate_t coord;
    coord.x = x;
    coord.y = y;
    coord.z = z;
    return coord;
}
void coordinate_update_x(coordinate_t coord, int new_x) {
    coord.x = new_x;
}

coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x) {
    return (coordinate_t){.x = new_x};
}

