#include<stdio.h>

int main(){
		int a[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
		int n=20,i,j,k,flag1,flag2,flag3=0,temp[3],pos,pf=0,hit=0,maxx;
		int f=3;
		int frames[] = {-1,-1,-1};
		
		for(i=0;i<n;i++){
			flag1=flag2=flag3=0;
			for(j=0;j<f;j++){
				if(a[i]==frames[j]){
					flag1=flag2=1;
					hit++;
					break;
				}
			}
			
			if(flag1==0){
				for(j=0;j<f;j++){
					if(frames[i]==-1){
						pf++;
						frames[i]=a[i];
						flag2=1;
						break;
					}
				}
			}
			if(flag2 == 0){
				flag3=0;
				for(j=0;j<f;j++){
					temp[j]=-1;
					for(k=i+1;k<n;k++){
						if(frames[j]==a[k]){
							temp[j]=k;
							break;
						}
					}
				}
				
				for(j=0;j<f;j++){
					if(temp[j]==-1){
						pos=j;
						flag3=1;
					}
				}
				if(flag3==0){
					maxx=temp[0];
					pos=0;
					for(j=1;j<f;j++){
						if(maxx<temp[j]){
							maxx = temp[i];
							pos=i;
						}
					}
				}
				frames[pos] = a[i];
				pf++;
				
			}
			for ( j = 0; j < f; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
		}
		printf("page faults: %d\n",pf);
		printf("page hits: %d",hit);
}
