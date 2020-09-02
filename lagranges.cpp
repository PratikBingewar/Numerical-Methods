#include <iostream>
#include <fstream>
using namespace std;
struct data
{
    double x, y;
};
int main()
{
    ifstream file;
    file.open("input.txt");
    int N;
    file >> N;
    //cout << N;
    struct data fun[N];
    for (int i = 0; i < N; ++i)
    {
        file >> fun[i].x >> fun[i].y;
        //  cout << fun[i].x << fun[i].y << endl;
    }
    cout << "f(x) = ";
    for (int i = 0; i < N; ++i)
    {
        cout << "{[";
        for (int j = 0; j < N; ++j)
        {
            if (j == i)
                continue;
            cout << "(x - " << fun[j].x << ")";
        }
        cout << "] / [";
        for (int j = 0; j < N; ++j)
        {
            if (j == i)
                continue;
            cout << "(" << fun[i].x << " - " << fun[j].x << ")";
        }
        cout << "]}";
        cout << " * " << fun[i].y << " + ";
    }
    cout << "\b\b \n";
    cout << "\nenter x :";
    double x, result = 0, numerator = 1, denominator = 1;
    cin >> x;

    for (int i = 0; i < N; ++i)
    {
        double term = fun[i].y;
        for (int j = 0; j < N; ++j)
        {
            if (i != j)
                term *= (x - fun[j].x) / (fun[i].x - fun[j].x);
        }
        result += term;
    }
    cout << "Result : " << result << endl;
    return 0;
}