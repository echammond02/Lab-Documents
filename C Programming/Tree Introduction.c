/*

Program description: Linked Lists Advanced and Trees Introduction.

**********************************************

Date last modified: 4/13/23

Libraries Included: stdio.h

CONSTANTS Defined: None

**********************************************


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Struct definition
typedef struct node
{
int data;
struct node* left;
struct node* right;
}node;


//Function prototypes
struct node* CreateTree0();
struct node* CreateTree1(int input);
struct node* AddNode(struct node* root, int value);
struct node* AddNode2(struct node* root, int value);
struct node* DeleteNode(struct node* root, int value);
void TraverseInOrderPrint(struct node* root);
void TraversePreOrderPrint(struct node* root);
void TraversePostOrderPrint(struct node* root);
bool TraverseFind(struct node* root, int value);

//Global variables
//--none

//Start of main
int main()
{

//Temp varibables for file input
char command[30];
char command2[30];

struct node* root = NULL;

//File input
FILE * file = fopen("testing.txt", "r"); //Open file
while (fscanf(file, "%s %s", command, command2) != EOF)
{
//Print the contents of the file
//printf("%s %s\n", command, command2);


// **************************************** Cases for commands

//Insert a node
if ((strcmp(command, "insert") == 0) || (strcmp(command, "Insert") == 0))
	{
	int tempNum = atoi(command2);
	printf("\nInserting node %d\n", tempNum);
	root = AddNode(root, tempNum);
	}
//Delete a node
if ((strcmp(command, "delete") == 0) || (strcmp(command, "Delete") == 0))
	{
	int tempNum = atoi(command2);
	printf("\nDeleting node %d\n\n", tempNum);
	root = DeleteNode(root, tempNum);
	}
//Traverse InOrder
if ((strcmp(command2, "in-order") == 0) || (strcmp(command, "In-Order") == 0))
	{
	printf("In-Order traversal: \n\n");
	TraverseInOrderPrint(root);
	}
//Traverse PreOrder
if ((strcmp(command2, "pre-order") == 0) || (strcmp(command, "Pre-Order") == 0))
	{
	printf("Pre-Order traversal: \n\n");
	TraversePreOrderPrint(root);
	}
//Traverse PostOrder
if ((strcmp(command2, "post-order") == 0) || (strcmp(command, "Post-Order") == 0))
	{
	printf("Post-Order traversal: \n\n");
	TraversePostOrderPrint(root);
	}

}


printf("Final tree: \n------------------------------------\n\n");
TraversePreOrderPrint(root);
fclose(file); //Close the file
return 0;
}



//Function to create an empty binary tree  with a root pointer.
struct node* CreateTree0()
{
	struct node* root;
	root->left = NULL;
	root->right = NULL;
	return NULL;
}

//Function to create 1 root node in a tree
struct node* CreateTree1(int input)
{
	struct node* tree = (struct node*)malloc(sizeof(struct node)); //Allocates memory for 1 node
	tree->data = input; //Sets the data parameter of the node to the input
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}


//Function to Add a node to the tree.
struct node* AddNode(struct node* root, int value)
{
if (root == NULL)
{
root = CreateTree1(value); //If there is no node, create this node as the first root node

}
else //If one already exists, one can be added
	{


struct node* search_node = root;
struct node* pred = root;
while(search_node != NULL) //While not at the end
{
	if(value < search_node->data || value < search_node->data) //If the node will be on the left
	{
		pred = search_node; //Set the predecessor
		search_node = search_node->left; //Move to the left
	}
	else if(value > search_node->data) //Same with the right side
	{
		pred = search_node;
		search_node = search_node->right;
	}
}

struct node* new_node = CreateTree1(value);

if(value < pred->data) //If the value is less than the previous one, create it on the left
pred->left = new_node;
else
pred->right = new_node; //Else create it on the right


//return tree;
	}
return root;
}

//Function to Add the data to the node
struct node* AddNode2(struct node* root, int value)
{
root->data = value;
return root;
}


//Function to print all nodes in order
void TraverseInOrderPrint(struct node* tree)
{
	if (tree == NULL)
	     return;

	TraverseInOrderPrint(tree->left);
	printf("%d\n", tree->data);
	TraverseInOrderPrint(tree->right);

}



//Function to print all nodes preorder
void TraversePreOrderPrint(struct node* tree)
{
	if (tree == NULL)
		return;

	printf("%d\n", tree->data);
	TraversePreOrderPrint(tree->left);
	TraversePreOrderPrint(tree->right);

}


//Function to print all nodes postorder
void TraversePostOrderPrint(struct node* tree)
{
	if (tree == NULL)
		return;
	TraversePostOrderPrint(tree->left);
	TraversePostOrderPrint(tree->right);
	printf("%d\n", tree->data);

}

//Function to delete a node and repair the tree
struct node* DeleteNode(struct node* root, int value)
{

struct node* currentNode = root;
struct node* pred = root;

while (currentNode->data != value)
	{
	if (value < currentNode->data) //If it is less than
		{
		pred = currentNode; //keep track of the previous one
		currentNode = currentNode->left; //move left
		if (currentNode == NULL)
			{
			return root;
			}


		}
	if (value > currentNode->data) //If it is greater than
		{
		pred = currentNode; //keep track of the previous one
		currentNode = currentNode->right; //Move right
		if (currentNode == NULL)
			{
			printf("The node %d does not exist.\n", value);
			return root;
			}
		}
	}
//Leaf Case
if (currentNode->left == NULL && currentNode->right == NULL)
{
	if ((pred->left)->data == value)
	pred->left = NULL;
	else
	pred->right = NULL;

free(currentNode);
currentNode = NULL;
return root;
}

//2 Child case
if (currentNode->left != NULL && currentNode->right != NULL)
{
	pred = currentNode;
	currentNode = currentNode->right; //Move to the successor
	pred->data = currentNode->data; //Predecessor data is this one
	pred->right = currentNode->right; //store all data back 1
	free(currentNode);

return root;
}

//1 Child case
if ((currentNode->left != NULL && currentNode->right == NULL) || (currentNode->left == NULL && currentNode->right != NULL))
{
	//if the node has only a left child
	if (currentNode->left != NULL)
	{
		//Swap the nodes
		pred = currentNode;
		currentNode = currentNode->left;
		pred->data = currentNode->data;
		pred->left = currentNode->left;
		pred->right = currentNode->right;
		free(currentNode);
		currentNode = NULL;
	}

	//If the node has only a right child
	if (currentNode->right != NULL)
	{
		//Swap the nodes
		pred = currentNode;
		currentNode = currentNode->right;
		pred->data = currentNode->data;
		pred->left = currentNode->left;
		pred->right = currentNode->right;
		free(currentNode);
		currentNode = NULL;
	}

return root;
}



}



bool TraverseFind(struct node* root, int value)
{

//same code from the DeleteNode function search part

struct node* currentNode = root;
struct node* pred = currentNode;
while (currentNode->data != value)
        {
        if (value < currentNode->data) //If it is less than
                {
                pred = currentNode;
                currentNode = currentNode->left;
                if (currentNode == NULL)
                        {
			printf("The node %d does not exist\n", value);
                        return false;
                        }
                }
        if (value > currentNode->data) //If it is greater than
                {
                pred = currentNode;
                currentNode = currentNode->right;
                if (currentNode == NULL)
                        {
                        printf("The node %d does not exist\n", value);
                        return false;
                        }
                }
	   else
	return true;
	}
}
