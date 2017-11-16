#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int **floyd(int **a,int n)
{
	int **r1,i,j,k;
	r1=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         r1[i]=(int *)malloc(n * sizeof(int));
    r1=a;
    for(k=0;k<n;k++)
    	for(j=0;j<n;j++)
    		for(i=0;i<n;i++)
    			r1[i][j]=min(r1[i][j],(r1[i][k]+r1[k][j]));
    return r1;
}
void main()
{
	int **a,**res,i,j,n;
	printf("Enter the number of nodes:\n");
		scanf("%d",&n);
	printf("Enter adjacency matrix:(Enter 1000 for edge with no weight)\n");
	a=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         a[i]=(int *)malloc(n * sizeof(int));
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		scanf("%d",&a[i][j]);
    res=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         res[i]=(int *)malloc(n * sizeof(int));
    res=floyd(a,n);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    		printf("%d\t",res[i][j]);
    	printf("\n");
    }
}