/*
Program description: Linked Lists and Structures

Functions per the lab manual include:
CreateListNoNodes: Create an empty linked list.
CreateListNode: Create a linked list with 1 entry with data to fill it as a parameter.
InsertFront: Inserts a node at the front of the linked list.
InsertMiddle: Inserts a node into the middle of the list.
InsertEnd: Inserts a node at the end of the list.
DeleteFront: Deletes the first node in the list.
DeleteMiddle: Deletes a node in the middle of the list.
DeleteEnd: Deletes a node at the end of the list.
Traverse: traverses the list based on some key value in the data portion of the node.
LookUpByIndex: Find a node by an index number. Returns -1 if it doesn't exist.
PrintNode: Prints information in the current node: first name, last name, PUID, and age.


**********************************************

Date last modified: 3/29/23

Libraries Included: stdio.h

CONSTANTS Defined: None

**********************************************

*/

//# includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 30

//Struct Definition
typedef struct student
{

char firstName[MAXSIZE];
char lastName[MAXSIZE];
int puid;
int age;
struct student* next;

};

//Function prototypes. Function code was referenced from opentechguides.com and a bit of OpenAI generation
struct student* CreateListNoNodes();
struct student* CreateListNode(char first[], char last[], int puid, int age);
void PrintAll(struct student* head);
struct student* structCreate();
struct student* InsertFront(struct student* head, char first[], char last[], int puid, int age);
struct student* InsertEnd(struct student* head, char first[], char last[], int puid, int age);
struct student* DeleteFront(struct student* head);
struct student* DeleteEnd(struct student* head);
struct student* PushLL(struct student* head);
struct student* PopLL(struct student* head);
int SizeLL(struct student* head);
bool EmptyLL(struct student** head);
struct student* EnqueueLL(struct student* head);
struct student* DequeueLL(struct student* head);
void PushA();
void PopA();
int SizeA();
bool EmptyA();



//Global variables
int option = 0;
char tempFirst[MAXSIZE];
char tempLast[MAXSIZE];
int tempPuid;
int tempAge;
int temp = 1; //counter for struct elements
int linkedMoves = 0;
int arryMoves = 0;

//Array list vars
int incr = 0; //Current last index of the array
char* firstArry[MAXSIZE];
char* lastArry[MAXSIZE];
int puidArry[30];
int ageArry[30];
int top = 0;
int arrySize = 1;

//Start of main **********************************************************************************************
int main()
{

//Gives user prompts to enter node details and creates the node
struct student* head = structCreate();
head->next = structCreate();
(head->next)->next = structCreate();
((head->next)->next)->next = structCreate();

printf("\nElements in the list:\n\n");
PrintAll(head);


//Option to use a stack or queue
int option1 = 0;
do
{
printf("\nWould you like to: use a stack (1), queue (2), or end (3) ");
scanf("%d", &option1);
if (option1 == 1) //STACK CODE
{

printf("\nPlease choose from the list of commands:");
printf("\n\n1) Pop - Delete a node from the stack");
printf("\n2) Push - Add a node to the stack");
printf("\n3) Print the stack");
printf("\n4) Empty the stack");
printf("\n5) Print moves made\n");
int op1 = 0;
scanf("%d", &op1);
switch(op1)
{

case 1:
//Delete the top node
printf("\n");
head = PopLL(head);
printf("\nThe new stack: \n");
PrintAll(head);
break;


case 2:
//Add a node to the stop of the stack
printf("\n");
head = PushLL(head);
printf("\nThe new stack: \n");
PrintAll(head);
break;

case 3:
//Print the stack
printf("\n");
PrintAll(head);
int sizeOfStack = SizeLL(head);
printf("\nThe size of the stack: %d\n\n", sizeOfStack);
break;

case 4:
//Empty stack
printf("\n");
EmptyLL(&head);
printf("The new queue: \n");
PrintAll(head);
break;

case 5:
//Print moves
printf("\n");
printf("Number of linked list moves made: %d\nNumber of array moves made: %d\n\n", linkedMoves, arryMoves);
break;

} //End of stack switch case

}






else if (option1 == 2) //QUEUE CODE
{

printf("\nPlease choose from the list of commands:");
printf("\n\n1) Enqueue - Add a node to the queue");
printf("\n2) Dequeue - Delete a node from the queue");
printf("\n3) Print the queue");
printf("\n4) Empty the queue\n");
int op2 = 0;
scanf("%d", &op2);
switch(op2)
{

case 1:
//Enqueue
printf("\n");
head = EnqueueLL(head);
printf("\nThe new queue: \n");
PrintAll(head);
break;

case 2:
//Dequeue
printf("\n");
head = DequeueLL(head);
printf("\nThe new queue: \n");
PrintAll(head);
break;

case 3:
//Print
printf("\n");
PrintAll(head);
int sizeOfQueue = SizeLL(head);
printf("\nThe size of the stack: %d\n\n", sizeOfQueue);
break;

case 4:
//Empty the queue
printf("\n");
EmptyLL(&head);
printf("The new queue: \n");
PrintAll(head);
break;

case 5:
//Print moves
printf("\n");
printf("Number of linked list moves made: %d\nNumber of array moves made: %d\n\n", linkedMoves, arryMoves);
break;



} //End of queue switch case


}
} while (option1 != 3);
return 0;

} //End of main ***********************************************************************************************



