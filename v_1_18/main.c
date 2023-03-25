/*1.18. Вычислите среднее квадратическое отклонение D от среднего
арифметического M для элементов последовательности, т.е. суммы*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void StatisticsComputer(FILE *file, double *AVG, double *Disp);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    double AVG = 0.0;
    double Disp = 0.0;

    StatisticsComputer(file, &AVG, &Disp);

    printf("AVG = %lf\n", AVG);
    printf("Disp = %lf\n", Disp);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void StatisticsComputer(FILE *file, double *AVG, double *Disp)
{
    int scanValue = 0;
    double cnt = 0.0;
    double sum = 0.0;

    double sumPow2 = 0.0;
    while(1 == fscanf(file, "%i", &scanValue))
    {
        cnt += 1.0;
        sum += (double)scanValue;
        *AVG = sum / cnt;

        sumPow2 += pow((double)scanValue - *AVG ,2.0);
        *Disp = sumPow2 / cnt;
    }
}
