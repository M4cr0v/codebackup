/*
 * =====================================================================================
 *
 *       Filename:  bits.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月23日 12时12分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static int multiplication_bits(int x, int y)
{
    int result = 0, firstone, temp = 0;
    if (x < 0) {
        return -multiplication_bits(-x, y);
    }
    if (y < 0) {
        return -multiplication_bits(x, -y);
    }
    while (y) {
        firstone = y & (~y+1);
        y -= firstone;
        temp = x;
        while (firstone != 1) {
            firstone >>= 1;
            temp <<= 1; 
        }
        result += temp;
    }
    return result;
}

void bits_test(void)
{
    int x = -12, y = 4;
    printf("%d * %d = %d\n", x, y , multiplication_bits(x, y));
}
