/*
Two enum names can have same value.
If we do not explicitly assign values to enum names, the compiler by default assigns values starting from 0.
We can assign values to some name in any order. All unassigned names get value as value of previous name plus one. 
The value assigned to enum names must be some integral constant.
i.e., the value must be in range from minimum possible integer value to maximum possible integer value.
All enum constants must be unique in their scope

We can also use macros to define names constants

There are multiple advantages of using enum over macro when many related named constants have integral values. 
- Enums follow scope rules. 
- Enum variables are automatically assigned values. Following is simpler.
*/

#include <stdio.h>
enum day {sunday = 1, tuesday, wednesday, thursday, friday, saturday};

int main()
{
    enum day d = thursday;
    printf("The day number stored in d is %d", d);
    return 0;
}
