#include <stdio.h>
#include <stdlib.h>

void printChessBoard(char **chessboard,int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c  ",chessboard[i][j]);
        }
        printf("\n");
    }
}

int isQueenSafe(char **chessboard,int row,int col,int n)
{
    int i,j;

    //Check vertical safety
    for(i=row-1,j=col;i>=0;i--){
        if(chessboard[i][j]=='Q'){
            return 0;
        }
    }

    //check backward left diagonal safety
    for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(chessboard[i][j]=='Q'){
            return 0;
        }
    }
    //check backward right diagonal safety
    for(i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(chessboard[i][j]=='Q'){
            return 0;
        }
    }
    return 1; // Queen Safe
}

void placeQueens(char **chessboard,int n,int row)
{
    int col;
    if(row==n){
        printChessBoard(chessboard,n);
        printf("\n\n");
        return;
    }
    for(col=0;col<n;col++){
        if(isQueenSafe(chessboard,row,col,n)){
            chessboard[row][col]='Q';
            placeQueens(chessboard,n,row+1);
            chessboard[row][col]='_';
        }
    }
}

int main()
{
    char **chessboard;
    int n,i,j;
    printf("Enter the size of the board:");
    scanf("%d",&n);
    chessboard = (char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
        chessboard[i] = (char*)malloc(n*sizeof(char));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            chessboard[i][j]='_';
        }
    }

    printf("\nChessboard before placing queens:\n\n");
    printChessBoard(chessboard,n);
     printf("\nChessboard after placing queens:\n\n");
    placeQueens(chessboard,n,0);


}
