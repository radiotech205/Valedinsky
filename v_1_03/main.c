/*Составьте программу для проверки является ли последователь-
ность геометрической прогрессией.*/
#include <stdio.h>
#include <stdlib.h>

int SequensityDetecter(FILE *fileGen32);
int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int result = SequensityDetecter(fileGen32);
    printf("result = %i\n", result);

    fclose(fileGen32);

    printf("Hello World!\n");
    return 0;
}

int SequensityDetecter(FILE *fileGen32)
{
    int x = 0, y = 0, delta = 0;
    fscanf(fileGen32, "%i", &x);
    fscanf(fileGen32, "%i", &y);
    delta = y / x;
    while(fscanf(fileGen32, "%i", &x) == 1)
    {
        if(x / y != delta) return 1;
        y = x;
    }
    return 0;
}
