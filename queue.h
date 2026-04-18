#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct queueNode {
    struct treeNode* data;
    struct queueNode* next;
};

extern struct queueNode* front;
extern struct queueNode* rear;

void addQueueNode (struct treeNode* treeNode);
struct treeNode* removeQueueNode ();
int getQueueSize ();

#endif