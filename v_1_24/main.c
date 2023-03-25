/*1.24. Введите с клавиатуры число n и определите количество невоз-
растающих участков последовательности, имеющих длину не меньше
n.*/
#include <stdio.h>
#include <stdlib.h>

int NumberNonIncrComputer(FILE *file, int lenght);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    int lenght = atoi(argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int numberNonIncr = NumberNonIncrComputer(file, lenght);
    printf("numberNonIncr = %i, lenght = %i\n", numberNonIncr, lenght);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int NumberNonIncrComputer(FILE *file, int lenghtSrc)
{
    int numberNonIncr = 0;

    int lenght = 1;

    int scanVal = 0;
    int newScanVal = 0;

    fscanf(file,"%i", &scanVal);
    while(1 == fscanf(file, "%i", &newScanVal))
    {
        if(scanVal <= newScanVal)
        {
            lenght++;
        }
        else
        {
            if(lenght >= lenghtSrc)
            {
                numberNonIncr++;
            }
            lenght = 1;
        }

        scanVal = newScanVal;
    }
    return numberNonIncr;
}
