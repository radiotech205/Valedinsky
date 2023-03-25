/*1.34. Напишите функцию, получающую в качестве параметра имя
текстового файла и копирующую его содержимое в другой файл с заме-
ной всех маленьких букв на большие*/
#include <stdio.h>
#include <string.h>

int ConverterToCapital(FILE *fileIn, FILE *fileOut);

int main(int argc, char* argv[])
{
    const int argNumber = 2;
    if(argc != argNumber)
    {
        printf("Error: argc = %i, must be %i.\n", argc, argNumber);
        return -1;
    }

    char fileName[256];
    strcpy(fileName, argv[1]);

    FILE *fileIn = fopen(fileName, "r");
    if(fileIn == NULL)
    { printf("Error of fileIn\n"); return -1;}

    FILE *fileOut = fopen("../fileName.txt", "w");
    if(fileOut == NULL)
    { printf("Error of fileOut\n"); return -1;}

    int num = ConverterToCapital(fileIn, fileOut);
    printf("num = %i\n", num);

    fclose(fileIn);
    fclose(fileOut);
    printf("Hello World!\n");
    return 0;
}

int ConverterToCapital(FILE *fileIn, FILE *fileOut)
{
    int c = 0;
    int cnt = 0;

    while((c = getc(fileIn)) != EOF)

    {
        if((c >= 97) && (c <= 122))
        {
            c -= 32;
        }
        putc(c, fileOut);

            cnt++;
    }
    return cnt;
}
