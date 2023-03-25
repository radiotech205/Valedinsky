/*Введите с клавиатуры число x и определите к какому значению
ближе всего x : к минимальному в массиве, максимальному или среднему
арифметическому*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    32
#define PRINT_VAR_NAME(var) #var
int NearestFounder2(double *arrX, int arrXCnt, double xValue,
                   double *arrXValMin, double *arrXValAVG, double *arrXValMax);

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

    double arrXValMin = 0.0;
    double arrXValAVG = 0.0;
    double arrXValMax = 0.0;

    int result = NearestFounder2(arrX, arrXCnt, xValue,
                                &arrXValMin, &arrXValAVG, &arrXValMax);
    printf("%s = %i, %s = %lf, %s = %lf, %s = %lf, %s = %lf\n",
           PRINT_VAR_NAME(result), result,
           PRINT_VAR_NAME(xValue), xValue,
           PRINT_VAR_NAME(arrXValMin), arrXValMin,
           PRINT_VAR_NAME(arrXValAVG), arrXValAVG,
           PRINT_VAR_NAME(arrXValMax), arrXValMax);

    printf("Hello World!\n");
    return 0;
}

int NearestFounder2(double *arrX, int arrXCnt, double xValue,
                   double *arrXValMin, double *arrXValAVG, double *arrXValMax)
{
    int result = -1;
    *arrXValMin = arrX[0];
    *arrXValMax = arrX[0];
    double arrXSum = 0.0;

    for(int i = 0; i < arrXCnt; i++)
    {
        arrXSum += arrX[i];

        if(arrX[i] < *arrXValMin)
            *arrXValMin = arrX[i];

        if(arrX[i] > *arrXValMax)
            *arrXValMax = arrX[i];
    }
    *arrXValAVG = arrXSum / (double)arrXCnt;

    double distMin = sqrt(pow((*arrXValMin - xValue),2.0));
    double distAVG = sqrt(pow((*arrXValAVG - xValue),2.0));
    double distMax = sqrt(pow((*arrXValMax - xValue),2.0));

    if((distMin < distAVG) && (distMin < distMax))
        result = 0;
    else if((distAVG < distMin) && (distAVG < distMax))
        result = 1;
    else if((distMax < distMin) && (distMax < distAVG))
        result = 2;


    return result;
}
