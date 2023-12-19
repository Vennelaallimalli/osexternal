#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int main(){
    int a[100], i, n, HeadMoment = 0, head, count = 0;
    printf("Enter the n value ");
    
    scanf("%d", &n);
    printf("Enter the array values\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter head value\n");
    scanf("%d", &head);
    while (count != n){
        int min = INT_MAX, d, t;
        for (i = 0; i < n; i++)
            {
			d = abs(a[i] - head);
            if (min > d){
                min = d;
                t=i;
            }
        }
        HeadMoment =HeadMoment + min;
        head= a[t];
        a[t] = INT_MAX;
        count++;
    }
    printf("Total head movement is %d \n", HeadMoment);



}


