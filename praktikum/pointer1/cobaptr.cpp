#include <stdio.h>

void cobaPointer() {
    // initialization
    int var = 10;

    // declare pointer variable
    int* ptr;

    // assign the address of a variable to a pointer
    // note that data type of ptr and var must be same
    ptr = &var;
    //	&var = ptr; compiler
    //	var = ptr; compiler
    //	*ptr = var;
    //	var = *ptr;

    // output
    printf("Value at ptr p = %p \n", ptr);
    printf("Value at ptr d = %d \n", ptr);
    printf("Value at var p = %p \n", var);
    printf("Value at *ptr p = %p \n", *ptr);
    printf("Value at var d = %d \n", var);
    printf("Value at *ptr d = %d \n", *ptr);
    //    printf("Value at *var p = %d \n", *var);
    //    printf("Value at *var p = %d \n", *var);
    printf("Value at *var d = %d \n", &var);
    printf("Value at *var p = %p \n", &var);
}

// Driver program
int main() {
    cobaPointer();
    return 0;
}