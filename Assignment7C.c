//vedavikas potnuru 1601cs31 Assignment7C.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 1000000

int minsteps(int n)
{
  int a[n+1],i;
  
  for (i=2; i<=n; i++){

        a[i] = INT_MAX;

        }
        
        a[1]=0;

        a[0]=0;

  int parent[n+1];

  parent[0] = 0;

  parent[1] = -1;

  for (i=2; i<=n; i++)
    {
        
          
        if(i%7==0){
          
          int res = a[i/7];

            if (res != INT_MAX && res + 1 < a[i]){

                  a[i] = res + 1;

                 parent[i]=i/7;

                }
          
          }
        if(i%5==0){
          
          int res = a[i/5];

             if (res != INT_MAX && res + 1 < a[i]){

                  a[i] = res + 1;

                  parent[i]=i/5;

                }
          
          }
        if(i%3==0){
          
          int res = a[i/3];

              if (res != INT_MAX && res + 1 < a[i]){

                  a[i] = res + 1;

                  parent[i]=i/3;

                }
          
          }
        if(i%2==0){
          
          int res = a[i/2];

              if (res != INT_MAX && res + 1 < a[i]){

                  a[i] = res + 1;

                  parent[i]=i/2;

                }
          
          }else{
          
          int res = a[i-1];

              if (res != INT_MAX && res + 1 < a[i]){

                  a[i] = res + 1;
          
                  parent[i]=i-1;

           }


          }
          
          
          
    }
  
int s = n;

 while(s!=-1){
  
  if(s!=1)

    printf("%d ->",s);

  else{

     printf("%d ",s);

  }
     s = parent[s];

  }
  
 printf("\n"); 
  
  return a[n];
 
  
}

int main(){

int n,i;

printf("Enter the value of n\n");

scanf("%d",&n);

int minSteps = minsteps(n);

printf("Minimum no of steps required is %d.\n",minSteps);


return 0;

}






















