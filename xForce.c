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
#include "xForce.h"

int main(int argc, const char *argv[])
{
    char menu = 0;
    while (1) {
        printf("********** Function Menu: **********\n");
        printf("************************************\n");
        printf("1. gcd test.\n");
        printf("9. exit.\n");
        printf("************************************\n");
        printf("Please input number to select:\n");
        scanf("%d",&menu);
        switch (menu) {
            case 1: gcd_test();break;
            case 9: return 0;
            default: break;
        }
    }
    return 0;
}