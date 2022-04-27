#include <stdio.h>

void f(char* p, int x){
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
    printf("Hello, World!\n");

    char* h = "Hello";
    char* w = "World!";
    printf("%s %s\n", h, w);

    f("foo",7);
    
    return 0;
}