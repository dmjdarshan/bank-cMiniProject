#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "header.h"


int main_exit;
void depo(char* accountNo, char* result);



int deposit()
{          
    char path[100] = "D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\";
    char accountnumber[15];            //user input
    char buffer[1024];                 //entire line from the accountfile
    
    char *accountname;                 //account name from the user file
    char *amount;                      //amount user inputs
    char *temp;                   
    
    char* result;

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
        withdraw();
    }
    else{

        depo(accountnumber, result);   
    }
}

void depo(char* accountNo, char* result)
{
    char path[100] = "D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\";
    FILE *accountfile;  
        
    double AMOUNT;                     //total amount
    double depositamt;                //the amount user withdraws

    char* accountname;
    char* amount; 
    char* type;

    

    accountname = strtok(result, ",");
    type = strtok(NULL, ",");
    amount = strtok(NULL, ",");
    
    

    

    printf("\n");
    printf("The account holder name is %s\n",accountname);
    printf("\n");
    printf("The balance in the account is %s \n",amount);
    printf("\n");

    char *ptr;
    AMOUNT=strtod(amount,&ptr);   //standard function in stdlib.h

    int typ = atoi(type);
    
    
    char* filename = strcat(path, accountNo);
    
    accountfile=fopen(filename,"a+");
    delay(1000000000);


    depo:
    system("cls");

    printf("\nBalance: %lg\n", AMOUNT);

    printf("Enter the amount customer want to Deposit  :  ");
    scanf("%lg",&depositamt);

    
    
    if (typ == 1)
    {
        if (depositamt >= 50000.00)
        {
            printf("\nAmount too large!!\n");
            printf("\nOnly less than Rs.50000 is possible for Savings Account\n");

            delay(1000000000);
            delay(100000000);
            delay(100000000);
            delay(100000000);
            delay(100000000);
            delay(100000000);
            delay(100000000);
            delay(100000000);
            goto depo;
        }
        else
            AMOUNT=AMOUNT+depositamt;
            delay(100000000);

            printf("\n");
            printf("The amount has been sucessfully deposited!!\n");
            printf("\n");
            delay(1000000000);

            printf("Account balance is %.2lf",AMOUNT);
            printf("\n");
    }
    else if (typ == 0)
    {
        
            
        AMOUNT=AMOUNT-depositamt;
        delay(100000000);

            printf("\n");
            printf("The amount has been sucessfully withdrawn!!\n");
            printf("\n");
            delay(1000000000);

            printf("Account balance is %.2lf",AMOUNT);
            printf("\n");
       
        
    }
    

    

    

    fprintf(accountfile,"\nDeposit,");
    fprintf(accountfile,"%d",todaysDate.dd);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d",todaysDate.mm);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d,",todaysDate.yy);
    fprintf(accountfile,__TIME__);
    fprintf(accountfile,",");
    fprintf(accountfile,"%.2lf,",depositamt);
    fprintf(accountfile,"%.2lf",AMOUNT);

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