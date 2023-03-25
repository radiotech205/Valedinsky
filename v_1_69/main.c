#include <stdio.h>
#include <stdlib.h>

int Alu(int oper0, char operat, int oper1);
int SeqComputer(char arrOperators[5],
                int aValue, int bValue, int cValue, int dValue, int eValue, int fValue);

int main(int argc, char *argv[])
{
    int aValue = (argc >= 2) ? atoi(argv[1]) : 1;
    int bValue = (argc >= 3) ? atoi(argv[2]) : 1;
    int cValue = (argc >= 4) ? atoi(argv[3]) : 1;
    int dValue = (argc >= 5) ? atoi(argv[4]) : 1;
    int eValue = (argc >= 6) ? atoi(argv[5]) : 1;
    int fValue = (argc >= 7) ? atoi(argv[6]) : 1;

    char arrOperators[] = {'+', '*', '-', '/', '^'};

    SeqComputer(arrOperators, aValue,  bValue,  cValue,  dValue,  eValue,  fValue);



    printf("Hello World!\n");
    return 0;
}

int SeqComputer(char arrOperators[5],
                int aValue, int bValue, int cValue, int dValue, int eValue, int fValue)
{
    int result = 0;

    for(int op0 = 0; op0 < 5; op0++)
    {
        for(int op1 = 0; op1 < 5; op1++)
        {
            for(int op2 = 0; op2 < 5; op2++)
            {
                for(int op3 = 0; op3 < 5; op3++)
                {
                    for(int op4 = 0; op4 < 5; op4++)
                    {
                        int cond0 = ((op0 != op1) && (op0 != op2) && (op0 != op3) && (op0 != op4));
                        int cond1 = ((op1 != op0) && (op1 != op2) && (op1 != op3) && (op1 != op4));
                        int cond2 = ((op2 != op0) && (op2 != op1) && (op2 != op3) && (op2 != op4));
                        int cond3 = ((op3 != op0) && (op3 != op1) && (op3 != op2) && (op3 != op4));
                        int cond4 = ((op4 != op0) && (op4 != op1) && (op4 != op2) && (op4 != op3));
                        if(cond0 && cond1 && cond2 && cond3 && cond4)
                        {
                            result = Alu(aValue, arrOperators[op0], bValue);
                            result = Alu(result, arrOperators[op1], cValue);
                            result = Alu(result, arrOperators[op2], dValue);
                            result = Alu(result, arrOperators[op3], eValue);
                            result = Alu(result, arrOperators[op4], fValue);
                            printf("%i %c %i %c %i %c %i %c %i %c %i = %i\n",
                                   aValue, arrOperators[op0],
                                   bValue, arrOperators[op1],
                                   cValue, arrOperators[op2],
                                   dValue, arrOperators[op3],
                                   eValue, arrOperators[op4],
                                   fValue, result);
                        }
                    }
                }
            }

        }
    }
    return result;
}

int Alu(int oper0, char operat, int oper1)
{
    int result = 0;
    switch(operat)
    {
    case '+':
        result = oper0 + oper1;
        break;

    case '*':
        result = oper0 * oper1;
        break;

    case '-':
        result = oper0 - oper1;
        break;

    case '/':
        result = oper0 / oper1;
        break;

    case '^':
        result = 1;
        for(int i = 1; i <= oper1; i++)
            result *= oper0;
        break;
    default:
        result = -1;
        printf("%s\n", __FUNCTION__);
        break;
    }
    return result;
}
