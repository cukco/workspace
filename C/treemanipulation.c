#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TreeNode{
    int id;
    struct TreeNode *leftmostChild;
    struct TreeNode *rightSibling;
};
typedef struct TreeNode* TreeNode;
TreeNode makenode(int a){
    TreeNode tmp=(TreeNode)malloc(sizeof(struct TreeNode));
    tmp->id=a;
    tmp->leftmostChild=NULL;
    tmp->rightSibling=NULL;
    return tmp;
}
TreeNode find(TreeNode root,int a){
    if(root==NULL) return NULL;
    if(root->id==a) return root;
    TreeNode tmp=find(root->leftmostChild,a);
    if(tmp!=NULL) return tmp;
    return find(root->rightSibling,a);
}
void insert(TreeNode *root,int u,int v){
    TreeNode nodev=find(*root,v);
    TreeNode nodeu=find(*root,u);
    if(nodev==NULL || nodeu!=NULL) return;
    if(nodev->leftmostChild==NULL) nodev->leftmostChild=makenode(u);
    else{
        TreeNode curr=nodev->leftmostChild;
        while(curr->rightSibling!=NULL) curr=curr->rightSibling;
        curr->rightSibling=makenode(u);
    }
}
void preorder(TreeNode r){
    if(r==NULL) return;
    printf("%d ",r->id);
    TreeNode tmp = r->leftmostChild;
    while(tmp!=NULL){
        preorder(tmp);
        tmp=tmp->rightSibling;
    }
}
void inorder(TreeNode r){
    if(r==NULL) return;
    TreeNode tmp = r->leftmostChild;
    inorder(tmp);
    printf("%d ",r->id);
    if(tmp!=NULL){
        tmp=tmp->rightSibling;
        while(tmp!=NULL){
            inorder(tmp);
            tmp=tmp->rightSibling;
        }
    }
}
void postorder(TreeNode r){
    if(r==NULL) return;
    TreeNode tmp = r->leftmostChild;
    while(tmp!=NULL){
        postorder(tmp);
        tmp=tmp->rightSibling;
    }
    printf("%d ",r->id);
}
int height(TreeNode root){
    if(root==NULL) return 0;
    int maxh=0;
    TreeNode tmp=root->leftmostChild;
    while(tmp!=NULL){
        int h=height(tmp);
        if(h>maxh) maxh=h;
        tmp=tmp->rightSibling;
    }
    return maxh+1;
}
int countleaf(TreeNode root){
    if(root==NULL) return 0;
    if(root->leftmostChild==NULL) return 1;
    int c=0;
    TreeNode tmp=root->leftmostChild;
    while(tmp!=NULL){
        c+=countleaf(tmp);
        tmp=tmp->rightSibling;
    }
    return c;
}
int countchild(TreeNode root){
    if(root==NULL) return 0;
    if(root->leftmostChild==NULL) return 0;
    int c=0;
    TreeNode tmp=root->leftmostChild;
    while(tmp!=NULL){
        c++;
        tmp=tmp->rightSibling;
    }
    return c; 
}
int toancuc=0;
void duyet(TreeNode root,int k){
    if(root==NULL) return;
    if(countchild(root)==k) toancuc++;
    TreeNode tmp=root->leftmostChild;
    while(tmp!=NULL){
        duyet(tmp,k);
        tmp=tmp->rightSibling;
    }
}
int countKchildren(TreeNode root,int u,int k){
    TreeNode p=find(root,u);
    duyet(p,k);
    return toancuc;
}
int main(){
    TreeNode root=NULL;
    char c[20];
    while(1){
        scanf(" %s",c);
        if(strcmp(c,"MakeRoot")==0){
            int k;
            scanf("%d",&k);
            root=makenode(k);
        }else if(strcmp(c,"Insert")==0){
            int u,v;
            scanf("%d %d",&u,&v);
            insert(&root,u,v);
        }else if(strcmp(c,"PreOrder")==0){
            preorder(root);
            printf("\n");
        }else if(strcmp(c,"InOrder")==0){
            inorder(root);
            printf("\n");
        }else if(strcmp(c,"PostOrder")==0){
            postorder(root);
            printf("\n");
        }else if(strcmp(c,"CountLeaves")==0){
            int u;
            scanf("%d",&u);
            TreeNode p=find(root,u);
            printf("%d\n",countleaf(p));
        }else if(strcmp(c,"CountKChildren")==0){
            toancuc=0;
            int u,k;
            scanf("%d %d",&u,&k);
            printf("%d\n",countKchildren(root,u,k));
        }else if(strcmp(c,"*")==0) return 0;
    }
}