#include<stdio.h>
#include<stdlib.h>
int a[100];
int tmp[100];
int check(int n,int arr[]){
    int stack[100]={0};
    int top=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1 || arr[i]==2 || arr[i]==3) stack[++top]=arr[i]; 
        else{
            if(top==0) return 0;
            if(arr[i]-stack[top]!=3) return 0;
            top--;
        }
    }
    return(top==0);
}
void gen(int sodiemtrong,int k,int luuso[100],int sophantu){
    if(k==sodiemtrong){
        int x=0;
        for(int i=0;i<sophantu;i++){
            if(luuso[i]==0){
                tmp[i]=a[x];
                x++;
            }
            else tmp[i]=luuso[i];
        }
        if(check(sophantu,tmp)){
            for(int i=0;i<sophantu;i++) printf("%d",tmp[i]);
            printf(" ");
        }
        return;
    }
    for(int i=1;i<7;i++){
        a[k]=i;
        gen(sodiemtrong,k+1,luuso,sophantu);
    }
}
void count(int n,int luuso[100]){
    int sodiemtrong=0;
    for(int i=0;i<n;i++){
        if(luuso[i]==0) sodiemtrong++;
    }
    gen(sodiemtrong,0,luuso,n);
}
int main(){
    int luuso[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&luuso[i]);
    }
    count(n,luuso);
    printf("\n");
}