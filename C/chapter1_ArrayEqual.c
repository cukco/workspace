#include<stdio.h>
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        int array1len,array2len;
        scanf("%d %d",&array1len,&array2len);
        int array1[array1len];
        int array2[array2len];
        for(int i=0;i<array1len;i++){
            scanf("%d",&array1[i]);
        }
        for(int i=0;i<array2len;i++){
            scanf("%d",&array2[i]);
        }
        if(array1len!=array2len) printf("0\n");
        else{
            int flag=1;
            for(int i=0;i<array1len;i++){
                if(array1[i]!=array2[i]){
                    flag=0;
                    break;
                }
            }
            printf("%d\n",flag);
        }
    }
}