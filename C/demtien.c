#include<stdio.h>
int S,n;
int a[100];
int count=0;
void gen(int index,int currsum){
    if(currsum==S){
        count++;
        return;
    }
    if( index==n || currsum>S) return;
    int remain=S-currsum;
    int maxqty=remain/a[index];
    for(int i=0;i<=maxqty;i++){
        gen(index,currsum+a[index]*i);
    }
}
int main(){
    scanf("%d %d",&n,&S);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    gen(0,0);
    printf("%d",count);
}