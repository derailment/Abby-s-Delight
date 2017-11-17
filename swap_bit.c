#include <stdio.h>

/*
 * swapping individual bits with XOR
 */
unsigned int i, j; // positions of bit sequences to swap
unsigned int n;    // number of consecutive bits in each sequence
unsigned int b;    // bits to swap reside in b
unsigned int r;    // bit-swapped result goes here
unsigned int x;    // XOR temporary

int main(){
    i = 1;
    j = 5;
    n = 3;
    b = 47; // 47 (00101111)
    x = ((b >> i) ^ (b >> j)) & ((1U << n) - 1);
    r = b ^ ((x << i) | (x << j)); // 227 (11100011)

    return 0;    
}
