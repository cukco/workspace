#include <stdio.h>
#include<string.h>
int n;
int X[20];
int a[20][20];
int visited[20];
int cost=0;
int min=__INT_MAX__;
void check(int k){
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i]=1;
            X[k]=i;
            cost+=a[X[k-1]][X[k]];
            if (cost < min) { 
                if (k == n) {
                    int total = cost + a[i][1]; 
                    if (total < min)
                        min = total;
                } else {
                    check(k + 1);
                }
            }
            visited[i]=0;
            cost-=a[X[k-1]][X[k]];
        }
    }
}
int main() {   
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    X[1]=1;
    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    visited[1]=1;
    check(2);
    printf("%d",min);
}