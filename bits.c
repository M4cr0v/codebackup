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

int log2bits(int x)
{
    int n, sh;

    if (x==0) {
        return 0;
    }
    n = 0;
    sh = sizeof(x)<<3;
    while (sh>>=1) {
        if (x>>sh) {
            n += sh;
            x >>= sh;
        } 
    }
//    if (x>>16) {
//        n += 16;
//        x >>= 16;
//    }
//    if (x>>8) {
//        n += 8;
//        x >>= 8;
//    }
//    if (x>>4) {
//        n += 4;
//        x >>= 4;
//    }
//    if (x>>2) {
//        n += 2;
//        x >>= 2;
//    }
//    if (x>>1) {
//        n += 1;
//        x >>= 1;
//    }
    return n;

}

static int multiplication_bits(int x, int y)
{
    int result = 0, firstone = 0;
    if (x < 0) {
        return -multiplication_bits(-x, y);
    }
    if (y < 0) {
        return -multiplication_bits(x, -y);
    }
    while (y) {
        firstone = y & (~y+1);
        y -= firstone;
        result += (x << log2bits(firstone));
    }
    return result;
}

void bits_test(void)
{
    int x = -12, y = 4;
    printf("%d * %d = %d\n", x, y , multiplication_bits(x, y));
}
