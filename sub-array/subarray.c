#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
int loop =0;
void printSubsequences(int arr[], int n,int sum) 
{
	int opsize=1;
	for(int i=1; i<=n; i++)
        	opsize = opsize * 2;
	for (int counter = 1; counter < opsize; counter++) 
	{ 
		int ssum=0;
		for (int j = 0; j < n; j++)
			if (counter & (1<<j)) 
				ssum+=arr[j];
		if(ssum==sum)
		{
			for (int j = 0; j < n; j++) 
			{
				loop++;
				if (counter & (1<<j)) 
					printf("%3d",arr[j]);
			}
		printf("\n"); 
		}
	} 
} 

// main program 

int main() 
{ 
	int n;
	printf("enter size of array\n");
	scanf("%d",&n); 
	int arr[n];
	printf("enter array elements\n"); 
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int sum;
	printf("enter sum \n");
	scanf("%d",&sum);
	printf("All Non-empty Subsequences\n"); 
	printSubsequences(arr, n,sum); 
	printf("loop = %d\n", loop);
	return 0; 
} 

