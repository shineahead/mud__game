//
// Created by shineahead on 2022-08-21.
//
#pragma once
#ifndef MUD_GAME_BOSS_H
#define MUD_GAME_BOSS_H
#include "Skills.h"
#include<vector>

class Boss {
public:
    friend class Fight;
    Boss(int id);   //我们把所有BOSS的属性都写在默认构造函数里面
    ~Boss();    //之后通过每个地图设定id来设定BOSS的存在

    int getHp();
    int getHp_max();
    int getMp();
    int getDef();
    int getAtt();
    int getAddGol();
    int getAddLv();
    int getAddPoint();
    int getId();
    string getName();
    string getDesc();
    Boss& operator=(Boss const&b);
    vector<Skills> bossSkills; //Boss的技能
    void showBoss();
private:
    int id; //boss的ID
    int Hp; //血量值
    int Hp_max; //最大生命值
    int Mp; //体力值
    int Def;  //防御值
    int Att;  //攻击力
    int AddGol; //掉落的金钱
    int AddLv;  //掉落的经验
    int AddPoint;   //掉落的技能点数
    string name;    //boss的名字
    string desc;    //boss的描述
};


#endif //MUD_GAME_BOSS_H
