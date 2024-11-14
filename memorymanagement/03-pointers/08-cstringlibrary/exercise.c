#include <string.h>
#include "exercise.h"

int smart_append(TextBuffer* dest, const char* src) {
    if (dest == NULL || src == NULL){
        return 1;
    }
    int max_buff = 64; // defnes max buffer size
    int length = strlen(src); // get the length of the src string
    int remaining = max_buff - dest->length - 1; // calculate remaining space in buffer with null terminator
    
    //if the length of the string is greather than the remaining space
    if (length > remaining ){
        // append what it can to the buffer and add null terminator
        strncat(dest->buffer, src, remaining);
        dest->length = max_buff - 1; // update the length to max size minus the null terminator
        dest->buffer[max_buff - 1] = '\0'; // adds null terminator
        return 1; //returns false, indicating the full operation was not possible
    }
    // if there is enough space available, append the entrie src
    else{
        strcat(dest->buffer, src);
        dest->length += length; // update the length
        return 0; // return true indicating the full append was succesful
    }
}