//Function to create a linked list with one node
struct student* CreateListNode(char first[MAXSIZE], char last[MAXSIZE], int puid, int age)
{

	struct student* node = (struct student*)malloc(sizeof(struct student)); //Allocates memory for 1 node of a structure
	node->next = NULL; //points the end of this node to null
		for (int i = 0; i < MAXSIZE; i++)
			node->firstName[i] = first[i]; //data entry into the list
		for (int i = 0; i < MAXSIZE; i++)
			node->lastName[i] = last[i]; // ^
	node->puid = puid; // ^^^
	node->age = age;
	return node;

}

//Print all nodes
void PrintAll(struct student* head)
{
	struct student* current = head;
		while (current != NULL) //While there is at least an element in the list
		{//Print everything and move on
			printf("First name: %s\n", current->firstName);
			printf("Last name: %s\n", current->lastName);
			printf("PUID: %d\n", current->puid);
			printf("Age: %d\n\n", current->age);
			current = current->next;
		}
}

//Asks the user for input and creates a node
struct student* structCreate()
{
	printf("\nStudent #%d:\n\nFirst name: ", temp);
	scanf("%s", tempFirst);
	printf("\nLast name: ");
	scanf("%s", tempLast);
	printf("\nPUID: ");
	scanf("%d", &tempPuid);
	printf("\nAge: ");
	scanf("%d", &tempAge);

	firstArry[incr] = tempFirst;
	lastArry[incr] = tempLast;
	puidArry[incr] = tempPuid;
	ageArry[incr] = tempAge;

	return CreateListNode(tempFirst, tempLast, tempPuid, tempAge);
}


//Function to create a list node at the end of the linked list
struct student* InsertEnd(struct student* head, char first[MAXSIZE], char last[MAXSIZE], int puid, int age)
{
        //Create a node
        struct student* node = CreateListNode(first, last, puid, age);
        struct student* currentNode = head;

        //If the head node has nothing in it
        if (currentNode == NULL)
        {
                head == node; //This node is the new head
        }
        else
        {
                while (currentNode->next != NULL) //Keep iterating through nodes until it is the last one
                {
                        currentNode = currentNode->next; //Move down the list
                } //End of the while
        currentNode->next = node; //Then, assign the created node to be after the head node
        }//else end
	return head;
} //End of the InsertEnd function


struct student* InsertFront(struct student* head, char first[MAXSIZE], char last[MAXSIZE], int puid, int age)
{
        struct student* node = CreateListNode(first, last, puid, age); //Makes a new node
        node->next = head; //The end of this node points to the head node
        //head = node; //Sets the head reference to this as the new node
	return node;
}//End of InsertFront function


//Deletes the first node in the list
struct student* DeleteFront(struct student* head)
{

        if (head == NULL) //If the header doesnt exist yet, the list doesnt exist. Print an error.
                {
                        printf("\nThis list has no nodes in it. :(");
                }

	struct student* currentNode = head; //Create a new node and assign it to the head node
	currentNode = currentNode->next; //Set the head reference to the seconf node
	free(head); //Free memory for the first node
	head = NULL;
	return currentNode;
}//End of DeleteFront function


//Deletes the last node in the list
struct student* DeleteEnd(struct student* head)
{

        if (head == NULL)//If the head doesnt exist, the list doesnt exist. Print an error.
        {
        printf("There is no node here to delete :(");
        }

