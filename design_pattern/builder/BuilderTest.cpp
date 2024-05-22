#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
private:
    vector<string> parts;

public:
    void Add(string strtemp)
    {
        parts.push_back(strtemp);
    }
    void Show()
    {
        vector<string>::iterator p = parts.begin();
        while (p != parts.end())
        {
            cout << *p << endl;
            p++;
        }
    }
};

class Builder
{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product *getProduct() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product *product = new Product();

public:
    void buildPartA()
    {
        product->Add("部件A");
    }
    void buildPartB()
    {
        product->Add("部件B");
    }
    Product *getProduct()
    {
        return this->product;
    }
};

class ConcreteBuilder2 : public Builder
{
private:
    Product *product = new Product();

public:
    void buildPartA()
    {
        product->Add("部件X");
    }
    void buildPartB()
    {
        product->Add("部件Y");
    }
    Product *getProduct()
    {
        return this->product;
    }
};

class Director
{
public:
    void construct(Builder *builder)
    {
        builder->buildPartA();
        builder->buildPartB();
    }
};

int main()
{
    Director *director = new Director();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    // 指挥者用ConcreteBuilder1的方法来建造产品
    director->construct(b1); // 创建的是产品A和产品B
    Product *p1 = b1->getProduct();
    p1->Show();

    // 指挥者用ConcreteBuilder2的方法来建造产品
    director->construct(b2); // 创建的是产品X和产品Y
    Product *p2 = b2->getProduct();
    p2->Show();
}