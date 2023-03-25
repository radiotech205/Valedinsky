#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    int numMemb = argc > 1 ? atoi(argv[1]) : 1;

    double mult = 1.0;
    for(int i = 2; i < numMemb; i++)
        mult *=(1 - (1/pow((double)i, 2.0)));

    printf("mult = %lf\n", mult);

    printf("Hello World!\n");
    return 0;
}
