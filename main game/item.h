#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
using namespace std;


//������Ʒ
class item      
{
    static int currentID;
public:
    //�����µ���Ʒ
    item(string Name,int Weight,int Size,int Num):name(Name),weight(Weight),size(Size),num(Num){
        ID=++currentID;
    };

    //��ȡ��Ʒ����������
    void get_info(){
        
        cout<<name<<' '<<num;
    };

    //��ȡ��Ʒ����
    int get_weight(){
        return weight;
    };

    //��ƷЧ��
    virtual void utilize()=0;

    

protected:
	string name;
	int ID;                 //��Ʒ��� 
	int weight;              //��Ʒ����
	int size;                //��Ʒռ�� 
	int num;                //�ѵ�����

};

int item::currentID=0;
#endif 




/*
//躹�����Ʒ�Ķ��壺


struct item      //������Ʒ
{
	char name[50];
	int nbt;                 //��Ʒ��� 
	int heavy;
	int size;                //��Ʒռ�� 
	int num;
};

struct bagpack	//���屳��
{
	int size;
	int level;
	int heavy;
	int object_num;
	struct item bagpack_item[10];
};
void show_bagpack(struct bagpack *a)	//��ʾ��������
{
	printf("size:%d   level:%d   heavy:%d  object number:%d\n", a->size, a->level, a->heavy, a->object_num);
	printf("items:\n");
	for (int i = 0; i < (a->object_num); i++)
	{
		printf("%s %d\n", (a->bagpack_item[i]).name, (a->bagpack_item[i]).num);
	}
}


struct treasure	//���屦��
{
	int judge;
	int dimension;
	char name[50];
	int object_num;
	struct item treasure_item[5];
	int x_location;
	int y_location;
};
void load_treasure(int x, int y, int dimension,int num, struct treasure *a[max_num_real])	//���뱦�غ���
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
