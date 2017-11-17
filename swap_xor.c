#include <stdio.h>

/*
 * swapping values with XOR
 */

int a=2;
int b=3;

int main(){

    if (&a == &b) return 0;
    a ^= b;
    b ^= a;
    a ^= b;

    return 0;
}
