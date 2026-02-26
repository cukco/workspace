#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int somu(int coso,int somu){
    if(somu==0 || coso==1){
        return 1;
    }
    int x=coso;
    for(int i=1;i<somu;i++){
        x*=coso;
    }
    return x;
}
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
void addterm(node *a,int coef,int exp){
    node tmp=makenode(coef,exp);
    if(*a==NULL){
        *a=tmp;
    }else{
        node sau=*a,trc=NULL;
        while(sau!=NULL && sau->exp > exp){ // move to the right order's position
            trc=sau;
            sau=sau->next;
        }
        if (sau != NULL && sau->exp == exp) { // check if same exp
            sau->coef += coef;
            free(tmp); 
            if (sau->coef == 0) {  // delete when coef=0
                if (trc == NULL) {
                    *a = sau->next;
                } else {
                    trc->next = sau->next;
                }
                free(sau);
        }
        return;
    }
    if (trc == NULL) { //add node
        tmp->next = *a;
        *a = tmp;
    } else {
        tmp->next = sau;
        trc->next = tmp;
    }
    }
}
void Evaluate(node a,int k){
    int x=0;
    while(a!=NULL){
        x+=a->coef * somu(k,a->exp);
        a=a->next;
    }
    printf("%d\n",x);
}
void printpoly(node a){
    while(a!=NULL){
        printf("%d %d ",a->coef,a->exp);
        a=a->next;
    }
    printf("\n");
}
void addpoly(node a, node b, node *result) {
    node tmp;
    while (*result != NULL) {
        tmp = *result;
        *result = (*result)->next;
        free(tmp);
    }
    node tail = NULL;
    while (a != NULL && b != NULL) {
        node newNode = (node)malloc(sizeof(struct Node));
        if (a->exp == b->exp) {
            newNode->coef = a->coef + b->coef;
            newNode->exp = a->exp;
            a = a->next;
            b = b->next;
        } else if (a->exp > b->exp) {
            newNode->coef = a->coef;
            newNode->exp = a->exp;
            a = a->next;
        } else { 
            newNode->coef = b->coef;
            newNode->exp = b->exp;
            b = b->next;
        }
        newNode->next = NULL;
        if (*result == NULL) {
            *result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    while (a != NULL) {
        node newNode = (node)malloc(sizeof(struct Node));
        newNode->coef = a->coef;
        newNode->exp = a->exp;
        newNode->next = NULL;

        if (*result == NULL)
            *result = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        a = a->next;
    }
    while (b != NULL) {
        node newNode = (node)malloc(sizeof(struct Node));
        newNode->coef = b->coef;
        newNode->exp = b->exp;
        newNode->next = NULL;

        if (*result == NULL)
            *result = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        b = b->next;
    }
}
void destroy(node *a){
    *a=NULL;
}
int main(){
    node poly[100001];
    for(int i=0;i<100001;i++){
        poly[i]=NULL;
    }
    while(1){
        char c[20];
        scanf("%s",c);
        if(strcmp(c,"*")==0) return 0;
        if(strcmp(c,"AddTerm")==0){
            int id,coef,exp;
            scanf("%d %d %d",&id,&coef,&exp);
            getchar();
            addterm(&poly[id],coef,exp);
        }else if(strcmp(c,"EvaluatePoly")==0){
            int id,k;
            scanf("%d %d",&id,&k);
            getchar();
            Evaluate(poly[id],k);
        }else if(strcmp(c,"AddPoly")==0){
            int id1,id2,id3;
            scanf("%d %d %d",&id1,&id2,&id3);
            getchar();
            addpoly(poly[id1],poly[id2],&poly[id3]);
        }else if(strcmp(c,"PrintPoly")==0){
            int id;
            scanf("%d",&id);
            getchar();
            printpoly(poly[id]);
        }else if(strcmp(c,"Destroy")==0){
            int id;
            scanf("%d",&id);
            getchar();
            destroy(&poly[id]);
        }
    }
}