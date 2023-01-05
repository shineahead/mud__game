#include "Fight.h"
#include "Map.h"
#include <windows.h>
#include <iostream>
#include "Learning_skills.h"
#include "Drug_store.h"
#include "Save_data.h"
#include "Read_data.h"


using namespace std;

//��һ�Ǽ���15��������10������10������30Ѫ��

//��ʼҳ�����Ⱦ
void InitializerPage()
{
    //������ɫ
    cout << "\n\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << '\t'   << "         0                       0         0      0          0                    0         0               " << endl;
    cout << '\t'   << "    0    0                       0         0     000000000   0         0          0         0               " << endl;
    cout << '\t'   << "     0   0                       0         0    0  0    0    0         0          0     000000000           " << endl;
    cout << '\t'   << "   0     0      00000000   0000000000000  0    0    0  0     0         0         0         0                " << endl;
    cout << '\t'   << "    0    0         0       0     0    0  0           0      0          0        0     0000000000000        " << endl;
    cout << '\t'   << "         0        0        0     0   0  0  0        0  0   0 0    0    0    0  0  0       0                 " << endl;
    cout << '\t'   << " 000000000000000 0 00000   0  0000000      0       0    0    0    0    0    0     0      0                  " << endl;
    cout << '\t'   << "         0      0  0   0   0   0   0       0      0  0   0   0    0    0    0     0     000000000           " << endl;
    cout << '\t'  << "         0         00000   0    0 0        0     0  0  0  0  0    0    0    0     0            0            " << endl;
    cout << '\t'  << "         0                0      0         0       0  0      0    0    0    0     0        0  0             " << endl;
    cout << '\t'  << "         0               0      0 0        0         0  0    0    00000000000     0         00              " << endl;
    cout << '\t'  << "         0              0      0   0       0        0  0     0                    0          0             " << endl;
    cout << '\t'  << "         0             0      0     0      0          0      0                    0           0             " << endl;

}
//���±��������
void PrintStory()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background = "\n\t���ף�������ʷ�Ͽ�ǰ����Ķ���������š�4��Ϳ�ʼ����������һԾ��Ϊ���������������Ķ��ߡ�����÷������޹������С�޲£����˽��Ǽ��е�ٮٮ�ߡ�\n\tȻ����ŵĵ�·���ƺ�ע�����ۡ�����֮ǰ����λ������꣬�⵽������������п�Ĵ�������������������ʮ�ط������۵Ķ�֮������һҹ֮�䣬��Ϊ���У��������ڵĶ�����Ҳ������ʱ������ţ��������ɢ��";
    for (int i = 0; i < background.length(); i++) {
        cout << background[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
    string background6 = "\n\t�����������������ӣ���δ�����˻顭�����ִ�������������������������ʱ��һ���Ļ�������ϵĽ�ָ�︡�֣��������³�Ϊ��������һ���е�ٮٮ�ߣ�Ϊ��һѩ�˻�����ĳ��裬����Ҫ�����ø����ܹ�����̹�����㣬��������Ȼ��������֮Լ��������ħ��ɽ������ҩ�ϵİ����£���һ������ʵ����\n\t��ħ��ɽ������̽�ʶ��Сҽ�ɡ���֥����ʵ���Ϊ������������ϣ�����ͦ�������ɳĮ���������������������Ļ������ɯŮ�����ڽ���Ϊ�Ϲ����ޡ��߲���������������걻�߲�������ѹ�ƣ�����������Ϊ������շ������Լ��ĵ�һ����Դ����������Ļ�\n\t���׸��߼�Լ��������ڣ�һ����ս�������٣�";
    for (int i = 0; i < background6.length(); i++) {
        cout << background6[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");



    //������ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background2 = "\n\tѬ�������׸�磬����֮Լ�������٣����������������д��д��!\n\t���ף��ð������ӣ����ÿ���������ʵ����ΰ�!";
    for (int i = 0; i < background2.length(); i++) {
        cout << background2[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");


    //������ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background3 = "\n\t���ף�����֮Լ�������ˣ�ս�ɣ�\n\t������Ȼ�����ף���ȷʵ���ˣ�����������ǰ�Ǹ����ҷ�����ү��\n\t������Ȼ���Ҵ�δ���ǹ�����ǰ��д�µ����飬Ҳ��δ���ǹ�����֮���Լ����\n\t������Ȼ�����ף����ǲ�����սʤ�ҵģ�����ǰ��ˣ�����Ҳ��ˣ�";
    for (int i = 0; i < background3.length(); i++) {
        cout << background3[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");


    //���û�ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background1 = "\n\t����֮Լ�Ľ����������Ȼս�ܸ��ա�������ڻص��ң���Ӧ����ϲ�õĳ��������ϸ��ױ������°�ߡ�������������ڣ�����ɽ��ս������֮�ʣ�ҩ�ϸ����ս��ɽ������������ڡ��ڼ��֪��֥��������������ϣ�Ҳ�Ļ����䡣�������Ѿ��ص����ϣ��������ĵ�ָ���������׶�������׷�����ӳ��˼���۹���\n\t�Դ�ƾ������ִ�������������½����һ�δε�����֮�䣬�����ų������޷����ܵ�ʹ�࣬������ǿ��ʵ�������Ŵ�½�۷�ǿ��������";
    for (int i = 0; i < background1.length(); i++) {
        cout << background1[i];
        Sleep(30);
    }
    cout << endl;
    system("pause");
    system("cls");


    //������ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background4 = "\n\tҩ�ϣ����ף����ɸ�󶥻���ǳ�֮��������������\n\t���ף��õģ���ʦ��";
    for (int i = 0; i < background4.length(); i++) {
        cout << background4[i];
        Sleep(30);
    }
    cout << endl;
    system("pause");
    system("cls");


    //������ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background5 = "\n\t����ۣ����ף����ѽ��붷�ۣ�����������½�������һ�����ˣ�\n\t���ף��������ɲ�ֹ��һ�˽�����˶��ۣ�\n\t��������𣬷�ӡ��ǧ��������";
    for (int i = 0; i < background5.length(); i++) {
        cout << background5[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
}
void PrintStory1()
{
    system("cls");
    //���ú�ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "���±���" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background = "\n\t���ף�������ʷ�Ͽ�ǰ����Ķ���������š�4��Ϳ�ʼ����������һԾ��Ϊ���������������Ķ��ߡ�����÷������޹������С�޲£����˽��Ǽ��е�ٮٮ�ߡ�\n\tȻ����ŵĵ�·���ƺ�ע�����ۡ�����֮ǰ����λ������꣬�⵽������������п�Ĵ�������������������ʮ�ط������۵Ķ�֮������һҹ֮�䣬��Ϊ���У��������ڵĶ�����Ҳ������ʱ������ţ��������ɢ��";
    for (int i = 0; i < background.length(); i++) {
        cout << background[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
    string background6 = "\n\t�����������������ӣ���δ�����˻顭�����ִ�������������������������ʱ��һ���Ļ�������ϵĽ�ָ�︡�֣��������³�Ϊ��������һ���е�ٮٮ�ߣ�Ϊ��һѩ�˻�����ĳ��裬����Ҫ�����ø����ܹ�����̹�����㣬��������Ȼ��������֮Լ��������ħ��ɽ������ҩ�ϵİ����£���һ������ʵ����\n\t��ħ��ɽ������̽�ʶ��Сҽ�ɡ���֥����ʵ���Ϊ������������ϣ�����ͦ�������ɳĮ���������������������Ļ������ɯŮ�����ڽ���Ϊ�Ϲ����ޡ��߲���������������걻�߲�������ѹ�ƣ�����������Ϊ������շ������Լ��ĵ�һ����Դ����������Ļ�\n\t���׸��߼�Լ��������ڣ�һ����ս�������٣�";
    for (int i = 0; i < background6.length(); i++) {
        cout << background6[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
}
void PrintStory2()
{
    //���û�ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background1 = "\n\t����֮Լ�Ľ����������Ȼս�ܸ��ա�������ڻص��ң���Ӧ����ϲ�õĳ��������ϸ��ױ������°�ߡ�������������ڣ�����ɽ��ս������֮�ʣ�ҩ�ϸ����ս��ɽ������������ڡ��ڼ��֪��֥��������������ϣ�Ҳ�Ļ����䡣�������Ѿ��ص����ϣ��������ĵ�ָ���������׶�������׷�����ӳ��˼���۹���\n\t�Դ�ƾ������ִ�������������½����һ�δε�����֮�䣬�����ų������޷����ܵ�ʹ�࣬������ǿ��ʵ�������Ŵ�½�۷�ǿ��������";
    for (int i = 0; i < background1.length(); i++) {
        cout << background1[i];
        Sleep(30);
    }
    cout << endl;
    system("pause");
    system("cls");
}

extern map<int, string> levelGrade;
extern void Declaration();

void OutChoice(Map& map, Role &role)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
    void DealChoice(int order, Map& map, Role &role);
    string c;
    cout << endl << endl << "1.ս�� 2.�ƶ� 3.���� 4.ѧϰ���� 5.����ҩ 6.�˳���Ϸ 7.�����˳� 8.�鿴����" << endl;
    cin >> c;
    if (c.length() != 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "����������" << endl;
        Sleep(1000);
        system("cls");
    }
    else
        DealChoice(stoi(c), map, role);
}

void DealChoice(int order, Map& map, Role &role)
{
    switch (order)
    {
        case 1:
        {
            if ( !map.ifCanFight()) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << "��ǰλ���޷�����ս��" << endl;
                Sleep(2000);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                cout << "\n";
                for (Boss b: map.monster[map.NameSet[make_pair(map.px, map.py)]])
                {
                    cout << b.getId() << ". " << b.getName() << ": " << b.getDesc() << endl;
                }
                cout << "\nѡ��id����ս��(����0�˳�ѡ��)\n" << endl;
                int num;
                cin >> num;
                if (num == 0)
                    break;
                Boss b(num);
                Fight fight(&role, b);
                //����ս��
                fight.enterFight();
                //ս������������
                fight.setFight();
            }
            break;
        }
        case 2:
        {
Place:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            map.showMap();  //��ӡ��ͼ
            cout << "\n\n��ǰλ�ã�" << map.NameSet[make_pair(map.px, map.py)] << "\n";
            cout << "����w, a, s, d�����ƶ�, ��1�����ͼ";
            char c;
            cin >> c;
            if (c != '1')
            {
                int x, y;
                x = map.px;
                y = map.py;
                switch (c)
                {
                    case 'w': y -= 1;break;
                    case 'a': x -= 1;break;
                    case 's': y += 1;break;
                    case 'd': x += 1;break;
                    default:break;
                }
                if (map.NameSet[make_pair(x, y)].empty()){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << "�޷��ƶ�����ȷ�ĵ�ͼ!" << endl;
                    Sleep(2000);
                }
                else
                    map.Move(c);
                goto Place;
            }
            else
            {
                //�����ͼ
                map.enterMap(map.NameSet[make_pair(map.px, map.py)]);
            }
            break;
        }
        case 3:
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//���ú�ɫ����ɫ���
            cout << "\n����1�鿴��ҩ������2�鿴����\n";
            int num;
            cin >> num;
            if (num == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                role.bag.showBagElixir();
                Sleep(3000);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                role.bag.showBagSkills();
                Sleep(3000);
            }
            break;
        }
        case 4:
        {
            Learning_skills Ls(&role);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            Ls.showSkills();
            Ls.deal();
            break;
        }
        case 5:
        {
            DrugStore Ds(&role);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            Ds.showElixir();
            Ds.deal();
            break;
        }
        case 6:
        {
            //�˳���Ϸ
            exit(0);
        }
        case 7:
        {
            //������Ϸ���˳�
            Save_data Sd;
            Sd.Save(role);
            Sd.Save(map);
            Sd.Save(role.bag);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "\n�ļ�����ɹ�\n" << endl;
            Sleep(1500);
            exit(0);
        }
        case 8:
        {
            //չʾ����
            role.showTask();
            system("pause");
            break;
        }
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "ѡ������ִ�������������" << endl;
            Sleep(1000);
            system("cls");
            break;
    }
}

void NewGame(Role role, Map map)
{
    PrintStory1();
    while (true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        map.showPrePos();
        role.showRole();
        OutChoice(map, role);
        if (role.getLevel() == 9)
            break;
    }
}

void LastGame(Role role, Map map)
{
    //���뱣�������
    Read_data Rd(&role, &role.bag, &map);
    Rd.Read();
    while (true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        map.showPrePos();
        role.showRole();
        OutChoice(map, role);
        if (role.getLevel() == 9)
            break;
    }
}

int main() {
    InitializerPage();
    Declaration();
    Role role;  //���ɽ�ɫ
    Map map;    //���ɵ�ͼ
    cout << "\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t����Ϸ�ɲ�Ը��͸¶�����ĸ�ͬѧ����ͬѧ����ͬѧ���Ǻ�ͬѧ����\n";
    cout << "\t\t\t************************************************************\n\n\n";
    string back = "1.�µ���Ϸ 2.��ȡ�浵 3.�˳���Ϸ";
    cout << '\t' << '\t' << '\t' << '\t';
    for (char i : back)
    {
        cout << i;
        Sleep(30);
    }
    cout << endl;
    int num;
    cin >> num;

   switch (num)
   {
       case 1:
           //�µ���Ϸ
           NewGame(role, map);
           break;
       case 2:
           //�ɵ���Ϸ
           LastGame(role, map);
           break;
       case 3:
           exit(0);
       default:
           break;
   }

    system("pause");
    return 0;
}
