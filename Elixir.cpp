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
            name = "复伤丹";
            addHp = 50;
            price = 70;
            desc = "具有一点的疗伤效果";
            break;
        }
        case 2:
        {
            name = "融灵丹";
            addHp = 100;
            price = 120;
            desc = "得灵魂与肉体融合地丹药，并能够使得灵魂力量快速回复，还能将灵魂曾经所受的创伤完全修复";
            break;
        }
        case 3:
        {
            name = "返命丹";
            addHp = 250;
            price = 200;
            desc = "只要不是被人直接砍掉了脑袋，或是直接震碎了心脏，那么此丹药就可以救人一命";
            break;
        }
        case 4:
        {
            name = "回气丹";
            addMp = 50;
            price = 50;
            desc = "快速恢复斗气";
            break;
        }
        case 5:
        {
            name = "养气散";
            addMp = 100;
            price = 120;
            desc = "用于使用密法提高功力后的气脉虚弱";
            break;
        }
        case 6:
        {
            name = "回春丹";
            addMp = 150;
            price = 200;
            desc = "一种回复斗气的丹药";
            break;
        }
        case 7:
        {
            name = "火菩丹";
            addMp = 200;
            price = 300;
            desc = "丹药呈青红色，能够治疗因火焰反噬而导致的后遗症";
            break;
        }
        case 8:
        {
            name = "筑基灵液";
            price = 50;
            addLv = 50;
            desc = "斗师以下使用，加速修炼效果";
            break;
        }
        case 9:
        {
            name = "破厄丹";
            price = 100;
            addLevel = 1;
            desc = "破除封印，并能有几率免除下次封印";
            break;
        }
        case 10:
        {
            name = "皇极丹";
            price = 200;
            addStar = 1;
            desc = "能够使得服下它的斗皇级别强者，提高1到2星级，一名斗皇，一生只能服用一枚皇极丹";
            break;
        }
        case 11:
        {
            name = "青灵丹";
            addAtt = 50;
            price = 80;
            desc = "四品丹药，内服药，丹药呈翠青色";
            break;
        }
        case 12:
        {
            name = "蓄力丸";
            addAtt = 100;
            price = 150;
            desc = "提高个人一定程度的力量";
            break;
        }
        case 13:
        {
            name = "护脉丹";
            addDef = 50;
            price = 100;
            desc = "保护脉络不受伤害";
            break;
        }
        case 14:
        {
            name = "血莲丹";
            addDef = 100;
            price = 200;
            desc = "可以在人体内形成血痂保护人体内外不受火焰的伤害";
            break;
        }
        case 15:
        {
            name = "噬生丹";
            addAtt = 200;
            addDef = 200;
            addHp = -300;
            price = 400;
            desc = "能让大斗师级别的人在极短时间内提高到斗王的水平，但使用者只有三年寿命";
            break;
        }
        case 16:
        {
            name = "天魂血骨丹";
            addHp = 60;
            addMp = 60;
            addDef = 60;
            addAtt = 60;
            addLv = 60;
            price = 350;
            desc = "内服药，丹药呈紫红色，具有改变体质，提高修炼天赋的霸道之效，具备夺天之能";
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
