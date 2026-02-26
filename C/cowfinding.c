#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int destination=1;
    int step=1;
    int current=x;
    int total=0;
    while(1){
        int next=x+destination*step;
        if(destination==1){
            if(current <= y && next >= y){
                total+=y-current;
                break;
        }
        }else{
            if(current >=y && next <=y){
                total+=current-y;
                break;
            }
        }
        total+=abs(next-current);
        current=next;
        step*=2;
        destination*=-1;
    }
    printf("%d",total);
}