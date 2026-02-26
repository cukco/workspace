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
struct stack{
    int key;
    struct stack *next;
};
typedef struct stack* stack;
stack makestack(int x){
    stack tmp=(stack)malloc(sizeof(struct stack));
    tmp->key=x;
    tmp->next=NULL;
    return tmp;
}
void push(stack *head, int x) {
    stack tmp = makestack(x);
    tmp->next = *head;
    *head = tmp;
}
void pop(stack *head) {
    if (*head == NULL) return;
    stack tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
int top(stack root){
    if(root==NULL) return -1;
    return root->key;
}
int check(int a[],int n){
    int root=-1;
    stack head=NULL;
    for(int i=0;i<n;i++){
        if(a[i]<root) return 0;
        while(head!=NULL && a[i]>top(head)){
            root=top(head);
            pop(&head);
        }
        push(&head,a[i]);
    }
    return 1;
}
int main(){
    BST root=NULL;
    int x;
    scanf("%d",&x);
    int arr[x];
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
        insert(&root,NULL,arr[i]);
    }
    if(check(arr,x)==0){
        printf("NULL");
        return 0;
    }
    postorder(root);
}
