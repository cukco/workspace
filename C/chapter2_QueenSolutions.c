#include<stdio.h>
#include<stdio.h>
int n;
int sum=0;
int a[12][12];
int cotsan[12];
int cot[12];
int cheo[2*12];
int cheo2[2*12];

void check(int r){
    if(r==n){
        sum++;
        return;
    }
    if(cotsan[r]!=-1){
        int c=cotsan[r];
        if(cot[c] || cheo[r+c] || cheo2[r-c+n-1]) return;
        cot[c]=cheo[r+c]=cheo2[r-c+n-1]=1;
        check(r+1);
        cot[c]=cheo[r+c]=cheo2[r-c+n-1]=0;
    }else{
        for(int c=0;c<n;c++){
            if(cot[c] || cheo[r+c] || cheo2[r-c+n-1]) continue;
            cot[c]=cheo[r+c]=cheo2[r-c+n-1]=1;
            check(r+1);
            cot[c]=cheo[r+c]=cheo2[r-c+n-1]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) cot[i]=0;
    for(int i=0;i<n;i++) cotsan[i]=-1;
    for(int i=0;i<2*n;i++) cheo[i]=cheo2[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1){
                cotsan[i]=j;
            }
        }
    }
    check(0);
    printf("%d",sum);
}
