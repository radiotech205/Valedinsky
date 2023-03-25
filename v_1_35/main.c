/*1.35. Напишите функцию-фильтр, копирующую содержимое одного
файла в другой файл, за исключением символов, содержащихся в задан-
ной текстовой строке.*/
#include <stdio.h>
#include <string.h>

void CopyFilter(FILE *fin, FILE *fout, char *badsym);
int CharacterFounder(int ch, char *badSym, int badSymCnt);

int main()
{
    FILE *fileIn = fopen("../fileGen32.txt", "r");
    if(fileIn == NULL)
    { printf("Error of fileIn\n"); return -1;}

    FILE *fileOut = fopen("../fileName.txt", "w");
    if(fileOut == NULL)
    { printf("Error of fileOut\n"); return -1;}

    char badsym[] = {'/', '*', '-', '+', ' '};
    CopyFilter(fileIn, fileOut, badsym);

    fclose(fileIn);
    fclose(fileOut);
    printf("Hello World!\n");
    return 0;
}

void CopyFilter(FILE *fin, FILE *fout, char *badsym)
{
    int badSymCnt = strlen(badsym);
    int c = 0;


    while((c = getc(fin)) != EOF)
    {
        if(0 == CharacterFounder(c, badsym, badSymCnt))
        {
            putc(c, fout);
        }
    }
}

int CharacterFounder(int ch, char *badSym, int badSymCnt)
{
    int result = 0;
    for(int i = 0; i < badSymCnt; i++)
        if(ch == badSym[i])
            result = 1;

    return result;
}
