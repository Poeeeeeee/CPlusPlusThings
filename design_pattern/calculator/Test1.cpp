#include <iostream>

using namespace std;

typedef class ICalculator
{
    public:
    virtual double getResult(char operation, double num1, double num2) = 0;
} ICalculator;

class Calculator : public ICalculator
{
    public:
    double getResult(char operation, double num1, double num2)
    {
        double result = 0.0;
        switch (operation)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            break;
        }
        return result;
    }
};

int main()
{
    double x = 0.0, y = 0.0, result = 0.0;
    char operation = '+';

    cout << "please input number and operation" << endl;
    cin >> x >> operation >> y;

    Calculator c;
    ICalculator *i = &c;

    result = i -> getResult(operation, x, y);

    cout << "calculator rseult:" << result << endl;

    return result;
}