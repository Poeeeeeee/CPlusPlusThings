#include <iostream>

using namespace std;

class Operation
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

class AddOperation : public Operation
{
public:
    double getResult()
    {
        return num1 + num2;
    }
};

class SubOperation : public Operation
{
public:
    double getResult()
    {
        return num1 - num2;
    }
};

class MulOperation : public Operation
{
public:
    double getResult()
    {
        return num1 * num2;
    }
};

class DivOperation : public Operation
{
public:
    double getResult()
    {
        return num1 / num2;
    }
};

class OperationContext
{
private:
    Operation *op;

public:
    OperationContext(char operation)
    {
        switch (operation)
        {
        case '+':
            op = new AddOperation;
            break;
        case '-':
            op = new SubOperation;
            break;
        case '*':
            op = new MulOperation;
            break;
        case '/':
            op = new DivOperation;
            break;
        default:
            op = new AddOperation;
            break;
        }
    }
    double getResult(double num1, double num2)
    {
        op -> setNum1(num1);
        op -> setNum2(num2);
        return op->getResult();
    }
};

int main()
{
    double x = 0.0, y = 0.0, result = 0.0;
    char operation = '+';

    cout << "please input number and operation(+-*/)" << endl;
    cin >> x >> operation >> y;

    OperationContext *op = new OperationContext(operation);
    result = op -> getResult(x, y);

    cout << "calculator rseult:" << result << endl;

    return result;
}