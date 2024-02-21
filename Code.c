#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customer();
void employeeveri();
void employee();
void billgen();
void mr();
void nc();
void ad();
void del();
void cb();

#define maxc 20
#define maxname 50
#define maxadd 50
#define maxmeter 10
#define maxe 6

struct customer
{
    char name[50];
    char address[50];
    char id[10];
    long int bill;
    int units;
} details[maxc];

struct employee
{
    char name[50];
    char id[10];
} edetails[maxe];

struct customer details[maxc] =
    {
        {"Mr.Vamshi Reddy", "123 Main St, City A", "MTR001",0},
        {"Mr.Nikhil", "456 Elm St, City B", "MTR002",0},
        {"Mr.Mudassir", "789 Oak St, City C", "MTR003",0},
        {"Mr. Manoj Kumar", "321 Maple St, City D", "MTR004",0},
        {"Mr.Zain", "654 Pine St, City E", "MTR005",0},
        {"Mr.Sai Harshith", "987 Cedar St, City F", "MTR006",0},
        {"Mr.Sai Vikranth", "159 Birch St, City G", "MTR007",0},
        {"Mr.Sai Saketh", "753 Walnut St, City H", "MTR008",0},
        {"Mr.Uday Kumar", "258 Cherry St, City I", "MTR009",0},
        {"Mr.Akshith Verma", "852 Willow St, City J", "MTR010",0},
        {"Mr.Sravan Kumar", "753 Oak St, City K", "MTR011",0},
        {"Mr.Vedant", "159 Elm St, City L", "MTR012",0},
        {"Mr.Rohith", "951 Pine St, City M", "MTR013",0},
        {"Mr.Soumith", "357 Maple St, City N", "MTR014",0},
        {"Mr.Chaitanya Aradhya", "258 Cedar St, City O", "MTR015",0}};

struct employee edetails[maxe] =
    {
        {"Devendra", "EMP001"},
        {"Manish", "EMP002"},
        {"Naveen", "EMP003"},
        {"Navdeep", "EMP004"},
        {"Sagar", "EMP005"},
        {"Venu", "EMP006"},
};

int main()
{
    int n;

    printf("\n      **************************** WELCOME TO THE ELECTRICITY DEPARTMENT ****************************\n");

    printf("\nPlease select an option:\n");
    printf("Press 1 if you are a customer\n");
    printf("Press 2 if you are an Board Employee\n");
    printf("Press 3 to exit\n");
    printf("Please enter your choice: ");

reen:
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        customer();
        break;
    case 2:
        employeeveri();
        break;
    case 3:
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    default:
        printf("Invalid choice. Please try again: ");
        goto reen;
        break;
    }

    return 0;
}

void customer()
{
    int n;

    printf("\n*********************************************************************************************************************************\n");
    printf("\n\nPlease select an option:\n");
    printf("1. Check Electricity bill\n");
    printf("2. Request meter replacement\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
reen:
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        cb();
        break;
    case 2:
        mr();
        break;
    case 3:
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    default:
        printf("Invalid choice. Please try again: ");
        goto reen;
        break;
    }
}

