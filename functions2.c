#include<stdio.h>
#include<stdbool.h>

//global variables
int balance = 3000;
int set_pin = 1234;
int entered_pin = 0;

bool authenticate(int a);
int requestAmount();
int deposit(int b);
int withDraw(int c);
int transfer(int d);

int main()
{
    start:

    printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
    
    //local variable
    static int tries = 0;

    scanf("%d", &entered_pin);

    menu:

    if(authenticate(entered_pin) && tries < 4)
    {
        //local variable
        int menu_item;
        printf("Select an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4. Transfer\n");
        scanf("%d", &menu_item);
    switch(menu_item)
    {
        case 1: printf("%d\n", balance);
        break;
        case 2: withDraw(requestAmount());
        break;
        case 3: deposit(requestAmount());
        break;
        case 4: transfer(requestAmount());
    }
    }

    else
    {
        ++tries;
        printf("Invalid pin after %d tries\n", tries);
        if (tries >= 4){return 0;}
        goto start;
    }
    
    //local variable
    int response;

    printf("Would you like to perform another transaction?\n1. Yes\n2. No\n");
    scanf("%d", &response);

    if(response == 1)
    {
        goto menu;
    }

    printf("Thank you for banking with us\n");
    return 0;

}

bool authenticate(int a)
{
    if (set_pin == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int requestAmount()
{
    //local variable
    int amount = 0;
    printf("Please enter an amount for the transaction: ");
    scanf("%d", &amount);
    return amount;
}

int deposit(int b)
{
    balance = balance + b;
    return balance;
}

int withDraw(int c)
{
    balance= balance - c;
    return balance;
}

int transfer(int d)
{
    //local variable
    int receive_acc = 0;
    printf("Please enter recipient's account number: ");
    scanf("%d", &receive_acc);
    balance = balance - d;
    return balance;
}