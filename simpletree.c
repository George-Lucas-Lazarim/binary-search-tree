#include "tree.h"
#include <time.h>

int main() {
    int n;

    srand(time(NULL));
    struct treeNode* tree = NULL;

    printf("\nEnter the number of random elements you want to insert into the tree: ");
    scanf("%d", &n);
    
    for (int i=0; i < n; i++) {
        tree = addData(tree, rand() % 1000);
    }

    printf("\nPrinting the tree (parent: left child, right child)");
    printTree(tree);

    printf("\n\nPrinting the tree by level (level: data in level)\n");
    printTreeLevel(tree);

    printf("\nEnter a number to search for it: ");
    scanf("%d", &n);
    if (searchData(tree, n)) printf("\nNumber found!");
    else printf("\nThe number was not found!");

    printf("\nLowest value of the tree: %d", minTree(tree));
    printf("\nGreater value of the tree: %d", maxTree(tree));

    printf("\n\nEnter a number to delete it: ");
    scanf("%d", &n);
    tree = deleteNode(tree, n);
    printTreeLevel(tree);

    printf("The height of the tree is: %d", getTreeHeight(tree));

    printf("\nDeleting the tree... ");
    tree = deleteTree(tree);
    printf("Deleted!\n");
}