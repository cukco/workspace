#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    char name[10];
    struct Node *leftmostchild;
    struct Node *rightsibling;
};
typedef struct Node* node;
node ds[10000]={NULL}; // index của name trong list này và bên dưới như nhau
char name[10000][10];   // giúp chuyển đổi từ string -> int để quản lý node
int idcount=0;
int getid(char *s){
    for(int i=0;i<idcount;i++){
        if(strcmp(name[i],s)==0) return i; // nếu id đã trùng thì trả về
    }
    strcpy(name[idcount],s); // ghi name mới vào 
    return idcount++;  // trả vể id mới, sau đó cộng thêm cho lần sử dụng id sau
}
node makenode(char *s){
    int id=getid(s);
    if(ds[id]==NULL){
        ds[id]=(node)malloc(sizeof(struct Node));
        strcpy(ds[id]->name,s);
        ds[id]->leftmostchild=NULL;
        ds[id]->rightsibling=NULL;
    }
    return ds[id];
}
void add(char *parent, char *child){
    node p=makenode(parent);  // tạo 2 node ảo mới
    node c=makenode(child);
    c->rightsibling=NULL;
    if(p->leftmostchild==NULL){
        p->leftmostchild=c;
    }else{
        node t=p->leftmostchild;
        while(t->rightsibling!=NULL){
            t=t->rightsibling;
        }
        t->rightsibling=c;
    }
}
int countdesc(node a){
    int count=0;
    if(a==NULL || a->leftmostchild==NULL) return 0;
    else{
        node c=a->leftmostchild;
        while(c!=NULL){
            count+=1+countdesc(c);
            c=c->rightsibling;
        }
    }
    return count;
}
int depth(node u) {
    if (u == NULL) return 0;
    int best = 0;
    node c = u->leftmostchild;
    while (c != NULL) {
        int d = 1 + depth(c);
        if (d > best) best = d;
        c = c->rightsibling;
    }
    return best;
}
int main(){
    char line[200];
    int i=0;
    while(1){
        fgets(line,sizeof(line),stdin);
        line[strcspn(line,"\n")]=0;
        if(strcmp(line,"***")==0) break;
        char *child = strtok(line, " ");
        char *parent = strtok(NULL, " ");
        add(parent,child);
    }
    while(1){
        fgets(line,sizeof(line),stdin);
        line[strcspn(line,"\n")]=0;
        if(strcmp(line,"***")==0) break;
        char *cmd = strtok(line, " ");
        char *name1 = strtok(NULL, " ");
        int k=getid(name1);
        if(strcmp(cmd,"descendants")==0){
            printf("%d\n",countdesc(ds[k]));
        }else if(strcmp(cmd,"generation")==0){
            printf("%d\n",depth(ds[k]));
        }
    }
}