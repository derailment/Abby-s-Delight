#include<stdio.h>
/*
 * round up to the next highest power of 2 by float casting
 */
unsigned int v; // round this 32-bit value to the next highest power of 2
unsigned int r;       // put the result here. (so v=3 -> r=4; v=8 -> r=8)
unsigned int t;
float f;

int main(){

    v = 5;

    if (v > 1) 
    {
          f = (float)v;
          t = 1U << ((*(unsigned int *)&f >> 23) - 0x7f);
          r = t << (t < v);
    }
    else 
    {
          r = 1;
    }

    return 0;
}
