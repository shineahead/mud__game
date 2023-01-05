//
// Created by shineahead on 2022-08-21.
//
//地图类用来显示人物所在的位置
#pragma once
#ifndef MUD_GAME_MAP_H
#define MUD_GAME_MAP_H
#include<string>
#include<map>
#include<utility>
#include "Boss.h"
#include <vector>

using namespace std;

class Map {
public:
    Map();  //初始化ifChatted全部未对话过
    ~Map();

    bool ifCanChat();   //判断是否能对话，包括是否已经对过话或者无法对话
    bool ifCanFight();  //判断是否能战斗
    void showMap();     //打印地图
    void enterMap(string const&name);    //进入地图,通过px和py来定位到具体的地图
    void showPrePos();  //展示当前地方的信息，例如有哪些野怪或者人物
    void Move(char order);    //进行移动人物,通过id直接进入该地方

public:
    map<pair<int,int> , string> NameSet; //地图的名字，可以用默认构造函数进行初始化
    map<string, bool> ChatPlace;//string是能进行对话的地图名，以及是否对过话
    map<string, bool> CanFight;//能进行战斗的地方
    map<string, int> TaskPlace;//有任务的地方,后面的数字表示任务的编号
    map<string, string> inf;    //每个地图的信息
    map<string, vector<Boss>> monster;   //每个地图的野怪
    //int ChatPlace[10];  //能进行对话的地方
    //bool ifChatted[10];  //是否已经对过话
    // string NameSet[10]; //地图的名字，可以用默认构造函数进行初始化
    // int ChatPlace[10];  //能进行对话的地方
    // bool ifChatted[10];  //是否已经对过话
    int px; //x坐标，用来定位地图
    int py; //y坐标，用来定位地图
};


#endif //MUD_GAME_MAP_H
