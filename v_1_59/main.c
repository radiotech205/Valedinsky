#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ConvertCC(char* x,int fromCC,int toCC);

int main(int argc, char *argv[])
{
    int fromCC = (argc >= 3) ? atoi(argv[2]) : 0;
    int toCC = (argc >= 4) ? atoi(argv[3]) : 0;

    char *number = ConvertCC(argv[1], fromCC, toCC);



    printf("x = %s, fromCC = %i, toCC = %i, number = %s\n",
           argv[1], fromCC, toCC, number);

    printf("Hello World!\n");
    return 0;
}


//Функция возвращающая переведенное число
char* ConvertCC(char* x,int fromCC,int toCC)
{
//    for(int j = 0; j < strlen(x); j++)
//        printf("%i - %i - %c\n", j, x[j], x[j]);

    //Таблица символов исходного числа для
    //определения их порядкового номера
    char *abc = strdup("0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ");
    //Промежуточная строка
    char buf[255]={0};
    //Результирующая строка
    char *result;

    int i //Это количество символов в начальном числе
       ,k //Это будет порядковым номером очередного символа в входном числе
       ,ten=0 //Это будет его аналог в 10-чной системе
       ,stp=1; //А это просто степень для перевода в 10-чную
    //Узнаем сколько символов во входящем числе
    for(i=0;x[i];i++);
    //А потом с последнего символа начинаем переводить
    for(;i;i--)
    {
        //Выясняем его порядковый номер
        for(k = 0; abc[k] != x[i-1] && k < 36; k++);
        //Умножаем его на степень, прибавляя к результирующему числу
        // в 10-тиричной системе
        ten += k * stp;
        //И повышаем степень для следующего символа
        stp *= fromCC;
//        printf("ten = %i, k = %i\n", ten, k);
    }
    //После обратной формулой
    k = 0;
    while(ten)
    {
     //Получаем цифры числа в нужной системе
     i=ten % toCC;
     //И пишем их в буфер
     buf[k++] = abc[i];
     //Деля число на основание результирующей системы
     ten /= toCC;
    }

    //Поскольку число у нас в буффере верх ногами
    //Создаем результирующую переменку
    result = (char*)malloc(k+1);
    //В которую пишем результат в его естесственном виде
    for(i = 0; k; i++)
        result[i] = buf[--k];
    //Маркеруем конец строки нулем
    result[i] = 0;
    //И возвращаем
    return result;

}
