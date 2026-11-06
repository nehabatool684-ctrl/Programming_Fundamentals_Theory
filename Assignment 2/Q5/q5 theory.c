#include <stdio.h>
#include <string.h> // for strcmp

//definging all ffunctions
void displayMenu();
void registerMember(char name[], int *studentID, int *memberType);
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks);
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType);
float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine);
void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver);

//Display Menu to users
void displayMenu(){
    printf("\n===== Library Menu =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

// Member registration-FACULTY OR STUDENT
void registerMember(char name[], int *studentID, int *memberType){//taking all address and writing in them to reflect changes in main function
    printf("Enter name: ");
    scanf(" %[^\n]", name); // reads full name with space
    printf("Enter student ID: ");
    scanf("%d", studentID);//studentID is address

    // validting membership type
    do {
        printf("Enter membership type (1=Student, 2=Faculty): ");
        scanf("%d", memberType);
        if(*memberType < 1 || *memberType > 2)
            printf("Invalid, retry: ");
    } while(*memberType < 1 || *memberType > 2);

    printf("Registered! %s\n", name);
    // * means: change the real variable in main, not a copy
}//end function

//Display books
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks){
    printf("\n%-10s %-25s %-10s\n", "ID", "Title", "Copies");
    for(int i = 0; i < totalBooks; i++){
        printf("%-10d %-25s %-10d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}//end function

// book borrowing system
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType){
    // CHECK 1: Limit
    if(*borrowedCount >= 3){
        printf("Cannot borrow. Max 3 books reached.\n");
        return; // exit early ifthe books borrowed are getting more than 3
        //return used to exit function
    }

    int id, days;
    printf("Enter book ID to borrow: ");
    scanf("%d", &id);
    printf("Enter days you intend to keep: ");
    scanf("%d", &days);
    if(days <= 0){ printf("Days must be positive.\n"); return; }

    // CHECK 2: Find book 
    int index = -1; // -1 = not found
    for(int i = 0; i < totalBooks; i++){//traversing through books to find one
        if(bookIDs[i] == id){ index = i; break; }
    }//end finding
    if(index == -1){ printf("Invalid Book ID.\n"); return; }

    // CHECK 3: Copies
    if(availableCopies[index] == 0){
        printf("No copies available for %s.\n", bookTitles[index]);
        return;
    }

    // UPDATE: All checks passed
    availableCopies[index]--; 
    borrowedBookIDs[*borrowedCount] = id; 
    (*borrowedCount)++; 

    int allowed = (memberType == 1) ? 14 : 30;
    printf("Borrowed %s. Return within %d days.\n", bookTitles[index], allowed);
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine){
    int id, actualDays;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    printf("Enter actual days kept: ");
    scanf("%d", &actualDays);
    if(actualDays <= 0){ printf("Days must be positive.\n"); return 0; }

    // CHECK: Did I borrow this?
    int pos = -1;
    for(int i = 0; i < *borrowedCount; i++){
        if(borrowedBookIDs[i] == id){ pos = i; break; }
    }
    if(pos == -1){ printf("You did not borrow this book.\n"); return 0; }

    // FIND in library to increase copies
    for(int i = 0; i < totalBooks; i++){
        if(bookIDs[i] == id){ availableCopies[i]++; break; }
    }

    // REMOVE from my borrowed list - shift left
    for(int i = pos; i < *borrowedCount - 1; i++){
        borrowedBookIDs[i] = borrowedBookIDs[i+1];
    }
    (*borrowedCount)--;

    // FINE CALCULATION: Declare = 0 trick
    int allowed = (memberType == 1) ? 14 : 30;
    int rate = (memberType == 1) ? 20 : 10;
    float fine = 0;
    if(actualDays > allowed){
        int extra = actualDays - allowed;
        fine = extra * rate;
        *totalFine += fine; // add to cumulative
        printf("Late by %d days. Fine: Rs %.2f\n", extra, fine);
    } else {
        printf("Returned on time. No fine.\n");
    }
    return fine; // return this return's fine
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver){
    printf("\n===== Member Record =====\n");
    printf("Name: %s\nID: %d\nType: %s\n", name, studentID, (memberType==1)?"Student":"Faculty");
    printf("Currently Borrowed: ");
    if(borrowedCount == 0) printf("None");
    for(int i = 0; i < borrowedCount; i++) printf("%d ", borrowedBookIDs[i]);
    printf("\nTotal Fine Before Waiver: Rs %.2f\n", totalFine);
    printf("Final Fine Payable: Rs %.2f\n", fineAfterWaiver);
}
// ===== 7. main - Skeleton we wrote first =====
int main(){
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    char name[50] = "";
    int studentID = 0, memberType = 0;
    int borrowedBookIDs[3]; // max 3 count allowed
    int borrowedCount = 0;
    float totalFine = 0, fineAfterWaiver = 0;

    int choice;
    int registered = 0; // flag: 0 means not registered

    // 2. MENU LOOP
    do {
        displayMenu();//callling display menu function
        scanf("%d", &choice);//input cohice from menu to continue
        switch(choice){
            case 1:
                registerMember(name, &studentID, &memberType);
                registered = 1;
                break;
            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;
            case 3:
                if(!registered) printf("Register first!\n");
                else borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType);
                break;
            case 4: {
                if(!registered) printf("Register first!\n");
                else {
                    float f = returnBook(bookIDs, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                    // WAIVER - Ask once after return
                    if(f > 0){
                        int code;
                        printf("Enter membership code for 50%% waiver (2026): ");
                        scanf("%d", &code);
                        if(code == 2026){
                            fineAfterWaiver = totalFine * 0.5;
                            printf("Waiver applied! Final: %.2f\n", fineAfterWaiver);
                        } else {
                            fineAfterWaiver = totalFine;
                            printf("Wrong code. No waiver.\n");
                        }
                    }
                }
                break;
            }
            case 5:
                if(!registered) printf("Register first!\n");
                else {
                    // If waiver never applied, final = total
                    if(fineAfterWaiver == 0 && totalFine > 0) fineAfterWaiver = totalFine;
                    displayMemberRecord(name, studentID, memberType, borrowedBookIDs, borrowedCount, totalFine, fineAfterWaiver);
                }
                break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 6);
    return 0;
}
