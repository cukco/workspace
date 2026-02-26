#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[10000];
    fgets(str,sizeof(str),stdin);
    int sum=0;
    int a=0,b=1;
    int dangnhan=0;
    for(int i=0;i<strlen(str);i++){
        if(isdigit(str[i])){
            a=a*10+(str[i]-'0');
        }else if(str[i]=='*'){
            b*=a;
            a=0;
            dangnhan=1;
        }else if(str[i]=='+' || i==strlen(str)-1){
            if(dangnhan==1){
                sum+=b*a;
                a=0;
                b=1;
                dangnhan=0;
            }else if(dangnhan==0){
                sum+=a;
                a=0;
            }
        }
    }
    printf("%d",sum);
}