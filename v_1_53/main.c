/*1.53. Измените решение предыдущей задачи так, чтобы функция
search дополнительно определяла индекс найденного элемента в мас-
сиве либо позицию, в которую можно поставить искомый элемент, если
он не присутствует в массиве.*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB    32

int Search(double *arrX, int arrXSize, double xValue, int *xPosition);

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

    int xPosition = 0;
    int result = Search(arrX, arrXSize, xValue, &xPosition);
    printf("xValue = %lf, result = %i, xPosition = %i\n", xValue, result, xPosition);

    printf("Hello World!\n");
    return 0;
}


int Search(double *arrX, int arrXSize, double xValue, int *xPosition)
{
    int result = 0;
    int left, right, mid;

    if((xValue < arrX[0]))
    {
        *xPosition = -1;
        return 0;
    }
    if(xValue > arrX[arrXSize-1])
    {
        *xPosition = arrXSize;
        return 0;
    }

    left = 0;
    right = arrXSize-1;

    while((right-left) > 1)
    {
        mid = (left + right)/2;
        if(xValue == arrX[mid])
        {
            *xPosition = mid;
            return 1;
        }
        if(xValue > arrX[mid])
            left = mid;
        else
            right = mid;
    }

    printf("l = %i, m = %i, r = %i\n", left, mid, right);
    if(xValue == arrX[right])
    {
        result = 1;
        *xPosition = right;
    }
    else
    {
        result = 0;
        *xPosition = right;
    }

    return result;
}
