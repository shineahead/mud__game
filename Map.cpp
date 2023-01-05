//
// Created by shineahead on 2022-08-21.
//
#include<iostream>
#include<windows.h>
#include<map>
#include<string>
#include "Map.h"
using namespace std;
Map::Map() {
    NameSet.insert(make_pair(make_pair(0, 0) , "��̹��"));
    NameSet.insert(make_pair(make_pair(1, 0), "ħ��ɽ��"));
    NameSet.insert(make_pair(make_pair(1, 1), "����۹�"));
    NameSet.insert(make_pair(make_pair(2, 1), "�����"));
    NameSet.insert(make_pair(make_pair(3, 1), "�����ɳĮ"));
    NameSet.insert(make_pair(make_pair(2, 2), "����ѧԺ"));
    NameSet.insert(make_pair(make_pair(2, 3), "���ɸ�"));
    NameSet.insert(make_pair(make_pair(3, 3), "���ӹ�"));
    NameSet.insert(make_pair(make_pair(3, 0), "����"));
    NameSet.insert(make_pair(make_pair(2, 4), "���"));
    px = 0;
    py = 0;

    //̸���ص�
    ChatPlace.insert(make_pair("���ɸ�",true));
    ChatPlace.insert(make_pair("�����",true));
    ChatPlace.insert(make_pair("����",true));
    ChatPlace.insert(make_pair("���",true));

    //ս���ص�
    CanFight.insert(make_pair("ħ��ɽ��", true));
    CanFight.insert(make_pair("����۹�", true));
    CanFight.insert(make_pair("�����", true));
    CanFight.insert(make_pair("�����ɳĮ", true));
    CanFight.insert(make_pair("����ѧԺ", true));
    CanFight.insert(make_pair("���ɸ�", true));
    CanFight.insert(make_pair("���ӹ�", true));
    CanFight.insert(make_pair("����", true));
    CanFight.insert(make_pair("���", true));

    //����ص�
    TaskPlace.insert(make_pair("ħ��ɽ��", 1));
    TaskPlace.insert(make_pair("�����", 2));
    TaskPlace.insert(make_pair("�����ɳĮ", 3));
    TaskPlace.insert(make_pair("���ɸ�", 4));
    TaskPlace.insert(make_pair("���", 5));

    //ÿ���ط��Ĺ���
    vector<Boss> v1;
    v1.emplace_back(Boss(1));
    v1.emplace_back(Boss(2));
    v1.emplace_back(Boss(3));
    monster.insert(make_pair("ħ��ɽ��", v1));
    //����Ѭ��֮ս֮��
    vector<Boss> v2;
    v2.emplace_back(Boss(7));
    monster.insert(make_pair("����", v2));
    //��������Ȼս��֮��
    vector<Boss> v3;
    v3.emplace_back(Boss(8));   //������Ȼ
    v3.emplace_back(Boss(11));
    monster.insert(make_pair("�����", v3));
    //����۹�
    vector<Boss> v4;
    v4.emplace_back(Boss(4));
    v4.emplace_back(Boss(6));
    v4.emplace_back(Boss(13));  //����ɯ
    monster.insert(make_pair("����۹�", v4));
    //�����ɳĮ
    vector<Boss> v5;
    v5.emplace_back(Boss(4));
    v5.emplace_back(Boss(5));
    monster.insert(make_pair("�����ɳĮ", v5));
    //����ѧԺ
    vector<Boss> v6;
    v6.emplace_back(Boss(9));
    v6.emplace_back(Boss(10));
    monster.insert(make_pair("����ѧԺ", v6));
    //���ɸ�
    vector<Boss> v7;
    v7.emplace_back(Boss(14));
    monster.insert(make_pair("���ɸ�", v7));
    //���ӹ�
    vector<Boss> v8;
    v8.emplace_back(Boss(11));
    v8.emplace_back(Boss(12));
    monster.insert(make_pair("���ӹ�", v8));
    //���
    vector<Boss> v9;
    v9.emplace_back(Boss(15));
    monster.insert(make_pair("���", v9));

    //��ͼ�Ի���Ϣ
    inf["����"] = "\n\tѬ�������׸�磬����֮Լ�������٣����������������д��д��!\n\t���ף��ð������ӣ����ÿ���������ʵ����ΰ�!";
    inf["�����"] = "\n\t���ף�����֮Լ�������ˣ�ս�ɣ�\n\t������Ȼ�����ף���ȷʵ���ˣ�����������ǰ�Ǹ����ҷ�����ү��\n\t������Ȼ���Ҵ�δ���ǹ�����ǰ��д�µ����飬Ҳ��δ���ǹ�����֮���Լ����\n\t������Ȼ�����ף����ǲ�����սʤ�ҵģ�����ǰ��ˣ�����Ҳ��ˣ�";
    inf["���ɸ�"] = "\n\tҩ�ϣ����ף����ɸ�󶥻���ǳ�֮��������������\n\t���ף��õģ���ʦ��";
    inf["���"] = "\n\t����ۣ����ף����ѽ��붷�ۣ�����������½�������һ�����ˣ�\n\t���ף��������ɲ�ֹ��һ�˽�����˶��ۣ�\n\t��������𣬷�ӡ��ǧ��������";

}
Map::~Map()
{

}

