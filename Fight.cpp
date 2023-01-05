
// Created by shineahead on 2022-08-22.
//

#include "Fight.h"
#include <string>
#include<iostream>
#include <cstdlib>
#include<windows.h>
#include<ctime>
using namespace std;

Fight::Fight(Role *r, Boss &b): boss(b),role(r){}

Fight::~Fight() {}

void Fight::enterFight()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);//设置红色和绿色相加
    cout << "正在进入战斗.....请稍等" << endl;
    Sleep(2000);
}
//每个战斗回合的输出
Role& Fight::setFight() {
    //表示当前的战斗还未结束
    while ( symbol)
    {
        //用flag来判断是否要结算当前回合
        bool flag = true;
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);//设置红色和绿色相加
        cout << endl << endl;
        role->showRole();
        cout << endl << endl;
        boss.showBoss();
        cout << endl << endl;
        cout << "当前是第" << count << "个回合" << endl;
        int choice = outMenu();
        roleHurt = 0;
        bossHurt = 0;
        switch (choice)
        {
            //使用丹药
            case 1:
            {
                if ( !role->bag.ifUseElixir())
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "\n背包中已无丹药可以使用了\n" << endl;
                    Sleep(2000);
                    flag = false;
                    break;
                }
                role->bag.showBagElixir();
                cout << endl << endl;
                cout << "选择丹药的id进行使用(输入0退出选择)" << endl;
                string id;
                cin >> id;
                if (stoi(id) == 0)
                {
                    flag = false;
                    break;
                }
                if ( id.length() != 1 && id.length() != 2)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "输入过多参数" << endl;
                    flag = false;
                    Sleep(2000);
                    break;
                }
                else
                {
                    int n1 = stoi(id), n2;
                    //这里记得n1要减1,n2是使用的数量
                    if (n1 > role->bag.bagElixir.size())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "输入的id错误" << endl;
                        Sleep(2000);
                        flag = false;
                        break;
                    }
                    role->bag.showElixir(n1);
                    cout << "请输入使用的数量" << endl;
                    cin >> n2;
                    if (n2 > role->bag.getElixirNum(n1))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "\n超过背包内丹药的数量！\n" << endl;
                        Sleep(2000);
                        flag = false;
                        break;
                    }
                    else
                    {
                        //拿到选择的丹药
                        Elixir e(n1);
                        if (e.getAddAtt())
                        {
                            role->ATT += e.getAddAtt() * n2;
                        }
                        if (e.getAddMp())
                        {
                            role->MP += e.getAddMp() * n2;
                            if (role->MP > role->MP_MAX)
                                role->MP = role->MP_MAX;
                        }
                        if (e.getAddLv())
                        {
                            role->LV += e.getAddLv() * n2;
                            role->impLevel();    //判断是否能升级
                        }
                        if (e.getAddDef())
                        {
                            role->DEF += e.getAddDef() * n2;
                        }
                        if (e.getAddGrade())
                        {
                            role->level += e.getAddGrade() * n2;
                            role->MP += 10 * 3 * e.getAddGrade() * n2;
                            role->MP_MAX += 10 * 3 * e.getAddGrade() * n2;
                            role->HP += 30 * 3 * e.getAddGrade() * n2;
                            role->HP_MAX += 30 * 3 * e.getAddGrade() * n2;
                            role->ATT += 15 * 3 * e.getAddGrade() * n2;
                            role->ATT_MAX += 15 * 3 * e.getAddGrade() * n2;
                            role->DEF += 10 * 3 * e.getAddGrade() * n2;
                            role->DEF_MAX += 10 * 3 * e.getAddGrade() * n2;
                            if (role->HP > role->HP_MAX)
                                role->HP = role->HP_MAX;
                            if (role->MP > role->MP_MAX)
                                role->MP = role->MP_MAX;
                        }
                        if (e.getAddStar())
                        {
                            role->level += e.getAddStar() * n2;
                            role->impLevel();
                            role->MP += 10 * e.getAddStar() * n2;
                            role->MP_MAX += 10 * e.getAddStar() * n2;
                            role->HP += 30 * e.getAddStar() * n2;
                            role->HP_MAX += 30 * e.getAddStar() * n2;
                            role->ATT += 15 * e.getAddStar() * n2;
                            role->ATT_MAX += 15 * e.getAddStar() * n2;
                            role->DEF += 10 * e.getAddStar() * n2;
                            role->DEF_MAX += 10 * e.getAddStar() * n2;
                            if (role->MP > role->MP_MAX)
                                role->MP = role->MP_MAX;
                            if (role->HP > role->HP_MAX)
                                role->HP = role->HP_MAX;
                        }
                        if (e.getAddHp())
                        {
                            role->HP += e.getAddHp() * n2;
                            if (role->HP > role->HP_MAX)
                                role->HP = role->HP_MAX;
                        }
                        //把背包里面丹药的数量减少
                        role->bag.reduceElixir(n1, 1, n2);
                    }
                }
                break;
            }
            //使用斗技
            case 2:
            {
                if (role->bag.bagSkills.empty())
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "\n你没有斗技可以使用！\n" << endl;
                    Sleep(2000);
                    flag = false;
                    break;
                }
                else
                {
                    //展示斗技
                    role->bag.showBagSkills();
                    string c;
                    cout << "选择斗技的id进行使用(输入0退出选择)" << endl;
                    cin >> c;
                    if (stoi(c) == 0)
                    {
                        flag = false;
                        break;
                    }
                    if (stoi(c) > role->bag.bagSkills.size())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "输入的id错误" << endl;
                        Sleep(1000);
                        flag = false;
                        break;
                    }
                    int id = stoi(c);
                    Skills s(id);
                    if (role->MP < s.getConsume())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "\n你目前的体力值不够放技能" << endl;
                        Sleep(2000);
                        flag = false;
                        break;
                    }
                    role->MP -= s.getConsume();
                    if (s.getAddAtt())
                        role->ATT += s.getAddAtt();
                    if (s.getAddHp())
                    {
                        role->HP += s.getAddHp();
                        if (role->HP > role->HP_MAX)
                            role->HP = role->HP_MAX;
                    }
                    if (s.getAddDef())
                        role->DEF += s.getAddDef();
                    if (s.getdecHp())
                        roleHurt = role->ATT + s.getdecHp();
                    else
                        roleHurt = role->ATT;
                    cout << "斗技的效果" << endl << endl;
                    role->bag.showSkill(id);
                }
                break;
            }
            //普通攻击
            case 3:
            {
                roleHurt = role->ATT;
                break;
            }
            //逃跑
            case 4:
            {
                srand(time(0));
                int number = rand() % 100 + 1;
                if (number <= 75)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "逃跑成功" << endl;
                    Sleep(2000);
                    symbol = false;
                    flag = false;
                    break;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "逃跑失败" << endl;
                    Sleep(2000);
                    roleHurt = 0;
                    break;
                }
            }
            default:
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << "选择的数字错误请重新输入" << endl;
                Sleep(1000);
                flag = false;
                break;
            }
        }
        //正常战斗情况
        if (flag)
        {
            //如果BOSS有技能的话，随机使用
            if (!boss.bossSkills.empty())
            {
                int size = boss.bossSkills.size();
                int ran = rand() % 6 + 1;
                int num = rand() % size;
                //使用技能d
                if (ran <= 3)
                {
                    Skills s = boss.bossSkills[num];
                    if (s.getAddAtt())
                        boss.Att += s.getAddAtt();
                    if (s.getAddHp())
                    {
                        boss.Hp += s.getAddHp();
                        if (boss.Hp > boss.Hp_max)
                            boss.Hp = boss.Hp_max;
                    }
                    if (s.getAddDef())
                        boss.Def += s.getAddDef();
                    if (s.getdecHp())
                        bossHurt = boss.Att + s.getdecHp();
                    else
                        bossHurt = boss.Att;
                }
                else
                    bossHurt = boss.Att;
            }
            else
                bossHurt = boss.Att;
            int dec1 = bossHurt - role->DEF;
            int dec2 = roleHurt - boss.Def;
            if (dec1 < 0)
                dec1 = 0;
            if (dec2 < 0)
                dec2 = 0;
            role->HP -= dec1;
            boss.Hp -= dec2;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "\n你对" << boss.getName() << "造成了" << dec2 << "点伤害" << endl;
            cout << boss.getName() << "对你造成了" << dec1 << "点伤害\n" << endl;
            count++;
            Sleep(2000);
            if (ifEndFight())
            {
                recoverRole();
                addToRole();
                return *role;
            }
        }
        setFight();
    }
    return *role;
}

