//
// Created by shineahead on 2022-08-22.
//
#pragma once
#ifndef MUD_GAME_READ_DATA_H
#define MUD_GAME_READ_DATA_H
#include "Role.h"
#include "Bag.h"
#include "Map.h"
#include "Task.h"
//前向引用
class Role;
class Bag;
class Map;
class Read_data {
public:
    Read_data(Role *r, Bag *b, Map *m);
    ~Read_data();
    void Read();
private:
    Role *role;
    Map *map;
    Bag *bag;
};


#endif //MUD_GAME_READ_DATA_H
