/*
 * =====================================================================================
 *
 *       Filename:  sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月06日 23时59分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

void InsertionSort(ElementType Src[], int N)
{
    int i, j;
    ElementType Temp;
    for (i = 1; i < N; i++) {
        Temp = Src[i];
        for (j = i; j > 0 && Src[j-1] > Temp; j--) {
            Src[j] = Src[j-1];
        }
        Src[j] = Temp;
    }
}

void BubbleSort(ElementType Src[], int N)
{
    int i, j;
    ElementType Temp;
    for (i = N; i > 1; i--) {
        for (j = 1; j < i; j++) {
            if (Src[j] < Src[j-1]) {
                Temp = Src[j-1];
                Src[j-1] = Src[j];
                Src[j] = Temp;
            }
        }
    }

}

void SimpleSelectionSort(ElementType Src[], int N)
{
    int i, end, iTemp;
    ElementType Temp;
    end = N-1;
    while (end > 0) {
        Temp = Src[0];
        iTemp = 0;
        for (i = 0; i <= end; i++) {
            if (Src[i] > Temp) {
                Temp = Src[i];
                iTemp = i;
            }
        }
        //swap Src[iTemp] with Src[end]
        Temp = Src[end];
        Src[end] = Src[iTemp];
        Src[iTemp] = Temp;

        --end;
    }
}

void sort_test(void)
{
    int N = 10;
    int s[N], i;
    printf("Original data:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", s[i] = rand()&0x3FF);
    }
    printf("\n");


    SimpleSelectionSort(s, N);
    printf("Sorted data:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}
