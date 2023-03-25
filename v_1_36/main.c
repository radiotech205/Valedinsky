/*1.36. Напишите функцию-фильтр, которая при каждом обращении
возвращает очередной допустимый символ из заданного тестового файла.
При достижении конца файла функция возвращает значение EOF. Набор
допустимых символов задается строкой — параметром функции*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Filter(FILE *fileIn, char *goodSym);

int main()
{
    FILE *fileIn = fopen("../fileGen32.txt", "r");
    if(fileIn == NULL)
    { printf("Error of fileIn\n"); return -1;}

    char goodSym[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    int ch = 0;
    while((ch = Filter(fileIn, goodSym)) != EOF)
        printf("%c", ch);

    fclose(fileIn);
    printf("Hello World!\n");
    return 0;
}

int Filter(FILE *fileIn, char *goodSym)
{
    static int arrGood[256];
    for(int i = 0; i < 256; i++) arrGood[i] = 0;
    int ch;
    for(uint i = 0; i < strlen(goodSym); i++)
    {
        ch = goodSym[i];
        arrGood[ch] = 1;
    }

    while( (ch = fgetc(fileIn)) != EOF && !arrGood[ch]);

    return ch;
}
