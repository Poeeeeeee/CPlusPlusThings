#include <iostream>
#include <string>

using namespace std;

class Country;

class UnitedNations
{
public:
    virtual void declare(string message, Country *country) = 0;
};

class Country
{
protected:
    UnitedNations *un;

public:
    Country(UnitedNations *temp)
    {
        un = temp;
    }
};

class USA : public Country
{
public:
    USA(UnitedNations *temp) : Country(temp){};
    void declare(string message)
    {
        un->declare(message, this);
    }
    void getMessage(string message)
    {
        cout << "USA get message: " << message << endl;
    }
};

class Iraq : public Country
{
public:
    Iraq(UnitedNations *temp) : Country(temp){};
    void declare(string message)
    {
        un->declare(message, this);
    }
    void getMessage(string message)
    {
        cout << "Iraq get message: " << message << endl;
    }
};

class UnitedNationsSecurityCouncil : public UnitedNations
{
private:
    USA *usa;
    Iraq *iraq;

public:
    void setUsa(USA *usa)
    {
        this->usa = usa;
    }
    void setIraq(Iraq *iraq)
    {
        this->iraq - iraq;
    }
    void declare(string message, Country *country)
    {
        if (country == usa)
        {
            iraq->getMessage(message);
        }
        else
        {
            usa->getMessage(message);
        }
    }
};

int main()
{
    UnitedNationsSecurityCouncil *UNSC = new UnitedNationsSecurityCouncil();

    USA *c1 = new USA(UNSC);
    Iraq *c2 = new Iraq(UNSC);

    UNSC->setUsa(c1);
    UNSC->setIraq(c2);

    c1->declare("不准研制核武器，否则要发动战争！");
    c2->declare("我们没有核武器，也不怕侵略。");

    return 0;
}