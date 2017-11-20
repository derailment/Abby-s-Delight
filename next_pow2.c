#include<stdio.h>
/*
 * round up to the next hightest power of 2
 */
unsigned int v; // compute the next highest power of 2 of 32-bit v

int main(){
    v = 0;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    v += (v == 0);
    return 0;
}
