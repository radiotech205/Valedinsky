/*Определите и напечатайте все отрезки возрастания последова-
тельности. Каждый участок печатается с новой строки.*/
#include <stdio.h>
#include <stdlib.h>

void IncreaserPrinter(FILE *file);

int main()
{
    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    IncreaserPrinter(file);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

void IncreaserPrinter(FILE *file)
{
    int x1 = 0;
    int x2 = 0;

    int ena = 0;

    if(1 != fscanf(file, "%i", &x1))
        return;

    while(1 == fscanf(file, "%i", &x2))
    {
        if(x1 < x2)
        {
            printf("%i ", x1);
            ena = 1;
        }
        else if(ena)
        {
            printf("%i \n", x1);
            ena = 0;
        }
        x1 = x2;
    }
}
