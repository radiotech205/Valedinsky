/*Составьте программу для вычисления среднего арифметического
элементов числовой последовательности*/
#include <stdio.h>
#include <stdlib.h>

double AvgComputer(FILE *fileGen32);

int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    double avg = AvgComputer(fileGen32);
    printf("avg = %lf\n", avg);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

double AvgComputer(FILE *fileGen32)
{
    int arrXValue = 0;
    int cnt = 0;
    double sum = 0.0;
    double avg = 0.0;

    while(fscanf(fileGen32,"%i", &arrXValue) == 1)
    {
        sum += (double)arrXValue;
        cnt++;
    }
    avg = sum / (double)cnt;

    return avg;
}

