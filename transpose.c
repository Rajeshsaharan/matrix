#include <stdio.h>
#define Max 3
void transpose(int (*arr)[Max], int pos_row, int row, int col)
{
    if(pos_row >= row){
        return;
    }
    for(int pos_col = pos_row+1; pos_col < col; pos_col ++){
        int temp = arr[pos_row][pos_col];
        arr[pos_row][pos_col] = arr[pos_col][pos_row];
        arr[pos_col][pos_row] = temp;
    }
    transpose(arr, pos_row+1, row, col);
}



void reverse_row(int (*arr)[Max], int pos_row, int row, int col){
    if(pos_row >= row){
        return;
    }
    int start = 0;
    int end = col -1;
    while(start < end){
        int temp = arr[pos_row][start];
        arr[pos_row][start] = arr[pos_row][end];
        arr[pos_row][end] = temp;
        start++;
        end--;

    }
    reverse_row(arr, pos_row +1, row , col);
}

void reverse_col(int (*arr)[Max], int pos_col , int row, int col){
    if(pos_col >= col){
        return;
    }
    int start = 0;
    int end = row-1;
    while(start < end){
        int temp = arr[start][pos_col];
        arr[start][pos_col] = arr[end][pos_col];
        arr[end][pos_col] = temp;
        start++;
        end--;

    }
    return reverse_col(arr, pos_col+1, row, col);
}



void  print_recur2(int  (*ARR)[3], int pos_row, int row , int col){
    if(pos_row >= row){
        return;
    }
    for(int j = 0; j< col;j ++){
        printf("%d ", ARR[pos_row][j]);
    }
    printf("\n");
    print_recur2(ARR, pos_row+1, row, col);
}


int main(){
    int arr[Max][Max] = {{1,2,3}, {4,5,6}, {7, 8,9}};
    print_recur2(arr, 0, Max, Max);
    reverse_col(arr,0,Max, Max);
    transpose(arr,0,Max, Max);
    printf("___________________\n");
    print_recur2(arr,0,Max, Max);
    
}