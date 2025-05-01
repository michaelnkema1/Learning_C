#include<stdio.h>

struct Shop
{
    char name[50];
    char phone_number[20];
};

struct Clothing 
{
    int code;
    int year;
    struct Shop shop;
    struct Price
    {
        char currency[50];
        int amount;
    };
    struct Price price;
    union Size
    {
        int digit;
        char letter;
        char word[20];
    };
    union Size size;
    int sizetype;

};

struct Shop shops[50];
struct Clothing clothes[50];
int shopCount = 0;
int clothesCount = 0;

void showShops();
void showDetails(int a);
void showClothes(int a);
void addClothing();

int main()
{
    struct Shop shop1, shop2;
    shops[0] = shop1;
    shops[1] = shop2;
    shopCount = 2;
    struct Clothing cloth1, cloth2, cloth3, cloth4;
    clothes[0] = cloth1;
    clothes[1] = cloth2;
    clothes[2] = cloth3;
    clothes[3] = cloth4;
    clothesCount = 4;

    int looping=0;
     do{
        printf("CLOTHING MALL\n1.Visit Shop\t2.Add Clothing\t3.Exit\n");
        int option;
        scanf(" %d", &looping);
        switch(looping){
        case 1: showShops();
            scanf(" %d", &option);
            showDetails(option-1);
            showClothes(option-1);
            break;
        case 2: addClothing();
            break;
        case 3: looping = 0; 
            printf("Thanks for shopping :)");
            break;
        default:
            printf("Invalid choice\n"); 
            break;
}
}
    while(looping>0);


    return 0;
}

void showShops()
{
    printf("Available Shops:\n");
    for (int i = 0; i < shopCount; i++) 
    {
        printf("%d. %s  %s\n", i + 1, shops[i].name, shops[i].phone_number);
    }
}

void showDetails(int a)
{
    printf("Shop Name: %s || %d\n", shops[a].name, shops[a].phone_number);
}

void showClothes(int a)
{
    printf("Clothes available in %s:\n", shops[a].name);
    for (int i = 0; i < clothesCount; i++) 
    {
        if (strcmp(clothes[i].shop.name, shops[a].name) == 0) {
            printf("Code: %d, Year: %d, Price: %s %d\n", 
                clothes[i].code, clothes[i].year, clothes[i].price.currency, clothes[i].price.amount);
        }
    }
}

void addClothing()
{
    struct Clothing clothes[clothesCount + 1];
    printf("Enter clothing code: ");
    scanf("%d", &clothes[clothesCount + 1].code);
    printf("Enter manufacturing year: ");
    scanf("%d", &clothes[clothesCount + 1].year);
    printf("Enter a currency for the price\n");
    scanf("%c ", &clothes[clothesCount + 1].price.currency);
    printf("Enter a price for the clothing\n");
    scanf("%c ", &clothes[clothesCount + 1].price.amount);
    printf("Clothing item added successfully!\n");
    clothesCount++;
}
