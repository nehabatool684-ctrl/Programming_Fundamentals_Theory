#include <stdio.h>
//Programmer:Syeda Neha Batool Jaffri
//Section:BDS-1A
//Date:4-Nov-2026
//Purpose: Bakery Festival Manegment System

//validate days
int getValidDays(){
    int daysnum;
    do {
        printf("Enter number of days for festival (1-7): ");
        scanf("%d", &daysnum);
        if(daysnum < 1 || daysnum > 7)
            printf("Invalid number, retry: ");
    } while(daysnum < 1 || daysnum > 7);//end while do
    return daysnum;
}//end function

float calculateDailySales(int dayNum){//Calculate sales for each day
    int numOrder;//orders in a day
    printf("Enter number of orders for day %d: ", dayNum);
    scanf("%d", &numOrder);

    float amountorder[numOrder];//list costs per order stored in array amountorder
    float total = 0;//total cost
    float highest = 0;//highest cost of all sales perday

    for(int i = 0; i < numOrder; i++){
        do {//validating amount is not negative
            printf("Enter amount for order %d: ", i + 1);
            scanf("%f", &amountorder[i]);
            if(amountorder[i] <= 0) printf("Invalid, enter again: ");
        } while(amountorder[i] <= 0);

        total += amountorder[i];//finding total cost of sales
        if(i == 0 || amountorder[i] > highest) highest = amountorder[i];
    }//end for
    
    float average = total / numOrder;//average per day
    printf("Total Sales: Rs %.2f\nAverage order: Rs %.2f\nHighest Order: Rs %.2f\n", total, average, highest);
    return total;
}//end function

int findHighestSalesDay(float dailySales[], int numOfDays){
    int bestDay = 0;//aking index of day with highest sale
    float mostSale = dailySales[0];//highest sale cost
    for(int i = 1; i < numOfDays; i++){
        if(dailySales[i] > mostSale){//comparing 
            mostSale = dailySales[i];//value of highest sale price
            bestDay = i;//index of that day
        }
    }
    return bestDay + 1;//converting from array t human counts as indexes are from 0..
}//end function

void displayBarChart(float dailySales[], int numOfDays){
    for(int d = 0; d < numOfDays; d++){
        printf("Day %d: ", d + 1);//converting from array to human so +!
        int stars = (int)dailySales[d] / 100;//type casting from float to integer to ignore any value lesser than 100
        for(int i = 0; i < stars; i++) printf("*");
        printf(" (Rs %.2f)\n", dailySales[d]);
    }//end for
}//end function

int main(){
    int days = getValidDays();//total days for festival
    float totalSales[days];//stores list of total sales per day , has length of days of festival
    float totals = 0.0;//total cost for all days

    for(int i = 0; i < days; i++){//calculating total sales for whole festival
        totalSales[i] = calculateDailySales(i + 1);
        totals += totalSales[i];
    }//end for

    int highDay = findHighestSalesDay(totalSales, days);
    float highestSale = totalSales[highDay - 1];//converting from human to array, the function returns day+1 already in human so to convert back from human to array do -1

    printf("======= Festival Summary =======\n");
    printf("Total Festival Sales: Rs %.2f\n", totals);
    printf("Day with highest Sale: %d\n", highDay);
    printf("Highest daily sale: Rs %.2f\n", highestSale);

    printf("=== Daily Sales BarChart ===\n");
    displayBarChart(totalSales, days);
    return 0;
}
