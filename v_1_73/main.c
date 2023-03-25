#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    double x;
    double y;
} coord_s;

double LenghtComputer(coord_s a, coord_s b);

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

    double lenghtMax = 0.0;
    int lenghtMaxInd0 = 0;
    int lenghtMaxInd1 = 0;
    double lenght = 0.0;

    for(int i = 0; i < nmValue; i++)
    {
        for(int j = i+1+1; j < nmValue+i-1; j++)
        {
//            printf("%i - %i\n", i, j%nmValue);
            lenght = LenghtComputer(arrCoord[i], arrCoord[j%nmValue]);
            if(lenght > lenghtMax)
            {
                lenghtMax = lenght;
                lenghtMaxInd0 = i;
                lenghtMaxInd1 = j%nmValue;
            }
        }
    }

    printf("lenghtMax = %lf, i = %i, j = %i\n", lenghtMax, lenghtMaxInd0, lenghtMaxInd1);

    free(arrCoord);
    printf("Hello World!\n");
    return 0;
}


double LenghtComputer(coord_s a, coord_s b)
{
    return sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0));
}
