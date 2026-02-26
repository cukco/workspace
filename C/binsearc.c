#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void binsearch(int a[],int x,int left,int right){
    if(left>right){
        printf("0\n");
        return;
    }
    int mid=(left+right)/2;
    if(a[mid]==x){
        printf("%d\n",1);
    }else if(a[mid]>x) binsearch(a,x,left,mid-1);
    else if(a[mid]<x) binsearch(a,x,mid+1,right);
}
int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compare);
    char c[10];
    while(1){
        scanf(" %s",c);
        if(strcmp(c,"#")==0) return 0;
        else{
            int k;
            scanf("%d",&k);
            binsearch(a,k,0,n-1);
        }
    }
}