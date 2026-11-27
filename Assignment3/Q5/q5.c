//programmer:Syeda Neha Batool Jaffri
//date: 11/27/2026
//section:BDS-1A
//Roll:26K-2522
//Purpose: making start pattern for input of odd numbers(7 and 21)
//Steps: the start has been divided in to 3 parts(1. head,2. body,3. legs)

#include <stdio.h>
int main(){
    int n;
    printf("Enter number of stars in a side (odd, 3 or more): ");
   scanf("%d",&n);

    int h = n-1;               // rows in the middle and bottom sections
    int max_col = 4*n-3;
    int peak_index = max_col/2;

    char top[n][max_col];
    char body[h][max_col];
    char legs[h][max_col];

    // fill all arrays with spaces
    for(int r=0;r<n;r++)
        for(int c=0;c<max_col;c++)
            top[r][c]=' ';
    for(int r=0;r<h;r++)
        for(int c=0;c<max_col;c++){
            body[r][c]=' ';
            legs[r][c]=' ';
        }

    // top tip
    for(int r=0;r<n;r++){
        top[r][peak_index+r]='*';
        top[r][peak_index-r]='*';
    }
    // arms (last row of top)
    for(int i=0;i<n;i++){
        top[n-1][peak_index+h+i]='*';
        top[n-1][peak_index-h-i]='*';
    }

    // sides slanting inward
    int start=1;
    int end=max_col-2;
    for(int r=0;r<h;r++){
        body[r][start]='*';
        body[r][end]='*';
        start++;
        end--;
    }

    // bottom legs
    for(int r=0;r<h;r++){
        int k=r+1;
        // outer edge
        legs[r][peak_index+h+k]='*';
        legs[r][peak_index-h-k]='*';
        // inner edge (not on the last row)
        if(k<h){
            legs[r][peak_index+2*k-1]='*';
            legs[r][peak_index-2*k+1]='*';
        }
    }

    // printing
    for(int r=0;r<n;r++){
        for(int c=0;c<max_col;c++) printf("%c",top[r][c]);
        printf("\n");
    }
    for(int r=0;r<h;r++){
        for(int c=0;c<max_col;c++) printf("%c",body[r][c]);
        printf("\n");
    }
    for(int r=0;r<h;r++){
        for(int c=0;c<max_col;c++) printf("%c",legs[r][c]);
        printf("\n");
    }
    return 0;
}
