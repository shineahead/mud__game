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

//��ɫֻ������
class Role {
public:
    friend class Fight;
    friend class DrugStore;
    friend class Learning_skills;
    friend class Save_data;
    friend class Read_data;
    Role();
    ~Role();
    Bag bag;    //��ɫ�ı���
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
    void impLevel();    //�ж��Ƿ�����
    bool reduceElixir(int id, int type, int num);     //ʹ�õ�ҩ
    bool ifComTask();   //�ж��Ƿ�����˵�ǰ������,һ����ս��֮������ж�
    friend class Bag;
    Role& operator=(Role const& r);
    void showRole();    //չʾ����ĸ�����Ϣ
    void showTask();    //չʾ�����������Ϣ
    bool addSkills(int id);   //����������Ӷ���
    void addGoods(int id, int type, int num);    //������������ӵ�ҩ
protected:
    int HP = 0; //Ѫ��ֵ
    int HP_MAX = 0;
    int level = 0;  //�ȼ�
    int star = 0;   //�Ǽ�������Ϊ3��
    int MP = 0; //����ֵ
    int MP_MAX = 0;
    int LV = 0; //����ֵ
    int ATT = 0;  //������
    int ATT_MAX = 0;
    int DEF = 0;  //����ֵ
    int DEF_MAX = 0;
    int Gol = 0;  //��Ǯ��
    int Point = 0;  //���ܵ���
    string name = "����";  //����
    string desc; //��ɫ����
    Task task[20];  //���е�����ȫ�ӽ���
    int taskId = 1;


};


#endif //MUD_GAME_ROLE_H
