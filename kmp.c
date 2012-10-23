/*
 * =====================================================================================
 *
 *       Filename:  kmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月08日 22时08分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

static void ComputePrefixFunction(char *P, int *Pi)
{
    int l, i, k;
    l = strlen(P);
    Pi[0] = 0;
    for (i = 1; i < l; i++) {
        k = Pi[i-1];
        while (k > 0 && P[i] != P[k]) {
            k = Pi[k-1];
        }
        if (P[i] == P[k]) {
            Pi[i] = k + 1;
        }
        else {
            Pi[i] = k;
        }
    }

}

void KmpMatcher(char *T, char *P)
{
    int i, m, l;
    int *Pi;
    l = strlen(T);
    Pi = malloc(l * sizeof(int));
    if (Pi == NULL) {
        error_at_line(0, (int)NULL, __FILE__, __LINE__, "%s", "Out of space!!!");
    }
    ComputePrefixFunction(T, Pi);
//    printf("Pi: \n");
//    for (i = 0; i < l; i++) {
//        printf("%d ", Pi[i]);
//    }
//    printf("\n");

    m = 0;
    for (i = 0; P[i] != '\0'; i++) {
        while (m > 0 && P[i] != T[m]) {
            m = Pi[m-1];
        }
        if (P[i] == T[m]) {
            m++;
        }
        if (m == l) {
            printf("Pattern occurs with shift %d.\n", i+1-l);
            m = Pi[m-1];
        }
    }

    free(Pi);
    Pi = NULL;
}

void kmp_test(void)
{
    char T[] = "abcab";
    char P[20] = "abcabcaababcdefabcab";
    printf("Original string:\n");
    printf("T = %s\n", T);
    printf("P = %s\n", P);
    KmpMatcher(T, P);

}
