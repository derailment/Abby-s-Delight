#include<stdio.h>
/*
 * an full adder
 */ 
int x, y;
int add(int a, int b)
{
        if (b == 0) return a;
        int sum = a ^ b; /* 相加但不進位 */
        int carry = (a & b) << 1; /* 進位但不相加 */
        return add(sum, carry);
}

int main (){

    x = 5;
    y = 6;

    printf("%d + %d = %d\n", x, y, add(x, y));

    return 0;
}

