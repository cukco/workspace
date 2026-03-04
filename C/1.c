#include<stdio.h>
int check(int x){
    if(x<0) return 2;
    return 1;
}
int main(){
    printf("%d",check(3));
}