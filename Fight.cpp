
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
                                                             FOREGROUND_GREEN);//���ú�ɫ����ɫ���
    cout << "���ڽ���ս��.....���Ե�" << endl;
    Sleep(2000);
}
//ÿ��ս���غϵ����
Role& Fight::setFight() {
    //��ʾ��ǰ��ս����δ����
    while ( symbol)
    {
        //��flag���ж��Ƿ�Ҫ���㵱ǰ�غ�
        bool flag = true;
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);//���ú�ɫ����ɫ���
        cout << endl << endl;
        role->showRole();
        cout << endl << endl;
        boss.showBoss();
        cout << endl << endl;
        cout << "��ǰ�ǵ�" << count << "���غ�" << endl;
        int choice = outMenu();
        roleHurt = 0;
        bossHurt = 0;
        switch (choice)
        {
            //ʹ�õ�ҩ
            case 1:
            {
                if ( !role->bag.ifUseElixir())
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "\n���������޵�ҩ����ʹ����\n" << endl;
                    Sleep(2000);
                    flag = false;
                    break;
                }
                role->bag.showBagElixir();
                cout << endl << endl;
                cout << "ѡ��ҩ��id����ʹ��(����0�˳�ѡ��)" << endl;
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
                    cout << "����������" << endl;
                    flag = false;
                    Sleep(2000);
                    break;
                }
                else
                {
                    int n1 = stoi(id), n2;
                    //����ǵ�n1Ҫ��1,n2��ʹ�õ�����
                    if (n1 > role->bag.bagElixir.size())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "�����id����" << endl;
                        Sleep(2000);
                        flag = false;
                        break;
                    }
                    role->bag.showElixir(n1);
                    cout << "������ʹ�õ�����" << endl;
                    cin >> n2;
                    if (n2 > role->bag.getElixirNum(n1))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "\n���������ڵ�ҩ��������\n" << endl;
                        Sleep(2000);
                        flag = false;
                        break;
                    }
                    else
                    {
                        //�õ�ѡ��ĵ�ҩ
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
                            role->impLevel();    //�ж��Ƿ�������
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
                        //�ѱ������浤ҩ����������
                        role->bag.reduceElixir(n1, 1, n2);
                    }
                }
                break;
            }
            //ʹ�ö���
            case 2:
            {
                if (role->bag.bagSkills.empty())
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "\n��û�ж�������ʹ�ã�\n" << endl;
                    Sleep(2000);
                    flag = false;
                    break;
                }
                else
                {
                    //չʾ����
                    role->bag.showBagSkills();
                    string c;
                    cout << "ѡ�񶷼���id����ʹ��(����0�˳�ѡ��)" << endl;
                    cin >> c;
                    if (stoi(c) == 0)
                    {
                        flag = false;
                        break;
                    }
                    if (stoi(c) > role->bag.bagSkills.size())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "�����id����" << endl;
                        Sleep(1000);
                        flag = false;
                        break;
                    }
                    int id = stoi(c);
                    Skills s(id);
                    if (role->MP < s.getConsume())
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << "\n��Ŀǰ������ֵ�����ż���" << endl;
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
                    cout << "������Ч��" << endl << endl;
                    role->bag.showSkill(id);
                }
                break;
            }
            //��ͨ����
            case 3:
            {
                roleHurt = role->ATT;
                break;
            }
            //����
            case 4:
            {
                srand(time(0));
                int number = rand() % 100 + 1;
                if (number <= 75)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "���ܳɹ�" << endl;
                    Sleep(2000);
                    symbol = false;
                    flag = false;
                    break;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "����ʧ��" << endl;
                    Sleep(2000);
                    roleHurt = 0;
                    break;
                }
            }
            default:
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << "ѡ������ִ�������������" << endl;
                Sleep(1000);
                flag = false;
                break;
            }
        }
        //����ս�����
        if (flag)
        {
            //���BOSS�м��ܵĻ������ʹ��
            if (!boss.bossSkills.empty())
            {
                int size = boss.bossSkills.size();
                int ran = rand() % 6 + 1;
                int num = rand() % size;
                //ʹ�ü���d
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
            cout << "\n���" << boss.getName() << "�����" << dec2 << "���˺�" << endl;
            cout << boss.getName() << "���������" << dec1 << "���˺�\n" << endl;
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
    cout << "ѡ��ս����ʽ��1.ʹ�õ�ҩ 2.ʹ�ö��� 3.��ͨ���� 4.����" << endl;
    string c;
    cin >> c;
    if (c.length() != 1)
        cout << "����������" << endl;
    else
        return stoi(c);
}

//�˳���Ϸ
void Fight::endGame() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    system("cls");
    string back = "���ź����������ս����ʧ���ˣ�ϣ�������µĴ�½���ܹ���ɽ����886";
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
        cout << boss.getName() << "��������ս������" << endl;
        Sleep(2000);
        symbol = false;
        if (boss.getName() == "�����")
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//���ú�ɫ����ɫ���
            string back = "��ϲ��ɹ������˻���ۣ����������ǰ����ǧ����������������";
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

    if (boss.getName() == "������Ȼ")
    {
        system("cls");
        //���û�ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);
        string background1 = "\n\t����֮Լ�Ľ����������Ȼս�ܸ��ա�������ڻص��ң���Ӧ����ϲ�õĳ��������ϸ��ױ������°�ߡ�������������ڣ�����ɽ��ս������֮�ʣ�ҩ�ϸ����ս��ɽ������������ڡ��ڼ��֪��֥��������������ϣ�Ҳ�Ļ����䡣�������Ѿ��ص����ϣ��������ĵ�ָ���������׶�������׷�����ӳ��˼���۹���\n\t�Դ�ƾ������ִ�������������½����һ�δε�����֮�䣬�����ų������޷����ܵ�ʹ�࣬������ǿ��ʵ�������Ŵ�½�۷�ǿ��������";
        for (char i : background1) {
            cout << i;
            Sleep(30);
        }
        cout << endl;
        system("pause");
        system("cls");
    }
    //�ж��Ƿ����������
    if (role->task[role->getTaskId()].getGoal() == boss.getName())
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN);//���ú�ɫ����ɫ��
        cout << "\n����������ɣ�\n" << endl;
        Sleep(2000);
        string back = "\n��ϲ������" + to_string(role->task[role->taskId].getAddGol()) + "����ң�" + to_string(role->task[role->taskId].getAddLv()) + "�㾭�飬" + to_string(role->task[role->taskId].getAddPoint()) + "�����ܵ���\n\n";
        for (char i : back)
        {
            cout << i;
            Sleep(20);
        }
        role->LV += role->task[role->taskId].getAddLv();
        role->Gol += role->task[role->taskId].getAddGol();
        role->Point += role->task[role->taskId].getAddPoint();
        role->taskId++;
        //�ж��Ƿ�����
        role->impLevel();
        system("pause");
    }
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);//���ú�ɫ����ɫ���
    string back = "\n��ϲ������" + to_string(boss.AddGol) + "����ң�" + to_string(boss.AddLv) + "�㾭�飬" + to_string(boss.AddPoint) + "�����ܵ���\n\n";
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




