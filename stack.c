// Implementation of stack using array in C
#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top, size, arr[100];
} Stack_default = {-1, 100, {}};

typedef struct Stack Stack;

void push(Stack*, int item);
int pop(Stack*);
void display(Stack*);

void main(){
    Stack stack1 = Stack_default;
    int choice;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int item;
        switch(choice){
            case 1:
                printf("Enter an item to Push: ");
                scanf("%d", &item);
                push(&stack1, item);
                break;
            case 2:
                item = pop(&stack1);
                printf("Deleted item: %d\n", item);
                break;
            case 3:
                display(&stack1);
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

void push(Stack *stack, int item){
    if(stack->top == stack->size - 1){
        printf("Overflow");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = item;
}

int pop(Stack *stack){
    if(stack->top == -1){
        printf("Underflow");
        return 0;
    }
    int item = stack->top;
    stack->top--;
    return item;
}

void display(Stack *stack)
{
    int i;
    printf("Items in Stack are: ");
    for(i = 0; i <= stack->top; i++){
        printf("%d ", stack->arr[i]);
    }
}
