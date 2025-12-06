// Genady Kogan
#include"BinaryTree.c"

int main()
{
    node *root1=NULL;
    node* mirror = NULL;

    /*ex6*/
    node* rootEx6_1 = NULL;
    rootEx6_1 = NewNode(1);
    rootEx6_1->left = NewNode(2);
    rootEx6_1->right = NewNode(3);
    rootEx6_1->left->left = NewNode(4);
    rootEx6_1->left->right = NewNode(5);
    rootEx6_1->right->right = NewNode(6);
    int indexEx6_1 = 0;
    node* rootEx6_2 = NULL;
    rootEx6_2 = NewNode(1);
    rootEx6_2->left = NewNode(2);
    rootEx6_2->right = NewNode(3);
    rootEx6_2->left->left = NewNode(4);
    rootEx6_2->left->right = NewNode(5);
    rootEx6_2->right->left = NewNode(6);
    int indexEx6_2 = 0;

    /*ex1*/
    printf("ex1");
    root1 = randomTree();
    printf("\n\n Preorder Traversal tree\n");
    preOrderTraversal(root1);
    /*ex3*/
    printf("\nex3\n");
    printNodeAtDistance(rootEx6_1,2);
    /*	  Binary search tree
      ------------------
             5
            /  \
           /    \
          3      9
         / \     / \
        1   4   8   11
       / \     /      \
     -3   2   7        12
     k=2
     output: 1 4 8 11
    */

    /*ex4*/
    printf("\nex4\n");
    mirrorify(root1, &mirror);

    /*ex5*/
    printf("\nex5");
    printf("\n\n Preorder Traversal tree\n");
    preOrderTraversal(mirror);
    printf("\n\n In_order Traversal tree\n");
    printf("\n\n In_order of original tree\n");
    preOrderTraversal(root1);
    printf("\n\n In_order of mirror tree\n");
    inOrderTraversal(mirror);
    printf("\n\n Postorder Traversal tree\n");
    postOrderTraversal(mirror);
    printf("\n");

    /*ex7*/
    printf("\nex7\n");
    printf("%s\n",isFull(rootEx6_2)? "true": "false");

    /*ex8*/
    printf("\nex8\n");
    printLeaves(rootEx6_2);

    /*ex9*/
    printf("\nex9\n");
    printf("%d\n",depth(rootEx6_2)); // 3

    /*ex10*/
    printf("\nex10\n");
    levelStatistics(rootEx6_2,1);

    /*ex2*/
    deleteTree(root1);
    deleteTree(rootEx6_1);
    deleteTree(rootEx6_2);
    return 0;
}
