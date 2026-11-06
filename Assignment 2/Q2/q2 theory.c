
#include<stdio.h>
//Programmer:Syeda Neha Batool Jaffri
//Section:BDS-1A
//Date: 4-Nov-2026
//purpose:Knowing all possible ambical pairs below N 

//function for calculating sum of proper divisors of a number
int sumdivisor(int num){
    int nsum = 0;
    for(int i = 1; i <= num/2; i++){
        if(num % i == 0){
            nsum += i;
        }//end if
    }//end for
    return nsum;
}//end function 

int main(){
    int n; //taking input n and storing
    printf("enter number n");
    scanf("%d", &n);

    int rows = 0;
    printf("Amicable pairs up to %d:\n", n);
   //starting count from 2 as dividing by 0 is error and 1 is for every ambical number a proper divisor
    for(int count = 2; count <= n; count++){
        int nsum = sumdivisor(count);//proper divisors sum for count
        int ndivisorsum = sumdivisor(nsum);//proped divisors sum fir sum of proper divisors of count

        // nsum > count = no duplicate, nsum <= n = both <= n
        if(nsum > count && nsum <= n && ndivisorsum == count){
            printf("(%d,%d)\n", count, nsum);
            rows++;
        }
    }

    if(rows == 0){
        printf("No amicable pairs found.\n");
    } else {
        printf("\nTotal pair: %d", rows);
    }
    return 0;
}
