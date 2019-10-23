#include<stdio.h>
#include<string.h>

void findLCS(char *X, char *Y, int XLen, int YLen)
{
	int L[XLen + 1][YLen + 1];
	int r, c, i;
  
	//  find the length of the LCS
 
	for(r = 0; r <= XLen; r++)
	{
		for(c = 0; c <= YLen; c++)
		{
		    if(r == 0 || c == 0)
		        L[r][c] = 0;

			else if(X[r - 1] == Y[c - 1])
    		    L[r][c] = L[r - 1][c - 1] + 1;

			else
			{
				if(L[r - 1][c]>L[r][c - 1])
					L[r][c]=L[r-1][c];
				else
					L[r][c]=L[r][c-1];
	    	}
		printf("  %d  ",L[r][c]);	
    	}
		printf("\n");
	}

	//  Print LCS
   
	r = XLen;
	c = YLen;
	i = L[r][c];

	char LCS[i+1];

	// * setting the NULL character at the end of LCS character array.
	LCS[i] = '\0';

	while(r > 0 && c > 0)
	{
		if(X[r - 1] == Y[c - 1])
		{
	    	LCS[i - 1] = X[r - 1];
	    	i--;
	    	r--;
	    	c--;
	    }
		else if(L[r - 1][c] > L[r][c - 1])
			r--;
		else
    	  c--;
	}

	//print result
	printf("Length of the LCS: %d\n", L[XLen][YLen]);
	printf("LCS: %s\n", LCS);
}

int main(void)
{
  //the two sequences
	char X[20],Y[20];
	printf("enter 1st string\n");
	scanf("%s",X);
	printf("enter 2nd string\n");
	scanf("%s",Y);
  //length of the sequences
  int XLen = strlen(X);
  int YLen = strlen(Y);

  findLCS(X, Y, XLen, YLen);

  return 0;
}
