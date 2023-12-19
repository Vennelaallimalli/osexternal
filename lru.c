#include<stdio.h>

int findminn(int time[],int f){
	int ans=time[0],pos=0,i;
	for( i=1;i<f;i++){
		if(ans>time[i]){
			pos=i;
			ans=time[i];
		}
	}
	return pos;
}

int main(){
	int a[]={7,0,1,2,0,3,0,4,2,3,0,3,2,3,1,2,0,1,7,0,1};
	int f = 3,flag1=0,flag2=0,i,j,hit=0,time[3],pf=0,counter=0,pos;
	int frames[]={-1,-1,-1};
	int n=20;
	
	
	for(i=0;i<20;i++){
		flag1=flag2=0;
		for(j=0;j<f;j++){
			if(frames[j]==a[i]){
				hit++;
				flag1=flag2=1;
//				counter++;
				time[j]=i+1;
				break;
			}
		}
		if(flag1==0){
			for(j=0;j<f;j++){
				if(frames[j]==-1){
//					counter++;
					frames[j]=a[i];
					time[j]=i+1;
					flag2=1;
					pf++;
					break;
				}
			}
		}
		
		if(flag2==0){
			pos = findminn(time,f);
//			counter++;
			frames[pos]=a[i];
			time[pos]=i+1;
			pf++;
		
		}
		
		for(j=0;j<f;j++){
			printf("%d  ",frames[j]);
		}
		printf("\n");
	}
	printf("pagefaults:%d\n",pf);
		printf("pagehits:%d\n",hit);
}
