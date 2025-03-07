#include <stdio.h>
extern int animals; 
extern void printAnimal();
int main() {
    animals = 7;
    printf("%d", animals);
    printAnimal();
    return 0;
}
