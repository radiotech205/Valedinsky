/*Определите является ли последовательность возрастающей,
убывающей или ни той, ни другой*/
#include <stdio.h>
#include <stdlib.h>

int  SortOfSquensity(FILE *file);

int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int result = SortOfSquensity(fileGen32);
    printf("result = %i\n", result);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int  SortOfSquensity(FILE *file)
{
    int scanValue = 0;
    int scanNewValue = 0;

    int result = 0;

    int incMode = 0;
    int decMode = 0;


    fscanf(file, "%i", &scanValue);
    while(1 == fscanf(file, "%i", &scanNewValue))
    {
        if(scanValue < scanNewValue)
            incMode = 1;
        else if(scanValue > scanNewValue)
            decMode = 1;

        scanValue = scanNewValue;
    }

    if((1 == incMode) && (1 == decMode))
        result = 0;
    else if((1 == incMode) && (0 == decMode))
        result = 1;
    else if((0 == incMode) && (1 == decMode))
        result = -1;

    return result;
}
