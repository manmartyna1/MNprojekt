#include "numerical.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// Funkcja testowa do ca³kowania i Eulera (dT/dt = -a*(T^4 - b))
double coolingODE(double t, double T) {
    double alpha = 4e-12;
    double beta = 0;
    return -alpha * (pow(T, 4) - beta);
}

// Funkcja testowa do ca³kowania (x^2)
double f(double x) {
    return x * x;
}

int main() {
    cout << fixed << setprecision(6);

    // === Interpolacja z pliku o uk³adzie kolumnowym ===
    ifstream file("MN_zal.txt");
    vector<double> x_vals, y_vals;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        double x, y;
        if (!(iss >> x >> y)) continue; // Pomija puste lub b³êdne linie
        x_vals.push_back(x);
        y_vals.push_back(y);
    }
    file.close();
    double xi = 2.5;
    double yi = lagrangeInterpolation(x_vals, y_vals, xi);
    cout << "[INTERPOLACJA] f(" << xi << ") = " << yi << endl;

    // === Ca³kowanie ===
    double integral = trapezoidalIntegral(f, 0, 1, 100);
    cout << "[CALKOWANIE] Ca³ka z x^2 od 0 do 1 = " << integral << endl;

    // === Euler (model ch³odzenia) ===
    double T0 = 344.0;
    double h = 1.0;
    int steps = 344;
    vector<double> temps = eulerMethod(coolingODE, 0, T0, h, steps);
    ofstream out("euler_temperatury.csv");
    for (int i = 0; i <= steps; ++i) {
        out << i << "," << temps[i] << endl;
    }
    out.close();
    cout << "[EULER] Temp. po " << steps << " s: " << temps.back() << " K (wynik zapisany w euler_temperatury.csv)" << endl;

    // === Aproksymacja ===
    vector<double> xa = { 1, 2, 3, 4 };
    vector<double> ya = { 2.1, 4.2, 6.1, 8.2 };
    cout << "[APROKSYM. MNK] Dla x=5: y = " << linearRegression(xa, ya, 5) << endl;

    // === Bisekcja ===
    auto eq = [](double x) { return x * x - 2; };
    double root = bisection(eq, 1, 2, 1e-6);
    cout << "[BISEKCJA] Pierwiastek z 2: " << root << endl;

    return 0;
}
