//
// Created by shineahead on 2022-08-20.
//

#include "Elixir.h"

Elixir::Elixir() {}

Elixir::Elixir(int id): id(id)
{   
    switch (id)
    {
        case 1:
        {
            name = "���˵�";
            addHp = 50;
            price = 70;
            desc = "����һ�������Ч��";
            break;
        }
        case 2:
        {
            name = "���鵤";
            addHp = 100;
            price = 120;
            desc = "������������ںϵص�ҩ�����ܹ�ʹ������������ٻظ������ܽ�����������ܵĴ�����ȫ�޸�";
            break;
        }
        case 3:
        {
            name = "������";
            addHp = 250;
            price = 200;
            desc = "ֻҪ���Ǳ���ֱ�ӿ������Դ�������ֱ�����������࣬��ô�˵�ҩ�Ϳ��Ծ���һ��";
            break;
        }
        case 4:
        {
            name = "������";
            addMp = 50;
            price = 50;
            desc = "���ٻָ�����";
            break;
        }
        case 5:
        {
            name = "����ɢ";
            addMp = 100;
            price = 120;
            desc = "����ʹ���ܷ���߹��������������";
            break;
        }
        case 6:
        {
            name = "�ش���";
            addMp = 150;
            price = 200;
            desc = "һ�ֻظ������ĵ�ҩ";
            break;
        }
        case 7:
        {
            name = "���е�";
            addMp = 200;
            price = 300;
            desc = "��ҩ�����ɫ���ܹ���������淴�ɶ����µĺ���֢";
            break;
        }
        case 8:
        {
            name = "������Һ";
            price = 50;
            addLv = 50;
            desc = "��ʦ����ʹ�ã���������Ч��";
            break;
        }
        case 9:
        {
            name = "�ƶ�";
            price = 100;
            addLevel = 1;
            desc = "�Ƴ���ӡ�������м�������´η�ӡ";
            break;
        }
        case 10:
        {
            name = "�ʼ���";
            price = 200;
            addStar = 1;
            desc = "�ܹ�ʹ�÷������Ķ��ʼ���ǿ�ߣ����1��2�Ǽ���һ�����ʣ�һ��ֻ�ܷ���һö�ʼ���";
            break;
        }
        case 11:
        {
            name = "���鵤";
            addAtt = 50;
            price = 80;
            desc = "��Ʒ��ҩ���ڷ�ҩ����ҩ�ʴ���ɫ";
            break;
        }
        case 12:
        {
            name = "������";
            addAtt = 100;
            price = 150;
            desc = "��߸���һ���̶ȵ�����";
            break;
        }
        case 13:
        {
            name = "������";
            addDef = 50;
            price = 100;
            desc = "�������粻���˺�";
            break;
        }
        case 14:
        {
            name = "Ѫ����";
            addDef = 100;
            price = 200;
            desc = "�������������γ�Ѫ�豣���������ⲻ�ܻ�����˺�";
            break;
        }
        case 15:
        {
            name = "������";
            addAtt = 200;
            addDef = 200;
            addHp = -300;
            price = 400;
            desc = "���ô�ʦ��������ڼ���ʱ������ߵ�������ˮƽ����ʹ����ֻ����������";
            break;
        }
        case 16:
        {
            name = "���Ѫ�ǵ�";
            addHp = 60;
            addMp = 60;
            addDef = 60;
            addAtt = 60;
            addLv = 60;
            price = 350;
            desc = "�ڷ�ҩ����ҩ���Ϻ�ɫ�����иı����ʣ���������츳�İԵ�֮Ч���߱�����֮��";
            break;
        }
        default:break;
    }
}

Elixir::~Elixir() {}

int Elixir::getAddHp()
{
    return addHp;
}

int Elixir::getAddMp()
{
    return addMp;
}

int Elixir::getAddLv()
{
    return addLv;
}

int Elixir::getAddAtt()
{
    return addAtt;
}

int Elixir::getAddDef()
{
    return addDef;
}

int Elixir::getPrice()
{
    return price;
}

int Elixir::getAddGrade()
{
    return addLevel;
}

int Elixir::getAddStar()
{
    return addStar;
}

int Elixir::getId(){
    return this->id;
}

int Elixir::getNum()
{
    return num;
}

string Elixir::getName()
{
    return name;
}

string Elixir::getDesc()
{
    return desc;
}

int Elixir::setNum(int num)
{
    this->num += num;
}

Elixir& Elixir::operator=(Elixir const& e)
{
    this->price = e.price;
    this->addHp = e.addMp;
    this->name = e.name;
    this->num = e.num;
    this->addMp = e.addMp;
    this->addDef = e.addDef;
    this->addAtt = e.addAtt;
    this->desc = e.desc;
    this->addLv = e.addLv;
    this->addLevel = e.addLevel;
    this->addStar = e.addStar;

}
