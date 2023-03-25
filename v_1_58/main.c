#include <stdio.h>
#include <stdlib.h>

int Binary(uint n, int *arrBit, int arrBitSize)
{
    uint mask = 1;
    int i = 0;
    for(i = 0; i < arrBitSize; i++)
    {
        if(n & mask)
            arrBit[i] = 1;
        else
            arrBit[i] = 0;

        mask <<= 1;
    }
    return i;
}


int main(int argc, char *argv[])
{
    int arrBitSize = 16;
    int *arrBit = (int*)malloc(sizeof(int)*arrBitSize);

    int inputValue = 0;
    if(argc >= 2)
        inputValue = atoi(argv[1]);

    int arrBitLenght = 0;

    arrBitLenght = Binary(inputValue, arrBit, arrBitSize);

    printf("inputValue = %i\n", inputValue);
    for(int i = arrBitLenght-1; i >= 0; i--)
        printf("%i ", arrBit[i]);
    printf("\n");

    printf("Hello World!\n");
    return 0;
}
