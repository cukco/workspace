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
int height(BinTree root){
    if(root==NULL) return 0;
    int hleft=height(root->left);
    int hright=height(root->right);
    if(hleft>hright) return hleft+1;
    else return hright+1;
}
int rank(BinTree root,int currenSum,int S){
    if(root==NULL) return 0;
    currenSum++;
    if(root->id == S){
        return currenSum;
    }
    int res=rank(root->left,currenSum,S);
    if(res!=0) return res;
    return rank(root->right,currenSum,S);
}
int che=1;
void check(BinTree root,BinTree currNode,int maxheight){
    if(currNode==NULL) return;
    if(che==0) return;
    if((currNode->left==NULL && currNode->right!=NULL)||(currNode->left!=NULL && currNode->right==NULL)){
        che=0;
        return;
    }
    if(currNode==NULL && currNode==NULL){
        if(rank(root,0,currNode->id)!=maxheight){
            che=0;
            return;
        }
    }
    check(root,currNode->left,maxheight);
    check(root,currNode->right,maxheight);
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
        }else if(strcmp(c,"*")==0)  break;
    }
    int maxh=height(root);
    check(root,root,maxh);
    printf("%d %d",che,maxh);
}
