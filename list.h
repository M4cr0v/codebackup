/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年09月16日 23时26分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _LIST_
#define _LIST_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#define LIST_PTR
//#define LIST_CURSOR



struct Node;
#ifdef LIST_PTR
typedef struct Node *PtrToNode;
#endif

#ifdef LIST_CURSOR
#define SpaceSize 100
typedef int PtrToNode;
void InitializeCursorSpace(void);
#endif

typedef int ElementType;
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);
void PrintList(List L);


#ifdef __cplusplus
}
#endif
#endif
