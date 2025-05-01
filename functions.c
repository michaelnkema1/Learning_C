#include<stdio.h>
#include<math.h>

float square(float side);
float circle(float radius);
float triangle(float base, float height);
float rectangle(float length, float width);
float trapezium(float height, float a, float b);
float paralleogram(float base, float height);
start

int main()
{
    float area;
    // shape 1
    printf("shape 1\ncontains a semi-circle and a rectangle\n");
    area = circle(4)/2 + rectangle(12, 8);
    printf("Area of shape 1: %.2fft\n\n",area);start

    // shape 2
    printf("shape 2\ncontains a triangle and a rectangle\n");
    area = rectangle(13,8) + triangle(8,6);
    printf("Area of shape 2: %.2fin\n\n", area);

    // shape 3
    printf("shape 3\ncontains a square and rectangle\n");
    area = square(5) + rectangle(11,4);
    printf("Area of shape 3: %.2fcm\n\n", area);

    // shape 4
    printf("shape 4\ncontains a triangle and a semi circle\n");
    area = triangle(7,8) + circle(4)/2;
    printf("Area of shape 4: %.2fft\n\n", area);

    // shape 5
    printf("shape 5\ncontains a triangle and a rectangle\n");
    area = triangle(7,4) + square(7);
    printf("Area of shape 5: %.2fm\n\n", area);

    // shape 6
    printf("shape 6\ncontains 3 squares\n");
    area = square(6) * 3;
    printf("Area of shape 6: %.2fyd\n\n", area);



    //COMPOUND FIGURES
    //SHAPE 1
    printf("Compound shape 1\nContains a semi-circle and a trapezium\n");
    area = trapezium(13,12,24) + circle(9)/2;
    printf("Area of Compound shape 1: %.2fin\n\n", area);

    //SHAPE 2
    printf("Compound shape 2\nContains a parallelogram minus a triangle\n");
    area = paralleogram(19,15) - triangle(19,7);
    printf("Area of Compound shape 2: %.2fft\n\n", area);

    //SHAPE 3
    printf("Compound shape 3\nContains a circle minus a triangle\n");
    area = circle(6) - triangle(12,6);
    printf("Area of Compound shape 3: %.2fyd\n\n", area);

    //SHAPE 4
    printf("Compound shape 4\nContains a parallelogram and a square\n");
    area = paralleogram(11,7) + square(11);
    printf("Area of Compound shape 4: %.2fin\n\n", area);

    //SHAPE 5
    printf("Compound shape 5\nContains a rectangle and a semi-circle\n");
    area = rectangle(22,13) + circle(11)/2;
    printf("Area of Compound shape 5: %.2fft\n\n", area);

    //SHAPE 6
    printf("Compound shape 6\nContains a rectangle minus a triangle\n");
    area = rectangle(26,17) - triangle(14,17);
    printf("Area of Compound shape 6: %.2fyd\n\n", area);


    return 0;
}


float square(float side)
{
    return side * side;
}

float circle(float radius)
{
    float a = 3.14 * (radius * radius);
    return a;
}

float triangle(float base, float height)
{
    float b = 0.5 * (base * height);
    return b;
}

float rectangle(float length, float height)
{
    return length * height;
}

float trapezium(float height, float a, float b)
{
    float c = 0.5 * height;
    return c * (a + b);
}

float paralleogram(float base, float height)
{
    return base * height;
}