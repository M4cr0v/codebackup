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
#include <error.h>
#include <errno.h>
typedef int ElementType;
extern struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);
void PrintList(List L);




#ifdef __cplusplus
}
#endif
#endif
