//vedavikas 1601cs31 Assignment9B.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INT_MAX 999999

//PLEASE USE gcc Assignment9B.c -lm while compiling this code as I used math.h library for finding log values..

int minDist(float mi[], bool vis[],int n)
{
   
   float min = INT_MAX;
   int min_ind,i;
  
   for (i = 0; i < n; i++){
     if (vis[i] == false && mi[i] <= min){
         min =mi[i], min_ind = i;
         
         }
         
         }
  
   return min_ind;
   
}



void printPath(int par[], int x)
{
   
if(x!=INT_MAX&&x!=-1){
  int y = x;

 x = par[x];

 printPath(par,x);

 printf("%d -> ",y+1);

}else{
  return;
}


}


float realiblepath(float **adj,bool vis[],float mi[],int n,int st,int end,int **adjM1){


     int i;

  int par[n];
  
  par[st-1] =-1;
  
  for (i = 0; i < n; i++)
     {
       par[i] = INT_MAX;
       
       }
       
     for (i = 0; i < n-1; i++)
     {
       
       int u = minDist(mi,vis,n);
  
    
       vis[u] = true;
  
       int v;
     
       for (v = 0; v < n; v++)
  
        
         if (!vis[v] && adjM1[u][v]>0 && mi[u] != INT_MAX && mi[u]+adj[u][v] < mi[v]){
         
            mi[v] = mi[u] + adj[u][v];
            
            par[v] = u;
            
            
            }
            
     }
     
// int x = par[end-1];

// printf("%d <-",end);

// while(x!=INT_MAX&&x!=-1){

// printf("%d <-",x+1);

// x = par[x];

// }

if(mi[end-1]!=INT_MAX){

printPath(par,par[end-1]);

printf("%d ",end);

} else{

printf("No Possible path between the given vertices\n");

  return -1;
}      


return pow(2.71828,-mi[end-1]);

}




int main(){


int n,e,i,j;

printf("Enter the no of vertices and the no of pairs of vertices(edge between them).\n");

scanf("%d",&n);


float **adjM;
int **adjM1;

adjM = (float **) malloc(n*sizeof(float *));

adjM1 = (int **) malloc(n*sizeof(int *));


scanf("%d",&e);



for(i=0;i<n;i++){

adjM[i] = (float *) malloc(n*sizeof(float));

adjM1[i] = (int *) malloc(n*sizeof(int));


for(j=0;j<n;j++){


adjM[i][j] = 0;

adjM1[i][j] = 0;

}


}


for(i=0;i<e;i++){


int a,b;

float c;

printf("Enter the pair - %d and thier reliability of the communication channel\n",i+1);

scanf("%d%d%f",&a,&b,&c);

adjM[a-1][b-1] = -log(c);

//printf("%f\n",-log(c));


adjM1[a-1][b-1] = 1;

}



int st,end;

printf("Enter the start and ending vertices (To find the most reliable path between them).\n");

scanf("%d%d",&st,&end);


float mi[n];

bool vis[n];

for(i=0;i<n;i++){

if(i==st-1)
mi[st-1] = 0;
else
mi[i] = INT_MAX;

vis[i] = false;

}





float path = realiblepath(adjM,vis,mi,n,st,end,adjM1);

if(path!=-1)
printf("( %f )\n",path);



}


























