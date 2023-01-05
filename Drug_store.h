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
    DrugStore(Role *role1);  //��Ĭ�Ϲ��캯�������ʼ����ҩ
    ~DrugStore();

    void deal();    //����
    void showElixir();  //չʾ���еĵ�ҩ
    bool buyElixir(int id, int num);   //����ҩ
private:
    vector<Elixir> storeElixir;
    Role *role;
};


#endif //MUD_GAME_GROCERY_H
