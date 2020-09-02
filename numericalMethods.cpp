#include <iostream>
#include <iomanip>
#include "polynomial.hpp"
#define PRV 0.001
using namespace std;

int main()
{
    Polynomial p, p1;
    p.accept();
    p.display();
    cout << "\nRoot [ Newton Raphson ] :" << p.newtonRaphson();
    cout << "\nRoot [ Secant Method ] :" << p.secantMethod();
    cout << "\nRoot [ Bisection Method ]: " << p.bisection();
    cout << "\nRoot [ Regula false Method ]: " << p.regulafalse();

    cout << endl;
    return 1;
}
