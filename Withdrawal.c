#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "header.h"

void systime(char *filename,FILE *accountfile);
void delay(int n);

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
    
    double AMOUNT;                     //total amount
    double withdrawamt;                //the amount user withdraws


    mainfile=fopen("Accountdetails.csv","r+");
    
    printf("Enter the Account Number\n");
    scanf("%s",accountnumber);
    
    char *filename=strcat(accountnumber,".csv");
    accountfile=fopen(filename,"r");


    if(accountfile==NULL)
    { 
        printf("\n");
        delay(1000000000);
        printf("INVALID ACCOUNT NUMBER!!!!\n");
        exit(0);
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

    }

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
    fprintf(accountfile,"%s,",accountNo);
    fprintf(accountfile,"%s,",accountname);
    fprintf(accountfile,"%.2lf,",AMOUNT);
    fprintf(accountfile,"%.2lf,",withdrawamt);

    systime(filename,accountfile);

    char mainfilebuffer[1024];            //entire line from the mainfile
    char *maintemp,*mainamount;         

    while((fgets(mainfilebuffer,1024,mainfile))!=NULL)    //this part is remaining.to change the amount in mainfile
    {
        maintemp=strtok(mainfilebuffer,",");

        for(int i=1;i<=11;i++)
        {
            mainamount=strtok(NULL,",");
        }
    }

    
}

void delay(int n)                   //used to dealy the operation by few seconds
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=i;
    }
}



void systime(char *filename,FILE *accountfile)        //returns the system date
{
    accountfile=fopen(filename,"a+") ;
    int hours, minutes, seconds;

    time_t now;                                        //predefined structure in time.h

    time(&now);

    struct tm *local=localtime(&now);

   hours = local->tm_hour;
   minutes = local->tm_min;
   seconds=local->tm_sec;
   
   fprintf(accountfile,"%d:%d:%d",hours,minutes,seconds);
}