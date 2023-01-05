//
// Created by shineahead on 2022-08-22.
//

#include "Drug_store.h"
#include<iostream>
#include <windows.h>
using namespace std;
//�����еĵ�ҩ��ʼ����
DrugStore::DrugStore(Role *role1): role(role1)
{
    //��ʼ��Ĭ�ϵ�ҩ
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
            cout << "Ѫ��ֵ:" << storeElixir[i].getAddHp() << " �ۼ�:";
        if (storeElixir[i].getAddMp())
            cout << "����ֵ:" << storeElixir[i].getAddMp() << " �ۼ�:";
        if (storeElixir[i].getAddLv())
            cout << "����ֵ:" << storeElixir[i].getAddLv() << " �ۼ�:";
        if (storeElixir[i].getAddAtt())
            cout << "������:" << storeElixir[i].getAddAtt() << " �ۼ�:";
        if (storeElixir[i].getAddDef())
            cout << "������:" << storeElixir[i].getAddDef() << " �ۼ�:";
        if (storeElixir[i].getAddStar())
            cout << "�Ǽ�����:" << storeElixir[i].getAddStar() << " �ۼ�:";
        if (storeElixir[i].getAddGrade())
            cout << "�ȼ�����:" << storeElixir[i].getAddGrade() << " �ۼ�:";
        cout << storeElixir[i].getPrice() << "���" << endl << endl;
    }
}

bool DrugStore::buyElixir(int id, int num)
{
    Elixir e(id);
    if (e.getPrice() * num > role->getGol())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n��Ҳ�����" << endl;
        Sleep(2000);
        return false;
    }
    else if(id > storeElixir.size())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n��������ȷ��ID��" << endl;
        Sleep(2000);
        return false;
    }
    else
    {
        role->addGoods(id, 1, num);
        //���ѵĽ��
        role->Gol -= Elixir(id).getPrice() * num;
        return true;
    }
}
//���һЩѡ����Ϣ
void DrugStore::deal() {
    //��չʾ���е���Ϣ
    int id, num;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "\n������Ҫ����ĵ�ҩid���������ÿո����(����0 0�˳�ѡ��)" << endl;
    cin >> id >> num;
    if (id == 0)
        return;
    if (buyElixir(id, num))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << endl << endl << "����ɹ���" << endl;
        Sleep(2000);
    }
}
