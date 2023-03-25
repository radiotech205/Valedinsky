/*Введите с клавиатуры число x и определите порядковый номер
первого числа, равного x .*/
#include <stdio.h>
#include <stdlib.h>

int SequensityNumberComputer(FILE *fileGen32, int x);

int main(int argc, char **argv)
{
    const int numArgc = 2;
    if(argc != numArgc)
    {
        printf("Error! argc = %i, must be %i\n", argc, numArgc);
        return -1;
    }

    int x = atoi(argv[1]);

    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int seqNuber = SequensityNumberComputer(fileGen32, x);
    printf("seqNuber = %i\n", seqNuber);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int SequensityNumberComputer(FILE *fileGen32, int x)
{
    int scanValue = 0;
    int seqCnt = 0;
    while(fscanf(fileGen32, "%i", &scanValue) == 1)
    {
        seqCnt++;
        if(scanValue == x)
            break;
    }
    return seqCnt;
}
