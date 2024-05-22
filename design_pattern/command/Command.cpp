#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Command;
class Executor;

class Executor
{
public:
    void doOneThing()
    {
        cout << "do one thing" << endl;
    }
    void doOrtherThing()
    {
        cout << "do orther thing" << endl;
    }
};

class Command
{
protected:
    Executor *excutor;

public:
    virtual void executeCommand() = 0;
};

class OneThing : public Command
{
public:
    OneThing(Executor *excutor)
    {
        this->excutor = excutor;
    }
    void executeCommand()
    {
        this->excutor->doOneThing();
    }
};

class OrtherThing : public Command
{
public:
    OrtherThing(Executor *excutor)
    {
        this->excutor = excutor;
    }
    void executeCommand()
    {
        this->excutor->doOrtherThing();
    }
};

class Context
{
private:
    vector<Command *> commands;

public:
    void addCommand(Command *command)
    {
        this->commands.push_back(command);
    }
    void removeCommand(Command *commandToRemove)
    {
        auto it = find(commands.begin(), commands.end(), commandToRemove);
        if (it != commands.end())
        {
            commands.erase(it);
        }
    }
    void notifyCommands()
    {
        for (auto command : commands)
        {
            if (command)
            {
                command->executeCommand();
            }
        }
    }
};

int main()
{
    Executor *excutor = new Executor();
    Command *comand1 = new OneThing(excutor);
    Command *comand2 = new OrtherThing(excutor);
    Context *context = new Context();

    context->addCommand(comand1);
    context->addCommand(comand1);
    context->addCommand(comand1);
    context->addCommand(comand2);
    context->removeCommand(comand1);

    context->notifyCommands();
}