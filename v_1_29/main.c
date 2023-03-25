/*1.29. Последовательность чисел представляет собой коэффициенты
многочлена, расположенные в порядке возрастания степеней. Введите с
клавиатуры число x и вычислите значение многочлена и его производной
в точке x .*/
#include <stdio.h>
#include <stdlib.h>

void SequensityComputer(FILE *file, double valueX, double *valueFx, double *valueDFx);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    double valueX = atof(argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    double valueFx = 0.0;
    double valueDFx = 0.0;

    SequensityComputer(file, valueX, &valueFx, &valueDFx);

    printf("valueX = %lf\n", valueX);
    printf("valueFx = %lf\n", valueFx);
    printf("valueDFx = %lf\n", valueDFx);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void SequensityComputer(FILE *file, double valueX, double *valueFx, double *valueDFx)
{
    int valueA = 0;

    double valuePkm = 0.0;
    double valuePk = 0.0;

    double valueDkm = 0.0;
    double valueDk = 0.0;

    while(1 == fscanf(file,"%i", &valueA))
    {
        valuePk = valueX * valuePkm + valueA;
        valueDk = valuePkm + valueDkm;

        valuePkm = valuePk;
        valueDkm = valueDk;
    }
    *valueFx = valuePk;
    *valueDFx = valueDk;
}
