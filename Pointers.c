#include <stdio.h>
#include <stdbool.h>

/* Michael Nkema
 7277023
 21037754
 Computer Engineering */

 
void add(float *result, float operand);
void subtract(float *result, float operand);
void multiply(float *result, float operand);
void divide(float *result, float operand);

int main() {
    float operand1, operand2;
    float *result = &operand1;
    char operator;
    bool on = true; 

start:
    printf("Start Calculations!\n");
    printf("Instructions:\n");
    printf("  - Enter numbers and operators normally.\n");
    printf("  - Use '@0' to reset calculations.\n");
    printf("  - Use '#0' to exit.\n");

    printf("\nEnter first number: ");
    scanf(" %f", &operand1);

    do {
        printf("\nEnter operator or '@' to reset, '#' to exit: ");
        scanf(" %c", &operator);

        if (operator == '#') {
            printf("Goodbye! Exiting...\n");
            break;
        }
        if (operator == '@') {
            goto start; 
        }

        printf("Enter second number: ");
        scanf(" %f", &operand2);

        switch (operator) {
            case '+': add(result, operand2); break;
            case '-': subtract(result, operand2); break;
            case '*': multiply(result, operand2); break;
            case '/': divide(result, operand2); break;
            default: printf("Invalid operator. Try again.\n");
        }

        printf("Result: %.2f\n", *result);

    } while (on);

    return 0;
}


void add(float *result, float operand) {
    printf("%.2f + %.2f = ", *result, operand);
    *result += operand;
    printf("%.2f\n", *result);
}

void subtract(float *result, float operand) {
    printf("%.2f - %.2f = ", *result, operand);
    *result -= operand;
    printf("%.2f\n", *result);
}

void multiply(float *result, float operand) {
    printf("%.2f * %.2f = ", *result, operand);
    *result *= operand;
    printf("%.2f\n", *result);
}

void divide(float *result, float operand) 
{
    printf("%.2f / %.2f = ", *result, operand);
    *result /= operand;
    printf("%.2f\n", *result);
}
