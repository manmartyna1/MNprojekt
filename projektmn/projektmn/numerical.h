#ifndef NUMERICAL_H
#define NUMERICAL_H

#include <vector>

/**
 * @brief Interpolacja wielomianowa Lagrange�a
 *
 * @param x Wektor wsp�rz�dnych X (punkty)
 * @param y Wektor warto�ci Y odpowiadaj�cy punktom X
 * @param x_interp Punkt, dla kt�rego interpolujemy
 * @return Przybli�ona warto�� funkcji interpoluj�cej w punkcie x_interp
 *
 * @example
 * lagrangeInterpolation({1, 2, 3}, {1, 4, 9}, 2.5);
 */
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double x_interp);


/**
 * @brief Rozwi�zywanie uk�ad�w r�wna� liniowych metod� eliminacji Gaussa
 *
 * @param A Macierz wsp�czynnik�w
 * @param b Wektor wyraz�w wolnych
 * @return Wektor rozwi�za�
 *
 * @example
 * gaussElimination({{2,1},{5,7}}, {11,13});
 */
typedef std::vector<std::vector<double>> Matrix;
std::vector<double> gaussElimination(Matrix A, std::vector<double> b);


/**
 * @brief Aproksymacja funkcji metod� najmniejszych kwadrat�w (regresja liniowa)
 *
 * @param x Wektor X (punkty pomiarowe)
 * @param y Wektor Y (warto�ci odpowiadaj�ce X)
 * @param x_val Punkt, dla kt�rego chcemy obliczy� warto�� funkcji
 * @return Warto�� funkcji aproksymuj�cej w x_val
 *
 * @example
 * linearRegression({1, 2, 3}, {2, 4, 6}, 4);
 */
double linearRegression(const std::vector<double>& x, const std::vector<double>& y, double x_val);


/**
 * @brief Obliczanie ca�ki oznaczonej metod� trapez�w
 *
 * @param f Wska�nik na funkcj� jednowymiarow�
 * @param a Pocz�tek przedzia�u ca�kowania
 * @param b Koniec przedzia�u ca�kowania
 * @param n Liczba przedzia��w
 * @return Przybli�ona warto�� ca�ki
 *
 * @example
 * trapezoidalIntegral([](double x){ return x*x; }, 0, 1, 100);
 */
double trapezoidalIntegral(double (*f)(double), double a, double b, int n);


/**
 * @brief Rozwi�zywanie r�wna� r�niczkowych metod� Eulera
 *
 * @param f Funkcja pochodnej y' = f(x, y)
 * @param x0 Punkt pocz�tkowy x
 * @param y0 Warto�� pocz�tkowa y(x0)
 * @param h Krok ca�kowania
 * @param steps Liczba krok�w
 * @return Wektor warto�ci y[i] dla ka�dego kroku
 *
 * @example
 * eulerMethod([](double x, double y) { return x + y; }, 0, 1, 0.1, 10);
 */
std::vector<double> eulerMethod(double (*f)(double, double), double x0, double y0, double h, int steps);


/**
 * @brief Znajdowanie miejsca zerowego funkcji metod� bisekcji
 *
 * @param f Funkcja jednowymiarowa
 * @param a Lewy koniec przedzia�u
 * @param b Prawy koniec przedzia�u
 * @param tol Tolerancja
 * @return Przybli�one miejsce zerowe funkcji
 *
 * @example
 * bisection([](double x){ return x*x - 2; }, 1, 2, 1e-6);
 */
double bisection(double (*f)(double), double a, double b, double tol);

#endif
