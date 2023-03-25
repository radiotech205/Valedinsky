#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
/*
1.88. С использованием функции GetWord из предыдущей задачи
выполните следующую обработку текстового файла:
+1) подсчитайте количество слов в исходном файле;
+2) подсчитайте максимальную, минимальную и среднюю длину слов;
+3) подсчитайте среднее количество слов в одном предложении (пред-
ложение — это последовательность слов, оканчивающаяся одним из сим-
волов “.!?”);
+4) выберите и напечатайте все слова, начинающиеся с заглавной бук-
вы.
*/

int IsDelimiter(char ch, const char *arrDelim);
int GetWord (FILE *f, char *word, uint32_t *wordSize, const char *delim, uint32_t *dotFlag, uint32_t *upperFlag);
int AddAlpha(FILE *f, char *ch, const char *delim, char *word, uint32_t *wordSize, uint32_t *dotFlag);

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

    char *word = (char*)malloc(1024);
    uint32_t wordSize = 0;
    uint32_t wordCnt = 0;

    uint32_t wordSizeMin = strlen(arrDelimiters);
    uint32_t wordSizeMax = 0;

    uint32_t dotFlag = 0;
    uint32_t wordDotCnt = 0;
    uint32_t *arrClause = (uint32_t*)malloc(sizeof(uint32_t) * 1024*1024);
    uint32_t arrClauseCnt = 0;
    double wordAVG = 0.0;

    uint32_t upperFlag = 0;

    FILE *file = fopen(fileName, "r");

    while(!feof(file))
    {
        if(GetWord(file, word, &wordSize, arrDelimiters, &dotFlag, &upperFlag) == 0)
        {
            if(wordSize > wordSizeMax)
                wordSizeMax = wordSize;
            if(wordSize < wordSizeMin)
                wordSizeMin = wordSize;

            wordCnt++;
            wordSize = 0;
            printf("%s_\n", word);

            if(dotFlag == 0)
                wordDotCnt++;
            else
            {
                dotFlag = 0;
                printf("wordDotCnt = %i\n", wordDotCnt);
                arrClause[arrClauseCnt] = wordDotCnt;
                wordDotCnt = 0;
                arrClauseCnt++;
            }

            if(upperFlag)
            {
                upperFlag = 0;
                printf("\t\t\t %s\n", word);
            }
        }
    }
    printf("\n");
    fclose(file);


    printf("wordCnt = %i\n", wordCnt);
    printf("wordSizeMax = %i\n", wordSizeMax);
    printf("wordSizeMin = %i\n", wordSizeMin);

    {
        uint32_t sum = 0;
    for(uint32_t i = 0; i < arrClauseCnt; i++)
    {
        sum += arrClause[i];
    }
    wordAVG = (double)sum/(double)arrClauseCnt;
    }
    printf("wordAVG = %lf\n", wordAVG);

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
