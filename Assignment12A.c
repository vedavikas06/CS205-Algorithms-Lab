//vedavikas 1601cs31 Assignment12A.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define INT_MIN -100000
#define INT_MAX 999999
 
char in[600][20];

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
   
   
 
  struct Queue* queue = createQueue(n+2);
  
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



int main(){

int n,i,j,x,y;

printf("Enter the no of Companies && Students Respectively.\n");

scanf("%d%d",&x,&y);

n = x+y;

printf("Enter the names of Companies && Students Respectively.\n");

for(j=1;j<=n;j++){

scanf("%s",in[j]);

i=0;

while( in[j][i] ) {

     in[j][i] = tolower(in[j][i]);

      i++;
   }

}


// for(j=1;j<=n;j++){

// printf("%s\n",in[j]);


// }

int **adjM;

adjM = (int **) malloc((n+2)*sizeof(int *));


for(i=0;i<n+2;i++){
adjM[i] = (int *) malloc((n+2)*sizeof(int));
for(j=0;j<n+2;j++){

adjM[i][j] = 0;

}

}

/*
for(i=1;i<n+1;i++){

for(j=1;j<n+1;j++){

if(j-i<=3 && j-i>0){

adjM[i][j] = i+j;

}


}

}
*/

for(i=1;i<=x;i++){

adjM[0][i] = 1;


}


for(i=x+1;i<=n;i++){

adjM[i][n+1] = 1;

}


for(i=1;i<=x;i++){

for(j=x+1;j<=n;j++){

if(i!=j){

char a[20],b[20];

strcpy(a,in[i]);

strcpy(b,in[j]);


/*if(Valid(a,b)){

adjM[i][j] = 1;


}*/


if( Valid(a,b) >= 2){

adjM[i][j] = 1;

//printf("%s %s\n",a,b);

}

//printf("%s %s\n",a,b);


}

}

}




// for(i=0;i<n+2;i++){

// for(j=0;j<n+2;j++){

// printf("%d ",adjM[i][j]);


// }

// printf("\n");

// }


printf("\n");


int max_fl = 0;

int parent[n+2];


for(i=0;i<n+2;i++){

parent[i] = -1;


}

while(bfs(adjM,0,n,parent)){

int min  =  INT_MAX;

int v = n+1,u;

while(v!=0){

u= parent[v];

if(min>adjM[u][v]){

min = adjM[u][v];

}

v = u;

}

max_fl += min;

v = n+1;

while(v!=0){

u = parent[v];

adjM[u][v] -= min;

adjM[v][u] += min;

v = u;

}





}

/*
for(i=x+1;i<=n;i++){

if(parent[i] != -1){

printf("%s ----  %s\n",in[parent[i]],in[i]);

}


}
*/



for(i=x+1;i<=n;i++){

for(j=1;j<=x;j++){


if(adjM[i][j] == 1){

printf("%s ---->  %s\n",in[j],in[i]);

break;

}


}

}



printf("\nMax no of students hired by the companies is %d.\n",max_fl);



return 0;

}
