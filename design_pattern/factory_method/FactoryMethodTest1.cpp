#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Operation
{
public:
    virtual double getResult(double num1, double num2) = 0;
};

class Add : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return num1 + num2;
    }
};

class Sub : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return num1 - num2;
    }
};

class Mul : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return num1 * num2;
    }
};

class Div : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return num1 / num2;
    }
};

class Log : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return log(num1) / log(num2);
    }
};

class Pow : public Operation
{
public:
    double getResult(double num1, double num2)
    {
        return pow(num1, num2);
    }
};

class IFactory
{
public:
    virtual Operation *createOperation(char type) = 0;
};

class BaseFactory : public IFactory
{
public:
    Operation *createOperation(char type)
    {
        Operation *op;
        switch (type)
        {
        case '+':
            op = new Add();
            break;
        case '-':
            op = new Sub();
            break;
        case '*':
            op = new Mul();
            break;
        case '/':
            op = new Div();
            break;
        default:
            break;
        }
        return op;
    }
    BaseFactory() {}
    ~BaseFactory() {}
};

class AdvancedFactory : public IFactory
{
public:
    Operation *createOperation(char type)
    {
        Operation *op;
        switch (type)
        {
        case 'l':
            op = new Add();
            break;
        case 'p':
            op = new Sub();
            break;
        default:
            break;
        }
        return op;
    }
    AdvancedFactory() {}
    ~AdvancedFactory() {}
};

class OperationFactory
{
    public:
    static Operation *createOperation(char type)
    {
        Operation *op;
        IFactory *factory;
        switch (type)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            factory = new BaseFactory();
            break;
        case 'l':
        case 'p':
            factory = new AdvancedFactory();
            break;
        default:
            break;
        }
        return factory->createOperation(type);
    }
};

int main()
{
    double x = 0.0, y = 0.0, result = 0.0;
    char operation = '+';

    cout << "please input first number" << endl;
    cin >> x ;
    cout << "please input first operation(+-*/lp)" << endl;
    cin >> operation;
    cout << "please input second number" << endl;
    cin >> y;

    Operation *op = OperationFactory::createOperation(operation);
    result = op->getResult(x, y);

    cout << "calculator rseult:" << result << endl;

    return 0;
}