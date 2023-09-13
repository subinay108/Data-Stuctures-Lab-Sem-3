// n-ary Tree Reading and displaying using array 
// node -> child
// node -> parent
#include<stdio.h>

struct Tree{
    int n;
    int size;
    int arr[100];
} Tree_default = {2, 100, {}};

typedef struct Tree Tree;
 
int getChildNode(Tree*, node);
int getParentNode(Tree*, node);

void main(){

}