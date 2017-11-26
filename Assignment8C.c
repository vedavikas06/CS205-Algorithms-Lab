//vedavikas potnuru Assignment8C.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//dfs of a undirected graph.
void Dfs(bool vis[],int i1,int n,int **adjM,int *cnt){


   vis[i1] = true;
 
   int i;

 // *cnt = *cnt +1;
   //*cnt is for the purpose of finding sum of the degree of all vertices in the connected component.
 for (int i = 0; i < n; ++i)
{

	*cnt += adjM[i1][i];


	if(i==i1&&adjM[i][i1]){

		*cnt += adjM[i1][i];

	}

}


for(i=0;i<n;i++){

 if(adjM[i1][i]){

 if(vis[i] == false){


 Dfs(vis,i,n,adjM,cnt);

    }


  }


}





}



int connectComp(int n,int **adjM){

bool *vis = (bool  *) malloc(n*sizeof(bool));

int i,max = -100000;

for (i = 0; i < n; ++i)
{

	vis[i] = false;

}



for (i = 0; i < n; ++i)
{
	
	if(vis[i] == false){
    
    int val = 0;

   Dfs(vis,i,n,adjM,&val);

  if(val/2 > max){

  	max = val/2; 
  }


	}

}


return max;

}



int main(){



int n,noofP;

printf("Enter the no of vertices and the no of pairs of vertices(edge between them).\n");

scanf("%d%d",&n,&noofP);

int i,j;

int **adjM;

adjM = (int **) malloc(n*sizeof(int *));


for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){

adjM[i][j] = 0;

}

}


for(i=0;i<noofP;i++){

int a,b;

printf("Enter the pair - %d\n",i+1);

scanf("%d%d",&a,&b);

adjM[a-1][b-1] = 1;

adjM[b-1][a-1] = 1;

}



// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",adjM[i][j]);

// }

// printf("\n");

// }



printf("\nMaximum no of edges in a connected component of this graph is  %d.\n",connectComp(n,adjM));
  

return 0;

}
