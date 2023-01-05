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
            name = "八极崩";
            desc = "近身攻击斗技，以攻击力强横著称，炼至大成，攻击暗含八重劲气。";
            decHp = 50;
            conPoint = 4;
            consume = 20;
            break;
        }
        case 2:
        {
            name = "吸掌";
            desc = "炼至大成，可吸千斤巨石，若是遇敌，狂猛吸力，能将人体血液，强行扯出。";
            decHp = 50;
            addHp = 50;
            conPoint = 7;
            consume = 35;
            break;
        }
        case 3:
        {
            name = "狮虎碎金吟";
            desc = "狮虎齐啸，万兽臣服，有碎金震魂之大威能。";
            decHp = 100;
            conPoint = 8;
            consume = 50;
            break;
        }
        case 4:
        {
            name = "焰分噬浪尺";
            desc = "大成劈山断浪。";
            decHp = 50;
            conPoint = 4;
            consume = 20;
            break;
        }
        case 5:
        {
            name = "帝印决";
            desc = "五印合一，威力巨大。";
            decHp = 150;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 6:
        {
            name = "佛怒火莲";
            desc = "通过多种火焰相融产生强大的破坏力，火莲的威力随融合火焰种类多少变化。";
            decHp = 200;
            conPoint = 15;
            consume = 80;
            break;
        }
        case 7:
        {
            name = "大天造化掌";
            desc = "造化圣者融合百家武学所创，讲究造化之意，以掌破天，以力碎万物。手掌需要被金灵涎淬炼方能使出，否则必遭反噬。";
            decHp = 150;
            addHp = -100;
            conPoint = 10;
            consume = 50;
            break;
        }
        case 8:
        {
            name = "金刚琉璃身";
            desc = "琉璃圣者所创，以身化金刚琉璃，无锋能破，无坚不摧，此技炼至大成，化金刚琉璃身，九丈九尺，乃为极致，金光耀世，拳可崩天，脚可裂地。";
            addDef = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 9:
        {
            name = "龙凰古甲";
            desc = "太虚古龙一族的防御技能，龙鳞衣的最高等级，普天之下防御力最强悍的护甲之一。";
            addDef = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 10:
        {
            name = "三千雷幻身";
            desc = "风雷阁镇阁之宝。远古流传而下的斗技，此法修成，能凝雷幻身，雷幻身实力与本体相仿，本体不死，幻身不灭。";
            addDef = 200;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 11:
        {
            name = "大地罡炎";
            desc = "将自身斗气传入大地，创造极度炽热的劲气浆流，出其不意自对手立脚大地之处喷射而出，无声无息间给人以致命攻击。";
            addHp = -100;
            addAtt = 150;
            conPoint = 10;
            consume = 70;
            break;
        }
        case 12:
        {
            name = "龙鳞衣";
            desc = "太虚古龙一族的防御技能.";
            addDef = 100;
            conPoint = 10;
            consume = 60;
            break;
        }
        case 13:
        {
            name = "五轮离火法";
            desc = "控火法诀，功分五重，按兽形而辨，狼，豹，狮，虎，蛟，每一重分有各自火灵，法诀大成，五兽齐聚，可成五轮离火阵，有蒸海焚天之莫大威能。";
            addAtt = 150;
            conPoint = 12;
            consume = 60;
            break;
        }
        case 14:
        {
            name = "黄泉天怒";
            desc = "声波斗技，萧炎由九幽地冥蟒族黄泉石碑中接下黄泉妖圣残魂的灵魂攻击而获得，黄泉妖圣当年闻名之技，与黄泉指和黄泉掌有“黄泉指，断生死，黄泉怒，碎人魂”之说。";
            decHp = 150;
            conPoint = 12;
            consume = 80;
            break;
        }
        case 15:
        {
            name = "风之极陨杀";
            desc = "攻击斗技，云山曾凭借此技击杀两位斗皇。";
            decHp = 100;
            conPoint = 10;
            consume = 40;
            break;
        }
        case 16:
        {
            name = "风之极落日曜";
            desc = "攻击斗技，威力巨大";
            decHp = 150;
            conPoint = 15;
            consume = 70;
            break;
        }
        case 17:
        {
            name = "蛇灵";
            decHp = 50;
            break;
        }   
        case 18:    
        {
            name = "风壁";
            desc = "天空中狂风猛然大振，生成一道几乎是横跨了半个天空的深青色巨大风墙。";
            addDef = 50;
            break;
        }
        case 19:
        {
            name = "万风缠缚";
            desc = "手掌对着敌人一握，涌现出无数由狂风汇聚而成的实质风绳，在虚空穿梭间将敌人缚绑。";
            decHp = 50;
            break;
        }
        case 20:
        {
            name = "残影";
            desc = "身体分化出两道拥有斗皇级的残影，残影具备云山的智慧，但抗打击能力较差。";
            addDef = 100;
            addAtt = 100;
            break;
        }
        case 21:
        {
            name = "大风手印";
            desc = "双手结营，右手挥出一道近几丈高的能量手印。";
            decHp = 75;
            break;
        }
        case 22:
        {
            name = "大悲撕风手";
            desc = "一只几丈高的能量大手从掌心浮现，带着凶悍劲风向敌人怒拍而下。";
            decHp = 125;
            break;
        }
        case 23:
        {
            name = "风刹湮罡";
            desc = "风属性斗气聚于头顶，凝聚成一柄足有丈许宽大的青色长剑。随着手印变换，长剑疯狂旋转，向着敌人暴掠而出。";
            decHp = 150;
            break;
        }
        case 24:
        {
            name = "血魔蚀心雷";
            desc = "依靠着血色云雷中所积蓄的能量，攻击力极强。";
            decHp = 150;
            break;
        }
        case 25:
        {
            name = "斩帝鬼血刃";
            desc = "此招乃是远古时期，魂族斗帝所遗留下来的斗技，据说，在曾经斩杀过斗帝强者，听到这里，也可以想象得出此招的威力之大，不同凡响。";
            decHp = 300;
            break;
        }
        case 26 :
        {
            name = "血之帝身";
            desc = "斗帝强者都有属于自己的万丈帝身。萧炎的是炎之帝身、而魂天帝的则是血之帝身。只是帝身之间也有等级区分。";
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