//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_TASK_H
#define MUD_GAME_TASK_H
#include <string>
#include "Skills.h"
using namespace std;
//��ɫ������

class Task {
public:
    Task();
    Task(int num);
    ~Task();

    string getTitle();
    string getDesc();
    int getAddPoint();
    int getAddLv();
    int getId();    //��ȡ����ı��
    int getAddGol();
    bool getSymbol();
    string getGoal();
    void showTask();
    void setTaskSymbol();   //���������֮���symbol����Ϊtrue
    Task& operator=(Task const&task);    //���صȺ������


private:
    int id; //�����id
    bool symbol = false;    //�����жϵ�ǰ�����Ƿ��Ѿ����ܹ�
    string title;  //����ı���
    string desc;   //���������
    string goal;    //�����Ŀ�����
    int addPoint;   //������ļ��ܵ���
    int addLv;  //�������ӵľ������
    int addGol; //�������ӵĽ��
};


#endif //MUD_GAME_TASK_H
