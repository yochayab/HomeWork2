#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

/* Helper: build example tree for mirror & traversals
   Structure (BST insert of: 5,3,6,2,4):
           5
          / \
         3   6
        / \
       2   4
*/
node* buildMirrorExampleTree() {
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    return root;
}

/* Helper: build full binary tree for tests (Full tree)
   Insert order: 4,2,6,1,3,5,7 → perfect BST
           4
         /   \
        2     6
       / \   / \
      1   3 5   7
*/
node* buildFullTreeExample() {
    node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);
    return root;
}

/* Helper: build a general tree for leaves / levelStatistics / depth */
node* buildGeneralTreeExample() {
    node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 1);
    root = insert(root, 8);
    return root;
}

int main() {
    /* Seed rand for randomTree */
    srand((unsigned int)time(NULL));

    printf("===== TEST Q1: randomTree & deleteTree =====\n");
    node* randRoot = randomTree();
    printf("Random tree (inorder traversal): ");
    inOrderTraversal(randRoot);
    printf("\n");
    deleteTree(randRoot);  // test deleteTree on random tree
    printf("Random tree deleted.\n\n");

    printf("===== TEST Q3: printNodeAtDistance =====\n");
    node* levelTree = buildGeneralTreeExample();
    printf("Tree inorder (for reference): ");
    inOrderTraversal(levelTree);
    printf("\n");

    for (int k = 0; k <= 3; k++) {
        printf("Nodes at distance %d from root: ", k);
        printNodeAtDistance(levelTree, k);
        printf("\n");
    }
    printf("\n");

    printf("===== TEST Q4 + Q5: mirrorify & traversals =====\n");
    node* mirrorSrc = buildMirrorExampleTree();
    node* mirrorTree = NULL;

    printf("Original tree inorder: ");
    inOrderTraversal(mirrorSrc);
    printf("\n");

    mirrorify(mirrorSrc, &mirrorTree);

    printf("Mirror tree inorder:   ");
    inOrderTraversal(mirrorTree);
    printf("\n");

    printf("Original tree preorder: ");
    preOrderTraversal(mirrorSrc);
    printf("\n");
    printf("Original tree postorder: ");
    postOrderTraversal(mirrorSrc);
    printf("\n\n");

    printf("Mirror tree preorder:   ");
    preOrderTraversal(mirrorTree);
    printf("\n");
    printf("Mirror tree postorder:  ");
    postOrderTraversal(mirrorTree);
    printf("\n\n");

    printf("===== TEST Q6: insert =====\n");
    node* insertTree = NULL;
    int valuesToInsert[] = { 10, 5, 15, 3, 7, 12, 20 };
    int nVals = sizeof(valuesToInsert) / sizeof(valuesToInsert[0]);

    for (int i = 0; i < nVals; i++) {
        insertTree = insert(insertTree, valuesToInsert[i]);
    }

    printf("BST after insertions (inorder): ");
    inOrderTraversal(insertTree);
    printf("\n\n");

    printf("===== TEST Q7: isFull =====\n");
    node* fullTree = buildFullTreeExample();
    node* notFullTree = NULL;
    /* Create non-full tree: 1 root with only left child */
    notFullTree = insert(notFullTree, 10);
    notFullTree = insert(notFullTree, 5);   // will go to left only

    printf("Full tree inorder: ");
    inOrderTraversal(fullTree);
    printf("\nIs full tree full? %s\n",
        isFull(fullTree) ? "true" : "false");

    printf("Not-full tree inorder: ");
    inOrderTraversal(notFullTree);
    printf("\nIs not-full tree full? %s\n\n",
        isFull(notFullTree) ? "true" : "false");

    printf("===== TEST Q8: printLeaves =====\n");
    printf("General tree inorder: ");
    inOrderTraversal(levelTree);
    printf("\nLeaves (from left to right): ");
    printLeaves(levelTree);
    printf("\n\n");

    printf("===== TEST Q9: depth =====\n");
    int dGeneral = depth(levelTree);
    int dFull = depth(fullTree);
    int dInsertTree = depth(insertTree);

    printf("Depth of general tree: %d\n", dGeneral);
    printf("Depth of full tree:    %d\n", dFull);
    printf("Depth of insert tree:  %d\n\n", dInsertTree);

    printf("===== TEST Q10: levelStatistics =====\n");
    printf("General tree inorder: ");
    inOrderTraversal(levelTree);
    printf("\n");

    for (int lvl = 0; lvl <= 4; lvl++) {
        printf("Level %d: ", lvl);
        int count = levelStatistics(levelTree, lvl);
        printf("\nNumber of nodes at level %d: %d\n", lvl, count);
    }

    printf("\nTest invalid levels:\n");
    int c1 = levelStatistics(levelTree, -1);   // should print error
    printf("\nReturned count for level -1: %d\n", c1);

    /* This might be beyond depth; according to your implementation
       it will just return 0 without error. */
    int c2 = levelStatistics(levelTree, 100);
    printf("Returned count for level 100: %d\n", c2);

    printf("\n===== CLEANUP =====\n");
    deleteTree(mirrorSrc);
    deleteTree(mirrorTree);
    deleteTree(insertTree);
    deleteTree(fullTree);
    deleteTree(notFullTree);
    deleteTree(levelTree);
    printf("All trees deleted.\n");

    return 0;
}
