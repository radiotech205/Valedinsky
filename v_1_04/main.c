/*Обозначим элементы последовательности x k , k = 0, 1, . . . .
Введите с клавиатуры четыре числа a, b, c, d и проверьте, удовлетво-
ряют ли элементы последовательности рекуррентному соотношению
ax k + bx k+1 + cx k+2 = d .*/
#include <stdio.h>
#include <stdlib.h>

int ValueComputer(FILE *fileGen32, int a, int b, int c, int d);

int main(int argc, char* argv[])
{
    const int argNumber = 5;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);


    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int computeValue = ValueComputer(fileGen32, a, b, c, d);
    if(computeValue == d)
        printf("Equal! %i == %i\n", computeValue, d);
    else
        printf("Not equal! %i != %i\n", computeValue, d);






    fclose(fileGen32);

    printf("Hello World!\n");
    return 0;
}

int ValueComputer(FILE *fileGen32, int a, int b, int c, int d)
{
    int arrX[3];
    int result = 0;

    result = fscanf(fileGen32,"%i",&arrX[0]);
    result = fscanf(fileGen32,"%i",&arrX[1]);
    result = fscanf(fileGen32,"%i",&arrX[2]);

    int computeValue = a*arrX[0] + b*arrX[1] + c * arrX[2];

    printf("%i * %i + %i * %i + %i * %i = %i, must: %i\n",
           a, arrX[0], b, arrX[1], c, arrX[2], computeValue,d);

    return computeValue;
}
