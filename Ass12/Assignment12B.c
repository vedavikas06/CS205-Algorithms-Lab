//vedavikas 1601cs31 Assignment12B.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define INT_MIN -100000
#define INT_MAX 999999
#define min(a,b) (((a)<(b))?(a):(b))


int **adjM,**adj;

int *h,*efl;

int Valid(char a[],char b[]){

int i,j;

char a1[20],b1[20];

strcpy(a1,a);

strcpy(b1,b);

int validEdge = 0;


for(i=0;i<strlen(a);i++){

for(j=0;j<strlen(b);j++){

if(a[i]==b[j]){

b[j] = '*';

validEdge++;

break;

}

}

}

strcpy(a,a1);

strcpy(b,b1);


return validEdge;

}



void preflow(int s,int n)
{
    
    h[s] = n;

    int i;

    for (i = 1; i < n ; i++)
    {
        if(adjM[s][i] >0){
            

            adj[s][i] = adjM[s][i];
 
            
            efl[i] += adjM[s][i];

            adj[i][s] = -adjM[s][i];
        
    }

}


}



int overFlow(int n)
{
	int i;

    for ( i = 1; i < n-1; i++)
       if (efl[i] > 0){

            return i;
       }
 
    
    return -1;
}



// To push flow from overflowing vertex u
bool push(int u,int n)
{

    int i;

     for ( i = 0; i < n; i++)
    {
        
            
            if (adj[u][i]== adjM[u][i]){
                continue;
            }
 
            if (h[u] > h[i])
            {
                
                int flow = min(adjM[u][i] - adj[u][i],efl[u]);
 
                efl[u] -= flow;
 
               
                efl[i] += flow;
 
                
                adj[u][i] += flow;
 

                if(adjM[i][u] == 0){

                	adjM[i][u] = flow;

                	adj[i][u] = 0;
                }else{

                	adj[i][u]-= flow;

                }
 
                return true;
            }
        
    }

    return false;
}



void relabel(int u,int n)
{
    
    int mh = INT_MAX;
 
    
    for (int i = 0; i < n; i++)
    {
            
            if (adj[u][i] == adjM[u][i]){
                continue;
            }
 
            
            if (h[i] < mh)
            {

                mh = h[i];
                
                h[u] = mh + 1;

            }
        
    }

}




struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }
 

bool isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
   
}
 

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}



bool bfs(int **adjM, int src,int  n,int parent[])
{
   
   
 
  struct Queue* queue = createQueue(2000);
  
     enqueue(queue, src);
     
     bool visited[n+2];
     int i,j;
     
     for(i = 0;i<n+2;i++){
     
     visited[i] = false;
     
     }
     
     
 
    
    while (!isEmpty(queue))
    {
        
        int u = dequeue(queue);
        
        visited[u] = true;
 
        int v;
        
        for (v = 0; v < n+2; ++v)
        {
           
            if (adjM[u][v]>0 && !visited[v])
            {
                
                enqueue(queue, v);
                
                parent[v] =u;
                
                if(v == n+1){
                
                return true;
                
                }
                
            }

            
        }
    }

    return false;

}














int main(){



int n1,n;

//scanf("%d",&n1);

int i,j;

n1=71;

n=n1+2;

//char in[n][20];

//char in[][20]={"Goa","Mumbai","Delhi","Bangalore","Hyderabad","Ahmedabad","Chennai","Kolkata","Surat","Pune","Jaipur","Lucknow","Kanpur","Nagpur","Visakhapatnam", "Indore","Thane","Bhopal","Patna","Vadodara","Ghaziabad","Ludhiana", "Coimbatore","Agra","Madurai","Nashik","Faridabad","Meerut","Rajkot","Varanasi","Srinagar","Aurangabad","Dhanbad","Amritsar","NaviMumbai","Allahabad", "Ranchi","Howrah","Jabalpur","Gwalior","Vijayawada","Jodhpur","Raipur","Kota","Guwahati","Chandigarh","Thiruvananthapuram","Solapur","Tiruchirappalli","Bareilly", "Moradabad","Mysore","Tiruppur","Gurgaon","Aligarh","Jalandhar","Bhubaneswar", "Salem","Warangal","Guntur","Bhiwandi","Saharanpur","Gorakhpur","Bikaner", "Amravati","Noida","Jamshedpur","Bhilai","Cuttack","Firozabad","Kochi","Thiruvananthapuram" };

char in[][20]={ "Goa","Mumbai","Delhi","Bangalore","Hyderabad","Ahmedabad","Chennai","Kolkata",
	                   "Surat","Pune","Jaipur","Lucknow","Kanpur","Nagpur","Visakhapatnam", 
	                   "Indore","Thane","Bhopal","Patna","Vadodara","Ghaziabad","Ludhiana", 
	                   "Coimbatore","Agra","Madurai","Nashik","Faridabad","Meerut","Rajkot",
	                   "Varanasi","Srinagar","Aurangabad","Dhanbad","Amritsar","NaviMumbai","Allahabad", 
	                   "Ranchi","Howrah","Jabalpur","Gwalior","Vijayawada","Jodhpur","Raipur","Kota",
	                   "Guwahati","Chandigarh","Thiruvananthapuram","Solapur","Tiruchirappalli","Bareilly", 
	                   "Moradabad","Mysore","Tiruppur","Gurgaon","Aligarh","Jalandhar","Bhubaneswar", 
	                   "Salem","Warangal","Guntur","Bhiwandi","Saharanpur","Gorakhpur","Bikaner", 
	                   "Amravati","Noida","Jamshedpur","Bhilai","Cuttack","Firozabad","Kochi","Goa","Thiruvananthapuram" };

// for(i=1;i<=n1;i++){



// scanf("%s",in[i]);

// // j=0;

// // while( in[i][j] ) {

// //      in[i][j] = tolower(in[i][j]);

// //       j++;
// //    }



// }


// for(i=0;i<n;i++){


// printf("%d - %s\n",i,in[i]);


// }


int **adjM1;


adjM = (int **) malloc(n*sizeof(int *));

adj = (int **) malloc(n*sizeof(int *));

adjM1 = (int **) malloc(n*sizeof(int *));

for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

adj[i] = (int *) malloc(n*sizeof(int));

adjM1[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){

adjM[i][j] = 0;

adj[i][j] =0;

adjM1[i][j] = 0;

}

}


