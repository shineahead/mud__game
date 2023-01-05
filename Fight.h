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
    void enterFight();  //��������ս���Ļ��棬��Ļ�ȼ���
    bool ifEndFight();    //�ж��Ƿ�ս��������
    Role& setFight();    //����ս���ĳ���,�������͹��������ֵ��
    int outMenu();   //����ѡ����ͨ����,�ü���,�õ�ҩ�ȵ�
    void addToRole();   //��������֮��ӵľ��飬��ң����ܵ�ȵ�
    void recoverRole();  //�ѽ�ɫ��Ѫ��������ֵ�Ȼ���
    void endGame(); //������Ϸ

private:
    int count =  1; //�����������㵱ǰΪ�ڼ��غ�
    Role *role;  //����
    Boss boss;  //����
    double roleHurt;    //role��ɵ��˺�
    double bossHurt;    //boss��ɵ��˺�
    bool symbol = true; //������ʾս���Ƿ����,true��ʾ�ڽ�����
};


#endif //MUD_GAME_FIGHT_H
