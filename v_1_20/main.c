/*Определите длину наибольшего постоянного участка, т.е. мак-
симальное количество подряд идущих элементов в одним и тем же зна-
чением.*/
#include <stdio.h>
#include <stdlib.h>

int  LenghtEqualSeqComputer(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int lenghtEqualSeq = LenghtEqualSeqComputer(file);
    printf("lenghtEqualSeq = %i\n", lenghtEqualSeq);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int  LenghtEqualSeqComputer(FILE *file)
{
    int scanVal = 0;
    int newScanVal = 0;

    int lenght = 1;
    int lenghtMax = 0;

    fscanf(file,"%i", &scanVal);
    while(1 == fscanf(file, "%i", &newScanVal))
    {
        if(scanVal == newScanVal)
        {
            lenght++;
            if(lenght > lenghtMax)
                lenghtMax = lenght;
        }
        else
        {
            lenght = 1;
        }
        scanVal = newScanVal;
    }
    return lenghtMax;
}
