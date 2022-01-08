/* Peter Zhou */
#include <stdio.h>
#include <stdlib.h>


/* custom functions declaration */
int get_input(void); // get positive integer input from terminal
int factorial(int); // computes factorial via recursion


/* main function */
int main(void) {
    int output = factorial(get_input());
    printf("%i", output);
    return 0;
}


/* custom functions */
int get_input(void) {
    int input;
    printf("Input positive integer here: ");
    scanf("%i", &input);

    if (input < 0) {
        printf("Negative integers not allowed!");
        exit(0);
    }

    return input;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}