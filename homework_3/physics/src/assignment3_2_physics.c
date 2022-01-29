
double dxdt(double* x, double t, double* param) {
    deriv = x[1];
    return deriv;    
}

double dvxdt(double* x, double t, double* param) {
    // x[0] = x, x[1] = vx, x[2] = y, x[3] = vy
    // p(aram)[0] = g, p[1] = m, p[2] = B2, p[3] = a, p[4] = alpha, p[5] = T0
    double v = sqrt(x[1]*x[1] + x[3]*x[3]);
    double base = 1 - param[3] * x[2] / param[5];

    deriv = -param[2] * pow(base, param[4]) * v * x[3] / param[1];
}

