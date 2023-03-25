#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void PrimeComputer(int nValue, int *arrPN, int *arrPNSize);

int main(int argc, char *argv[])
{
    int nValue = (argc >= 2) ? atoi(argv[1]) : 8;


    int *arrPN = (int*)malloc(sizeof(int) * nValue);
    int arrPNSize = 0;


    PrimeComputer(nValue, arrPN, &arrPNSize);




    for(int i = 0; i < arrPNSize; i++)
        printf("%i\n", arrPN[i]);


    free(arrPN);
    printf("Hello World!\n");
    return 0;
}


void PrimeComputer(int nValue, int *arrPN, int *arrPNSize)
{
    int pnCnt = 0;
    for(int i = 1; i < nValue; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if((i % j) == 0)
                pnCnt++;
        }

        if(pnCnt == 2)
        {
            arrPN[*arrPNSize] = i;
            (*arrPNSize)++;
        }
        pnCnt = 0;
    }
}
