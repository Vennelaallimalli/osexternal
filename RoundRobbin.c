 //Round Robin
#include<stdio.h>
#include<stdlib.h>
struct node{
 int at,bt,ct,wt,tat,tbt,v,pid,q;
 };
 void sort(struct node P[],int n);
 int rear=-1,front=-1;
#define x 50
int Q[x];
void enqueue(int val )
{
 if(rear==-1 && front==-1)
 {
 rear=front=0;
 Q[rear]=val;
 }
 else if(rear>=x-1)
    printf("Q is full\n");
 else
   Q[++rear]=val;
}
int dequeue()
{
  int a=Q[front];
  if(front==-1 || front>rear)
    printf("Q is empty\n");
    else if(front==rear){
     front=-1;
     rear=-1;
     }
   else
    front++;
    return a;
 }
 void EnterQueue(struct node P[],int t,int n)
 {
 	int i;
   for(i=0;i<n;i++)
   {
     if(P[i].at<=t && P[i].v!=1 && P[i].q!=1){
       enqueue(i);
     //  printf("%d ",P[i].pid);
       P[i].q=1;
      }
   }
 //  display();
}
void display()
{
 int i;
 for(i=front;i<rear+1;i++)
  printf("%d  ",Q[i]);
  printf("\n");
 }
 
    void main()
 {
   int n,TQ,i;
   printf("Enter number of Processor and TQ"); 
   scanf("%d%d",&n,&TQ);
   struct node  P[n];
  // int ct[n];
   printf("Enter Arrival Time and Brust time  of each processor");
   for(i=0;i<n;i++)
   {
     // printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d",&P[i].at,&P[i].bt);
      P[i].tbt=0;
      P[i].v=0;
      P[i].q=0;
    }
    sort(P,n);
  int k=0;
  int t=P[0].at;
  float awt=0,atat=0;
  EnterQueue(P,t,n);
  display();
  while(k<n)
  {
      
       int id=dequeue();
       if(P[id].bt<TQ){
       P[id].tbt=P[id].tbt+P[id].bt;
       t=t+P[id].bt;
       P[id].bt=0;
       P[id].v=1;
       P[id].ct=t;
        P[id].tat=P[id].ct-P[id].at;
        P[id].wt=P[id].tat-P[id].tbt;
        k++;
        awt=awt+P[id].wt;
        atat=atat+P[id].tat;
       EnterQueue(P,t,n);
      }
     else{
     P[id].tbt=P[id].tbt+TQ;
     P[id].bt=P[id].bt-TQ;
     t=t+TQ;
     
     if(P[id].bt>0){
     EnterQueue(P,t,n);
      enqueue(id);
      
      }
     else
     {
       P[id].bt=0;
       P[id].v=1;
       P[id].ct=t;
        P[id].tat=P[id].ct-P[id].at;
        P[id].wt=P[id].tat-P[id].tbt;
        k++;
        awt=awt+P[id].wt;
        atat=atat+P[id].tat;
       EnterQueue(P,t,n);
     }
     printf("%d ",P[id].pid);
     }
     
    
}
       

 printf("\nArrival Time,Bruste Time,Completion Time,Turn around Time ,Waiting Time of Each Processor\n");
  for(i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t\n",P[i].at,P[i].tbt,P[i].ct,P[i].tat,P[i].wt);
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

     
   
        
       
    
    
    
    
