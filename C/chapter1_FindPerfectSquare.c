#include<stdio.h>
#include<math.h>
int main(){
    int sum=0,n;
    scanf("%d",&n);
    while(n--){
        int k;
        scanf("%d",&k);
        float x=sqrt(k);
        if((int)x-sqrt(k)==0) sum++;
    }
    printf("%d",sum);
}