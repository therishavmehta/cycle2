#include<stdio.h>
#include<stdlib.h>

int logical(int a,int b,int c)
{
	if(a==1)
		return 1;
	return (b*c);
}
int **warshall(int **a,int n)
{
	int **r1,**r2,i,j,k;
	r1=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         r1[i]=(int *)malloc(n * sizeof(int));
    r2=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         r2[i]=(int *)malloc(n * sizeof(int));
    r1=a;
    r2=a;
    for(k=0;k<n;k++)
    {
    	r1=r2;
    	for(j=0;j<n;j++)
    		for(i=0;i<n;i++)
    			r2[i][j]=logical(r1[i][j],r1[i][k],r1[k][j]);
    }
    return r2;
}
void main()
{
	int **a,**res,i,j,n;
	printf("Enter the number of nodes:\n");
		scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	a=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         a[i]=(int *)malloc(n * sizeof(int));
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		scanf("%d",&a[i][j]);
    res=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
         res[i]=(int *)malloc(n * sizeof(int));
    res=warshall(a,n);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    		printf("%d\t",res[i][j]);
    	printf("\n");
    }
}