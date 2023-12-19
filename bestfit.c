#include<stdio.h>
int main()
{
	int m,n,i,j,sum=0,bsum=0,intf=0;
	printf("enter number of blocks: ");
	scanf("%d",&m);
	int b[m],a[m];
	printf("\n enter the each block size: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nenter number of processors: ");
	scanf("%d",&n);
	int p[n],flag[n];
	printf("\n enter the each processor size: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<m;i++)
	{
		a[i]=0;
	}
	//best fit
	printf("processor\tsize\tblock\n");
	int index;
	for(i=0;i<n;i++)
	{
		int min=999999;
		index=-1;
		for(j=0;j<m;j++)
		{
			if(p[i]<=b[j] && a[j]!=-1)
			{
				if(min>b[j])
				{
					min=b[j];
					index=j;
				}
			
			}
		}
		if(index!=-1)
		{
				a[index]=-1;
				printf("p%d\t\t%d\t%d\t",i+1,p[i],index+1);
				printf("\n");
				flag[i]=1;
					intf=intf+(b[index]-p[i]);		
		}
		
		if(flag[i]!=1)
		{
			sum=sum+p[i];
				printf("p%d\t\t%d\tnot allocated\n",i+1,p[i]);
		}
			
			
	}
		for(i=0;i<m;i++)
	{
		if(a[i]!=-1)
		{
		   bsum=bsum+b[i];
		}
	}
	if(sum>=bsum)
		printf("\nno external fragmentation");
	else
	{
		printf("\nexternal fragmentation is there");
	}
	printf("\ninternal fragmentation is %d",intf);
	
	
}
