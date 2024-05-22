#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class ISale
{
public:
    virtual double acceptCash(double price, int num) = 0;
};

class CashSuper : public ISale
{
protected:
    ISale *component;

public:
    void decorate(ISale *comp)
    {
        component = comp;
    }
    double acceptCash(double price, int num)
    {
        double result = 0.0;

        if (component != nullptr)
        {
            result = component->acceptCash(price, num);
        }

        return result;
    }
};

class CashNormal : public CashSuper
{
public:
    double acceptCash(double price, int num)
    {
        return price * num;
    }
};

class CashRebate : public CashSuper
{
private:
    double moneyRebate = 1.0;

public:
    double acceptCash(double price, int num)
    {
        double result = price * num * moneyRebate;
        return CashSuper::acceptCash(result, 1);
    }
    CashRebate(double moneyRebate)
    {
        this->moneyRebate = moneyRebate;
    }
    ~CashRebate() {}
};

class CashReturn : public CashSuper
{
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;

public:
    double acceptCash(double price, int num)
    {
        double result = price * num;
        if (moneyCondition > 0 && result >= moneyCondition)
        {
            result = result - floor(result / moneyCondition) * moneyReturn;
        }
        return CashSuper::acceptCash(result, 1);
    }
    CashReturn(double moneyCondition, double moneyReturn)
    {
        this->moneyCondition = moneyCondition;
        this->moneyReturn = moneyReturn;
    }
    ~CashReturn() {}
};

class CashContext
{
private:
    ISale *cs;

public:
    CashContext(int cashType)
    {
        switch (cashType)
        {
        case 1:
            this->cs = new CashNormal();
            break;
        case 2:
            this->cs = new CashRebate(0.8);
            break;
        case 3:
            this->cs = new CashRebate(0.7);
            break;
        case 4:
            this->cs = new CashReturn(300, 100);
            break;
        case 5:
        {
            // 先打8折,再满300返100
            CashNormal *normal1 = new CashNormal();
            CashReturn *ret1 = new CashReturn(300, 100);
            CashRebate *rebate1 = new CashRebate(0.8);
            ret1->decorate(normal1);
            rebate1->decorate(ret1);
            this->cs = rebate1;
            break;
        }
        case 6:
        {
            // 先满200返50，再打7折
            CashNormal *normal2 = new CashNormal();
            CashRebate *rebate2 = new CashRebate(0.7);
            CashReturn *ret2 = new CashReturn(200, 50);
            rebate2->decorate(normal2);
            ret2->decorate(rebate2);
            this->cs = ret2;
            break;
        }
        }
    }
    ~CashContext() {}
    double getResult(double price, int num)
    {
        return this->cs->acceptCash(price, num);
    }
};

int main()
{
    int discount = 0;       // 商品折扣模式(1.正常收费 2.打八折 3.打七折 4.满300送100 5.先8折，再满300送100 6.先满200返50，再打7折)
    double price = 0;       // 商品单价
    int num = 0;            // 商品购买数量
    double totalPrices = 0; // 当前商品合计费用
    double total = 0;       // 总计所有商品费用

    do
    {
        cout << "请输入商品折扣模式(1.正常收费 2.打八折 3.打七折 4.满300送100 5.先8折,再满300送100 6.先满200返50,再打7折):" << endl;
        cin >> discount;
        cout << "请输入商品单价：" << endl;
        cin >> price;
        cout << "请输入商品数量：" << endl;
        cin >> num;
        cout << endl;
        if (price > 0 && num > 0)
        {
            // 根据用户输入，将对应的策略对象作为参数传入CashContext对象中
            CashContext *cc = new CashContext(discount);

            // 通过Context的getResult方法的调用，可以得到收取费用的结果
            // 让具体算法与客户进行了隔离
            totalPrices = cc->getResult(price, num);

            total += totalPrices;
            cout << endl;
            cout << "单价：" << price << "元 数量：" << num << " 合计：" << totalPrices << "元" << endl;
            cout << endl;
            cout << "总计：" << total << "元" << endl;
            cout << endl;
        }
    } while (price > 0 && num > 0);

    return 0;
}