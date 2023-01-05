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
            cout << "����˺�:" << storeSkills[i].getdecHp() << " ";
        if (storeSkills[i].getdecDef())
            cout << "���ٶԷ�����:" << storeSkills[i].getdecDef() << " ";
        if (storeSkills[i].getAddHp())
            cout << "�ظ�Ѫ��:" << storeSkills[i].getAddHp() << " ";
        if (storeSkills[i].getAddDef())
            cout << "���Ӽ�������:" << storeSkills[i].getAddDef() << " ";
        if (storeSkills[i].getAddAtt())
            cout << "���Ӽ���������:" << storeSkills[i].getAddAtt() << " ";
        if (storeSkills[i].getdecAtt())
            cout << "���ٶ��湥����:" << storeSkills[i].getdecAtt() << " ";
        cout << "���輼�ܵ���:" << storeSkills[i].getConPoint() << endl << endl;
    }
}

bool Learning_skills::learnSkills(int id) {
    Skills skill(id);
    if (role->getPoint() < skill.getConPoint())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n���ܵ���������" << endl;
        Sleep(2000);
        return false;
    }
    else if(id > storeSkills.size() || id < 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n��������ȷ��ID��" << endl;
        Sleep(2000);
        return false;
    }
    else
        return role->addSkills(id);
}

void Learning_skills::deal() {
    //��չʾ���е���Ϣ
    int id;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << endl << "������ѧ�ļ��ܱ��(����0�˳�ѡ��)" << endl;
    cin >> id;
    if (id == 0)
        return;
    if (learnSkills(id))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "ѧϰ�ɹ���" << endl;
        role->Point -= Skills(id).getConPoint();
        Sleep(2000);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "ѧϰʧ�ܣ�" << endl;
        Sleep(2000);
    }
}





