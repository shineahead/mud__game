//
// Created by shineahead on 2022-08-20.
//
#pragma once
#ifndef MUD_GAME_ORIGIN_DEFINE_CPP
#define MUD_GAME_ORIGIN_DEFINE_CPP
#include<iostream>
#include<windows.h>
#include<map>
#include<string>
#include "Boss.h"
#include "Task.h"
#include "Drug_store.h"
#include "Learning_skills.h"
#include "Map.h"
using namespace std;

map<int, string> levelGrade;    //等级规划
int exp_level[9];   //每一等级升星所需要的经验


#endif //MUD_GAME_ORIGIN_DEFINE_CPP
