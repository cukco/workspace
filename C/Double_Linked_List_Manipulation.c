#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node* node;
node makenode(int x){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->data=x;
    tmp->next=NULL;
    tmp->prev=NULL;
    return tmp;
}
void addlast(node *a,int x){
    if (*a == NULL) {
        *a = makenode(x);
        return;
    }
    node tmp=makenode(x);
    node p=*a;
    while(p->next!=NULL){
        if(p->data==x) return;
        p=p->next;
    }
    if(p->data==x) return;
    p->next=tmp;
    tmp->prev=p;
}
void addfirst(node *a,int x){
    node p=*a;
    while(p!=NULL){
        if(p->data==x){
            return;
        }
        p=p->next;
    }
    if(*a==NULL){
        *a=makenode(x);
    }else{
        node tmp=makenode(x);
        tmp->next = *a;
        tmp->prev = NULL;
        (*a)->prev = tmp;
        *a = tmp;
    }
}
void addafter(node *a,int u,int v){
    if (*a == NULL) {
        addfirst(a, u);
        return;
    }
    node p = *a,k=*a;
    while(k!=NULL){
        if(k->data==u){
            return;
        }
        k=k->next;
    }
    while (p != NULL && p->data!=v) {
        p = p->next;
    }
    if (p == NULL) {
        return;
    } else {
        node tmp=makenode(u);
        tmp->next = p->next;
        tmp->prev = p;
        p->next = tmp;
        if (tmp->next != NULL) {
            tmp->next->prev = tmp;
        }
    }
}
void addbefore(node *a,int u,int v){
    if (*a == NULL) {
        addfirst(a, u);
        return;
    } 
    node p = *a,k=*a;
    while(k!=NULL){
        if(k->data==u){
            return;
        }
        k=k->next;
    }
    while (p != NULL && p->data!=v) {
        p = p->next;
    }
    if (p == NULL) {
        return;
    } else {
        node tmp=makenode(u);
        if(p->prev==NULL){
            addfirst(a,u);
            return;
        }
        tmp->next = p;
        tmp->prev = p->prev;
        p->prev->next = tmp;
        p->prev = tmp;
    }
}
void remove1(node *a, int y) {
    node p = *a;
    while (p != NULL) {
        node next = p->next; 
        if (p->data == y) {
            if (p->prev != NULL)
                p->prev->next = p->next;
            else
                *a = p->next;

            if (p->next != NULL)
                p->next->prev = p->prev;

            free(p);
        }
        p = next;
    }
}
void reverse(node *a) {
    node curr = *a;
    node tmp = NULL;
    while (curr != NULL) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }
    if (tmp != NULL)
        *a = tmp->prev;
}
void inra(node a){
    while(a!=NULL){
        printf("%d ",a->data);
        a=a->next;
    }
}
void inra0(node a){
    while(a->next!=NULL){
        a=a->next;
    }
    while(a!=NULL){
        printf("%d ",a->data);
        a=a->prev;    
    }
}
int main() {
    int n;
    node head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        addlast(&head, a);
    }
    getchar(); 
    while (1) {
        char c[100];
        scanf("%s",c);
        if (strcmp(c, "addlast") == 0) {
            int k;
            scanf("%d", &k);
            addlast(&head, k);
            getchar();
        } else if (strcmp(c, "addfirst") == 0) {
            int k;
            scanf("%d", &k);
            addfirst(&head, k);
            getchar();
        } else if (strcmp(c, "addafter") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addafter(&head, u, v);
            getchar();
        } else if (strcmp(c, "addbefore") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addbefore(&head, u, v);
            getchar();
        } else if (strcmp(c, "remove") == 0) {
            int k;
            scanf("%d", &k);
            remove1(&head, k);
            getchar();
        } else if (strcmp(c, "reverse") == 0) {
            reverse(&head);
        }else if(strcmp(c, "output") == 0){
            int k;
            scanf("%d", &k);
            if(k==1){
                inra(head);
            }else if(k==0){
                inra0(head);
            }
        }else if (strcmp(c, "#") == 0) {
            break;
        }
    }
    return 0;
}