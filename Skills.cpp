//
// Created by shineahead on 2022-08-20.
//

#include "Skills.h"
Skills::Skills(){}
Skills::Skills(int id) 
{
    this->id = id;
    switch (id)
    {
        case 1:
        {
            name = "�˼���";
            desc = "�������������Թ�����ǿ�����ƣ�������ɣ������������ؾ�����";
            decHp = 50;
            conPoint = 4;
            consume = 20;
            break;
        }
        case 2:
        {
            name = "����";
            desc = "������ɣ�����ǧ���ʯ���������У������������ܽ�����ѪҺ��ǿ�г�����";
            decHp = 50;
            addHp = 50;
            conPoint = 7;
            consume = 35;
            break;
        }
        case 3:
        {
            name = "ʨ�������";
            desc = "ʨ����Х�����޳�������������֮�����ܡ�";
            decHp = 100;
            conPoint = 8;
            consume = 50;
            break;
        }
        case 4:
        {
            name = "������˳�";
            desc = "�����ɽ���ˡ�";
            decHp = 50;
            conPoint = 4;
            consume = 20;
            break;
        }
        case 5:
        {
            name = "��ӡ��";
            desc = "��ӡ��һ�������޴�";
            decHp = 150;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 6:
        {
            name = "��ŭ����";
            desc = "ͨ�����ֻ������ڲ���ǿ����ƻ������������������ںϻ���������ٱ仯��";
            decHp = 200;
            conPoint = 15;
            consume = 80;
            break;
        }
        case 7:
        {
            name = "�����컯��";
            desc = "�컯ʥ���ںϰټ���ѧ�����������컯֮�⣬�������죬���������������Ҫ�������Ѵ�������ʹ����������ⷴ�ɡ�";
            decHp = 150;
            addHp = -100;
            conPoint = 10;
            consume = 50;
            break;
        }
        case 8:
        {
            name = "���������";
            desc = "����ʥ����������������������޷����ƣ��޼᲻�ݣ��˼�������ɣ���������������ɾųߣ���Ϊ���£����ҫ����ȭ�ɱ��죬�ſ��ѵء�";
            addDef = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 9:
        {
            name = "���˹ż�";
            desc = "̫�����һ��ķ������ܣ������µ���ߵȼ�������֮�·�������ǿ���Ļ���֮һ��";
            addDef = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 10:
        {
            name = "��ǧ�׻���";
            desc = "���׸����֮����Զ���������µĶ������˷��޳ɣ������׻����׻���ʵ���뱾����£����岻����������";
            addDef = 200;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 11:
        {
            name = "������";
            desc = "�������������أ����켫�ȳ��ȵľ������������䲻���Զ������Ŵ��֮�����������������Ϣ�����������������";
            addHp = -100;
            addAtt = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 12:
        {
            name = "������";
            desc = "̫�����һ��ķ�������.";
            addDef = 100;
            conPoint = 10;
            consume = 60;
            break;
        }
        case 13:
        {
            name = "�������";
            desc = "�ػ𷨾����������أ������ζ��棬�ǣ�����ʨ�������ԣ�ÿһ�ط��и��Ի��飬������ɣ�������ۣ��ɳ��������������������֮Ī�����ܡ�";
            addAtt = 150;
            conPoint = 12;
            consume = 60;
            break;
        }
        case 14:
        {
            name = "��Ȫ��ŭ";
            desc = "���������������ɾ��ĵ�ڤ�����Ȫʯ���н��»�Ȫ��ʥ�л����깥������ã���Ȫ��ʥ��������֮�������Ȫָ�ͻ�Ȫ���С���Ȫָ������������Ȫŭ�����˻ꡱ֮˵��";
            decHp = 150;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 15:
        {
            name = "��֮����ɱ";
            desc = "������������ɽ��ƾ��˼���ɱ��λ���ʡ�";
            decHp = 100;
            conPoint = 10;
            consume = 40;
            break;
        }
        case 16:
        {
            name = "��֮��������";
            desc = "���������������޴�";
            decHp = 150;
            conPoint = 15;
            consume = 70;
            break;
        }
        case 17:
        {
            name = "����";
            decHp = 50;
            break;
        }   
        case 18:    
        {
            name = "���";
            desc = "����п����Ȼ��������һ�������Ǻ���˰����յ�����ɫ�޴��ǽ��";
            addDef = 50;
            break;
        }
        case 19:
        {
            name = "������";
            desc = "���ƶ��ŵ���һ�գ�ӿ�ֳ������ɿ���۶��ɵ�ʵ�ʷ���������մ���佫���˸���";
            decHp = 50;
            break;
        }
        case 20:
        {
            name = "��Ӱ";
            desc = "����ֻ�������ӵ�ж��ʼ��Ĳ�Ӱ����Ӱ�߱���ɽ���ǻۣ�������������ϲ";
            addDef = 100;
            addAtt = 100;
            break;
        }
        case 21:
        {
            name = "�����ӡ";
            desc = "˫�ֽ�Ӫ�����ֻӳ�һ�������ɸߵ�������ӡ��";
            decHp = 75;
            break;
        }
        case 22:
        {
            name = "��˺����";
            desc = "һֻ���ɸߵ��������ִ����ĸ��֣������׺����������ŭ�Ķ��¡�";
            decHp = 125;
            break;
        }
        case 23:
        {
            name = "��ɲ���";
            desc = "�����Զ�������ͷ�������۳�һ���������������ɫ������������ӡ�任�����������ת�����ŵ��˱��Ӷ�����";
            decHp = 150;
            break;
        }
        case 24:
        {
            name = "Ѫħʴ����";
            desc = "������Ѫɫ���������������������������ǿ��";
            decHp = 150;
            break;
        }
        case 25:
        {
            name = "ն�۹�Ѫ��";
            desc = "��������Զ��ʱ�ڣ����嶷�������������Ķ�������˵��������նɱ������ǿ�ߣ��������Ҳ��������ó����е�����֮�󣬲�ͬ���졣";
            decHp = 300;
            break;
        }
        case 26 :
        {
            name = "Ѫ֮����";
            desc = "����ǿ�߶��������Լ������ɵ������׵�����֮����������۵�����Ѫ֮����ֻ�ǵ���֮��Ҳ�еȼ����֡�";
            addHp = 500;
            addAtt = 200;
            addDef = 200;
            break;
        }
    }
}

int Skills::getId()
{
    return this->id;
}

int Skills::getConsume()
{
    return consume;
}

int Skills::getAddDef()
{
    return addDef;
}

int Skills::getAddHp()
{
    return addHp;
}

int Skills::getAddAtt()
{
    return addAtt;
}

string Skills::getName()
{
    return name;
}

string Skills::getDesc()
{
    return desc;
}

int Skills::getdecDef()
{
    return decDef;
}
int Skills::getdecHp()
{
    return decHp;
}
int Skills::getdecAtt()
{
    return decAtt;
}

int Skills::getConPoint()
{
    return conPoint;
}

Skills::~Skills() {}

Skills& Skills::operator=(Skills const&s)
{
    this->id = s.id;
    this->consume = s.consume;
    this->conPoint = s.conPoint;
    this->decHp = s.conPoint;
    this->addHp = s.addHp;
    this->addDef = s.addDef;
    this->addAtt = s.addAtt;
    this->decAtt = s.decAtt;
    this->decDef = s.decDef;
    this->name = s.name;
    this->desc = s.desc;
}