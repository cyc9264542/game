#include "all.h"
//若某个头文件报错，请参考people.h开头注释 

//将主体代码写在game函数中，并调试，没问题的函数放到对应的头文件中，函数调用写在game中

//请勿轻易修改main fail文件中的代码，否则可能引起冲突，如需修改请告诉其他人，避免两人同时修改导致冲突 

int start_UI(void);                            //开始界面 
void loading_pv(int t);                        //加载动画
int game(void);                                //游戏主体



int main(void){	
	userand(); 
	Hide(); 
	
	start_UI();
	
	game();

	return 0;
}



int start_UI(void){
	printf("按任意键开始游戏");
	getch(); 
	clear();
	loading_pv(1);
	
	return 0;
}

void loading_pv(int t){
	clear();
	printf("加载中");
		for(int i=1;i<=t;i++){
			timesleeps(0.2);
			putchar('.');
			timesleeps(0.25);
			putchar('.');
			timesleeps(0.25);
			putchar('.');
			timesleeps(0.2);
			printf("\b\b\b   \b\b\b");
		}
		printf("\r      \r");
	
}

int game(void){
	
	
	
                //韬哥的测试代码部分:

	/*
	
	//读入加载大小
	struct land earth[x_setup][y_setup];		//初始化实体库
	struct monster *monster_earth[max_num_real]; 
	struct people *people_earth[max_num_real];
	struct treasure *treasure_earth[max_num_real];
	for(int i=0;i<max_num_real;i++){			//指针指向
		monster_earth[i]=new monster;
		people_earth[i]=new people;
		//treasure_earth[i]=new treasure;
	}
	//struct bagpack bagpack_earth;

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
	
	*/
	
	
	
	return 0;
}





