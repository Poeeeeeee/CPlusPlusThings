#include <iostream>

using namespace std;

class Trade
{
public:
    virtual void sell() = 0;
    virtual void buy() = 0;
};

class Stock1 : public Trade
{
public:
    // 卖股票
    void sell()
    {
        cout << "股票1卖出" << endl;
    }

    // 买股票
    void buy()
    {
        cout << "股票1买入" << endl;
    }
};

// 股票2
class Stock2 : public Trade
{

public:
    // 卖股票
    void sell()
    {
        cout << "股票2卖出" << endl;
    }

    // 买股票
    void buy()
    {
        cout << "股票2买入" << endl;
    }
};

// 国债1
class NationalDebt1 : public Trade
{
public:
    // 卖国债
    void sell()
    {
        cout << "国债1卖出" << endl;
    }

    // 买国债
    void buy()
    {
        cout << "国债1买入" << endl;
    }
};

// 房地产1
class Realty1 : public Trade
{
public:
    // 卖房地产
    void sell()
    {
        cout << "房地产1卖出" << endl;
    }

    // 买房地产
    void buy()
    {
        cout << "房地产1买入" << endl;
    }
};

class Fund
{
private:
    Stock1 *stock1;
    Stock2 *stock2;
    NationalDebt1 *nationalDebt1;
    Realty1 *realty1;

public:
    Fund()
    {
        this->stock1 = new Stock1();
        this->stock2 = new Stock2();
        this->nationalDebt1 = new NationalDebt1();
        this->realty1 = new Realty1();
    }
    void buyFund()
    {
        this->stock1->buy();
        this->stock2->buy();
        this->nationalDebt1->buy();
        this->realty1->buy();
    }
    void sellFund()
    {
        this->stock1->sell();
        this->stock2->sell();
        this->nationalDebt1->sell();
        this->realty1->sell();
    }
    ~Fund() {}
};

int main()
{
    Fund *fund = new Fund();
    fund->buyFund();
    fund->sellFund();
    return 0;
}