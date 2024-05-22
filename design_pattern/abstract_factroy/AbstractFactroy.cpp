#include <iostream>
#include <string>
#include "GetConfig.h"

using namespace std;

class User;

class Department;

class User
{
private:
    string name;

public:
    User(string name)
    {
        this->name = name;
    };
    ~User() {}
    string getName()
    {
        return this->name;
    }
};

class Department
{
private:
    string depName;

public:
    Department(string depName)
    {
        this->depName = depName;
    };
    ~Department() {}
    string getDepName()
    {
        return this->depName;
    }
};

class IUser
{
public:
    virtual void insertUser(User *user) = 0;
    virtual User *getUser(int id) = 0;
};

class IDepartment
{
public:
    virtual void insertDepartment(Department *dep) = 0;
    virtual Department *getDepartment(int id) = 0;
};

class IFactroy
{
public:
    virtual IUser *createUser() = 0;
    virtual IDepartment *createDepartment() = 0;
};

class AccessUser : public IUser
{
public:
    void insertUser(User *user)
    {
        cout << "Access新增用户: " << user->getName() << endl;
    }
    User *getUser(int id)
    {
        cout << "Access根据id获取用户,id: " << id << endl;
        return new User("lisi");
    }
};

class SqlServerUser : public IUser
{
public:
    void insertUser(User *user)
    {
        cout << "SqlServer新增用户: " << user->getName() << endl;
    }
    User *getUser(int id)
    {
        cout << "SqlServer根据id获取用户,id: " << id << endl;
        return new User("zhangsan");
    }
};

class AccessDepartment : public IDepartment
{
public:
    void insertDepartment(Department *dep)
    {
        cout << "Access新增部门: " << dep->getDepName() << endl;
    }
    Department *getDepartment(int id)
    {
        cout << "Access根据id获取部门,id: " << id << endl;
        return new Department("it");
    }
};

class SqlServerDepartment : public IDepartment
{
public:
    void insertDepartment(Department *dep)
    {
        cout << "SqlServer新增部门: " << dep->getDepName() << endl;
    }
    Department *getDepartment(int id)
    {
        cout << "SqlServer根据id获取部门,id: " << id << endl;
        return new Department("rs");
    }
};

class AccessFactroy : public IFactroy
{
public:
    IUser *createUser()
    {
        return new AccessUser();
    };
    IDepartment *createDepartment()
    {
        return new AccessDepartment();
    }
};

class SqlServerFactroy : public IFactroy
{
public:
    IUser *createUser()
    {
        return new SqlServerUser();
    };
    IDepartment *createDepartment()
    {
        return new SqlServerDepartment();
    }
};

class Context
{
public:
    static IFactroy *createFactroy(int type)
    {
        IFactroy *factory;
        switch (type)
        {
        case 1:
            factory = new AccessFactroy();
            break;
        case 2:
            factory = new SqlServerFactroy();
            break;
        default:
            factory = new AccessFactroy();
            break;
        }
        return factory;
    }
};

int main()
{
    User *user = new User("李四");
    Department *department = new Department("科技部");

    IFactroy *factory = Context::createFactroy(1);
    IUser *iuser = factory->createUser();
    iuser->insertUser(user);
    User *u = iuser->getUser(1);
    cout << "用户:" << u->getName() << endl;

    IDepartment *idepartment = factory->createDepartment();
    idepartment->insertDepartment(department);
    Department *d = idepartment->getDepartment(2);
    cout << "部门:" << d->getDepName() << endl;

    cout << endl;
    cout << "**********************************************" << endl;
    return 0;
}