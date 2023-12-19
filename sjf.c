 #include<stdio.h>
int main()
{
int n,i,j;
double awt=0,atat=0;
 printf("enter no of process : ");
 scanf("%d",&n);
 int at[n],bt[n],ct[n],wt[n],tat[n];
 printf("enter arrival time and burst time ");
 for(i=0;i<n;i++)
 {
   scanf("%d%d",&at[i],&bt[i]);
 }
 //sort
 for(i=0;i<n;i++)
 {
   for(j=0;j<n-i-1;j++)
   {
     if(at[j]>at[j+1])
     {
       int t=at[j+1];
       at[j+1]=at[j];
       at[j]=t;
       int tt=bt[j+1];
       bt[j+1]=bt[j];
       bt[j]=tt;
     }
     if(at[j]==at[j+1])
     {
       if(bt[j]>bt[j+1])
       {
          int t=at[j+1];
       at[j+1]=at[j];
       at[j]=t;
       int tt=bt[j+1];
       bt[j+1]=bt[j];
       bt[j]=tt;
       }
     }
   }
 }
 for(i=0;i<n;i++)
 ct[i]=-1;
 int ind=0,index;
 ct[0]=at[0]+bt[0];
 for(i=1;i<n;i++)
  {
     int min=1000;
     for(j=1;j<n;j++)
     {
       if(at[j]<ct[ind]&&bt[j]<min&&ct[j]==-1)
       {
         min=bt[j];
         index=j;
       }
     }
     ct[index]=ct[ind]+bt[index];
     ind=index;
  }
  
   for(i=0;i<n;i++)
 {
   tat[i]=ct[i]-at[i];
   wt[i]=tat[i]-bt[i];
 }
 printf("\tat\tbt\tct\ttat\twt\n");
 for(i=0;i<n;i++)
 {
  awt=awt+wt[i];
  atat=atat+tat[i];
  printf("\t%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
 }
 printf("average waiting time = %f\n average turn arround time =%f ",awt/n,atat/n);
 return 0;
  
  
  
  }
 
 
 
 
