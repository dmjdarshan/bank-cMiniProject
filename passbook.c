#include<stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>

int main_exit;
void next(char* accountNo, char* result);

void passbook()
{
    char* result, *accountnumber;

    system("cls");
    printf("Enter the Account Number\n");
    scanf("%s",accountnumber);
    fflush(stdin);
    
    result = findAccount(accountnumber);   
    
    if (result == NULL)
    {
        printf("Invalid Account Number\n");
        delay(10000000);
        delay(10000000);
        delay(10000000);
        delay(10000000);
        delay(10000000);
        delay(10000000);
        passbook();
    }
    else{
        printf("Heloo");
        next(accountnumber, result);   
    }
}

void next(char* accountNo, char* result)
{
    FILE *accountfile;  
    
    char buffer[1024];
    char* temp;
    
    
    char* filename = strcat(globe.path, accountNo);
    
    accountfile=fopen(filename,"r");
    delay(1000000000);


    passB:
    system("cls");

    fgets(buffer, 1024, accountfile);
    temp = strtok(buffer, ",");
    printf("Account Number: ", temp);
    temp = strtok(NULL, ",");
    printf("Account Holder: ", temp);
    temp = strtok(NULL, ",");
    printf("Account Type: ", temp);

    printf("\nOperation\t\tDate\t\tTime\t\tAmount\t\tBalance");

    while (fgets(buffer, 1024, accountfile))
    {
        
        temp = strtok(buffer, ",");
        while (temp)
        {
         
            printf("%s ", temp );
            temp = strtok(NULL, ",");
        }
        printf("\n");
    }


    
    
    add_invalid:
    
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit== 1)
        menu();
    else if(main_exit== 0)
        close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }

    fclose(accountfile);



}