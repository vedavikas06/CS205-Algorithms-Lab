//Vedavikas potnuru 1601cs31 28-08-17 filename :  Assign5A.c
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

//swapping the values..
void swap(int *x,int *y){

int temp = *x;

*x = *y;

*y = temp;

}

//finding the index of the median of the 3 numbers.

int medianfind(int t[],int a,int b,int c){

if(t[a]<=t[b]&&t[b]<=t[c]||t[a]>=t[b]&&t[b]>=t[c]){

   return b;

}else if(t[b]<=t[a]&&t[a]<=t[c]|| t[b]>=t[a]&&t[a]>=t[c]){

   return a;

}else if(t[a]<=t[c]&&t[c]<=t[b] || t[b]<=t[c]&&t[c]<=t[a]){

   return c;
}

return b;


}


//splitting the numbers into 3 parts..

void divideL(int *a,int n,int piv){

 int i1, j1, k1, u, v, w,ran;
//n <= 1  then return 
   if (n <= 1) {
    return;
  }
  //if n==2 then swap if they are not in ascending order.
   if (n == 2) {

      if (a[0] > a[1]) {
     
     swap(&a[0],&a[1]);

      }

      return;
   }
   if(piv==0){

     swap(&a[0],&a[0]);

   }
   //if piv==1 swap the random with first element.
   if (piv == 1) {

      i1= rand() % n; 

     swap(&a[0],&a[i1]);

   } 
   //if piv ==2 then find the median element and swap it with median element.
    else if (piv == 2) {

     u = 0; v = n/2; w = n-1;

    ran = medianfind(a,u,v,w);

     swap(&a[ran],&a[0]);

      } 
      //if piv ==3 then find the median element and swap it with median element.
      else if(piv==3){

      u = n/4; v = n/2; w = 3*n/4;

      ran = medianfind(a,u,v,w);

     swap(&a[ran],&a[0]);

      }
     
// intializing the intial element as pivot.and also the values.
   

   

   i1 = 0,j1 = 0;

   k1 = n-1;

   v = a[0]; 

  
   while (j1 <= k1) {

   if (a[j1] == v){
    //increment j1
      ++j1;

    }
     if (a[j1] <= v) {
        
         swap(&a[i1],&a[j1]);
     //increment i1 j1.
          ++j1;

          ++i1;

      }
       else {
         
         swap(&a[j1],&a[k1]);
    //decrement k1 by 1.
           --k1;

      }

      
   }


   divideL(a, i1, piv);

   divideL(a+j1, n-j1, piv);


}




//quicksort


void quicksort(int a[],int n,int piv){
 
 //if pivot is 0
if( piv == 0){


divideL(a,n,0);

//if pivot is 1
}else if( piv ==1){

divideL(a,n,1);

//if pivot is 2
}else if( piv ==2){

divideL(a,n,2);

//if pivot is 3.
}else if(piv == 3){

divideL(a,n,3);


}

 
}



//main function.

int main(){

int n,i,piv;

time_t t;

srand((unsigned int)time(NULL));
//creating the clock variables.
clock_t c1, c2,c3,c4;

//printf("Enter n\n");
//scanf("%d",&n);

//int *a = (int *)malloc(n*sizeof(int));


//printf("Enter the pivot\n");

//scanf("%d",&piv);


//printf("For n %d\n",n);


printf("n      Pivot type              Random                                  Sorted                             Almost Sorted\n");

for(n=10000;n<=10000000;n*=10){


for(piv=0;piv<=3;piv++){
  //creating the memory by using malloc .

int *a = (int *)malloc(n*sizeof(int));
//creating the random elements..

for(i=0;i<n;i++){

//scanf("%d",&a[i]);
a[i] = rand() % 1000000000;
 

}


//printf("For pivot %d\n",piv);
c1 = clock();

//printf("\nThe median of the array is %d\n",median(a,n));

quicksort(a,n,piv);

c2 = clock();


// for(i=0;i<n;i++){

// printf("%d\n",a[i]);

 
//}

double runtime1 = (double)(c2-c1) / (double)CLOCKS_PER_SEC; 

c1 = clock();

quicksort(a,n,piv);

c2 = clock();


 // for(i=0;i<n;i++){

 // printf("%d\n",a[i]);

 
 // }

double runtime2 = (double)(c2-c1) / (double)CLOCKS_PER_SEC; 



int j;

for(j=0;j<n/100;j++){
   
   swap(&a[rand() % n],&a[rand() % n]);
   
}


c1 = clock();

quicksort(a,n,piv);

c2 = clock();

// for(i=0;i<n;i++){

// printf("%d\n",a[i]);

 
 //}
//printing the runtimes for corresponding n and pivots..

double runtime3 = (double)(c2-c1) / (double)CLOCKS_PER_SEC; 

printf("%d       %d               %.20f                       %.20f                 %.20f\n",n,piv,runtime1,runtime2,runtime3);

//frreeing the memory

free(a);

}



}


}









