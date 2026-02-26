#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TreeNode{
    int id;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode* TreeNode;
TreeNode makenode(int id){
    TreeNode tmp=(TreeNode)malloc(sizeof(struct TreeNode));
    tmp->id=id;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
TreeNode find(TreeNode head,int v){
    if(head==NULL) return NULL;
    if((head)->id==v) return head;
    TreeNode res = find(head->left, v);
    if(res!=NULL) return res;   
    return find(head->right,v);
}
void addleft(TreeNode *head,int u,int v){
    TreeNode p=find(*head,v); // Tim xem co node v chua
    TreeNode o=find(*head,u); // Tim xem co node u chua
    if(p==NULL || o!=NULL || p->left!=NULL) return;
    p->left=makenode(u);
}
void addright(TreeNode *head,int u,int v){
    TreeNode p=find(*head,v); // Tim xem co node v chua
    TreeNode o=find(*head,u); // Tim xem co node u chua
    if(p==NULL || o!=NULL || p->right!=NULL) return;
    p->right=makenode(u);
}
void preorder(TreeNode r){
    if(r==NULL) return;
    printf("%d ",r->id);
    preorder(r->left);
    preorder(r->right);
}
void postorder(TreeNode r){
    if(r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->id);
}
void inorder(TreeNode r){
    if(r==NULL) return;
    inorder(r->left);
    printf("%d ",r->id);
    inorder(r->right);
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
        }else if(strcmp(c,"AddLeft")==0){
            int u,v;
            scanf("%d %d",&u,&v);
            addleft(&root,u,v);
        }else if(strcmp(c,"AddRight")==0){
            int u,v;
            scanf("%d %d",&u,&v);
            addright(&root,u,v);
        }else if(strcmp(c,"PreOrder")==0){
            preorder(root);
            printf("\n");
        }else if(strcmp(c,"InOrder")==0){
            inorder(root);
            printf("\n");
        }else if(strcmp(c,"PostOrder")==0){
            postorder(root);
            printf("\n");
        }else if(strcmp(c,"*")==0) return 0;
    }   
}