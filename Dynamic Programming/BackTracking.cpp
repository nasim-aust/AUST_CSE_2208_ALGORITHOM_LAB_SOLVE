#include<bits/stdc++.h>
#define N 8
using namespace std;

bool online_safe(int board[N][N], int row, int col)
{

    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (int i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool FindPlace(int board[N][N], int col)
{
    if(col >= N)
        return true;
    for(int i=0; i<N; i++)
    {
        if(online_safe(board, i, col))
        {
            board[i][col] = 1;
            if(FindPlace(board, col+1) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}


int main()
{
    int board[N][N] = {0};
    if(FindPlace(board,0) == true)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout << board[i][j] <<" ";
            cout << endl;
        }
    }

    return 0;
}
