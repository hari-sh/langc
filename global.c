#include<stdio.h>
void printArr(int* arr, int len) {
    for(int i=0; i<len; i++)    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int c[4];
int main() {
    static int a[4];
    int b[4];
    printf("static Variable: \n");
    printArr(a,4);
    printf("local variable: \n");
    printArr(b,4);
    printf("global variable: \n");
    printArr(c, 4);
    return 0;
}