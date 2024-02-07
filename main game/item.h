#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
using namespace std;


//定义物品
class item      
{
    static int currentID;
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




/*
//韬关于物品的定义：


struct item      //定义物品
{
	char name[50];
	int nbt;                 //物品编号 
	int heavy;
	int size;                //物品占格 
	int num;
};

struct bagpack	//定义背包
{
	int size;
	int level;
	int heavy;
	int object_num;
	struct item bagpack_item[10];
};
void show_bagpack(struct bagpack *a)	//显示背包函数
{
	printf("size:%d   level:%d   heavy:%d  object number:%d\n", a->size, a->level, a->heavy, a->object_num);
	printf("items:\n");
	for (int i = 0; i < (a->object_num); i++)
	{
		printf("%s %d\n", (a->bagpack_item[i]).name, (a->bagpack_item[i]).num);
	}
}


struct treasure	//定义宝藏
{
	int judge;
	int dimension;
	char name[50];
	int object_num;
	struct item treasure_item[5];
	int x_location;
	int y_location;
};
void load_treasure(int x, int y, int dimension,int num, struct treasure *a[max_num_real])	//载入宝藏函数
{
	int restnum=num;
	for (int i = 0;i<max_num_real; i++)
	{
		if (a[i]->judge != 1)
		{
			restnum--;
			a[i]->judge = 1;
			strcpy(a[i]->name, "treasure");
			a[i]->dimension=dimension;
			a[i]->x_location = x;
			a[i]->y_location = y;
		}
	if(restnum==0)
	{
		break;
	}
	}
	return ;
}

*/
