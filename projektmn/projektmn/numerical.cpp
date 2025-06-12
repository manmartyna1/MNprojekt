#include "numerical.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

// Lagrange
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double x_interp) {
    int n = x.size();
    if (n != y.size() || n == 0)
        throw std::invalid_argument("Rozmiary wektorów x i y musz¹ byæ równe i > 0");

    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i)
                term *= (x_interp - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

// Eliminacja Gaussa
std::vector<double> gaussElimination(Matrix A, std::vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        }
        std::swap(A[i], A[maxRow]);
        std::swap(b[i], b[maxRow]);
        for (int k = i + 1; k < n; ++k) {
            double c = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j)
                A[k][j] -= c * A[i][j];
            b[k] -= c * b[i];
        }
    }
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    return x;
}

// Regresja liniowa (MNK)
double linearRegression(const std::vector<double>& x, const std::vector<double>& y, double x_val) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; ++i) {
        sumX += x[i]; sumY += y[i];
        sumXY += x[i] * y[i]; sumX2 += x[i] * x[i];
    }
    double a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - a * sumX) / n;
    return a * x_val + b;
}

// Ca³kowanie – metoda trapezów
double trapezoidalIntegral(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i)
        sum += f(a + i * h);
    return sum * h;
}

// Metoda Eulera
std::vector<double> eulerMethod(double (*f)(double, double), double x0, double y0, double h, int steps) {
    std::vector<double> y(steps + 1);
    y[0] = y0;
    for (int i = 1; i <= steps; ++i) {
        y[i] = y[i - 1] + h * f(x0, y[i - 1]);
        x0 += h;
    }
    return y;
}

// Bisekcja
double bisection(double (*f)(double), double a, double b, double tol) {
    if (f(a) * f(b) >= 0)
        throw std::invalid_argument("Brak zmiany znaku na przedziale");
    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}
