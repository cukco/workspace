#include<stdio.h>
#include<string.h>
int main(){
    char text[1000000];
    char p2[100],p1[100];
    scanf("%s",p1);
    getchar();
    fgets(p2,sizeof(p2),stdin);
    p2[strcspn(p2,"\n")]='\0';
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")]='\0';
    char *token=strtok(text," ");
    while(token){
        if(strcmp(token,p1)==0){
            printf("%s ",p2);
        }else printf("%s ",token);
        token=strtok(NULL," ");
    }
}