#include<stdio.h>
int main(){
    int x=5;
    int *p = &x;
    printf("%d\n",x);
    printf("%p\n",p);
    printf("%d\n",*p);
    printf("%p\n",&x);
    printf("%p\n",&p);
}