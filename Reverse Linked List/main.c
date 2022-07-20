/* Emircan KÝREZ - Ch3rry */
/* Last Update: 20/07/2022 */
/*
----------------------- INFORMATION ---------------------------
• It is recommended to read the README.md file before proceeding to the project.
• For any questions and suggestions related to the project, via the e-mail address "emircan200123@hotmail.com", you can contact me by
typing "Github | C-EN / Reverse Linked List" to the subject line 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}NODE;

void insert(NODE **head, int value);
NODE *createNode(int value);
void printList(NODE *head);
void reverse(NODE **head);

int main(){
	NODE *head = NULL;
	insert(&head, 9);
	insert(&head, 7);
	insert(&head, 5);
	insert(&head, 2);
	printList(head);
	reverse(&head);
	printList(head);
	reverse(&head);
	printList(head);
	return 0;
}

void insert(NODE **head, int value){
	NODE *newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
}

NODE *createNode(int value){
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	tmp->value = value;
	tmp->next = NULL;
	return tmp;
}

void printList(NODE *head){
	while(head != NULL){
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void reverse(NODE **head){
	NODE *prev = NULL, *current = *head, *next;
	while(current != NULL){
		next = current->next; //save next node
		current->next = prev; //current node shows previous node
		prev = current; //update prev node
		current = next; //update current node
	}
	*head = prev;
}
