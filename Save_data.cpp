//
// Created by shineahead on 2022-08-22.
//

#include "Save_data.h"
#include <fstream>
#include <windows.h>

void Save_data::Save(Role &role) {
    ofstream out("role.dat", ios::out);
    //写入人物的数据
    if (out.is_open())
    {
        out << role.HP << " "
        << role.HP_MAX << " "
        << role.level << " "
        << role.star << " "
        << role.MP << " "
        << role.MP_MAX << " "
        << role.LV << " "
        << role.ATT << " "
        << role.ATT_MAX << " "
        << role.DEF << " "
        << role.DEF_MAX << " "
        << role.Gol << " "
        << role.Point << " "
        << role.taskId;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
}

void Save_data::Save(Map &map) {
    ofstream out("map.dat", ios::out);
    if (out.is_open())
    {
        out << map.px << " "
        << map.py << " "
        << map.ChatPlace["星陨阁"] << " "
        << map.ChatPlace["云岚宗"] << " "
        << map.ChatPlace["落神涧"] << " "
        << map.ChatPlace["魂殿"];
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
}

void Save_data::Save(Bag &bag) {
    ofstream out("bag.dat", ios::out);
    if (out.is_open())
    {
        //存储斗技容器的容量大小
        out << bag.bagSkills.size() << " ";
        //先存储背包中的斗技
        for (Skills s: bag.bagSkills)
        {
            //斗技只需要存储ID
            out << s.getId() << " ";
        }
        //存储丹药容器的容量大小
        out << bag.bagElixir.size() << " ";
        //再存储背包中的丹药
        for (Elixir e: bag.bagElixir)
        {
            //丹药需要存储ID和数量这两个字段
            out << e.getId() << " " << e.getNum() << " ";
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "\n文件写入错误\n" << endl;
        Sleep(2000);
    }
}


