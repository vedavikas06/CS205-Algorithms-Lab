//vedavikas potnuru Assignment8A.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INT_MIN -100000
 

//implementing a queue.
struct Queue
{

    int front, rear, size;

    unsigned capacity;

    int* array;

};
 
//creating  a queue
struct Queue* createQueue(unsigned capacity)
{

    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    queue->capacity = capacity;

    queue->front = queue->size = 0;

    queue->rear = capacity - 1;

    queue->array = (int*) malloc(queue->capacity * sizeof(int));

    return queue;
}

//checking whether its full or not.
bool isFull(struct Queue* queue)
{ 
 return (queue->size == queue->capacity); 
  }
 
//checking whether ts empty or not.
bool isEmpty(struct Queue* queue)
{ 
 return (queue->size == 0);
  }

//inserting a element into a queue.
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;

    queue->array[queue->rear] = item;

    queue->size = queue->size + 1;
   
}
 
//deleting a element from a queue.
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;

    int item = queue->array[queue->front];

    queue->front = (queue->front + 1)%queue->capacity;

    queue->size = queue->size - 1;

    return item;

}
 
// // Function to get front of queue
// int front(struct Queue* queue)
// {
//     if (isEmpty(queue))
//         return INT_MIN;

//     return queue->array[queue->front];

// }
 

//checking whether the graph is bipartite or not..
bool Bipartite(int **adjM, int sr,int  n)
{
   
    int color[n],i;

    //intializing all colors to -1.
    for (i = 0; i < n; ++i)
        color[i] = -1;
 
   //intializing the source color to 1.
    color[sr] = 1;
 
 //itializing the queue.
  struct Queue* queue = createQueue(1000);


     enqueue(queue, sr);
 
    
    while (!isEmpty(queue))
    {
        
        int u = dequeue(queue);
        
        if (adjM[u][u] == 1){

           return false; 

       }
 
        int v;

        for (v = 0; v < n; ++v)
        {
           
            if (adjM[u][v] && color[v] == -1)
            {
                
                //color[v] = 1 - color[u];
                if(color[u]==0){

                    color[v] = 1;

                }else{

                    color[v] = 0;
                }
                
                enqueue(queue, v);
            }
 
            else if (adjM[u][v] && color[v] ==color[u]){

                return false;

            }

        }

    }
    
   
   for (i = 0; i < n; ++i){

        if(color[i]==-1){

        color[i] = 1;

        }

        int j;
        
        for(j=0;j<n;j++){
        
        if(adjM[i][j] && color[j]==-1){

        color[i] = 0;
        
        }
        
        }
        
        } 
    
    
  printf("\nFirst Team : ");

 for (i = 0; i < n; ++i){

        if(color[i]==0){

        printf("%d ",i+1);

        }
        
        }
        

      printf("\n");  

     printf("\nSecond Team :");

 for (i = 0; i < n; ++i){

        if(color[i]==1){

        printf("%d ",i+1);

        }
        
        }

 
   printf("\n\n");  

    
    return true;

}






int main(){

int n,noofP;

printf("Enter the no of vertices and the no of pairs of players having rivalry between them.\n");

scanf("%d%d",&n,&noofP);

int i,j;

int **adjM;

adjM = (int **) malloc(n*sizeof(int *));


for(i=0;i<n;i++){

adjM[i] = (int *) malloc(n*sizeof(int));

for(j=0;j<n;j++){

adjM[i][j] = 0;

}

}


for(i=0;i<noofP;i++){

int a,b;

printf("Enter the pair - %d\n",i+1);

scanf("%d%d",&a,&b);

adjM[a-1][b-1] = 1;

adjM[b-1][a-1] = 1;

}

// for(i=0;i<n;i++){

// for(j=0;j<n;j++){

// printf("%d ",adjM[i][j]);

// }

// printf("\n");

// }



if(Bipartite(adjM,0,n)){


printf("\nYes, can split them into 2 teams.\n");

}else{

printf("\ncan't split them into 2 teams.\n");

}


return 0;

}
