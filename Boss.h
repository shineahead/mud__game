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
    Boss(int id);   //���ǰ�����BOSS�����Զ�д��Ĭ�Ϲ��캯������
    ~Boss();    //֮��ͨ��ÿ����ͼ�趨id���趨BOSS�Ĵ���

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
    vector<Skills> bossSkills; //Boss�ļ���
    void showBoss();
private:
    int id; //boss��ID
    int Hp; //Ѫ��ֵ
    int Hp_max; //�������ֵ
    int Mp; //����ֵ
    int Def;  //����ֵ
    int Att;  //������
    int AddGol; //����Ľ�Ǯ
    int AddLv;  //����ľ���
    int AddPoint;   //����ļ��ܵ���
    string name;    //boss������
    string desc;    //boss������
};


#endif //MUD_GAME_BOSS_H
