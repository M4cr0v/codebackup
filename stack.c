/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月03日 16时13分47秒
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
#include <error.h>
#include <errno.h>
#include <string.h>

#define MinStackSize (5)
#define EmptyTOS (-1)

typedef int ElementType;
struct StackRecord {
	int Capacity;
	int TopOfStack;
	ElementType *Array;
} /* optional variable list */ ;
typedef struct StackRecord *Stack;

static int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

static int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}

static void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

static Stack CreatStack(int MaxElements)
{
	Stack S;
	if (MaxElements < MinStackSize) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Stack size is too small");
	}
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Out of space!!!");
	}
	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Out of space!!!");
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

static void DisposeStack(Stack S)
{
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}

static void Push(ElementType X, Stack S)
{
	if (IsFull(S)) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Full stack!!!");
	} else {
		S->Array[++S->TopOfStack] = X;
	}
}

static ElementType Top(Stack S)
{
	if (IsEmpty(S)) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Empty stack!!!");
	} else {
		return S->Array[S->TopOfStack];
	}
}

static void Pop(Stack S)
{
	if (IsEmpty(S)) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Empty stack!!!");
	} else {
		--S->TopOfStack;
	}
}

static ElementType TopAndPop(Stack S)
{
	if (IsEmpty(S)) {
		error_at_line(1, (int) NULL, __FILE__, __LINE__, "%s",
			      "Empty stack!!!");
	} else {
		return S->Array[S->TopOfStack--];
	}
}

static int Priority(char x, char y)
{
	switch (x) {
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		switch (y) {
		case '(':
			return 1;	/* '(' < '+' or '-' or '*' or '/' here */
		case '*':
		case '/':
			return 0;
		case '+':
		case '-':
			return 1;
		default:
			break;
		}
	case '(':
		return 0;	/* '(' < '+' or '-' or '*' or '/' here */
	default:
		break;
	}
}

void infix_to_prefix(char *Dest, const char *Src)
{
	char *P, *D;
	Stack S;
	P = Src;
	D = Dest;
	S = CreatStack(strlen(Src));
	while (*P != '\0') {
		switch (*P) {
		case '(':
			Push(*P++, S);
			break;
		case ')':
			while (!IsEmpty(S) && Top(S) != '(') {
				*D++ = TopAndPop(S);
			}
			Pop(S);
			++P;
			break;
		case '*':
		case '/':
		case '+':
		case '-':
			while (!IsEmpty(S) && Priority(Top(S), *P)) {
				*D++ = TopAndPop(S);
			}
			Push(*P++, S);
			break;
		default:
			*D++ = *P++;
			break;
		}
	}
	while (!IsEmpty(S)) {
		*D++ = TopAndPop(S);
	}
}

void infix_to_prefix_test(void)
{
	char s[] = "a+(b-(c+d)*e)-f";
	char d[20] = { '\0' };
	infix_to_prefix(d, s);
	printf("Original infix string: %s\n", s);
	printf("Converted prefix string: %s\n", d);
}
