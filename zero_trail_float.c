#include<stdint.h>
/*
 * count the consecutive zero bits (trailing) on the right by casting to a float
 */
unsigned int v;            // find the number of trailing zeros in v
int r;                     // the result goes here
float f;

int main(){
    v = 13; // 13 (1101)
    f = (float)(v & -v); // cast the least significant bit in v to a float
    r = (*(uint32_t *)&f >> 23) - 0x7f;

    return 0;
}
