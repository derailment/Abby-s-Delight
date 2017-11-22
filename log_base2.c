#include<stdio.h>
/*
 * find the log base 2 of an N-bit integer in O(lg(N)) operations
 */
unsigned int v;  // 32-bit value to find the log2 of 
const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
const unsigned int S[] = {1, 2, 4, 8, 16};
unsigned int r = 0; // result of log2(v) will go here
int i;

int main(){

    v = 13; // 13 (1101)

    for (i = 4; i >= 0; i--) // unroll for speed...
    {
          if (v & b[i])
          {             
            v >>= S[i];
            r |= S[i];
          } 
    }

    return 0;
}
