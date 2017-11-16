#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int binomial(int n,int k)
{
	int **c,i,j;
	c=(int **)malloc(sizeof(int *)*(n+1));
	
    for (i=0; i<=n; i++)
         c[i] = (int *)malloc((k+1) * sizeof(int));
     
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=(min(i,k));j++)
		{
			if(j==0 || j==i)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];

		}
	}
	return c[n][k];
}
void main()
{
	int n,k,res;
	printf("Enter n and k\n");
		scanf("%d %d",&n,&k);
	res=binomial(n,k);
	printf("%d\n",res);
}