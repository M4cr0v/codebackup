/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月16日 23时22分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "list.h"

struct Node {
    ElementType Element;
    Position Next;
} /* optional variable list */;

List MakeEmpty(List L)
{
    List X=L->Next, Y;
    while (X != NULL) {
        Y = X->Next;
        free(X);
        X = Y;
    }
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL; 
}

Position Find(ElementType X, List L)
{
    Position P=L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P=L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TempCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TempCell = P->Next;
        P->Next = TempCell->Next;
        free(TempCell);
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TempCell;
    TempCell = malloc(sizeof(struct Node));
    if (TempCell == NULL) {
        error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
    }

    TempCell->Element = X;
    TempCell->Next = P->Next;
    P->Next = TempCell;
}

void DeleteList(List L)
{
    Position P, Temp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Temp = P->Next;
        free(P);
        P = Temp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

List CreatList(int size)
{
    Position Head, P;
    int i, NodeSize;
    NodeSize = sizeof(struct Node);
    if ((Head = malloc(NodeSize))==NULL) {
        error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
    }
    Head->Next = NULL;
    P = Head;
    for (i = 0; i < size; i++) {
        if ((P->Next = malloc(NodeSize))==NULL) {
            error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
        }
        P = P->Next;
    }
    return Head;
}

List ReverseList(List L)
{
    Position P1, P2, P3;
    if (L==NULL || L->Next==NULL) {
        return L;
    }
    P1 = L->Next;
    P2 = P1->Next;
    P3 = P2->Next;
    P1->Next = NULL;
    while (P3!=NULL) {
        P2->Next = P1;
        P1 = P2;
        P2 = P3;
        P3 = P3->Next;
    }
    P2->Next = P1;
    L->Next = P2;
    return L;

}

void PrintList(List L)
{
    printf("Head->");
    while (L->Next!=NULL) {
        printf("%d->", L->Next->Element);
        L = L->Next;
    }
    printf("NULL\n");
}

void ListTest(void)
{
    int l=10, i;
    List L, P;
    L = CreatList(l);
    P = L->Next;
    for (i = 0; i < l; i++) {
        P->Element = i;
        P = P->Next;
    }
    printf("Origin List:\n");
    PrintList(L);
    L = ReverseList(L);
    printf("Reversed List:\n");
    PrintList(L);
}
