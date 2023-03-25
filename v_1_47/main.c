/*1.47. Введите с клавиатуры число x и удалите из массива все эле-
менты, превосходящие x , а оставшиеся уплотните (т.е. сдвиньте к началу
массива с сохранением их порядка).*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB    32

void DeleteAndMove(double *arr, int *arrSize, int deletePos);
void Computer(double *arrX, int *arrXSize, double xValue);

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
        arrX[i] = (double)(rand()%10);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");


    Computer(arrX, &arrXSize, xValue);


    printf("arrX:\n");
    for(int i = 0; i < arrXSize; i++)
    {
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");


    printf("Hello World!\n");
    return 0;
}

void DeleteAndMove(double *arr, int *arrSize, int deletePos)
{
    for(int i = deletePos; i < *arrSize-1; i++)
        arr[i] = arr[i + 1];
    (*arrSize)--;
}

void Computer(double *arrX, int *arrXSize, double xValue)
{
    for(int i = 0; i < *arrXSize; i++)
    {
        if(arrX[i] > xValue)
        {
            DeleteAndMove(arrX, arrXSize, i);
            i = -1;
        }
    }
}
