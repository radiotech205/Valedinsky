/*Введите с клавиатуры число x и определите порядковый номер
последнего числа, равного x*/
#include <stdio.h>
#include <stdlib.h>

int LastNumberComputer(FILE *fileGen32, int x);

int main(int argc, char **argv)
{
    const int numArgc = 2;
    if(argc != numArgc)
    {
        printf("Error! argc = %i, must be %i\n", argc, numArgc);
        return -1;
    }

    int x = atoi(argv[1]);

    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int nuber = LastNumberComputer(fileGen32, x);
    printf("nuber = %i\n", nuber);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int LastNumberComputer(FILE *fileGen32, int x)
{
    int lastNumber = -1;
    int scanValue = 0;
    int cnt = 0;
    while(1 == fscanf(fileGen32, "%i", &scanValue))
    {

        if(scanValue == x)
            lastNumber = cnt;

        cnt++;
    }
    return lastNumber;
}
