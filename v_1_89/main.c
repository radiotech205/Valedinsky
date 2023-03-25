#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_ELEMENTS    1024
/*1.89. По заданному текстовому файлу сформируйте файл-словарь,
содержащий все слова из исходного файла, записанные в алфавитном
порядке по одному в строке.*/
int IsDelimiter(char ch, const char *arrDelim);
int GetWord (FILE *f, char *word, uint32_t *wordSize, const char *delim, uint32_t *dotFlag, uint32_t *upperFlag);
int AddAlpha(FILE *f, char *ch, const char *delim, char *word, uint32_t *wordSize, uint32_t *dotFlag);
int AddToDictionary(char *word, char (*arrDict)[MAX_ELEMENTS], uint32_t *arrDictSize);
int CompChar(const void *e1, const void *e2);

int main(int argc, char *argv[])
{
    char *fileName = NULL;
    if(argc > 1)
    {
        fileName = (char*)malloc(strlen(argv[1]));
        strcpy(fileName, argv[1]);
    }
    else if(argc == 1)
    {
        printf("argc = %i, error, exit\n", argc);
        return -1;
    }
    const char arrDelimiters[] = ".,;:!? ()[]-+*/";

    char *word = (char*)malloc(MAX_ELEMENTS);
    uint32_t wordSize = 0;

    uint32_t dotFlag = 0;
    uint32_t upperFlag = 0;

//    char **arrDict = (char **)malloc(sizeof(char*) * MAX_ELEMENTS);
//    for(uint32_t i = 0; i < MAX_ELEMENTS; i++)
//        arrDict[i] = (char*)malloc(sizeof(char) * MAX_ELEMENTS);

    char arrDict[MAX_ELEMENTS][MAX_ELEMENTS];

    uint32_t arrDictSize = 0;

    FILE *file = fopen(fileName, "r");
    while(!feof(file))
    {
        if(GetWord(file, word, &wordSize, arrDelimiters, &dotFlag, &upperFlag) == 0)
        {
            printf("%s_\n", word);
            AddToDictionary(word, arrDict, &arrDictSize);
        }
    }
    printf("\n");
    fclose(file);

    printf("-------------------------\n");
    for(uint32_t i = 0; i < arrDictSize; i++)
        printf("%s, %li\n", arrDict[i], strlen(arrDict[i]));



    free(word);
//    for(uint32_t i = 0; i < MAX_ELEMENTS; i++)
//        if(arrDict[i] != NULL)
//            free(arrDict[i]);
    //free(arrDict);
    printf("Hello World!\n");
    return 0;
}

int IsDelimiter(char ch, const char *arrDelim)
{
    int result = 1;
    for(uint i = 0; i < strlen(arrDelim); i++)
    {
        if(ch == arrDelim[i])
        {
            result = 0;
            break;
        }
    }
    return result;
}

int GetWord(FILE *f, char *word, uint32_t *wordSize, const char *delim, uint32_t *dotFlag, uint32_t *upperFlag)
{
    int result = 0;
    *wordSize = 0;

    char ch = fgetc(f);
    char chNext;
    if(isupper(ch))
        *upperFlag = 1;

    AddAlpha(f, &ch, delim, word, wordSize, dotFlag);
    if(ch == '-')
    {
        chNext = fgetc(f);
        if(isalnum(chNext))
        {
            word[*wordSize] = ch;
            (*wordSize)++;
            AddAlpha(f, &chNext, delim, word, wordSize, dotFlag);
        }
        else if(chNext == '\n')
        {
            while(ch == '\n')
            {
               ch = fgetc(f);
               if(feof(f))
                   break;
            }
            ch = fgetc(f);
            AddAlpha(f, &ch, delim, word, wordSize, dotFlag);

            if(chNext == ' ')
            {
                while(ch == ' ')
                {
                   ch = fgetc(f);
                   if(feof(f))
                       break;
                }
                ch = fgetc(f);
                AddAlpha(f, &ch, delim, word, wordSize, dotFlag);
            }
        }
        else if(chNext == ' ')
        {
            while(ch == ' ')
            {
               ch = fgetc(f);
               if(feof(f))
                   break;
            }
            ch = fgetc(f);
            AddAlpha(f, &ch, delim, word, wordSize, dotFlag);
        }
    }
    if(*wordSize > 0)
        word[*wordSize] = '\0';
    else
        result = 1;

    if(feof(f))
        result = -1;

    return result;
}

int AddAlpha(FILE *f, char *ch, const char *delim, char *word, uint32_t *wordSize, uint32_t *dotFlag)
{
    int result = 0;
    while(IsDelimiter(*ch, delim) == 1)
    {
        word[*wordSize] = *ch;
        (*wordSize)++;
        *ch = fgetc(f);

        if(feof(f))
        {
            result = 1;
            break;
        }
    }
    if(*ch == '.' || *ch == '!' || *ch == '?')
        *dotFlag = 1;
    return result;
}

int AddToDictionary(char *word, char (*arrDict)[MAX_ELEMENTS], uint32_t *arrDictSize)
{
    int result = 1;

    uint32_t index = 0;
    for(index = 0; index < *arrDictSize; index++)
    {
        if(!strcmp(arrDict[index], word))
        {
            result = 1;
            break;
        }
        else
        {
            result = 0;
        }
    }

    if((!result) || (*arrDictSize == 0))
    {
        strcpy(arrDict[*arrDictSize], word);
        (*arrDictSize)++;

        qsort(&arrDict[0][0], (*arrDictSize), MAX_ELEMENTS, CompChar);


//        printf("-------------------------------\n");

//        for(uint i = 0; i < *arrDictSize; i++)
//            printf("%s\n", arrDict[i]);
    }


    return result;
}

int CompChar(const void *e1, const void *e2)
{
//    const char *pe1 = *(const char**)e1;
//    const char *pe2 = *(const char**)e2;

    printf("%s: %s, %s\n", __FUNCTION__, (char*)e1, (char*)e2);
    return strncmp(e1, e2, 1);
}
