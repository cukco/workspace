#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct hash{
    char id[21];
    long long money;
    struct hash *next;
};
typedef struct hash* hash;
unsigned int returnindex(char str[]){
    unsigned int hash=0;
    while(*str){
        hash=(hash*31)+(*str++);
    }
    return hash%200007;
}
hash array[200007];
hash find(char id[]){
    unsigned int index=returnindex(id);
    hash p=array[index];
    while(p!=NULL){
        if(strcmp(p->id,id)==0){
            return p;
        }
        p=p->next;
    }
    return p;
}
void insert(char id[],int tien){
    unsigned int index=returnindex(id);
    hash p=find(id);
    if(p==NULL){
        hash tmp=(hash)malloc(sizeof(struct hash));
        strcpy(tmp->id,id);
        tmp->money=0;
        tmp->money+=tien;
        tmp->next=array[index];
        array[index]=tmp;
    }else if(p!=NULL){
        p->money+=tien;
    }
}
int main(){
    while(1){
        char from[21];
        char to[21];
        int money;
        char time[9];
        char atm[5];
        scanf("%s",from);
        if(strcmp(from,"#")==0) break;
        scanf("%s %d %s %s",to,&money,time,atm);
        insert(from,money);
    }
    while(1){
        char cmd[30];
        char id[21];
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0) break;
        scanf("%s",id);
        hash tmp=find(id);
        if(tmp!=NULL) printf("%lld\n",find(id)->money);
        else printf("0\n");
    }
}