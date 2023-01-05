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
            name = "紫金翼狮王";
            Hp = 200;
            Hp_max = 200;
            Def = 50;
            Att = 50;
            AddGol = 200;
            AddLv = 100;
            AddPoint = 2;
            desc = "六阶魔兽，在人类当中也就是斗皇级别的存在。";
            break;
        }
        case 2:
        {
            name = "幽海蛟兽";
            Hp = 250;
            Hp_max = 250;
            Att = 50;
            Def = 50;
            AddGol = 200;
            AddLv = 110;
            AddPoint = 2;
            desc = "加玛帝国的守护神兽，实力也在六阶。";
            break;
        }
        case 3:
        {
            name = "八翼黑蛇皇";
            Hp = 300;
            Hp_max = 300;
            Att = 50;
            Def = 50;
            AddGol = 200;
            AddLv = 120;
            AddPoint = 2;
            desc = "六阶魔兽，相当于斗皇巅峰。";
            break;
        }
        case 4:
        {
            name = "苍狼王";
            Hp = 350;
            Hp_max = 350;
            Att = 75;
            Def = 50;
            AddGol = 300;
            AddLv = 130;
            AddPoint = 2;
            desc = "七阶魔兽，对标实力在二星斗宗左右。";
            Skills boss_skill(17);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 5:
        {
            name = "噬金鼠王";
            Hp = 400;
            Hp_max = 400;
            Att = 75;
            Def = 75;
            AddGol = 400;
            AddLv = 140;
            AddPoint = 3;
            desc = "是七阶魔兽，相当于人类七星斗宗强者的实力。";
            Skills boss_skill(18);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 6:
        {
            name = "九幽地冥蟒";
            Hp = 450;
            Hp_max = 450;
            Att = 100;
            Def = 75;
            AddGol = 400;
            AddLv = 150;
            AddPoint = 3;
            desc = "远古天蛇的后裔，为魔兽三大巨头之一，自带天下数一数二的奇毒“帝蟒蚀心毒”。";
            Skills boss_skill(19);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 7:
        {
            name = "萧熏儿";
            Hp = 500;
            Hp_max = 500;
            Def = 100;
            Att = 100;
            AddGol = 450;
            AddLv = 160;
            AddPoint = 4;
            desc = "萧薰儿原名叫古熏儿，远古八族古族族长古元的女儿，拥有金帝焚天炎，异火榜排名第四，曾帮助萧炎收服净莲妖火";
            Skills boss_skill(20);
            bossSkills.push_back(boss_skill);
            break;
        }
        case 8:
        {
            name = "纳兰嫣然";
            Hp = 600;
            Hp_max = 600;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 170;
            AddPoint = 4;
            desc = "纳兰嫣然，是云岚宗少宗主，自小与萧炎指腹为婚，后因萧炎实力下降而看不起萧炎，并擅自登门取消婚约";
            Skills boss_skill1(19);
            Skills boss_skill2(18);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 9:
        {
            name = "太虚古龙";
            Hp = 700;
            Hp_max = 700;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 180;
            AddPoint = 4;
            desc = "魔兽世界公认的最强种族，把天妖凰当食物，擅长使用空间之力，能在虚无空间中自由穿梭，并在其中建立了栖息地龙岛。俗话说神龙见首不见尾，古龙一族向来低调，一般人很难见到他们。";
            Skills boss_skill1(19);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 10:
        {
            name = "远古天蛇";
            Hp = 800;
            Hp_max = 800;
            Att = 100;
            Def = 100;
            AddGol = 450;
            AddLv = 190;
            AddPoint = 4;
            desc = "蛇类魔兽的先祖，数量稀少，性情凶戾，极度危险。";
            Skills boss_skill1(17);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 11:
        {
            name = "远古天凰";
            Hp = 900;
            Hp_max = 900;
            Att = 100;
            Def = 100;
            AddGol = 500;
            AddLv = 200;
            AddPoint = 4;
            desc = "天妖凰的祖先，血脉纯正，能和太虚古龙一族抗衡。不过由于血脉的流失，现在已经在斗气大陆消失。";
            Skills boss_skill1(21);
            Skills boss_skill2(20);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 12:
        {
            name = "龙凰";
            Hp = 1000;
            Hp_max = 1000;
            Att = 100;
            Def = 100;
            AddGol = 500;
            AddLv = 210;
            AddPoint = 4;
            desc = "由太虚古龙或者远古天凰吸收龙凰本源果进化而来，血脉集古龙天凰与一体，堪称魔兽中的天花板。传说中龙凰一共出现过五次，古龙与天凰一族不管谁出了龙凰另外一族就会被完全压制。";
            Skills boss_skill1(19);
            Skills boss_skill2(22);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 13:
        {
            name = "美杜莎";
            Hp = 2000;
            Hp_max = 2000;
            Att = 100;
            Def = 50;
            AddGol = 500;
            AddLv = 220;
            AddPoint = 5;
            desc = "堪与斗圣强者相抗衡的远古异兽，辨认它的标志，便是其身七彩，其瞳略紫，其体泛，其力通天！";
            Skills boss_skill1(21);
            Skills boss_skill2(23);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 14:
        {
            name = "云山";
            Hp = 3000;
            Hp_max = 3000;
            Att = 100;
            Def = 100;
            AddGol = 1000;
            AddLv = 230;
            AddPoint = 5;
            desc = "云岚宗前任宗主，闭关多年在魂殿的帮助下成为斗宗强者，初登场实力为一星斗宗，最终实力为三星斗宗。";
            Skills boss_skill1(22);
            Skills boss_skill2(23);
            bossSkills.push_back(boss_skill1);
            bossSkills.push_back(boss_skill2);
            break;
        }
        case 15:
        {
            name = "魂天帝";
            Hp = 5000;
            Hp_max = 5000;
            Att = 200;
            Def = 150;
            AddGol = 1000;
            AddLv = 240;
            AddPoint = 10;
            desc = "远古八族魂族族长，原为九星斗圣巅峰实力，后以中州为鼎，生灵为料，天地为火，肉身为丹，将帝品雏丹炼化为成品帝丹，晋升斗帝——自号魂帝，最终被炎帝用牺牲肉身的代价所封印。    一袭白袍，看上去温文尔雅，实则为人心狠手辣，小心谨慎，做事不择手段，男主角萧炎的最大仇人。";
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
    cout << "当前野怪属性:  " << endl;
    cout << "名称：" << name << " 描述：" << desc << endl;
    cout << "血量：" << Hp << "/" << Hp_max;
    cout << "  攻击力：" << Att << "  防御力：" << Def << endl;
    cout << "*************************************\n";
}

int Boss::getId() {
    return this->id;
}
