//
// Created by shineahead on 2022-08-29.
//
#include "origin_define.h"
//��Ϸ�趨�Ķ���

void Declaration()
{
    levelGrade.insert(make_pair(1, "����"));
    levelGrade.insert(make_pair(2, "��ʦ"));
    levelGrade.insert(make_pair(3, "����"));
    levelGrade.insert(make_pair(4, "����"));
    levelGrade.insert(make_pair(5, "����"));
    levelGrade.insert(make_pair(6, "����"));
    levelGrade.insert(make_pair(7, "��ʥ"));
    levelGrade.insert(make_pair(8, "����"));
    for (int i = 1; i <= 8; i++)
    {
        int val = 50;
        exp_level[i] = val + 10 * (i - 1);
    }
}




