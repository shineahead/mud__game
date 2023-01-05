# mud游戏

#### 简介
大二小学期C++项目mud游戏

---

## 游戏介绍

​	本mud游戏角色仅有一个，就是萧炎。你要通过不断的打怪升级，一步一步解锁故事的剧情（虽然我们也没有设置很多剧情），然后挨着完成游戏的任务，最后当你击败了魂天帝的时候游戏就结束了。注意：由于本游戏比较粗糙，所以游戏内的游戏数值设置的不是很合理，请多多体谅，虽然应该不会有人真的来玩吧= =。

​	游戏中的玩法仅有购买丹药，学习斗技然后不断地战斗，我们非常贴心地想到了玩家每次战斗之后血量不健康的问题。所以我们的战斗扣血仅仅是在战斗中，战斗一旦完成之后角色自动恢复满血满体力的状态。这也就意味着丹药的提升效果也只是在战斗中才有效。请注意，千万不要在战斗中死掉，因为你一旦死掉，游戏就自动结束了，意味着你就得重新开始玩这款粗糙的游戏了，又得重复一遍枯燥的过程捏。所以在战斗中一旦发现打不过的情况，请记得及时逃跑（我们的逃跑成功几率足足有百分之五十！！！）。对了，我们的游戏还加了存档的功能，所以如果你没有时间一次性通过的话，建议保存信息下回再战！骚年，我很欣赏你这种吃了垃圾吐出来之后留着下次继续吃的心态。

​	还有一个问题，那就是其他游戏几乎都会有的装备和防具，为什么我们没有呢？这当然不是因为我们不会写，其中的原因其实是非常复杂的，一个就是我们没啥时间来写勒，毕竟我都是在展示的前一天凌晨三点半才勉勉强强地写完，但是还没有进行debug的工作，所以第二天早上互测的时候毫不意外地出现了许多的bug，不过请放心，都已经解决掉了（不排除有新的bug我没有发现，毕竟这游戏我自己都没有玩通关）。一把这个项目课堂展示之后，我就一点动它的想法都没有了，虽然看着它这个半成品虽然让我这个强迫症很难受，可是懒癌专治强迫症= =。总而言之，希望你是第一个通关游戏的人，不然，这个游戏可太可怜了，被开发出来就没有人愿意通关它。（说不定日后我功成名就了之后愿意给它重新修缮一下0.0）

---

## 游戏设计中类的说明

1.Role类

在Role类中把人物的属性给放在了私有成员中，然后在公共接口中把每个属性都设置了一个getXXX()函数（所以为什么不直接设置成公有成员呢）。要记得给人物加最大生命值和最大体力值的变量，战斗结束之后方便把当前生命值重新设置回来。在人物中还添加了一个bag的对象，显然它就是人物的背包，放在下面细嗦。噢对，由于要给人物添加任务，所以设置了一个任务类的数组，在初始化对象的时候把所有的任务全部写进去，然后用一个taksId变量来知道当前的任务。其实这里可以用C++的stack容器，完成一个任务就删除栈顶的元素，不过这都是后话了，我也懒得改了。

2.Bag类

bag类，顾名思义就是人物的背包，里面存放的仅有丹药和斗技，至于为什么要把斗技这么奇怪的东西也放在背包里面，那当然是因为方便啊。里面用vector容器存放了丹药类和斗技类，这次我倒是把它们放到了公共成员当中。至于为什么，我老是干些这种事情，代码的撰写规范不统一，就像变量的命名一样......扯远了。在使用丹药之后要判断是否它的数量为0，为0的话直接从vecotor容器里面删除它，其他的都没什么。唯一麻烦的就是，要打印某个丹药或者斗技的详细信息的时候，我无法直接索引到vector数组里面对应的元素，我只有挨个遍历一遍，判断丹药的ID和传入的参数是否一致，见下例。

``` c++
int order = -1;
    for (Elixir e: bagElixir)
    {
        order++;
        if (e.getId() == id)
            break;
    }
    id = order;
```

3.Elixir类

