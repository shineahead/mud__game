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
    Learning_skills(Role *role1);  //��Ĭ�Ϲ��캯�������ʼ������
    ~Learning_skills();

    void deal();
    void showSkills();  //չʾ����ѧϰ�Ķ���
    bool learnSkills(int id); //ѧϰ����
private:
    vector<Skills> storeSkills;
    Role *role;
};


#endif //MUD_GAME_LEARING_SKILLS_H
