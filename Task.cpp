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
            title = "ħ������";
            desc = "��ħ��ɽ��Ǳ������������һֻ����";
            addLv = 100;
            addGol = 100;
            addPoint = 10;
            goal = "�Ͻ���ʨ��";
            break;
        }
        case 2:
        {
            title = "����֮Լ";
            desc = "ǰ���������������Ȼ��������֮ս���������";
            addLv = 200;
            addGol = 300;
            addPoint = 15;
            goal = "������Ȼ";
            break;
        }
        case 3:
        {

            title = "�����ɳĮ����";
            desc = "�������ɳĮ��������ɯ�����ܲ��ո��������Ļ�";
            addLv = 150;
            addGol = 200;
            addPoint = 15;
            goal = "����ɯ";
            break;
        }
        case 4:
        {
            title = "����֮��";
            desc = "�������ɸ��������";
            addLv = 250;
            addGol = 500;
            addPoint = 15;
            goal = "��ɽ";
            break;
        }
        case 5:
        {
            title = "�վ�֮ս";
            desc = "��ӡ�����";
            goal = "�����";
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

