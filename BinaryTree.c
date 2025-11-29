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
int GetRandomLR()
{
	return rand() % 2;
}
node* randomInsertInto(node* root, int value)
{
	if (root == NULL)
		return NewNode(value);
	int side = GetRandomLR();
	if(side == 0)
	{
		if(root->left == NULL)
			root->left = NewNode(value);
		else
			randomInsertInto(root->left,value);
	}
	else
	{
		if(root->right == NULL)
			root->right= NewNode(value);
		else
			randomInsertInto(root->right,value);
	}
	return root;
}
int GetRandomNumberRoot()
{
	return rand() % 2;
}
int GetRandomNumberNode()
{
	return rand() % 3;
}
int GetRandomValueNode()
{
	return rand();
}
/*============================ex1===========================*/
node* randomTree()
/* function creating random binary tree */
{
	int RootNum = GetRandomNumberRoot();
	if(RootNum == 0)
		return NULL;
	node* Root = NewNode(GetRandomValueNode());
	int SubRootnum = GetRandomNumberNode();
	if(SubRootnum == 0)
		return Root;
	if(SubRootnum == 1)
	{
		randomInsertInto(Root,GetRandomValueNode());
		return Root;
	}
	if(SubRootnum == 2)
	{
		Root->left  = randomInsertInto(Root->left,GetRandomValueNode());
		Root->right = randomInsertInto(Root->right,GetRandomValueNode());
		return Root;
	}
	return Root;
}
/*============================ex2===========================*/
void deleteTree(node* root)
{
	if (root == NULL){// nothing to erase if null
          return;
          }
          deleteTree(root->left);//recursive call for deleting left root till null
          deleteTree(root->right);//recursive call for deleting right root till null
          free(root);//free root itself
}

/*============================ex3===========================*/
void printNodeAtDistance(node *root , int k)
/*Given a Binary Tree and a positive integer ‘k’, write code which will 
print all the nodes which are at distance ‘k’ from the root.
For example: For Binary Tree on the right side, Following are the 
nodes which should get printed for the below values of ‘k’*/
{
	if(root == NULL)
		return;
	if(k==0)
	{
		printf("%d ",root->data);
		return;
	}
	if(k>0)
	{
		printNodeAtDistance(root->left,k-1);
		printNodeAtDistance(root->right,k-1);
	}
}

/*============================ex4===========================*/
void mirrorify(node* root, node** mirror)
/*Mirrorify function takes two trees, riginal tree and a mirror tree
It recurses on both the trees,but when original tree recurses on left,
mirror tree recurses on right and vice-versa*/
{
	if (root == NULL){//if main root is null mirror will be null aswell
          *mirror = NULL;
          return;
          }
    *mirror =NewNode(root->data);
    mirrorify(root->left,&((*mirror)->right));
	mirrorify(root->right,&((*mirror)->left));

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
node* insert(node* root, int data) {
// 1. If the tree is empty, return a new, single node
// 2. Otherwise, recur down the tree
// 3. return the (unchanged) node pointer

	// ADD YOUR CODE HERE
 if (root==NULL)//if the given root is null insert the data to be the main root
  		return NewNode(data);
 if (data < root->data){//if the inserted data smaller then the current data go left till its not
   root->left = insert(root->left,data);
   }
   else if (data > root->data){//if the inserted data greater then the current data go right till its not
     root->right = insert(root->right,data);
   }
   return root;
}

/*============================ex7===========================*/
bool isFull(node* root) 
// 1. If root = NULL this a full binary tree
// 2. If the element hasn't son this is a full binary tree
// 3. Browse the left and right side to see if it is a full binary tree
{	
		if(root == NULL)
			return true;
		if (root->left != NULL && root->right != NULL)
		{
			return isFull(root->left)&&isFull(root->right);
		}
		if (root->left == NULL && root->right == NULL)
		{
			return true;
		}

		return false;

}

/*============================ex8===========================*/
void printLeaves(node* root)
{
	// ADD YOUR CODE HERE
if (root == NULL)
  return;
if (root->left == NULL && root->right == NULL){//if it dosent have childerns print root
  printf("%d ",root->data);
}
printLeaves(root->left);
printLeaves(root->right);
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
<<<<<<< HEAD

=======
>>>>>>> ilay
