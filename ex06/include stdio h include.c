#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
struct Node{
int vertex;
struct Node*next;
};
struct Node*adjLists[MAX_VERTICES];
int visisted[MAX_VERTICES];
};
struct Node*createNode(int v){
struct Node*newNode=(struct Node*)malloc(sizeof(struct NOde));
newNode->vertex=v;
newNOde->next=NULL;
return newNode;
}
struct Graph*createGraph(){
struct Graph*graph=(struct Graph*)malloc(sizeof(struct graph));
int i;
for(i=0;i<MAX_VERTICES;i++){
graph->adjLists[i]=NULL;
graph->visited[i]=0;
}
return graph;
}
void addEDge(struct Graph*graph,int src,int dest){
struct Node*newNode=createNode(dest);
newNode->next=graph->adjLists[src];
graph->adjLists[src]=newNode;
newNode=createNode(src);
newNode->next=graph->adjLists[dest];
graph->adjLists[dest]=newNode;
}


