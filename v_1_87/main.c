#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
/*1.87. В файле, содержащем литературный текст, возможны переносы
слов между строками. Модифицируйте функцию GetWord из предыду-
щей задачи так, чтобы она обнаруживала и правильно выводила перене-
сенные слова.
Идеи реализации. Можно считать, что слово разбито переносом на
две части, если за допустимыми (буквенными) символами идет символ
“-”, за которым следуют один или несколько символов перевода стро-
ки, и далее, возможно, несколько пробелов до следующего допустимого
символа.*/
int IsDelimiter(char ch, const char *arrDelim);
int GetWord (FILE *f, char *word, const char *delim);
int AddAlpha(FILE *f, char *ch, const char *delim, char *word, uint32_t *wordSize);


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

    FILE *file = fopen(fileName, "r");

    while(GetWord(file, word,  arrDelimiters) == 0)
    {
        printf("%s ", word);
    }

    fclose(file);

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

int GetWord(FILE *f, char *word, const char *delim)
{
    int result = 0;
    uint32_t wordSize = 0;

    char ch = fgetc(f);
    AddAlpha(f, &ch, delim, word, &wordSize);
    if(ch == '-')
    {
        ch = fgetc(f);
        if(isalnum(ch))
        {
            AddAlpha(f, &ch, delim, word, &wordSize);
        }
        if(ch == '\n')
        {
            while(ch == '\n')
            {
               ch = fgetc(f);
               if(feof(f))
                   break;
            }
            AddAlpha(f, &ch, delim, word, &wordSize);
        }
        if(ch == ' ')
        {
            while(ch == ' ')
            {
               ch = fgetc(f);
               if(feof(f))
                   break;
            }
            AddAlpha(f, &ch, delim, word, &wordSize);
        }
    }


    word[wordSize] = '\0';

    if(feof(f))
        result = -1;

    return result;
}

int AddAlpha(FILE *f, char *ch, const char *delim, char *word, uint32_t *wordSize)
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
    return result;
}
