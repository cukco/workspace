#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char name[10];
    struct Node *next;
};
typedef struct Node* node;
node makenode(char c[10]){
    node tmp=(node)malloc(sizeof(struct Node));
    strcpy(tmp->name,c);
    tmp->next=NULL;
    return tmp;
}
void add(node *a,char c[10]){
    node tmp=makenode(c);
    if(*a==NULL) *a=tmp;
    else{
        node p=*a;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
int main(){
    char write[20];
    node ds[100][10]={NULL};
    while(1){
        scanf(" %s",write);
        char c[2][10];
        int index=0;
        char *token = strtok(write, " ");
        while (token != NULL) {
            strcpy(c[index],token);
            index++;
            token = strtok(NULL, " ");
        }
        if(ds[])
    }
}