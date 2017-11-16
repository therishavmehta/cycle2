#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500
#define START 1000000
#define SKIP 1000000
#define END 10000000
int t[END];
void shifttable(char p[])
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<MAX;i++)
  t[i]=m;
 for(j=0;j<m-1;j++)
  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 n=strlen(src);
 m=strlen(p);
 //printf("\nLength of text=%d",n);
 //printf("\n Length of pattern=%d",m);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k]))
   k++;
  if(k==m)
   return(i-m+1);
  else
   i+=t[src[i]];
 }
 return -1;
}
char* randgen(int n)
{
 char *a = (char*)malloc(n*sizeof(char));
 int i;
 for(i=0;i<n-1;i++)
 {
  a[i]=(rand()%65)+26;
  //printf("%c",a[i]);
 }
 a[i] = '\0';
 return a;
}
void main()
{
 char *src,*p;
 int pos;
 int srcl,pl,n;
 double st,end,diff;
   for(n=START;n<=END;n+=SKIP){
        srand(time(NULL));
        srcl = rand() % 1000;
        pl = rand() % 100;
        src = randgen(n);
        p = randgen(pl);
        clock_t stt = clock();
        shifttable(p);
        pos=horspool(src,p);
        clock_t end1 = clock();
        diff = (double)(end1-stt) / CLOCKS_PER_SEC;
        printf("%d %d %lf\n",n,pos,diff);
        free(src);
        free(p);
   }
}