#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "header.h"


int main_exit;
void systime(char *filename,FILE *accountfile);


int withdraw()
{
    FILE *mainfile;                 
    FILE *accountfile;        

    char accountnumber[15];            //user input
    char buffer[1024];                 //entire line from the accountfile
    
    char *accountNo;                   //account number from the user file
    char *accountname;                 //account name from the user file
    char *amount;                      //amount user inputs
    char *temp; 
    char *filename;                    
    
    int result;

    double AMOUNT;                     //total amount
    double withdrawamt;                //the amount user withdraws


    mainfile=fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\AccountDetails.csv","r+");
    system("cls");
    printf("Enter the Account Number\n");
    scanf("%s",accountnumber);
    fflush(stdin);
    
    result = findAccount(accountnumber);
    
    if (result == 0)
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

        char path[100] = "D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\";
        char *buff= strcat(accountnumber,".csv"); 
        char* filename = strcat(path, buff);
        accountfile=fopen(filename,"r");

        fgets(buffer, 1024, accountfile);
        printf("\n%s", buffer);
        accountNo = strtok(buffer, ",");
        accountname = strtok(NULL, ",");
        printf("%s", accountname);

        fgets(buffer, 1024, accountfile);
        
        

        fclose(accountfile);
    }

    

    /*
    if(accountfile==NULL)
    { 
        printf("\n");
        delay(1000000000);
        printf("INVALID ACCOUNT NUMBER!!!!\n");
        
    }
    else
    {
        while((fgets(buffer,1024,accountfile))!=NULL)
        {
            temp=strtok(buffer,",");
            accountNo=strtok(NULL,",");
            accountname=strtok(NULL,",");
            amount=strtok(NULL,",");
        }

    }*/
   // fclose(accountfile);


    accountfile=fopen(filename,"a+");

    delay(1000000000);

    printf("\n");
    printf("The account holder name is %s\n",accountname);
    printf("\n");
    printf("The balance in the account is %s \n",amount);
    printf("\n");
    
    char *ptr;
    AMOUNT=strtod(amount,&ptr);   //standard function in stdlib.h

    delay(1000000000);

    printf("Enter the amount customer want to withdraw  :  ");
    scanf("%lg",&withdrawamt);
    
    AMOUNT=AMOUNT-withdrawamt;

    delay(1000000000);

    printf("\n");
    printf("The amaount has been sucessfully withdrawn!!\n");
    printf("\n");

    delay(1000000000);

    printf("Account balance is %.2lf",AMOUNT);
    printf("\n");


    fprintf(accountfile,"\nWithdraw,");
    fprintf(accountfile,"%d",todaysDate.dd);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d",todaysDate.mm);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d,",todaysDate.yy);
    fprintf(accountfile,__TIME__);
    fprintf(accountfile,",");
    fprintf(accountfile,"%.2lf,",withdrawamt);
    fprintf(accountfile,"%.2lf,",AMOUNT);

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

    fclose(mainfile);
    fclose(accountfile);
    
}
