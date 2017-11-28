#include<stdio.h>
/*
 * count leading zeroes from MSB
 */
unsigned int v;  // find the number of trailing zeros in 32-bit v 
int r;           // result goes here
int n = 32, c = 16;

int main(){

    v = 13; // 13 (1101)

    do {
        unsigned int y = v >> c;
        if (y) { n -= c; v = y; }
        c >>= 1;
    } while (c);
    
    r = (n - v);

    return 0;

}
