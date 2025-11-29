#include"BinaryTree.h"

/*=========================================================*/
node* NewNode(int value) 
/* Function that allocates a new node with the
given data and NULL left and right pointers */
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}
node* Left(node* root) {
	return root->left;
}
node* Right(node* root) {
	return root->right;
}

/*============================ex1===========================*/
node* randomTree()
/* function creating random binary tree */
{
	// ADD YOUR CODE HERE
}

/*============================ex2===========================*/
void deleteTree(node* root) 
{
	// ADD YOUR CODE HERE
}

/*============================ex3===========================*/
void printNodeAtDistance(node *root , int k)
/*Given a Binary Tree and a positive integer ‘k’, write code which will 
print all the nodes which are at distance ‘k’ from the root.
For example: For Binary Tree on the right side, Following are the 
nodes which should get printed for the below values of ‘k’*/
{
	// ADD YOUR CODE HERE
}

/*============================ex4===========================*/
void mirrorify(node* root, node** mirror)
/*Mirrorify function takes two trees, riginal tree and a mirror tree
It recurses on both the trees,but when original tree recurses on left,
mirror tree recurses on right and vice-versa*/
{
	// ADD YOUR CODE HERE  
}

/*============================ex5===========================*/
void preOrderTraversal(node* root)
{
	// ADD YOUR CODE HERE
}

void inOrderTraversal(node* root)
{
	// ADD YOUR CODE HERE
}
void postOrderTraversal(node* root)
{
	// ADD YOUR CODE HERE
}

/*============================ex6===========================*/
node* insert(node* root, int data) 
// 1. If the tree is empty, return a new, single node
// 2. Otherwise, recur down the tree
// 3. return the (unchanged) node pointer
{
	// ADD YOUR CODE HERE
}

/*============================ex7===========================*/
bool isFull(node* root) 
// 1. If root = NULL this a full binary tree
// 2. If the element hasn't son this is a full binary tree
// 3. Browse the left and right side to see if it is a full binary tree
{	
	// ADD YOUR CODE HERE
}

/*============================ex8===========================*/
void printLeaves(node* root)
{
	// ADD YOUR CODE HERE
}

/*============================ex9===========================*/
int depth(node *root)
{
	// ADD YOUR CODE HERE
}

/*============================ex10===========================*/
int levelStatistics(node* root, int level) 
{
	// ADD YOUR CODE HERE
}