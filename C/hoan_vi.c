#include<stdio.h>
#include<ctype.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if(m<=0 ||n<=0){
        printf("Error");
        return 0;
    }
    
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++){
        int temp=a[i][x];
        a[i][x]=a[i][y];
        a[i][y]=temp;
    }
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}