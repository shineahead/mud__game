//
// Created by shineahead on 2022-08-21.
//
#pragma once
#ifndef MUD_GAME_BAG_H
#define MUD_GAME_BAG_H
#include<map>
#include<vector>
#include "Elixir.h"
#include "Skills.h"

using namespace std;
//背包里面最多只能放20个药，学习10种斗技


class Bag {
public:

    Bag();
    ~Bag();
    int getMaxElixir();  //得到最大背包容量
    void showElixir(int id);   //得到背包里编号为id的丹药信息
    void showSkill(int id);   //得到背包里编号为id的技能信息
    void showBagElixir();    //展示背包的丹药
    bool ifUseElixir(); //判断是否还有药可以使用
    int getElixirNum(int id);  //得到背包里的丹药的数量
    //Bag& addGoods(int id, int type, int num);    //往背包里面添加丹药
    void reduceElixir(int id, int type, int num);   //减少背包里面的丹药
    void showBagSkills();  //展示所有的斗技
    //bool addSkills(int id);   //往背包里面加斗技
    void ifDeleteElixir();  //判断是否需要把丹药从背包中删除
    Bag& operator=(Bag const& b);
    vector<Elixir> bagElixir;   //用vector来存储丹药
    vector<Skills> bagSkills;   //用vector来存储斗技

private:
    int max_Elixir_num;  //最大丹药存储量
    int max_skills_num;
};

#endif //MUD_GAME_BAG_H
