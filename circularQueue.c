// Implementation of circular queue using array in C
#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int first, last, size, arr[100];
} CircularQueue_default = {-1, -1, 100, {}};

typedef struct CircularQueue CircularQueue;

void enqueue(CircularQueue*, int item);
int dequeue(CircularQueue*);
void display(CircularQueue*);

void main(){
    CircularQueue cq1 = CircularQueue_default;
    int choice;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int item;
        switch(choice){
            case 1:
                printf("Enter an item to enqueue: ");
                scanf("%d", &item);
                enqueue(&cq1, item);
                break;
            case 2:
                item = dequeue(&cq1);
                printf("Deleted item: %d\n", item);
                break;
            case 3:
                display(&cq1);
                printf("\n");
                break;
            case 4:
                printf("Exit");
                exit(0);
                break;
            default:
                printf("Invalid input\n");
        }
    }
    getchar();
}

void enqueue(CircularQueue *cq, int item){
    // Overflow condition
    if((cq->last + 1) % cq->size == cq->first){
    	printf("Overflow\n");
        return;
    }

    // Empty Queue condition
    if(cq->last == -1 && cq->first == -1){
        cq->first = (cq->first + 1) % cq->size;
    }

    // Other condition
    cq->last = (cq->last + 1) % cq->size;
    cq->arr[cq->last] = item;
}

int dequeue(CircularQueue *cq){
    // Underflow condition
    if(cq->first == -1){
    	printf("Underflow\n");
        return -1;
    }
	
	int item = cq->arr[cq->first];
	
    // If first and last are at same location
    if(cq->first == cq->last){
        cq->first = -1;
        cq->last = -1;
    }else{
    	cq->first = (cq->first + 1) % cq->size;	
	}
    
    return item;
}

void display(CircularQueue *cq){
	// Overflow condition
	if(cq->first == -1){
		printf("Empty Queue");
		return;
	}
	printf("front: %d rear: %d\n", cq->first, cq->last);
    int i;
    for(i = cq->first; i != cq->last; i = (i + 1) % cq->size){
        printf("%d ", cq->arr[i]);
    }
    printf("%d ", cq->arr[cq->last]);
}
