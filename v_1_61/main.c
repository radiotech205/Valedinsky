#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int mValue = (argc >= 2) ? atoi(argv[1]) : 1;
    int nValue = (argc >= 3) ? atoi(argv[2]) : 1;

    int result01 = mValue / nValue;
    int result02 = (mValue % nValue);

    int result03 = 100 * result02/nValue;

    printf("%i,%02i\n",  result01,  result03);

    printf("Hello World!\n");
    return 0;
}
