#include<stdio.h>
#include<limits.h>
#include<inttypes.h>
/*
 * count bits set (rank) from the most-significant bit upto a given position
 */
uint64_t v;       // compute the rank (bits set) in v from the MSB to pos
unsigned int pos; // bit position to count bits upto
uint64_t r;       // resulting rank of bit at pos goes here

int main(){
    
    v = 19; // 19 (10011)
    pos = 64; 

    // shift out bits after given position
    r = v >> (sizeof(v) * CHAR_BIT - pos);
    r = r - ((r >> 1) & ~0UL/3);
    r = (r & ~0UL/5) + ((r >> 2) & ~0UL/5);
    r = (r + (r >> 4)) & ~0UL/17;
    r = (r * (~0UL/255)) >> ((sizeof(v) - 1) * CHAR_BIT); // r = 3
    return 0;
}
