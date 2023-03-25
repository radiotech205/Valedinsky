#include <stdio.h>
#include <stdlib.h>

void PrimeComputer(int nValue, int *arrPN, int *arrPNSize);
int Search(int *arr, int arrSize, int value);


int main(int argc, char *argv[])
{
    int mValue = (argc >= 2) ? atoi(argv[1]) : 6;

    const int maxNumber = mValue;

    int *arrPN = (int*)malloc(sizeof(int) * maxNumber);
    int arrPNSize = 0;
    PrimeComputer(maxNumber, arrPN, &arrPNSize);
    printf("Computing of Primary Numbers is done\n");
    int *arrMembers = (int*)malloc(sizeof(int) * maxNumber);
    int arrMembersSize = 0;

    int pnValue = 0;

    while(mValue != 1)
    {
        for(int i = 0; i < arrPNSize; i++)
        {
            if((mValue % arrPN[i]) == 0)
            {
                pnValue = arrPN[i];
                break;
            }
        }

        mValue /= pnValue;
        arrMembers[arrMembersSize] = pnValue;
        arrMembersSize++;
    }

    mValue = (argc >= 2) ? atoi(argv[1]) : 6;
    printf("mValue = %i:\n", mValue);
    if(arrMembersSize == 0)
        printf("is primary number.\n");

    for(int i = 0; i < arrMembersSize; i++)
        printf("%i ", arrMembers[i]);

    printf("\n");



    free(arrPN);
    free(arrMembers);
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

int Search(int *arr, int arrSize, int value)
{
    int result = -1;
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] == value)
        {
            result = i;
            break;
        }
    }
    return result;
}
