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
    desc = "萧家三公子，是家族百年内最年轻的斗者。因斗气尽失遭到未婚妻纳兰嫣"
           "然登门悔婚，萧炎一怒之下将其休去，并与其订下三年之约。萧炎一筹莫展之际，药"
           "老出现，拜药老为师，后天赋重展，开启了自己的传奇之路！";
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
    //已经完成了任务了
    if (task[taskId].getSymbol())
        taskId++;   //自动跳到下一个任务
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
        //判断使用丹药之后是否药品为空，为空则删除之
        this->bag.ifDeleteElixir();
        return true;
    }
    else
        return false;
}
//判断升级的情况
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
    cout << "当前人物属性:  " << endl;
    cout << "姓名：" << name << "  等级：" << levelGrade[level] << "  星级：" << star << endl;
    cout << "血量：" << HP << "/" << HP_MAX << "  体力：" << MP << "/" << MP_MAX << endl;
    cout << "攻击力：" << ATT << "  防御力：" << DEF << endl;
    cout << "金币：" << Gol << "  技能点数: " << Point << endl;
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
        cout << "\n你已经学习过该技能了" << endl;
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
    //查找背包里面是否已经存在该药品
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
                                                             FOREGROUND_GREEN);//设置红色和绿色相加
    if (!task[taskId].getTitle().empty())
    {
        cout << "*************************************\n";
        cout << "当前任务：" << task[taskId].getTitle() << endl;
        cout << "描述：" << task[taskId].getDesc() << endl;
        cout << "任务目标：" << task[taskId].getGoal() << endl;
        cout << "*************************************\n\n";
    }
    else
    {
        cout << "\n当前没有任何任务：\n\n" << endl;
    }
}
