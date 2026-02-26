#include<stdio.h>
#include<math.h>
int check(int n){
    if(n<=3){
        return 1;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int a;
    scanf("%d",&a);
    if(check(a)==1){
        printf("%d",a);
        return 0;
    }
    int c[100];
    int b=0;
    while(a!=1){
        for(int i=2;i<=a;i++){
            if(a%i==0 && check(i)==1){
                c[b]=i;
                a=a/i;
                b++;
                break;
            }
        }
    }
    for(int i=0;i<b;i++){
        if(i==b-1){
            printf("%d",c[i]);
        }else{
            printf("%d*",c[i]);
        }
    }
}