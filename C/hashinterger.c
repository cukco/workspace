#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned long long ull;
struct hash{
    ull key;
    struct hash *next;
};
typedef struct hash* hash;
hash array[10007]={NULL};
int getindex(ull key){
    return key%10007;
}
int find(ull x){
    int index=getindex(x);
    hash tmp=array[index];
    while(tmp!=NULL){
        if(tmp->key==x){
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}
void insert(ull x){
    if(find(x)){
        printf("0\n");
        return;
    }
    int index=getindex(x);
    hash tmp=(hash)malloc(sizeof(struct hash));
    tmp->key=x;
    tmp->next=NULL;
    if(array[index]==NULL){
        array[index]=tmp;
    }else{
        tmp->next=array[index];
        array[index]=tmp;
    }
    printf("1\n");
}
void insert1(ull x){
    int index=getindex(x);
    hash tmp=(hash)malloc(sizeof(struct hash));
    tmp->key=x;
    tmp->next=NULL;
    if(array[index]==NULL){
        array[index]=tmp;
    }else{
        tmp->next=array[index];
        array[index]=tmp;
    }
}
int main(){
    char cmd[50];
    while (scanf("%s", cmd) != EOF && strcmp(cmd, "*") != 0) {
        ull val = strtoull(cmd, NULL, 10);
        insert1(val);
    }
    while(1){
        char c[10];
        scanf(" %s",c);
        if(strcmp(c,"insert")==0){
            ull k;
            scanf("%llu",&k);
            insert(k);
        }else if(strcmp(c,"find")==0){
            ull k;
            scanf("%llu",&k);
            printf("%d\n",find(k));
        }else if(strcmp(c,"***")==0){
            break;
        }
    }
}