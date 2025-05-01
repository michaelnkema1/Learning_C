#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float total_marks = 0;
float average_mark = 0;

int main()
{
    struct Student
    {
        char Name[20];
        int Roll_number;
        float subject[3];
    };

    struct Student Student1;
    printf("Enter Student Name: ");
    scanf("%s", &Student1.Name);

    printf("\nEnter Student Roll Number: ");
    scanf("%d", &Student1.Roll_number);

    for(int i = 0; i < 3; i++)
    {
        printf("\nEnter Subject %d marks: ", i + 1);
        scanf("%f", &Student1.subject[i]);
    }

    for(int i = 0; i < 3; i++)
    {
      total_marks += Student1.subject[i];
    }
    
    average_mark = total_marks / 3;

    printf("\n--- Student Details ---\n");
    printf("\nName: %s", Student1.Name);
    printf("\nRoll No: %d", Student1.Roll_number);
    printf("\nSubject 1: %f",Student1.subject[0]);
    printf("\nSubject 2: %f",Student1.subject[1]);
    printf("\nSubject 3: %f",Student1.subject[2]);

    printf("\nTotal Marks: %.2f", total_marks);
    printf("\n Average Mark: %.2f\n", average_mark); 


}