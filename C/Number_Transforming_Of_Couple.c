#include<stdio.h>
struct Node{
    int a;
    int b;
    int step;
    int path[1000][2];
};
typedef struct Node Node;
int visited[31][31];
int main(){
    int c,d,x,y;
    scanf("%d %d %d %d",&c,&d,&x,&y);
    if(c==x && d==y){
        printf("0 (%d %d)",c,d);
        return 0;
    }else if( (c+d) %2 != 0 && x%2==0 && y%2==0){
        printf("-1");
        return 0;
    }
    Node ds[1000];
    int front=0,after=0;
    ds[after].a=c;
    ds[after].b=d;
    ds[after].step=0;
    ds[after].path[0][0]=c;
    ds[after].path[0][1]=d;
    visited[c][d]=1;
    after++;
    while(front<after){
        Node cur=ds[front++];
        int a=cur.a,b=cur.b;
        if(a==x && b==y){
            printf("%d",cur.step);
            for(int i=0;i<=cur.step;i++){
                printf("(%d %d) ",cur.path[i][0],cur.path[i][1]);
            }
            return 0;
        }
        if(a>b){
            int na=a-b,nb=b;
            if(na>=0 && nb<=30 && visited[na][nb]!=1){
                visited[na][nb]=1;
                Node nxt=cur;
                nxt.a=na;
                nxt.b=nb;
                nxt.step++;
                nxt.path[nxt.step][0]=na;
                nxt.path[nxt.step][1]=nb;
                ds[after++]=nxt;
            }
        }
        int na=a+b,nb=b;
        if(na>=0 && nb<=30 && visited[na][nb]!=1){
            visited[na][nb]=1;
            Node nxt=cur;
            nxt.a=na;
            nxt.b=nb;
            nxt.step++;
            nxt.path[nxt.step][0]=na;
            nxt.path[nxt.step][1]=nb;
            ds[after++]=nxt;
        }
        na=b;
        nb=a;
        if(na>=0 && nb<=30 && visited[na][nb]!=1){
            visited[na][nb]=1;
            Node nxt=cur;
            nxt.a=na;
            nxt.b=nb;
            nxt.step++;
            nxt.path[nxt.step][0]=na;
            nxt.path[nxt.step][1]=nb;
            ds[after++]=nxt;
        }
    }
}