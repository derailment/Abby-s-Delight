#include <stdio.h>

/*
 * sign extending from a variable bit-width
 */

int b; // 4 bits
int x; // 1101 (-3 in 4-bit machine)
int r; // 111...1101 (-3 in 32-bit machine)
int m;

int main(){
    
    b = 4; 
    x = 13; 
    m = 1U << (b - 1); 
    x = x & ((1U << b) -  1); // skip this if bits in x above b are already zero
    r = (x ^ m) - m;

    return 0;

}
