//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_GROCERY_H
#define MUD_GAME_GROCERY_H
#include "Role.h"
class Role;
class DrugStore {
public:
    DrugStore(Role *role1);  //在默认构造函数里面初始化丹药
    ~DrugStore();

    void deal();    //处理
    void showElixir();  //展示所有的丹药
    bool buyElixir(int id, int num);   //购买丹药
private:
    vector<Elixir> storeElixir;
    Role *role;
};


#endif //MUD_GAME_GROCERY_H
