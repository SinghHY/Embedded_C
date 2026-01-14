#include <stdio.h>

int main() {
    int var = 10;
    
    // Store address of var variable
    int* ptr = &var;
    
    // Dereferencing ptr to access the value
    printf("The pointer value is = %d", *ptr);
    
    return 0;
}