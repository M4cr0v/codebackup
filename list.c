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

#ifdef LIST_PTR
List MakeEmpty(List L)
{
    Position P, Temp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Temp = P->Next;
        free(P);
        P = Temp;
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

//    //if you malloc all nodes' space once, then you cannot free a single node later
//    if ((Head = malloc(NodeSize * (size+1)))==NULL) {
//        error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
//    }
//    P = Head;
//    for (i = 0; i < size; i++) {
//        P->Next = P+1;
//        P = P->Next;                         /* or you can use ++P; */
//    }
    
    if ((Head = malloc(NodeSize))==NULL) {
        error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
    }
    P = Head;
    for (i = 0; i < size; i++) {
        if ((P->Next = malloc(NodeSize))==NULL) {
            error_at_line(0, errno, __FILE__, __LINE__, "%s", "malloc");
        }
        P = P->Next;
    }
    P->Next = NULL;
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
    int l=10, i, temp=3;
    int *memtest;
    List L, P;
    L = CreatList(l);
    P = L->Next;
    for (i = 0; i < l; i++) {
        P->Element = i;
        P = P->Next;
    }

    printf("Origin List:\n");
    PrintList(L);
    
    P = FindPrevious(temp, L);
    Insert(temp+2, L, P);
    printf("Inserted List:\n");
    PrintList(L);

    Delete(temp, L);
    printf("Deleted List:\n");
    PrintList(L);
    
    L = ReverseList(L);
    printf("Reversed List:\n");
    PrintList(L);
}
#endif


#ifdef LIST_CURSOR
struct Node CursorSpace[SpaceSize];

void InitializeCursorSpace(void)
{
    int i;
    for (i = 0; i < SpaceSize; i++) {
        CursorSpace[i].Next = i+1;
    }
    CursorSpace[SpaceSize-1].Next = 0;

}

static Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

List MakeEmpty(List L)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next != 0) {
        P = CursorSpace[P].Next;
    }
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[L].Next;
    CursorSpace[L].Next = 0;
    return L;
}

int IsEmpty(const List L)
{
    return CursorSpace[L].Next == 0;
}

int IsLast(const Position P, const List L)
{
    return CursorSpace[P].Next == 0;
}

Position Find(ElementType X, const List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while (P && CursorSpace[P].Next != X) {
        P = CursorSpace[P].Next;
    }
    return P;
}

void Delete(ElementType X, const List L)
{
    Position P, TempCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TempCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TempCell].Next;
        CursorFree(TempCell);
    }
}

Position FindPrevious(ElementType X, const List L)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X) {
        P = CursorSpace[P].Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TempCell;
    TempCell = CursorAlloc();
    if (TempCell == 0) {
        error_at_line(0, ENOMEM, __FILE__, __LINE__, "%s", "CursorAlloc");
    }
    CursorSpace[TempCell].Element = X;
    CursorSpace[TempCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TempCell;
}

void DeleteList(List L)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next != 0) {
        P = CursorSpace[P].Next;
    }
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[L].Next;
    CursorSpace[L].Next = 0;
}

Position Header(const List L)
{
    return L;
}

Position First(const List L)
{
    return CursorSpace[L].Next;
}

Position Advance(const Position P)
{
    return CursorSpace[P].Next;
}

ElementType Retrieve(const Position P)
{
    return CursorSpace[P].Element;
}

List CreatList(int size)
{
    Position Head, P=0;
    int i;
    for (i = 0; i <= size; i++) {
        P = CursorSpace[P].Next;
        if (P == 0) {
            error_at_line(0, ENOMEM, __FILE__, __LINE__, "%s", "CursorAlloc");
        }
    }
    Head = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = 0;
    return Head;
}

List ReverseList(List L)
{
    Position P1, P2, P3;
    if (L==0 || CursorSpace[L].Next==0) {
        return L;
    }
    P1 = CursorSpace[L].Next;
    P2 = CursorSpace[P1].Next;
    P3 = CursorSpace[P2].Next;
    CursorSpace[P1].Next = 0;
    while (P3!=0) {
        CursorSpace[P2].Next = P1;
        P1 = P2;
        P2 = P3;
        P3 = CursorSpace[P3].Next;
    }
    CursorSpace[P2].Next = P1;
    CursorSpace[L].Next = P2;
    return L;

}

void PrintList(List L)
{
    printf("Head->");
    while (CursorSpace[L].Next!=0) {
//        printf("%d(%d)->", CursorSpace[L].Next, CursorSpace[CursorSpace[L].Next].Element);
        printf("%d->", CursorSpace[CursorSpace[L].Next].Element);
        L = CursorSpace[L].Next;
    }
    printf("NULL\n");
}

void ListTest(void)
{
    int l=10, i, temp = 3;
    List L, P;
    InitializeCursorSpace();
    L = CreatList(l);
    P = CursorSpace[L].Next;
    for (i = 0; i < l; i++) {
        CursorSpace[P].Element = i;
        P = CursorSpace[P].Next;
    }
    printf("Origin List:\n");
    PrintList(L);

    P = FindPrevious(temp, L);
    Insert(temp+2, L, P);
    printf("Inserted List:\n");
    PrintList(L);

    Delete(temp, L);
    printf("Deleted List:\n");
    PrintList(L);

    L = ReverseList(L);
    printf("Reversed List:\n");
    PrintList(L);
}

#endif
