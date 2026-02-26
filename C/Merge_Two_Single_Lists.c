#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node makenode(int x){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
void add(node *a,int x){
    node tmp=makenode(x);
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
void dsort(node head1,node head2,node *result){ // thu tu giam dan
    while(head1!=NULL){
        node p=*result;
        if(*result==NULL){
            *result=makenode(head1->data);
            head1=head1->next;
            continue;
        }
        // nếu x lớn hơn hoặc bằng phần tử đầu => chèn lên đầu
        if(head1->data >= (*result)->data){
            node tmp=makenode(head1->data);
            tmp->next=*result;
            *result=tmp;
            head1=head1->next;
            continue;
        }
        while(p->next!=NULL && p->next->data > head1->data){
            p=p->next;
        }
        node tmp=makenode(head1->data);
        tmp->next=p->next;
        p->next=tmp;
        head1=head1->next;
    }
    while(head2!=NULL){
        node p=*result;
        if(*result==NULL){
            *result=makenode(head2->data);
            head2=head2->next;
            continue;
        }
        if(head2->data >= (*result)->data){
            node tmp=makenode(head2->data);
            tmp->next=*result;
            *result=tmp;
            head2=head2->next;
            continue;
        }
        while(p->next!=NULL && p->next->data > head2->data){
            p=p->next;
        }
        node tmp=makenode(head2->data);
        tmp->next=p->next;
        p->next=tmp;
        head2=head2->next;
    }
}
void isort(node head1,node head2,node *result){ // thu tu tang dan
    while(head1!=NULL){
        node p=*result;
        if(*result==NULL){
            *result=makenode(head1->data);
            head1=head1->next;
            continue;
        }
        // nếu x lớn hơn hoặc bằng phần tử đầu => chèn lên đầu
        if(head1->data <= (*result)->data){
            node tmp=makenode(head1->data);
            tmp->next=*result;
            *result=tmp;
            head1=head1->next;
            continue;
        }
        while(p->next!=NULL && p->next->data < head1->data){
            p=p->next;
        }
        node tmp=makenode(head1->data);
        tmp->next=p->next;
        p->next=tmp;
        head1=head1->next;
    }
    while(head2!=NULL){
        node p=*result;
        if(*result==NULL){
            *result=makenode(head2->data);
            head2=head2->next;
            continue;
        }
        if(head2->data <= (*result)->data){
            node tmp=makenode(head2->data);
            tmp->next=*result;
            *result=tmp;
            head2=head2->next;
            continue;
        }
        while(p->next!=NULL && p->next->data < head2->data){
            p=p->next;
        }
        node tmp=makenode(head2->data);
        tmp->next=p->next;
        p->next=tmp;
        head2=head2->next;
    }
}
void inra(node a){
    while(a!=NULL){
        printf("%d ",a->data);
        a=a->next;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    node head1=NULL,head2=NULL;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        add(&head1,k);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        add(&head2,k);
    }
    node result=NULL;
    char s[10];
    scanf("%s",s);
    if(strcmp(s,"dSort")==0){
        dsort(head1,head2,&result);
        inra(result);
    }else{
        isort(head1,head2,&result);
        inra(result);
    }
}