#include<stdio.h>
#include<math.h>

char grade (int score);

int main()
{
    int n = 0;
    printf("Enter the number of students in the class: ");
    scanf("%d", &n);

    float marks[n];
    printf("Start entering their marks");
    for(int i=0; i< n; ++i)
    {
        printf("\nStudent %d:\t",i+1);
        scanf("%f", &marks[i]);
    }

    for(int i=0; i< n; ++i)
    {
        printf("\n\nStudent %d: %.2f \t",i+1,marks[i]);
    }

    int i = 0;
    float sum = 0;

    for(int i=0; i< n; ++i)
    {
        sum += marks[i];
    }

    float mean = sum / n;
    printf("\n\nMean mark of students is %.2f\n\n", mean);
    

    float temp = 0;
    for(int i; i<n; ++i)
    {
      for(int j=i+1; j<n; ++j)
      {
        if(marks[i] > marks[j])
        {
            //switch positions
            temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
        }
      }

    }


    for(int m=0; m < n; ++m)
    {
        printf("%.2f ,",marks[m]);
    }
    printf("\n\n\n");



    //MULTI-DIMENTIONAL ARRAYS
    float studentResults[7][2] = {3,57.45, 2 , 69.29 , 2 , 71.32 , 4 , 65.05 , 3 , 75.67 , 3 , 48.65 , 1 , 88.21};
    printf("\nCREDIT\t|SCORE\t|GRADE\t|\n");
    printf("\t|\t|\t|\n");
    for(int i=0; i<7; ++i)
    {
      for(int j=0; j<2; ++j)
      {
         printf("%.2f \t|", studentResults[i][j]);
         if(j%2 == 1)
        {
            printf("%c \t|", grade(studentResults[i][j]));
            printf("\n\t|\t|\t|");
        }
      }
       printf("\n");
    }

    float weightedsum = 0;
    float totalcredits = 0;

    for(int i=0; i<7; ++i)
    {
        weightedsum = weightedsum + (studentResults[i][0] * studentResults[i][1]);
        totalcredits += studentResults[i][0];
    }
        float cwa = weightedsum/totalcredits;
        printf("\nCWA = %.2f\n", cwa);
 
    return 0;
}

char grade (int score)
{
    if (score > 70)
    {
        return 'A';
    }
    else if (score > 60)
    {
        return 'B';
    }
    else if (score > 50)
    {
        return 'C';
    }
    else if (score > 40)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }

}