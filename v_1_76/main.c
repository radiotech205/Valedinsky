#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
Дано множество точек. Найти центр и радиус минимального
круга, который содержит все эти точки.
*/
typedef struct
{
    double x;
    double y;
} coord_s;

void CircleBuilder(coord_s center, double radius, int numPoints, coord_s *coordCircle);
void CircleComputer(coord_s point1, coord_s point2, coord_s point3,
                   coord_s *center, double *raduis);


int main(int argc, char *argv[])
{
    int numPoints = (argc >= 2) ? atoi(argv[1]) : 3;
    double radius = (argc >= 3) ? atof(argv[2]) : 1.0;
    coord_s coordCenter;
    coordCenter.x = (argc >= 4) ? atof(argv[3]) : 0.0;
    coordCenter.y = (argc >= 5) ? atof(argv[4]) : 0.0;

    coord_s *coordCircle = (coord_s*)malloc(sizeof(double) * 4 * numPoints);
    if(coordCircle == NULL) {printf("error of malloc\n");   return -1;}

    CircleBuilder(coordCenter, radius, numPoints, coordCircle);

    for(int i = 0; i < 2*numPoints; i++)
        printf("%lf - %lf\n", coordCircle[i].x, coordCircle[i].y);


    coord_s computeCenter;
    double computeRaduis;

    double minRadius = 0.0;
    coord_s minRadiusCenter;
    int firstRunFlag = 1;

    for(int i = 0; i < 2*numPoints - 2; i++)
    {
        for(int j = i+1; j < 2*numPoints - 1; j++)
        {
            for(int k = j+1; k < 2*numPoints; k++)
            {
                CircleComputer(coordCircle[i], coordCircle[j], coordCircle[k],
                               &computeCenter, &computeRaduis);
                printf("%i - %i - %i, (%lf, %lf) %lf\n", i, j, k, computeCenter.x, computeCenter.y, computeRaduis);
                if(firstRunFlag)
                {
                    firstRunFlag = 0;
                    minRadius = computeRaduis;
                }

                if(computeRaduis < minRadius)
                {
                    minRadius = computeRaduis;
                    minRadiusCenter = computeCenter;
                    printf("\t circle is: (%lf, %lf) %lf\n", minRadiusCenter.x, minRadiusCenter.y, minRadius);
                }
            }
        }
    }

    printf("Minimal circle is: (%lf, %lf) %lf\n", minRadiusCenter.x, minRadiusCenter.y, minRadius);


    free(coordCircle);
    printf("Hello World!\n");
    return 0;
}

void CircleBuilder(coord_s center, double radius, int numPoints, coord_s *coordCircle)
{
    int randValue = 0;
    double value = 0.0;
    for(int i = 0; i < numPoints; i++)
    {
        randValue = (rand() - RAND_MAX/2) % (int)(radius * 1000.0);
        coordCircle[i].x = (double)(randValue)/1000.0;
        value = sqrt(pow(radius, 2.0) - pow(coordCircle[i].x - center.x, 2.0)) + center.y;
        coordCircle[i].y = value;

        randValue = rand() % 2;
        if(randValue == 0)
            coordCircle[i].y *= -1.0;
    }

    for(int i = numPoints; i < 2*numPoints; i++)
    {
        randValue = (rand() - RAND_MAX/2) % (int)(radius * 1000.0);
        value = (double)(randValue)/1000.0;
        coordCircle[i].x = value;

        randValue = (rand() - RAND_MAX/2) % (int)(radius * 1000.0);
        value = (double)(randValue)/1000.0;
        coordCircle[i].y = value;
    }
}

void CircleComputer(coord_s point1, coord_s point2, coord_s point3,
                   coord_s *center, double *raduis)
{
    // center
    double maValue = (point2.y - point1.y)/(point2.x - point1.x);
    double mbValue = (point3.y - point2.y)/(point3.x - point2.x);

    center->x = (maValue*mbValue*(point1.y - point3.y) +
                     mbValue*(point1.x + point2.x) -
                     maValue*(point2.x + point3.x))
                        /(2*(mbValue - maValue));

    center->y = (-1/maValue) * (center->x - (point1.x + point2.x)/2) + (point1.y + point2.y)/2;


    *raduis = sqrt(pow(point1.x - center->x,2.0) + pow(point1.y - center->y,2.0));
}