void employeeveri()
{
    char id[10], name[50];
    int n, i, flag = 0;

    printf("\n*********************************************************************************************************************************\n");
ren:
    printf("\nEnter your username: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", id);

    for (i = 0; i < maxe; i++)
    {
        if (strcmp(name, edetails[i].name) == 0 && strcmp(id, edetails[i].id) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        employee();
    }
    else
    {
        printf("\nYour username or password is incorrect. Please try again");
        goto ren;
    }
}

void employee()
{
    int n;

    printf("\n*********************************************************************************************************************************\n");
    printf("\n\nPlease select an option:\n");
    printf("1. Delete existing customer\n");
    printf("2. Add new customer\n");
    printf("3. Change address of existing customer\n");
    printf("4. Generate electricity bill\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
reen:
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        del();
        break;
    case 2:
        nc();
        break;
    case 3:
        ad();
        break;
    case 4:
        billgen();
        break;
    case 5:
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    default:
        printf("\nInvalid choice. Please try again: ");
        goto reen;
        break;
    }
}

// Bill generation logic
void billgen()
{
    int i, u, n, flag = 1;
    long int total_bill;
    char id[10];

    printf("Please enter your Unique meter number: ");
bg:
    scanf("%s", id);

    for (i = 0; i < maxc; i++)
    {
        if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nplease enter a valid meter number: ");
        goto bg;
    }

    printf("\nPlease press 1 to confirm your details or 2 to re-enter your Meter number: ");
    scanf("%d", &n);
    if (n == 2)
    {
        printf("\nPlease enter your meter number: ");
        goto bg;
    }

    printf("\nElectricity Tariff for Households (Rates/Unit):\n");
    printf("\nUpto 20 units .............................. = Rs.3/Unit");
    printf("\n21 to 30 units .............................. = Rs.7/Unit");
    printf("\n31 To 50 units .............................. = Rs.8/Unit");
    printf("\n51 To 150 units .............................. = Rs.10/Unit");
    printf("\n151 To 250 units .............................. = Rs.11/Unit");
    printf("\n251 To 400 units .............................. = Rs.12/Unit");
    printf("\n400+ units ................................. = Rs.13/Unit\n");

    printf("\nPlease enter your total units consumed: ");
    scanf("%d", &u);

    details[i].units=u;

    if (u <= 20)
        total_bill = u * 3;
    else if (u <= 30)
        total_bill = u * 7;
    else if (u <= 50)
        total_bill = u * 8;
    else if (u <= 150)
        total_bill = u * 10;
    else if (u <= 250)
        total_bill = u * 11;
    else if (u <= 400)
        total_bill = u * 12;
    else
        total_bill = u * 13;

    printf("\nYour Total Bill Is Rs.%ld\n", total_bill);

   details[i].bill = total_bill;

    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        employee();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }
}

// Meter Replacement Logic
void mr()
{
    int i, u, total_bill, n, flag = 1;
    char id[10];

    printf("Please enter your Unique meter number: ");
mr:
    scanf("%s", id);

    for (i = 0; i < maxc; i++)
    {

        if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nplease enter a valid meter number: ");
        goto mr;
    }

    printf("\nPlease press 1 to confirm your details or 2 to re-enter your Meter number: ");
    scanf("%d", &n);
    if (n == 2)
    {
        printf("\nPlease enter your meter number: ");
        goto mr;
    }

    printf("\nDear %s your request for meter replacement has been raised, our team will contact you soon", details[i].name);

    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        customer();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }
}

// Logic for New customer Registration
void nc()
{
    int n, i, m = 1, hmn = 0, cmn = 0;
    struct customer newCustomer;

    printf("Please enter the name of the new customer: ");
    scanf(" %[^\n]", newCustomer.name);

    printf("Please enter the address of the new customer: ");
    scanf(" %[^\n]", newCustomer.address);

    // Find the highest existing meter number
    for (i = 0; i < maxc; i++)
    {
        cmn = atoi(details[i].id + 3);
        if (cmn > hmn)
        {
            hmn = cmn;
        }
    }

    char newMeterNumber[maxmeter];
    sprintf(newMeterNumber, "MTR%03d", hmn + 1);
    strcpy(newCustomer.id, newMeterNumber);

    printf("\nUnique customer meter number:%s\n", newCustomer.id);

    // Find the first empty slot in the details array
    for (i = 0; i < maxc; i++)
    {
        if (details[i].name[0] == '\0')
        {
            // Add the new customer to the details array
            strcpy(details[i].name, newCustomer.name);
            strcpy(details[i].address, newCustomer.address);
            strcpy(details[i].id, newCustomer.id);
            printf("Customer Registration successfull!\n");
            break;
        }

        if (i == maxc)
        {
            printf("Cannot add new customer. Details array is full.\n");
        }
    }

    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        employee();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }
}

