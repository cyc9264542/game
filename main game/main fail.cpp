#include <stdio.h>
#include <string.h>
#include "NB.h"
#define max_num_real 1000  //最大每种实体数量
#define x_setup 10
#define y_setup 10
struct item      //定义物品
{
	char name[50];
	int nbt;
	int heavy;
	int size;
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
	int dimension;
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
struct land		//定义每块地

{
	int dimension;
	int level;
	int x_location;
	int y_location;

	int land_people_judge;
	int land_monster_judge;
	int land_treasure_judge;

	int land_people_num;
	int land_monster_num;
	int land_treasure_num;

	int land_wall_judge;
	int land_void_judge;

	int land_action_num;
	int land_action_judge;

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
void load_land(int x, int y, int dimension,  struct land *a)								//载入地图函数

{
	a->x_location = x;
	a->y_location = y;
	a->dimension = dimension;
	a->level = 1;
	int judge;
	judge = (randint(1, 10));
	if (judge >= 1 && judge <= 3)   //判断载入实体类型
	{
		a->land_void_judge = 1;
		a->land_monster_judge = 0;
		a->land_people_judge = 0;
		a->land_treasure_judge = 0;
	}
	else if (judge >= 4 && judge <= 7)
	{
		a->land_void_judge = 0;
		a->land_monster_judge = 1;
		a->land_people_judge = 0;
		a->land_treasure_judge = 0;
		a->land_monster_num = (randint(2, 3));
		
	}
	else if (judge >= 8 && judge <= 9)
	{
		a->land_void_judge = 0;
		a->land_monster_judge = 0;
		a->land_people_judge = 1;
		a->land_treasure_judge = 0;
		a->land_people_num = (randint(2, 3));
		
	}
	else
	{
		a->land_void_judge = 0;
		a->land_monster_judge = 0;
		a->land_people_judge = 0;
		a->land_treasure_judge = 1;
		a->land_treasure_num = (randint(2, 3));
		
	}

	return;
}
void load(int x,int y,struct land earth[][y_setup],struct monster *monster_earth[],struct people *people_earth[],struct treasure *treasure_earth[])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			load_land(i, j, 1, &earth[i][j]);
			if(earth[i][j].land_void_judge == 1)
			{
				continue;
			}
			
			else if(earth[i][j].land_monster_judge ==1)
			{
				load_monster(i,j,1,earth[i][j].land_monster_num,monster_earth);
			}
			else if(earth[i][j].land_people_judge == 1)
			{
				load_people(i,j,1,earth[i][j].land_people_num,people_earth);
			}
			else if(earth[i][j].land_treasure_judge == 1)
			{
				load_treasure(i,j,1,earth[i][j].land_treasure_num,treasure_earth);
			}

		}
	}

}
int main(void)
{	//读入加载大小
	struct land earth[x_setup][y_setup];		//初始化实体库
	struct monster *monster_earth[max_num_real]; 
	struct people *people_earth[max_num_real];
	struct treasure *treasure_earth[max_num_real];
	for(int i=0;i<max_num_real;i++){			//指针指向
		monster_earth[i]=new monster;
		people_earth[i]=new people;
		treasure_earth[i]=new treasure;
	}
	struct bagpack bagpack_earth;

	load(x_setup,y_setup,earth,monster_earth,people_earth,treasure_earth);

	for(int i=0;i<x_setup;i++)
	{
		for(int j=0;j<y_setup;j++)
	{
		printf("%d %d %d 你好%d\n",earth[i][j].land_void_judge,earth[i][j].land_monster_judge,earth[i][j].land_people_judge,earth[i][j].land_treasure_judge);
		
	}

	}
	
	for(int j=0;j<max_num_real;j++)
	{
		if( monster_earth[j]->judge==1)
		{
			printf("monster%d %d %d %d %d   %d %d\n", monster_earth[j]->attack,monster_earth[j]->defense,monster_earth[j]->luck,monster_earth[j]->speed,monster_earth[j]->wisdom,monster_earth[j]->x_location,monster_earth[j]->y_location);
		}
		if( people_earth[j]->judge==1)
		{
			printf("people%d %d %d %d %d   %d %d\n", people_earth[j]->attack,people_earth[j]->defense,people_earth[j]->luck,people_earth[j]->speed,people_earth[j]->wisdom,people_earth[j]->x_location,people_earth[j]->y_location);
		}

		
	}
	// 测试输出

	return 0;
}
