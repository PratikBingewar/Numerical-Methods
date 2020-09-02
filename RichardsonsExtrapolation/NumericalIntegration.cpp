#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
    return 1 / (x * x * x + 1); //(2 + sin(2 * sqrt(x)));
}
float trapezoidal(float a, float b, int n)
{
    float h = (b - a) / n;
    float sum = (h / 2) * (f(a) + f(b));
    for (int i = 1; i < n; i++)
    {
        sum += h * f(a + i * h);
    }
    return sum;
}
float simpson13(float a, float b, int n) // n is even
{
    if (n % 2 != 0)
    {
        cerr << "Simpsons 1/3 rule cannot be applied, N should be an even number.";
        return 0;
    }
    float h = (b - a) / n;
    float sum = (h / 3) * (f(a) + f(b));
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)

            sum += (h / 3) * (2 * f(a + i * h));
        else
            sum += (h / 3) * (4 * f(a + i * h));
    }
    return sum;
}

float bools(float a, float b, int n) //n is multiple of 4
{
    if (n % 4 != 0)
    {
        cerr << "Bool\'s rule cannot be applied . N should be multiple of 4.";
        return 0;
    }
    float h = (b - a) / n;
    float sum = (14 * h / 45) * (f(a) + f(b));
    for (int i = 1; i < n; i++)
    {
        if (i % 4 == 0)
            sum += (2 * h / 45) * (14 * f(a + i * h));
        else if (i % 2 == 0)
            sum += (2 * h / 45) * (12 * f(a + i * h));
        else
            sum += (2 * h / 45) * (32 * f(a + i * h));
    }
    return sum;
}
int main()
{
    float a, b;
    int nodes = 6;
    cout << "Enter Interval : ";
    cin >> a >> b;
    cout << "\nHow many nodes : ";
    cin >> nodes;
    cout << "\nTrapezoidal Rule : " << trapezoidal(a, b, nodes) << endl;
    cout << "Simpsons 1/3 Rule : " << simpson13(a, b, nodes) << endl;
    cout << "Bool's Rule : " << bools(a, b, nodes) << endl;
}