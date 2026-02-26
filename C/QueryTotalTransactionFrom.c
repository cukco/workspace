#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct hashtable{
    long long id;
    int money;
    struct hahstable *next;
};
typedef struct hashtable* hashtable;
int returnid(char c[]){
    int sum=0;
    int heso=1;
    for(int i=strlen(c)-1;i>=0;i--){
        if(isdigit(c[i])){
            sum+=(c[i]-'0')*heso;
            heso*=10;
        }else break;
    }
    return sum;
}
hashtable table[10000];
int hashfunction(long long key){
    return key%10000;
}
int checkexist(long long key){
    int index=hashfunction(key);
    if(table[index]==NULL) return 0;
    else return 1;
}
int main(){
    while(1){
    }
}