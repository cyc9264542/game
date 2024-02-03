#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
using namespace std;


//定义物品
class item      
{
    static int item::currentID;
public:
    //创造新的物品
    item(string Name,int Weight,int Size,int Num):name(Name),weight(Weight),size(Size),num(Num){
        ID=++currentID;
    };

    //获取物品名称与数量
    void get_info(){
        
        cout<<name<<' '<<num;
    };

    //获取物品重量
    int get_weight(){
        return weight;
    };

    //物品效用
    virtual void utilize()=0;

    

protected:
	string name;
	int ID;                 //物品编号 
	int weight;              //物品重量
	int size;                //物品占格 
	int num;                //堆叠数量

};

int item::currentID=0;
#endif 