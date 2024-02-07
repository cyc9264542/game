/*
#include<string.h>    //没有这个，会导致头文件报错，因为有的函数定义在其他头文件里，但主文件没问题，加上这个
#include"NB.h"        //可能导致头文件包含出问题，但加了条件编译，应该问题不大，反正先注释掉放在这里。 
*/

#define max_num_real 1000  //最大每种实体数量


struct skill	//定义技能
{
	char name[50];
	int damage;
	int level;
	int possibility;
	int pp;
	int anime;
};


struct people	//定义人
{
	int judge;
	int dimension;              //维度 
	char name[50];
	int level;
	int attack;
	int defense;
	int speed;
	int wisdom;
	int luck;
	struct skill *people_skill[5];
	int x_location;
	int y_location;
};
struct monster	//定义怪物
{
	int judge;
	int dimension;
	char name[50];
	int level;
	int attack;
	int defense;
	int speed;
	int wisdom;
	int luck;
	struct skill *monster_skill[5];
	int x_location;
	int y_location;
};

void load_monster(int x, int y, int dimension, int num,struct monster *a[max_num_real])		//载入怪物函数
{
	int restnum=num;
	for (int i = 0;i<max_num_real; i++)
	{

		if (a[i]->judge != 1)
		{
			restnum--;
			a[i]->judge = 1;
			strcpy(a[i]->name, "wolf");
			a[i]->dimension=dimension;
			a[i]->level = 1;
			a[i]->attack = randint(1, 5);
			a[i]->defense = randint(2, 8);
			a[i]->speed = randint(2, 7);
			a[i]->wisdom = randint(1, 6);
			a[i]->luck = randint(1, 4);
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
void load_people(int x, int y, int dimension,int num, struct people *a[max_num_real])		//载入人函数
{
	int restnum=num;
	for (int i = 0;i<max_num_real; i++)
	{
		if (a[i]->judge != 1)
		{
			restnum--;
			a[i]->judge = 1;
			strcpy(a[i]->name, "people");
			a[i]->dimension=dimension;
			a[i]->level = 1;
			a[i]->attack = randint(2, 5);
			a[i]->defense = randint(2, 6);
			a[i]->speed = randint(1, 3);
			a[i]->wisdom = randint(1, 5);
			a[i]->luck = randint(1, 5);
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
