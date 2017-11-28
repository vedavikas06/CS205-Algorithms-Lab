#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define INT_MIN -100000
#define INT_MAX 999999
#define max(a,b) (((a)>(b))?(a):(b))


int minDist(int mi[], bool vis[],int n)
{
   
   int min = INT_MAX;
   
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

int Valid(char a[],char b[]){

int i,j;
char a1[15],b1[15];
strcpy(a1,a);

strcpy(b1,b);

int validEdge = 0;


for(i=0;i<strlen(a);i++){

for(j=0;j<strlen(b);j++){

if(a[i]==b[j]){

b[j] = '*';

validEdge++;

break;

}

}

}

strcpy(a,a1);

strcpy(b,b1);


return validEdge;

}

int diff(char a[],char b[]){

int dif = 0,i;


for(i=0;i<=max(strlen(a)-1,strlen(b)-1);i++){

int a1=0,b1=0;

if(i<strlen(a)){

a1 = a[i];

}

if(i<strlen(b)){

b1 = b[i];

}

dif += abs(a1 - b1);


}

return dif;

}



int main(){

int n;

printf("Enter the no of Localities.\n");

scanf("%d",&n);

int i,j;

char in[n][15];

for(i=0;i<n;i++){

printf("Enter the Locality - %d\n",i+1);

scanf("%s",in[i]);

}



int **adjM,**slo;

adjM = (int **) malloc(n*sizeof(int *));

slo = (int **) malloc(n*sizeof(int *));


for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

slo[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){

adjM[i][j] = 0;

slo[i][j] = strlen(in[j]) - strlen(in[i]);

}

}


for(i=0;i<n;i++){

for(j=0;j<n;j++){

if(i!=j){
char a[15],b[15];

strcpy(a,in[i]);

strcpy(b,in[j]);


/*if(Valid(a,b)){

adjM[i][j] = 1;


}*/


if(slo[i][j]==0){

adjM[i][j] = diff(a,b);

}

else if(abs(slo[i][j]) == 1 && Valid(a,b) >= 1){

adjM[i][j] = diff(a,b);


}else if(abs(slo[i][j]) == 2 && Valid(a,b) >= 2){

adjM[i][j] = diff(a,b);

}

//printf("%s %s\n",a,b);


}

}

 }

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",adjM[i][j]);


// }

// printf("\n");

// }



// printf("\n");

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",slo[i][j]);


// }

// printf("\n");

// }

int dist[n];

for(i=0;i<n;i++){

dist[i] = INT_MAX;

}

  int st,end;

  printf("\nEnter the 2 localities for which shortest path is to be found.\n");

  scanf("%d%d",&st,&end);
  
  dist[st-1] = 0;

   int par[n];
  
  par[st-1] =-1;
  
  for (i = 0; i < n; i++)
     {
       par[i] = INT_MAX;
       
       }
  
   bool visit[n];

  for(i=0;i<n;i++){

     visit[i] = false;

   }
  

  
  
   
     for (i = 0; i < n-1; i++)
     {
       
       int u = minDist(dist,visit,n);
  
       visit[u] = true;
       
       int v;
      
       for (v = 0; v < n; v++)
  
         if (!visit[v] && adjM[u][v] > 0 && slo[u][v] > 0 && dist[u] != INT_MAX && (dist[u]+adjM[u][v]) < dist[v]){

            dist[v] = dist[u] + adjM[u][v];
                
            par[v] = u;
          }

     }

  if(dist[end-1]==INT_MAX)

    printf("No Path Exists!.\n");

else{

   
  printf("\nshortest distance between them is %d.\n\nThe path is : ",dist[end-1]);

printPath(par,par[end-1]);

printf("%d.\n",end);



}
   
 return 0;

}































