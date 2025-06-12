#include "numerical.h"
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;

void testLagrangeBasic() {
    vector<double> x = { 1, 2, 3 };
    vector<double> y = { 1, 4, 9 };
    double result = lagrangeInterpolation(x, y, 1.5);
    assert(abs(result - 2.25) < 1e-5);
}

void testLagrangeError() {
    try {
        lagrangeInterpolation({ 1, 2 }, { 1 }, 1.5);
        assert(false); // powinien rzuciæ wyj¹tek
    }
    catch (const invalid_argument&) {
        assert(true);
    }
}

void testGauss() {
    Matrix A = { {2, 1}, {5, 7} };
    vector<double> b = { 11, 13 };
    vector<double> x = gaussElimination(A, b);
    assert(abs(x[0] - 7.111) < 0.01);
    assert(abs(x[1] - (-3.222)) < 0.01);
}

void testRegression() {
    vector<double> x = { 1, 2, 3 };
    vector<double> y = { 2, 4, 6 };
    double pred = linearRegression(x, y, 4);
    assert(abs(pred - 8.0) < 1e-5);
}

void testIntegral() {
    auto f = [](double x) { return x * x; };
    double result = trapezoidalIntegral(f, 0, 1, 100);
    assert(abs(result - 1.0 / 3.0) < 0.01);
}

void testEuler() {
    auto dydx = [](double x, double y) { return x + y; };
    vector<double> result = eulerMethod(dydx, 0, 1, 0.1, 10);
    assert(result.size() == 11);
}

void testBisection() {
    auto f = [](double x) { return x * x - 2; };
    double root = bisection(f, 1, 2, 1e-6);
    assert(abs(root - sqrt(2)) < 1e-5);
}

int main() {
    testLagrangeBasic();
    testLagrangeError();
    testGauss();
    testRegression();
    testIntegral();
    testEuler();
    testBisection();
    cout << "Wszystkie testy zaliczone!\n";
    return 0;
}
