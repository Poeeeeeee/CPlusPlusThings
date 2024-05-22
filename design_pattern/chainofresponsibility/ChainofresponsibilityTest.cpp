#include <iostream>
#include <string>

using namespace std;

class Handler
{
protected:
    Handler *successor;

public:
    void setSuccessor(Handler *successor)
    {
        this->successor = successor;
    }
    virtual void handleRequest(int request) = 0;
};

class ConcreteHandler1 : public Handler
{
public:
    void handleRequest(int request)
    {
        if (0 <= request && request <= 10)
        {
            cout << "handler1 executeing ..." << endl;
        }
        else if (this->successor != nullptr)
        {
            this->successor->handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void handleRequest(int request)
    {
        if (10 < request && request <= 20)
        {
            cout << "handler2 executeing ..." << endl;
        }
        else if (this->successor != nullptr)
        {
            this->successor->handleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler
{
public:
    void handleRequest(int request)
    {
        if (request > 20)
        {
            cout << "handler3 executeing ..." << endl;
        }
        else if (this->successor != nullptr)
        {
            this->successor->handleRequest(request);
        }
    }
};

int main()
{
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();
    h1->setSuccessor(h2);
    h2->setSuccessor(h3);

    int requests[] = {2, 5, 14, 22, 18, 3, 27, 20};

    for (int request : requests)
    {
        h1->handleRequest(request);
    }
}