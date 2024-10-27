#include <stdio.h>
#define Max 3

void rotate(int (*arr)[Max], int row, int col){
    int i ;
    if(row <= 1 && col <= 1){ //means no need to rotation there are one element in center
        return;
    }
    int temp = arr[0][0];
    for(i =1; i < row; i++){ //rotating first row
        arr[i-1][0] = arr[i][0];
    }
    for( i =1; i < col; i++){
        arr[row-1][i-1] = arr[row-1][i]; //rotating last colum
    }
    for( i = row-2; i >= 0; i--){ //rotating last row
        arr[i+1][col-1] = arr[i][col-1];
    }
    for( i = col-2; i>=1; i--){ //rotating first column
        arr[0][i+1] = arr[0][i];
    }
    arr[0][i+1] = temp;
    rotate((int (*)[Max])(&arr[1][1]), row-2, col -2); 
}



void print_matrix(int arr[][3], int rows, int col)
{
    if (rows == 0) //base case
    {
        return;
    }
    for (int j = 0; j < col; j++)
    {
        printf("%d ", arr[rows - 1][j]);
    }
    printf("\n");
    print_matrix(arr, rows - 1, col);
}


void print_recur(int arr[][3], int pos_col, int pos_rows, int rows, int col){
    if(pos_rows >= rows){
        return;
    }
    printf("%d ", arr[pos_rows][pos_col]);
    if(pos_col == col -1){
        printf("\n");
        print_recur(arr, 0 , pos_rows +1, rows, col);
    }else{
        print_recur(arr, pos_col+1, pos_rows, rows, col);
    }
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


void print_row_wise(int (*Arr)[3], int row, int col){
    if(col == 0){
        return;
    }
    for(int i = 0; i < row; i++){
        printf("%d ", Arr[i][col-1]);
    }
    printf("\n");
    print_row_wise(Arr, row, col -1);

}



// for matrix is while loop is better

int main()
{                   //0 1 2 
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(arr) / sizeof(arr[0]);      // no of rows in matrix
    int col = sizeof(arr[0]) / sizeof(arr[0][0]); // no of col in matrix
    int i = 0;
    int result[3][3];
    while (i < rows)
    {
        int j = 0;
        while (j < col)
        {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    print_matrix(arr, rows, col); //reverse column wise 
    print_recur(arr, 0, 0, rows, col); // column wise
    print_recur2(arr,0,rows, col); //column wise
    printf("________________________\n");
  // print_row_wise(arr, rows, col); //reverse row wise
    
    //best way to do matrix think one terms of recursion and another think in terms ofloop
    rotate(arr, rows, col);
    print_recur2(arr, 0, rows, col);
} 

