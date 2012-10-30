/*
 * =====================================================================================
 *
 *       Filename:  bignumber.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月30日 20时48分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

//MultiplicationOfBigNumber
void MBN(unsigned char x[], int lengthx, unsigned char y[], int lengthy,unsigned char r[], int lengthr)
{
    int i, j, k, mul;
    if (lengthx + lengthy > lengthr) {
        error_at_line(0, (int)NULL, __FILE__, __LINE__, "%s", "result space is not enough");
    }
    for (i = 0; i < lengthr; i++) {
        r[i] = 0;
    }
    for (i = 0; i < lengthx; i++) {
        for (j = 0; j < lengthy; j++) {
            mul = x[i] * y[j];
            //deal with the carry
            k = i + j;
            while (mul && k<lengthr) {
                mul += r[k];
                r[k] = mul & 0xFF;
                mul = (mul - r[k]) >> 8;
                k++;
            }
        }
    }
}

void MBN_test(void)
{
    unsigned char x[5] = {0x01, 0x02, 0x03, 0xFF, 0x1F};
    unsigned char y[5] = {0xAF, 0xFC, 0x2F, 0x00, 0x21};
    unsigned char r[20]={0};
    int i;
    int lengthx=5, lengthy=5, lengthr=10;
    MBN(x, lengthx, y, lengthy, r, lengthr);
    printf("x = ");
    for (i = lengthx-1; i >= 0; i--) {
        printf("%02X", x[i]);
    }
    printf("\n");
    
    printf("y = ");
    for (i = lengthy-1; i >= 0; i--) {
        printf("%02X", y[i]);
    }
    printf("\n");

    printf("r = x * y = ");
    for (i = lengthr-1; i >= 0; i--) {
        printf("%02X", r[i]);
    }
    printf("\n");

}
