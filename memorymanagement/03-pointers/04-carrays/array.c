#include <stdio.h>

int main(){
typedef struct Coordinate{
    int x;
    int y;
    int z;
} coordinate_t;

coordinate_t points[3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

coordinate_t *ptr = points;
printf("ptr[1].x = %d, ptr[1].y = %d, ptr[1].z = %d\n",
       (ptr + 1)->x, (ptr + 1)->y, (ptr + 1)->z
       );
}