// address change logic
void ad()
{
    int i, u, n, flag = 1;
    char id[10], add[30];

    printf("Please enter your Unique meter number: ");
mr:
    scanf("%s", id);

    for (i = 0; i < maxc; i++)
    {
        if ((strcmp(details[i].name, "\0") == 0) && (strcmp(id, details[i].id) == 0))
        {
            flag = 1;
            break;
        }

        else if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nplease enter a valid meter number: ");
        goto mr;
    }

    printf("\nPlease press 1 to confirm your details or 2 to re-enter your Meter number: ");
    scanf("%d", &n);
    if (n == 2)
    {
        printf("\nPlease enter your meter number: ");
        goto mr;
    }

newad:

    printf("\nPlease enter your new address: ");

    scanf(" %[^\n]", add);

    printf("\nYour new address is: %s", add);

    printf("\nPlease press 1 to confirm or 2 to re-enter your new address: ");
    scanf("%d", &n);

    if (n == 2)
    {
        goto newad;
    }

    for (i = 0; i < maxc; i++)
    {
        if (strcmp(id, details[i].id) == 0)
        {
            strcpy(details[i].address, add);
        }
    }

    printf("\nAddress updated successfully, Your new details are:  ");

    for (i = 0; i < maxc; i++)
    {
        if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            break;
        }
    }


    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        employee();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }
}

// customer deletion
void del()
{
    int i, u, n, flag = 1;
    char id[10];

    printf("Please enter your Unique meter number: ");
mr:
    scanf("%s", id);

    for (i = 0; i < maxc; i++)
    {
        if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nplease enter a valid meter number: ");
        goto mr;
    }

    printf("\nPlease press 1 to confirm your details or 2 to re-enter your Meter number: ");
    scanf("%d", &n);
    if (n == 2)
    {
        printf("\nPlease enter your meter number: ");
        goto mr;
    }

    printf("\nPlease press 1 to delete your details or 2 to back to main menu: ");
    scanf("%d", &n);

    if (n == 1)
    {
        strcpy(details[i].name, "\0");
        strcpy(details[i].address, "\0");
        strcpy(details[i].id, "\0");
        printf("\nCustomer deletion successfully completed");
    }
    else
    {
        employee();
    }


    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        employee();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }
}

void cb()
{
    int i, u, n, flag = 1;
    char id[10];

    printf("Please enter your Unique meter number: ");
mr:
    scanf("%s", id);

    for (i = 0; i < maxc; i++)
    {
        if (strcmp(id, details[i].id) == 0)
        {
            printf("\nCustomer name: %s", details[i].name);
            printf("\nCustomer address: %s\n", details[i].address);
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nplease enter a valid meter number: ");
        goto mr;
    }

    printf("\nPlease press 1 to confirm your details or 2 to re-enter your Meter number: ");
    scanf("%d", &n);
    if (n == 2)
    {
        printf("\nPlease enter your meter number: ");
        goto mr;
    }

    if(details[i].bill == 0)
    {
        printf("\n**Unable to fetch your bill at the moment, please try again**");
    }
    else
    {
        printf("\n\n********************************\n");
        printf("        ELECTRICITY BILL        \n");
        printf("********************************\n");
        printf("Meter Number: %s\n",details[i].id);
        printf("Name: %s\n", details[i].name);
        printf("address: %s\n", details[i].address);
        printf("********************************\n");
        printf("Total units consumed: %d\n",details[i].units);
        printf("Your total bill: Rs.%d\n", details[i].bill);
        printf("********************************\n");

    }

    printf("\n\nPress 1 to go back to the main menu, 2 to logout and 3 to exit: ");
    scanf("%d", &n);

    if (n == 1)
        customer();
    else if (n == 2)
    {
        main();
    }
    else
    {
        printf("\n**************Thank you for using the electricity billing system. Goodbye!********************\n");
        exit(0);
    }

}
