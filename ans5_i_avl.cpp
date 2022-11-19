// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	int height;
};

// function to get the height of the tree
int height(Node *root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

// function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *right_part)
{
	Node *x = right_part->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = right_part;
	right_part->left = T2;

	// Update heights
	right_part->height = max(height(right_part->left),height(right_part->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
Node *leftRotate(Node *left_part)
{
	Node *y = left_part->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = left_part;
	left_part->right = T2;

	// Update heights
	left_part->height = max(height(left_part->left),height(left_part->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *root)
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

/*Recursive function to insert a key
in the subtree rooted with node and
returns the new root of the subtree.*/
Node* insert(Node* node, int data)
{
	/*  Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(data));

	if (data< node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else // Equal keys are not allowed in BST
		return node;

	/*  Update height of this ancestor node */
	node->height = 1 + max(height(node->left),height(node->right));

	/*  Get the balance factor of this parent
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 &&data< node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder
// traversal of the tree.
void preOrder(Node *root)    //preOrder traversal function
{
	if(root != NULL)
	{
		cout << root->data<< " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node *root = NULL;     //initially root of tree is null
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	/* The  AVL Tree would look like
		 	30
	    / \
		20  40 
	 / \   \
	10 25  50
	*/
	cout << "Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);
	
	return 0;
}
