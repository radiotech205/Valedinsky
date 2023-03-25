#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int Binary(uint n, int *arrBit, int arrBitSize);
void GroupMaker(int nValue, int kValue, char *fileName);



int main(int argc, char *argv[])
{
    int nValue = (argc >= 2) ? atoi(argv[1]) : 32;
    int kValue = (argc >= 3) ? atoi(argv[2]) : 8;

    char *fileName = NULL;
    if(argc >= 4)
    {
        fileName = (char*)malloc(256);
        strcpy(fileName, argv[3]);
    }
    else
        fileName = strdup("fileName.txt");

    GroupMaker(nValue, kValue, fileName);

    printf("Hello World!\n");
    return 0;
}


int Binary(uint n, int *arrBit, int arrBitSize)
{
    int mask = 1;
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

void GroupMaker(int nValue, int kValue, char *fileName)
{
    int *arrBit = (int*)malloc(sizeof(int) * nValue);
    memset(arrBit, 0, sizeof(int) * nValue);


    FILE *file = fopen(fileName, "w");

    int onesCnt = 0;
    for(uint64_t i = 0; i < ((1L << nValue) - 1L); i++)
    {
        Binary(i, arrBit, nValue);
        for(int j = 0; j < nValue; j++)
        {
            if(arrBit[j] == 1)
                onesCnt++;
        }

        if(onesCnt == kValue)
        {
            for(int j = nValue-1; j >= 0; j--)
                fprintf(file,"%i ", arrBit[j]);

            fprintf(file, "\n");
        }
        onesCnt = 0;
    }

    fclose(file);

    free(arrBit);
}
