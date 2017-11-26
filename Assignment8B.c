//vedavikas potnuru Assignment8B.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//to check whether there is a edge or not..
bool Valid(char a[],char b[]){

int cnt1[26];

int cnt2[26],i;


for(i=0;i<26;i++){


cnt1[i] = 0;

cnt2[i] = 0;

}

for(i=1;i<5;i++){

cnt1[a[i]-'a']++;


}


for(i=0;i<5;i++){

cnt2[b[i]-'a']++;


}

bool validEdge = true;

for(i=1;i<5;i++){

if(cnt1[a[i]-'a']>cnt2[a[i]-'a']){

validEdge = false;

break;

}



}

// int n = 0;


// for (int i = 1; i < 5; ++i)
// {
//    if(a[i]==b[i]){

//    n++;

//    }
// }
// if(n==4){

//     validEdge = true;

// }


return validEdge;

}



//for dfs of a graph.
void Dfs(bool vis[],int i1,int n,int **adjM,int cnt){

   if(cnt!=0){

   vis[i1] = true;

 }
 
  int i;


for(i=0;i<n;i++){


 if(adjM[i1][i] && vis[i] == false){


 Dfs(vis,i,n,adjM,1);

   
  }


}


}




void Dfs1(bool vis[],int i1,int n,int **adjM,bool *che){


   vis[i1] = true;
 
   int i;


  for(i=0;i<n;i++){


      if(adjM[i1][i] && vis[i] == false){


         Dfs1(vis,i,n,adjM,che);

   
  }
       else if(adjM[i1][i] && vis[i] == true){

         *che = true;


  }




 }



 }


bool Cyclic(int i1, bool visi[], bool recSta[],int** adjM,int n)
{
    if(visi[i1] == false)
    {
       
        visi[i1] = true;

        recSta[i1] = true;
 
        int i;
        
        for(i = 0; i < n; ++i)
        {
        if(adjM[i1][i])

            if ( !visi[i] && Cyclic(i, visi,recSta,adjM,n) ){

                return true;

            }

            else if (recSta[i]){

                return true;

            }

        }
 
    }

    recSta[i1] = false;

    return false;
}



int main(){

int n;

printf("Enter the no of Words\n");

scanf("%d",&n);

int i,j;

char in[n][6];

for(i=0;i<n;i++){

printf("Enter the word - %d\n",i+1);

scanf("%s",in[i]);

}


int **adjM;

adjM = (int **) malloc(n*sizeof(int *));


for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){

adjM[i][j] = 0;

}

}


for(i=0;i<n;i++){

for(j=0;j<n;j++){

if(i!=j){

char a[5],b[5];

if(Valid(in[i],in[j])){

adjM[i][j] = 1;


}

}

}


}

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",adjM[i][j]);


// }

// printf("\n");

// }

  
    bool visi[n];

    bool recSta[n];
    
    bool cycle = false;
    
    for(i = 0; i < n; i++)
    {
        visi[i] = false;
        recSta[i] = false;
    }
 
    
    for(i = 0; i < n; i++){

        if (Cyclic(i, visi, recSta,adjM,n)){
            
               cycle = true;
                   
              break;     
              
            }
            
            }
 if(cycle){
 
 printf("\nGraph is Cyclic.\n\n");
 
 }else{
 
  printf("\nGraph is Acyclic.\n\n");

 }


// bool vi[n];


//  for (int i = 0; i < n; ++i)
//  {

//    vi[i] =false;


//  }





// bool che = false;


//    for (int i = 0; i < n; i++){

//         if (vi[i] == false && !che){

//           Dfs1(vi,i,n,adjM,&che);

//         }
           
// }

// if(!che){

//   printf("There is no cycle\n");

// }else{

//    printf("There is a cycle\n");

// }


bool vis[n];

printf("0  -  indicates no path between respective vertices.\n\n1  -  indicates path between respective vertices.\n\n");

printf("  ");
for (j = 0; j < n; ++j)
{

  printf("%d ", j+1);

}

printf("\n");

for (i = 0; i < n; ++i)
{


    for (j = 0; j < n; ++j)
{

    vis[j] = false;

}
    
    if(vis[i] == false){
    
    int cnt = 0;

   Dfs(vis,i,n,adjM,cnt);



    }


printf("%d ",i+1);

for (j = 0; j < n; ++j)
{

  if(vis[j]){

    printf("1 ");

  }
  else{

     printf("0 ");

  }

}

printf("\n");



}
  

return 0;

}





















































