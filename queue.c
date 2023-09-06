// Implentation of queue using array in C
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int first, last, size, arr[100];
};

typedef struct Queue Queue;

void initialize(Queue);
void enqueue(Queue, int item);
int dequeue(Queue);
void display(Queue);

void main(){
    Queue q1;
    int choice;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your chioce: ");
        scanf("%d", &choice);
        int item;
        switch(choice){
            case 1:
                printf("Enter an item to enqueue: ");
                scanf("%d", &item);
                enqueue(q1, item);
                break;
            case 2:
                item = dequeue(q1);
                printf("Deleted item: %d", item);
                break;
            case 3:
                display(q1);
                break;
            case 4:
                printf("Exit");
                exit(0);
                break;
            default:
                printf("Invalid input");
        }
    }
    getchar();
}

void enqueue(Queue q, int item){
    if(q.last == q.size - 1){
        printf("Overflow");
        return;
    }
    if(q.first == -1 && q.last == -1){
        q.first++;
    }
    q.last++;
    q.arr[q.last] = item;
}

int dequeue(Queue q){
    if((q.first == -1 && q.last == -1) || (q.first > q.last)){
        printf("Underflow");
        return 0;
    }
    int item = q.first;
    q.first++;
    return item;
}

void display(Queue q){
    int i;
    printf("Items in Queue are: ");
    for(i = 0; i < q.size; i++){
        printf("%d ", q.arr[i]);
    }
}

void initialize(Queue q){
    q.first = -1;
    q.last = -1;
    q.size = 100;
}