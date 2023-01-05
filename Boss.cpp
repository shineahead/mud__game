//
// Created by shineahead on 2022-08-21.
//

#include "Boss.h"
#include <windows.h>
#include<iostream>
using namespace std;

Boss::Boss(int id)
{
    this->id = id;
    switch (id)
    {
        case 1:
        {
            name = "�Ͻ���ʨ��";
            Hp = 200;
            Hp_max = 200;
            Def = 50;
            Att = 50;
            AddGol = 200;
            AddLv = 100;
            AddPoint = 2;
            desc = "����ħ�ޣ������൱��Ҳ���Ƕ��ʼ���Ĵ��ڡ�";
            break;
        }
        case 2:
        {
            name = "�ĺ�����";
            Hp = 250;
            Hp_max = 250;
            Att = 50;
            Def = 50;
            AddGol = 200;
            AddLv = 110;
            AddPoint = 2;
            desc = "����۹����ػ����ޣ�ʵ��Ҳ�����ס�";
            break;
        }
        case 3:
        {
            name = "������߻�";
            Hp = 300;
            Hp_max = 300;
            Att = 50;
            Def = 50;
            AddGol = 200;
            AddLv = 120;
            AddPoint = 2;
            desc = "����ħ�ޣ��൱�ڶ����۷塣";
            break;
        }
        case 4:
        {
            name = "������";
            Hp = 350;
            Hp_max = 350;
            Att = 75;
            Def = 50;
            AddGol = 300;
            AddLv = 130;
            AddPoint = 2;
            desc = "�߽�ħ�ޣ��Ա�ʵ���ڶ��Ƕ������ҡ�";
            Skills boss_skill(17);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 5:
        {
            name = "�ɽ�����";
            Hp = 400;
            Hp_max = 400;
            Att = 75;
            Def = 75;
            AddGol = 400;
            AddLv = 140;
            AddPoint = 3;
            desc = "���߽�ħ�ޣ��൱���������Ƕ���ǿ�ߵ�ʵ����";
            Skills boss_skill(18);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 6:
        {
            name = "���ĵ�ڤ��";
            Hp = 450;
            Hp_max = 450;
            Att = 100;
            Def = 75;
            AddGol = 400;
            AddLv = 150;
            AddPoint = 3;
            desc = "Զ�����ߵĺ��ᣬΪħ�������ͷ֮һ���Դ�������һ�������涾������ʴ�Ķ�����";
            Skills boss_skill(19);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 7:
        {
            name = "��Ѭ��";
            Hp = 500;
            Hp_max = 500;
            Def = 100;
            Att = 100;
            AddGol = 450;
            AddLv = 160;
            AddPoint = 4;
            desc = "��޹��ԭ���й�Ѭ����Զ�Ű�������峤��Ԫ��Ů����ӵ�н�۷����ף������������ģ������������շ���������";
            Skills boss_skill(20);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 8:
        {
            name = "������Ȼ";
            Hp = 600;
            Hp_max = 600;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 170;
            AddPoint = 4;
            desc = "������Ȼ�������������������С������ָ��Ϊ�飬��������ʵ���½������������ף������Ե���ȡ����Լ";
            Skills boss_skill1(19);
            Skills boss_skill2(18);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 9:
        {
            name = "̫�����";
            Hp = 700;
            Hp_max = 700;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 180;
            AddPoint = 4;
            desc = "ħ�����繫�ϵ���ǿ���壬�������˵�ʳ��ó�ʹ�ÿռ�֮�����������޿ռ������ɴ��󣬲������н�������Ϣ���������׻�˵�������ײ���β������һ�������͵���һ���˺��Ѽ������ǡ�";
            Skills boss_skill1(19);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 10:
        {
            name = "Զ������";
            Hp = 800;
            Hp_max = 800;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 190;
            AddPoint = 4;
            desc = "����ħ�޵����棬����ϡ�٣��������壬����Σ�ա�";
            Skills boss_skill1(17);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 11:
        {
            name = "Զ�����";
            Hp = 900;
            Hp_max = 900;
            Att = 100;
            Def = 100;
            AddGol = 500;
            AddLv = 200;
            AddPoint = 4;
            desc = "�����˵����ȣ�Ѫ���������ܺ�̫�����һ�忹�⡣��������Ѫ������ʧ�������Ѿ��ڶ�����½��ʧ��";
            Skills boss_skill1(21);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 12:
        {
            name = "����";
            Hp = 1000;
            Hp_max = 1000;
            Att = 100;
            Def = 100;
            AddGol = 500;
            AddLv = 210;
            AddPoint = 4;
            desc = "��̫���������Զ������������˱�Դ������������Ѫ�������������һ�壬����ħ���е��컨�塣��˵������һ�����ֹ���Σ����������һ�岻��˭������������һ��ͻᱻ��ȫѹ�ơ�";
            Skills boss_skill1(19);
            Skills boss_skill2(22);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 13:
        {
            name = "����ɯ";
            Hp = 2000;
            Hp_max = 2000;
            Att = 100;
            Def = 50;
            AddGol = 500;
            AddLv = 220;
            AddPoint = 5;
            desc = "���붷ʥǿ���࿹���Զ�����ޣ��������ı�־�����������߲ʣ���ͫ���ϣ����巺������ͨ�죡";
            Skills boss_skill1(21);
            Skills boss_skill2(23);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 14:
        {
            name = "��ɽ";
            Hp = 3000;
            Hp_max = 3000;
            Att = 100;
            Def = 100;
            AddGol = 1000;
            AddLv = 230;
            AddPoint = 5;
            desc = "�����ǰ���������չض����ڻ��İ����³�Ϊ����ǿ�ߣ����ǳ�ʵ��Ϊһ�Ƕ��ڣ�����ʵ��Ϊ���Ƕ��ڡ�";
            Skills boss_skill1(22);
            Skills boss_skill2(23);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 15:
        {
            name = "�����";
            Hp = 5000;
            Hp_max = 5000;
            Att = 200;
            Def = 150;
            AddGol = 1000;
            AddLv = 240;
            AddPoint = 10;
            desc = "Զ�Ű�������峤��ԭΪ���Ƕ�ʥ�۷�ʵ������������Ϊ��������Ϊ�ϣ����Ϊ������Ϊ��������Ʒ��������Ϊ��Ʒ�۵����������ۡ����ԺŻ�ۣ����ձ��׵�����������Ĵ�������ӡ��    һϮ���ۣ�����ȥ���Ķ��ţ�ʵ��Ϊ���ĺ�������С�Ľ��������²����ֶΣ����������׵������ˡ�";
            Skills boss_skill1(24);
            Skills boss_skill2(25);
            Skills boss_skill3(26);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            bossSkills.push_back(boss_skill3);
            break;
        }
        default:
            break;
    }
}

Boss::~Boss() {}

int Boss::getHp()
{
    return this->Hp;
}


int Boss::getMp()
{
    return this->Mp;
}
int Boss::getDef()
{
    return this->Def;
}
int Boss::getAtt()
{
    return this->Att;
}
int Boss::getAddGol()
{
    return this->AddGol;
}
int Boss::getAddLv()
{
    return this->AddLv;
}
int Boss::getAddPoint()
{
    return this->AddPoint;
}

Boss& Boss::operator=(Boss const&b)
{
    Hp = b.Hp;
    Mp = b.Mp;
    Def = b.Def;
    Att = b.Att;
    AddGol = b.AddGol;
    AddLv = b.AddLv;
    AddPoint = b.AddPoint;
    name = b.name;
    desc = b.desc;
    bossSkills = b.bossSkills;
}

string Boss::getName()
{
    return this->name;
}

string Boss::getDesc() {
    return this->desc;
}

int Boss::getHp_max()
{
    return this->Hp_max;
}

void Boss::showBoss()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << "*************************************\n";
    cout << "��ǰҰ������:  " << endl;
    cout << "���ƣ�" << name << " ������" << desc << endl;
    cout << "Ѫ����" << Hp << "/" << Hp_max;
    cout << "  ��������" << Att << "  ��������" << Def << endl;
    cout << "*************************************\n";
}

int Boss::getId() {
    return this->id;
}
