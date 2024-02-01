#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
//#include <pthread.h>

#define up 72
#define down 80
#define left 75
#define right 77
#define Esc 27

//SetConsoleOutputCP(65001);936:��������,65001:UTF-8, 

void userand(void);                     //���� 
int randint(int a,int b);               //������� 
float randuniform(float a,float b);     //���ʵ�� 
void timesleep(int seconds);            //ʱ����ͣ���Ͼ�ȷ�������1�� 
void timesleeps(double seconds);        //ʱ����ͣ��������ȷ��������ͣ���֮һ�� 
int issu(int);                          //�ж����� 
int add(int a,int b);                   //����λ������� 

void gotoxy(short x,short y);        //�ƶ����
VOID Hide(VOID);                     //���ع�� 
inline void clear(void);             //������Ļ
int * choose_sort(int *p,int n);     //�ݹ�ʵ��ѡ������ 


int add(int a,int b){          //��д����һ������ͨ��λ������� 
	int c=a&b;                 //��Ϊ1+1Ҫ��1����Ҫ����λ�浽c�� 
	c<<=1;                     //��λ 
	if(c==0)return a^b;        //c��0ʱ���ý���c����0ʱ��Ҫ�õݹ�ӵ������ 
	return add(a^b,c);         //0+0=0��0+1=1��1+1=0����λ��������ǡ��������߼����� 
}

void userand(void){srand((unsigned)time(NULL));}
int randint(int a,int b)
	{
//	 srand((unsigned)time(NULL));
	 return rand()%(b-a+1)+a;
	}
float randuniform(float a,float b)
	{
//		srand((unsigned)time(NULL));
		return ((float)(rand()%1000))/1000.0*(b-a)+a;
	}
void timesleep(int seconds)
	{
		int i,j;
		i=time(NULL),j=time(NULL);
		for(;j-i<=seconds;j=time(NULL))
		{
			continue;
		}
	}
void timesleeps(double x){
	int t=10000*x;
	for(int x=0,i=1;i<=t;i++){
		for(int j=1;j<=3385;j++){
					x=(double)x;
				x=sin(x);
			}
		}
}
		
		
int issu(int x){
    if(x==1||x==0)return 0;
    if(x==2)return 1;
    for(int i=2;i<=x/2+1;i++){
        if(x%i==0)return 0;
    }
    return 1;
}

void gotoxy(short x,short y){
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(handle,pos);
}
VOID Hide(VOID){
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
inline void clear(void){
	system("cls");
}

int * choose_sort(int *p,int n){
	if(n==1)return p;
	int max=p[0];
	int j=0;
	for(int i=0;i<n;i++){
		if(p[i]>max){
			max=p[i];
			j=i;
		}
	}
	if(max!=p[n-1])p[n-1]^=p[j]^=p[n-1]^=p[j];
	return choose_sort(p,n-1);
}
