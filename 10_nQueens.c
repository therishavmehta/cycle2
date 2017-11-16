#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int x[50],count=0;
int place(int k,int n);
int main()
{
  int n;
  for(n=1;n<=10;n++){
	  clock_t start = clock();
	  count=0;
	  queen(1,n);
	  clock_t end = clock();
	  double diff = (double)(end-start)/CLOCKS_PER_SEC;
	  printf("%d %s %lf\n",n,(count==1)? "Possible": "Not Possible",diff);
  }
  }
  int place(int k,int i)
  {
    int j;
    for(j=1;j<k;j++)
    if((x[j]==i)||(abs(x[j]-1)==abs(j-k)))
    return 0;
    else
    return 1;
   }
  
   int nqueen(int k,int n)
   {
     int j,i,p;
     for(i=1;i<=n;i++)
     {
       if(place(k,i))
       {
         x[k]=i;
         if(k==n){
		   count = 1;
		   break;
		 }
         else
        nqueen(k+1,n);
       }
     }
   }