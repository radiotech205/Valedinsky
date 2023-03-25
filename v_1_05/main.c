/*Определите количество чисел в последовательности, которые
больше предшествующего числа.*/
#include <stdio.h>
#include <stdlib.h>

int NumbersCount(FILE *fileGen32);
int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int numNumbers = NumbersCount(fileGen32);
    printf("numNumbers = %i\n", numNumbers);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int NumbersCount(FILE *fileGen32)
{
    int number = 0;
    int newNumber = 0;
    int numCnt = 0;

    fscanf(fileGen32,"%i", &number);

    while(fscanf(fileGen32,"%i", &newNumber) == 1)
    {
        if(newNumber > number)
        {
            printf("newNumber = %i, number = %i\n", newNumber, number);
            numCnt++;
        }

        number = newNumber;
    }

    return numCnt;
}
