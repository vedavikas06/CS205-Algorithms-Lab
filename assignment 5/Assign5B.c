//Vedavikas potnuru 1601cs31 28-08-17 filename :  Assign5B.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//finding the maximum number and also the maximum length of the string.
void findMaxMin(int arr[],int len[],int n,int *minL,int *max1){

int i;

*minL=-1000,*max1 = -1000;

for(i=0;i<n;i++){

if(arr[i]>*max1){

*max1 = arr[i];


}

if(len[i] > *minL){

*minL = len[i];

}


}

}


//doing radix sort on all the strings..

void cntSort1(int arr[],char ch[][100],int n,int j){

//intializing the the count of all the letters to zero.

int i,cnt[59]={0};

//creating another array for the final sorted values.
int op1[n];

char op2[n][100];

for(i=0;i<n;i++){


/*if the j is less than the string length then the char is null in that position. so that is given the least priority.
	hence increasing the count of 0 by1. */
	if(j<strlen(ch[i])){

cnt[ch[i][j]-64]++;

}
else{

cnt[0]++;

}

}

//adding it in the cumulative order.
for(i=0;i<=57;i++){

cnt[i+1] = cnt[i+1] + cnt[i];


}

//to maintain the stability maintaining running the loop (i) from the last.  i.e  n-1
for(i=n-1;i>=0;i--){

//jf j >= length it means the charecter is null. so doing the same process for cnt[0] as cnt[0] eans the null..
if(j<strlen(ch[i])){

op1[cnt[ch[i][j]-64]-1] = arr[i];

strcpy(op2[cnt[ch[i][j]-64]-1],ch[i]);
//decreasing the count by 1.
cnt[ch[i][j]-64]--;

}
else{

op1[cnt[0]-1] = arr[i];

//decreasing the count by 1.
strcpy(op2[cnt[0]-1],ch[i]);

cnt[0]--;

}


}

//finally copying to the intial array of numbers and strings.

for(i=0;i<n;i++){

arr[i] = op1[i];

strcpy(ch[i],op2[i]);

}


}


void cntSort2(int arr[],char ch[][100],int n,int j){
//intializing the count of 0 1 2 3----9 to zero.
int i,cnt[10]={0};
//creating another array for the final sorted values.
int op1[n];

char op2[n][100];

for(i=0;i<n;i++){
//increasing the count of the digits.

cnt[(arr[i]/j)%10]++;

}


//adding it in the cumulative order.
for(i=0;i<=8;i++){

cnt[i+1] = cnt[i+1] + cnt[i];

}

//to maintain the stability maintaining running the loop (i) from the last.  i.e  n-1
for(i=n-1;i>=0;i--){


op1[cnt[(arr[i]/j)%10]-1] = arr[i];

strcpy(op2[cnt[(arr[i]/j)%10]-1],ch[i]);

//decresing the count by 1.

cnt[(arr[i]/j)%10]--;


}

//finally copying to the intial array of numbers and strings.
for(i=0;i<n;i++){

arr[i] = op1[i];

strcpy(ch[i],op2[i]);

}


}


int main(){

//intializing the values..

int n;

printf("        ENTER THE NO OF CRICKETER'S\n");

scanf("%d",&n);

char ch[n][100];

int num[n],i;

int len[n];
//intializing the lengths of all the strings to zero..
for(i=0;i<n;i++){

len[i] = 0;

}

for(i=0;i<n;i++){

printf("        ENTER THE CRICKETER - %d   NAME\n",i+1);

scanf("%s",ch[i]);

printf("        Enter their runs in international test cricket career\n");

scanf("%d",&num[i]);
//intializing the lengths to respective values.
len[i] = strlen(ch[i]);

}

  int minL,maxnum;
//calling the function findminmax  ..
  findMaxMin(num,len,n,&minL,&maxnum);

   int j;
 
//primarily sorting the strings first and next the numbers to get them in the sorted order.

for (j = minL-1; j >=0 ; j--){

        cntSort1(num,ch, n, j);

}



for (j = 1; maxnum/j > 0; j *= 10){

        cntSort2(num,ch, n, j);

}
//printing the output..

printf("------ OUTPUT--------\n");

for(i=0;i<n;i++){


printf("%s     %d\n\n",ch[i],num[i]);



}




}


