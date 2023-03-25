/*1.26. Назовем локальным строгим экстремумом такой элемент x i по-
следовательности, для которого выполнено x i−1 < x i > x i+1 либо x i−1 >
x i < x i+1 , i > 0. Определите и напечатайте локальные экстремумы с со-
седними точками. Каждая тройка печатается с новой строки.*/
#include <stdio.h>
#include <stdlib.h>

int DistanceComputer(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    DistanceComputer(file);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int DistanceComputer(FILE *file)
{
    int localMaxDistance = 0;
    int localMaxDistanceMax = 0;
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;

    int flagStart = 0;

    if(1 != fscanf(file, "%i", &x1))
        return -1;
    if(1 != fscanf(file, "%i", &x2))
        return -1;

    while(1 == fscanf(file, "%i", &x3))
    {
        if(((x1 < x2) && (x2 > x3)) ||
           ((x1 > x2) && (x2 < x3)) )
        {
            localMaxDistance = 0;
            flagStart = 1;
            printf("%i \t %i \t %i \n", x1, x2, x3);
        }
        else
        {
            if(flagStart)
                localMaxDistance++;
        }

        if(localMaxDistanceMax < localMaxDistance)
            localMaxDistanceMax = localMaxDistance;


        x1 = x2;
        x2 = x3;
    }
    return localMaxDistanceMax;
}
