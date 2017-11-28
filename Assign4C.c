#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))



int** addMatrix(int** a, int** b,int n){
	int **c,i,j;
	
c = (int **)malloc(n*sizeof(int *));
  for (i = 0; i < n; i++)
    {
    	 c[i] = (int *)malloc(n*sizeof(int));
        for (j = 0; j < n; j++)
        {
         c[i][j]=a[i][j]+b[i][j];   
        }
        
    }

	return c;
	
}



int** divideAndConquer(int** a, int** b,int n){
	int i,j,k;
    if (n == 1){
         //calculate and return base case
         int** c;
         c = (int **)malloc(n*sizeof(int *));
         
          for ( i = 0; i < n; i++){
          	
        c[i] = (int *)malloc(n*sizeof(int));
           
        for ( j = 0; j < n; j++)
        {
            c[i][j] = a[i][j]*b[i][j];
           /* for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }*/
        }
    }
         
      return c;   
    }
    else {
    	int **a11,**a12,**a21,**a22;
    	int **b11,**b12,**b21,**b22;
    	 a11 = (int **)malloc((n/2)*sizeof(int *));
    	  a12 = (int **)malloc((n/2)*sizeof(int *));
    	   a21 = (int **)malloc((n/2)*sizeof(int *));
    	    a22 = (int **)malloc((n/2)*sizeof(int *));
    	     b11 = (int **)malloc((n/2)*sizeof(int *));
    	      b12 = (int **)malloc((n/2)*sizeof(int *));
    	       b21 = (int **)malloc((n/2)*sizeof(int *));
    	       b22 = (int **)malloc((n/2)*sizeof(int *));
    	        
    	
    	for(i=0;i<n;i++){
    		
    		for(j=0;j<n;j++){
    			if(i<n/2&&j<n/2){
    				a11[i][j]=a[i][j];
				}else if(i<n/2&&j>=n/2){
					a12[i][j-n/2]=a[i][j];
				}else if(i>=n/2&&j<n/2){
					a21[i-n/2][j]=a[i][j];
				}else if(i>=n/2&&j>=n/2){
					a22[i-n/2][j-n/2]=a[i][j];
				}
			}
    		
    		
    		
		}
    		for(i=0;i<n;i++){
    		
    		for(j=0;j<n;j++){
    			
    			if(i<n/2&&j<n/2){
    				b11[i][j]=b[i][j];
				}else if(i<n/2&&j>=n/2){
					b12[i][j-n/2]=b[i][j];
				}else if(i>=n/2&&j<n/2){
					b21[i-n/2][j]=b[i][j];
				}else if(i>=n/2&&j>=n/2){
					b22[i-n/2][j-n/2]=b[i][j];
				}
			}
    		
    		
    		
		}
    	
          
        int** c11 = addMatrix(divideAndConquer(a11,b11,n/2),divideAndConquer(a12,b21,n/2),n/2);
        int** c12 = addMatrix(divideAndConquer(a11,b12,n/2),divideAndConquer(a12,b22,n/2),n/2);
        int** c21 = addMatrix(divideAndConquer(a21,b11,n/2),divideAndConquer(a22,b21,n/2),n/2);
        int** c22 = addMatrix(divideAndConquer(a21,b12,n/2),divideAndConquer(a22,b22,n/2),n/2);
        //combine result quarters into one result matrix and return
        int **c;
        
        	for(i=0;i<n;i++){
    		
    		for(j=0;j<n;j++){
    			
    			if(i<n/2&&j<n/2){
    				c[i][j]=c11[i][j];
				}else if(i<n/2&&j>=n/2){
					c[i][j]=c12[i][j-n/2];
				}else if(i>=n/2&&j<n/2){
					c[i][j]=c21[i-n/2][j];
				}else if(i>=n/2&&j>=n/2){
					c[i][j]=c22[i-n/2][j-n/2];
				}
			}
    		
    		
    		
		}
        
        
        return c;
        
    }
}











int main(){
 
int n;
scanf("%d",&n);

int **A,**B,i,j;
A = (int **)malloc(n*sizeof(int *));
B = (int **)malloc(n*sizeof(int *));
  for (i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(n*sizeof(int));
        for (j = 0; j < n; j++)
        {
           scanf("%d",&A[i][j]);
            
        }
        
    }
 

  for (i = 0; i < n; i++)
    {
         B[i] = (int *)malloc(n*sizeof(int));
        for (j = 0; j < n; j++)
        {
           scanf("%d",&B[i][j]);
            
        }
        
    }

int **c;
c = divideAndConquer(A,B,n);
   
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
       printf("%d ",c[i][j]);
        }
        printf("\n");
    }


return 0;



}






