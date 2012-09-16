/*
 * =====================================================================================
 *
 *       Filename:  queens.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月11日 14时50分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>

char queens_check(int x[], int k)
{
    int i;
    for (i = 0; i < k; i++) {
        if (x[i]==x[k] || abs(i-k)==abs(x[i]-x[k])) {
            return 1;                           /* conflict */
        }
    }
    return 0;

}

void queens_show(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",x[i]);
    }
    printf("\n");

//    int j;
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            if (j == x[i]) {
//                printf("O ");
//            }
//            else {
//                printf("* ");
//            }
//        }
//        printf("\n");
//    }
//    printf("\n\n\n");
}

void queens_backtrace(int x[], int n)
{
    int i;
    for (i = 0; i < n-1; i++) {
        x[i] = -1;
    }
    i = 0;
    x[i] = -1;
    while (i >= 0) {
        x[i]++;
        while (x[i]<n && queens_check(x, i)) {
            x[i]++;
        }
        if (x[i]<n && i==n-1) {
            queens_show(x,n);
        }
        else if (x[i]<n && i<n-1) {
            i++;
        }
        else {
            x[i] = -1;
            i--;
        }
    }
}


void queens_recursive(int x[], int index, int n)
{
    int i;
    if (index == n) {
        queens_show(x, n);
    }
    else
        for (i = 0; i < n; i++) {
            x[index] = i;
            if (!queens_check(x, index)) {
                queens_recursive(x, index+1, n);
            }
        }
}

void permutation(int x[], int index , int n)
{
    int i,temp;
    if (index == n) {
        queens_show(x, n);
    }
    else
        for (i = index; i < n; i++) {
            temp = x[index];
            x[index] = x[i];
            x[i] = temp;
            if (!queens_check(x, index)) {
                permutation(x, index+1, n);
            }
            x[i] = x[index];
            x[index] = temp;
        }
}

void queens_permutation(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        x[i] = i;
    }
    permutation(x, 0, n);
}

int num_of_one(int x)
{
    x = ((x&0xaaaaaaaa)>>1) + (x&0x55555555);
    x = ((x&0xcccccccc)>>2) + (x&0x33333333);
    x = ((x&0xf0f0f0f0)>>4) + (x&0x0f0f0f0f);
    x = ((x&0xff00ff00)>>8) + (x&0x00ff00ff);
    x = ((x&0xffff0000)>>16) + (x&0x0000ffff);
    return x;
    
}

int log2simple(int x)
{
    int i=0;
    while ((1<<i)!=x) {
        ++i;
    }
    return i;
}

void bitcal(int row, int ld, int rd, int x[], int n)
{
    char maxbits=32;
    int upperlimit=(0xFFFFFFFF<<(maxbits-n))>>(maxbits-n);
    int pos, p;
    if ((row&upperlimit)!=upperlimit) {
        pos = upperlimit & ~(row|ld|rd);
        while (pos!=0) {
            p = pos & -pos;                     /* equals to pos & (~pos+1) */
            pos = pos - p;
            x[num_of_one(row)] = log2simple(p);
            bitcal(row+p, (ld+p)<<1, (rd+p)>>1, x, n);

        }
    }
    else
        queens_show(x, n);
}

void queens_bits(int x[], int n)
{
    bitcal(0, 0, 0, x, n);
}

int t_main(int argc, const char *argv[])
{
    int x[500]={0};
    int n=9;
    printf("Please input queens number!\n");
    scanf("%d",&n);
    printf("queens_backtrace result:\n");
    queens_backtrace(x, n);    
    printf("queens_recursive result:\n");
    queens_recursive(x, 0 , n);
    printf("queens_permutation result:\n");
    queens_permutation(x, n);
    printf("queens_bits result:\n");
    queens_bits(x, n);
    return 0;
}
