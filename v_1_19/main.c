/*Определите, сколько раз во входной последовательности встре-
чается подпоследовательность 1, 2, 3, . . . , 10.*/
#include <stdio.h>
#include <stdlib.h>

int  NumEntryComputer(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int numEntry = NumEntryComputer(file);
    printf("numEntry = %i\n", numEntry);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int  NumEntryComputer(FILE *file)
{
    int numEntry = 0;
    const int arrX []= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int arrXCnt = 10;
    int scanVal = 0;
    int seqTriggered = 0;
    int seqCnt = 0;
    while(1 == fscanf(file, "%i", &scanVal))
    {
        if(seqTriggered == 0)
        {
            if(scanVal == arrX[0])
            {
                seqCnt++;
                seqTriggered = 1;
            }
        }
        else
        {
            if(scanVal == arrX[seqCnt])
                seqCnt++;
            else
            {
                if(seqCnt == arrXCnt)
                    numEntry++;

                seqCnt = 0;
                seqTriggered = 0;
            }
        }
    }
    return numEntry;
}
