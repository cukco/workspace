#include<stdio.h>
int n;
int a[21];
void gen(int n,int k){
    if(k==n){
        for(int i=0;i<n;i++) printf("%d",a[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<2;i++){
        a[k]=i;
        gen(n,k+1);
    }

}
int main(){
    scanf("%d",&n);
    gen(n,0);
}