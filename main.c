#include<stdio.h>
#include "header.h"
#include <windows.h>

int main_exit;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
    printf("\n\n\n\nThis C Mini Project is developed by Code With C team!");
}

void menu(void)
{   
    int choice;
    struct accountdetail account;
    
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tBANK MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Withdraw\n\t\t3.Deposit\n\t\t4.View Account holder's list\n\t\t5.Check the existing Account details\n\t\t6.Delete Account\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:createAccount(&account);;
        break;
        case 2:printf("Prajwal your function here");;
        break;
        case 3:printf("Adithya your function here");;
        break;
        case 4:printf("Darshan your function here");;
        break;
        case 5:printf("Darshan your function here");;
        break;
        case 6:printf("Bhavik your function here");;
        break;
        case 7:close();
        break;

    }
}

int main()
{
    char user[10],username[10] = "admin",pass[10],password[10]="admin";
    int i=0;
    
    system("cls");
    system("color 9");
    printf("\n\n\n\t\t\t\tBANK MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\tUsername :");
    scanf("%s", user);
    printf("\n\n\t\t\t\tPassword :");
    scanf("%s",pass);
    
    if ((strcmp(pass,password)==0) && (strcmp(user,username)==0))
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
