#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int parent[1000];

int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}

void main()
{
 int i,j,k,a,b,u,v,n,ne=1;
	int min,mincost=0,cost[1000][1000];
	for(n=100;n<=1000;n+=100){
		mincost=0;ne=1;
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		   cost[i][j] = rand() % n;
		   if(cost[i][j]==0)
			cost[i][j]=999;
		  }
		  
		clock_t start = clock();
		while(ne<n)
		 {
		  for(i=1,min=999;i<=n;i++)
		   for(j=1;j<=n;j++)
		   {
			if(cost[i][j]<min)
			{
			 min=cost[i][j];
			 a=u=i;
			 b=v=j;
			 ne++;
			}
		   }
		  u=find(u);
		  v=find(v);
		  if(uni(u,v)) mincost +=min;
		  cost[a][b]=cost[b][a]=999;
		 }
		clock_t end = clock();
		double diff = (double)(end - start)/CLOCKS_PER_SEC;
		printf("%d %lf\n",n,diff);
	}
 
}