/*1.15. Определите количество чисел, равных минимуму из всех чисел
последовательности.*/
#include <stdio.h>
#include <stdlib.h>

int  MinimumCounter(FILE *file, int *minValue);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int minValue = 0;
    int minCount = MinimumCounter(file, &minValue);

    printf("minCount = %i\n", minCount);
    printf("minValue = %i\n", minValue);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int MinimumCounter(FILE *file, int *minValue)
{
    int minCount = 0;
    int scanValue = 0;
    fscanf(file, "%i", &scanValue);
    *minValue = 0;
    rewind(file);
    while(1 == fscanf(file, "%i", &scanValue))
    {
        if(scanValue < *minValue)
            *minValue = scanValue;
        else if(scanValue == *minValue)
            minCount++;
    }
    return minCount;
}
