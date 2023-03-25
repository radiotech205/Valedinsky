/*Подсчитайте количество положительных, отрицательных и ну-
левых чисел последовательности.*/
#include <stdio.h>
#include <stdlib.h>

int MembersOfSequensity(FILE *file,
                         int *numPositive, int *numZero, int *numNegative);

int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int numPositive = 0;
    int numZero = 0;
    int numNegative = 0;
    int numTotal = 0;

    numTotal = MembersOfSequensity(fileGen32, &numPositive,  &numZero, &numNegative);
    printf("numTotal = %i\n", numTotal);
    printf("numPositive = %i\n", numPositive);
    printf("numZero = %i\n", numZero);
    printf("numNegative = %i\n", numNegative);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int MembersOfSequensity(FILE *file,
                         int *numPositive, int *numZero, int *numNegative)
{
    int scanfValue = 0;
    int totalCnt = 0;

    while(1 == fscanf(file, "%i", &scanfValue))
    {
        if(scanfValue < 0)
            (*numNegative)++;
        else if(scanfValue > 0)
            (*numPositive)++;
        else
            (*numZero)++;
        totalCnt++;
    }
    return totalCnt;
}
