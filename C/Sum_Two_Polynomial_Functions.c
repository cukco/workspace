#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node MakeNode(int x){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
void addlast(node *a,int x){
    node tmp=MakeNode(x);
    if(*a==NULL){
        *a=tmp;
    }else{
        node p=*a;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
int sonode(node a){
    int x=0;
    while(a!=NULL){
        x++;
        a=a->next;
    }
    return x;
}
void plus(node head1, node head2, node *tong) {
    while (head1 != NULL || head2 != NULL) {
        int x = 0;
        if (head1 != NULL) {
            x += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            x += head2->data;
            head2 = head2->next;
        }
        addlast(tong, x);
    }
}
void minus(node head1, node head2, node *tong) {
    while (head1 != NULL || head2 != NULL) {
        int x = 0;
        if (head1 != NULL) {
            x += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            x -= head2->data;
            head2 = head2->next;
        }
        addlast(tong, x);
    }
}
void inra(node a) {
    while (a != NULL) {
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}
void tong1(node a){
    int x=0;
    node tmp=a;
    while (tmp != NULL) {
        if(tmp->data!=0){
            x++;
        }
        tmp = tmp->next;
    }
    if(x==0){
        printf("1 0");
    }else{
        printf("%d ",x);
        inra(a);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    node head1=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        addlast(&head1,a[i]);
    }
    scanf("%d",&n);
    node head2=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        addlast(&head2,a[i]);
    }
    node tong=NULL;
    char c[10];
    scanf("%s",c);
    if(strcmp(c,"minus")==0){
        minus(head1,head2,&tong);
    }else{
        plus(head1,head2,&tong);
    }
    tong1(tong);
}