#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int coef;
    int exp;
    struct Node* next;
};
typedef struct Node* node;
node makenode(int coef,int exp){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->coef=coef;
    tmp->exp=exp;
    tmp->next=NULL;
    return tmp;
}
node push
int main(){
    int iddaluu[100];
    while(1){
        char c[20];
        fgets(c,sizeof(c),stdin);
        c[strcspn(c,"\n")]='\0';
        if(strcmp(c,"AddTerm")==0){
            int id,coef,exp;
            scanf("%d %d %d",&id,&coef,&exp);
            int flag=0;
            for(int i=0;i<100;i++){
                if(id==iddaluu[i]){
                    flag==1;
                    break;
                }
            }
            if(flag==1){

            }
        }
    }
}