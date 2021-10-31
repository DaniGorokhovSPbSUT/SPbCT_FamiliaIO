#include "MathLib.h"
#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, c;
    cout << "Введите сторону а: ";
    cin >> a;
    cout << "Введите сторону b: ";
    cin >> b;
    cout << "Введите сторону c: ";
    cin >> c;

    try
    {
        cout << "Периметр равен: " << MathFuncs::MyMathFuncs::Per(a, b, c) << endl;
        cout << "Площадь равна: " << MathFuncs::MyMathFuncs::Square(a, b, c) << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}

