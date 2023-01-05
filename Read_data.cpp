//
// Created by shineahead on 2022-08-22.
//

#include "Read_data.h"
#include<fstream>
#include <windows.h>

void Read_data::Read(){
    //读入role文件
    ifstream inR("role.dat", ios::in);
    if (inR.is_open())
    {
        inR >> role->HP >> role->HP_MAX >> role->level
        >> role->star >> role->MP >> role->MP_MAX
        >> role->LV >> role->ATT >> role->ATT_MAX
        >> role->DEF >> role->DEF_MAX >> role->Gol
        >> role->Point >> role->taskId;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
    //读入bag文件
    int size_S, size_E;
    ifstream inB("bag.dat", ios::in);
    if (inB.is_open())
    {
        inB >> size_S;
        for (int i = 0; i < size_S; i++)
        {
            int id;
            inB >> id;
            Skills s(id);
            bag->bagSkills.push_back(s);
        }
        inB >> size_E;
        for (int i = 0; i < size_E; i++)
        {
            int id, num;
            inB >> id >> num;
            Elixir e(id);
            e.setNum(num);
            bag->bagElixir.push_back(e);
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
    //读入map文件
    ifstream inM("map.dat", ios::in);
    if (inM.is_open())
    {
        inM >> map->px >> map->py
           >> map->ChatPlace["星陨阁"]
           >> map->ChatPlace["云岚宗"]
           >> map->ChatPlace["落神涧"]
           >> map->ChatPlace["魂殿"];
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
}



Read_data::Read_data(Role *r, Bag *b, Map *m): role(r), map(m), bag(b)
{

}

Read_data::~Read_data() {

}
