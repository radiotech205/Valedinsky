#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    double x1;
    double x2;
} coordX_s;

int RangeAdder(coordX_s *range, coordX_s point, double eps, int mode);

int main(int argc, char *argv[])
{
    int fileNameSize = (argc >= 2) ? strlen(argv[1]) : 0;
    coordX_s rangeInput;
    rangeInput.x1 = (argc >= 3) ? atof(argv[2]) : 0.0;
    rangeInput.x2 = (argc >= 4) ? atof(argv[3]) : 0.0;


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

//    double lowRange = 0.0;
//    double hiRange = 0.0;
    coordX_s range;
    const double eps = pow(10.0, -6.0);

    for(int i = 0; i < nmValue; i++)
    {
        RangeAdder(&range, arrCoord[i], eps, 1);
    }
    printf("Total: %lf, %lf\n", range.x1, range.x2);

    int result = RangeAdder(&range, rangeInput, eps, 0);
    printf("result = %i\n", result);

    free(arrCoord);
    printf("Hello World!\n");
    return 0;
}

int RangeAdder(coordX_s *range, coordX_s point, double eps, int mode)
{
    if(fabs(range->x1 - range->x2) < eps)
    {
        if(mode)
        {
            range->x1 = point.x1;
            range->x2 = point.x2;
            printf("add clip (%lf %lf), now (%lf, %lf)\n",
                   point.x1, point.x2,
                   range->x1, range->x2);
        }
        else
            return 0;
    }
    else if((point.x1 < range->x1) && (point.x2 > range->x1) && (point.x2 < range->x2))
    {
        if(mode)
        {
            range->x1 = point.x1;
            printf("add clip (%lf %lf), now (%lf, %lf)\n",
                   point.x1, point.x2,
                   range->x1, range->x2);
        }
        else
            return 0;
    }
    else if((point.x1 > range->x1) && (point.x1 < range->x2) && (point.x2 > range->x2))
    {
        if(mode)
        {
            range->x2 = point.x2;
            printf("add clip (%lf %lf), now (%lf, %lf)\n",
                   point.x1, point.x2,
                   range->x1, range->x2);
        }
        else
            return 0;
    }
    else if((point.x1 < range->x1) && (fabs(range->x1 - point.x2) < eps))
    {
        if(mode)
        {
            range->x1 = point.x1;
            printf("add clip (%lf %lf), now (%lf, %lf)\n",
                   point.x1, point.x2,
                   range->x1, range->x2);
        }
        else
            return 0;
    }
    else if((fabs(range->x2 - point.x1) < eps) && (point.x2 > range->x2))
    {
        if(mode)
        {
            range->x2 = point.x2;
            printf("add clip (%lf %lf), now (%lf, %lf)\n",
                   point.x1, point.x2,
                   range->x1, range->x2);
        }
        else
            return 0;
    }
    else if(((fabs(range->x1 - point.x1) < eps) || point.x1 > range->x1) &&
            ((fabs(range->x2 - point.x2) < eps) || (point.x2 < range->x2)))
    {
        if(mode == 0)
            return 0;
    }
    else if((point.x1 < range->x1) && (fabs(range->x2 - point.x2) < eps))
    {
        if(mode == 0)
            return 0;
    }
    else if((fabs(range->x1 - point.x1) < eps) && (point.x2 > range->x2))
    {
        if(mode == 0)
            return 0;
    }
    else if((point.x1 < range->x1) && (point.x2 > range->x2))
    {
        if(mode == 0)
            return 0;
    }
    else
    {
        if(mode == 0)
            return 1;
    }
    return 1;
}