int Fight::outMenu() {
    cout << "选择战斗方式：1.使用丹药 2.使用斗技 3.普通攻击 4.逃跑" << endl;
    string c;
    cin >> c;
    if (c.length() != 1)
        cout << "输入过多参数" << endl;
    else
        return stoi(c);
}

//退出游戏
void Fight::endGame() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    system("cls");
    string back = "很遗憾，您在这次战斗中失败了，希望您在新的大陆上能够东山再起，886";
    for (char i: back)
    {
        cout << i;
        Sleep(30);
    }
    system("pause");
    exit(0);
}

bool Fight::ifEndFight()
{
    if (role->HP <= 0)
        endGame();
    else if(boss.Hp <= 0)
    {
        cout << boss.getName() << "已死亡，战斗结束" << endl;
        Sleep(2000);
        symbol = false;
        if (boss.getName() == "魂天帝")
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//设置红色和绿色相加
            string back = "恭喜你成功击败了魂天帝，现在你可以前往大千世界继续你的历险了";
            for (char i :back)
            {
                cout << i;
                Sleep(20);
            }
            exit(0);
        }
        return true;
    }
    return false;
}

void Fight::recoverRole()
{
    role->HP = role->HP_MAX;
    role->MP = role->MP_MAX;
    role->ATT = role->ATT_MAX;
    role->DEF = role->DEF_MAX;
    boss.Hp = boss.Hp_max;
}

