#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
Дано множество отрезков. Найти точку, которая принадлежит
наибольшему количеству отрезков, определить это количество.
*/
typedef struct
{
    double x1;
    double x2;
} coordX_s;


int main(int argc, char *argv[])
{
    int fileNameSize = (argc >= 2) ? strlen(argv[1]) : 0;
    double point = (argc >= 3) ? atof(argv[2]) : 0.0;


    char *fileName = (char*)malloc(fileNameSize);
    if(argc >= 2)
        strcpy(fileName, argv[1]);
    else
    {
        printf("argc = %i, exit\n", argc);
        return 1;
    }

    int nmValue = 0;
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Can not open file %s, exit\n", fileName);
        return 1;
    }
    fscanf(file, "%i\n", &nmValue);
    printf("nmValue = %i\n", nmValue);
    coordX_s *arrCoord = (coordX_s*)malloc(sizeof(coordX_s) * nmValue);

    for(int i = 0; i < nmValue; i++)
    {
        fscanf(file, "%lf \t %lf\n", &arrCoord[i].x1, &arrCoord[i].x2);
        printf( "%i - %06.3lf \t %06.3lf\n", i, arrCoord[i].x1, arrCoord[i].x2);
    }
    fclose(file);

    int insertCnt = 0;
    const double eps = pow(10.0, -6.0);
    for(int i = 0; i < nmValue; i++)
    {
        int pEqualX1 = fabs(point - arrCoord[i].x1) < eps;
        int pEqualX2 = fabs(point - arrCoord[i].x2) < eps;

        int pMoreX1 = point > arrCoord[i].x1;
        int pLessX2 = point < arrCoord[i].x2;

        if((pEqualX1 || pMoreX1) && (pEqualX2 || pLessX2))
            insertCnt++;
    }

    printf("insertCnt = %i\n", insertCnt);




    free(arrCoord);
    printf("Hello World!\n");
    return 0;
}
