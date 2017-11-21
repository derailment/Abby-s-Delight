#include<stdio.h>
#include<stdbool.h>
/*
 * determine if a word has a zero byte
 */
unsigned int v; // 32-bit word to check if any 8-bit byte in it is 0
bool hasZeroByte;
bool hasNoZeroByte;
unsigned char *p;

int main(){
    
    v = 150797811; // 2147483647 (01111111111111111111111111111111)

    // fewer operations:
    hasZeroByte = ~((((v & 0x7F7F7F7F) + 0x7F7F7F7F) | v) | 0x7F7F7F7F); // 0x7F7F7F7F = 01111111011111110111111101111111
    
    // more operations:
    hasNoZeroByte = ((v & 0xff) && (v & 0xff00) && (v & 0xff0000) && (v & 0xff000000));
        
    // or:
    p = (unsigned char *) &v;  
    hasNoZeroByte = *p && *(p + 1) && *(p + 2) && *(p + 3);
    
    return 0;
}
