#include <iostream>

using namespace std;

class Opration
{
protected:
    double num1;
    double num2;

public:
    virtual double getResult() = 0;
    void setNum1(double number1)
    {
        num1 = number1;
    };
    double getNum1(void)
    {
        return num1;
    };
    void setNum2(double number2)
    {
        num2 = number2;
    };
    double getNum2(void)
    {
        return num2;
    };
};

class AddOpration : public Opration
{
public:
    double getResult()
    {
        return num1 + num2;
    }
};

class SubOpration : public Opration
{
public:
    double getResult()
    {
        return num1 - num2;
    }
};

class MulOpration : public Opration
{
public:
    double getResult()
    {
        return num1 * num2;
    }
};

class DivOpration : public Opration
{
public:
    double getResult()
    {
        return num1 / num2;
    }
};

class OprationFactory
{
public:
    static Opration *createOpration(char opration);
};

Opration *OprationFactory::createOpration(char opration)
{
    Opration *oper;
    switch (opration)
    {
    case '+':
        oper = new AddOpration;
        break;
    case '-':
        oper = new SubOpration;
        break;
    case '*':
        oper = new MulOpration;
        break;
    case '/':
        oper = new DivOpration;
        break;
    default:
        oper = new AddOpration;
        break;
    }
    return oper;
};

int main()
{
    double x = 0.0, y = 0.0, result = 0.0;
    char operation = '+';

    cout << "please input number and operation(+-*/)" << endl;
    cin >> x >> operation >> y;

    Opration *op = OprationFactory::createOpration(operation);
    op->setNum1(x);
    op->setNum2(y);
    result = op->getResult();

    cout << "calculator rseult:" << result << endl;

    return result;
}