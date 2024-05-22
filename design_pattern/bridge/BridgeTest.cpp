#include <iostream>
#include <string>

using namespace std;

class MobilePhoneSoftware
{
public:
    virtual void run() = 0;
};

class MobileGame : public MobilePhoneSoftware
{
public:
    void run()
    {
        cout << "mobile game running" << endl;
    }
};

class MobileMusic : public MobilePhoneSoftware
{
public:
    void run()
    {
        cout << "mobile music running" << endl;
    }
};

class MobileAudio : public MobilePhoneSoftware
{
public:
    void run()
    {
        cout << "mobile audio running" << endl;
    }
};

class MobileBrand
{
protected:
    MobilePhoneSoftware *software;
    string name;

public:
    virtual void softRun() = 0;
};

class HuaWeiBrand : public MobileBrand
{
public:
    void softRun()
    {
        cout << this->name << " ";
        this->software->run();
    }
    void setSoftware(MobilePhoneSoftware *software)
    {
        this->software = software;
    }
    HuaWeiBrand(string name)
    {
        this->name = name;
    }
};

class AppleBrand : public MobileBrand
{
public:
    void softRun()
    {
        cout << this->name << " ";
        this->software->run();
    }
    void setSoftware(MobilePhoneSoftware *software)
    {
        this->software = software;
    }
    AppleBrand(string name)
    {
        this->name = name;
    }
};

class VivoBrand : public MobileBrand
{
public:
    void softRun()
    {
        cout << this->name << " ";
        this->software->run();
    }
    void setSoftware(MobilePhoneSoftware *software)
    {
        this->software = software;
    }
    VivoBrand(string name)
    {
        this->name = name;
    }
};

int main()
{
    HuaWeiBrand *huawei = new HuaWeiBrand("huawei");
    huawei->setSoftware(new MobileGame());
    huawei->softRun();
    AppleBrand *apple = new AppleBrand("apple");
    apple->setSoftware(new MobileMusic());
    apple->softRun();
    VivoBrand *vivo = new VivoBrand("vivo");
    vivo->setSoftware(new MobileAudio());
    vivo->softRun();
    return 0;
}