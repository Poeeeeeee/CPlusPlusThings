#include <iostream>
#include <string>

using namespace std;

class Player
{
protected:
    string name;

public:
    virtual void attack() = 0;
    virtual void defense() = 0;
};

class Forwards : public Player
{
public:
    Forwards(string name)
    {
        this->name = name;
    }
    void attack()
    {
        cout << "前锋 " << this->name << " 进攻" << endl;
    }
    void defense()
    {
        cout << "前锋 " << this->name << " 防守" << endl;
    }
};

class Center : public Player
{
public:
    Center(string name)
    {
        this->name = name;
    }
    void attack()
    {
        cout << "中锋 " << this->name << " 进攻" << endl;
    }
    void defense()
    {
        cout << "中锋 " << this->name << " 防守" << endl;
    }
};

class Guards : public Player
{
public:
    Guards(string name)
    {
        this->name = name;
    }
    void attack()
    {
        cout << "后卫 " << this->name << " 进攻" << endl;
    }
    void defense()
    {
        cout << "后卫 " << this->name << " 防守" << endl;
    }
};

class ForeignCenter
{
private:
    string name;

public:
    void jingong()
    {
        cout << "外籍中锋 " << this->name << " 进攻" << endl;
    }
    void fangshou()
    {
        cout << "外籍中锋 " << this->name << " 防守" << endl;
    }
    void setName(string name)
    {
        this->name = name;
    }
};

class Translator : public Player
{
private:
    ForeignCenter *foreignCenter = new ForeignCenter();

public:
    Translator(string name)
    {
        this->name = name;
        foreignCenter->setName(name);
    }
    void attack()
    {
        foreignCenter->jingong();
    }
    void defense()
    {
        foreignCenter->fangshou();
    }
};

int main()
{
    Player *forwards = new Forwards("巴蒂尔");
    forwards->attack();

    Player *guards = new Guards("麦克格雷迪");
    guards->attack();

    Player *center = new Translator("姚明");

    center->attack();
    center->defense();
}