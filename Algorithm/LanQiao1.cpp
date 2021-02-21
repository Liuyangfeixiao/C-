#include <iostream>
#include <cstdio>

using namespace std;

int a[100];//存所有和尚的初始位置
int b[100];//存两两和尚之间的阶梯数
int minmin=10000;//移动的最小距离
int minA=0;//移动的和尚位置

int main()
{
	int r1=0,r2=0,i,j,s=0;
	//输入
	while(1)
	{
		scanf("%d",&a[r1++]);
		if(getchar()=='\n')
			break;
	}
	
	for(i=0;i<r1-1;i=i+2)
	{
		b[r2]=a[i+1]-a[i]-1;//存两两和尚之间的阶梯数
		s=s^b[r2++];//计算初始局面
	}	
	
	if(s==0)//初始局面异或为0，先发指令者必败
	{
		cout<<-1;
	} 

	else
	{
		for(i=0;i<r2;i++)
		{
			s=0;
			for(j=0;j<r2;j++)
			{
				if(j!=i)
					s=s^b[j];
			}
			if(b[i]>s)//左边的点移动
			{
				if(b[i]-s<minmin)
				{
					minmin=b[i]-s;
					minA=a[i*2];
				}
			}
			else if(b[i]<s)//如果右边有足够的阶梯数可供移动，移动右边的点
			{
				if(a[i*2+1]+s-b[i]<a[i*2+2])
				{
					if(s-b[i]<minmin)
					{
						minmin=s-b[i];
						minA=a[i*2+1];
					}
				}
			}
		} 
		int minB=minA+minmin;
		printf("%d %d",minA,minB);
	}
	return 0;
}