#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define min1(a, b, c) (min(min(a,b),c))

bool istherepath(int m,int n,int a,int b){

bool exis = (a<=m&&a>=0&&b<=n&&b>=0);

return exis;

}



void Intialize(int **cnt,int m,int n,int a[100][100]){
int i,j;
for(i=0;i<m;i++){

for(j=0;j<n;j++)
cnt[i][j] = a[i][j];

}



}


void dpmincost(int a,int b,int **temp,int ** dir1,int ** dir2){

int i,j;

for(i=a;i>=0;i--){

	for(j=b;j>=0;j--){
  int fimin = min1(temp[i+1][j],temp[i][j+1],temp[i+1][j+1]) ;
   temp[i][j] += min1(temp[i+1][j],temp[i][j+1],temp[i+1][j+1]) ;
   if(fimin == temp[i+1][j]){

    dir1[i][j] = i+1;
	dir2[i][j] = j;



   }else if(fimin== temp[i][j+1]){

    dir1[i][j] = i;
	dir2[i][j] = j+1;



   }else if(fimin== temp[i+1][j+1]){

    dir1[i][j] = i+1;
	dir2[i][j] = j+1;



   }

	}

}


}






void direction(int **dir1,int **dir2,int m,int n){

int i,j;
i = 0;

j= 0;
int i1,j1;
printf("Move :");
while(!(i==m-1&&j==n-1)){

i1 = dir1[i][j];
j1 = dir2[i][j];
if(i+1==i1&&j1==j){
	printf("Downward ");
}else if(i==i1&&j1==j+1){
	printf("Rightward ");
}else if(i1==i+1&&j1==j+1){
 
 printf("Diagnally ");

}

i=i1;
j = j1;


}


printf("\n");

}



void findmincost(int a[100][100],int m,int n){



int **temp,**dir1,**dir2;
int i,j;


temp =(int **)malloc((m)*sizeof(int *));
dir1 =(int **)malloc((m)*sizeof(int *));
dir2 =(int **)malloc((m)*sizeof(int *));


for(i=0;i<m;i++){

temp[i] =(int *)malloc((n)*sizeof(int));	
dir1[i] =(int *)malloc((n)*sizeof(int));	
dir2[i] =(int *)malloc((n)*sizeof(int));	
}




Intialize(temp,m,n,a);


for(i=n-2;i>=0;i--){

	temp[m-1][i]+=temp[m-1][i+1];
	dir1[m-1][i] = m-1;
	dir2[m-1][i] = i+1;
}

for(i=m-2;i>=0;i--){

	temp[i][n-1]  += temp[i+1][n-1];
	dir1[i][n-1] = i+1;
	dir2[i][n-1] = n-1;
}



dpmincost(m-2,n-2,temp,dir1,dir2);




// for(i=0;i<m;i++){

// 	for(j=0;j<n;j++){
  
   
// printf("%d ",temp[i][j]);
// 	}
// 	printf("\n");
// }


//  for(i=0;i<m;i++){

//  for(j=0;j<n;j++){

//  printf("%d ",dir1[i][j]);



//  }

//  printf("\n");



//  }
//  printf("-----\n");
//  for(i=0;i<m;i++){

//  for(j=0;j<n;j++){

//  printf("%d ",dir2[i][j]);



//  }

//  printf("\n");



//  }



printf("%d\n",temp[0][0]);



direction(dir1,dir2,m,n);


}



int main(){

int row,col;

scanf("%d%d",&row,&col);

int a[100][100];

int i,j;


for(i=0;i<row;i++){

for(j=0;j<col;j++){

scanf("%d",&a[i][j]);

}



}



findmincost(a,row,col);

//printf("%d\n",min1);


}
















































































































