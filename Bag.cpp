//
// Created by shineahead on 2022-08-21.
//
#include <iostream>
#include <windows.h>
#include<vector>
#include "Bag.h"
using namespace std;


Bag::Bag(){
    max_Elixir_num = 20;
    max_skills_num = 10;
}

Bag::~Bag(){}

int Bag::getMaxElixir()  //得到最大背包容量
{
    return max_Elixir_num;
}
void Bag::showElixir(int id)   //得到背包里编号为id的丹药信息
{
    int order = -1;
    for (Elixir e: bagElixir)
    {
        order++;
        if (e.getId() == id)
            break;
    }
    id = order;
    cout << bagElixir[id].getName() << ":" << bagElixir[id].getDesc() << endl;
    if (bagElixir[id].getAddAtt())
        cout << "增加的攻击力为：" << bagElixir[id].getAddAtt() << endl;
    if (bagElixir[id].getAddDef())
        cout << "增加的防御力为：" << bagElixir[id].getAddDef() << endl;
    if (bagElixir[id].getAddGrade())
        cout << "增加的等级为：" << bagElixir[id].getAddGrade() << endl;
    if (bagElixir[id].getAddStar())
        cout << "增加的星级为：" << bagElixir[id].getAddStar() << endl;
    if (bagElixir[id].getAddHp())
        cout << "增加的血量为：" << bagElixir[id].getAddHp() << endl;
    if (bagElixir[id].getAddMp())
        cout << "增加的体力值为：" << bagElixir[id].getAddMp() << endl;
    if (bagElixir[id].getAddLv())
        cout << "增加的经验值为：" << bagElixir[id].getAddLv() << endl;
    cout << "剩余的数量为：" << bagElixir[id].getNum() << endl;

}

bool Bag::ifUseElixir() //判断是否还有药可以使用

{
    if (bagElixir.empty())
        return false;
    else
        return true;
}
int Bag::getElixirNum(int id)  //得到背包里的丹药的数量
{

    return bagElixir.size();
}


//Bag& Bag::addGoods(int id, int type, int num) //往背包里面添加丹药
//{
//    int order = -1;
//    Elixir elixir(id);
//    //查找背包里面是否已经存在该药品
//    for (Elixir e: bagElixir)
//    {
//        if (e.getId() == id)
//            order = id;
//    }
//    if (order != -1)
//        bagElixir[order].setNum(num);
//    else
//    {
//        elixir.setNum(num);
//        bagElixir.push_back(elixir);
//    }
//    return *this;
//}
void Bag::reduceElixir(int id, int type, int num) //减少背包里面的丹药
{
    //使用丹药时减少之
    int order = -1;
    for (Elixir e: bagElixir)
    {
        order++;
        if (e.getId() == id)
            break;
    }
    id = order;
    bagElixir[id].setNum(-num);
    ifDeleteElixir();

}
void Bag::showBagSkills()  //展示所有的斗技
{
    if (bagSkills.empty())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n你还不会任何斗技!\n";
    }
    for (Skills s : bagSkills)
    {
        cout << s.getId() << ". " << s.getName() << ": " << s.getDesc() << endl;
    }
}

//bool Bag::addSkills(int id)   //往背包里面加斗技
//{
//    bool flag = true;
//    for (Skills s: bagSkills)
//    {
//        if (s.getId() == id)
//            flag = false;
//        else
//        {
//            bagSkills.push_back(s);
//        }
//    }
//    if (!flag)
//    {
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
//        cout << "\n已经学习过该技能了" << endl;
//        Sleep(1000);
//    }
//    return flag;
//}

void Bag::ifDeleteElixir()  //判断是否需要把丹药从背包中删除
{
    int id, num, order = -1;
    bool flag = true;
    for (Elixir e: bagElixir)
    {
        order++;
        if (e.getNum() <= 0)
        {
            flag = false;
        }
    }
    if (!flag)
    {
        auto it = bagElixir.begin() + order;
        bagElixir.erase(it);
    }
}
//重载运算符=
Bag& Bag::operator=(Bag const& b)
{
    this->max_Elixir_num = b.max_Elixir_num;
    this->max_skills_num = b.max_skills_num;
    for (const Elixir& e: b.bagElixir)
    {
        this->bagElixir.push_back(e);
    }
    for (const Skills& s: b.bagSkills)
    {
        this->bagSkills.push_back(s);
    }
}

void Bag::showBagElixir() {
    if (bagElixir.empty())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n背包中没有任何丹药!\n";
    }
    for (Elixir a : bagElixir)
    {
        cout << a.getId() << ". " << a.getName() << ": " << a.getDesc() << " 数量：" << a.getNum() << endl;
    }
}

void Bag::showSkill(int id) {
    int order = -1;
    for (Elixir e: bagElixir)
    {
        order++;
        if (e.getId() == id)
            break;
    }
    id = order;
    cout << bagSkills[id].getName() << ": " << bagSkills[id].getDesc() << endl;
    cout << "消耗的体力值为：" << bagSkills[id].getConsume() << endl;
    cout << "需要的技能点数为：" << bagSkills[id].getConPoint() << endl;
    if (bagSkills[id].getdecHp())
        cout << "造成的伤害值：" << bagSkills[id].getdecHp() << endl;
    if (bagSkills[id].getAddHp())
        cout << "恢复的血量值：" << bagSkills[id].getAddHp() << endl;
    if (bagSkills[id].getAddAtt())
        cout << "增加的攻击力：" << bagSkills[id].getAddAtt() << endl;
    if (bagSkills[id].getdecDef())
        cout << "减少对面的防御值：" << bagSkills[id].getdecDef() << endl;
    if (bagSkills[id].getdecAtt())
        cout << "减少对面的攻击力：" << bagSkills[id].getdecAtt() << endl;
    if (bagSkills[id].getAddDef())
        cout << "增加的防御值：" << bagSkills[id].getAddDef() << endl;

}

