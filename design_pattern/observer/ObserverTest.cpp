#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Subject;

class Observer
{
protected:
    string name;
    Subject *subject;

public:
    virtual void update() = 0;
};

class Subject
{
private:
    vector<Observer *> observers;

protected:
    string status;

public:
    void attach(Observer *observer)
    {
        this->observers.push_back(observer); // 直接存储指针
    };
    void detach(Observer *observer)
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    };
    void notifyObserver()
    {
        for (auto observer : observers) // 使用范围for循环遍历
        {
            if (observer) // 确保指针不为空
                observer->update();
        }
    }
    string getStatus()
    {
        return this->status;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
};

class ConcreteObserver : public Observer
{

public:
    void update()
    {
        cout << "observer " << this->name << " update status " << this->subject->getStatus() <<endl;
    }
    ~ConcreteObserver() {}
    ConcreteObserver() {}
    ConcreteObserver(string name, Subject *subject)
    {
        this->name = name;
        this->subject = subject;
    }
};

class ConcreteSubject : public Subject
{
};

int main()
{
    Subject *subject = new ConcreteSubject();
    ConcreteObserver *ob1 = new ConcreteObserver("NameX", subject);
    ConcreteObserver *ob2 = new ConcreteObserver("NameY", subject);
    ConcreteObserver *ob3 = new ConcreteObserver("NameZ", subject);
    subject->attach(ob1);
    subject->attach(ob2);
    subject->attach(ob3);

    subject->setStatus("ABC");
    subject->notifyObserver();
    return 0;
}