Elixir是丹药类，我观摩别的mud游戏的代码的时候发现了这个巨好用的结构。在丹药的构造函数中传入一个ID，然后把游戏中需要用到的所有丹药都在构造函数中写出来，用switch-case结构，意味着我们每次只需要传入一个ID就可以生成不同的丹药对象了，非常的方便。由于各种丹药的属性不一样，所以在打印具体丹药的信息的时候需要用if语句判断是否为0来决定打印当前属性，我觉得这么写比较蠢但是我又想不到什么较好的方法。

``` c++
if (bagElixir[id].getAddAtt())
        cout << "增加的攻击力为：" << bagElixir[id].getAddAtt() << endl;
```



4.Skills类

这个类就是斗技类，倒是没有什么需要特别注意的，和上面的丹药类大同小异。

5.Drug_store

药铺类，很显然是买丹药的地方。先把所有的丹药给展示一遍然后提升玩家输入ID和数量进行购买，由于需要对人物的背包作一些修改，所以定义了一个Role*的变量，然后就传入role对象的指针，这样就可以往人物背包里面加丹药了。其实一开始用的是引用，但是不知道为什么，用引用的话会有一些奇怪的报错，用了指针之后就正常多了。

6.Learning_skills

一言以蔽之，学习斗技的类。和上面完全一毛一样。

7.Map类

地图类，用于打印地图和移动地图还有存储每个地图的信息。地图类中全部的成员都是公共的，定义了px，py两个坐标用来定位当前在哪个地图里面，移动人物时也是改变的px，py的值。地图的信息我们全部都用的map容器来存储各种信息，比如说地图名字对应的坐标，地图名字对应的怪物种类

``` C++
map<pair<int,int> , string> NameSet; //地图的名字，可以用默认构造函数进行初始化
map<string, bool> ChatPlace;//string是能进行对话的地图名，以及是否对过话
map<string, bool> CanFight;//能进行战斗的地方
map<string, int> TaskPlace;//有任务的地方,后面的数字表示任务的编号
map<string, string> inf;    //每个地图的信息
map<string, vector<Boss>> monster;   //每个地图的野怪
```

8.Boss类

敌人类，和丹药类一样的操作，通过ID直接生成一个对象，还要给Boss也加一些技能，在战斗的时候随机使用。刚开始的时候我还给Boss加了一个体力值，后来觉得没什么必要，因为本身就只有百分之五十的几率放技能，而且就算Boss一直放技能，是不是也非常的合理呢，比如说洛克王国里面那些Boss一旦血量低于百分之多少就一直放那种回血技能，非常赖皮，我可不会学他们这个。

9.Fight类

战斗类，参入角色和敌人的对象进行初始化，人物的参数要传入指针对象。每个回合打印敌人和人物的属性信息，用一个symbol变量来记录战斗是否已经完成，在每个回合结算之后都要判断是否应该结束战斗。然后在战斗过程中给出玩家四个选项：1.普通攻击 2.使用丹药 3.使用斗技 4.逃跑，同样是通过switch-case结构来处理输入的信息。我们设置的造成的伤害值是玩家的攻击力加斗技的威力减去敌人的防御值，在玩家战斗成功之后写一个函数把玩家所有的状态恢复满。

10.Save_data类

保存游戏进度的类，里面只需要分别写保存人物属性，地图属性——是否已经对过话，背包元素。这里新学了一个操作文件的方式，用fstream流文件，写入数据非常的方便

``` c++
ofstream out("map.dat", ios::out);
out << map.px << " " << map.py << " ";
```

11.Read_data类

读入游戏进度的类，照着上面保存数据的方式挨着读进来就没什么问题，要注意的是传入人物对象的指针

``` c++
ifstream inM("role.dat", ios::in);
inM >> map->px >> map->py;
```

12.Origin_define类

初始定义变量的类，刚开始我的想法挺美好的，把所有需要用到的变量进行初始化，比如说每个等级对应的名称啊，每个等级升级所需要的经验啊之类的，想要使用就直接include就行了。但是不知道为什么总是会报重定义的错误，所以后来就把它里面的变量改成了全局变量来使用，还不如直接定义呢，整得那么麻烦。

``` c++
extern map<int, string> levelGrade;
extern void Declaration();
```

13.Task类

任务类，用于这个类比较简单，只有一些简单的任务标题，描述，完成之后获得的东西之类的属性，没什么可说的。



#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
