#include <stdio.h>
/*
 * reverse bits without loop
 */
unsigned int v;     // input bits to be reversed
unsigned int r; // r will be reversed bits of v;

int main(){
    
    v = 13; // 13 (000...01101)

    r = v;
    r = ((r & 0xffff0000) >> 16) | ((r & 0x0000ffff) << 16);
    r = ((r & 0xff00ff00) >> 8)  | ((r & 0x00ff00ff) << 8);
    r = ((r & 0xf0f0f0f0) >> 4)  | ((r & 0x0f0f0f0f) << 4);
    r = ((r & 0xcccccccc) >> 2)  | ((r & 0x33333333) << 2);
    r = ((r & 0xaaaaaaaa) >> 1)  | ((r & 0x55555555) << 1);

    return 0;
}
