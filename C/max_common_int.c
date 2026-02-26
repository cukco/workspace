#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *next;
};
typedef struct Node* node;
node makenode(int x){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->key=x;
    tmp->next=NULL;
    return tmp;
}
node ds[1000000]={NULL};
int hashcode(int key){
    return key%1000000;
}
void insert(int key){
    int nodeid=hashcode(key);
    ds[nodeid]=makenode(key);
}
int search(int key){
    int nodeid=hashcode(key);
    if(ds[nodeid]==NULL){
        return 0;
    }else return 1;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d",&tmp);
        insert(tmp);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(search(a[i])){
            count++;
        }
    }
    printf("%d",count);
}