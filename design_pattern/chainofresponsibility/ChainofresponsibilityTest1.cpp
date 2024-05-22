#include <iostream>
#include <string>

using namespace std;

class Request;

class Request
{
private:
    string type;
    string content;
    int num;

public:
    void setType(string type)
    {
        this->type = type;
    }
    string getType()
    {
        return this->type;
    }
    void setContent(string content)
    {
        this->content = content;
    }
    string getContent()
    {
        return this->content;
    }
    void setNum(int num)
    {
        this->num = num;
    }
    int getNum()
    {
        return this->num;
    }
};

class Manager
{
protected:
    string name;
    Manager *superior;

public:
    void setSuperior(Manager *superior)
    {
        this->superior = superior;
    }
    void setName(string name)
    {
        this->name = name;
    }
    virtual void requestApplications(Request *req) = 0;
};

class CommonManager : public Manager
{
public:
    void requestApplications(Request *request)
    {
        if (request->getType() == "请假" && request->getNum() <= 2)
            cout << this->name << ":" << request->getContent() << " 数量：" << request->getNum() << "天，被批准" << endl;
        else if (this->superior != nullptr)
        {
            this->superior->requestApplications(request);
        }
    }
};

class Director : public Manager
{
public:
    void requestApplications(Request *request)
    {
        if (request->getType() == "请假" && request->getNum() <= 5)
            cout << this->name << ":" << request->getContent() << " 数量：" << request->getNum() << "天，被批准" << endl;
        else if (this->superior != nullptr)
        {
            this->superior->requestApplications(request);
        }
    }
};

class GeneralManager : public Manager
{
public:
    void requestApplications(Request *request)
    {
        if (request->getType() == "请假")
            cout << this->name << ":" << request->getContent() << " 数量：" << request->getNum() << "天，被批准" << endl;
        else if (request->getType() == "加薪" && request->getNum() <= 5000)
        {
            cout << this->name << ":" << request->getContent() << " 数量：" << request->getNum() << "元，被批准" << endl;
        }
        else if (request->getType() == "加薪" && request->getNum() > 5000)
        {
            cout << this->name << ":" << request->getContent() << " 数量：" << request->getNum() << "元，再说吧" << endl;
        }
    }
};

int main()
{
    CommonManager *manager = new CommonManager();
    manager->setName("金利");
    Director *director = new Director();
    director->setName("宗剑");
    GeneralManager *generalManager = new GeneralManager();
    generalManager->setName("钟精励");
    
    manager->setSuperior(director);
    director->setSuperior(generalManager);

    Request *request = new Request();
    request->setType("请假");
    request->setContent("小菜请假");
    request->setNum(1);
    manager->requestApplications(request);

    Request *request2 = new Request();
    request2->setType("请假");
    request2->setContent("小菜请假");
    request2->setNum(4);
    manager->requestApplications(request2);

    Request *request3 = new Request();
    request3->setType("加薪");
    request3->setContent("小菜请求加薪");
    request3->setNum(5000);
    manager->requestApplications(request3);

    Request *request4 = new Request();
    request4->setType("加薪");
    request4->setContent("小菜请求加薪");
    request4->setNum(10000);
    manager->requestApplications(request4);
    return 0;
}