#include <iostream>

using namespace std;

class ICharacter
{
public:
    virtual void show() = 0;
};

class Person : public ICharacter
{
private:
    string name;

public:
    void show()
    {
        cout << "装扮的" << name << endl;
    }
    void setName(string n)
    {
        name = n;
    }
    string getName(void)
    {
        return name;
    }
    Person(string n)
    {
        name = n;
    }
    ~Person() {}
};

class Finery : public ICharacter
{
protected:
    ICharacter *component;

public:
    void decorate(ICharacter *comp)
    {
        component = comp;
    }
    void show()
    {
        if (component != nullptr)
        {
            component->show();
        }
    }
};

class BigTrouser : public Finery
{
public:
    void show()
    {
        cout << "垮裤";
        component->show();
    }
};

class LeatherShoes : public Finery
{
public:
    void show()
    {
        cout << "皮鞋";
        component->show();
    }
};

class Sneakers : public Finery
{
public:
    void show()
    {
        cout << "球鞋";
        component->show();
    }
};

class StrawHat : public Finery
{
public:
    void show()
    {
        cout << "草帽";
        component->show();
    }
};

class Suit : public Finery
{
public:
    void show()
    {
        cout << "西装";
        component->show();
    }
};

class Tie : public Finery
{
public:
    void show()
    {
        cout << "领带";
        component->show();
    }
};

class TShirts : public Finery
{
public:
    void show()
    {
        cout << "T恤";
        component->show();
    }
};

int main()
{

    cout << "**********************************************" << endl;

    Person *xc = new Person("小菜");

    cout << " 第一种装扮：" << endl;

    Sneakers *pqx = new Sneakers(); // 生成球鞋实例
    pqx->decorate(xc);              // 球鞋装饰小菜

    BigTrouser *kk = new BigTrouser(); // 生成垮裤实例
    kk->decorate(pqx);                 // 垮裤装饰“有球鞋装饰的小菜”

    TShirts *dtx = new TShirts(); // 生成T恤实例
    dtx->decorate(kk);            // T恤装饰“有垮裤球鞋装饰的小菜”

    dtx->show(); // 执行形象展示

    cout << " 第二种装扮：" << endl;

    LeatherShoes *px = new LeatherShoes(); // 生成皮鞋实例
    px->decorate(xc);                      // 皮鞋装饰小菜

    Tie *ld = new Tie(); // 生成领带实例
    ld->decorate(px);    // 领带装饰“有皮鞋装饰的小菜”

    Suit *xz = new Suit(); // 生成西装实例
    xz->decorate(ld);      // 西装装饰“有领带皮鞋装饰的小菜”

    xz->show(); // 执行形象展示

    cout << " 第三种装扮：" << endl;

    Sneakers *pqx2 = new Sneakers(); // 生成球鞋实例
    pqx2->decorate(xc);              // 球鞋装饰小菜

    LeatherShoes *px2 = new LeatherShoes(); // 生成皮鞋实例
    px2->decorate(pqx2);                    // 皮鞋装饰“有球鞋装饰的小菜”

    BigTrouser *kk2 = new BigTrouser(); // 生成垮裤实例
    kk2->decorate(px2);                 // 垮裤装饰“有皮鞋球鞋装饰的小菜”

    Tie *ld2 = new Tie(); // 生成领带实例
    ld2->decorate(kk2);   // 领带装饰“有垮裤皮鞋球鞋装饰的小菜”

    StrawHat *cm2 = new StrawHat(); // 生成草帽实例
    cm2->decorate(ld2);             // 草帽装饰“有领带垮裤皮鞋球鞋装饰的小菜”

    cm2->show(); // 执行形象展示

    cout << "**********************************************" << endl;
}