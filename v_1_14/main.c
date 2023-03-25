/*Определите порядковый номер первого числа, равного макси-
муму из всех чисел последовательности.*/
#include <stdio.h>
#include <stdlib.h>

void MaxFounder(FILE *file, int *firstMaxPos, int *firstMaxVal);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int firstMaxPos = 0;
    int firstMaxVal = 0;



    MaxFounder(file, &firstMaxPos, &firstMaxVal);
    printf("firstMaxPos = %i\n", firstMaxPos);
    printf("firstMaxVal = %i\n", firstMaxVal);


    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void MaxFounder(FILE *file, int *firstMaxPos, int *firstMaxVal)
{
    int maxVal = 0;
    int scanVal = 0;
    int posCnt = 0;

    while(1 == fscanf(file, "%i", &scanVal))
    {
        if(scanVal > maxVal)
        {
            maxVal = scanVal;
            *firstMaxPos = posCnt;
            *firstMaxVal = maxVal;
        }
        posCnt++;
    }
}

