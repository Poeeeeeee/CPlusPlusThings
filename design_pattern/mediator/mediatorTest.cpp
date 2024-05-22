#include <iostream>
#include <string>

using namespace std;

class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;
class ConcreteMediator;

class Mediator
{
public:
    virtual void send(string message, Colleague *colleague) = 0;
};

class Colleague
{
protected:
    Mediator *mediator;

public:
    Colleague(Mediator *temp)
    {
        mediator = temp;
    }
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator){};
    void send(string message)
    {
        mediator->send(message, this);
    }
    void notify(string message)
    {
        cout << "colleague1 get message " << message << endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator){};
    void send(string message)
    {
        mediator->send(message, this);
    }
    void notify(string message)
    {
        cout << "colleague2 get message " << message << endl;
    }
};

class ConcreteMediator : public Mediator
{
private:
    ConcreteColleague1 *colleague1;
    ConcreteColleague2 *colleague2;

public:
    void setColleague1(ConcreteColleague1 *colleague)
    {
        colleague1 = colleague;
    }
    void setColleague2(ConcreteColleague2 *colleague)
    {
        colleague2 = colleague;
    }
    void send(string message, Colleague *colleague)
    {
        if (colleague == colleague1)
        {
            colleague2->notify(message);
        }
        else
        {
            colleague1->notify(message);
        }
    }
};

int main()
{
    ConcreteMediator *m = new ConcreteMediator();

    ConcreteColleague1 *c1 = new ConcreteColleague1(m);
    ConcreteColleague2 *c2 = new ConcreteColleague2(m);

    m->setColleague1(c1);
    m->setColleague2(c2);

    c1->send("吃过饭了吗?");
    c2->send("没有呢，你打算请客？");
    return 0;
}