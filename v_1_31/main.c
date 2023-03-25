/*1.31. Введите с клавиатуры символ и определите сколько раз он
встречается в текстовом файле.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharacterCounter(FILE *file, int chr);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    char chr[10];
    strcpy(chr,argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int chrCnt = CharacterCounter(file, chr[0]);
    printf("%c: %i\n", chr[0], chrCnt);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int CharacterCounter(FILE *file, int chr)
{
    int scanChar = 0;
    int chrCnt = 0;

    while(!feof(file))
    {
        scanChar = fgetc(file);
        if(scanChar == chr)
            chrCnt++;
    }
    return chrCnt;
}
