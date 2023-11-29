// Insertion Sort
#include<stdio.h>

void insertionSort(int* arr, int n);

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
	insertionSort(arr, n);
	
	// Print the array
	printf("Array after sorting: ");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	return 1;
}

void insertionSort(int* a, int n){
	int i, j, temp;
	for(i = 1; i < n; i++){
		temp = a[i];
		j = i - 1;
		while(temp < a[j]){
			a[j+1] = a[j];
			j--;
			if(j == -1) break;
		}
		a[j+1] = temp;
	}
}