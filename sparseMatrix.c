// Sparse Matrix to store non-zero elements
#include<stdio.h>

void main(){
    int m, n;
    printf("Enter the dimensions of the 2-D array: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("Enter the array: \n");
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int count = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(arr[i][j] != 0){
                count++;
            }
        }
    }

    int sp[count + 1][3];
    sp[0][0] = m; // stores the no. of rows
    sp[0][1] = n; // stores the no. of cols
    sp[0][2] = count; // stores the no. of non-zero elements

    int cur_row = 1;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(arr[i][j] != 0){
                sp[cur_row][0] = i;
                sp[cur_row][1] = j;
                sp[cur_row][2] = arr[i][j];
                cur_row++;
            }
        }
    }

    printf("\nThe Sparse Matrix is: \n");
    for(i = 0; i < cur_row; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", sp[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
}