#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

int main_exit;

void accountDetails()
{
    FILE *fp;
    char buffer[1024], *value;
    int i;
    fp = fopen("D:\\DARSHAN BTECH\\bank-cMiniProject\\database\\AccountDetails.csv", "r");
    

    while (fgets(buffer, 1024, fp))
    {
        i = 1;
        value = strtok(buffer, ",");
        while (value)
        {
            if ((i == 1) | (i == 2) | (i == 4) | (i == 5) | (i == 13) | (i == 14) )
            {
                printf("%s ", value );
            }
            
            i++;
            value = strtok(NULL, ",");
        }
        printf("\n");
    }

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


}
