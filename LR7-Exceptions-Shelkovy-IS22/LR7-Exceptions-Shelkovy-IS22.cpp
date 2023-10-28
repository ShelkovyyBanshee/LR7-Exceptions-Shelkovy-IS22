#include <iostream>
#include <exception>

using namespace std;

class SolveEquationExceptionVar1 {};

class SolveEquationExceptionVar2
{
public:
    double a;
    double b;
    double c;
};

class SolveEquationExceptionVar3 : public exception
{
public:
    double a;
    double b;
    double c;
};

double* getRoots(double a, double b, double c)
{
    double D = b * b - 4 * a * c;
    double* result = NULL;

    if (a == 0)
    {
        result = new double[2];
        result[0] = 1;
        result[1] = -c / b;
    }
    else if (D == 0)
    {
        result = new double[2];
        result[0] = 1;
        result[1] = (-b + sqrt(D)) / (2 * a);
    }
    else
    {
        result = new double[3];
        result[0] = 2;
        result[1] = (-b + sqrt(D)) / (2 * a);
        result[2] = (-b - sqrt(D)) / (2 * a);
    }

    return result;
}

bool isKsCorrect(double a, double b, double c)
{
    return !(a == 0 && b == 0 || b * b - 4 * a * c < 0.0);
}

double* solveEquationVar1(double a, double b, double c)
{
    if (!isKsCorrect(a, b, c))
        throw SolveEquationExceptionVar1();
    return getRoots(a, b, c);
}

double* solveEquatioVar2n(double a, double b, double c) throw ()
{
    if (!isKsCorrect(a, b, c))
        throw SolveEquationExceptionVar1();
    return getRoots(a, b, c);
}

double* solveEquationVar3(double a, double b, double c) throw (exception)
{
    if (!isKsCorrect(a, b, c))
        throw exception();
    return getRoots(a, b, c);
}

double* solveEquationVar4(double a, double b, double c) throw (SolveEquationExceptionVar1)
{
    if (!isKsCorrect(a, b, c))
        throw SolveEquationExceptionVar1();
    return getRoots(a, b, c);
}

int main()
{
    double a, b, c;
    int n;
    cin >> n;

    double* answer = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        try
        {
            answer = solveEquationVar1(a, b, c);
            if (answer[0] == 1)
                cout << answer[1] << endl;
            else
                cout << answer[1] << " " << answer[2] << endl;
        }
        catch (SolveEquationExceptionVar1)
        {
            if ((a == 0 && b == 0 && c != 0) || b * b - 4 * a * c < 0.0)
                cout << "Error № 2 - net vezhestvennyh resheniy!!!!\n";
            else if (a == 0 && b == 0 && c == 0)
                cout << "Error № 1 - beskonechnoe mnozhestvo resheniy!!!!\n";
        }
    }
}
