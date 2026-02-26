#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    int n[]={20,10,50,60};
    qsort(n,4,sizeof(int),cmp);
    for(int i=0;i<4;i++){
        printf("%d ",n[i]);
    }
}