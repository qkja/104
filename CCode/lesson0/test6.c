#include<stdio.h>
struct S
{
    char a: 3;
    char b: 4;
    char c: 5;
    char d: 4;
    
};
int main()
{
    printf("%d\n", sizeof(struct S));
    return 0;
}
