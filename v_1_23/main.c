/*1.23. Определите длину наибольшего возрастающего участка после-
довательности.*/
#include <stdio.h>
#include <stdlib.h>

int LenghtIncrSeqComputer(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int lenghtIncrSeq = LenghtIncrSeqComputer(file);
    printf("lenghtIncrSeq = %i\n", lenghtIncrSeq);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}


int LenghtIncrSeqComputer(FILE *file)
{
    int lenghtIncrSeq = 1;
    int lenghtIncrSeqMax = 1;
    int scanVal = 0;
    int newScanVal = 0;

    fscanf(file,"%i", &scanVal);
    while(1 == fscanf(file, "%i", &newScanVal))
    {
        if(newScanVal > scanVal)
        {
            lenghtIncrSeq++;
            if(lenghtIncrSeq > lenghtIncrSeqMax)
                lenghtIncrSeqMax = lenghtIncrSeq;
        }
        else
            lenghtIncrSeq = 1;

        scanVal = newScanVal;
    }
    return lenghtIncrSeqMax;
}
