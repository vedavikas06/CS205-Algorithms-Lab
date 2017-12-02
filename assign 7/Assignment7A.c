//vedavikas potnuru 1601cs31 Assignment7A.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 1000000

int Kthsmallest(int a[],int l,int r,int k);

void swap(int *a,int *b){

int temp = *a;
*a= *b;
*b = temp;

}


int cmpfunc (const void * a, const void * b)
{
   
   return ( *(int*)a - *(int*)b );

}



int findMedian(int arr[], int n)
{

    qsort(arr,n, sizeof(int), cmpfunc);
   // int i;
   // // for(i=0;i<n;i++){
   // // 	printf("%d ",arr[i]);
   // // }
    
   // //  printf("\n");

    return arr[n/2];  

}



int partition(int a[],int l,int r,int med){



int i,j;

    	i=l;

    while(i<=r){
 
        if (a[i] == med)

           break;

       i++;
   }

    swap(&a[i], &a[r]);

    int last = a[r];

    i = l-1;

    j=l;

   	while(j<=r-1){

   if(a[j]<=last){

    i++;

   swap(&a[j],&a[i]);

  }

j++;

}

   swap(&a[i+1],&a[r]);

   return i+1;

}


int medianf(int median[],int n,int arr[],int l){

 int i; 

 for (i=0; i<n/7; i++)

            median[i] = findMedian(arr+l+i*7, 7);

        if (i*7 < n)
        {

            median[i] = findMedian(arr+l+i*7, n%7); 

            i++;

        }   

 return i;

}



int mediofmed(int median[],int i){

    int medMed ;
    if( (i == 1)){
    	medMed = median[i-1];
    	}else{
    		medMed = Kthsmallest(median, 0, i-1, i/2);
    	}
                                

     return medMed;                        

}

int Kthsmallest(int a[],int l,int r,int k){




  if (k > 0 && k <= r - l + 1){

     int n = r-l+1;

     int i, media[(n+6)/7]; 
     
    i = medianf(media,n,a,l);
    
    int medMed = mediofmed(media,i);
    
int par = partition(a,l,r,medMed);

if(par-l == k-1){


return a[par];

}
else if(par-l< k-1){


return Kthsmallest(a,par+1,r,k-par+l-1);

}
else{

return Kthsmallest(a,l,par-1,k);


}


}
//printf("-1-\n");
return -1;



}


int main(){

int n,i;

printf("Enter no of elements\n");

scanf("%d",&n);

printf("Enter the elements\n");

int a[n];

for(i=0;i<n;i++){

scanf("%d",&a[i]);


}

printf("Enter the value of k\n");

int k;

scanf("%d",&k);


if(Kthsmallest(a,0,n-1,k)!=-1){
	printf("------%d th smallest element is %d.-----\n",k,Kthsmallest(a,0,n-1,k));
}else{
	printf("%d th element doesn't exist\n",k);
}

return 0;

}


