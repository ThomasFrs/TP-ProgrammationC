#include <stdio.h>
#include <math.h>

void exercice3()
{
        int number;
        printf("Enter a number : ");
        scanf("%d", &number);

        printf("Square of number is : %d\n", number*number);
}

void exercice4()
{
    double number;
    printf("Enter a number : ");
    scanf("%lf", &number);
    printf("Square root of number is : %f\n", pow(number, 0.5));
}

void exercice5()
{
        int a,b;
        printf("Enter a and b : ");
        scanf("%d %d", &a, &b);
        int temp = a;
        a = b;
        b = temp;
        printf("a = %d, b = %d\n", a, b);
}

void exercice6()
{
        int farenheit;
        printf("Enter temperature in Farenheit : ");
        scanf("%d", &farenheit);
        
        int celsius =  (5.0f/9.0f) * (farenheit - 32);
        printf("Farenheit = %d, Celsius = %d\n", farenheit, celsius); 
}

void exercice7()
{
        unsigned char number;
        printf("Enter a number : ");
        scanf("%hhu", &number);

        unsigned char square = number * number;
        printf("Square of number is : %c\n", square);

        // 8 returns '@' because it's the 64th character in the ASCII alphabet
        // 16 returns nothing because a char is made of 8-bits and 256 > 255 (max nb)
}

void exercice8()
{
        float numbers[5], min, max;
        for( int i = 0; i < sizeof(numbers)/sizeof(int); i++ )
        {
                scanf("%f", &numbers[i]);
                if(i == 0) min = numbers[i], max = numbers[i];

                if( numbers[i] < min) min = numbers[i];
                else if( numbers[i] > max) max = numbers[i];
        }


        for( int i = 0; i < sizeof(numbers)/sizeof(int); i++ )
                printf("%f ", numbers[i]);
        printf("| Min = %f | Max = %f\n", min, max);  
}

int main()
{
        printf("Hello, World!\n");
        exercice8();
        return 0;
}
