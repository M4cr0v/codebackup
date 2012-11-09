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
		for (j = i; j > 0 && Src[j - 1] > Temp; j--) {
			Src[j] = Src[j - 1];
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
			if (Src[j] < Src[j - 1]) {
				Temp = Src[j - 1];
				Src[j - 1] = Src[j];
				Src[j] = Temp;
			}
		}
	}

}

void SimpleSelectionSort(ElementType Src[], int N)
{
	int i, end, iTemp;
	ElementType Temp;
	end = N - 1;
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

static void Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void QuickSort(int Src[], int begin, int end)
{
	int left, right;
	if (begin < end) {	//ascending order
		left = begin + 1;
		right = end;
		while (left < right) {
			while (left < right && Src[left] < Src[begin]) {
				left++;
			}
			while (left < right && Src[right] >= Src[begin]) {
				right--;
			}
			Swap(&Src[left], &Src[right]);
		}		//Finally, left=right
		if (Src[left] < Src[begin]) {	//Src[left]<Src[begin] also means left=right=end, and Src[begin] is largest
			Swap(&Src[begin], &Src[left]);
			QuickSort(Src, begin, left - 1);

		} else {
			if (left - 1 == begin) {	//Src[begin] is smallest
				QuickSort(Src, left, end);
			} else {
				Swap(&Src[begin], &Src[left - 1]);
				QuickSort(Src, begin, left - 2);
				QuickSort(Src, left, end);
			}
		}
	} else if (begin > end) {	//descending order
		Swap(&begin, &end);
		left = begin + 1;
		right = end;
		while (left < right) {
			while (left < right && Src[left] > Src[begin]) {
				left++;
			}
			while (left < right && Src[right] <= Src[begin]) {
				right--;
			}
			Swap(&Src[left], &Src[right]);
		}		//Finally, left=right
		if (Src[left] > Src[begin]) {	//Src[left]>Src[begin] also means left=right=end, and Src[begin] is smallest
			Swap(&Src[begin], &Src[left]);
			QuickSort(Src, left - 1, begin);

		} else {
			if (left - 1 == begin) {	//Src[begin] is largest
				QuickSort(Src, end, left);
			} else {
				Swap(&Src[begin], &Src[left - 1]);
				QuickSort(Src, left - 2, begin);
				QuickSort(Src, end, left);
			}
		}
	}
}

void sort_test(void)
{
	int N = 20;
	int s[N], i, submenu;
	while (1) {
		printf("********** Submenu: **********\n");
		printf("************************************\n");
		printf("1. InsertionSort.\n");
		printf("2. BubbleSort.\n");
		printf("3. SimpleSelectionSort.\n");
		printf("4. QuickSort.\n");
		printf("0. exit.\n");
		printf("************************************\n");
		printf("Please input number to select:\n");


		scanf("%d", &submenu);
		switch (submenu) {
		case 1:
			printf("Original data:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i] = rand() & 0xFF);
			}
			printf("\n");

			InsertionSort(s, N);
			printf("Sorted data by InsertionSort:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i]);
			}
			printf("\n");
			break;
		case 2:
			printf("Original data:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i] = rand() & 0xFF);
			}
			printf("\n");

			BubbleSort(s, N);
			printf("Sorted data by BubbleSort:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("Original data:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i] = rand() & 0xFF);
			}
			printf("\n");

			SimpleSelectionSort(s, N);
			printf("Sorted data by SimpleSelectionSort:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i]);
			}
			printf("\n");
			break;
		case 4:
			printf("Original data:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i] = rand() & 0xFF);
			}
			printf("\n");
			QuickSort(s, 0, N - 1);
			printf("Ascending order by QuickSort:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i]);
			}
			printf("\n");

			printf("Original data:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i] = rand() & 0xFF);
			}
			printf("\n");
			QuickSort(s, N - 1, 0);
			printf("Descending order by QuickSort:\n");
			for (i = 0; i < N; i++) {
				printf("%d ", s[i]);
			}
			printf("\n");
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}
