/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月05日 16时26分19秒
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

typedef int ElementType;
struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
} /* optional variable list */;
typedef struct QueueRecord *Queue;
#define MiniQueueSize (5)

static int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

static int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

static void MakeEmpty(Queue Q)
{
    Q->Front = 1;
    Q->Rear = 0;
    Q->Size = 0;
}

static Queue CreatQueue(int MaxElements)
{
    Queue Q;
    if (MaxElements < MiniQueueSize) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Queue size is too small!!!");
    }
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Out of space!!!");
    }
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Out of space!!!");
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

static void DisposeQueue(Queue Q)
{
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

static int Succ(int value, Queue Q)
{
    if (++value == Q->Capacity) {
        value = 0;
    }
    return value;
}

static void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q)) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Full queue!!!");
    }
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

static ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

static void Dequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Empty queue!!!");
    }
    else {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

static ElementType FrontAndDequeue(Queue Q)
{
    ElementType Temp;
    if (IsEmpty(Q)) {
        error_at_line(1, (int)NULL, __FILE__, __LINE__, "%s", "Empty queue!!!");
    }
    else {
        Q->Size--;
        Temp = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
        return Temp;
    }
}

void queue_test(void)
{
    int i;
    Queue Q;
    Q = CreatQueue(16);
    printf("Enqueue:\n");
    for (i = 0; i < 16; i++) {
        Enqueue(i, Q);
        printf("%d ", i);
    }
    printf("\n");

    printf("Dequeue:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", FrontAndDequeue(Q));
    }
    printf("\n");

}
