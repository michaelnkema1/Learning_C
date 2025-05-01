#include <stdio.h>

/* Name: Michael Nkema  
   Student No: 21037754 */

int main()
{
    int order = 1;
    int time = 0;
    float cost = 0;

    printf("WELCOME TO FIIFI’S ICE CREAM SHOP\nWhat would you like to order?\n");

    do
    {
        int flavour = 0, size = 0, topping = 0;
        float item_cost = 0;
        int item_time = 0;

        printf("1 - Vanilla\n2 - Strawberry\n3 - Chocolate\n4 – Mango\n5 - Enquiries\n");
        scanf("%d", &flavour);

        if (flavour == 5)
        {
            printf("A customer service agent will be with you soon\n");
            continue;
        }

        if (flavour < 1 || flavour > 4)
        {
            printf("Invalid Flavour Entry\n");
            continue;
        }

        printf("1 - Small\n2 - Large\n");
        scanf("%d", &size);

        if (size == 1)
        {
            item_time = 2;
            if (flavour == 1 || flavour == 2)
                item_cost = 5;
            else if (flavour == 3)
                item_cost = 6;
            else if (flavour == 4)
                item_cost = 7;
        }
        else if (size == 2)
        {
            item_time = 3;
            if (flavour == 1 || flavour == 2)
                item_cost = 8;
            else if (flavour == 3)
                item_cost = 9;
            else if (flavour == 4)
                item_cost = 10;
        }
        else
        {
            printf("Invalid Size Entry\n");
            continue;
        }

        cost += item_cost;
        time += item_time;

        printf("%s %s\n", (size == 1) ? "Small" : "Large",
               (flavour == 1) ? "Vanilla" : (flavour == 2) ? "Strawberry" :
               (flavour == 3) ? "Chocolate" : "Mango");

        // Toppings Selection
        int toppings = 1;
        do
        {
            printf("\nChoose a topping (Enter 5 to finish):\n");
            printf("1 - Sprinkles (GHS 2)\n2 - Whipped Cream (GHS 3)\n3 - Chopped Nuts (GHS 4)\n4 - Coconut Shavings (GHS 5)\n5 - Nothing Else\n");
            scanf("%d", &topping);

            if (topping == 1)
            {
                printf("Added Sprinkles.\n");
                cost += 2;
                time += 1;
            }
            else if (topping == 2)
            {
                printf("Added Whipped Cream.\n");
                cost += 3;
                time += 2;
            }
            else if (topping == 3)
            {
                printf("Added Chopped Nuts.\n");
                cost += 4;
                time += 1;
            }
            else if (topping == 4)
            {
                printf("Added Coconut Shavings.\n");
                cost += 5;
                time += 3;
            }
            else if (topping == 5)
            {
                break;
            }
            else
            {
                printf("Invalid Topping Entry\n");
            }
        } while (1);

        // Ask if they want another order
        printf("\nWould you like anything else?\n1 - Yes\n2 - No\n");
        scanf("%d", &order);

    } while (order == 1);

    // Display total cost and waiting time
    printf("\nTotal cost: GHS %.2f\nTotal waiting time: %d minutes\n", cost, time);
    printf("Kindly wait for your order...\n");

    // Countdown using for loop
    printf("Countdown using for loop: ");
    for (int i = time; i > 0; i--)
    {
        printf("%d ", i);
    }
    printf("\n");

    // Countdown using while loop
    int countdown = time;
    printf("Countdown using while loop: ");
    while (countdown > 0)
    {
        printf("%d ", countdown--);
    }
    printf("\nHere is your order\nThanks for coming to Fiifi’s Ice Cream Shop!\n");

    return 0;
}
