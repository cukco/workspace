#include<stdio.h>
void binsearch(int a[],int x,int step,int left,int right){
    if(left>right){
        printf("Cannot Find");
        return;
    }
    int mid=(left+right)/2;
    if(a[mid]==x){
        printf("%d ",mid);
        printf("%d",step);
    }else if(a[mid]>x) binsearch(a,x,step+1,left,mid-1);
    else if(a[mid]<x) binsearch(a,x,step+1,mid+1,right);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    binsearch(a,2,1,0,n-1);
}