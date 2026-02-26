#include<stdio.h>
#include<stdlib.h>
struct Edge{
    int src;
    int dest;
    int weight;
};
typedef struct Edge Edge;
int compare(const void *a,const void *b){
    Edge* canh1=(Edge*)a;
    Edge* canh2=(Edge*)b;
    return ( canh1->weight - canh2->weight );
}
int parent[100000];
int findroot(int u){
    if(parent[u]==u) return u;
    return parent[u]=findroot(parent[u]);
}
int unionset(int u,int v){
    int rootu=findroot(u);
    int rootv=findroot(v);
    if (rootu != rootv){
        parent[rootu] = rootv;
        return 1;
    }
    return 0;
}
Edge arr[100000];
void kruskal(int n,int m){
    qsort(arr,m,sizeof(struct Edge),compare);
    for(int i=0;i<100000;i++) parent[i]=i;
    int sum=0;
    int count=1;
    for(int i=0;i<m;i++){
        if(unionset(arr[i].src,arr[i].dest)){
            count++;
            sum+=arr[i].weight;
            if(count==n) break;
            }
        }
    printf("%d",sum);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&arr[i].src,&arr[i].dest,&arr[i].weight);
    }
    kruskal(n,m);
}