#include <iostream>
#include <string>
#include <map>

using namespace std;

class PlayContext
{
private:
    string playText;

public:
    void setPlayText(string playText)
    {
        this->playText = playText;
    }
    string getPlayText()
    {
        return this->playText;
    }
};

class Expression
{
public:
    void interpret(PlayContext *context)
    {
        if (!context->getPlayText().empty())
        {
            std::string playKey = context->getPlayText().substr(0, 1);
            context->setPlayText(context->getPlayText().substr(2));

            size_t spacePos = context->getPlayText().find(' ');
            if (spacePos != std::string::npos)
            {
                std::string playValueStr = context->getPlayText().substr(0, spacePos);
                double playValue = std::stod(playValueStr);
                context->setPlayText(context->getPlayText().substr(spacePos + 1));

                this->execute(playKey, playValue);
            }
            else
            {
                // 处理没有空格的情况或错误情况
                std::cerr << "No space found in the play text." << std::endl;
            }
        }
    }

    // 执行
    virtual void execute(string key, double value) = 0;
};

class Note : public Expression
{
public:
    void execute(string key, double value)
    {
        // 音符映射表
        std::map<char, std::string> noteMap = {
            {'C', "1"},
            {'D', "2"},
            {'E', "3"},
            {'F', "4"},
            {'G', "5"},
            {'A', "6"},
            {'B', "7"}};

        // 查找键对应的音符
        auto it = noteMap.find(key[0]); // 假设key的第一个字符是有效的键
        if (it != noteMap.end())
        {
            std::string note = it->second; // 获取对应的音符
            std::cout << note << " ";      // 输出音符
        }
        else
        {
            std::cout << "Invalid key: " << key << std::endl;
        }

        // 在这个例子中，我们忽略了value参数，因为它在Java方法中没有使用
    }
};

class Scale : public Expression
{
public:
    void execute(string key, double value)
    {
        std::string scale = "";

        // 假设value是一个可以转换为整数的值，这里我们简单地将它转换为int
        int intValue = static_cast<int>(value);

        // 检查intValue是否在我们预期的范围内
        switch (intValue)
        {
        case 1:
            scale = "低音";
            break;
        case 2:
            scale = "中音";
            break;
        case 3:
            scale = "高音";
            break;
        // 可以添加default来处理不在预期范围内的值
        default:
            scale = "未知的音高";
            break;
        }

        std::cout << scale << " ";

        // 注意：在这个例子中，我们没有处理key参数，因为原Java代码也没有使用它
    }
};

class Speed : public Expression
{
public:
    void execute(string key, double value)
    {
        string speed;
        if (value < 500)
            speed = "快速";
        else if (value >= 1000)
            speed = "慢速";
        else
            speed = "中速";

        cout << speed << " " << endl;
    }
};

class ExpressionFactory
{
public:
    static Expression *createExpression(char type)
    {

        Expression *expression;
        switch (type)
        {
        case 'O':
            expression = new Scale();
            break;
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'A':
        case 'B':
        case 'P':
            expression = new Note();
            break;
        case 'T':
            expression = new Speed();
            break;
        }
        return expression;
    }
};

int main()
{
    PlayContext *context = new PlayContext();
    // 音乐-上海滩
    cout << "音乐-上海滩：" << endl;
    context->setPlayText("T 500 O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 ");

    while (!context->getPlayText().empty())
    {
        string str = context->getPlayText().substr(0, 1);
        char type = str.front();
        Expression *expression = ExpressionFactory::createExpression(type);
        expression->interpret(context);
    }
    return 0;
}