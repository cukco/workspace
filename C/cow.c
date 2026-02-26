#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char cow[8][6]={"Krixi","Toro","Emily","Max","Yasuo","Leona","Garen","Jinx"};
    char order[8][6];
    while(n--){
        char s[1000];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; 
        char name1[50], name2[50];
        sscanf(s, "%s must be milked beside %s", name1, name2);
        printf("%s ", name1);
        printf("%s", name2);
    }
}