#include<stdio.h>
struct code
{
    int i;
    char c;
    struct code *ptr;
};

int main()
{
    struct code var1;
    struct code var2;
    struct code var3;

    var1.i=65;
    var1.c='A';
    var1.ptr=NULL;

    var2.i=66;
    var2.c='B';
    var2.ptr=NULL;

    var3.i=67;
    var3.c='C';
    var3.ptr=NULL;

    var1.ptr=&var2;
    var2.ptr=&var3;

    printf("%d %c\n", var1.ptr->i, var1.ptr->c);
    printf("%d %c\n", var2.ptr->i, var2.ptr->c);
}
