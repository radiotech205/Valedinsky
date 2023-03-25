/*1.33. Напишите функцию, получающую в качестве параметра имя
текстового файла и подсчитывающую количество латинских букв в фай-
ле*/
#include <stdio.h>
#include <string.h>

int LatSignComputer(FILE *file);

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

    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    { printf("Error of file\n"); return -1;}

    int numLatSign = LatSignComputer(file);
    printf("numLatSign = %i\n", numLatSign);

    fclose(file);
    printf("Hello World!\n");
    return 0;
}

int LatSignComputer(FILE *file)
{
    int c = 0;
    int cnt = 0;

    while((c = getc(file)) != EOF)

    {
        if(((c >= 65) && (c <= 90)) ||
           ((c >= 97) && (c <= 122)))
            cnt++;
    }
    return cnt;
}
