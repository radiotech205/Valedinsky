#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    double x;
    double y;
} coord_s;

int Intersect(coord_s a, coord_s b, coord_s c, coord_s d, double eps);

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

    /**************************************************/
    for(int i = 0; i < nmValue; i += 1)
    {
        //printf("%i - %i\n", i, i+1);
        for(int j = i+1; j < nmValue; j += 1)
        {
            //printf("\t %i - %i\n", j, j+1);
            if(Intersect(arrCoord[i], arrCoord[i+1], arrCoord[j], arrCoord[j+1], 1e-9))
            {
                if((i+1) != j)
                    printf("Intersect %i-%i & %i-%i\n",i, i+1, j, j+1);
            }
        }
    }




    free(arrCoord);
    printf("Hello World!\n");
    return 0;
}

void Swap(double *a, double *b)
{
    double temp = *b;
    *b = *a;
    *a = temp;
}

double Max(double a, double b)
{
    return (a > b) ? a : b;
}

double Min(double a, double b)
{
    return (a < b) ? a : b;
}

double Area(coord_s a, coord_s b, coord_s c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int Intersect1(double a, double b, double c, double d, double eps)
{
    if(a > b)
        Swap(&a, &b);
    if(c > d)
        Swap(&c, &d);

    return ((Max(a, c) < Min(b, d)) || ((fabs(Max(a, c) - Min(b, d))) < eps));
}

int Intersect(coord_s a, coord_s b, coord_s c, coord_s d, double eps)
{
    return Intersect1(a.x, b.x, c.x, d.x, eps)
            && Intersect1(a.y, b.y, c.y, d.y, eps)
            && ((Area(a, b, c) * Area(a, b, d) < 0) || (fabs(Area(a, b, c) * Area(a, b, d)) < eps))
            && ((Area(c, d, a) * Area(c, d, b) < 0) || (fabs(Area(c, d, a) * Area(c, d, b)) < eps));
}
