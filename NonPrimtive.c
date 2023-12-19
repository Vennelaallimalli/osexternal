#include<stdio.h>
#include<stdlib.h>
struct node{
 int pid,at,bt,ct,wt,tat,v,prio;
 };

 void sort(struct node P[],int n)
{
	int i,j;
   for( i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
     {
       if(P[j+1].at<P[j].at)
       {
         struct node t=P[j];
         P[j]=P[j+1];
         P[j+1]=t;
        }
       else if(P[j].at==P[j+1].at)
        {
        	if(P[j].bt>P[j+1].bt)
        	{
        	  struct node t=P[j];
        	  P[j]=P[j+1];
        	  P[j+1]=t;
			}
		}
      }
    }
}

 
 void main()
 {
   int n,i,j,gc[10],t1=0,g=1,c=0;
   gc[0]=t1;;
   printf("Enter number of Processes");
   scanf("%d",&n);
   struct node  P[n];
   int ct[n];
   printf("Enter Arrival Time and Brust time and priority of each process");
   for(i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d%d",&P[i].at,&P[i].bt,&P[i].prio);
    }
  sort(P,n);
   int t=0;
  
  for(i=0;i<n;i++)
  P[i].v=0;
  float awt=0,atat=0;
  
  for(i=0;i<n;i++)
  {
    while(P[i].at>t)
     t++;
    int min=9999;
    int idx;
      for(j=0;j<n;j++)
      {
        if( P[j].at<=t && min>P[j].prio && P[j].v!=1)
         {
         min=P[j].prio;
         idx=j;
         }
       }
       P[idx].ct=t+P[idx].bt;
       if(t1<P[idx].at){
        printf("idle ");
        c++;
        t1=P[idx].at;
		gc[g++]=t1;}
       printf("p%d ",P[idx].pid);
       t=P[idx].ct;
       t1=P[idx].ct;
       gc[g++]=t1;
       P[idx].v=1;
       P[idx].tat=P[idx].ct-P[idx].at;
       P[idx].wt=P[idx].tat-P[idx].bt;
       awt=awt+P[idx].wt;
       atat=atat+P[idx].tat;
   }
   int c1=c;
   printf("\n");
   for(i=0;i<=(n+c1);i++)
    printf("%d ",gc[i]);
    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\n");
   for(i=0;i<n;i++)
  printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt);
 printf("awt=%.2f    Average tat=%.2f",awt/n,atat/n);   
 printf("\n");
}




 /*
 Enter number of Processor5
Enter Arrival Time and Brust time and Priority of each point
Processor 1:0 1 2

Processor 2:2 7 1

Processor 3:2 4 3

Processor 4:7 9 4

Processor 5:6 2 3

Gantt Chart
1 Idle 2 3 5 4
Pid     AT      BT      Prio    CT      TAT     WT
1       0       1       2       1       1       0
2       2       7       1       9       7       0
3       2       4       3       13      11      7
5       6       2       3       15      9       7
4       7       9       4       24      17      8
Average Wating time=4.40
 Average Turn Around Time= 9.00
 */   
 
