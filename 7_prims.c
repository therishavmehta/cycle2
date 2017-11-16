#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a,b,u,v,n,i,j,ne=1,k;
	int *visited,min,mincost=0,**cost;
	for(k=100;k<=1000;k+=100)
	{
		n=k;
		cost=(int**)malloc(sizeof(int*)*n);
		for(i=1;i<=n;i++)
		   cost[i]=(int*)malloc(sizeof(int)*n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cost[i][j]=rand()%20;
				if(cost[i][j]==0)
					cost[i][j]=999;
			}
		visited=(int*)malloc(sizeof(int)*n);
		visited[1]=1;
		printf("\n");
		clock_t st=clock();
		while(ne<n)
		{
			for(i=1,min=999;i<=n;i++)
				for(j=1;j<=n;j++)
					if(cost[i][j]<min)
						if(visited[i]!=0)
						{
							  min=cost[i][j];
							  a=u=i;
							  b=v=j;
						}
					if(visited[u]==0 || visited[v]==0)
					  {
					   printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
					   mincost+=min;
					   visited[b]=1;
					  }
					cost[a][b]=cost[b][a]=999;
		}
		clock_t stop=clock();
		double elapsed=(double)(stop-st)/CLOCKS_PER_SEC;
		printf("%d\t%f\n",n,elapsed);
	}
}