#include "tree.h"
#include <time.h>

int main() {
    int n;

    srand(time(NULL));
    struct treeNode* myTree = NULL;

    printf("\nEnter the number of random elements you want to insert into the tree: ");
    scanf("%d", &n);
    
    for (int i=0; i < n; i++) {
        myTree = addData(myTree, rand() % 1000);
    }

    printf("\nPrinting the tree (parent: left child, right child)");
    printTree(myTree);
    printf("\n\nPrinting the tree by level (level: data in level)\n");
    printTreeLevel(myTree);
}