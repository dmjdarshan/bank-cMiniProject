#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct loan                  
{
     long int principal;
     float rate;
     float interest;
     float tot_amount;
     int time;
     int d,m,y;
     float emi;
 };
void avail_loan(struct loan *ptr);
void calculate_emi(struct loan *ptr);

void main()
{
      struct loan ptr;
      avail_loan(&ptr);
      calculate_emi(&ptr);
}
 
void avail_loan(struct loan *ptr)
{   
                 char acc[15];
                 printf("enter the clients account number  :" );
                 scanf("%s",&acc);
                 FILE *fptr;
                 FILE *fptr1;
                 fptr1=fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\AccountDetails.csv","r");
                 {
                         char line[100];
                          while((fgets(line,100,fptr1))!=NULL)
                         {
                               char *token=strtok(line,",");
                               if(strcmp(token,acc)==0)
                               {                 
                                   printf(" YOU are eligible for loan \n"); 
                                   printf("enter the loan amount: ");
                                   scanf("%ld",&ptr->principal);
                                   ptr->rate=1;
                                   printf("enter the duration of the loan in months: ");
                                   scanf("%d",&ptr->time);
                                   printf("enter the date, month and year \n ");
                                   scanf("%d/%d/%d",&ptr->d,&ptr->m,&ptr->y);
                                   printf("loan availed date  is %d/%d/%d\n",ptr->d,ptr->m,ptr->y);
                                   ptr->interest=(ptr->principal*ptr->time*ptr->rate)/100.0;
                                   ptr->tot_amount=ptr->principal+ptr->interest;
                                   printf("the interest on loan is %f\n",ptr->interest);
                                   printf("the total amount to be repayed is %f \n",ptr->tot_amount);
                                   ptr->emi=ptr->tot_amount/ptr->time;
                                   printf("emi on loan is is %f\n",ptr->emi);
                                   fptr=fopen("loan1.csv","a+");
                                   fprintf(fptr,"%s,%ld,%f,%d,%d,%d,%d,%f,%f,%f \n",acc,ptr->principal,ptr->rate,ptr->time,ptr->d,ptr->m,ptr->y,ptr->interest,ptr->tot_amount,ptr->emi);
                                   fclose(fptr);
                              }
                               else
                               {
                                       printf(" You are not eligible for availing the loan \n "); 
                                       exit(0);
                                }
               }
     }
     fclose(fptr1);
}
void calculate_emi(struct loan *ptr)
{
           printf("emi on loan is is %f\n",ptr->emi);
}
