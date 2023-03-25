/*Определите все ли элементы последовательности равны между
собой*/
#include <stdio.h>
#include <stdlib.h>

int AllElementsAreEqual(FILE *file);

int main()
{
    FILE *fileGen32 = fopen("../fileGen32.txt", "r");
    if(fileGen32 == NULL)
    {
        printf("Error of opening file!\n");
        return -1;
    }

    int result = AllElementsAreEqual(fileGen32);
    printf("result = %i\n", result);

    fclose(fileGen32);
    printf("Hello World!\n");
    return 0;
}

int AllElementsAreEqual(FILE *file)
{
    int value = 0;
    int newValue = 0;
    int result = 0;

    fscanf(file,"%i", &value);

    while(1 == fscanf(file, "%i", &newValue))
    {
        if(value != newValue)
        {
            result = -1;
        }
        value = newValue;
    }

    if(result != -1)
        result = 0;

    return result;
}
