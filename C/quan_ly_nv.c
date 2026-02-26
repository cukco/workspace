#include<stdio.h>
#include<string.h>
struct name{
    char ten[31];
    int namsinh;
    int year;
    long long luong;
};
typedef struct name name;
int main(){
    name ds[50];
    int n;
    scanf("%d",&n);
    long long max;
    scanf("%lld",&max);
    long long basic;
    scanf("%lld",&basic);
    int heso;
    scanf("%d",&heso);
    int heso5;
    scanf("%d",&heso5);
    getchar();
    long long sum=0;
    for(int i=0;i<n;i++){
        fgets(ds[i].ten,sizeof(ds[i].ten),stdin);
        ds[i].ten[strcspn(ds[i].ten,"\n")]='\0';
        scanf("%d",&ds[i].namsinh);
        scanf("%d",&ds[i].year);
        int sodot=ds[i].year/5;
        getchar();
        ds[i].luong=basic*heso+basic*sodot*heso5;
        if(ds[i].luong>max){
            ds[i].luong=max;
        }
        sum+=ds[i].luong;
    }
    for(int i=0;i<n;i++){
        printf("%s %d %d %lld ",ds[i].ten,ds[i].namsinh,ds[i].year,ds[i].luong);
        
    }
    printf("%lld",sum);
}