/*Пусть последовательность является неубывающей. Определите
количество различных элементов этой последовательности*/
#include <stdio.h>
#include <stdlib.h>

int DiffrentsFounder(FILE *file);
int FounderAtArray(int *arr, int arrCnt, int value);


int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int diffNum = DiffrentsFounder(file);
    printf("diffNum = %i\n", diffNum);


    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int DiffrentsFounder(FILE *file)
{
    int scanValue = 0;
    int *arrDiff = (int*)malloc(sizeof(int) * 1024);
    int arrDiffCnt = 0;

    while(1 == fscanf(file, "%i", &scanValue))
    {
        if(0 == FounderAtArray(arrDiff, arrDiffCnt, scanValue))
        {
            arrDiff[arrDiffCnt] = scanValue;
            arrDiffCnt++;
        }
    }
    return arrDiffCnt+1;
}

int FounderAtArray(int *arr, int arrCnt, int value)
{
    int result = 0;
    for(int i = 0; i < arrCnt; i++)
    {
        if(arr[i] == value)
        {
            result = 1;
            break;
        }
    }
    return result;
}
