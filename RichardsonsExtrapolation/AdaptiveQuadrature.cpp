#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
    return 1 / (x * x * x + 1); //(2 + sin(2 * sqrt(x)));
}
int main()
{
    float a, b, tol;
    cout << "Enter Interval : ";
    cin >> a >> b;
    cout << "\nEnter Tolerance : ";
    cin >> tol;
}