#include<stdio.h>
int main()
{
	freopen("newBubble.coe","r",stdin);
	freopen("test.coe","w",stdout);
	char a[20];
	printf("memory_initialization_radix=16;\n");
	printf("memory_initialization_vector=\n");
	while(scanf("%s",a)>0)
	{
		printf("%s,\n",a);
	 } 
//	scanf("%s",a);
//	for(int len=13;len>0;len--)
//	for(int i=0;i+1<len;i++)
//		if(a[i]<a[i+1])
//		{
//			int t=a[i];
//			a[i]=a[i+1];
//			a[i+1]=t;
//		}
//	printf("%s",a);
 } 
