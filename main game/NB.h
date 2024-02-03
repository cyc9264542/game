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

//SetConsoleOutputCP(65001);936:简体中文,65001:UTF-8, 

void userand(void);                     //播种 
int randint(int a,int b);               //随机整数 
float randuniform(float a,float b);     //随机实数 
void timesleep(int seconds);            //时间暂停，较精确，但最低1秒 
void timesleeps(double seconds);        //时间暂停，不够精确，但可暂停万分之一秒 
int issu(int);                          //判断素数 
int add(int a,int b);                   //利用位运算求和 

void gotoxy(short x,short y);        //移动光标
VOID Hide(VOID);                     //隐藏光标 
inline void clear(void);             //清理屏幕
int * choose_sort(int *p,int n);     //递归实现选择排序 


int add(int a,int b){          //先写两个一般整数通过位运算相加 
	int c=a&b;                 //因为1+1要进1，把要进的位存到c中 
	c<<=1;                     //进位 
	if(c==0)return a^b;        //c是0时候不用进，c不是0时候要用递归加到结果上 
	return add(a^b,c);         //0+0=0，0+1=1，1+1=0（进位），发现恰好与异或逻辑相似 
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
