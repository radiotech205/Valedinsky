#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB 32

int main()
{
    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);
    for(int i = 0; i < NUM_MEMB; i++)
    {
        arrX[i] = rand()%10;
    }

    FILE *fileGen32 = fopen("fileGen32.txt", "w");
    for(int i = 0; i < NUM_MEMB; i++)
    {
        fprintf(fileGen32, "%i\n",arrX[i]);
    }
    fclose(fileGen32);

    printf("Hello World!\n");
    return 0;
}
