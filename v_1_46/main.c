/*1.46. Введите с клавиатуры число x и определите количество эле-
ментов массива, расстояние от которых до x в два раза меньше, чем
максимальное расстояние между x и элементами массива.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_MEMB    32
#define PRINT_VAR_NAME(var) #var
double DistMaxComputer(double *arrX, int arrXCnt, double xValue);
int NumElementsComputer(double *arrX, int arrXCnt, double xValue, double arrXDistMax);

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

    double arrXDistMax = DistMaxComputer(arrX, arrXCnt, xValue);
    int numElem = NumElementsComputer(arrX, arrXCnt, xValue, arrXDistMax);

    printf("%s = %lf, %s = %lf, %s = %i\n",
           PRINT_VAR_NAME(xValue), xValue,
           PRINT_VAR_NAME(arrXDistMax), arrXDistMax,
           PRINT_VAR_NAME(numElem), numElem);

    printf("Hello World!\n");
    return 0;
}

double DistMaxComputer(double *arrX, int arrXCnt, double xValue)
{
    double distMax = sqrt(pow(arrX[0] - xValue, 2.0));
    double dist = 0.0;

    for(int i = 0; i < arrXCnt; i++)
    {
        dist = sqrt(pow(arrX[i] - xValue,2.0));
        if(dist > distMax)
            distMax = dist;
    }
    return distMax;
}

int NumElementsComputer(double *arrX, int arrXCnt, double xValue, double arrXDistMax)
{
    int numElem = 0;
    double dist = 0.0;

    for(int i = 0; i < arrXCnt; i++)
    {
        dist = sqrt(pow(arrX[i] - xValue, 2.0));
        if(fabs(dist - arrXDistMax/2.0) < 0.001)
        {
            numElem++;
            printf("(%lf) ", arrX[i]);
        }
    }
    if(numElem != 0)
        printf("\n");

    return numElem;
}
