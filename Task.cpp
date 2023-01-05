//
// Created by shineahead on 2022-08-22.
//

#include "Task.h"
#include<iostream>
using namespace std;

Task::Task() {}

Task::Task(int num)
{
    switch (num)
    {
        case 1:
        {
            title = "魔地深入";
            desc = "在魔兽山脉潜心修炼并击败一只怪兽";
            addLv = 100;
            addGol = 100;
            addPoint = 10;
            goal = "紫金翼狮王";
            break;
        }
        case 2:
        {
            title = "三年之约";
            desc = "前往云岚宗与纳兰嫣然进行三年之战并将其击败";
            addLv = 200;
            addGol = 300;
            addPoint = 15;
            goal = "纳兰嫣然";
            break;
        }
        case 3:
        {

            title = "塔戈尔沙漠遭遇";
            desc = "在塔戈尔沙漠遇到美杜莎，击败并收复青莲地心火";
            addLv = 150;
            addGol = 200;
            addPoint = 15;
            goal = "美杜莎";
            break;
        }
        case 4:
        {
            title = "星陨之炼";
            desc = "击败星陨阁的试炼者";
            addLv = 250;
            addGol = 500;
            addPoint = 15;
            goal = "云山";
            break;
        }
        case 5:
        {
            title = "终局之战";
            desc = "封印魂天帝";
            goal = "魂天帝";
            break;
        }
        default:
            break;
    }
}

Task::~Task()
{

}



Task& Task::operator=(Task const& task)
{
    this->id = task.id;
    this->addLv = task.addLv;
    this->desc = task.desc;
    this->addGol = task.addGol;
    this->addPoint = task.addPoint;
    this->title = task.title;
    this->symbol = task.symbol;
    this->goal = task.goal;
}

string Task::getTitle() {return this->title;}

string Task::getDesc() {return this->desc;}

string Task::getGoal() {return this->goal;}

int Task::getId() {return this->id;}

int Task::getAddGol() {return this->addGol;}

int Task::getAddLv() {return this->addLv;}

int Task::getAddPoint() {return this->addPoint;}

bool Task::getSymbol() {return this->symbol;}

void Task::showTask()
{
    cout <<  title << ":" << endl << desc << endl;
}

void Task::setTaskSymbol()
{
    symbol = true;
}

