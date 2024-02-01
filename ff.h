#include <stdio.h>
#include<string.h>
void estr_to_num(char *a,int len);//科学计数法转数字
void fengshu_to_xunhuan(int x,int y);//分数转循环小数
void fengshu_to_xunhuan(int x,int y)
{
int xun(int j,int k)
{
    int a[10000];
    int c[10000];
    int b[10000];
    int n=0,isok=0;
    for(int i=0;i<10000;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<10000;i++)
    {
        c[i]=100000;
    }
    for(int i=0;i<10000;i++)
    {
        b[i]=0;
    }
    a[j]=1;
    c[j]=-1;
    while(1==1)
    {
        b[n]=(j*10)/k;
        j=(j*10)%k;
        if(n<c[j])
        {
            c[j]=n;
        }
        if(a[0]==1)
        {
            isok=1;
            break;
        }
        if(a[j]==1)
        {
            break;
        }
        a[j]=1;
        n++;
    }

    if(isok==1)
    {
        for(int p9=0;p9<n;p9++)
        {
        printf("%d",b[p9]);
        }
        printf("(0)");
    }
    else
    {
        for(int p7=0;p7<=c[j];p7++)
        {
        printf("%d",b[p7]);
        }
        printf("(");
        for(int p8=c[j]+1;p8<=n;p8++)
        {
        printf("%d",b[p8]);
        }
        printf(")");

    }
}
    if(x>y)
    {
        if(x%y==0)
        {
            printf("%d.(0)",x/y);
        }
        else
        {
        int zh,yu;
        zh=x/y;
        yu=x%y;
        printf("%d.",zh);
        xun(yu,y);

        }
    }
    else if(x<y)
    {

        printf("0.");
        xun(x,y);
    }
    else
    {
        printf("1.(0)");
    }

}
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
