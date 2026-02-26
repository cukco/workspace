#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct hash{
    char c[51];
    struct hash *next;
};
typedef struct hash* hash;
int returnindex(char c[]){
    int k=0;;
    for(int i=0;i<strlen(c);i++){
        k = (k * 256 + c[i]) % 200007;
    }
    return k;
}
hash array[200007];
int find(char str[]){
    int index=returnindex(str);
    hash p=array[index];
    if(p!=NULL){
        while(p!=NULL){
            if(strcmp(p->c,str)==0){
                return 1;
            }
            p=p->next;
        }
    }
    return 0;
}
void insert(char str[]){
    int index=returnindex(str);
    hash tmp=(hash)malloc(sizeof(struct hash));
    strcpy(tmp->c,str);
    tmp->next=NULL;
    tmp->next=array[index];
    array[index]=tmp;
}
void insert1(char str[]){
    if(find(str)==0){
        insert(str);
        printf("1\n");
    }else{
        printf("0\n");
    }    
}
int main(){
    while(1){
        char c[51];
        scanf(" %s",c);
        if(strcmp(c,"*")==0) break; 
        insert(c);
    }
    while(1){
        char cmd[10];
        scanf(" %s",cmd);
        if(strcmp(cmd,"insert")==0){
            char c[51];
            scanf(" %s",c);
            insert1(c);
        }else if(strcmp(cmd,"find")==0){
            char c[51];
            scanf(" %s",c);
            printf("%d\n",find(c));
        }else if(strcmp(cmd,"***")==0){
            break;
        }
    }
}