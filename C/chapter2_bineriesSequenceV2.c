#include<stdio.h>
char array[20];
void gen(int n,int k){
    if(k==n){
        for(int i=0;i<n;i++){
            printf("%d",array[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<2;i++){
        if(k>0){
            if(i==array[k-1] && i==1){
                continue;
            }
        }
        array[k]=i;
        gen(n,k+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    gen(n,0);
}