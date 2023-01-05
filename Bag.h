//
// Created by shineahead on 2022-08-21.
//
#pragma once
#ifndef MUD_GAME_BAG_H
#define MUD_GAME_BAG_H
#include<map>
#include<vector>
#include "Elixir.h"
#include "Skills.h"

using namespace std;
//�����������ֻ�ܷ�20��ҩ��ѧϰ10�ֶ���


class Bag {
public:

    Bag();
    ~Bag();
    int getMaxElixir();  //�õ���󱳰�����
    void showElixir(int id);   //�õ���������Ϊid�ĵ�ҩ��Ϣ
    void showSkill(int id);   //�õ���������Ϊid�ļ�����Ϣ
    void showBagElixir();    //չʾ�����ĵ�ҩ
    bool ifUseElixir(); //�ж��Ƿ���ҩ����ʹ��
    int getElixirNum(int id);  //�õ�������ĵ�ҩ������
    //Bag& addGoods(int id, int type, int num);    //������������ӵ�ҩ
    void reduceElixir(int id, int type, int num);   //���ٱ�������ĵ�ҩ
    void showBagSkills();  //չʾ���еĶ���
    //bool addSkills(int id);   //����������Ӷ���
    void ifDeleteElixir();  //�ж��Ƿ���Ҫ�ѵ�ҩ�ӱ�����ɾ��
    Bag& operator=(Bag const& b);
    vector<Elixir> bagElixir;   //��vector���洢��ҩ
    vector<Skills> bagSkills;   //��vector���洢����

private:
    int max_Elixir_num;  //���ҩ�洢��
    int max_skills_num;
};

#endif //MUD_GAME_BAG_H
