#include<stdio.h>
#include<math.h>
int max(int a,int b){
    return (a>b) ? a : b;
}
int min(int a,int b){
    return (a<b) ? a : b;
}
int main(){
    int n;
    scanf("%d",&n);
    int MaxX=0,MinX=100000,MaxY=0,MinY=100000;
    while(n--){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int curmaxX=max(x1,x2);
        int curminX=min(x1,x2);
        int curmaxY=max(y1,y2);
        int curminY=min(y1,y2);
        MaxX=max(curmaxX,MaxX);
        MinX=min(curminX,MinX);
        MaxY=max(curmaxY,MaxY);
        MinY=min(curminY,MinY);   
    }
    printf("%d",(MaxX-MinX)*(MaxY-MinY));
}