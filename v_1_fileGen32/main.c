#include <stdio.h>
#include <stdlib.h>

#define NUM_MEMB    32

int main()
{
    int *arrX = (int*)malloc(sizeof(int) * NUM_MEMB);

    for(int i = 0; i < NUM_MEMB; i++)
    {
        arrX[i] = rand()%10;
        printf("%i ", arrX[i]);
    }

    FILE *file = fopen("fileGen32.txt", "w");

    for(int i = 0; i < NUM_MEMB; i++)
        fprintf(file,"%d\n", arrX[i]);

    fclose(file);

    printf("Hello World!\n");
    return 0;
}
