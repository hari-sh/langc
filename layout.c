#include <stdio.h>
#include <stdlib.h>

int gvar = 66;
const int cgvar = 1010;
int ugvar;

void foo() {
    int lvar = 1;
    printf("Address of lvar:\t%p", (void*)&lvar);
}

int main() {
    
    int *hvar = (int*)malloc(sizeof(int));
    printf("Address of foo:\t\t%p\n", (void*)&foo);
    printf("Address of cgvar:\t%p\n", (void*)&cgvar);
    printf("Address of gvar:\t%p\n", (void*)&gvar);
    printf("Address of ugvar:\t%p\n", (void*)&ugvar);
    printf("Address of hvar:\t%p\n", (void*)hvar);
    foo();
    
    return 0;
}
