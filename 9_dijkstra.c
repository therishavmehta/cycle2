#include <stdio.h>
#include <limits.h>
#include<time.h>
int V;
  
int minDistance(int dist[], int sptSet[])
{
   int min = INT_MAX, min_index;
   int v;
   for (v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

int printSolution(int dist[], int n)
{
   int i;
   printf("Vertex   Distance from Source\n");
   for (i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
  
void dijkstra(int graph[V][V], int src)
{
     int dist[V],i;  
     int sptSet[V]; 
         for (i = 0; i < V; i++)
	        dist[i] = INT_MAX, sptSet[i] = 0;
  
     dist[src] = 0;
  
     int count,v;
     for (count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
  
       sptSet[u] = 1;
  
       for ( v = 0; v < V; v++)
  
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  printSolution(dist, V);
}
  int main()
{
   /* Let us create the example graph discussed above */
   int n,graph[100][100],i,j;
    FILE *fp1;
    system("rm -rf dijk.txt"); 
    for(n=1;n<=10;n+=1)
   {
   fp1=fopen("dijk.txt","a");
    V=n;
   for(i=0;i<V;i++)
   {
   for(j=0;j<V;j++)
   {
 	graph[i][j]=rand()%10; // scanf("%d",&graph[i][j]);
   }
   }
     clock_t start=clock();
     dijkstra(graph, 0);
     clock_t stop=clock();
     double elapsed=(double)(stop-start)/CLOCKS_PER_SEC;
     //printf("%d\t%f\n",n,elapsed);
     fprintf(fp1,"%d\t",n);
     fprintf(fp1,"%f\n",elapsed);
     fclose(fp1);
     }
  return 0;
}