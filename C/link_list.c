#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
 
};
typedef struct Node* node;
node makeNode(int x){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
bool empty(node a){
    return a==NULL;
}
int size(node a){
    int sum=0;
    while(a!=NULL){
        a=a->next;
        sum++;
    }
    return sum;
}
void insertfirst(node *a,int x){
    node tmp=makeNode(x);
    if(*a==NULL){
        *a=tmp;
    }else{
        tmp->next=*a;
        *a=tmp;
    }
}
void insertlast(node *a,int x){
    node tmp=makeNode(x);
    if(*a==NULL){
        *a=tmp;
    }else{
        node p=*a;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
void insertmid(node *a, int x, int y) {
    node tmp = makeNode(x);
    if (*a == NULL) {
        insertfirst(a, x);
        return;
    }
    node p = *a;
    while (p != NULL && p->data!=y) {
        p = p->next;
    }
    if (p == NULL) {
        return;
    } else {
        tmp->next = p->next;
        p->next = tmp;
    }
}
void insertbefore(node *a, int x, int y) {
    node tmp = makeNode(x);
    if (*a == NULL) {
        insertfirst(a, x);
        return;
    }
    node truoc=NULL;
    node sau = *a;
    while (sau != NULL && sau->data!=y) {
        truoc=sau;
        sau = sau->next;
    }
    if (sau == NULL) {
        return;
    } else {
        if (truoc == NULL) {
        tmp->next = *a;
        *a = tmp;
        }else{
        tmp->next = truoc->next;
        truoc->next = tmp;
        }
    }
}
void removefirst(node *a){
    if(*a==NULL){
        return;
    }
    *a=(*a)->next;
}
void removelast(node *a){
    if(*a==NULL){
        return;
    }else{
        node sau=*a,truoc=NULL;
        if(sau->next==NULL){
            *a==NULL;
            return;
        }
        while(sau->next!=NULL){
            truoc=sau;
            sau=sau->next;
        }
        truoc->next=NULL;

    }
}
void remove1(node *a, int y) {
    if (*a == NULL) return;
    if ((*a)->data == y) {
        node tmp = *a;
        *a = (*a)->next;
        free(tmp);
        remove1(a, y);
    } else {
        remove1(&(*a)->next, y);
    }
}
void reverse(node *a){
    node prev = NULL;      
    node curr = *a;        
    node next = NULL;      
    while (curr != NULL) {
        next = curr->next;    
        curr->next = prev;     
        prev = curr;          
        curr = next;          
    }
    *a = prev;
}
void printlist(node a){
    node p=a;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main() {
    int n;
    node head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        insertlast(&head, a);
    }
    getchar(); 
    while (1) {
        char c[100];
        scanf("%s",&c);
        if (strcmp(c, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            insertlast(&head, k);
            getchar();
        } else if (strcmp(c, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            insertfirst(&head, k);
            getchar();
        } else if (strcmp(c, "addafter") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            insertmid(&head, u, v);
            getchar();
        } else if (strcmp(c, "addbefore") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            insertbefore(&head, u, v);
            getchar();
        } else if (strcmp(c, "remove") == 0) {
            int k;
            scanf("%d", &k);
            remove1(&head, k);
            getchar();
        } else if (strcmp(c, "reverse") == 0) {
            reverse(&head);
        } else if (strcmp(c, "#") == 0) {
            break;
        }
    }
    printlist(head);
    return 0;
}