// Selection Sort
#include<stdio.h>

void swap(int*, int*);
void selectionSort(int* arr, int n);

int main(){
	int i, n;
	// Input of the size of the array
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	
	// Declaration of array of size n
	int arr[n];
	
	// Input the array
	printf("Enter the elements of array: ");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	// Sort the Array
	selectionSort(arr, n);
	
	// Print the array
	printf("Array after sorting: ");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	return 1;
}

void selectionSort(int* a, int n){
	int i, j, small, temp;
	for(i = 0; i < n-1; i++){
		small = i;
		for(j = i+1; j <= n-1; j++){
			if(a[small] > a[j]){
				small = j;
			}
		}
		swap(&a[i], &a[small]);
	}
}

void swap(int* a, int* b){
	// swaps a and b
	int temp = *a;
	*a = *b;
	*b = temp;
}