#include<stdio.h>
int main(){
    char n[3][3];
    int x=0;
    int o=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf(" %c",&n[i][j]);
            if(n[i][j]=='X'){
                x++;
            }else if(n[i][j]=='0'){
                o++;
            }
        }
    }
    if(x<o || x>(o+1)){
        printf("khonghople");
        return 0;
    }
    for(int i=0;i<3;i++){
        int flag=0;
        for(int j=0;j<3;j++){
            if(n[i][j]=='X'){
                flag+=2;
            }else if(n[i][j]=='0'){
                flag+=3;
            }else{
                flag+=5;
            }
        }
        if(flag==6){
            printf("mewin");
            return 0;
        }
        if(flag==9){
            printf("lywin");
            return 0;
        }
    }
    if(n[0][0]=='X' && n[1][1]=='X' && n[2][2]=='X' ){
        printf("mewin");
        return 0;
    }
    if(n[0][0]=='0' && n[1][1]=='0' && n[2][2]=='0' ){
        printf("lywin");
        return 0;
    }
    if(n[0][2]=='X' && n[1][1]=='X' && n[2][0]=='X' ){
        printf("mewin");
        return 0;
    }
    if(n[0][2]=='0' && n[1][1]=='0' && n[2][0]=='0' ){
        printf("lywin");
        return 0;
    }
    if(o<x){
        printf("ly");
        return 0;
    }else if(o==x){
        printf("me");
        return 0;
    }else if(o==4 && x==5){
        printf("hoa");
        return 0;
    }
}