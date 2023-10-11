// Implementation of Singly Linked List in C
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;
 
Node* createList();

Node* createNode(int);

// Insertions
void insertAtFirst(Node**, int);
void insertAtLast(Node**, int);
void insertAfter(Node**, Node*, int);
void insertBefore(Node**, Node*, int);
void insertAtPos(Node**, int, int);

// Deletions
void deleteAtFirst(Node**);
void deleteAtLast(Node**);
void deleteAtPos(Node**, int);

// Display
void display(Node*);

int main(){
	Node* list = createList();
	int i;
	for(i = 1; i < 11; i++){
		insertAtLast(&list, i);
	}
	deleteAtFirst(&list);
	deleteAtLast(&list);
	deleteAtPos(&list, 1);
	display(list);
	return 0;
}

void deleteAtFirst(Node** list){
	Node* head = *list;
	if(head == NULL){
		printf("List is empty");
	}
	else{
		Node* next = head->next;
		free(head);
		*list = next;
	}
}

void deleteAtLast(Node** list){
	Node* head = *list;
	if(head == NULL){
		printf("List is empty");
		return;
	}
	Node* h = head;
	Node* prev;
	while(h->next != NULL){
		prev = h;
		h = h->next;
	}
	free(h);
	prev->next = NULL;
}

void deleteAtPos(Node** list, int pos){
	Node* head = *list;
	Node* h = head;
	if(pos < 1){
		printf("Position can't be less than 1");
	}
	while(--pos){
		h = h->next;
	}
	if(h == head){
		*list = head->next;
	}
	free(h);
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

void display(Node* head){
	Node* h = head;
	while(h != NULL){
		printf("%d ", h->data);
		h = h->next;
	}
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