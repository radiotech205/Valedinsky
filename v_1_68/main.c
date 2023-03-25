#include <stdio.h>
#include <stdlib.h>
void WordWriter(int aValue, char *stringName);


int main(int argc, char *argv[])
{
    int aValue = (argc >= 2) ? atoi(argv[1]) : 1;

    char *stringName = (char*)malloc(15 << 1);

    WordWriter(aValue, stringName);

    printf("%s\n", stringName);
    free(stringName);

    printf("Hello World!\n");
    return 0;
}

void WordWriter(int aValue, char *stringName)
{
    int tenOrder = 1;
    int mullFactor = 10;
    for(; aValue/mullFactor; tenOrder++, mullFactor *= 10) ;


    char *arrOnes[] = {" ", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    char *arrTeen[] = {"ten", "eleven", "twelve", "thirteen",
                      "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen"};
    char *arrTens[] = {" ", "ten", "twenty", "thirty", "fourty",
                      "fifty", "sixty", "seventy", "eighty", "ninety"};


    int *arr = (int*)malloc(sizeof(int) * (tenOrder + 1));
    int value = 0;
    mullFactor = 1;
    for(int i = 0; i < tenOrder; i++)
    {
        value = (aValue / (mullFactor))%10;
        mullFactor *= 10;
        arr[i] = value;
    }

    sprintf(stringName, "aValue = %i:\n", aValue);
    for(int i = 0; i < tenOrder; i++)
    {
        int index = tenOrder-1 - i;

        switch (index)
        {
        case 0:
            sprintf(stringName,"%s %s ", stringName, arrOnes[arr[index]]);
            break;

        case 1:
        {
            if(arr[index] < 2)
                sprintf(stringName, "%s %s ", stringName, arrTeen[arr[index]]);
            else
                sprintf(stringName, "%s %s ", stringName, arrTens[arr[index]]);
        }
            break;

        case 2:
            sprintf(stringName, "%s %s hundreds ", stringName, arrOnes[arr[index]]);
            break;

        default:
            break;
        }
    }
    sprintf(stringName, "%s \n", stringName);
}
