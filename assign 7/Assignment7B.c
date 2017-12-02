//vedavikas potnuru 1601cs31 Assignment7B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 1000000
#define max(a,b) (((a)>(b))?(a):(b))


int cmpfunc (const void * a, const void * b)
{

   return ( *(int*)a - *(int*)b );

}




int main(){

     int n,i,m,j;

 printf("Enter no of elements\n");

     scanf("%d",&n);

      int a[n];

 printf("Enter the elements\n");

  for(i=0;i<n;i++){

     scanf("%d",&a[i]);


   }

 printf("Enter the value of m\n");

 scanf("%d",&m);

 qsort(a, n, sizeof(int), cmpfunc);
 
//  int used[n];
 
 
// for(i=0;i<n;i++){

// used[i] = 0;

// }
 
//  int sum=0;
 
//  for(i=n-1;i>0;i--){
 
//  if(used[i]==0){
 
//  for(j=i-1;j>=0;j--){
 
//  if(used[j]==0 && a[i]-a[j]<=m){
 
//  sum = sum + a[i] +a[j];
 
  
//  printf("(%d,%d)\n",a[j],a[i]);
 
 
//  used[i]=1;
 
//  used[j]=1;
 
//  break;
//  }
 
 
 
//  }
 
//  }
 
 
//  }
 
 
 
//  printf("%d\n",sum);
 
 
  int dy[n];

  dy[0] = 0;

  for(i=1;i<n;i++){


   dy[i] = dy[i-1];

 if(i!=0&&a[i]-a[i-1] <= m){


if(i<2){

  dy[i] = max(dy[i],a[i]+a[i-1]);

}else{

  dy[i] = max(dy[i],dy[i-2]+a[i]+a[i-1]);

}

}


}


printf("maximum possible sum of all the pairs is %d.\n",dy[n-1]);

printf("Final pair list :\n");

int total = dy[n-1];

i=n-1;

while(i>=1&&total>=0){

if(a[i]-a[i-1] <= m){

if(i<2){

if(total==a[i]+a[i-1]){

	total-=(a[i]+a[i-1]);
    
   printf("(%d,%d)  ",a[i-1],a[i]);

  i=i-2;

continue;

}

}else{

if(total==dy[i-2]+a[i]+a[i-1]){

	total-=(a[i]+a[i-1]);
    
 printf("(%d,%d)  ",a[i-1],a[i]);

i=i-2;

continue;

}



}

}


i=i-1;


}

printf("\n");


return 0;

}






















