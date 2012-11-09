/*
 * =====================================================================================
 *
 *       Filename:  prime.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年11月04日 10时48分59秒
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

void prime_less_than_n(int n)
{
	int i, j, sqroot, Max, pnumber;	//p[Max] is prime number space, pnumber is number of prime numbers already have
	Max = (n >> 1);
	int p[Max];
	pnumber = 0;
	printf("prime number less than n: \n");
	for (i = 2; i < n; i++) {
		sqroot = (int) sqrt(i);
		for (j = 0; j < pnumber && p[j] <= sqroot; j++) {
			if (i % p[j] == 0) {
				break;
			}
		}
		if (j == pnumber || p[j] > sqroot) {
			printf("%d ", i);
			p[pnumber++] = i;
		}
	}
	printf("\n");
}

void prime_test(void)
{
	int n;
	printf
	    ("Please input number n to output all the prime numbers less than n!\n");
	scanf("%d", &n);
	prime_less_than_n(n);
}
