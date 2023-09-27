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
void insertAtLast(Node**, int);
void insertAfter(Node**, Node*, int);
void insertBefore(Node**, Node*, int);
void insertAtPos(Node**, int, int);

void display(Node*);

void main(){
	Node* list = createList();
	int i;
	for(i = 1; i < 11; i++){
		insertAtLast(&list, i);
	}
	display(list);
}

void insertBefore(Node** list, Node* next_node, int value){
	Node* head = *list;
	// create a node
	Node* n = createNode(value);
	
	// set new node->next to next_node
	n->next = next_node; 
	
	// find previous node
	Node* temp = head;
	while(temp->next != next_node){
		temp = temp->next;
	}
	
	// set privious node-> next to new node
	temp->next = n;
}

void insertAfter(Node** list, Node* prev_node, int value){
	Node* head = *list;
	// create a node
	Node* n = createNode(value);
	// set new node->next to next node
	n->next = prev_node->next; 
	// set prev_node->next to new node
	prev_node->next = n;
}

void display(Node *head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

void insertAtLast(Node** list, int value){
	Node* head = *list;
	// create a node
	Node* n = createNode(value);
	// if head is null
	if(head == NULL){
		*list = n;
	}else{
		// traverse upto last node
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		//	printf("%d\n", temp->data);
		// set last node-> next to newnode
		temp->next = n;	
	}
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