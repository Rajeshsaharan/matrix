#include <stdio.h>
#define Max 3

void reverse(int *arr, int start  , int end){
    if(start > end){
        return;
    }else{
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        return reverse( arr, start +1, end -1);
    }
}

void reverse_row(int (*arr)[Max], int pos_row, int row, int col){
    if(pos_row >= row){
        return;
    }
    reverse(arr[pos_row], 0, col-1);
    reverse_row(arr, pos_row +1, row , col);
}

void  print_recur2(int  (*arr)[Max], int pos_row, int row , int col){
    if(pos_row >= row){
        return;
    }
    for(int j = 0; j< col;j ++){
        printf("%d ", arr[pos_row][j]);
    }
    printf("\n");
    print_recur2(arr, pos_row+1, row, col);
}


void main(){
   int arr[Max][Max] = {{1,2,3}, {4,5,6}, {7,8,9}};
   print_recur2(arr, 0, Max, Max);
   printf("____________________\n");
   reverse_row(arr, 0, Max, Max);
   print_recur2(arr, 0, Max, Max);
}