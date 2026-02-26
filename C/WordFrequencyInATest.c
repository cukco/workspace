#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct hash{
    char c[21];
    int freq;
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
hash array[200007]={NULL};
int inter_count=0;
hash find(char str[]){
    int index=returnindex(str);
    hash p=array[index];
    if(p!=NULL){
        while(p!=NULL){
            if(strcmp(p->c,str)==0){
                return p;
            }
            p=p->next;
        }
    }
    return NULL;
}
void insert(char str[]){
    int index=returnindex(str);
    hash tmp=(hash)malloc(sizeof(struct hash));
    strcpy(tmp->c,str);
    tmp->next=NULL;
    tmp->freq=1;
    tmp->next=array[index];
    array[index]=tmp;
    inter_count++;
}
struct hashtam{
    char c[21];
    int freq;
};
typedef struct hashtam hashtam;
int compare(const void *a,const void *b){
    hashtam *so1=(hashtam *)a;
    hashtam *so2=(hashtam *)b;
    return strcmp(so1->c,so2->c);
}
int main(){
    char str[21];
    while(scanf("%s",str)!=EOF){
        hash p=find(str);
        if(p==NULL) insert(str);
        else {
            p->freq++;
        }
    }
    hashtam uniqe_array[inter_count];
    int x=0;
    for(int i=0;i<200007;i++){
        if(array[i]!=NULL){
            hash p=array[i];
            while(p!=NULL){
                strcpy(uniqe_array[x].c,p->c);
                uniqe_array[x].freq=p->freq;
                x++;
                p=p->next;
            }
        }
    }
    qsort(uniqe_array,inter_count,sizeof(hashtam),compare);
    for(int i=0;i<inter_count;i++){
        printf("%s %d\n",uniqe_array[i].c,uniqe_array[i].freq);
    }
}
