//vedavikas 1601cs31 Assignment9C.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MIN(a,b) (((a)<(b))?(a):(b))

#define INT_MAX 0

#define MA 999999


int maxDist(int mi[], bool vis[],int n)
{
   
   int max = INT_MAX; 

   int max_ind = -1,i;
  
   for (i = 0; i < n; i++){

     if (vis[i] == false && mi[i] >= max){

         max =mi[i], max_ind = i;
         
         }
         
         }
  
   return max_ind;
   
}


// float edit(int ax,int ay,int bx,int by){


// return sqrt((ax - bx) * (ax - bx) + (ay-by) *(ay-by));


// }

int edit(char a[], char b[])
{
    int m= strlen(a);

    int n = strlen(b);


    int dp[m+1][n+1],i,j;
 
    
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            
            if (i==0){
                dp[i][j] = j;  
            }
 
           
            else if (j==0){
                dp[i][j] = i; 
            }
 
          
            else if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
 
           
            else{
                dp[i][j] = 1 + MIN(dp[i][j-1], MIN(dp[i-1][j], dp[i-1][j-1])); 
            }
        }
    }

return dp[m][n];

}
 
  


void printPath(int **path, int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(path, v, path[v][u]);
	printf(" %d -> ",path[v][u]+1); 
}



void floydWarshall (float **adjM,int n)
{
    
    float dist[n][n];

    int **path;

    path = (int **) malloc(n*sizeof(int *));

    int i, j, k;
 
    for (i = 0; i < n; i++){
    
        path[i] = (int *) malloc(n*sizeof(int));

        for (j = 0; j < n; j++){
            dist[i][j] = adjM[i][j];
      
          if (i == j)
				path[i][j] = i;
			else if (adjM[i][j] != MA)
				path[i][j] = i;
			else
				path[i][j] = -1;



        }
    }
 
    
    for (k = 0; k < n; k++)
    {
        
        for (i = 0; i < n; i++)
        {
            
            for (j = 0; j < n; j++)
            {
                
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    
                    dist[i][j] = dist[i][k] + dist[k][j];

                    path[i][j] = path[k][j];

                }
            }
        }
    }
 


for(i=0;i<n;i++){

for(j=0;j<n;j++){

printf("%f ",dist[i][j]);


}

printf("\n");

}
 
int max[n];

bool vis[n];

bool loc[n];

int par[n];

for (i = 0; i < n; ++i)
{
	max[i] = 0;
	vis[i] = false;
	loc[i] = false;
	par[i]= i;
}


for (i = 0; i < n; ++i)
{
	for (j = 0; j < n; ++j)
	{
		
   if(dist[i][j]<=30){

   	max[i]++;

   }


	}

}



for (i = 0; i < n; ++i)
{
	
int u = maxDist(max,vis,n);

if(u>=0){

//printf("%d\n",u);


loc[u] = true;



for (j = 0; j < n; ++j)
	{
		
   if(dist[u][j]<=30&&vis[j]==false){

   	vis[j] = true;

   	par[j] = u;

   }


	}

}


}

printf("Restaurents are at Location -");

for (i = 0; i < n; ++i)
{
	
if(loc[i]==true){

	printf(" %d ",i+1);

}


}

printf("\n");

for (i = 0; i < n; ++i)
{
	


	printf("(Restaurent at Location - %d sends food to location - %d)\n",par[i]+1,i+1);




}


for (i = 0; i < n; ++i)
{
	


	printf("Respective path of the deliviry is( %d -> ",par[i]+1);

   printPath(path,par[i],i);

   printf("%d )\n",i+1);



}



}


int main(){


int n,i,j,noofP;

printf("Enter the no of locations and No of roads between the localities\n");

scanf("%d%d",&n,&noofP);

// int x[n];

// int y[n];


// for ( i = 0; i < n; ++i)
// {

// scanf("%d%d",&x[i],&y[i]);

// }

char in[n][30];

for (i = 0; i < n; ++i)
{
     printf("Enter the name of Location - %d\n",i+1);

	scanf("%s",in[i]);

}




float **adjM;


adjM = (float **) malloc(n*sizeof(float *));






for(i=0;i<n;i++){


adjM[i] = (float *) malloc(n*sizeof(float));


for(j=0;j<n;j++){


adjM[i][j] = MA;

if(i==j)
adjM[i][i] = 0;


}


}



for(i=0;i<noofP;i++){

int a,b;

float tr;

printf("Enter the pair of localities - %d which have a Road and thier corresponding traffic.\n",i+1);

scanf("%d%d%f",&a,&b,&tr);

// float val = edit(x[a-1],y[a-1],x[b-1],y[b-1])*tr;

float val = edit(in[a-1],in[b-1])*tr;

adjM[a-1][b-1] = val;

adjM[b-1][a-1] = val;

}




// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%f ",adjM[i][j]);


// }

// printf("\n");

// }

floydWarshall(adjM,n);












}













