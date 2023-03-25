/*Введите с клавиатуры строку символов и для каждого ее эле-
мента определите сколько раз он встречается в текстовом файле.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharacterCounter(FILE *file, char *chr, int *chrMeet);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }
    char chr[256];
    strcpy(chr,argv[1]);

    FILE *file = fopen("../fileGen32.txt", "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}
    int *chrMeet = (int*)malloc(sizeof(int)*256);

    int numChar = CharacterCounter(file, chr, chrMeet);
    //printf("%c: %i\n", chr[0], chrCnt);
    for(int i = 0; i < numChar; i++)
    {
        printf("%c \t %i\n", chr[i], chrMeet[i]);
    }

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int CharacterCounter(FILE *file, char *chr, int *chrMeet)
{
    int i;
    int c;
    int buf[256];
    for(i = 0; i < 256; i++)
        buf[i] = 0;

    while((c = getc(file)) != EOF)
        buf[c]++;

    for(i = 0; chr[i]; i++)
        chrMeet[i] = buf[chr[i]];

    return i;
}