bool Map::ifCanChat()  //�ж��Ƿ��ܶԻ��������Ƿ��Ѿ��Թ��������޷��Ի�
{
    string tname = NameSet[ make_pair( px,py )];    //��ǰ��ͼ������
    if (ChatPlace[tname])
        return true;
    else
        return false;
}

bool Map::ifCanFight()  //�ж��Ƿ���ս��
{
    string tname = NameSet[ make_pair( px,py )];
    if (CanFight[tname])
        return true;
    else
        return false;
}

void Map::showMap()     //��ӡ��ͼ
{
    cout << "������½��ͼ:" << endl;
    cout << " __________________________            _____________ " << endl;
    cout << "|            |            |            |            |" << endl;
    cout << "|   ��̹��   |  ħ��ɽ��  |            |    ����  |" << endl;
    cout << "|____________|____________|____________|____________|" << endl;
    cout << "             |            |            |            |" << endl;
    cout << "             |   ����۹� |   �����   |  �����ɳĮ|" << endl;
    cout << "             |____________|____________|____________|" << endl;
    cout << "                          |            |             " << endl;
    cout << "                          |  ����ѧԺ  |             " << endl;
    cout << "                          |____________|____________ " << endl;
    cout << "                          |            |            |" << endl;
    cout << "                          |   ���ɸ�   |   ���ӹ�   |" << endl;
    cout << "                          |____________|____________|" << endl;
    cout << "                          |            |             " << endl;
    cout << "                          |    ���    |             " << endl;
    cout << "                          |____________|             " << endl;
    //cout << "�����ڵ�λ��Ϊ" << mapName[position] << endl;
}

void Map::enterMap(string const&name)    //�����ͼ,ͨ��px��py����λ������ĵ�ͼ
{
    if ( !NameSet[ make_pair(px, py) ].empty() )
    {
        cout << "�����ͼ......" << endl;
        Sleep(1000);
        //�������ĶԻ�
        if (ChatPlace[name])
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//���ú�ɫ����ɫ���
            for (char c: inf[name])
            {
                cout << c;
                Sleep(20);
            }
            Sleep(1500);
            //���Ϊ�Ѿ��Թ���
            ChatPlace[name] = false;
        }
    }
}

void Map::showPrePos()  //չʾ��ǰ�ط�����Ϣ����������ЩҰ�ֻ�������
{
    string name = NameSet[make_pair(px, py)];
    cout << inf[name];
    system("cls");
    cout << "��ǰ�ص㣺" << name << endl << endl;
    if (CanFight[name])
    {
        cout << "���Խ���ս���������У�" << endl;
        for (Boss b: monster[name])
        {
            cout << b.getName() << ": " << b.getDesc() << endl;
        }
        cout << endl << endl;
    }
    else
        cout << "��ǰ�ص�û��ս�����Է���" << endl << endl << endl;
}

void Map::Move(char order)    //�����ƶ�����,ͨ��idֱ�ӽ���õط�
{
    switch (order)
    {
        case 'w': py -= 1;break;
        case 'a': px -= 1;break;
        case 's': py += 1;break;
        case 'd': px += 1;break;
        default:break;
    }
}

