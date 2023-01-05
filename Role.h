//
// Created by shineahead on 2022-08-20.
//
#pragma once
#ifndef MUD_GAME_ROLE_H
#define MUD_GAME_ROLE_H
#include <string>
#include "Bag.h"
#include "Drug_store.h"
#include "Learning_skills.h"
#include "Task.h"
#include "Save_data.h"
#include "Read_data.h"
using namespace std;

//角色只有萧炎
class Role {
public:
    friend class Fight;
    friend class DrugStore;
    friend class Learning_skills;
    friend class Save_data;
    friend class Read_data;
    Role();
    ~Role();
    Bag bag;    //角色的背包
    int getHp();
    int getMp();
    int getLv();
    int getAtt();
    int getDef();
    int getGol();
    string getName();
    string getDesc();
    int getPoint();
    int getTaskId();
    int getLevel();
    int getStar();
    void impLevel();    //判断是否升级
    bool reduceElixir(int id, int type, int num);     //使用丹药
    bool ifComTask();   //判断是否完成了当前的任务,一般在战斗之后进行判断
    friend class Bag;
    Role& operator=(Role const& r);
    void showRole();    //展示人物的各种信息
    void showTask();    //展示人物的任务信息
    bool addSkills(int id);   //往背包里面加斗技
    void addGoods(int id, int type, int num);    //往背包里面添加丹药
protected:
    int HP = 0; //血量值
    int HP_MAX = 0;
    int level = 0;  //等级
    int star = 0;   //星级，共分为3级
    int MP = 0; //体力值
    int MP_MAX = 0;
    int LV = 0; //经验值
    int ATT = 0;  //攻击力
    int ATT_MAX = 0;
    int DEF = 0;  //防御值
    int DEF_MAX = 0;
    int Gol = 0;  //金钱数
    int Point = 0;  //技能点数
    string name = "萧炎";  //名字
    string desc; //角色描述
    Task task[20];  //所有的任务全加进来
    int taskId = 1;


};


#endif //MUD_GAME_ROLE_H
