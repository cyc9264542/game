/*
#include<string.h>    //û��������ᵼ��ͷ�ļ�������Ϊ�еĺ�������������ͷ�ļ�������ļ�û���⣬�������
#include"NB.h"        //���ܵ���ͷ�ļ����������⣬�������������룬Ӧ�����ⲻ�󣬷�����ע�͵�������� 
*/

#define max_num_real 1000  //���ÿ��ʵ������


struct skill	//���弼��
{
	char name[50];
	int damage;
	int level;
	int possibility;
	int pp;
	int anime;
};


struct people	//������
{
	int judge;
	int dimension;              //ά�� 
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
struct monster	//�������
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

void load_monster(int x, int y, int dimension, int num,struct monster *a[max_num_real])		//������ﺯ��
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
void load_people(int x, int y, int dimension,int num, struct people *a[max_num_real])		//�����˺���
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
