#include <stdio.h>

#define MAX_TIME 5
#define NUM_VAR 4

// void step(double** x, double* t, double*)
int sum(int a, int b) { return a+b; }
int mul(int a, int b) { return a*b; }

int (*func[2]) (int, int);

void scary(int (**array) (int, int)) {
    printf("%i\n", (*(array+1))(9, 5));
    printf("%i\n", array[0](9, 5));
}

double dot_product(double* x, double* y, size_t length) {
    double total = 0;
    for (int i = 0; i < length; ++i) {
        total += x[i] * y[i];
    }
    return total;
}

int main(void) {
    double classic_rk_weights[4] = {1/6, 1/3, 1/3, 1/6};
    double classic_rk_nodes[4] = {0, 1/2, 1/2, 1};
    double classic_rk_matrix[4][4] = { {0, 0, 0, 0}, {1/2, 0, 0, 0},
                                    {0, 1/2, 0, 0}, {0, 0, 1, 0} };



    double x[NUM_VAR][MAX_TIME] = { {1, 2, 3, 4, 5}, {5, 6, 7, 8, 5}, {9, 10, 11, 12, 5}, {13, 14, 15, 16, 5}};
    double y[3][4] = {0};

    func[0] = sum;
    func[1] = mul;

    printf("%lf\n", *(x[1]));
    printf("%lf\n", *(*(x+1)+1));
    printf("%i\n", func[1](3, 4));
    printf("%i\n", (*(func+1))(3, 4));

    scary(func);

    double ar1[4] = {1, 2, 3, 4};
    double ar2[4] = {1, 2, 3, 4};
    printf("%lf\n", dot_product(ar1, ar2, 4));

    return 0;
}