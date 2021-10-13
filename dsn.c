#include <stdio.h>

int sum_mul(unsigned char *, unsigned char *);

int main(void)
{
    unsigned char array[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char array1[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum=0;    
    sum=sum_mul(array, array1);
    printf("%d\n", sum);
    return 0;
}
int sum_mul(unsigned char *array, unsigned char *array1)
{
    int sum=0;
    __asm__
    (
        "movl $10, %%ecx\n\t" 
        "m1:\n\t" 
        "movb (%%rsi), %%al\n\t" 
        "movb (%%rdi), %%bl\n\t"
        "mulb %%bl\n\t" 
        "addw %%ax, %%dx\n\t" 
        "xorw %%ax, %%ax\n\t" 
        "xorw %%bx, %%bx\n\t"
        "addq $1, %%rsi\n\t"
        "addq $1, %%rdi\n\t"
        "loop m1\n\t"
        :"=d"(sum)
        :"S"(array), "D"(array1), "d"(sum)
        :"memory"
    );
    return sum;
}
