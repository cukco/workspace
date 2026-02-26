#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char str[1000000];
    int sum=0;
    scanf("%[^\x1A]",str);
    char *token=strtok(str," \n");
    while(token){
        sum++;
        token=strtok(NULL," \n");
    }
    printf("%d",sum);
    return 0;
}
