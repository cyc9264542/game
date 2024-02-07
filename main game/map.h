//若头文件报错，请参考people.h开头注释 

#define x_setup 10         //地图尺寸 
#define y_setup 10

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
				//load_treasure(i,j,1,earth[i][j].land_treasure_num,treasure_earth);
			}

		}
	}

}
