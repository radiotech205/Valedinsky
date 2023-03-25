/*1.21. Введите с клавиатуры число n и определите количество посто-
янных участков последовательности, имеющих длину не меньше n.*/
#include <stdio.h>
#include <stdlib.h>

int EqualLenghtComputer(FILE *file, int number);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    int number = atoi(argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int equalLenght = EqualLenghtComputer(file, number);
    printf("number = %i, equalLenght = %i\n", number, equalLenght);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int EqualLenghtComputer(FILE *file, int number)
{
    int equalLenght = 0;

    int scanVal = 0;
    int newScanVal = 0;

    int lenght = 1;
    int lenghtMax = 0;

    fscanf(file,"%i", &scanVal);
    while(1 == fscanf(file, "%i", &newScanVal))
    {
        if(scanVal == newScanVal)
        {
            lenght++;
            if(lenght > lenghtMax)
                lenghtMax = lenght;
        }
        else
        {
            if(lenght >= number)
                equalLenght++;

            lenght = 1;
        }
        scanVal = newScanVal;
    }
    return equalLenght;
}
