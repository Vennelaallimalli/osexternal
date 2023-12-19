
#include<stdio.h>

int  fifo(int a[],int n,int size)
{
    
    int frames[n],i,j;
    for (i=0;i<n;i++)
        frames[i]=-1;

    int index=-1;

    int page_faults=0;
    int page_hits=0;

    for (i=0;i<size;i++)
    {
        int symbol=a[i];
        int flag=0;

        for(j=0;j<n;j++)
        {
            if (symbol==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            printf("\nSymbol: %d  Frame: ",symbol);
            for (j=0;j<n;j++)
                printf("%d ",frames[j]);
            page_hits+=1;
        }
        else
        {
            index=(index+1)%n;
            frames[index]=symbol;
            page_faults+=1;
            printf("\nSymbol: %d  Frame: ",symbol);
            for (j=0;j<n;j++)
                printf("%d ",frames[j]);
        }
    }
    printf("\nPage hits: %d",page_hits);
    printf("\nPage faults: %d",page_faults);
}


int main()
{
    int n,i,no_frames;
    printf("enter no of frames:");
    scanf("%d",&no_frames);
    printf("enter size of ref str:");
    scanf("%d",&n);
    int a[n];
    printf("enter the refference string:");
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
    fifo(a,no_frames,n);
    return 0;
}
 
