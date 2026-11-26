//programmer:Syeda Neha Batool Jaffri
//date:11/26/2026
//Section:BDS-1A
//Roll:26K-2522
//purpose:making pentagon for assignment 3
//Input:7,21
//Description:The pentagon has been broken in to a pyramid at top and trapezium at bottom
//the code uses 2 functions for each part and each function is called in main function.


#include <stdio.h>
void top_pyramid(int n, int max_col, char pyramid[n][max_col]) {

    // filling pyramid with spaces 
    int i=0;
    for(i; i<n; i++) {
        int j=0;
        for(j; j<max_col; j++) {
            pyramid[i][j] = ' ';
        }
    }

    // filling pyramid
    int row=0;
    for(row; row<n; row++) {

        if(row==0) {
            pyramid[row][2*n-2]='*';
        }
        else {
            int fore = 2*n-2;
            int back = 2*n-2;
//just replacing white spaces with * where needed to make pyramid
            fore = fore + 2*row;
            back = back - 2*row;

            pyramid[row][fore]='*';
            pyramid[row][back]='*';
        }
    }
}
void bottom_trep(int n,int max_col,char trep[n-1][max_col]) {

    // filling array with spaces
    int i=0;
    for(i; i<n-1; i++) {
        int j=0;
        for(j; j<max_col; j++) {
            trep[i][j] = ' ';
        }
    }
//filling the trapezium
    int row=0;
    int start_col=1;
    int end_col=max_col-2;

    for(row; row<n-1; row++) {
    	//just replacing white spaces with * where needed to mke trapezium
        trep[row][start_col]='*';
        trep[row][end_col]='*';

        if(row==n-2) {
            int stars=start_col+2;
            for(stars; stars<end_col; stars+=2) {
                trep[row][stars]='*';
            }
        }
        start_col++;
        end_col--;
    }
}


int main() {

    int n;//number of sides for pentagon of odd numbers
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &n);
    if(n<2) {
        printf("Enter a number greater than 1.");
        return 1;
    }
    int max_col = 4*n-3;
    char trep[n-1][max_col];
    char pyramid[n][max_col];
    //pentagon is made of pyramid at top and 
    top_pyramid(n, max_col, pyramid);
    bottom_trep(n, max_col, trep);

    // Printing pyramid at top
    int row=0;
    int col=0;

    for(row; row<n; row++) {
        for(col=0; col<max_col; col++) {
            printf("%c", pyramid[row][col]);
        }
        printf("\n");
    }


    // Printing trapezium at bottom to complete the pentagon
    int rows=0;
    int cols=0;
    for(rows; rows<n-1; rows++) {
        for(cols=0; cols<max_col; cols++) {
            printf("%c", trep[rows][cols]);
        }
        printf("\n");
    }

    return 0;
}

