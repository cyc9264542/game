#include "all.h"
//��ĳ��ͷ�ļ�������ο�people.h��ͷע�� 

//���������д��game�����У������ԣ�û����ĺ����ŵ���Ӧ��ͷ�ļ��У���������д��game��

//���������޸�main fail�ļ��еĴ��룬������������ͻ�������޸�����������ˣ���������ͬʱ�޸ĵ��³�ͻ 

int start_UI(void);                            //��ʼ���� 
void loading_pv(int t);                        //���ض���
int game(void);                                //��Ϸ����



int main(void){	
	userand(); 
	Hide(); 
	
	start_UI();
	
	game();

	return 0;
}



int start_UI(void){
	printf("���������ʼ��Ϸ");
	getch(); 
	clear();
	loading_pv(1);
	
	return 0;
}

void loading_pv(int t){
	clear();
	printf("������");
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
	
	
	
                //躸�Ĳ��Դ��벿��:

	/*
	
	//������ش�С
	struct land earth[x_setup][y_setup];		//��ʼ��ʵ���
	struct monster *monster_earth[max_num_real]; 
	struct people *people_earth[max_num_real];
	struct treasure *treasure_earth[max_num_real];
	for(int i=0;i<max_num_real;i++){			//ָ��ָ��
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
		printf("%d %d %d ���%d\n",earth[i][j].land_void_judge,earth[i][j].land_monster_judge,earth[i][j].land_people_judge,earth[i][j].land_treasure_judge);
		
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
	// �������	
	
	*/
	
	
	
	return 0;
}





