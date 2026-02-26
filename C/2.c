#include <stdio.h>

int a[20];
int visited[20];
int arr[20][20];
int sum=0;
int min=10000;
void gen(int n, int k) {
    if (k == n-1) {
        sum+=arr[0][a[0]];
        for(int i=0;i<n-1;i++){
            sum+=arr[a[i]][a[i+1]];
        }
        sum+=arr[a[n-1]][0];
        if(sum<min){
            min=sum;
        }
        sum=0;
        return;
    }
    for (int i = 2; i <=n; i++) {
        if (visited[i] == 1) continue; 
        visited[i] = 1;                
        a[k] = i;                     
        gen(n, k + 1);                 
        visited[i] = 0;                
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) visited[i] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    gen(n, 0);
    printf("%d",min);
    return 0;
}