        struct student* currentNode = head; //Create the node for head reference
        struct student* prevNode = NULL; //Create a node to house the previous node

        while (currentNode->next != NULL) //Until we are at the end of the list
        {
                prevNode = currentNode; //the previous node is the one we are on
                currentNode = currentNode->next; //Move to the next node
        }

        if (prevNode == NULL) //If we are at the end of the list
        {
                head = NULL; //Delete the node
        }
        else
        {
                prevNode->next = NULL; //Set the end of the node to point to nothing. End of the list
        }

free(currentNode); //Free the memory up from the deleted node
}//End of DeleteEndFunction

//Adds node to the top of stack
struct student* PushLL(struct student* head)
{
        printf("\nStudent:\n\nFirst name: ");
        scanf("%s", tempFirst);
        printf("\nLast name: ");
        scanf("%s", tempLast);
        printf("\nPUID: ");
        scanf("%d", &tempPuid);
        printf("\nAge: ");
        scanf("%d", &tempAge);
	head = InsertFront(head, tempFirst, tempLast, tempPuid, tempAge);
	PushA();
	linkedMoves++;
return head;
}

//Deletes node from the top of the stack
struct student* PopLL(struct student* head)
{
linkedMoves++;
DeleteFront(head);
PopA();
}

//End of stack functions : )))))))))))))) start of queue functions




//Adds a node to the back of the queue
struct student* EnqueueLL(struct student* head)
{

        printf("\nStudent:\n\nFirst name: ");
        scanf("%s", tempFirst);
        printf("\nLast name: ");
        scanf("%s", tempLast);
        printf("\nPUID: ");
        scanf("%d", &tempPuid);
        printf("\nAge: ");
        scanf("%d", &tempAge);
	head = InsertEnd(head, tempFirst, tempLast, tempPuid, tempAge);
	linkedMoves++;
	PushA();
return head;
}

//Deletes the first node in the queue
struct student* DequeueLL(struct student* head)
{
linkedMoves++;
DeleteFront(head);
}

//Returns the size of the stack or queue
int SizeLL(struct student* head)
{

struct student* currentNode = head;
int sizeCount = 1;
	while (currentNode != NULL && currentNode->next != NULL)
	{
	currentNode = currentNode->next;
	sizeCount++;
	}
PopA();
return sizeCount;
}


//Empties the stack or queue
bool EmptyLL(struct student** head)
{

//struct student* currentNode = *head;
bool status = false; //Var to track if the stack or queue is empty
while (status != true)
	{
		if ((*head) != NULL)
		{
			*head = DeleteFront(*head);
			linkedMoves++;
			//currentNode = currentNode->next;
		}
	else if ((*head) == NULL)
		status = true;
	}
EmptyA();
return status;
}

void PushA()
{
arrySize++; //Another element in the array

	for (int j = 0; j<(arrySize+1); j++)
	{
	top++; //Increment the top of the stack
	firstArry[top] = tempFirst; //Move it over 1
	lastArry[top] = tempLast; //^
	puidArry[top] = tempPuid; //^
	ageArry[top] = tempAge; //^
	arryMoves++; //Add a move made
	}

}


void PopA()
{

arrySize--;//Decrement the size of the array
	firstArry[arrySize-1] = NULL; //Frees the space
	lastArry[arrySize-1] = NULL;
	puidArry[arrySize-1] = 0;
	ageArry[arrySize-1] = 0;
	arryMoves++;

	for (int j = 0; j<(arrySize+1); j++)
	{
		firstArry[arrySize-1] = firstArry[arrySize-2]; //Moves the first element back
		lastArry[arrySize-1] = lastArry[arrySize-2]; //Moves the second element back
		puidArry[arrySize-1] = puidArry[arrySize-2]; //Moves the third element back
		ageArry[arrySize-1] = ageArry[arrySize-2]; //Moves the last element back
		arryMoves++;

	}

}

//Returns the size of the stack
int SizeA()
{

return arrySize; //Global variable already created to determine this value

}


bool EmptyA()
{

if (firstArry[0] == NULL)
	return true;
	else
	return false;
for (int i = 0; i < arrySize; i++) //Iterate through the whole array and delete everything
	{
	firstArry[i] = NULL;
	lastArry[i] = NULL;
	puidArry[i] = 0;
	ageArry[i] = 0;
	}

}
