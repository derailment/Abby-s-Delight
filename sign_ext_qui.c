#include <stdio.h>
#include <limits.h>
/*
 * sign extending from a variable bit-width
 * a slightly faster but less portable
 */

int b; // 4 bits
int x; // 1101 (-3 in 4-bit machine)
int r; // 111...1101 (-3 in 32-bit machine)
int m;

int main(){
    
    b = 4; 
    x = 13; 
    m = CHAR_BIT * sizeof(x) - b;
    r = (x << m) >> m;

    return 0;

}
