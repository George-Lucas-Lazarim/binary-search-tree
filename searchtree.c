#include "searchtree.h"
#include "queue.h"

struct searchTreeNode* initNode (int data) {
    struct searchTreeNode* newNode = (struct searchTreeNode*) malloc (sizeof(struct searchTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

struct searchTreeNode* addData (struct searchTreeNode* root, int data) {
    if (root == NULL) return initNode(data);

    struct searchTreeNode* currentNode;
    struct searchTreeNode* tempNode = root;

    while (tempNode != NULL) {
        currentNode = tempNode;
        if (tempNode->data <= data) tempNode = tempNode->right;
        else tempNode = tempNode->left;
    }
    
    if (currentNode->data <= data) currentNode->right = initNode(data);
    else currentNode->left = initNode(data);

    return root;
}

bool searchData (struct searchTreeNode* root, int data) {
    while (root != NULL) {
        if (root->data == data) return true;
        if (root->data <= data) root = root->right;
        else root = root->left;
    }

    return false;
}

struct searchTreeNode* deleteTree (struct searchTreeNode* root) {
    if (root == NULL) return NULL;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
    return NULL;
}

int maxTree (struct searchTreeNode* root) {
    if (root == NULL) {
        printf("Empty!");
        return -1;
    }

    while (root->right != NULL) root = root->right;
    return root->data;
}

int minTree (struct searchTreeNode* root) {
    if (root == NULL) {
        printf("Empty!");
        return -1;
    }

    while (root->left != NULL) root = root->left;
    return root->data;
}

struct searchTreeNode* deleteNode (struct searchTreeNode* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct searchTreeNode* tempNode = root->right;
            free(root);
            return tempNode;
        } else if (root->right == NULL) {
            struct searchTreeNode* tempNode = root->left;
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

void printTreeNode (struct searchTreeNode* root) {
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

void printTree (struct searchTreeNode* root) {
    if (root == NULL) return;

    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}

void printTreeLevel (struct searchTreeNode* root) {
    if (root == NULL) return;

    addQueueNode(root);
    int level = 1;

    while (front != NULL) {
        int nodeCount = getQueueSize();

        printf("%d: ", level);

        while(nodeCount > 0) {
            struct searchTreeNode* currentNode = removeQueueNode();
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

int getTreeHeight (struct searchTreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}