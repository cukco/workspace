#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BST{
    int data;
    struct BST *parent;
    struct BST *left;
    struct BST *right;  
};
typedef struct BST* BST;
BST makenode(int x){
    BST tmp=(BST)malloc(sizeof(struct BST));
    tmp->data=x;
    tmp->parent=NULL;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void insert(BST *root,BST cha,int x){
    if(*root==NULL){
        *root=makenode(x);
        (*root)->parent=cha;
    }else if( (*root)->data < x ) insert(&((*root)->right),*root,x);
    else if( (*root)->data > x ) insert(&((*root)->left),*root,x);
}
BST toleast(BST root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
void remove1(BST *root,int x){
    if (*root == NULL) return; 
    if (x < (*root)->data) {
        remove1(&((*root)->left), x);
    } else if (x > (*root)->data) {
        remove1(&((*root)->right), x);
    } else {
        if((*root)->right!=NULL && (*root)->left!=NULL){
            BST temp = toleast((*root)->right);
            (*root)->data = temp->data;
            remove1(&((*root)->right), temp->data);
        }else if ((*root)->right != NULL) {
            BST temp = *root;
            *root = (*root)->right;
            if(*root!=NULL) (*root)->parent = temp->parent; 
            free(temp);
        } else if ((*root)->left != NULL) {
            BST temp = *root;
            *root = (*root)->left;
            if(*root!=NULL) (*root)->parent = temp->parent; 
            free(temp);
        }else{
            *root=NULL;
        }
    }
}
void preorder(BST r){
    if (r==NULL) return;
    printf("%d ",r->data);
    preorder(r->left);
    preorder(r->right);
}
void postorder(BST r){
    if (r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->data);
}
int main(){
    BST root=NULL;
    char c[20];
    while(1){
        scanf(" %s",c);
        if(strcmp(c,"#")==0) break;
        else if(strcmp(c,"insert")==0){
            int k;
            scanf("%d",&k);
            insert(&root,NULL,k);
        }else if(strcmp(c,"remove")==0){
            int k;
            scanf("%d",&k);
            remove1(&root,k);
        }else if(strcmp(c,"preorder")==0){
            preorder(root);
            printf("\n");
        }else if(strcmp(c,"postorder")==0){
            postorder(root);
            printf("\n");

    }
    }
}
