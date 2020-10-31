#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

char** genStr(int*);
void fill(char**, int);
void StrMod(char**, int);
void printStr(char**, int);
void search(char**, int);
void numStr(int*, int);


int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    char** str = genStr(&n);
    fill(str, n);
    StrMod(str, n);
    printStr(str, n);
    search(str, n);
    getchar();
    return 0;
}

char** genStr(int* n)
{
    char** str = NULL;
    int i;
    printf("Введите кол-во строк: ");
    scanf_s("%d", n);
    printf("\n");

    str = (char**)calloc(*n, sizeof(char*));
    for (i = 0; i < *n; i++)
    {
        str[i] = (char*)calloc(22, sizeof(char));
    }

    return str;
}

void fill(char** str, int n)
{
    int i;

    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Введите строку номер %d (до 20ти символов): ", i + 1);
        fgets(str[i], 22, stdin);
    }
    printf("\n");
}

void StrMod(char** str, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 22; j++)
        {
            if (str[i][j] == '\n')
            {
                str[i][j] = '\0';
            }
        }
    }
}

void printStr(char** str, int n)
{
    int i;
    printf("Ваши строки:\n");
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    printf("\n");
}

void search(char** str, int n)
{
    int i, j;
    void (*define)(int*, int);

    int* resultStr = (int*)calloc(n, sizeof(int));
    int counter = 0;
    int maxElement = 0;
    for (i = 0; i < n; i++)
    {
        counter = 0;
        for (j = 0; j < 22; j++)
        {
            if (str[i][j] != '\0')
            {
                if (str[i][j] == ' ')
                {
                    counter = 0;
                    continue;
                }
                counter++;
            }
            if (counter > resultStr[i])
            {
                resultStr[i] = counter;
            }
            if (str[i][j] == '\0')
            {
                break;
            }
        }
    }


    numStr(resultStr, n);
}