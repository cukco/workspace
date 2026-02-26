#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 100000
struct BinTree{
    int id;
    struct BinTree *right;
    struct BinTree *left;
};
typedef struct BinTree* BinTree;
BinTree nodes[max];
BinTree makenode(int a){
    BinTree tmp=(BinTree)malloc(sizeof(struct BinTree));
    tmp->id=a;
    tmp->left=NULL;
    tmp->right=NULL;
    nodes[a]=tmp;
    return tmp;
}
void insertright(int u,int v){
    if(nodes[v]==NULL || nodes[u]!=NULL) return;
    if(nodes[v]->right==NULL) nodes[v]->right=makenode(u);
}
void insertleft(int u,int v){
    if(nodes[v]==NULL || nodes[u]!=NULL) return;
    if(nodes[v]->left==NULL) nodes[v]->left=makenode(u);
}
int checkbalancetree(BinTree root){
    if(root==NULL) return 0;
    int leftH=checkbalancetree(root->left);
    if(leftH == -1) return -1;
    int rightH=checkbalancetree(root->right);
    if(rightH == -1) return -1;
    if(abs(rightH-leftH)>1) return -1;
    return (rightH>leftH ? rightH : leftH)+1;
}
int height(BinTree root){
    if(root==NULL) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return (rightH>leftH ? rightH : leftH)+1;
}
int main(){
    for(int i=0;i<max;i++) nodes[i]=NULL;
    BinTree root=NULL;
    char c[20];
    int u,v;
    while(1){
        scanf(" %s",c);
        if(strcmp(c,"MakeRoot")==0){
            scanf("%d",&u);
            root=makenode(u);
        }else if(strcmp(c,"AddLeft")==0){
            scanf("%d %d",&u,&v);
            insertleft(u,v);
        }else if(strcmp(c,"AddRight")==0){
            scanf("%d %d",&u,&v);
            insertright(u,v);
        }else if(strcmp(c,"*")==0)  break;
    }
    int result=checkbalancetree(root);
    if(result!=-1){
        printf("1 %d",result);
    }else{
        printf("0 %d",height(root));
    }
}