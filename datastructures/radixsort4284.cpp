#include<stdio.h>
void radixsort(int a[], int n)
{
	int big, nod = 0,steps,count[10], i, j, k,bucket[10][n],loc,div = 1;
	big = a[0], 1;
	for(i=1;i<n;i++)
	{
		if(a[i]>big)
		big =a[i];
	}
	while (big>0)
	{
		nod++;
		big = big/10;
	}
	for(steps = 1;steps<=nod;steps++){
		for(j = 0;j<10;j++){
			count[j]=0;
		}
		for(i=0;i<n;i++)
		{
			loc=(a[i]/div)%10;
			bucket[loc][count[loc]++]=a[i];
		}
		k=0;
		for(j=0;j<10;j++){
			for (i=0;i<count[j];i++){
				a[k]=bucket[j][i];
				k++;
			}
		}
		div=div*10;
	}
}
int main()
{
	int a[100],n,i;
	printf("\nEnter no.of elements");
	scanf("%d",&n);
	printf("enter %d elements",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("after applying radix sort, array elements are:\n");
	for (i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}

