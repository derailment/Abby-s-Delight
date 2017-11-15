#include <stdio.h>
#include <limits.h>

int v;
int sign;

int main(){
	
    // sign is either -1 or 0
    sign = -(v < 0);
    // to avoid branching
    sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
    // less instruction but not portable
    sign = v >> (sizeof(int) * CHAR_BIT - 1);	

    // sign is either -1 or +1
    sign = +1 | (v >> sizeof(int) * CHAR_BIT - 1);

    // sign is either -1, 0, or +1
    sign = (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1));
    // for portability, brevity, and perhaps speed
    sign = (v > 0) - (v < 0);

    // sign is either 0 or 1
    sign = 1 ^ ((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));	
	
    return 0;
}

