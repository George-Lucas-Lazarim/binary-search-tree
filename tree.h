#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* initNode (int data);
struct treeNode* addData (struct treeNode* root, int data);
bool searchData (struct treeNode* root, int data);
struct treeNode* deleteTree (struct treeNode* root);
int maxTree (struct treeNode* root);
int minTree (struct treeNode* root);
struct treeNode* deleteNode (struct treeNode* root, int data);
void printTreeNode (struct treeNode* root);
void printTree (struct treeNode* root);
void printTreeLevel (struct treeNode* root);
int getTreeHeight (struct treeNode* root);

#endif