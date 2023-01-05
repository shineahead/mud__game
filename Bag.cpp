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

int Bag::getMaxElixir()  //�õ���󱳰�����
{
    return max_Elixir_num;
}
void Bag::showElixir(int id)   //�õ���������Ϊid�ĵ�ҩ��Ϣ
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
        cout << "���ӵĹ�����Ϊ��" << bagElixir[id].getAddAtt() << endl;
    if (bagElixir[id].getAddDef())
        cout << "���ӵķ�����Ϊ��" << bagElixir[id].getAddDef() << endl;
    if (bagElixir[id].getAddGrade())
        cout << "���ӵĵȼ�Ϊ��" << bagElixir[id].getAddGrade() << endl;
    if (bagElixir[id].getAddStar())
        cout << "���ӵ��Ǽ�Ϊ��" << bagElixir[id].getAddStar() << endl;
    if (bagElixir[id].getAddHp())
        cout << "���ӵ�Ѫ��Ϊ��" << bagElixir[id].getAddHp() << endl;
    if (bagElixir[id].getAddMp())
        cout << "���ӵ�����ֵΪ��" << bagElixir[id].getAddMp() << endl;
    if (bagElixir[id].getAddLv())
        cout << "���ӵľ���ֵΪ��" << bagElixir[id].getAddLv() << endl;
    cout << "ʣ�������Ϊ��" << bagElixir[id].getNum() << endl;

}

bool Bag::ifUseElixir() //�ж��Ƿ���ҩ����ʹ��

{
    if (bagElixir.empty())
        return false;
    else
        return true;
}
int Bag::getElixirNum(int id)  //�õ�������ĵ�ҩ������
{

    return bagElixir.size();
}


//Bag& Bag::addGoods(int id, int type, int num) //������������ӵ�ҩ
//{
//    int order = -1;
//    Elixir elixir(id);
//    //���ұ��������Ƿ��Ѿ����ڸ�ҩƷ
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
void Bag::reduceElixir(int id, int type, int num) //���ٱ�������ĵ�ҩ
{
    //ʹ�õ�ҩʱ����֮
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
void Bag::showBagSkills()  //չʾ���еĶ���
{
    if (bagSkills.empty())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n�㻹�����κζ���!\n";
    }
    for (Skills s : bagSkills)
    {
        cout << s.getId() << ". " << s.getName() << ": " << s.getDesc() << endl;
    }
}

//bool Bag::addSkills(int id)   //����������Ӷ���
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
//        cout << "\n�Ѿ�ѧϰ���ü�����" << endl;
//        Sleep(1000);
//    }
//    return flag;
//}

void Bag::ifDeleteElixir()  //�ж��Ƿ���Ҫ�ѵ�ҩ�ӱ�����ɾ��
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
//���������=
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
        cout << "\n������û���κε�ҩ!\n";
    }
    for (Elixir a : bagElixir)
    {
        cout << a.getId() << ". " << a.getName() << ": " << a.getDesc() << " ������" << a.getNum() << endl;
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
    cout << "���ĵ�����ֵΪ��" << bagSkills[id].getConsume() << endl;
    cout << "��Ҫ�ļ��ܵ���Ϊ��" << bagSkills[id].getConPoint() << endl;
    if (bagSkills[id].getdecHp())
        cout << "��ɵ��˺�ֵ��" << bagSkills[id].getdecHp() << endl;
    if (bagSkills[id].getAddHp())
        cout << "�ָ���Ѫ��ֵ��" << bagSkills[id].getAddHp() << endl;
    if (bagSkills[id].getAddAtt())
        cout << "���ӵĹ�������" << bagSkills[id].getAddAtt() << endl;
    if (bagSkills[id].getdecDef())
        cout << "���ٶ���ķ���ֵ��" << bagSkills[id].getdecDef() << endl;
    if (bagSkills[id].getdecAtt())
        cout << "���ٶ���Ĺ�������" << bagSkills[id].getdecAtt() << endl;
    if (bagSkills[id].getAddDef())
        cout << "���ӵķ���ֵ��" << bagSkills[id].getAddDef() << endl;

}

