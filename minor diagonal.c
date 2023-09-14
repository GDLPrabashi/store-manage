
#include<stdio.h>

#define SIZE 3 // Matrix size
void main()
{
int A[SIZE][SIZE];
int row, col, sumd2 =0;
/* Input elements in matrix from user */
printf("Enter elements in matrix of size %dx%d: \n", SIZE, SIZE);
for(row=0; row<SIZE; row++)
{
for(col=0; col<SIZE; col++)
{
scanf("%d", &A[row][col]);
}
}
/* Find sum of minor diagonal elements */
for(row=0; row<SIZE; row++)
{
// (row, SIZE – row - 1) is the diagonal from top-right -> bottom-left
sumd2 += A[row][SIZE-1-row];
}
printf("\nSum of minor diagonal elements = %d", sumd2);
}
