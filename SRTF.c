#include<stdio.h>
#include<stdlib.h>
struct node{
 int at,bt,ct,wt,tat,tbt,v,pid;
 };
 void sort(struct node P[],int n);
    void main()
 {
   int n,i;
   printf("Enter number of Processes"); 
   scanf("%d",&n);
   struct node  P[n];
   printf("Enter Arrival Time and Brust time  of each process");
   for(i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d",&P[i].at,&P[i].bt);
    }
  sort(P,n);
  for(i=0;i<n;i++)
   {
     P[i].v=0;
     P[i].tbt=0;
    }
  int t=0,k=0;
  float awt=0,atat=0;
  printf("Gantt Chart\n");
  while(k!=n){
  int min=9999;
  int index;
  while(P[k].at>t)
  {
  printf("idle ");
   t++;}
  for(i=0;i<n;i++)
  {
    if(P[i].at<=t && P[i].bt<min && P[i].v!=1)
    {
      min=P[i].bt;
      index=i;
     }
   }
  P[index].tbt=P[index].tbt+1;
  printf("P%d ",P[index].pid);
  P[index].bt=P[index].bt-1;
  if(P[index].bt==0)
  {
    P[index].ct=t+1;
    P[index].tat=P[index].ct-P[index].at;
    P[index].wt=P[index].tat-P[index].tbt;
    P[index].v=1;
    k++;
    awt=awt+P[index].wt;
    atat=atat+P[index].tat;
   }
     t=t+1;
}
 printf("\nPid\tAT\tBT\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",P[i].pid,P[i].at,P[i].tbt,P[i].ct,P[i].tat,P[i].wt);
  }
  printf("Average Wating time=%.2f\n Average Turn Around Time= %.2f",awt/n,atat/n);
}
void sort(struct node P[],int n)
{
	int i,j;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(P[j].at>P[j+1].at)
      {
       struct node t=P[j];
       P[j]=P[j+1];
       P[j+1]=t;
      }
    }
  }
}
  
 /*
 Enter number of Processor6
Enter Arrival Time and Brust time  of each processor
Processor 1:0 8

Processor 2:1 6

Processor 3:2 5

Processor 4:3 2

Processor 5:4 4

Processor 6:5 1

P1 P2 P2 P4 P4 P6 P2 P2 P2 P2 P5 P5 P5 P5 P3 P3 P3 P3 P3 P1 P1 P1 P1 P1 P1 P1
Pid     AT      BT      CT      TAT     WT
1       0       8       26      26      18
2       1       6       10      9       3
3       2       5       19      17      12
4       3       2       5       2       0
5       4       4       14      10      6
6       5       1       6       1       0
Average Wating time=6.50
Average Turn Around Time= 10.83

Enter Arrival Time and Brust time  of each process
Processor 1:4 1

Processor 2:6 1

Processor 3:2 2

Processor 4:7 2

Processor 5:5 3

Processor 6:3 4

Processor 7:1 5
P7 P3 P3 P1 P5 P2 P5 P5 P4 P4 P7 P7 P7 P7 P6 P6 P6 P6
Pid     AT      BT      CT      TAT     WT
7       1       5       15      14      9
3       2       2       4       2       0
6       3       4       19      16      12
1       4       1       5       1       0
5       5       3       9       4       1
2       6       1       7       1       0
4       7       2       11      4       2
Average Wating time=3.43
 Average Turn Around Time= 6.00*/
  
  
  
