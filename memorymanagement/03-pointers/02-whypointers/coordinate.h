typedef struct coordinate {
  int x;
  int y;
  int z;
} coordinate_t;
coordinate_t new_coordinate(int x, int y, int z);
void coordinate_update_x(coordinate_t coord, int new_x);
coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x);
