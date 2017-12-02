#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define INT_MAX 999999

int minDist(int **mi, bool vis[],int k)
{
   
   int min = INT_MAX;

   int min_ind,i;
  
   for (i = 0; i < 8; i++){
  
     if (vis[i] == false && mi[k][i] <= min){
  
         min =mi[k][i], min_ind = i;
         
         }
         
         }
  
  return min_ind;
   
}


int** realiblepath(int adj[][8],int n){

int **dist,i,j,k;
 
dist = (int **) malloc(8*sizeof(int *));

for(i=0;i<8;i++){

dist[i] = (int *) malloc(8*sizeof(int));

}
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
        
            dist[i][j] = adj[i][j];
            
            }
            
            }
 
    
    for (k = 0; k < n; k++)
    {
       
        for (i = 0; i < n; i++)
        {
            
            for (j = 0; j < n; j++)
            {
                
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


        // for (i = 0; i < n; i++){

        //       printf("%s -> ",ina[i]);
        
        // for (j = 0; j < n; j++){
        
        //     if(i!=j && dist[i][j] > 0 && dist[i][j] < d){
            
        //     printf("%s ",ina[j]);
            
        //     }
            
        //     }
            
        //     printf("\n");
            
        //     }


return dist;

}


int main(){


int i,j,k;

char cities[8][15];

strcpy(cities[0],"Chennai");
strcpy(cities[1],"Kolkata");
strcpy(cities[2],"Indore");
strcpy(cities[3],"Bengaluru");
strcpy(cities[4],"Nagpur");
strcpy(cities[5],"Ranchi");
strcpy(cities[6],"Guwahati");
strcpy(cities[7],"Hyderabad");



int **adj = (int **) malloc(8*sizeof(int *));


for(i=0;i<8;i++){

adj[i] = (int *) malloc(8*sizeof(int));



}

int adjM[][8] = {{0,1678,1172,284,910,1234,1885,520},
{1678,0,1286,1559,980,325,528,1180},
{1172,1286,0,1100,383,973,1697,653},
{284,1559,1100,0,925,1415,2075,499},
{910,980,383,925,0,891,1392,423},
{1234,325,973,1415,891,0,713,973},
{1885,528,1697,2075,1392,713,0,2447},
{520,1100,653,499,423,973,2447,0}};



for(i=0;i<8;i++){

for(j=0;j<8;j++){

printf("%d ",adjM[i][j]);

adj[i][j] = adjM[i][j];


}

printf("\n");

}

printf("\n");

int **dist;


dist = realiblepath(adjM,8);


int min = INT_MAX,minI = -1;;


// for(i=0;i<8;i++){

// for(j=0;j<8;j++){

// printf("%d ",dist[i][j]);


// }

// printf("\n");

// // }


// // int r;

// // scanf("%d",&r);

// // if(r==0){

// for (i = 0; i < 8; ++i)
// {
   
// long sum = 0;

// bool visited[8] ;
// int i1;
// for (i1 = 0; i1 < 8; ++i1)
// {
//     visited[i1] = false;
// }

// visited[i] = true;


// printf("%s --  ",cities[i]);

// k = i;

// for (j = 0; j < 7; ++j)
// {
   
// int ind = minDist(dist,visited,k);

// printf("%s --  ", cities[ind]);

// visited[ind] = true;

// sum += dist[k][ind];

// k = ind;



// }

// if(sum < min){

//     min =  sum;

//     minI = i;
// }


// printf("\n");

// printf("%ld - sum of the least travel path.\n",sum);


// }

// printf("%d - %s\n",minI,cities[minI]);



// printf("\n\n");

for (i = 0; i < 8; ++i)
{
   
long sum = 0;

bool visited[8] ;
int i1;
for (i1 = 0; i1 < 8; ++i1)
{
    visited[i1] = false;
}

visited[i] = true;


//printf("%s --  ",cities[i]);

k = i;

for (j = 0; j < 7; ++j)
{
   
int ind = minDist(adj,visited,k);

//printf("%s --  ", cities[ind]);

visited[ind] = true;

sum += adj[k][ind];

k = ind;



}

if(sum < min){

    min =  sum;

    minI = i;
}


// printf("\n");

// printf("%ld - sum of the least travel path.\n",sum);


}

 printf("%d - sum of the least travel path.\n",min);

  printf("starting point is %s.\n\n",cities[minI]);

bool visited[8] ;
int i1;
for (i1 = 0; i1 < 8; ++i1)
{
    visited[i1] = false;
}

visited[minI] = true;


printf("%s --  ",cities[minI]);

k = minI;

for (j = 0; j < 7; ++j)
{
   
int ind = minDist(adj,visited,k);

printf("%s --  ", cities[ind]);

visited[ind] = true;

//sum += adj[k][ind];

k = ind;



}

printf(".\n");


}










