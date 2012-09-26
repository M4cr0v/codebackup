/*
 * =====================================================================================
 *
 *       Filename:  byte_alignment.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月24日 10时54分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "byte_alignment.h"

void byte_alignment_test(void)
{
    struct S12 {
        char a;
        short b;
    } s12;
    struct S124 {
        char a;
        short b;
        int c;
    } s124;
    struct S142 {
        char a;
        int b;
        short c;
    } s142;
   struct S18 {
        char a;
        double b;                               /* the alignment modulus of double and long double type are 4 bytes in 32bit Linux, though they take 8 and 12 bytes respectively; in windows, modulus and space are all 8 bytes */
    } s18;
    struct S181 {
        char a;
        double b;
        char c;
    } s181;
    struct S184 {
        char a;
        double b;
        int c;
    } s184;
    struct S1824 {
        char a;
        double b;
        short c;
        int d;
    } s1824;
    struct S1_142_2 {
        char a;
        struct S142 b;
        short c;
    } s1_142_2;

    printf("Note that the alignment modulus of double and long double type are 4 bytes in 32bit Linux, though they take 8 and 12 bytes respectively; in windows, modulus and space are all 8 bytes.\n");
    printf("s12: %d + %d = %d \n", sizeof(s12.a), sizeof(s12.b), sizeof(s12));
    printf("s124: %d + %d + %d = %d \n", sizeof(s124.a), sizeof(s124.b), sizeof(s124.c), sizeof(s124));
    printf("s142: %d + %d + %d = %d \n", sizeof(s142.a), sizeof(s142.b), sizeof(s142.c), sizeof(s142));
    printf("s18: %d + %d = %d \n", sizeof(s18.a), sizeof(s18.b), sizeof(s18));
    printf("s181: %d + %d + %d = %d \n", sizeof(s181.a), sizeof(s181.b), sizeof(s181.c), sizeof(s181));
    printf("s184: %d + %d + %d = %d \n", sizeof(s184.a), sizeof(s184.b), sizeof(s184.c), sizeof(s184));
    printf("s1824: %d + %d + %d + %d = %d \n", sizeof(s1824.a), sizeof(s1824.b), sizeof(s1824.c), sizeof(s1824.d), sizeof(s1824));
    printf("s1_142_2: %d + %d + %d = %d \n", sizeof(s1_142_2.a), sizeof(s1_142_2.b), sizeof(s1_142_2.c), sizeof(s1_142_2));

}
