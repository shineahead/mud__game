//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_SAVE_DATA_H
#define MUD_GAME_SAVE_DATA_H
#include "Role.h"
#include "Map.h"

class Save_data {
public:
    //保存人物的信息
    void Save(Role &role);
    //保存地图的信息
    void Save(Map &map);
    //保存背包的信息
    void Save(Bag &bag);
private:

};


#endif //MUD_GAME_SAVE_DATA_H
