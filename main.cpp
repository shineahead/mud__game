#include "Fight.h"
#include "Map.h"
#include <windows.h>
#include <iostream>
#include "Learning_skills.h"
#include "Drug_store.h"
#include "Save_data.h"
#include "Read_data.h"


using namespace std;

//升一星级加15攻击力，10体力，10防御，30血量

//初始页面的渲染
void InitializerPage()
{
    //设置蓝色
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
//故事背景的输出
void PrintStory()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background = "\n\t萧炎，萧家历史上空前绝后的斗气修炼天才。4岁就开始修炼斗气，一跃成为家族百年来最年轻的斗者。与青梅竹马萧薰儿，两小无猜，两人皆是家中的佼佼者。\n\t然而天才的道路，似乎注定曲折。三年之前，这位天才少年，遭到了有生以来最残酷的打击，他辛辛苦苦修炼数十载方才凝聚的斗之气旋，一夜之间，化为乌有，而且体内的斗气，也是随着时间的流逝，诡异地消散。";
    for (int i = 0; i < background.length(); i++) {
        cout << background[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
    string background6 = "\n\t家族冷遇，旁人轻视，被未婚妻退婚……种种打击接踵而至。就在他即将绝望时，一缕幽魂从他手上的戒指里浮现，萧炎重新成为家族年轻一辈中的佼佼者，为了一雪退婚带来的耻辱，最重要的是让父亲能够在乌坦城立足，与纳兰嫣然定下三年之约，并来到魔兽山脉，在药老的帮助下，进一步提升实力。\n\t在魔兽山脉，相继结识了小医仙、云芝（真实身份为云岚宗宗主云韵）。后挺进塔戈尔沙漠，遇见正在吞噬青莲地心火的美杜莎女王，在进化为上古异兽“七彩吞天蟒”后，因灵魂被七彩吞天蟒压制，被萧炎收养为宠物。后收服属于自己的第一个本源异火：青莲地心火。\n\t萧炎负尺践约来到云岚宗，一场大战即将来临！";
    for (int i = 0; i < background6.length(); i++) {
        cout << background6[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");



    //设置青色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background2 = "\n\t熏儿：萧炎哥哥，三年之约即将来临，不如让我们先来切磋切磋吧!\n\t萧炎：好啊，妮子！正好看看我如今的实力如何吧!";
    for (int i = 0; i < background2.length(); i++) {
        cout << background2[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");


    //设置青色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background3 = "\n\t萧炎：三年之约，我来了！战吧！\n\t纳兰嫣然：萧炎，你确实变了，不再是三年前那个萧家废物少爷！\n\t纳兰嫣然：我从未忘记过三年前你写下的休书，也从未忘记过你我之间的约定！\n\t纳兰嫣然：萧炎，你是不可能战胜我的！三年前如此，现在也如此！";
    for (int i = 0; i < background3.length(); i++) {
        cout << background3[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");


    //设置黄色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background1 = "\n\t三年之约的结果以纳兰嫣然战败告终。下云岚宗回到家，本应该是喜悦的场景，不料父亲被云岚宗掳走。萧炎再上云岚宗，与云山大战，绝望之际，药老附身对战云山，后逃离云岚宗。期间得知云芝是云岚宗宗主云韵，也心灰意冷。处于两难境地的云韵，听从了心的指引，让萧炎躲过云岚宗追击，逃出了加玛帝国。\n\t自此凭借他的执着与信念，闯荡大陆，在一次次的生死之间，承受着常人所无法承受的痛苦，疯狂地增强着实力，向着大陆巅峰强者迈进。";
    for (int i = 0; i < background1.length(); i++) {
        cout << background1[i];
        Sleep(30);
    }
    cout << endl;
    system("pause");
    system("cls");


    //设置青色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background4 = "\n\t药老：萧炎，星陨阁阁顶汇聚星辰之力，适宜修炼！\n\t萧炎：好的，老师！";
    for (int i = 0; i < background4.length(); i++) {
        cout << background4[i];
        Sleep(30);
    }
    cout << endl;
    system("pause");
    system("cls");


    //设置青色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                                                             FOREGROUND_BLUE);
    string background5 = "\n\t魂天帝：萧炎，我已进入斗帝，整个斗气大陆都将是我魂族的了！\n\t萧炎：这个世界可不止你一人进入的了斗帝！\n\t我生化异火，封印你千载万世！";
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
    //设置红色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "故事背景" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background = "\n\t萧炎，萧家历史上空前绝后的斗气修炼天才。4岁就开始修炼斗气，一跃成为家族百年来最年轻的斗者。与青梅竹马萧薰儿，两小无猜，两人皆是家中的佼佼者。\n\t然而天才的道路，似乎注定曲折。三年之前，这位天才少年，遭到了有生以来最残酷的打击，他辛辛苦苦修炼数十载方才凝聚的斗之气旋，一夜之间，化为乌有，而且体内的斗气，也是随着时间的流逝，诡异地消散。";
    for (int i = 0; i < background.length(); i++) {
        cout << background[i];
        Sleep(15);
    }
    cout << endl;
    system("pause");
    system("cls");
    string background6 = "\n\t家族冷遇，旁人轻视，被未婚妻退婚……种种打击接踵而至。就在他即将绝望时，一缕幽魂从他手上的戒指里浮现，萧炎重新成为家族年轻一辈中的佼佼者，为了一雪退婚带来的耻辱，最重要的是让父亲能够在乌坦城立足，与纳兰嫣然定下三年之约，并来到魔兽山脉，在药老的帮助下，进一步提升实力。\n\t在魔兽山脉，相继结识了小医仙、云芝（真实身份为云岚宗宗主云韵）。后挺进塔戈尔沙漠，遇见正在吞噬青莲地心火的美杜莎女王，在进化为上古异兽“七彩吞天蟒”后，因灵魂被七彩吞天蟒压制，被萧炎收养为宠物。后收服属于自己的第一个本源异火：青莲地心火。\n\t萧炎负尺践约来到云岚宗，一场大战即将来临！";
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
    //设置黄色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                             FOREGROUND_GREEN);
    string background1 = "\n\t三年之约的结果以纳兰嫣然战败告终。下云岚宗回到家，本应该是喜悦的场景，不料父亲被云岚宗掳走。萧炎再上云岚宗，与云山大战，绝望之际，药老附身对战云山，后逃离云岚宗。期间得知云芝是云岚宗宗主云韵，也心灰意冷。处于两难境地的云韵，听从了心的指引，让萧炎躲过云岚宗追击，逃出了加玛帝国。\n\t自此凭借他的执着与信念，闯荡大陆，在一次次的生死之间，承受着常人所无法承受的痛苦，疯狂地增强着实力，向着大陆巅峰强者迈进。";
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
                                                             FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
    void DealChoice(int order, Map& map, Role &role);
    string c;
    cout << endl << endl << "1.战斗 2.移动 3.背包 4.学习技能 5.购买丹药 6.退出游戏 7.保存退出 8.查看任务" << endl;
    cin >> c;
    if (c.length() != 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout << "输入过多参数" << endl;
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
                cout << "当前位置无法进行战斗" << endl;
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
                cout << "\n选择id进行战斗(输入0退出选择)\n" << endl;
                int num;
                cin >> num;
                if (num == 0)
                    break;
                Boss b(num);
                Fight fight(&role, b);
                //进入战斗
                fight.enterFight();
                //战斗场景的设置
                fight.setFight();
            }
            break;
        }
        case 2:
        {
Place:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            map.showMap();  //打印地图
            cout << "\n\n当前位置：" << map.NameSet[make_pair(map.px, map.py)] << "\n";
            cout << "输入w, a, s, d进行移动, 按1进入地图";
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
                    cout << "无法移动到正确的地图!" << endl;
                    Sleep(2000);
                }
                else
                    map.Move(c);
                goto Place;
            }
            else
            {
                //进入地图
                map.enterMap(map.NameSet[make_pair(map.px, map.py)]);
            }
            break;
        }
        case 3:
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                     FOREGROUND_GREEN);//设置红色和绿色相加
            cout << "\n输入1查看丹药，输入2查看斗技\n";
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
            //退出游戏
            exit(0);
        }
        case 7:
        {
            //保存游戏并退出
            Save_data Sd;
            Sd.Save(role);
            Sd.Save(map);
            Sd.Save(role.bag);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "\n文件保存成功\n" << endl;
            Sleep(1500);
            exit(0);
        }
        case 8:
        {
            //展示任务
            role.showTask();
            system("pause");
            break;
        }
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "选择的数字错误请重新输入" << endl;
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
    //读入保存的数据
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
    Role role;  //生成角色
    Map map;    //生成地图
    cout << "\n\n";
    cout << "\t\t\t************************************************************\n";
    cout << "\t\t\t本游戏由不愿意透露姓名的甘同学，郭同学，韩同学还是韩同学制作\n";
    cout << "\t\t\t************************************************************\n\n\n";
    string back = "1.新的游戏 2.读取存档 3.退出游戏";
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
           //新的游戏
           NewGame(role, map);
           break;
       case 2:
           //旧的游戏
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
