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