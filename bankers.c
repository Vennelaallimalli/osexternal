#include<stdio.h>

int main(){
	int p,r,i,j,z,flag=0,final=0,y,k,fz;
	printf("enter no. of process and resources");
	scanf("%d%d",&p,&r);
	int allocate[p][r];
	int max[p][r];
	int avail[r],need[p][r];
	int f[p],ans[p];
	printf("enter allocated matrix:");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d",&allocate[i][j]);
		}
	}
	printf("enter max matrix:");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<p;i++){
		f[i]=0;
	}
	
	printf("enter available resources:");
	for(i=0;i<r;i++){
		scanf("%d",&avail[i]);
	}
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-allocate[i][j];
		}
	}
	z=0;
	while(z<p){
		fz=0;
		for(i=0;i<p;i++){
			
			flag=1;
			
			for(j=0;j<r;j++){
				if(need[i][j]>avail[j]){
					flag=0;
					break;
				}
			}
				if(flag==1 && f[i]==0){
					ans[z]=i;
					f[i]=1;
					fz=1;
						z++;
				for(y=0;y<r;y++){
					avail[y]+=allocate[i][y];
				}
			
			
			}
			}
			if(fz==0 && k<=p)printf("not safe");
		}
	
	
	flag=0;
	for(i=0;i<p;i++){
		if(f[i]==0){
			flag=1;
			printf("no safe sequence");
		}
	}
	if(flag==0){
		printf("safe seq is:");
		for(i=0;i<p;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	printf("need matrix is:\n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			printf("%d ",need[i][j]);
}
printf("\n");}
}
