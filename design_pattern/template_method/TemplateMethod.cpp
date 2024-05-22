#include <iostream>

using namespace std;

class TestPaper
{
public:
    // 试题1
    void testQuestion1()
    {
        cout << " 杨过得到，后来给了郭靖，炼成倚天剑、屠龙刀的玄铁可能是[ ] \n a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << endl;
        cout << "答案：" << this->answer1() << endl;
    };
    // 试题2
    void testQuestion2()
    {
        cout << " 杨过、程英、陆无双铲除了情花，造成[ ] \n a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化  " << endl;
        cout << "答案：" << this->answer2() << endl;
    };
    // 试题3
    void testQuestion3()
    {
        cout << " 蓝凤凰致使华山师徒、桃谷六仙呕吐不止,如果你是大夫,会给他们开什么药[ ] \n a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对   " << endl;
        cout << "答案：" << this->answer3() << endl;
    }

protected:
    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

// 学生甲答的试卷
class TestPaperA : public TestPaper
{
protected:
    // 试题1
    string answer1()
    {
        return "b";
    }
    // 试题2
    string answer2()
    {
        return "a";
    }
    // 试题3
    string answer3()
    {
        return "c";
    }
};

// 学生乙答的试卷
class TestPaperB : public TestPaper
{

protected:
    // 试题1
    string answer1()
    {
        return "d";
    }
    // 试题2
    string answer2()
    {
        return "b";
    }
    // 试题3
    string answer3()
    {
        return "a";
    }
};

int main()
{
    cout << "学生甲写的试卷：" << endl;
    TestPaper *studentA = new TestPaperA();
    studentA->testQuestion1();
    studentA->testQuestion2();
    studentA->testQuestion3();

    cout<<endl;

    cout << "学生乙写的试卷：" << endl;
    TestPaper *studentB = new TestPaperB();
    studentB->testQuestion1();
    studentB->testQuestion2();
    studentB->testQuestion3();
    return 0;
}