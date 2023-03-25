/*1.44. Введите с клавиатуры число x и определите индекс и значение
элемента массива, ближайшего к числу x .*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    32

int NearestFounder(double *arrX, int arrXCnt, double xValue, double *nearValue);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    double *arrX = (double*)malloc(sizeof(double) * NUM_MEMB);
    int arrXCnt = NUM_MEMB;

    double xValue = atof(argv[1]);

    printf("arrX:\n");
    for(int i = 0; i < arrXCnt; i++)
    {
        arrX[i] = (double)(rand()%10);
        printf("%4.1lf ", arrX[i]);
    }
    printf("\n");

    double nearValue = 0;
    int nearPos = NearestFounder(arrX, arrXCnt, xValue, &nearValue);

    printf("xValue = %lf, nearValue = %lf, nearPos = %i\n",
           xValue, nearValue, nearPos);

    printf("Hello World!\n");
    return 0;
}

int NearestFounder(double *arrX, int arrXCnt, double xValue, double *nearValue)
{
    int nearPos = 0;
    double distMin = sqrt(pow(xValue - arrX[0], 2.0));
    double dist = 0.0;

    for(int i = 0; i < arrXCnt; i++)
    {
        dist = sqrt(pow(xValue - arrX[i],2.0));
        if(dist <= distMin)
        {
            distMin = dist;
            *nearValue = arrX[i];
            nearPos = i;
            break;
        }
    }
    return nearPos;
}
