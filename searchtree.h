#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct searchTreeNode {
    int data;
    struct searchTreeNode* left;
    struct searchTreeNode* right;
};

struct searchTreeNode* initNode (int data);
struct searchTreeNode* addData (struct searchTreeNode* root, int data);
bool searchData (struct searchTreeNode* root, int data);
struct searchTreeNode* deleteTree (struct searchTreeNode* root);
int maxTree (struct searchTreeNode* root);
int minTree (struct searchTreeNode* root);
struct searchTreeNode* deleteNode (struct searchTreeNode* root, int data);
void printTreeNode (struct searchTreeNode* root);
void printTree (struct searchTreeNode* root);
void printTreeLevel (struct searchTreeNode* root);
int getTreeHeight (struct searchTreeNode* root);

#endif