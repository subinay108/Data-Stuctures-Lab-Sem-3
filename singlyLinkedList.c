// Implementation of Singly Linked List in C
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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

// Search
int getIndex(Node**, int);

// Get length of a list
int getLength(Node**);

int main(){
	Node* list = createList();
	int choice, element, pos;
	while(1){
		system("cls");
		printf("Singly Linked List\n1.Insert at First\n2.Insert at Last\n\
3.Insert at Position\n4.Delete at First\n5.Delete at Last\n\
6.Delete at Position\n7.Display\n0.Exit\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter element: ");
				scanf("%d", &element);
				insertAtFirst(&list, element);
				printf("%d added at First\nEnter any key to proceed...", element);
				getch();
				break;
			case 2:
				printf("Enter element: ");
				scanf("%d", &element);
				insertAtLast(&list, element);
				printf("%d added at Last\nEnter any key to proceed...", element, pos);
				getch();
				break;
			case 3:
				printf("Enter position: ");
				scanf("%d", &pos);
				if(pos < 0 || pos > getLength(&list)){
					printf("Invalid position");
				}else{
					printf("Enter element: ");
					scanf("%d", &element);
					insertAtPos(&list, pos, element);
					printf("%d added at position %d", element, pos);
				}
				printf("\nEnter any key to proceed...");
				getch();
				break;
			case 4:
				deleteAtFirst(&list);
				printf("\nEnter any key to proceed...");
				getch();
				break;
			case 5:
				deleteAtLast(&list);
				printf("\nEnter any key to proceed...");
				getch();
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d", &pos);
				deleteAtPos(&list, pos);
				printf("\nEnter any key to proceed...");
				getch();
				break;
			case 7:
				printf("The list is: ");
				display(list);
				printf("\nEnter any key to proceed...");
				getch();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid input");
				printf("\nEnter any key to proceed...");
				getch();
		}
	}
	return 0;
}

int getLength(Node** list){
	Node* head = *list;
	Node* h = head;
	int length = 0;
	while(h != NULL){
		length++;
		h = h->next;
	}
	return length;
}

int getIndex(Node** list, int value){
	// returns the position of first occurance of value in the list
	// if there is no occurance then return -1
	Node* head = *list;
	Node* h = head;
	int position = 1;
	while(h->data != value){
		h = h->next;
		position++;
		if(h == NULL){
			position = -1;
			break;
		}
	}
	return position;
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


//This is not working now
// maybe deleting some node which shouln't be
// not referencing the list to head
void deleteAtPos(Node** list, int pos){
	Node* head = *list;
	Node* h = head;
	if(pos < 1){
		printf("Position can\'t be less than 1");
	}else if(pos > getLength(list)){
		printf("Position can\'t be greater than length");
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

void insertAtPos(Node** list, int pos, int value){
	// if position is negative or greater than length then return
	if(pos < 0 || pos > getLength(list)){
		return;
	}
	
	Node* head = *list;
	// if position is 0
	if(pos == 0){
		insertAtFirst(list, value);
		return;
	}
	// position other than 0
	Node* h = *list;
	
	while(--pos){
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