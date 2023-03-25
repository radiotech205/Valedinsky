/*1.22. Определите сколько элементов последовательности (не) содер-
жится в постоянных участках длины 2 и более.*/
#include <stdio.h>
#include <stdlib.h>

int NumberEmementsComputer(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int numElements = NumberEmementsComputer(file);
    printf("numElements = %i\n", numElements);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int NumberEmementsComputer(FILE *file)
{
    int numElements = 0;

    int scanVal = 0;
    int newScanVal = 0;

    int lenght = 1;

    fscanf(file,"%i", &scanVal);
    while(1 == fscanf(file, "%i", &newScanVal))
    {
        if(scanVal == newScanVal)
        {
            lenght++;
        }
        else
        {
            if(lenght > 2)
                numElements += lenght;

            lenght = 1;
        }

        scanVal = newScanVal;
    }
    return numElements;
}
