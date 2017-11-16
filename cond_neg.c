#include<stdio.h>
#include<stdbool.h>

/*
 * conditionally negate a value without branching
 */

int main(){
    bool fDontNegate; // flag indicating we should not negate v
    bool fNegate; // Flag indicating if we should negate v
    int v; // input value to negate
    int r;

    // if you need to negate only when a flag is false
    // result = fDontNegate ? v : -v
    r = (fDontNegate ^ (fDontNegate - 1)) * v;
    
    // if you need to negate only when a flag is true
    // result = fNegate ? -v : v
    r = (v ^ -fNegate) + fNegate;

    return 0;

}
