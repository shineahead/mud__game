//
// Created by shineahead on 2022-08-20.
//
#pragma once
#ifndef MUD_GAME_ELIXIR_H
#define MUD_GAME_ELIXIR_H
#include<string>
using namespace std;
//丹药
class Elixir {
public:
    Elixir();
    Elixir(int id);
    ~Elixir();

    string getName();
    string getDesc();
    int getAddHp();
    int getAddMp();
    int getAddLv();
    int getAddAtt();
    int getAddDef();
    int getPrice();
    int getAddGrade();
    int getAddStar();
    int getId();
    int getNum();
    int setNum(int num);    //买丹药或者使用的数量
    Elixir& operator=(Elixir const& e);
private:
    int id; //丹药的id
    int type = 1;   //用来区分丹药和斗技的类型，丹药-1，斗技-0
    int price = 0;  //丹药的价格
    int addHp = 0;  //增加血量值
    int addMp = 0;  //增加的体力值
    int addLv = 0;  //增加的经验值
    int addAtt = 0; //增加的攻击力
    int addDef = 0; //增加的防御值
    int addStar = 0;   //星级提升
    int addLevel = 0;   //等级提升,每个星级共分为3个等级
    int num = 0;    //丹药数量
    string name;    //丹药的名字
    string desc;    //丹药的描述

};


#endif //MUD_GAME_ELIXIR_H
