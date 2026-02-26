#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;

}
int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int donuoc(int from,int to, int goal){
    int count=0;
    int curfrom=0;
    int curto=0;
    while(1){
        if(curfrom==goal || curto==goal) break;
        if(curfrom==0){
            curfrom=from;
            count++;
            continue;
        }
        if(curto==to){
            curto=0;
            count++;
            continue;
        }
        int amount=(curfrom > to-curto) ? (to-curto) : curfrom;
        curto+=amount;
        curfrom-=amount;
        count++;
    }
    return count;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (c > a && c > b) { 
        printf("-1");
        return 0;
    }
    if (c % gcd(a, b) != 0) {
        printf("-1");
        return 0;
    }
    printf("%d",min(donuoc(a,b,c),donuoc(b,a,c)));
}