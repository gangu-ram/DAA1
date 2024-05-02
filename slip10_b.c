#include <stdio.h>
#include <stdbool.h>

#define N 8
void printSolution(int board[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col) 
{  
    for (int i = 0; i < col; i++) 
    {
    
        if (board[row][i]) 
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i >= 0; i--, j--) 
    {
        if (board[i][j]) 
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0  && i < N  ; i++, j--) 
    {
        if (board[i][j]) 
        {
            return false;
        }
    }
    return true;
}
bool solveNQueensUtil(int board[N][N], int col) 
{
    if (col >= N) 
    {
        return true;
    }
    for (int i = 0; i < N; i++) 
    {
        if (isSafe(board, i, col)) 
        {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1)) 
            {
                return true;  
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQueens() 
{
    int board[N][N] = { {0} };

    if (!solveNQueensUtil(board, 0)) 
    {
        printf("Solution does not exist");
        return;
    }

    printf("Solution exists:\n");
    printSolution(board);
}

int main() 
{
    solveNQueens();
    return 0;
}
