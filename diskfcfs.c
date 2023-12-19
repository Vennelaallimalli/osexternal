
#include <stdio.h>
#include <math.h>
void FCFS(int arr[],int head,int n)
{
	int count = 0;
	int t, distance,i;



	for( i=0;i<n;i++)
	{
		t = arr[i];
		

		distance = abs(t-head);
		count+= distance;
		head = t;
	}

	printf("Total number of seek operations: %d\n",count);
	printf("Seek Sequence is\n");

	for ( i = 0; i < n; i++) {
		printf("%d\n",arr[i]);
	}
}

int main()
{
	int n,i;
	printf("enter the number of n");
	scanf("%d",&n);

	int arr[n];
	printf("enter the value of arrays ");
	for( i=0;i<n;i++)
    {

        scanf("%d",&arr[i]);
    }
	int head;
	printf("enter the value of head ");
	scanf("%d",&head);


	FCFS(arr,head,n);

	return 0;
}