for(i=1;i<=n1;i++){

for(j=1;j<=n1;j++){


char a[20],b[20];

strcpy(a,in[i]);

strcpy(b,in[j]);


if(strlen(b)-strlen(a) == 1 &&  Valid(a,b) >= 1){

adjM[i][j] = 2*Valid(a,b);

}

// printf("%s %s -- %d\n",a,b,adjM[i][j]);


}

}


for(i=1;i<=n1;i++){

int sum =0;

for(j=1;j<=n1;j++){

sum+=adjM[j][i];


//printf("%s %s\n",a,b);


}

if(sum == 0){


adjM[0][i] = 20;



}

}



for(i=1;i<=n1;i++){

int sum =0;

for(j=1;j<=n1;j++){





sum+=adjM[i][j];


//printf("%s %s\n",a,b);


}

if(sum == 0){


adjM[i][n1+1] = 20;



}

}


//adjM[0][71] =0;

adjM[46][72] =0;

//---
// for(i=0;i<n;i++){

// printf("%d -- ",i);

// for(j=0;j<n;j++){

// adjM1[i][j] = adjM[i][j];

// printf("%d ",adjM[i][j]);

// }

// printf("\n");

// }

// printf("\n");





// for(i=0;i<n;i++){


// for(j=0;j<n;j++){




// printf("%d ",adj[i][j]);

// }

// printf("\n");
// }


h = (int *) malloc(n*sizeof(int));

efl = (int *) malloc(n*sizeof(int));


for (i = 0; i < n; ++i)
{
	h[i] = 0;

	efl[i] = 0;
}


   preflow(0,n);
 
    // while (overFlow(n) != -1)
    // {
    //     int u = overFlow(n);

    //     if (!push(u,n)){
    //         relabel(u,n);
    //     }
    // }
 
   
 
  struct Queue* queue = createQueue(2000);
     
     
     
     for(i = 1;i<n-1;i++){
      if(efl[i] != -1)
       enqueue(queue, i);
     
     }
     
     
 
    
    while (!isEmpty(queue))
    {
        
        int u = dequeue(queue);

      if (efl[u] > 0){

       if (!push(u,n)){

           relabel(u,n);

         }

     }
     

     for(i = 1;i<n-1;i++){

     if (efl[i] > 0){

           enqueue(queue, i); 
       }


    }


}



//printf("\n");

//----

// for(i=0;i<n;i++){


// for(j=0;j<n;j++){




// printf("%d ",adj[i][j]);

// }

// printf("\n");
// }




printf("\nMax flow between source and sink(i.e Goa   ---->  Thiruvananthapuram) is %d.\n",efl[n1+1]);





int max_fl = 0;

int parent[n1+2];

parent[0] = -1;

for (int i = 0; i < n1+2; ++i)
{
   parent[i] = INT_MAX;

}

while(bfs(adjM1,0,n1,parent)){

int min  =  INT_MAX;

int v = n1+1,u;

while(v!=0){

u= parent[v];

if(min>adjM1[u][v]){

min = adjM1[u][v];

}

v = u;

}

max_fl += min;

v = n1+1;

while(v!=0){

u = parent[v];

adjM1[u][v] -= min;

adjM1[v][u] += min;

v = u;

}

// printPath(parent,parent[n1+1]);

// printf("%d.\n\n",n+1);


// printf("flow in this path is %d.\n\n",min);


}
//-----
// printf("\n");

// for(i=0;i<n;i++){


// for(j=0;j<n;j++){

// printf("%d ",adjM1[i][j]);

// }

// printf("\n");
// }

//printf("Max flow between source and sink is %d.\n",max_fl);

return 0;

}
































