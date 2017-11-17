#include <stdio.h>
#include <limits.h>
/*
 * reverse bits the obvious way
 */
unsigned int v;     // input bits to be reversed
unsigned int r; // r will be reversed bits of v; first get LSB of v
int s; // extra shift needed at end

int main(){
    
    v = 13; // 13 (000...01101)
    r = v;
    s = sizeof(v) * CHAR_BIT - 1;

    for (v >>= 1; v; v >>= 1)
    {   
          r <<= 1;
          r |= v & 1;
          s--;
    }
    
    // shift when v's highest bits are zero
    r <<= s; // 2952790016 (1011000...0)

    return 0;
}
