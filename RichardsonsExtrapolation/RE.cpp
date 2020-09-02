#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float f(float x)
{
    return sin(x);
}

void Derivative(float x, int n, float h, float D[10][10])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        D[i][0] = (f(x + h) - f(x - h)) / (2 * h);
        //cout << D[i][0] << endl;
        for (j = 0; j <= (i - 1); j++)
        {
            // cout << i << j << endl;
            D[i][j + 1] = ((pow(4.0, float(j + 1))) * D[i][j] - D[i - 1][j]) / (pow(4.0, float(j + 1)) - 1);
        }
        h = h / 2;
    }
}

int main()
{
    float D[10][10];
    int n = 10, digits = 5;
    float h = 1, x = 0;
    cout << "Enter x : ";
    cin >> x;
    cout << "Enter Power : ";
    cin >> n;
    Derivative(x, n, h, D);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << setprecision(digits) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << setw(digits + 2) << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\tDerivative : f'(" << x << ") = " << D[n - 1][n - 1] << endl;
    return 0;
}
