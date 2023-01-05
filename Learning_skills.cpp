//
// Created by shineahead on 2022-08-22.
//

#include "Learning_skills.h"
#include<iostream>
#include <windows.h>
using namespace std;

Learning_skills::Learning_skills(Role *role1):role(role1)
{
    for (int i = 1; i <= 16; i++)
    {
        Skills s(i);
        storeSkills.push_back(s);
    }
}

Learning_skills::~Learning_skills() {}

void Learning_skills::showSkills()
{
    system("cls");
    for (int i = 0; i < 16; i++)
    {
        cout << i+1 << "." << storeSkills[i].getName() <<":"
             << storeSkills[i].getDesc() << " ";
        if (storeSkills[i].getdecHp())
            cout << "造成伤害:" << storeSkills[i].getdecHp() << " ";
        if (storeSkills[i].getdecDef())
            cout << "减少对方防御:" << storeSkills[i].getdecDef() << " ";
        if (storeSkills[i].getAddHp())
            cout << "回复血量:" << storeSkills[i].getAddHp() << " ";
        if (storeSkills[i].getAddDef())
            cout << "增加己方防御:" << storeSkills[i].getAddDef() << " ";
        if (storeSkills[i].getAddAtt())
            cout << "增加己方攻击力:" << storeSkills[i].getAddAtt() << " ";
        if (storeSkills[i].getdecAtt())
            cout << "减少对面攻击力:" << storeSkills[i].getdecAtt() << " ";
        cout << "所需技能点数:" << storeSkills[i].getConPoint() << endl << endl;
    }
}

bool Learning_skills::learnSkills(int id) {
    Skills skill(id);
    if (role->getPoint() < skill.getConPoint())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n技能点数不够！" << endl;
        Sleep(2000);
        return false;
    }
    else if(id > storeSkills.size() || id < 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n请输入正确的ID！" << endl;
        Sleep(2000);
        return false;
    }
    else
        return role->addSkills(id);
}

void Learning_skills::deal() {
    //先展示所有的信息
    int id;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << endl << "输入想学的技能编号(输入0退出选择)" << endl;
    cin >> id;
    if (id == 0)
        return;
    if (learnSkills(id))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "学习成功！" << endl;
        role->Point -= Skills(id).getConPoint();
        Sleep(2000);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "学习失败！" << endl;
        Sleep(2000);
    }
}





