#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int n,m,sx,sy;
struct Node{
    int x;
    int y;
    struct Node *next;
};
typedef struct Node* node;
node makenode(int a,int b){
    node tmp=(node)malloc(sizeof(struct Node));
    tmp->x=a;
    tmp->y=b;
    tmp->next=NULL;
    return tmp;
}
void push(node *a,int h,int b){
    node tmp=makenode(h,b);
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
void pop(node *a){
    if(*a==NULL) return;
    else{
        *a=(*a)->next;
    }
}
int d[1000][1000]; // lưu khoảng cách đi từ ô xuất phát đến ô này
bool visited[1000][1000];
int moveX[4]={0,0,1,-1};
int moveY[4]={1,-1,0,0};
void gen(int sx,int sy,int maze[][1000],int n,int m,node *head){
    visited[sx][sy]=true;
    push(head,sx,sy);
    while(*head != NULL){
        int x=(*head)->x;
        int y=(*head)->y;
        pop(head);
        for(int i=0;i<4;i++){
            int u=x+moveX[i];
            int v=y+moveY[i];
            if(u<0 || u>=n || v<0 || v>=m) continue;
            if(maze[u][v]==1) continue;
            if(!visited[u][v]){
                d[u][v]=d[x][y]+1;
                visited[u][v]=true;
                if(u==0 || u==n-1 || v==0 || v==m-1){
                    printf("%d",d[u][v]+1);
                    exit(0);
                }
                push(head,u,v);
            }

        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&sx,&sy);
    int maze[n][m];
    sx=sx-1;
    sy=sy-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    if (sx == 0 || sx == n-1 || sy == 0 || sy == m-1) {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           visited[i][j]=false;
           d[i][j]=0;
        }
    }
    node head=NULL;
    gen(sx,sy,maze,n,m,&head);
    printf("-1");
}