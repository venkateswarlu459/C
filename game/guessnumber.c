    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    int main()
    {
    	int n,a,count=0;
    	srand ( time(NULL) );
    	n = rand() % 1000 + 1;
    	printf("guess the Number from 1 to 1000\n");
    	while(1)
    	{
	    	scanf("%d",&a);	
  		if(a>n)
    		{
    			printf("value is high\n\n");
    			count++;
    		}
	    	else if(a<n)
    		{
	    		printf("value is low\n\n");
    			count++;
	    	}
    		else
    		{
    		printf("Result correct at %dth attempts\n",count+1);
    		break;
    			}
    	}
    	return 0;
    }
