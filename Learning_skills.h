//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_LEARING_SKILLS_H
#define MUD_GAME_LEARING_SKILLS_H
#include<iostream>
#include<vector>
#include "Bag.h"
#include "Skills.h"
#include "Role.h"
class Role;
class Learning_skills {
public:
    Learning_skills(Role *role1);  //在默认构造函数里面初始化斗技
    ~Learning_skills();

    void deal();
    void showSkills();  //展示可以学习的斗技
    bool learnSkills(int id); //学习斗技
private:
    vector<Skills> storeSkills;
    Role *role;
};


#endif //MUD_GAME_LEARING_SKILLS_H
