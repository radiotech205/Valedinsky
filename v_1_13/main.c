/*Определите значение минимального (или максимального) эле-
мента последовательности.*/
#include <stdio.h>
#include <stdlib.h>

int MaxFounder(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}



    int maxVal = MaxFounder(file);
    printf("maxVal = %i\n", maxVal);


    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int MaxFounder(FILE *file)
{
    int maxVal = 0;
    int scanVal = 0;

    while(1 == fscanf(file, "%i", &scanVal))
    {
        if(scanVal > maxVal)
        {
            maxVal = scanVal;
        }
    }
    return maxVal;
}
