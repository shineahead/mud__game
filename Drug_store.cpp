//
// Created by shineahead on 2022-08-22.
//

#include "Drug_store.h"
#include<iostream>
#include <windows.h>
using namespace std;
//把所有的丹药初始化好
DrugStore::DrugStore(Role *role1): role(role1)
{
    //初始化默认丹药
    for (int i = 1; i <= 16; i++)
    {
        Elixir e(i);
        storeElixir.push_back(e);
    }
}

DrugStore::~DrugStore()
{

}


void DrugStore::showElixir()
{
    system("cls");
    for (int i = 0; i < 16; i++)
    {
        cout << i+1 << "." << storeElixir[i].getName() <<":"
             << storeElixir[i].getDesc() << " ";
        if (storeElixir[i].getAddHp())
            cout << "血量值:" << storeElixir[i].getAddHp() << " 售价:";
        if (storeElixir[i].getAddMp())
            cout << "体力值:" << storeElixir[i].getAddMp() << " 售价:";
        if (storeElixir[i].getAddLv())
            cout << "经验值:" << storeElixir[i].getAddLv() << " 售价:";
        if (storeElixir[i].getAddAtt())
            cout << "攻击力:" << storeElixir[i].getAddAtt() << " 售价:";
        if (storeElixir[i].getAddDef())
            cout << "防御力:" << storeElixir[i].getAddDef() << " 售价:";
        if (storeElixir[i].getAddStar())
            cout << "星级提升:" << storeElixir[i].getAddStar() << " 售价:";
        if (storeElixir[i].getAddGrade())
            cout << "等级提升:" << storeElixir[i].getAddGrade() << " 售价:";
        cout << storeElixir[i].getPrice() << "金币" << endl << endl;
    }
}

bool DrugStore::buyElixir(int id, int num)
{
    Elixir e(id);
    if (e.getPrice() * num > role->getGol())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n金币不够！" << endl;
        Sleep(2000);
        return false;
    }
    else if(id > storeElixir.size())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n请输入正确的ID！" << endl;
        Sleep(2000);
        return false;
    }
    else
    {
        role->addGoods(id, 1, num);
        //花费的金币
        role->Gol -= Elixir(id).getPrice() * num;
        return true;
    }
}
//输出一些选择信息
void DrugStore::deal() {
    //先展示所有的信息
    int id, num;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "\n请输入要购买的丹药id和数量，用空格隔开(输入0 0退出选择)" << endl;
    cin >> id >> num;
    if (id == 0)
        return;
    if (buyElixir(id, num))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << endl << endl << "购买成功！" << endl;
        Sleep(2000);
    }
}
