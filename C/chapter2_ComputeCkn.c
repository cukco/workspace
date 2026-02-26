#include<stdio.h>
int array[1000][1000]={0};
int compute(int k,int n){
    if(array[k][n]!=0) return array[k][n]%(1000000007);
    else if(k==0 || k==n) return 1;
    else if(k==1 || k+1==n) return n;
    else{
        array[k][n-1]=compute(k,n-1);
        array[k-1][n-1]=compute(k-1,n-1);
        array[k][n]=array[k][n-1]+array[k-1][n-1];
        return array[k][n]%(1000000007);
    }
}
int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    printf("%d",compute(k,n));

}