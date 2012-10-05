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

int main(int argc, const char *argv[])
{
    char menu = 0;
    while (1) {
        if (menu != '\n') {
            printf("********** Function Menu: **********\n");
            printf("************************************\n");
            printf("1. gcd test.\n");
            printf("2. byte_alignment test.\n");
            printf("3. list test.\n");
            printf("4. infix to prefix(with stack) test.\n");
            printf("5. queue test.\n");
            printf("q. exit.\n");
            printf("************************************\n");
            printf("Please input number to select:\n");
        }
        
        scanf("%c", &menu);
        switch (menu) {
            case '1': gcd_test();break;
            case '2': byte_alignment_test();break;
            case '3': ListTest();break;
            case '4': infix_to_prefix_test();break;
            case '5': queue_test();break;
            case 'q': return 0;
            default: break;
        }
    }
    return 0;
}
