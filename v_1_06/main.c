/*Введите с клавиатуры число x и определите, сколько раз оно
встречается в последовательности.*/
#include <stdio.h>
#include <stdlib.h>

int MeetingComputer(FILE *fileGen32, int x);

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

    int result = MeetingComputer(fileGen32, x);
    printf("result = %i\n", result);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int MeetingComputer(FILE *fileGen32, int x)
{
    int meetCnt = 0;
    int scanValue = 0;
    while(fscanf(fileGen32,"%i", &scanValue) == 1)
    {
        if(scanValue == x)
            meetCnt++;
    }

    return meetCnt;
}
