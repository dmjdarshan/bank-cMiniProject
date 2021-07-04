struct dob
{
    int dd;
    int mm;
    int yy;
};
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

void createAccount(struct accountdetail *account);