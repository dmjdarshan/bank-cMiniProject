#include <windows.h>

struct dob
{
    int dd;
    int mm;
    int yy;
}todaysDate;
struct accountdetail
{
    char name[50];
    struct dob date;
    char gender[15];
    char mname[50];
    char fname[50];
    char nationality[25];
    int accountno[15];
    long int phno;
    char email[50];
    char occupation[20];
    char address[500];
    char nominee[50];
    char adharno[15];
    char pan[15];
    char amount[10];
    char acctype[15];
};

struct globals
{
    char path[100];
}globe;






void createAccount(struct accountdetail *account);
void delay(long int j);
void close(void);
void menu(void);
void accountDetails();
int passbook();
int withdraw();
char* findAccount(char* accountNo);