#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BinTree{
    int id;
    struct BinTree *right;
    struct BinTree *left;
};
typedef struct BinTree* BinTree;
BinTree makenode(int a){
    BinTree tmp=(BinTree)malloc(sizeof(struct BinTree));
    tmp->id=a;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
BinTree find(BinTree root,int u){
    if(root==NULL) return NULL;
    if(root->id==u) return root;
    BinTree tmp=find(root->left,u);
    if(tmp!=NULL) return tmp;
    return find(root->right,u);
}
void insertright(BinTree *root,int u,int v){
    BinTree a=find(*root,u);
    BinTree b=find(*root,v);
    if(a!=NULL || b==NULL || b->right!=NULL) return;
    b->right=makenode(u);
}
void insertleft(BinTree *root,int u,int v){
    BinTree a=find(*root,u);
    BinTree b=find(*root,v);
    if(a!=NULL || b==NULL || b->left!=NULL) return;
    b->left=makenode(u);
}
int pathsum(BinTree root,int currenSum,int S){
    if(root==NULL) return 0;
    currenSum=currenSum+root->id;
    if(currenSum==S && root->left==NULL && root->right==NULL){
        return 1;
    }
    if(pathsum(root->left,currenSum,S)) return 1;
    return pathsum(root->right,currenSum,S);
}
int main(){
    char c[20];
    BinTree root=NULL;
    while(1){
        scanf(" %s",c);
        if(strcmp(c,"MakeRoot")==0){
            int k;
            scanf("%d",&k);
            root=makenode(k);
        }else if(strcmp(c,"AddLeft")==0){
            int u,v;
            scanf("%d %d",&u,&v);
            insertleft(&root,u,v);
        }else if(strcmp(c,"AddRight")==0){
            int u,v;
            scanf("%d %d",&u,&v);
            insertright(&root,u,v);
        }else if(strcmp(c,"PathSum")==0){
            int S;
            scanf("%d",&S);
            if(pathsum(root,0,S)==1) printf("True\n");
            else printf("False\n");
        }else if(strcmp(c,"*")==0) return 0;
    }
}
