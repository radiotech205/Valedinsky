#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*1.86. Назовем словом группу символов, не содержащую внутри себя
символов из заданного набора символов-разделителей. Примерами разде-
лителей для слов обычного литературного текста могут служить символы
“.,;:!? ()[]-+* /"” и т.п. Реализуйте функцию, которая при каждом
обращении к ней выделяет из указанного текстового файла очередное
слово. Функция должна иметь прототип
int GetWord (FILE *f, char *word, char *delim);
где f — указатель на входной файл, word — указатель на буфер для оче-
редного слова, delim — указатель на сроку с символами-разделителями.
Возвращаемое значение — 0, если слово прочитано, и -1 в случае конца
файла или какого-либо другого отказа.*/

int IsDelimiter(char ch, const char *arrDelim);

int GetWord (FILE *f, char *word, const char *delim);

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
    FILE *file = fopen(fileName, "r");
    char ch = fgetc(file);
    while(!feof(file))
    {
        if(IsDelimiter(ch, arrDelimiters) == 1)
        {
            word[wordSize] = ch;
            wordSize++;
        }
        else
        {
            word[wordSize] = ch;
            wordSize++;

            word[wordSize] = '\0';
            wordSize = 0;
            printf("%s", word);
        }
        ch = fgetc(file);
    }
    printf("\n");
    fclose(file);

    printf("fileName: %s\n", fileName);
    /********************************/
    file = fopen(fileName, "r");

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
    while(IsDelimiter(ch, delim) == 1)
    {
        word[wordSize] = ch;
        wordSize++;
        ch = fgetc(f);

        if(feof(f))
            break;
    }
    word[wordSize] = '\0';

    if(feof(f))
        result = -1;

    return result;
}
