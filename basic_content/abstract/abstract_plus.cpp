#include <iostream>
#include <string>

using namespace std;

class AbstractBase
{
protected:
    string name;

public:
    AbstractBase(string name)
    {
        this->name = name;
    };
    virtual void notify() = 0;
};

class Con : public AbstractBase
{
public:
    Con(string name) : AbstractBase(name){};
    void notify()
    {
        cout << this->name << endl;
    }
};

int main()
{
    AbstractBase *a = new Con("abc");
    a->notify();
    return 0;
}