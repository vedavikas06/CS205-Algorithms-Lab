#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void Intialize(int **cnt,int n1,int n2){
int i,j;
for(i=0;i<=n1;i++){
for(j=0;j<=n2;j++){

cnt[i][j] = 0;

}

}



}



void dpminsubsum(int **temp,int n1,int n2,int a[],int **dir1,int **dir2){

int i,j;

for(i=1;i<=n1;i++){

for(j=1;j<=n2;j++){


if(a[i]<=j){

temp[i][j] = max(a[i]+temp[i-1][j-a[i]],temp[i-1][j]);

if(temp[i][j]==temp[i-1][j]){
	dir1[i][j] = i-1;
	dir2[i][j] = j;
}else{
	dir1[i][j] = i-1;
	dir2[i][j] = j-a[i];
}


}else{

	temp[i][j] = temp[i-1][j];
    dir1[i][j] = i-1;
	dir2[i][j] = j;	

}



}



}







}


void minsubsum(int a[],int n,int sum,int min){

int halfsum = sum/2;
int **temp,**dir1,**dir2;
int i,j;


temp =(int **)malloc((n+1)*sizeof(int *));
dir1 =(int **)malloc((n+1)*sizeof(int *));
dir2 =(int **)malloc((n+1)*sizeof(int *));


for(i=0;i<=n;i++){

temp[i] =(int *)malloc((halfsum+1)*sizeof(int));	
dir1[i] =(int *)malloc((halfsum+1)*sizeof(int));	
dir2[i] =(int *)malloc((halfsum+1)*sizeof(int));	
}




Intialize(temp,n,halfsum);
Intialize(dir1,n,halfsum);
Intialize(dir2,n,halfsum);

dpminsubsum(temp,n,halfsum,a,dir1,dir2);

// printf("%d %d %d\n",n,halfsum,temp[n][halfsum]);

// for(i=0;i<=n;i++){

//  for(j=0;j<=halfsum;j++){

//  printf("%d ",temp[i][j]);



//  }

//  printf("\n");



//  }
//  printf("-----\n");

//  for(i=0;i<=n;i++){

//  for(j=0;j<=halfsum;j++){

//  printf("%d ",dir1[i][j]);



//  }

//  printf("\n");



//  }
//  printf("-----\n");
//  for(i=0;i<=n;i++){

//  for(j=0;j<=halfsum;j++){

//  printf("%d ",dir2[i][j]);



//  }

//  printf("\n");



//  }


int result = (sum - temp[n][halfsum]) - temp[n][halfsum];




printf("%d\n",result);

bool a1[n+1];
for(i=1;i<=n;i++){
	a1[i] = false;
}

i = dir1[n][halfsum],j=dir2[n][halfsum];

int value = temp[n][halfsum],cnt=0;

printf("set - 1   ");
while((i!=0||j!=0)||cnt<=1){
	//printf("%d %d %d\n",i,j,value);

if(value - temp[i][j]!=0){
	printf("%d ",value - temp[i][j]+min);
	int i1;
	for(i1=1;i1<=n;i1++){
		if(a[i1] == value - temp[i][j]&&a1[i1]==false){
	a1[i1] = true;
	break;
}


}


}


value = temp[i][j];
int i1,j1;

i1 =  dir1[i][j];

j1 =  dir2[i][j];

i = i1;
j = j1;


if(i==0&&j==0){
	cnt++;
}

}


printf("\nset - 2   ");

for(i=1;i<=n;i++){

	if(a1[i] == false){

   printf("%d ",a[i]+min);

	}
}


printf("\n");


}





int main(){

int n;

scanf("%d",&n);

int a[n+1],total=0,i,neg=0,min = 1000000;

for(i=1;i<=n;i++){


scanf("%d",&a[i]);



if(min>a[i]){
	min = a[i];
}


}
//qsort(a+1,n, sizeof(int), cmpfunc);

//printf("%d %d\n",total,min);

if(min<0){

for(i=1;i<=n;i++){




a[i]-=min;
total+=a[i];



}

}else{
	min =0;
}


minsubsum(a,n,total,min);


}























