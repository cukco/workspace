#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char id[21];
    int tier;
    struct node *next;
};
typedef struct node* node;
node makenode(char *str,int tier){
    node tmp=(node)malloc(sizeof(struct node));
    strcpy(tmp->id,str);
    tmp->tier=tier;
    tmp->next=NULL;
    return tmp;
}
void submit(node *root,char *str,int tier){
    if(*root==NULL){
        *root=makenode(str,tier);
    }else{
        if(tier==1){
            node p=*root;
            if(p->tier==0){
                node tmp=makenode(str,tier);
                tmp->next=*root;
                *root=tmp;
            }else{
                while(p->next !=NULL && p->next->tier==1){
                    p=p->next;
                }
                node tmp=makenode(str,tier);
                tmp->next=p->next;
                p->next=tmp;
            }
        }else if(tier==0){
            node p=*root;
            while(p->next != NULL) p=p->next;
            node tmp=makenode(str,tier);
            p->next=tmp;
        }
    }
}
void run(node *root){
    if(*root==NULL){
        printf("EMPTY\n");
    }else{
        printf("%s %d\n",(*root)->id,(*root)->tier);
        *root=(*root)->next;
    }
}
int main(){
    node root=NULL;
    char cmd[21];
    while(1){
        scanf(" %s",cmd);
        getchar();
        if(strcmp(cmd,"END")==0) break;
        else if(strcmp(cmd,"SUBMIT")==0){
            char id[21];
            int tier;
            scanf("%s %d",id,&tier);
            submit(&root,id,tier);
        }else if(strcmp(cmd,"RUN")==0){
            run(&root);
        }
    }
}