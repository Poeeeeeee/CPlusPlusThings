#include <iostream>

using namespace std;

class Work;

class MorningState;

class State
{
public:
    virtual void handle(Work *work) = 0;
};

class Work
{
private:
    State *state;
    double current_time;
    bool work_finished = false;

public:
    Work(double cur_time, State *initialState = nullptr)
    {
        this->current_time = cur_time;
        if (initialState)
        {
            this->state = initialState;
        }
    }
    void setState(State *state)
    {
        this->state = state;
    }
    State *getState()
    {
        return this->state;
    }
    void setCurrentTime(double hour)
    {
        this->current_time = hour;
    }
    double getCurrentTime()
    {
        return this->current_time;
    }
    void setWorkFinished()
    {
        this->work_finished = true;
    }
    bool getWorkFinished()
    {
        return this->work_finished;
    }
    void handle()
    {
        state->handle(this);
    }
};

class SleepState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        cout << "现在是" << cur_time << "点," << "睡了" << endl;
    }
};

class RestState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        if (cur_time < 23.0)
        {
            cout << "现在是" << cur_time << "点," << "下班回家了" << endl;
        }
        else
        {
            work->setState(new SleepState());
            work->handle();
        }
    }
};

class AddWorkState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        bool isFinished = work->getWorkFinished();
        if (isFinished)
        {
            work->setState(new RestState());
            work->handle();
        }
        else
        {
            if (cur_time < 21.0)
            {
                cout << "现在是" << cur_time << "点," << "加班中" << endl;
            }
            else
            {
                work->setState(new RestState());
                work->handle();
            }
        }
    }
};

class EveningState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        bool isFinished = work->getWorkFinished();
        if (cur_time >= 18.0 && cur_time <= 21.0)
        {
            if (isFinished)
            {
                work->setState(new RestState());
            }
            else
            {
                work->setState(new AddWorkState());
            }
            work->handle();
        }
        else if (cur_time >= 21.0)
        {
            work->setState(new RestState());
            work->handle();
        }
    }
};

class AfterNoonState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        if (14.0 <= cur_time && cur_time <= 18.0)
        {
            cout << "现在是下午" << cur_time << "点," << "继续努力" << endl;
        }
        else
        {
            work->setState(new EveningState());
            work->handle();
        }
    }
};
class NoonState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        if (12.0 <= cur_time && cur_time <= 14.0)
        {
            cout << "现在是中午" << cur_time << "点," << "吃饭休息了" << endl;
        }
        else
        {
            work->setState(new AfterNoonState());
            work->handle();
        }
    }
};
class MorningState : public State
{
public:
    void handle(Work *work)
    {
        double cur_time = work->getCurrentTime();
        if (9.0 <= cur_time && cur_time <= 12.0)
        {
            cout << "现在是上午" << cur_time << "点," << "精神饱满" << endl;
        }
        else
        {
            work->setState(new NoonState());
            work->handle();
        }
    }
};

int main()
{
    Work *emergencyProjects = new Work(9, new MorningState());
    emergencyProjects->setCurrentTime(9);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(10);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(12);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(13);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(14);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(17);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(19);
    emergencyProjects->handle();
    emergencyProjects->setWorkFinished();
    emergencyProjects->setCurrentTime(20);
    emergencyProjects->handle();
    emergencyProjects->setCurrentTime(24);
    emergencyProjects->handle();
    return 0;
}