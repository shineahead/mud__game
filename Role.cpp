//
// Created by shineahead on 2022-08-20.
//

#include "Role.h"
#include<windows.h>
#include<iostream>
using namespace std;

extern map<int, string> levelGrade;
extern int exp_level[9];
extern void Declaration();

Role::Role()
{
    taskId = 1;
    HP = 210;
    HP_MAX = 210;
    MP = 50;
    MP_MAX = 50;
    LV = 0;
    ATT = 70;
    ATT_MAX = 70;
    DEF = 30;
    DEF_MAX = 30;
    Gol = 0;
    Point = 0;
    level = 1;
    star = 1;
    desc = "���������ӣ��Ǽ��������������Ķ��ߡ�������ʧ�⵽δ����������"
           "Ȼ���Żڻ飬����һŭ֮�½�����ȥ�������䶩������֮Լ������һ��Īչ֮�ʣ�ҩ"
           "�ϳ��֣���ҩ��Ϊʦ�����츳��չ���������Լ��Ĵ���֮·��";
    for (int i = 1; i <= 5; i++)
        task[i] = Task(i);
}

Role::~Role(){}

int Role::getMp() {return this->HP;}

int Role::getHp() {return this->MP;}

int Role::getAtt() {return this->ATT;}

int Role::getLv() {return this->LV;}

int Role::getLevel() {return this->level;}

int Role::getStar() {return this->star;}

int Role::getDef() {return this->DEF;}

int Role::getGol() {return this->Gol;}

string Role::getName() {return this->name;}

string Role::getDesc() {return this->desc;}

int Role::getPoint() {return this->Point;}

bool Role::ifComTask()
{
    //�Ѿ������������
    if (task[taskId].getSymbol())
        taskId++;   //�Զ�������һ������
}

int Role::getTaskId()
{
    return taskId;
}

Role& Role::operator=(Role const&r)
{
    this->HP = r.HP;
    this->bag = r.bag;
    this->taskId = r.taskId;
    this->level = r.level;
    this->star = r.star;
    this->MP = r.MP;
    this->LV = r.LV;
    this->ATT = r.ATT;
    this->DEF = r.DEF;
    this->Gol = r.Gol;
    this->Point = r.Point;
    this->name = r.name;
    this->desc = r.desc;
    this->HP_MAX = r.HP_MAX;
    this->MP_MAX = r.MP_MAX;
    this->ATT_MAX = r.ATT_MAX;
    this->DEF_MAX = r.DEF_MAX;
    for (int i = 1; i <= 5; i++)
        this->task[i] = r.task[i];
}

bool Role::reduceElixir(int id, int type, int num)
{
    Elixir e(this->bag.bagElixir[id]);
    int getNum = this->bag.bagElixir[id].getNum();
    if (getNum >= num)
    {
        num = -num;
        this->bag.bagElixir[id].setNum(num);
        //�ж�ʹ�õ�ҩ֮���Ƿ�ҩƷΪ�գ�Ϊ����ɾ��֮
        this->bag.ifDeleteElixir();
        return true;
    }
    else
        return false;
}
//�ж����������
void Role::impLevel(){
    Declaration();
    if (LV >= exp_level[level])
    {
        while (LV >= exp_level[level])
        {
            if (star >= 3)
            {
                level++;
                star = 0;
            }
            LV -= exp_level[level];
            star++;
            ATT += 15;
            ATT_MAX += 15;
            MP += 10;
            HP += 30;
            HP_MAX += 30;
            MP_MAX += 10;
            DEF += 10;
            DEF_MAX += 15;
        }
    }
}

void Role::showRole()
{
    cout << "*************************************\n";
    cout << "��ǰ��������:  " << endl;
    cout << "������" << name << "  �ȼ���" << levelGrade[level] << "  �Ǽ���" << star << endl;
    cout << "Ѫ����" << HP << "/" << HP_MAX << "  ������" << MP << "/" << MP_MAX << endl;
    cout << "��������" << ATT << "  ��������" << DEF << endl;
    cout << "��ң�" << Gol << "  ���ܵ���: " << Point << endl;
    cout << "*************************************\n\n";
}

bool Role::addSkills(int id) {
    bool flag = true;
    Skills skill(id);
    for (Skills s: bag.bagSkills)
    {
        if (s.getId() == id)
            flag = false;
    }
    if (!flag)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n���Ѿ�ѧϰ���ü�����" << endl;
        Sleep(1000);
    }
    else
    {
        bag.bagSkills.push_back(skill);
    }
    return flag;
}

void Role::addGoods(int id, int type, int num) {
    int order = -1;
    Elixir elixir(id);
    //���ұ��������Ƿ��Ѿ����ڸ�ҩƷ
    for (Elixir e: bag.bagElixir)
    {
        if (e.getId() == id)
            order = id;
    }
    if (order != -1)
        bag.bagElixir[order].setNum(num);
    else
    {
        elixir.setNum(num);
        bag.bagElixir.push_back(elixir);
    }
}

void Role::showTask()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);//���ú�ɫ����ɫ���
    if (!task[taskId].getTitle().empty())
    {
        cout << "*************************************\n";
        cout << "��ǰ����" << task[taskId].getTitle() << endl;
        cout << "������" << task[taskId].getDesc() << endl;
        cout << "����Ŀ�꣺" << task[taskId].getGoal() << endl;
        cout << "*************************************\n\n";
    }
    else
    {
        cout << "\n��ǰû���κ�����\n\n" << endl;
    }
}
