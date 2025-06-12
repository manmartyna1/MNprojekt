#ifndef NUMERICAL_H
#define NUMERICAL_H

#include <vector>

/**
 * @brief Interpolacja wielomianowa Lagrange’a
 *
 * @param x Wektor wspó³rzêdnych X (punkty)
 * @param y Wektor wartoœci Y odpowiadaj¹cy punktom X
 * @param x_interp Punkt, dla którego interpolujemy
 * @return Przybli¿ona wartoœæ funkcji interpoluj¹cej w punkcie x_interp
 *
 * @example
 * lagrangeInterpolation({1, 2, 3}, {1, 4, 9}, 2.5);
 */
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double x_interp);


/**
 * @brief Rozwi¹zywanie uk³adów równañ liniowych metod¹ eliminacji Gaussa
 *
 * @param A Macierz wspó³czynników
 * @param b Wektor wyrazów wolnych
 * @return Wektor rozwi¹zañ
 *
 * @example
 * gaussElimination({{2,1},{5,7}}, {11,13});
 */
typedef std::vector<std::vector<double>> Matrix;
std::vector<double> gaussElimination(Matrix A, std::vector<double> b);


/**
 * @brief Aproksymacja funkcji metod¹ najmniejszych kwadratów (regresja liniowa)
 *
 * @param x Wektor X (punkty pomiarowe)
 * @param y Wektor Y (wartoœci odpowiadaj¹ce X)
 * @param x_val Punkt, dla którego chcemy obliczyæ wartoœæ funkcji
 * @return Wartoœæ funkcji aproksymuj¹cej w x_val
 *
 * @example
 * linearRegression({1, 2, 3}, {2, 4, 6}, 4);
 */
double linearRegression(const std::vector<double>& x, const std::vector<double>& y, double x_val);


/**
 * @brief Obliczanie ca³ki oznaczonej metod¹ trapezów
 *
 * @param f WskaŸnik na funkcjê jednowymiarow¹
 * @param a Pocz¹tek przedzia³u ca³kowania
 * @param b Koniec przedzia³u ca³kowania
 * @param n Liczba przedzia³ów
 * @return Przybli¿ona wartoœæ ca³ki
 *
 * @example
 * trapezoidalIntegral([](double x){ return x*x; }, 0, 1, 100);
 */
double trapezoidalIntegral(double (*f)(double), double a, double b, int n);


/**
 * @brief Rozwi¹zywanie równañ ró¿niczkowych metod¹ Eulera
 *
 * @param f Funkcja pochodnej y' = f(x, y)
 * @param x0 Punkt pocz¹tkowy x
 * @param y0 Wartoœæ pocz¹tkowa y(x0)
 * @param h Krok ca³kowania
 * @param steps Liczba kroków
 * @return Wektor wartoœci y[i] dla ka¿dego kroku
 *
 * @example
 * eulerMethod([](double x, double y) { return x + y; }, 0, 1, 0.1, 10);
 */
std::vector<double> eulerMethod(double (*f)(double, double), double x0, double y0, double h, int steps);


/**
 * @brief Znajdowanie miejsca zerowego funkcji metod¹ bisekcji
 *
 * @param f Funkcja jednowymiarowa
 * @param a Lewy koniec przedzia³u
 * @param b Prawy koniec przedzia³u
 * @param tol Tolerancja
 * @return Przybli¿one miejsce zerowe funkcji
 *
 * @example
 * bisection([](double x){ return x*x - 2; }, 1, 2, 1e-6);
 */
double bisection(double (*f)(double), double a, double b, double tol);

#endif
