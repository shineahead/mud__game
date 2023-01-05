//
// Created by shineahead on 2022-08-20.
//
#pragma once
#ifndef MUD_GAME_SKILLS_Hd
#define MUD_GAME_SKILLS_H
#include<string>
using namespace std;

class Skills {
public:
    Skills();
    Skills(int id);
    ~Skills();

    int getId();
    int getConsume();
    int getAddDef();
    int getAddHp();
    int getAddAtt();
    int getdecDef();
    int getdecHp();
    int getdecAtt();
    int getConPoint();
    string getName();
    string getDesc();
    Skills& operator=(Skills const&s);
private:
    int id; //skill的id
    int type = 0;   //用来区分丹药和斗技的类型，丹药-1，斗技-0
    int consume = 0;    //消耗的体力值
    int conPoint = 0;   //需要的技能点数
    int decHp = 0;      //对对面造成的伤害
    int addHp = 0;      //增加的血量值
    int addDef = 0;     //增加的防御点数
    int addAtt = 0;     //增加的攻击力
    int decAtt = 0;     //减少对面的攻击力
    int decDef = 0;     //减少对面的防御力
    string name;    //斗技名称
    string desc;    //技能描述

};


#endif //MUD_GAME_SKILLS_H
