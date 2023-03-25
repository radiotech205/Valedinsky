/*1.54. Пусть элементы массива не убывают. Требуется вставить в
этот массив новый элемент x с сохранением упорядоченности всего мас-
сива. Местоположение нового элемента определить последовательным
поиском.*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB    32

int Insert(double *arrX, int arrXSize, double xValue);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXSize = NUM_MEMB;

    double xValue = atof(argv[1]);

    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        arrX[i] = (double)(rand()%3 + i);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    arrXSize = Insert(arrX, arrXSize, xValue);

    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    printf("Hello World!\n");
    return 0;
}

int Insert(double *arrX, int arrXSize, double xValue)
{
    int position = 0;
    for(int i = 0; i < arrXSize; i++)
    {
        if(xValue < arrX[i])
        {
            position = i;
            break;
        }
    }

    for(int j = arrXSize; j > position; j--)
    {
        arrX[j] = arrX[j-1];
    }
    arrX[position] = xValue;
    return arrXSize + 1;
}
