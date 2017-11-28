#include<stdio.h>

#include<stdlib.h>

#include<string.h>


int main(){
int n,i,j;

printf("Enter tot no of elements\n");
scanf("%d",&n);
char doc[20];
printf("Enter doctor name\n");
scanf("%s",doc);
int docL[26]={0};
int num[n];
for(i=0;i<strlen(doc);i++){
docL[doc[i]-'a']++;

}

char ch[100][100];
//ch = (char **)malloc(n*sizeof(char *));

int cnt[n],arr[n];

for(i=0;i<n;i++){
printf("Enter patient name\n");
num[i]=i;
//ch[i] = (char *)malloc(n*sizeof(char));

scanf("%s",ch[i]);
printf("Enter patient time\n");
scanf("%d",&arr[i]);

int cn[26]={0};

for(j=0;j<strlen(ch[i]);j++){

cn[ch[i][j]-'a']++;
}
cnt[i]=0;
int i1;
for(i1=0;i1<26;i1++){

if(docL[i1]&&cn[i1]){
cnt[i]++;
}


}


}


for(i=0;i<n-1;i++){

for(j=i+1;j<n;j++){

if(cnt[i]<cnt[j]){
int temp;
temp = cnt[i];
cnt[i]=cnt[j];
cnt[j] = temp;

temp = num[i];
num[i]=num[j];
num[j] = temp;

temp = arr[i];
arr[i]=arr[j];
arr[j] = temp;




}else if(cnt[i]==cnt[j]){

if(arr[i]>arr[j]){

int temp;
temp = num[i];
num[i]=num[j];
num[j] = temp;
temp = arr[i];
arr[i]=arr[j];
arr[j] = temp;

}



}





}



}




for(i=0;i<n;i++){

printf("%s\n",ch[num[i]]);

}









return 0;



}

























