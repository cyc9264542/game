#include <stdio.h>
#include<string.h>
void estr_to_num();//科学计数法转数字


void estr_to_num(char *a,int len)
{
    char s[len];
    strcpy(s,a);
    char s1[200];
    char s2[1000000];
	int t;
	int zhen;
	int num=0;
	
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]!='e')
		{
			num++;
		}
		else
		{
			break;
		}
	}
	int num1=0;
	for(int i=strlen(s)-num;i<strlen(s);i++)

	{

		
		s1[num1]=s[i];
		num1++;
	}
	int zhennum=strlen(s)-strlen(s1)-1;
	for(int i=0;i<zhennum;i++)

	{

		
		s2[i]=s[i];
	}
	

	sscanf(s1,"%d",&t);
	if(zhennum==1)
	{
		sscanf(s,"%de%d",&zhen,&t);
		if(zhen==0)
		{
			printf("0");
		}
		else if(t>=0)
		{
		
		printf("%d",zhen);
		for(int i=0;i<t;i++)
		{
			printf("0");
		}
		}
		else
		{
			for(int i=0;i<-t;i++)
		{
			printf("0");
		}
			printf(".");
			printf("%d",zhen);
		}


	}
	else
	{
		int nump=0;
		if(t==0)
		{
			puts(s2);
		}
		else if(t>0)
		{
			if(t<zhennum-2)
			{
			for(int i=0;i<zhennum;i++)
				{
					if(s2[i]!='.')
					{
						printf("%c",s2[i]);
						nump++;
						
					}
					if(nump==t+1)
					{
						printf(".");
					}
					
				}
			}
			else
			{
				for(int i=0;i<zhennum;i++)
				{
					if(s2[i]!='.')
					{
						printf("%c",s2[i]);
						
					}
				}
				for(int j=0;j<t-(zhennum-2);j++)
						{
						printf("0");
						}
			}
		}
		else
		{

			printf("0.");
			for(int i=0;i<-t-1;i++)
			{
				printf("0");
			}
			for(int i=0;i<zhennum;i++)
				{
					if(s2[i]!='.')
					{
						printf("%c",s2[i]);
						
					}
				}	
				
			
		}



	}
}
