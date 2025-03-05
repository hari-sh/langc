#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id; 

    union {       
        float hourlyRate;
        float salary;    
    } payment;
};

int main() {
    struct Employee e1;
    strcpy(e1.name, "Rana");
    e1.id = 101;
    e1.payment.hourlyRate = 300;

    printf("Employee 1: %s (ID: %d)\n", e1.name, e1.id);
    printf("Hourly Rate: Rs %.2f", e1.payment.hourlyRate);

    return 0;
}
