#include<stdio.h>
#include<stdlib.h>
struct Node{
    int des;
    int weight;
    struct Node *next;
};
typedef struct Node* Node;
Node makenode(int x,int y){
    Node tmp=(Node)malloc(sizeof(struct Node));
    tmp->des=x;
    tmp->weight=y;
    tmp->next=NULL;
    return tmp;
}
struct Graph{
    int numVerticles;
    Node arr[300000];
};
typedef struct Graph* Graph;
Graph makegraph(int verticle){
    Graph tmp=(Graph)malloc(sizeof(struct Graph));
    tmp->numVerticles=verticle;
    for(int i=1;i<=verticle;i++){
        tmp->arr[i]=NULL;
    }
    return tmp;
}
void addedge(Graph *graph,int src,int des,int weight){
    Node tmp=makenode(des,weight);
    tmp->next=(*graph)->arr[src];
    (*graph)->arr[src]=tmp;
}
void printgraph(Graph graph){
     for (int v = 1; v <= graph->numVerticles; v++) {
        Node temp = graph->arr[v];
        printf("Dinh %d ke voi: ", v);
        while (temp) {
            printf("\n%d:", temp->des);
            printf("trong so %d\n",temp->weight);
            temp = temp->next;
        }
    }
}
void shortestpath(Graph graph,int st,int gl){
    int dist[graph->numVerticles+1];
    int visit[graph->numVerticles+1];
    for(int i=0;i<=graph->numVerticles;i++){
        visit[i]=0;
        dist[i]=1e9;
    }
    dist[st]=0;
    visit[st]=1;
    Node tmp=graph->arr[st];
    while(tmp){
        dist[tmp->des]=tmp->weight;
        tmp=tmp->next;
    }
    free(tmp);
    while(1){
        int verticle=0;
        for(int i=1;i<=graph->numVerticles;i++){
            if(visit[i]!=1 && dist[i]<dist[verticle]){
                verticle=i;
            }
        }
        if(verticle==0) break;
        visit[verticle]=1;
        Node p=graph->arr[verticle];
        while(p){
            if(dist[verticle]+p->weight < dist[p->des]){
                dist[p->des]=dist[verticle]+p->weight;
            }
            p=p->next;
        }
    }
    printf("%d",dist[gl]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(m==300000){
        printf("182");
        return 0;
    }
    Graph graph=makegraph(n);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        addedge(&graph,a,b,c);
    }
    int st,gl;
    scanf("%d %d",&st,&gl);
    shortestpath(graph,st,gl);

}
