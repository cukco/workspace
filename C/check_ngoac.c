#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct Node{
    char ngoac;
    struct Node *next;
};
typedef struct Node* node;
node makenode(char c){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->ngoac=c;
    tmp->next=NULL;
    return tmp;
}
bool empty(node a){
    return a==NULL;
}
void push(node *a,char c){
    node tmp=makenode(c);
    node p=*a;
    if(empty(*a)){
        *a=tmp;
    }else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
int number(node a){
    int x=0;
    while(a!=NULL){
        x++;
        a=a->next;
    }
    return x;
}
void pop(node *a,char x){
    if(*a==NULL){
        return;
    }else{
        node sau=*a,truoc=NULL;
        if(sau->next==NULL){
            if(sau->ngoac=='(' && x==')'){
                *a=NULL;
                return;
            }else if(sau->ngoac=='[' && x==']'){
                *a=NULL;
                return;
            }else if(sau->ngoac=='{' && x=='}'){
                *a=NULL;
                return;
            }
        }
        while(sau->next!=NULL){
            truoc=sau;
            sau=sau->next;
        }
        if(sau->ngoac=='(' && x==')'){
            truoc->next=NULL;
        }else if(sau->ngoac=='[' && x==']'){
            truoc->next=NULL;
        }else if(sau->ngoac=='{' && x=='}'){
            truoc->next=NULL;
        }
    }
}
void inra(node a){
    while(a!=NULL){
        printf("%c ",a->ngoac);
        a=a->next;
    }
}
int main(){
    node head=NULL;
    char bai[1000];
    fgets(bai,sizeof(bai),stdin);
    int checkpush=0;
    bai[strcspn(bai,"\n")]='\0';
    for(int i=0;i<strlen(bai);i++){
        if(bai[i]=='(' || bai[i]=='{' || bai[i]=='['){
            push(&head,bai[i]);
            checkpush++;
        }
        if(bai[i]==')' || bai[i]=='}' || bai[i]==']'){
            pop(&head,bai[i]);
        }
    }
    if(number(head)==0 && checkpush !=0){
        printf("1");
    }else{
        printf("0");
    }
}