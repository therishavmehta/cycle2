#include<stdio.h>
#include<stdlib.h>

int *w,*v,**V;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int MFknapsack(int i,int j)
{
	int val;
	if(V[i][j] < 0)
	{
		if(j < w[i])
			val=MFknapsack(i-1,j);
		else
			val=max(MFknapsack(i- 1, j),(v[i] + MFknapsack(i - 1, j - w[i])));
		V[i][j]=val;
	}
	return V[i][j];
}
void main()
{
	int n,k,i,j,res;
	printf("Enter n and capacity\n");
		scanf("%d %d",&n,&k);
	V=(int **)malloc(sizeof(int *)*(n+1));
    for(i=0; i<=n; i++)
         V[i] = (int *)malloc((k+1) * sizeof(int));
    v=(int *)malloc(sizeof(int)*(n+1));
    w=(int *)malloc(sizeof(int)*(n+1));

    for(i=1;i<=n;i++)
    	for(j=1;j<=k;j++)
    		V[i][j]=-1;
    printf("Enter the weights:\n");
    for(i=1;i<=n;i++)
    	scanf("%d",&w[i]);
    printf("Enter the values:\n");
    for(i=1;i<=n;i++)
    	scanf("%d",&v[i]);
    printf("The result is %d\n",MFknapsack(n,k));
}