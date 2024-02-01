#include <stdio.h>
#include <string.h>
#include "NB.h"
struct item
{
	char name[50];
	int nbt;
	int heavy;
	int size;
	int num;
};
struct bagpack
{
	int size;
	int level;
	int heavy;
	int object_num;
	struct item bagpack_item[1000];
};
struct skill
{
	char name[50];
	int damage;
	int level;
	int possibility;
	int pp;
	int anime;
};
struct people
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
struct monster
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
struct treasure
{
	int judge;
	int dimension;
	char name[50];
	int object_num;
	struct item treasure_item[1000];
	int x_location;
	int y_location;
};
struct land

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
void show_bagpack(struct bagpack *a)
{
	printf("size:%d   level:%d   heavy:%d  object number:%d\n", a->size, a->level, a->heavy, a->object_num);
	printf("items:\n");
	for (int i = 0; i < (a->object_num); i++)
	{
		printf("%s %d\n", (a->bagpack_item[i]).name, (a->bagpack_item[i]).num);
	}
}

void load_monster(int x, int y, int num, int dimension, struct monster (*a)[10])
{
	int restnum=num;
	for (int i = 0;i<10; i++)
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
	
	return;
}
void load_people(int x, int y, int num, int dimension, struct people (*a)[10])
{
	int restnum=num;
	for (int i = 0;i<10; i++)
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
	return;
}
void load_treasure(int x, int y, int num, int dimension,struct treasure (*a)[10])
{
	int restnum=num;
	for (int i = 0;i<10; i++)
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
	return;
}
void load_land(int x, int y, int dimension, struct land *a)

{
	a->x_location = x;
	a->y_location = y;
	a->dimension = dimension;
	a->level = 1;
	int judge;
	judge = (randint(1, 10));
	if (judge >= 1 && judge <= 3)
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
		a->land_monster_num = (randint(1, 3));
		
	}
	else if (judge >= 8 && judge <= 9)
	{
		a->land_void_judge = 0;
		a->land_monster_judge = 0;
		a->land_people_judge = 1;
		a->land_treasure_judge = 0;
		a->land_people_num = (randint(1, 2));
		
	}
	else
	{
		a->land_void_judge = 0;
		a->land_monster_judge = 0;
		a->land_people_judge = 0;
		a->land_treasure_judge = 1;
		a->land_treasure_num = (randint(1, 2));
		
	}

	return;
}
int main(void)
{
	int x_setup;
	int y_setup;
	scanf("%d %d", &x_setup, &y_setup);
	struct land earth[x_setup][y_setup];
	struct monster monster_earth[10];
	struct people people_earth[10];
	struct treasure treasure_earth[10];
	struct bagpack bagpack_earth;

	for (int i = 0; i < x_setup; i++)
	{
		for (int j = 0; j < y_setup; j++)
		{
			load_land(i, j, 1, &earth[i][j]);
			if(earth[i][j].land_void_judge == 1)
			{
				;
			}
			
			else if(earth[i][j].land_monster_judge ==1)
			{
				load_monster(i,j,1,earth[i][j].land_monster_num,&monster_earth);
			}
			else if(earth[i][j].land_people_judge == 1)
			{
				load_people(i,j,1,earth[i][j].land_people_num,&people_earth);
			}
			else if(earth[i][j].land_treasure_judge == 1)
			{
				load_treasure(i,j,1,earth[i][j].land_treasure_num,&treasure_earth);
			}

		}
	}

	for(int i=0;i<x_setup;i++)
	{
		for(int j=0;j<y_setup;j++)
	{
		printf("%d %d %d %d\n",earth[i][j].land_void_judge,earth[i][j].land_monster_judge,earth[i][j].land_people_judge,earth[i][j].land_treasure_judge);
		
	}

	}
	
	for(int j=0;j<10;j++)
	{
		if( monster_earth[j].judge!=-1)
		{
			printf("monster%d %d %d %d %d   %d %d\n", monster_earth[j].attack,monster_earth[j].defense,monster_earth[j].luck,monster_earth[j].speed,monster_earth[j].wisdom,monster_earth[j].x_location,monster_earth[j].y_location);
		}
		if( people_earth[j].judge!=-1)
		{
			printf("people%d %d %d %d %d   %d %d\n", people_earth[j].attack,people_earth[j].defense,people_earth[j].luck,people_earth[j].speed,people_earth[j].wisdom,people_earth[j].x_location,people_earth[j].y_location);
		}

		
	}
	// 测试输出

	return 0;
}
