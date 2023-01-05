//
// Created by shineahead on 2022-08-29.
//
#include "origin_define.h"
//蚔牁扢隅腔隅砱

void Declaration()
{
    levelGrade.insert(make_pair(1, "須氪"));
    levelGrade.insert(make_pair(2, "須呇"));
    levelGrade.insert(make_pair(3, "須卼"));
    levelGrade.insert(make_pair(4, "須銘"));
    levelGrade.insert(make_pair(5, "須跁"));
    levelGrade.insert(make_pair(6, "須郬"));
    levelGrade.insert(make_pair(7, "須吤"));
    levelGrade.insert(make_pair(8, "須著"));
    for (int i = 1; i <= 8; i++)
    {
        int val = 50;
        exp_level[i] = val + 10 * (i - 1);
    }
}




