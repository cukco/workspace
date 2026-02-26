#include<stdio.h>
int a[100],b[100];
int S;
int count=0;
void gen(int n,int index,int k){
    if(index==n){
        int tinh=0;
        for(int i=0;i<n;i++){
            tinh+=a[i]*b[i];
        }
        if(tinh==S) count++;
        return;
    }
    for(int i=0;i<=k;i++){
        b[index]=i;
        gen(n,index+1,k);
    }
}
int main(){
    int n;
    scanf("%d %d",&n,&S);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    gen(n,0,10);
    printf("%d",count);
}