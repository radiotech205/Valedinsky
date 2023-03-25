#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int numMemb = argc > 1 ? atoi(argv[0]) : 1;

    double mult = 1.0;

    for(int k = 1; k < numMemb; k++)
        mult *= (4.0 * pow((double)i, 2.0));


    printf("Hello World!\n");
    return 0;
}
