#include <iostream>
#include <cmath>
using namespace std;
double func(double x)
{
    return 3 * x * pow(2, -x);
}
int main()
{
    int N, row, col;
    double h, x0, xn, **dt, *x;
    cout << "Enter interval [ X0 , Xn] : ";
    cin >> x0 >> xn;
    cout << "Enter N : ";
    cin >> N;
    h = (xn - x0) / N;
    row = N + 1;
    col = N + 1;
    x = new double[row];
    dt = new double *[row];
    for (int i = 0; i < row; i++)
        dt[i] = new double[col];
    for (int i = 0; i < row; i++)
    {
        x[i] = x0 + i * h;
        dt[i][0] = func(x[i]);
    }
    /*
    dt[0][0] = 1;
    dt[1][0] = 3;
    dt[2][0] = 49;
    dt[3][0] = 129;
    dt[4][0] = 813;
    */
    int j = 1;
    for (int j = 1; j < col; j++)
        for (int i = 0; i < row - j; i++)
            dt[i][j] = (dt[i + 1][j - 1] - dt[i][j - 1]) / (x[i + j] - x[i]);

    for (int i = 0; i < row; i++)
    {
        cout << x[i];
        for (int j = 0; j < col; j++)
        {
            cout << "\t" << dt[i][j];
        }
        cout << endl;
    }
    double t, x1, res;

    cout << "Enter x : ";
    cin >> x1;
    res = dt[0][0];
    for (int i = 1; i <= N; i++)
    {
        t = 1;
        for (int j = 0; j < i; j++)
            t *= (x1 - x[j]);
        res += t * dt[0][i];
    }
    cout << res;
    return 1;
}