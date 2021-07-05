#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void createDB();

char* accountNo;
char* date;
long accountN;

void createAccount(struct accountdetail *account)
{
    FILE *fp, *global;
    char buffer[1024];

    fp = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\AccountDetails.csv", "a++");

    global = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\global.csv", "r");

    fgets(buffer, 1024, global);

    accountNo = strtok(buffer, ",");
    date = strtok(NULL, ",");

    printf("%s", accountNo);
    printf("%s", date);

    printf("Account Holder Name : ");
    fscanf(stdin, "%s", account->name) != EOF;
    fprintf(fp, "\n%s,", account->name);
    fflush(stdin);

    printf("\ndd/mm/yyyy : ");
    fscanf(stdin, "%d %d %d", &account->date.dd, &account->date.mm, &account->date.yy);
    fprintf(fp, "%d / %d / %d ,", account->date.dd, account->date.mm, account->date.yy);
    fflush(stdin);

    printf("\nGender : ");
    fscanf(stdin, "%s", account->gender);
    fprintf(fp, "%s,", account->gender);
    fflush(stdin);

    printf("\nOccupation : ");
    fscanf(stdin, "%s,", account->occupation);
    fprintf(fp, "%s,", account->occupation);
    fflush(stdin);

    printf("\nNationality : ");
    fscanf(stdin, "%s,", account->nationality);
    fprintf(fp, "%s,", account->nationality);
    fflush(stdin);

    printf("\nAddress : ");
    fscanf(stdin, "%s,", account->address);
    fprintf(fp, "%s,", account->address);
    fflush(stdin);

    printf("\nMother name : ");
    fscanf(stdin, "%s,", account->mname);
    fprintf(fp, "%s,", account->mname);
    fflush(stdin);

    printf("\nFather name : ");
    fscanf(stdin, "%s,", account->fname);
    fprintf(fp, "%s,", account->fname);
    fflush(stdin);

    printf("\nNominee Name : ");
    fscanf(stdin, "%s,", account->nominee);
    fprintf(fp, "%s,", account->nominee);
    fflush(stdin);

    printf("\nAadhar Number : ");
    fscanf(stdin, "%s,", account->adharno);
    fprintf(fp, "%s,", account->adharno);
    fflush(stdin);

    printf("\nPAN Card Number : ");
    fscanf(stdin, "%s,", account->pan);
    fprintf(fp, "%s,", account->pan);
    fflush(stdin);

    printf("\nEnter the amount u want to deposit : ");
    fscanf(stdin, "%s", &account->amount);
    fprintf(fp, "%s,", account->amount);
    fflush(stdin);

    printf("\nAccount Type\n");
    printf("1 . Savings Account\n");
    printf("2 . Current Account\n");
    printf("\n");
    printf("Enter the choice(Savings,Current) : ");
    fscanf(stdin, "%s", account->acctype);
    fprintf(fp, "%s", account->acctype);

   

    createDB();

    printf("\nYour has been sucessfull created");

    fclose(fp);
    fclose(global);
}


void createDB()
{
    FILE *global;
    char* e;

    global = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\global.csv", "w");

    accountN = strtol(accountNo, &e, 10);
    accountN++;

    //Prajwal your code here.
    //Use accountNo for string operations and accountN for integer operations

    fprintf(global, "%ld,%s", accountN, date);

    fclose(global);
}