#include<iostream>
using namespace std;
/* list node */
struct node
{
	int data;
	struct node* next;
};

/*Function to print linked list */
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

struct node *newNode(int key)
{
	struct node *temp = new struct node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

struct node * checkLoop(struct node * head)
{
	struct node * slowPtr = head, *fastPtr = head;
	while(fastPtr->next != NULL)
	{
		slowPtr = slowPtr->next;
		fastPtr =  fastPtr->next->next;
		if(slowPtr == fastPtr) break;
	}
	if(fastPtr == NULL) return NULL;

	slowPtr = head;
	while(slowPtr != fastPtr)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	return fastPtr;
}

/* Drier program to test above function*/
int main()
{
	struct node *head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;
	/*printList(head);*/

	struct node * temp = checkLoop(head);
	cout << " Loop detected at "<< temp->data;

	/*printf("Linked List after removing loop \n");
	printList(head);*/
	return 0;
}