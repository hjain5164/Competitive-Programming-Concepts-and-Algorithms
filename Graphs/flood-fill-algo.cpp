#include <bits/stdc++.h>
using namespace std;
int R, C;
void printMat(char input[][50], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << input[i][j];
        cout << endl;
    }
}

//FloodFill algo
//ch is the character to be replaced
//color is the new character
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void floodFill(char mat[][50], int i, int j, char ch, char color)
{
    //Base case - Matrix Bounds
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }
    //Figure Boundary condition
    if (mat[i][j] != ch)
    {
        return;
    }
    //Recursive Call
    mat[i][j] = color;
    for (int k = 0; k < 4; k++)
    {
        floodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main()
{
    cin >> R >> C;
    char input[15][50];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> input[i][j];

    printMat(input, R, C);

    floodFill(input, 3, 2, '.', 'r');
    printMat(input, R, C);
    return 0;
}