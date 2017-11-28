#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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


int Ascii(char a[]){

int sum = 0,i;

for(i=0;i<5;i++){

sum += a[i];


}


return sum;

}





int diff(char a[],char b[]){

int dif = 0,i;


for(i=0;i<5;i++){


dif += abs(a[i] - b[i] );


}


return dif;


}



bool Valid(char a1[],char b1[]){

int i,j;

char a[6],b[6];


strcpy(a,a1);

strcpy(b,b1);


for(i=0;i<5;i++){

for(j=0;j<5;j++){

if(a[i] == b[j] && i==j){

b[j] = '*';

break;

}



}


}


bool validEdge = false;

int cnt = 0;

for(i=0;i<5;i++){

if(b[i] == '*'){

cnt++;

}



}

if(cnt==4){

validEdge = true;

}


return validEdge;

}


char ina[10000][6];


void realiblepath(int **adj,int d,int n,int val[]){


 int dist[n][n], i, j, k;
 
    
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
                
                if (dist[i][k] + dist[k][j] < dist[i][j] && i!=j)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",dist[i][j]);


// }

// printf("\n");

// }



int fl[n][n];

for(i=0;i<n;i++){



for(j=0;j<n;j++){


fl[i][j] = INT_MAX;


}


}




for(i=0;i<n;i++){



for(j=0;j<n;j++){

 if(i!=j && dist[i][j] > 0 && dist[i][j] < d && val[i] < val[j]){
            
        
fl[i][j] = 1;

}


}

}



    for (k = 0; k < n; k++)
    {
       
        for (i = 0; i < n; i++)
        {
            
            for (j = 0; j < n; j++)
            {
                
                if (fl[i][k] + fl[k][j] < fl[i][j] && i!=j)
                    fl[i][j] = fl[i][k] + fl[k][j];
            }
        }
    }

printf("\n");

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",fl[i][j]);


// }

// printf("\n");

// }

printf("\n");

      for (i = 0; i < n; i++){

              printf("%s can be accessed by all these -> ",ina[i]);
        
        for (j = 0; j < n; j++){

            if (i==j)
            {
                printf("%s ",ina[j]);
            }
        
            if(i!=j && fl[i][j] > 0 && fl[i][j]!=INT_MAX){
            
            printf("%s ",ina[j]);
            
            }
            
            }
            
            printf("\n");
            
            }


for(i=0;i<n;i++){

for(j=0;j<n;j++){

if(i==j){
    fl[i][j] = 1;
}
else if(fl[i][j]==INT_MAX){
    fl[i][j] = 0;
}


}


}


printf("\n1 - indicates direct access\n0 - indicates no access\nmore than 1 indicates indirect access\n\n");


for(i=0;i<n;i++){

for(j=0;j<n;j++){

printf("%d ",fl[i][j]);


}

printf("\n");

}





}


int main(){


int i,j,d,n;

printf("Enter the no of  students\n");

scanf("%d",&n);

int val[n];

for(i=0;i<n;i++){

printf("Enter the name of the student - %d\n",i+1);
scanf("%s",ina[i]);

val[i] = Ascii(ina[i]);



}

printf("\n");
int **adjM;

adjM = (int **) malloc(n*sizeof(int *));


for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){


adjM[i][j] = INT_MAX;


}


}




for(i=0;i<n;i++){

for(j=0;j<n;j++){

if(i!=j){


if(Valid(ina[i],ina[j]) && val[i] < val[j]){

adjM[i][j] = diff(ina[i],ina[j]);




}

}

}


}



for(i=0;i<n;i++){

for(j=0;j<n;j++){

printf("%d ",adjM[i][j]);


}

printf("\n");

}

printf("\nEnter the value of d.\n");

scanf("%d",&d);


realiblepath(adjM,d,n,val);






}

















