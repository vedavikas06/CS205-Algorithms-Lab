//vedavikas 1601cs31 Assignment9C.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define INT_MAX 999999



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




float avgAscii(char a[]){


float sum = 0;
int i;


for (i = 0; i <strlen(a) ; ++i)
{
	sum+=a[i];

}

//printf("%d %d\n",sum,(int)strlen(a));

return sum/strlen(a);


}





int diffAscii(char a[],char b[]){

int sum = 0,i;

for(i=0;i<strlen(a);i++){

sum+=a[i];


}


for(i=0;i<strlen(b);i++){

sum-=b[i];


}


return abs(sum);

}






int Valid(char a[],char b[]){

int cnt1[26];

int cnt2[26],i;


for(i=0;i<26;i++){


cnt1[i] = 0;

cnt2[i] = 0;

}

for(i=0;i<strlen(a);i++){

cnt1[a[i]-'a']++;


}


for(i=0;i<strlen(b);i++){

cnt2[b[i]-'a']++;


}

bool validEdge = false;


int one = 0,minone = 0,tcnt=0;


for(i=0;i<26;i++){

if(cnt2[i]-cnt1[i]==1){
	one++;
}else if(cnt2[i]-cnt1[i]==-1){
	minone++;
}else if(cnt2[i]==cnt1[i]){
	tcnt++;
}


}

if(one==1&&tcnt==25){
	validEdge = true;
}else if(minone==1&&tcnt==25){
	validEdge = true;
}
if(validEdge==true){

return diffAscii(a,b);

}else{

	return 0;
}



}






void MST(int **adjM,int n,float bore[])
{
     int par[n],i;
     float key[n];   
     bool vis[n];  
 
     
     for (i = 0; i < n; i++){
        key[i] = bore[i];
        vis[i] = false;
        par[i] = -1;
    }
 
    

     
     for ( i = 0; i < n; i++)
     {
        
        int u = minDist(key,vis,n);
 
       
        vis[u] = true;
 
        int v;

        for (v = 0; v < n; v++){
 
           
          if (adjM[u][v] && vis[v] == false && adjM[u][v] <  key[v]){

             par[v]  = u;

             key[v] = adjM[u][v];

         }


          }
     
 }





 //printf("\n");

float sum = 0;

 for (i = 0; i < n; ++i)
 {
 	
if(par[i]!=-1){

printf("%d -> %d ( %d )\n",par[i]+1,i+1,adjM[par[i]][i]);

sum+=adjM[par[i]][i];

}
else{

printf("%d borewell planted here only ( %f )\n",i+1,bore[i]);

sum+=bore[i];

}



 }


printf("\nTotal cost for supplying water %f.\n",sum);


     
}






int main(){


int n,i,j;

printf("Enter the no of houses.\n");

scanf("%d",&n);

char name[n][11];

float bore[n];

for (i = 0; i < n; ++i)
{
  printf("Enter the name of the owner of house - %d.\n",i+1);
	scanf("%s",name[i]);

 //name[i] =  strlwr(name[i]);

  for(j = 0; name[i][j]; j++){
    
  name[i][j] = tolower(name[i][j]);

}

}




int **adjM;


adjM = (int **) malloc(n*sizeof(int *));






for(i=0;i<n;i++){


adjM[i] = (int *) malloc(n*sizeof(int));


for(j=0;j<n;j++){


adjM[i][j] = 0;


}


}


for(j=0;j<n;j++){


bore[j] = avgAscii(name[j]);


}



for(i=0;i<n;i++){

for(j=0;j<n;j++){



if(Valid(name[i],name[j])){

adjM[i][j] = Valid(name[i],name[j]);


adjM[j][i] = Valid(name[i],name[j]);

}


}


}

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",adjM[i][j]);


// }

// printf("\n");

// }


// for(j=0;j<n;j++){

// printf("%f ",bore[j]);

// }

 printf("\n");

MST(adjM,n,bore);


}






















































































