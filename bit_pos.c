#include <stdio.h>
#include <inttypes.h>
/*
 * select the bit position (from the most-significant bit) with the given count (rank)
 */

uint64_t v;          // input value to find position with rank r
unsigned int r;      // input: bit's desired rank [1-64]
unsigned int s;      // output: Resulting position of bit with rank r [1-64]
uint64_t a, b, c, d; // intermediate temporaries for bit count
unsigned int t;      // bit count temporary

int main(){
    
    v = 13; // 13 (1101)
    r = 3;

    a =  v - ((v >> 1) & ~0UL/3);
    b = (a & ~0UL/5) + ((a >> 2) & ~0UL/5);
    c = (b + (b >> 4)) & ~0UL/0x11;
    d = (c + (c >> 8)) & ~0UL/0x101;
    t = (d >> 32) + (d >> 48);

    // now do branchless select
    s  = 64;
    // if (r > t) {s -= 32; r -= t;}
    s -= ((t - r) & 256) >> 3; r -= (t & ((t - r) >> 8));
    t  = (d >> (s - 16)) & 0xff;
    // if (r > t) {s -= 16; r -= t;}
    s -= ((t - r) & 256) >> 4; r -= (t & ((t - r) >> 8));
    t  = (c >> (s - 8)) & 0xf;
    // if (r > t) {s -= 8; r -= t;}
    s -= ((t - r) & 256) >> 5; r -= (t & ((t - r) >> 8));
    t  = (b >> (s - 4)) & 0x7;
    // if (r > t) {s -= 4; r -= t;}
    s -= ((t - r) & 256) >> 6; r -= (t & ((t - r) >> 8));
    t  = (a >> (s - 2)) & 0x3;
    // if (r > t) {s -= 2; r -= t;}
    s -= ((t - r) & 256) >> 7; r -= (t & ((t - r) >> 8));
    t  = (v >> (s - 1)) & 0x1;
    // if (r > t) s--;
    s -= ((t - r) & 256) >> 8;
    s = 65 - s; // s = 64

    return 0;
}
