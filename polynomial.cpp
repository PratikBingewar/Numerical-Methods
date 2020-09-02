#include "polynomial.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#define PRV 0.0001
using namespace std;
Polynomial::Polynomial(int d)
{
    degree = d;
    polynomial = new double[degree + 1];
}
/*
Polynomial::Polynomial(const Polynomial &p1)
{
    //delete[] polynomial;
    degree = p1.degree;
    polynomial = new double[degree + 1];
    for (int i = degree; i >= 0; i--)
    {
        polynomial[i] = p1.polynomial[i];
    }
}
*/
void Polynomial::operator=(const Polynomial &p1)
{
    degree = p1.degree;
    delete[] polynomial;
    polynomial = new double[degree + 1];
    for (int i = degree; i >= 0; i--)
    {
        polynomial[i] = p1.polynomial[i];
    }
}

int Polynomial::accept()
{
    delete[] polynomial;
    cout << "Enter Degree : ";
    if (degree < 0)
        exit(0);
    cin >> degree;
    polynomial = new double[degree + 1];
    cout << "Enter Coefficients : ";
    for (int i = degree; i >= 0; i--)
    {
        cout << "\nX^" << i << " : ";
        cin >> polynomial[i];
    }
    return degree;
}

void Polynomial::display() const
{
    cout << endl
         << "Polynomial : ";
    for (int i = degree; i > 0; i--)
    {
        if (polynomial[i] < 0)
            cout << "\b";
        cout << "(" << polynomial[i] << ")x^" << i << "+";
    }
    cout << "(" << polynomial[0] << ")";
}

double Polynomial::evaluate(double x) const
{
    double result = polynomial[0];
    for (int i = 1; i <= degree; ++i)
        result += polynomial[i] * pow(x, i);
    return result;
}

double Polynomial::regulafalse() const
{
    return root('r');
}
double Polynomial::bisection() const
{
    return root('b');
}

double Polynomial::root(char token) const
{
    double a, b;
    cout << "\nEnter interval [a, b] : ";
    cin >> a >> b;
    double c;
    if (abs(evaluate(a)) <= PRV)
        return a;
    if (abs(evaluate(b)) <= PRV)
        return b;
    if (evaluate(a) * evaluate(b) > 0)
    {
        cerr << "\nBisection cannot applied .Invalid Interval.\n";
        exit(0);
    }
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    cout << setw(13) << "a" << setw(13) << "b" << setw(13) << "c" << setw(13) << "f(a)" << setw(13) << "f(b)" << setw(13) << "f(c)" << setw(13) << "Update" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    do
    {
        if (token == 'b')
            c = (b + a) / 2;
        if (token == 'r')
            c = (a * evaluate(b) - b * evaluate(a)) / (evaluate(b) - evaluate(a));
        std::cout << std::fixed;
        cout << setprecision(5) << endl;
        cout << setw(13) << a << setw(13) << b << setw(13) << c << setw(13) << evaluate(a) << setw(13) << evaluate(b) << setw(13) << evaluate(c);

        if (evaluate(a) * evaluate(c) < 0)
        {
            b = c;
            cout << setw(13) << "b = c";
        }
        else
        {
            a = c;
            cout << setw(13) << "a = c";
        }
    } while (abs(evaluate(c)) >= PRV);
    cout << endl
         << setfill('-') << setw(100) << "-" << endl;
    cout << "\nRoot : " << c << endl;
    return c;
}

Polynomial Polynomial::derivative() const
{
    Polynomial result(degree - 1);
    for (int i = result.degree; i >= 0; --i)
    {
        result.polynomial[i] = polynomial[i + 1] * (i + 1);
    }
    return result;
}

double Polynomial::newtonRaphson() const
{
    double x, x1 = 0.0;
    cout << "\nEnter initial guess : ";
    cin >> x1;
    Polynomial der = derivative();
    cout << "\nRoot :";
    do
    {
        std::cout << std::fixed << setprecision(5);
        cout << endl
             << x1;
        x = x1;
        x1 = x - (evaluate(x) / der.evaluate(x));
    } while (abs(x1 - x) >= PRV);
    cout << endl;
    return x1;
}

double Polynomial::secantMethod() const
{
    double x0, x1, x2;
    cout << "\nEnter Initial Points x0 and x1 : ";
    cin >> x1 >> x2;
    do
    {
        std::cout << std::fixed << setprecision(5);
        cout << endl
             << x2;
        x0 = x1;
        x1 = x2;

        x2 = x1 - (evaluate(x1) * (x1 - x0) / (evaluate(x1) - evaluate(x0)));
    } while (abs(x2 - x1) >= PRV);
    cout << endl;

    return x2;
}
