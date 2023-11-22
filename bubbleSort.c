#include<stdio.h>

void swap(int*, int*);
void bubbleSort(int arr[], int n);

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
	bubbleSort(arr, n);
	
	return 1;
}

void swap(int* a, int* b){
	// swaps a and b
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n){
	int i, j, flag, n_swaps = 0, n_comps = 0;
	for(i = 0; i < n; i++){
		flag = 0;
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				flag = 1;
				n_swaps++;
			}
			n_comps++;
		}
		if(flag == 0){
			break;
		}
	}
	n_comps++;
	
	printf("\nArray after sorting: ");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\nNo. of comparisons: %d", n_comps);
	printf("\nNo. of swaps: %d", n_swaps);
}