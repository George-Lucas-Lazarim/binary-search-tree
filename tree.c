#include "tree.h"
#include "queue.h"

struct treeNode* initNode (int data) {
    struct treeNode* newNode = (struct treeNode*) malloc (sizeof(struct treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

struct treeNode* addData (struct treeNode* root, int data) {
    if (root == NULL) return initNode(data);

    struct treeNode* currentNode;
    struct treeNode* tempNode = root;

    while (tempNode != NULL) {
        currentNode = tempNode;
        if (tempNode->data <= data) tempNode = tempNode->right;
        else tempNode = tempNode->left;
    }
    
    if (currentNode->data <= data) currentNode->right = initNode(data);
    else currentNode->left = initNode(data);

    return root;
}

bool searchData (struct treeNode* root, int data) {
    while (root != NULL) {
        if (root->data == data) return true;
        if (root->data <= data) root = root->right;
        else root = root->left;
    }

    return false;
}

struct treeNode* deleteTree (struct treeNode* root) {
    if (root == NULL) return NULL;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
    return NULL;
}

int maxTree (struct treeNode* root) {
    if (root == NULL) {
        printf("Empty!");
        return -1;
    }

    while (root->right != NULL) root = root->right;
    return root->data;
}

int minTree (struct treeNode* root) {
    if (root == NULL) {
        printf("Empty!");
        return -1;
    }

    while (root->left != NULL) root = root->left;
    return root->data;
}

struct treeNode* deleteNode (struct treeNode* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct treeNode* tempNode = root->right;
            free(root);
            return tempNode;
        } else if (root->right == NULL) {
            struct treeNode* tempNode = root->left;
            free(root);
            return tempNode;
        } else {
            int maxVal = maxTree(root->left);
            root->data = maxVal;
            root->left = deleteNode(root->left, maxVal);
        }
    }

    return root;
}

void printTreeNode (struct treeNode* root) {
    if (root == NULL) return;

    printf("\n%d: ", root->data);
    if (root->left != NULL) {
        printf("%d; ", root->left->data);
    } else {
        printf("NULL; ");
    }
    if (root->right != NULL) {
        printf("%d", root->right->data);
    } else {
        printf("NULL");
    }
}

void printTree (struct treeNode* root) {
    if (root == NULL) return;

    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}

void printTreeLevel (struct treeNode* root) {
    if (root == NULL) return;

    addQueueNode(root);
    int level = 1;

    while (front != NULL) {
        int nodeCount = getQueueSize();

        printf("%d: ", level);

        while(nodeCount > 0) {
            struct treeNode* currentNode = removeQueueNode();
            printf("%d ", currentNode->data);

            if (currentNode->left != NULL) {
                addQueueNode(currentNode->left);
            }
            if (currentNode->right != NULL) {
                addQueueNode(currentNode->right);
            }

            nodeCount--;
        }
        printf("\n");
        level++;
    }
}
