#include <stdio.h>
#define Max 5

void rotate(int (*arr)[Max], int row, int col)
{
    int i;
    if (row <= 1 && col <= 1)
    { // means no need to rotation there are one element in center
        return;
    }
    int temp = arr[0][0];
    for (i = 1; i < row; i++)
    { // rotating first row
        arr[i - 1][0] = arr[i][0];
    }
    for (i = 1; i < col; i++)
    {
        arr[row - 1][i - 1] = arr[row - 1][i]; // rotating last colum
    }
    for (i = row - 2; i >= 0; i--)
    { // rotating last row
        arr[i + 1][col - 1] = arr[i][col - 1];
    }
    for (i = col - 2; i >= 1; i--)
    { // rotating first column
        arr[0][i + 1] = arr[0][i];
    }
    arr[0][i + 1] = temp;
    rotate((int(*)[Max])(&arr[1][1]), row - 2, col - 2);
}

void rotate_90_degree(int (*arr)[Max], int row, int col)
{
    int i;
    int j;
    if (row <= 1 && col <= 1)
    {
        return;
    }
    int temp[row - 1]; // storing column item
    int temp2[col-1]; //storing row item;

    // first colum with arr[i][0] 0th column
    int pos_col = col - 1;
    i = 0;
    while (i < row - 1 && pos_col > 0)
    {
        temp[i] = arr[i][0]; // store temp variable
        arr[i][0] = arr[0][pos_col];
        i++;
        pos_col--;
    }
    //last row with dynamic column o to col-1 
    i = 0;
     j = 0;
    while (i < col - 1 && j < row-1){
        temp2[i] = arr[row-1][i];
        arr[row-1][i] = temp[j];
        i++;
        j++;

    }
    // //last colum with changing row || column = col-1
    i =row -1;
    j = 0;
    while(i > 0 && j < col-1){
        temp[j] = arr[i][col-1];
        arr[i][col-1] = temp2[j];
        i--;
        j++;
     }
    // i = col -1; 
    // j = row -1;
    // while(i > 0 && j >=0 ){
    //     arr[i][0] = temp[j];
    //     j--;
    //     i--; 
    // }

    i = col-1;
     j = 0;
    while(i > 0 && j < col -1){
        arr[0][i] = temp[j];
        j++; 
        i--;
    }
     rotate_90_degree((int (*)[Max])(&arr[1][1]),row-2, col-2);

}
void print_recur2(int (*ARR)[Max], int pos_row, int row, int col)
{
    if (pos_row >= row)
    {
        return;
    }
    for (int j = 0; j < col; j++)
    {
        printf("%d ", ARR[pos_row][j]);
    }
    printf("\n");
    print_recur2(ARR, pos_row + 1, row, col);
}

int main()
{
    int arr[Max][Max] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    print_recur2(arr, 0, 5, 5);
    printf("_____________________\n");
    rotate_90_degree(arr, 5, 5);
    print_recur2(arr, 0, 5, 5);
}