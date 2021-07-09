#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void createDB(struct accountdetail *temp);

char* accountNo;
char* date;
long accountN;
int main_exit;

void createAccount(struct accountdetail *account)
{
    FILE *fp, *global;
    char buffer[1024];

    fp = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\AccountDetails.csv", "a++");

    global = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\global.csv", "r");

    fgets(buffer, 1024, global);

    accountNo = strtok(buffer, ",");
    date = strtok(NULL , ",");

    fprintf(fp,"\n%s,",accountNo);

    printf("Account Holder Name : ");
    fscanf(stdin, "%s", account->name);
    fprintf(fp, "%s,", account->name);
    fflush(stdin);

    printf("\ndd/mm/yyyy : ");
    fscanf(stdin, "%d/%d/%d", &account->date.dd, &account->date.mm, &account->date.yy);
    fprintf(fp, "%d",account->date.dd);
    fprintf(fp,"/");
    fprintf(fp,"%d",account->date.mm);
    fprintf(fp,"/");
    fprintf(fp,"%d",account->date.yy);
    fprintf(fp,"/,");
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

    struct accountdetail temp;
    temp=*account;


    createDB(&temp);

    printf("\nYour %s has been sucessfull created\n", account->acctype);
    printf("\n");

    printf("Your account number is %ld \n",(accountN-1));

    delay(100000000);
    
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
    

    fclose(fp);
    fclose(global);
}

void createDB(struct accountdetail *temp)
{

    FILE *global;
    char* e;

    FILE *accountfile;
    char path[100] = "D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\";

    global = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\global.csv", "w");

    accountN = strtol(accountNo, &e, 10);
    
    char *buff=strcat(accountNo,".csv"); 
    char* filename = strcat(path, buff);
                    
    accountfile=fopen(filename,"a+");

    fprintf(accountfile,"Account Number: %ld\n",accountN);
    fprintf(accountfile,"Name: %s\n",temp->name);
    fprintf(accountfile,"Account Created on: %d",temp->date.dd);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d",temp->date.mm);
    fprintf(accountfile,"/");
    fprintf(accountfile,"%d\n",temp->date.yy);
    fprintf(accountfile,"Balance: %s\n",temp->amount);
    

    accountN++;

    fprintf(global, "%ld,%s", accountN, date);

    fclose(global);
}