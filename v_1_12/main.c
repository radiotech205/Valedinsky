/*Определите номер первого и последнего максимального эле-
мента последовательности*/
#include <stdio.h>
#include <stdlib.h>

void MaxFounder(FILE *file, int *firstMaxPos, int *firstMaxVal, int *lastMaxPos, int *lastMaxVal);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int firstMaxPos = 0;
    int firstMaxVal = 0;

    int lastMaxPos = 0;
    int lastMaxVal = 0;

    MaxFounder(file, &firstMaxPos, &firstMaxVal, &lastMaxPos, &lastMaxVal);
    printf("firstMaxPos = %i\n", firstMaxPos);
    printf("firstMaxVal = %i\n", firstMaxVal);
    printf("lastMaxPos = %i\n", lastMaxPos);
    printf("lastMaxVal = %i\n", lastMaxVal);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void MaxFounder(FILE *file, int *firstMaxPos, int *firstMaxVal, int *lastMaxPos, int *lastMaxVal)
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
        else if(scanVal == maxVal)
        {
            *lastMaxPos = posCnt;
            *lastMaxVal = maxVal;
        }

        posCnt++;
    }
}