void Fight::addToRole()
{
    system("cls");

    if (boss.getName() == "纳兰嫣然")
    {
        system("cls");
        //设置黄色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);
        string background1 = "\n\t三年之约的结果以纳兰嫣然战败告终。下云岚宗回到家，本应该是喜悦的场景，不料父亲被云岚宗掳走。萧炎再上云岚宗，与云山大战，绝望之际，药老附身对战云山，后逃离云岚宗。期间得知云芝是云岚宗宗主云韵，也心灰意冷。处于两难境地的云韵，听从了心的指引，让萧炎躲过云岚宗追击，逃出了加玛帝国。\n\t自此凭借他的执着与信念，闯荡大陆，在一次次的生死之间，承受着常人所无法承受的痛苦，疯狂地增强着实力，向着大陆巅峰强者迈进。";
        for (char i : background1) {
            cout << i;
            Sleep(30);
        }
        cout << endl;
        system("pause");
        system("cls");
    }
    //判断是否完成了任务
    if (role->task[role->getTaskId()].getGoal() == boss.getName())
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);//设置红色和绿色相
        cout << "\n叮！任务完成！\n" << endl;
        Sleep(2000);
        string back = "\n恭喜你获得了" + to_string(role->task[role->taskId].getAddGol()) + "个金币，" + to_string(role->task[role->taskId].getAddLv()) + "点经验，" + to_string(role->task[role->taskId].getAddPoint()) + "个技能点数\n\n";
        for (char i : back)
        {
            cout << i;
            Sleep(20);
        }
        role->LV += role->task[role->taskId].getAddLv();
        role->Gol += role->task[role->taskId].getAddGol();
        role->Point += role->task[role->taskId].getAddPoint();
        role->taskId++;
        //判断是否升级
        role->impLevel();
        system("pause");
    }
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);//设置红色和绿色相加
    string back = "\n恭喜你获得了" + to_string(boss.AddGol) + "个金币，" + to_string(boss.AddLv) + "点经验，" + to_string(boss.AddPoint) + "个技能点数\n\n";
    for (char i : back)
    {
        cout << i;
        Sleep(20);
    }
    role->LV += boss.AddLv;
    role->Gol += boss.AddGol;
    role->Point += boss.AddPoint;
    role->impLevel();
    system("pause");
}




