#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    double x;
    double y;
} coord_s;

double TriangelArea(coord_s a, coord_s b, coord_s c);

int main(int argc, char *argv[])
{
    int fileNameSize = (argc >= 2) ? strlen(argv[1]) : 32;

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
    coord_s *arrCoord = (coord_s*)malloc(sizeof(coord_s) * nmValue);

    for(int i = 0; i < nmValue; i++)
    {
        fscanf(file, "%lf \t %lf\n", &arrCoord[i].x, &arrCoord[i].y);
        printf( "%i - %06.3lf \t %06.3lf\n", i, arrCoord[i].x, arrCoord[i].y);
    }
    fclose(file);

    int *arrSigns = (int*)malloc(sizeof(int) * nmValue);
    int arrSignsSize = 0;

    for(int i = 0; i < nmValue - 2; i++)
    {
        int j = i + 1;
        int k = j + 1;
        printf("%i %i %i\n", i, j, k);
        double result = TriangelArea(arrCoord[i], arrCoord[j], arrCoord[k]);
        printf("result = %lf\n", result);
        arrSigns[i] = (result > 0) ? 1 : 0;
        arrSignsSize++;
    }

    for(int i = 1; i < arrSignsSize; i++)
    {
        if(arrSigns[i-1] != arrSigns[i])
            printf("Manyangel is not fat\n");
    }

    free(arrCoord);
    printf("Hello World!\n");
    return 0;
}

double TriangelArea(coord_s a, coord_s b, coord_s c)
{
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
