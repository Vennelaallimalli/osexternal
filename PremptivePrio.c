
#include<stdio.h>
#include<stdlib.h>


struct node{
 int pid,at,bt,ct,wt,tat,v,tbt,prio;
 };
 void sort(struct node P[],int n);
 void main()
 {
   int n,i;
   printf("Enter number of Processor");
   scanf("%d",&n);
   struct node  P[n];
   printf("Enter Arrival Time , Brust time and  priority of each process");
   for(i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d%d",&P[i].at,&P[i].bt,&P[i].prio);
    }
  sort(P,n);
  
 for(i=0;i<n;i++)
 {
   P[i].tbt=0;
   P[i].v=0;
  } 
  float awt=0,atat=0;
   int t=0,k=0;
  while(k!=n){ 
     int min=9999;
     int idx;
     while(P[0].at>t)
      t++;
        for(i=0;i<n;i++)
           {
              if(P[i].at<=t && P[i].prio<min && P[i].v!=1)
                 {
                     min=P[i].prio;
                    idx=i;
                  }
            }
  if(idx>=0 && idx<n){
       P[idx].bt=P[idx].bt-1;
       P[idx].tbt=P[idx].tbt+1;
       }
  if(P[idx].bt==0)
     {
        P[idx].ct=t+1;
        P[idx].tat=P[idx].ct-P[idx].at;
        P[idx].wt=P[idx].tat-P[idx].tbt;
        k++;
        P[idx].v=1;
        awt=awt+P[idx].wt;
        atat=atat+P[idx].tat;
        printf("%d %d\n",P[idx].pid,P[idx].ct);
     }
  t=t+1;
  }
  printf("\nPid\tAT\tBT\tPrio\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].tbt,P[i].prio,P[i].ct,P[i].tat,P[i].wt);
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
       

  
