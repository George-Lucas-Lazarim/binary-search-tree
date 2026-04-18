#include "queue.h"

struct queueNode* front = NULL;
struct queueNode* rear = NULL;

void addQueueNode (struct treeNode* treeNode) {
    struct queueNode* newNode = (struct queueNode*) malloc (sizeof(struct queueNode));
    newNode->data = treeNode;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

struct treeNode* removeQueueNode () {
    if (front == NULL) return NULL;

    struct queueNode* freeNode = front;
    struct treeNode* data = front->data;

    front = front->next;
    if (front == NULL) rear = NULL;

    free(freeNode);
    return data;
}

int getQueueSize () {
    int count = 0;
    struct queueNode* temp = front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}
