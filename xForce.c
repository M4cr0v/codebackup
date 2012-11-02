/*
 * =====================================================================================
 *
 *       Filename:  xForce.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月14日 21时09分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "gcd.h"
#include "byte_alignment.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "sort.h"
#include "kmp.h"
#include "bits.h"
#include "bignumber.h"
#include "queens.h"


int main(int argc, const char *argv[])
{
    int menu = 0;
    while (1) {
        printf("********** Function Menu: **********\n");
        printf("************************************\n");
        printf("1. gcd test.\n");
        printf("2. byte_alignment test.\n");
        printf("3. list test.\n");
        printf("4. infix to prefix(with stack) test.\n");
        printf("5. queue test.\n");
        printf("6. sort test.\n");
        printf("7. kmp test.\n");
        printf("8. bits test.\n");
        printf("9. big number multiplication test.\n");
        printf("10. eight queens test.\n");
        printf("0. exit.\n");
        printf("************************************\n");
        printf("Please input number to select:\n");
        
        
        scanf("%d", &menu);
        switch (menu) {
            case 1: gcd_test();break;
            case 2: byte_alignment_test();break;
            case 3: ListTest();break;
            case 4: infix_to_prefix_test();break;
            case 5: queue_test();break;
            case 6: sort_test();break;
            case 7: kmp_test();break;
            case 8: bits_test();break;
            case 9: MBN_test();break;
            case 10: queens_test();break;
            case 0: return 0;
            default: break;
        }
    }
    return 0;
}
