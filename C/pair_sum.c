#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int twopointer(int a[],int n,int x){
    long long count=0;
    int left=0;
    int right=n-1;
    while(left<=right){
        if(a[left]+a[right]<=x){
            count+=right-left;
            left++;
        }else{
            right--;
        }
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compare);
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",twopointer(a,n,x));
    }
}