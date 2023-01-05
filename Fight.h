//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_FIGHT_H
#define MUD_GAME_FIGHT_H
#include "Role.h"
#include "Boss.h"
class Role;
class Fight {
public:
    Fight (Role *role, Boss &boss);
    ~Fight();
    void enterFight();  //构建进入战斗的画面，屏幕等几秒
    bool ifEndFight();    //判断是否战斗结束了
    Role& setFight();    //构建战斗的场景,输出人物和怪物的属性值等
    int outMenu();   //给出选择：普通攻击,用技能,用丹药等等
    void addToRole();   //怪兽死亡之后加的经验，金币，技能点等等
    void recoverRole();  //把角色的血量和体力值等回满
    void endGame(); //结束游戏

private:
    int count =  1; //计数器，计算当前为第几回合
    Role *role;  //人物
    Boss boss;  //敌人
    double roleHurt;    //role造成的伤害
    double bossHurt;    //boss造成的伤害
    bool symbol = true; //用来表示战斗是否结束,true表示在进行中
};


#endif //MUD_GAME_FIGHT_H
