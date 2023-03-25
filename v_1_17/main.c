/*1.17. Пусть последовательность является неубывающей. Определите
количество элементов, которые появляются в этой последовательности
более k раз, ( значение k вводится с клавиатуры).*/
#include <stdio.h>
#include <stdlib.h>

int CountFounder(FILE *file, int k);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    int k = atoi(argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int meetCnt = CountFounder(file, k);
    printf("meetCnt = %i\n", meetCnt);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int CountFounder(FILE *file, int k)
{
   int meetCnt = 0;
   int scanValue = 0;
   while(1 == fscanf(file, "%i", &scanValue))
   {
       if(k == scanValue)
           meetCnt++;
   }
   return meetCnt;
}
