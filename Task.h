//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_TASK_H
#define MUD_GAME_TASK_H
#include <string>
#include "Skills.h"
using namespace std;
//角色的任务

class Task {
public:
    Task();
    Task(int num);
    ~Task();

    string getTitle();
    string getDesc();
    int getAddPoint();
    int getAddLv();
    int getId();    //获取任务的编号
    int getAddGol();
    bool getSymbol();
    string getGoal();
    void showTask();
    void setTaskSymbol();   //在任务完成之后把symbol设置为true
    Task& operator=(Task const&task);    //重载等号运算符


private:
    int id; //任务的id
    bool symbol = false;    //用来判断当前任务是否已经接受过
    string title;  //任务的标题
    string desc;   //任务的描述
    string goal;    //任务的目标对象
    int addPoint;   //任务给的技能点数
    int addLv;  //任务增加的经验点数
    int addGol; //任务增加的金币
};


#endif //MUD_GAME_TASK_H
