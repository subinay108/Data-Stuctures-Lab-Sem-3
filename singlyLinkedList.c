// Implementation of Singly Linked List in C
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;
 
Node* createList();

Node* createNode(int);

void insertAtFirst(Node**, int);
void insertAtLast(Node*);
void insertAfter(Node*);
void insertBefore(Node*);
void insertAtPos(Node*);

void display(Node*);

void main(){
	Node* list = createList();
	int i;
	for(i = 1; i < 11; i++){
		insertAtFirst(&list, i);
	}
	display(list);
}

void display(Node *head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

void insertAtFirst(Node** list, int value){
	Node* head = *list;
	// create a node
	Node* n = createNode(value);
	
	// set new node next to head
	n->next = head;
	
	// set head to address of new node
	*list = n;
}

Node* createNode(int value){
	Node* n = (Node *) malloc(sizeof(Node));
	n->data = value;
	n->next = NULL;
	return n;
}

Node* createList(){
	Node *n = NULL;
	return n;
}