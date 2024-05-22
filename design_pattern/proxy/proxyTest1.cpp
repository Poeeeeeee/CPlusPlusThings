#include <iostream>

using namespace std;

class IGiveGift
{
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};

class SchoolGirl
{
private:
    string name;

public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName(void)
    {
        return this->name;
    }
    SchoolGirl(string name) 
    {
        this->name = name;
    }
    SchoolGirl() {}
    ~SchoolGirl() {}
};

class Pursuit : public IGiveGift
{
private:
    SchoolGirl *girl;

public:
    void giveDolls()
    {
        cout << this->girl->getName() << ",你好！送你洋娃娃。" << endl;
    }
    void giveFlowers()
    {
        cout << this->girl->getName() << ",你好！送你鲜花。" << endl;
    }
    void giveChocolate()
    {
        cout << this->girl->getName() << ",你好！送你巧克力。" << endl;
    }
    Pursuit(SchoolGirl *girl)
    {
        this->girl = girl;
    }
    ~Pursuit() {}
};

class Proxy : public IGiveGift
{
private:
    Pursuit *pursuit;

public:
    void giveDolls()
    {
        cout<<"代理"<<endl;
        this->pursuit->giveDolls();
    }
    void giveFlowers()
    {
        cout<<"代理"<<endl;
        this->pursuit->giveFlowers();
    }
    void giveChocolate()
    {
        cout<<"代理"<<endl;
        this->pursuit->giveChocolate();
    }
    Proxy(SchoolGirl *girl)
    {
        this->pursuit = new Pursuit(girl);
    }
    ~Proxy() {}
};



int main()
{
    cout << "**********************************************" << endl;
    cout << endl;

    SchoolGirl *girlLjj = new SchoolGirl();
    girlLjj->setName("李娇娇");

    Proxy *boyDl = new Proxy(girlLjj);
    boyDl->giveDolls();
    boyDl->giveFlowers();
    boyDl->giveChocolate();

    cout << endl;
    cout << "**********************************************" << endl;
    return 0;
}