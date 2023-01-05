//
// Created by shineahead on 2022-08-21.
//
//��ͼ��������ʾ�������ڵ�λ��
#pragma once
#ifndef MUD_GAME_MAP_H
#define MUD_GAME_MAP_H
#include<string>
#include<map>
#include<utility>
#include "Boss.h"
#include <vector>

using namespace std;

class Map {
public:
    Map();  //��ʼ��ifChattedȫ��δ�Ի���
    ~Map();

    bool ifCanChat();   //�ж��Ƿ��ܶԻ��������Ƿ��Ѿ��Թ��������޷��Ի�
    bool ifCanFight();  //�ж��Ƿ���ս��
    void showMap();     //��ӡ��ͼ
    void enterMap(string const&name);    //�����ͼ,ͨ��px��py����λ������ĵ�ͼ
    void showPrePos();  //չʾ��ǰ�ط�����Ϣ����������ЩҰ�ֻ�������
    void Move(char order);    //�����ƶ�����,ͨ��idֱ�ӽ���õط�

public:
    map<pair<int,int> , string> NameSet; //��ͼ�����֣�������Ĭ�Ϲ��캯�����г�ʼ��
    map<string, bool> ChatPlace;//string���ܽ��жԻ��ĵ�ͼ�����Լ��Ƿ�Թ���
    map<string, bool> CanFight;//�ܽ���ս���ĵط�
    map<string, int> TaskPlace;//������ĵط�,��������ֱ�ʾ����ı��
    map<string, string> inf;    //ÿ����ͼ����Ϣ
    map<string, vector<Boss>> monster;   //ÿ����ͼ��Ұ��
    //int ChatPlace[10];  //�ܽ��жԻ��ĵط�
    //bool ifChatted[10];  //�Ƿ��Ѿ��Թ���
    // string NameSet[10]; //��ͼ�����֣�������Ĭ�Ϲ��캯�����г�ʼ��
    // int ChatPlace[10];  //�ܽ��жԻ��ĵط�
    // bool ifChatted[10];  //�Ƿ��Ѿ��Թ���
    int px; //x���꣬������λ��ͼ
    int py; //y���꣬������λ��ͼ
};


#endif //MUD_GAME_MAP_H
