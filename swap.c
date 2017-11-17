#include <stdio.h>

/*
 * swapping values with subtraction and addition
 */

int a=2;
int b=3;

int main(){

    if (&a == &b) return 0;
    a -= b;
    b += a;
    a = b - a;

    return 0;
}
