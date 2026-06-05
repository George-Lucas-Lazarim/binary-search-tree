#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "searchtree.h"

struct queueNode {
    struct searchTreeNode* data;
    struct queueNode* next;
};

extern struct queueNode* front;
extern struct queueNode* rear;

void addQueueNode (struct searchTreeNode* searchTreeNode);
struct searchTreeNode* removeQueueNode ();
int getQueueSize ();

#endif