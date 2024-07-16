#ifndef QUEUE_H
#define QUEUE_H

#include "../../memory/memory.h"
#include "stdbool.h"

typedef struct QueueNode
{
    int value;
    struct QueueNode *node;
} QueueNode;

typedef struct QueueStruct
{
    int size;
    QueueNode *head;
} Queue;

typedef struct QueueHandlerStruct
{
    Queue *(*newQueue)();
    void (*enqueue)(Queue *queue, int value);
    void (*dequeue)(Queue *queue);
    bool (*isQueueEmpty)(Queue *queue);
    int (*peekQueue)(Queue *queue);
    void (*deleteQueue)(Queue *queue);
} QueueHandlerStruct;

Queue *newQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->size = 0;
    return queue;
};

QueueNode *newNode(int value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->value = value;
    newNode->node = NULL;
    return newNode;
}

void enqueue(Queue *queue, int value)
{
    if (queue->size == 0)
    {
        queue->head = newNode(value);
        queue->size++;
    }
    else if (queue->size > 0)
    {
        QueueNode *head = queue->head;
        while (head->node != NULL)
        {
            head = head->node;
        }
        head->node = newNode(value);
        queue->size++;
    }
}

void dequeue(Queue *queue)
{
    if (queue->size == 1)
    {
        QueueNode *head = queue->head;
        queue->head = NULL;
        free(head);
        queue->size = 0;
    }
    else if (queue->head != NULL)
    {
        QueueNode *head = queue->head;
        queue->head = head->node;
        free(head);
        queue->size--;
    }
}

bool isQueueEmpty(Queue *queue)
{
    return queue->head == NULL && queue->size == 0;
}

int peekQueue(Queue *queue)
{
    if (queue->head != NULL)
        return queue->head->value;
    return -1;
}

void deleteQueue(Queue *queue)
{
    while (queue->head != NULL)
    {
        dequeue(queue);
    }
    free(queue);
};

QueueHandlerStruct QueueHandler = {
    .newQueue = newQueue,
    .enqueue = enqueue,
    .dequeue = dequeue,
    .isQueueEmpty = isQueueEmpty,
    .peekQueue = peekQueue,
    .deleteQueue = deleteQueue,
};

extern QueueHandlerStruct QueueHandler;

#endif