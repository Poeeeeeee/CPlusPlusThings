#include <iostream>
#include <vector>

using namespace std;

class Man;
class Woman;

class Action
{
public:
    virtual void getManResult(Man *man) = 0;
    virtual void getWomenResult(Woman *women) = 0;
};

class Success : public Action
{
    void getManResult(Man *man)
    {
        cout << "success man" << endl;
    }
    void getWomenResult(Woman *women)
    {
        cout << "success women" << endl;
    }
};

class Fail : public Action
{
    void getManResult(Man *man)
    {
        cout << "fail man" << endl;
    }
    void getWomenResult(Woman *women)
    {
        cout << "fail women" << endl;
    }
};

class Amativeness : public Action
{
    void getManResult(Man *man)
    {
        cout << "amativeness man" << endl;
    }
    void getWomenResult(Woman *women)
    {
        cout << "amativeness women" << endl;
    }
};

class Marriage : public Action
{
    void getManResult(Man *man)
    {
        cout << "marriage man" << endl;
    }
    void getWomenResult(Woman *women)
    {
        cout << "marriage women" << endl;
    }
};

class Person
{
public:
    virtual void accept(Action *vistor) = 0;
};

class Man : public Person
{
public:
    void accept(Action *vistor)
    {
        vistor->getManResult(this);
    }
};

class Woman : public Person
{
public:
    void accept(Action *vistor)
    {
        vistor->getWomenResult(this);
    }
};

class ObjectStructure
{
private:
    vector<Person *> objs;

public:
    void attach(Person *p)
    {
        objs.push_back(p);
    }
    void clear(Person *p)
    {
        objs.pop_back();
    }
    void display(Action *vistor)
    {
        for (auto obj : objs)
        {
            if (obj)
            {
                obj->accept(vistor);
            }
        }
    }
};

int main()
{
    ObjectStructure *o = new ObjectStructure();
    o->attach(new Man());
    o->attach(new Woman());

    // 成功时的反应
    Success *v1 = new Success();
    o->display(v1);

    // 失败时的反应
    Fail *v2 = new Fail();
    o->display(v2);

    // 恋爱时的反应
    Amativeness *v3 = new Amativeness();
    o->display(v3);

    // 婚姻时的反应
    Marriage *v4 = new Marriage();
    o->display(v4);
    return 0;
}