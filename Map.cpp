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
    NameSet.insert(make_pair(make_pair(0, 0) , "乌坦城"));
    NameSet.insert(make_pair(make_pair(1, 0), "魔兽山脉"));
    NameSet.insert(make_pair(make_pair(1, 1), "加码帝国"));
    NameSet.insert(make_pair(make_pair(2, 1), "云岚宗"));
    NameSet.insert(make_pair(make_pair(3, 1), "塔戈尔沙漠"));
    NameSet.insert(make_pair(make_pair(2, 2), "迦南学院"));
    NameSet.insert(make_pair(make_pair(2, 3), "星陨阁"));
    NameSet.insert(make_pair(make_pair(3, 3), "冰河谷"));
    NameSet.insert(make_pair(make_pair(3, 0), "落神涧"));
    NameSet.insert(make_pair(make_pair(2, 4), "魂殿"));
    px = 0;
    py = 0;

    //谈话地点
    ChatPlace.insert(make_pair("星陨阁",true));
    ChatPlace.insert(make_pair("云岚宗",true));
    ChatPlace.insert(make_pair("落神涧",true));
    ChatPlace.insert(make_pair("魂殿",true));

    //战斗地点
    CanFight.insert(make_pair("魔兽山脉", true));
    CanFight.insert(make_pair("加码帝国", true));
    CanFight.insert(make_pair("云岚宗", true));
    CanFight.insert(make_pair("塔戈尔沙漠", true));
    CanFight.insert(make_pair("迦南学院", true));
    CanFight.insert(make_pair("星陨阁", true));
    CanFight.insert(make_pair("冰河谷", true));
    CanFight.insert(make_pair("落神涧", true));
    CanFight.insert(make_pair("魂殿", true));

    //任务地点
    TaskPlace.insert(make_pair("魔兽山脉", 1));
    TaskPlace.insert(make_pair("云岚宗", 2));
    TaskPlace.insert(make_pair("塔戈尔沙漠", 3));
    TaskPlace.insert(make_pair("星陨阁", 4));
    TaskPlace.insert(make_pair("魂殿", 5));

    //每个地方的怪兽
    vector<Boss> v1;
    v1.emplace_back(Boss(1));
    v1.emplace_back(Boss(2));
    v1.emplace_back(Boss(3));
    monster.insert(make_pair("魔兽山脉", v1));
    //与萧熏儿之战之地
    vector<Boss> v2;
    v2.emplace_back(Boss(7));
    monster.insert(make_pair("落神涧", v2));
    //与纳兰嫣然战斗之地
    vector<Boss> v3;
    v3.emplace_back(Boss(8));   //纳兰嫣然
    v3.emplace_back(Boss(11));
    monster.insert(make_pair("云岚宗", v3));
    //加码帝国
    vector<Boss> v4;
    v4.emplace_back(Boss(4));
    v4.emplace_back(Boss(6));
    v4.emplace_back(Boss(13));  //美杜莎
    monster.insert(make_pair("加码帝国", v4));
    //塔戈尔沙漠
    vector<Boss> v5;
    v5.emplace_back(Boss(4));
    v5.emplace_back(Boss(5));
    monster.insert(make_pair("塔戈尔沙漠", v5));
    //迦南学院
    vector<Boss> v6;
    v6.emplace_back(Boss(9));
    v6.emplace_back(Boss(10));
    monster.insert(make_pair("迦南学院", v6));
    //星陨阁
    vector<Boss> v7;
    v7.emplace_back(Boss(14));
    monster.insert(make_pair("星陨阁", v7));
    //冰河谷
    vector<Boss> v8;
    v8.emplace_back(Boss(11));
    v8.emplace_back(Boss(12));
    monster.insert(make_pair("冰河谷", v8));
    //魂殿
    vector<Boss> v9;
    v9.emplace_back(Boss(15));
    monster.insert(make_pair("魂殿", v9));

    //地图对话信息
    inf["落神涧"] = "\n\t熏儿：萧炎哥哥，三年之约即将来临，不如让我们先来切磋切磋吧!\n\t萧炎：好啊，妮子！正好看看我如今的实力如何吧!";
    inf["云岚宗"] = "\n\t萧炎：三年之约，我来了！战吧！\n\t纳兰嫣然：萧炎，你确实变了，不再是三年前那个萧家废物少爷！\n\t纳兰嫣然：我从未忘记过三年前你写下的休书，也从未忘记过你我之间的约定！\n\t纳兰嫣然：萧炎，你是不可能战胜我的！三年前如此，现在也如此！";
    inf["星陨阁"] = "\n\t药老：萧炎，星陨阁阁顶汇聚星辰之力，适宜修炼！\n\t萧炎：好的，老师！";
    inf["魂殿"] = "\n\t魂天帝：萧炎，我已进入斗帝，整个斗气大陆都将是我魂族的了！\n\t萧炎：这个世界可不止你一人进入的了斗帝！\n\t我生化异火，封印你千载万世！";

}
Map::~Map()
{

}

bool Map::ifCanChat()  //判断是否能对话，包括是否已经对过话或者无法对话
{
    string tname = NameSet[ make_pair( px,py )];    //当前地图的名字
    if (ChatPlace[tname])
        return true;
    else
        return false;
}

bool Map::ifCanFight()  //判断是否能战斗
{
    string tname = NameSet[ make_pair( px,py )];
    if (CanFight[tname])
        return true;
    else
        return false;
}

void Map::showMap()     //打印地图
{
    cout << "斗气大陆地图:" << endl;
    cout << " __________________________            _____________ " << endl;
    cout << "|            |            |            |            |" << endl;
    cout << "|   乌坦城   |  魔兽山脉  |            |    落神涧  |" << endl;
    cout << "|____________|____________|____________|____________|" << endl;
    cout << "             |            |            |            |" << endl;
    cout << "             |   加码帝国 |   云岚宗   |  塔戈尔沙漠|" << endl;
    cout << "             |____________|____________|____________|" << endl;
    cout << "                          |            |             " << endl;
    cout << "                          |  迦南学院  |             " << endl;
    cout << "                          |____________|____________ " << endl;
    cout << "                          |            |            |" << endl;
    cout << "                          |   星陨阁   |   冰河谷   |" << endl;
    cout << "                          |____________|____________|" << endl;
    cout << "                          |            |             " << endl;
    cout << "                          |    魂殿    |             " << endl;
    cout << "                          |____________|             " << endl;
    //cout << "您现在的位置为" << mapName[position] << endl;
}

void Map::enterMap(string const&name)    //进入地图,通过px和py来定位到具体的地图
{
    if ( !NameSet[ make_pair(px, py) ].empty() )
    {
        cout << "进入地图......" << endl;
        Sleep(1000);
        //输出人物的对话
        if (ChatPlace[name])
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//设置红色和绿色相加
            for (char c: inf[name])
            {
                cout << c;
                Sleep(20);
            }
            Sleep(1500);
            //标记为已经对过话
            ChatPlace[name] = false;
        }
    }
}

void Map::showPrePos()  //展示当前地方的信息，例如有哪些野怪或者人物
{
    string name = NameSet[make_pair(px, py)];
    cout << inf[name];
    system("cls");
    cout << "当前地点：" << name << endl << endl;
    if (CanFight[name])
    {
        cout << "可以进行战斗的人物有：" << endl;
        for (Boss b: monster[name])
        {
            cout << b.getName() << ": " << b.getDesc() << endl;
        }
        cout << endl << endl;
    }
    else
        cout << "当前地点没有战斗可以发生" << endl << endl << endl;
}

void Map::Move(char order)    //进行移动人物,通过id直接进入该地方
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

