#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
typedef struct
{
    double x1;
    double x2;
} coordX_s;

/*
Дано множество отрезков. Выбрать из него и вывести связное
подмножество отрезков, объединение которых дает отрезок наибольшей
длины.
 */
int MemoryChecker(void *ptr);
int FoundX2AtArray(coordX_s *arrCoordX, uint32_t arrCoordXSize, double value, double eps);
double LenghtComputer(coordX_s arrCoordX);



int main(int argc, char *argv[])
{
    int numObjects = (argc >= 2) ? atoi(argv[1]) : 5;
    coordX_s *arrCoordX = (coordX_s*)malloc(sizeof(coordX_s) * numObjects);

    for(int i = 0; i < numObjects; i++)
    {
        arrCoordX[i].x1 = (double)(rand()%25);
        arrCoordX[i].x2 = arrCoordX[i].x1 + (double)(rand()%5 + 1);
        printf("%lf \t %lf\n", arrCoordX[i].x1, arrCoordX[i].x2);
    }

    coordX_s **arrCoordX2D = (coordX_s**)malloc(sizeof(coordX_s*) * numObjects);
    MemoryChecker(arrCoordX2D);
    for(int i = 0; i < numObjects; i++)
    {
        arrCoordX2D[i] = (coordX_s*)malloc(sizeof(coordX_s) * numObjects);
        MemoryChecker(arrCoordX2D[i]);
    }

    uint32_t *arrCoordX2DSizes = (uint32_t*)malloc(sizeof(uint32_t) * numObjects);
    MemoryChecker(arrCoordX2DSizes);
    memset(arrCoordX2DSizes, 0, sizeof(uint32_t) * numObjects);

    for(int i = 0; i < numObjects; i++)
    {
        for(int j = i; j < numObjects; j++)
        {
            int resultX2 = FoundX2AtArray(arrCoordX2D[i], arrCoordX2DSizes[i], arrCoordX[j].x1, 0.1);
            if(!resultX2)
            {
                int index = arrCoordX2DSizes[i];
                arrCoordX2D[i][index] = arrCoordX[j];
                arrCoordX2DSizes[i] += 1;
            }
        }

    }


    for(int j = 0; j < numObjects; j++)
    {
        for(uint i = 0; i < arrCoordX2DSizes[j]; i++)
        {
            printf("(%lf;%lf) ", arrCoordX2D[j][i].x1, arrCoordX2D[j][i].x2);
        }
        printf("\n");
    }

    double *arrClipLenghts = (double*)malloc(sizeof(double) * numObjects);
    MemoryChecker(arrClipLenghts);
    memset(arrClipLenghts, 0.0, sizeof(double) * numObjects);

//     printf("------------------------------------\n");

    for(int j = 0; j < numObjects; j++)
    {
        for(int i = 0; i < numObjects; i++)
        {
            arrClipLenghts[j] += LenghtComputer(arrCoordX2D[j][i]);
        }
//        printf("%lf\n", arrClipLenghts[j]);
    }

    double max = arrClipLenghts[0];
    int maxPos = 0;
    for(int i = 0; i < numObjects; i++)
    {
        if(arrClipLenghts[i] > max)
        {
            max = arrClipLenghts[i];
            maxPos = i;
        }
    }

     printf("------------------------------------\n");
    for(uint i = 0; i < arrCoordX2DSizes[maxPos]; i++)
        printf("(%lf;%lf) ", arrCoordX2D[maxPos][i].x1, arrCoordX2D[maxPos][i].x2);


    free(arrCoordX);
    for(int i = 0; i < numObjects; i++)
        free(arrCoordX2D[i]);
    free(arrCoordX2D);
    free(arrCoordX2DSizes);
    free(arrClipLenghts);


    printf("Hello World!\n");
    return 0;
}


int MemoryChecker(void *ptr)
{
    int result = 1;
    if(ptr == NULL)
    {
        printf("Error in malloc, exit \n");
        result = 1;
    }
    else
        result = 0;
    return result;
}

int FoundX2AtArray(coordX_s *arrCoordX, uint32_t arrCoordXSize, double value, double eps)
{
    int result = 1;
    double x2 = arrCoordX[arrCoordXSize].x2;
    if(fabs(x2 - value) < eps)
        result = 0;
    else if((fabs(x2 - 0.0) < eps) && (arrCoordXSize == 0))
        result = 0;
    else if(fabs(arrCoordX[arrCoordXSize-1].x2 - value) < eps)
        result = 0;
    else
        result = 1;

//    printf("{ ");
//    for(uint i = 0; i < arrCoordXSize; i++)
//        printf("(%lf,%lf) ", arrCoordX[i].x1, arrCoordX[i].x2);
//    printf("}\n");


    return result;
}

double LenghtComputer(coordX_s arrCoordX)
{
    double lenght = arrCoordX.x2 - arrCoordX.x1;
    return lenght;
}
