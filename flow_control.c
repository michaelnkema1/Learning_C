#include <stdio.h>

/*Name: Michael Nkema
Student No: 21037754*/

int main()
{
    int order = 0;
    int time = 0;
    float cost = 0;

    printf("WELCOME TO FIIFI’S ICE CREAM SHOP\nWhat would you like to order?\n");

    do
    {
        int flavour = 0;
        int topping = 0;
        int size = 0;
        printf("1 - Vanilla\n2 - Strawberry\n3 - Chocolate\n4 – Mango\n5 - Enquiries\n");
        scanf("%d", &flavour);
        printf("1 - small\n2 - large\n");
        scanf("%d", &size);

        if (flavour == 1)
        {
            if (size == 1)
            {
                printf("Small Vanilla\n");
                cost += 5;
                time += 2;

            }
            else if (size == 2)
            {
                printf("Large Vanilla\n");
                cost += 8;
                time += 3;
            }
            else
            {
                printf("Invalid Size Entry\n");
            }
        }
        else if (flavour == 2)
        {
            if (size == 1)
            {
                printf("Small Strawberry\n");
                cost += 5;
                time += 2;

            }
            else if (size == 2)
            {
                printf("Large Strawberry\n");
                cost += 8;
                time += 3;
            }
            else
            {
                printf("Invalid Size Entry\n");
            }


        }
        else if(flavour == 3)
        {
            if (size == 1)
            {
                printf("Small Chocolate\n");
                cost += 6;
                time += 2;

            }
            else if (size == 2)
            {
                printf("Large Chocalate\n");
                cost += 9;
                time += 3;
            }
            else
            {
                printf("Invalid Size Entry\n");
            }
        }
        else if(flavour == 4)
        {
            if (size == 1)
            {
                printf("Small Mango\n");
                cost += 7;
                time += 2;

            }
            else if (size == 2)
            {
                printf("Large Mango\n");
                cost += 10;
                time += 3;
            }
            else
            {
                printf("Invalid Size Entry\n");
            }
        }

        else if(flavour == 5)
        {
            printf("A customer service agent will be with you soon\n");
        }

        else 
        {
            printf("Invalid Flavour Entry\n");
        }

        int toppings = 0;

    do 
    {
        printf("1 - Sprinkles\n2 - Whipped Cream\n3 - Chopped Nuts\n4 - Coconut Shavings\n5 - Nothing Else\n");
        scanf("%d", &toppings);

        if (toppings == 1)
        {
            printf("Sprinkles\n");
            cost += 2;
            time += 10;
            toppings++;
        }

        else if (toppings == 2)
        {
            printf("Whipped Cream\n");
            cost += 3;
            time += 12;
            toppings++;
        }

        else if (toppings == 3)
        {
            printf("Chopped Nuts\n");
            cost += 4;
            time += 13;
            toppings++;
        }

        else if (toppings == 4)
        {
            printf("Coconut Shavings\n");
            cost += 5;
            time += 15;
            toppings++;
        }

        else if (toppings == 5)
        {
            toppings = 0;
        }

        else
        {
            printf("Invalid Topping Entry\n");
        }


    }

    while(toppings > 0);


    }
    while(order > 0);

    
    int F_orders = 0;
    printf("Would you like anything else?\n1 - Yes\n2 - No\n");
    scanf("%d", &F_orders);

    if (F_orders == 1)
    {
        order++;
    }

    else 
    {
        order = 0;
        printf("Your total cost is: %.2f cedis, and your waiting time is: %d seconds\n", cost, time);
    }

    printf("Kindly wait for your order\n");

    printf("Countdown using for loop: ");
    for (int i = time; i > 0; i--)
    {
        printf("%d ", i);
    }
    printf("\n");


   int countdown = time;
    printf("Countdown using while loop: ");
    while (countdown > 0)
    {
        printf("%d ", countdown--);
    }

    printf("\nHere is your order\nThanks for coming to Fiifi’s Ice Cream\n");
}
