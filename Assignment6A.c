#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void Intialize(int cnt[],int n){
int i;
for(i=1;i<=n;i++){

cnt[i] = 1000000;

}



}


void mincoins(int a[],int n,int N,int max){

int cnt[N+1];

int parent[N+1];
int k;
for(k=1;k<=N;k++){

	parent[k] = 0;
}

cnt[0] = 0;

Intialize(cnt,N);

int i,j;

for(i=1;i<=N;i++){

j=n-1;

while(j>=0){

if(a[j]<=i){

int coins = cnt[i-a[j]];
if(coins!=1000000){

if(coins+1 < cnt[i]){
cnt[i] = coins+1;
parent[i] = a[j];

}


}



}

j--;

}

//printf("%d\n",parent[i]);


}




if(cnt[N]==0){


	printf("It's Not possible \n");

}
else if(cnt[N]==1000000){

printf("It's Not possible \n");

}
else{

printf("%d\n",cnt[N]);
int cnt1[max+1];


for(k=0;k<=max;k++){

	cnt1[k] = 0;

}

i=N;
while(parent[i]!=0&&i!=0){

cnt1[parent[i]]++;

i-=parent[i];


}

for(k=0;k<n;k++){

	printf("No of %d denominations -- %d\n",a[k],cnt1[a[k]]);

}






}


}




int main(){

int n,N;

scanf("%d",&n);

int a[n],i,j,max = -100;

for(i=0;i<n;i++){


scanf("%d",&a[i]);

if(max<a[i]){
	max = a[i];
}

}

scanf("%d",&N);

 qsort(a,n, sizeof(int), cmpfunc);

mincoins(a,n,N,max);

//printf("%d\n",min1);




}






















