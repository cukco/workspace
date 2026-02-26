#include<stdio.h>
int max=0;
int n;
void check(int a[],int n,int index){
    int chuoi=0;
    for(int i=index;i<n-1;i++){
        if(a[i]>=a[i+1]){
            check(a,n,i+1);
            chuoi=0;
        }
        chuoi++;
        if(chuoi>max){
            max=chuoi;
        }
    }
}
int main(){
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    check(a,n,0);
    printf("%d",max);
}