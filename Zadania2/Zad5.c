#include <stdio.h>
#include <string.h>

#define MAX 100
int FREE_SPACE = -1; // do sprawdzenie czy jest jeszcze miejsce
int TAKEN[100];  // zachowuje informacje czy pod danym indeksem jest kontakt czy jest on pusty

typedef struct
{
    char name[20];
    char lastName[20];
    char num[10];
} Contact;

void add(Contact *contactArray);
void search(Contact *contactArray, char *lastName);
void removeContact(Contact *contactArray, char *lastName);
void printAll(Contact *contactArray);

int main()
{
    //robocze dodanie poczatkowych danych
    Contact contactArray[MAX]; 
    Contact c1 = {"David", "Smith", "645648455"};
    Contact c2 = {"Steve", "Hinton", "767888455"};
    contactArray[0] = c1;
    TAKEN[0] = 1;
    contactArray[1] = c2;
    TAKEN[1] = 1;
    char removeC[20];
    char searchC[20];
    char action;
    do
    {
        printf("Choose action:\n");
        printf("a - add contact\n");
        printf("s - search contact\n");
        printf("r - remove contact\n");
        printf("p - print all contacts\n");
        printf("0 - exit\n");
        printf("Action: ");
        scanf(" %c", &action);
        switch (action) 
        {
            case 'a':
                add(contactArray);
                break;
            case 's':
                printf("Enter last name of contact you want to search: ") ;
                scanf("%s", searchC);
                search(contactArray, searchC);
                break;
            case 'r':
                printf("Enter last name of contact you want to remove: ") ;
                scanf("%s", removeC);
                removeContact(contactArray, removeC);
                break;
            case 'p':
                printAll(contactArray);
                break;
            case '0':
                return 0;
                break;
        }
        getchar();
    } while (action != '0');
    return 0;
}

void add(Contact *contactArray)
{
    FREE_SPACE = -1;
    //znajduje wolne miejsce
    for (int i = 0; i < MAX; i++)
    {
        if (TAKEN[i] != 1)
        {
            FREE_SPACE = i;
            break;
        }
    }
    //jesli nie znalazlo
    if (FREE_SPACE == -1)
    {
        printf("Contact has no more space! Contact won't be added!\n");
    }
    
    char name[20];
    char lastName[20];
    char num[20];
    
    printf("Enter name: ");
    scanf("%19s", name);
    printf("\nEnter last name: ");
    scanf("%19s", lastName);
    printf("\nEnter telephone number: ");
    scanf("%9s", num);
    printf("\n");
        
    Contact add;
    strcpy(add.name, name);
    strcpy(add.lastName, lastName);
    strcpy(add.num, num);
    if (FREE_SPACE != -1)
    {
        contactArray[FREE_SPACE] = add;
        TAKEN[FREE_SPACE] = 1; 
    }  
}

void search(Contact *contactArray, char *lastName)
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(contactArray[i].lastName, lastName) == 0)
        {
            printf("Contact name: %s\n", contactArray[i].name);
            printf("Contact last name: %s\n", contactArray[i].lastName);
            printf("Contact number: %s\n\n", contactArray[i].num);
            break;
        }
    }
}

void removeContact(Contact *contactArray, char *lastName)
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(contactArray[i].lastName, lastName) == 0)
        {
            strcpy(contactArray[i].name, "");
            strcpy(contactArray[i].lastName, "");
            strcpy(contactArray[i].num, "");
            TAKEN[i] = 0;
            break;
        }
    }
}

void printAll(Contact *contactArray)
{
    for (int i = 0; i < MAX; i++)
    {   
        if (TAKEN[i] == 1)
        {
            printf("Contact name: %s\n", contactArray[i].name);
            printf("Contact last name: %s\n", contactArray[i].lastName);
            printf("Contact number: %s\n\n", contactArray[i].num);
        }
    }
}
