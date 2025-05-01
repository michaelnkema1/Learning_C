#include<stdio.h>
#include<stdlib.h>

int main()
{
    int Subjects[5];
    int total = 0;
    float average = 0;
    char grade;
    for(int i = 0; i < 5; i++)
    {
        printf("Enter Subject %d mark: ",i + 1);
        scanf("%d", &Subjects[i]);
    }

    for(int n = 0; n < 5; n++)
    {
        total += Subjects[n];
    }

    average = total / 5;
    
    if (average > 90)
    {
        grade = 'A';
    }
    else if ( average > 80)
    {
        grade = 'B';
    } 
    else if (average > 70)
    {
        grade = 'C';
    }
    else if(average > 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    printf("\n Total = %d",total);
    printf("\n Average = %.2f",average);
    printf("\n Grade = %c\n", grade);

}