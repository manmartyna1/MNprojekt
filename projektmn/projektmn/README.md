# Projekt: Biblioteka numeryczna (C++)

##  Opis
Projekt zaliczeniowy z przedmiotu *Metody numeryczne*. Celem jest stworzenie biblioteki numerycznej w języku C++ implementującej podstawowe metody obliczeniowe.

Biblioteka zawiera:
- Interpolacja Lagrange’a
- Eliminacja Gaussa (układy równań liniowych)
- Aproksymacja (regresja liniowa)
- Całkowanie (metoda trapezów)
- Równania różniczkowe (metoda Eulera)
- Równania nieliniowe (metoda bisekcji)

---

##  Struktura projektu
projektmn/
├── include/
│ └── numerical.h # Deklaracje wszystkich funkcji
├── src/
│ └── numerical.cpp # Implementacja funkcji
├── tests/
│ └── test.cpp # Testy jednostkowe każdej funkcji
├── examples/
│ └── example.cpp # Praktyczne zastosowania funkcji
└── README.md # Dokumentacja projektu

##  Uruchomienie
Visual Studio
1. Otwórz plik projektmn.sln w Visual Studio.
2. W Eksploratorze rozwiązań przejdź do folderu tests/ lub examples/.
3. W zależności od tego, co chcesz uruchomić:
    - kliknij prawym przyciskiem na test.cpp lub example.cpp
	- wybierz "Wyłączony z kompilacji" (Tak/Nie)
4. Uruchom program 

## Testy jednostkowe
W pliku tests/test.cpp znajdują się testy sprawdzające:
- poprawne wartości zwracane przez każdą funkcję
- błędne dane wejściowe (np. różne długości wektorów)
- stabilność i dokładność wyników

Uruchomienie testów:
- Ustaw test.cpp jako element startowy
- Uruchom 

## Przykłady użycia
#include "numerical.h"
#include <iostream>
using namespace std;

int main() {
    vector<double> x = {1, 2, 3};
    vector<double> y = {1, 4, 9};
    double val = lagrangeInterpolation(x, y, 1.5);
    cout << "Interpolacja: " << val << endl;
}

Autorzy
Projekt wykonany przez:
- Martyna Mandziuk
- Gabriela Macheta 