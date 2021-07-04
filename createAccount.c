#include<stdio.h>
#include "header.h"
void createAccount(struct accountdetail *account)
{
    FILE *fp;
    fp=fopen("AccountDetails.csv","a++");

   printf("Account Holder Name : ");
   fscanf(stdin,"%s",account->name)!=EOF;
   fprintf(fp,"\n%s,",account->name);
   
   printf("\ndd/mm/yyyy : ");
   fscanf(stdin,"%d %d %d",&account->date.dd,&account->date.mm,&account->date.yy);
   fprintf(fp,"%d / %d / %d ,",account->date.dd,account->date.mm,account->date.yy);
    
   printf("\nGender : ");
   fscanf(stdin,"%s",account->gender);
   fprintf(fp,"%s,",account->gender);
    
    printf("\nOccupation : ");
    fscanf(stdin,"%s,",account->occupation);
    fprintf(fp,"%s,",account->occupation);
     
    printf("\nNationality : ");
    fscanf(stdin, "%s,",account->nationality);
    fprintf(fp,"%s,",account->nationality);

    printf("\nAddress : ");
    fscanf(stdin,"%s,",account->address);
    fprintf(fp,"%s,",account->address);

    printf("\nMother name : ");
    fscanf(stdin,"%s,",account->mname);
    fprintf(fp,"%s,",account->mname);
    
    printf("\nFather name : ");
    fscanf(stdin,"%s,",account->fname);
    fprintf(fp,"%s,",account->fname);

    printf("\nNominee Name : ");
    fscanf(stdin,"%s,",account->nominee);
    fprintf(fp,"%s,",account->nominee);

    printf("\nAdhar Number : ");
    fscanf(stdin,"%s,",account->adharno);
    fprintf(fp,"%s,",account->adharno);
    

    printf("\nPAN Card Number : ");
    fscanf(stdin,"%s,",account->pan);
    fprintf(fp,"%s,",account->pan);

    printf("Enter the amount u want to deposit : ");
    fscanf(stdin,"%s",&account->amount);
    fprintf(fp,"%s,",account->amount);
    
    printf("\nAccount Type\n");
    printf("1 . Savings Account\n");
    printf("2 . Current Account\n");
    printf("\n");
    printf("Enter the choice(Savings,Current) : ");
    fscanf(stdin,"%s",account->acctype);
    fprintf(fp,"%s",account->acctype);

    printf("\nYour has been sucessfull created");

    
}





























    
    
    
    
