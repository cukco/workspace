#include<stdio.h>
#include<string.h>
int main(){
    char c[100000];
    fgets(c,100000,stdin);
    int n=strlen(c);
    for(int i=0;i<n-1;i++){
        if(c[i]=='A' && c[i+1]=='B'){
            for(int j=i+2;j<n-1;j++){
                if(c[j]=='B' && c[j+1]=='A'){
                    printf("YES");
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(c[i]=='B' && c[i+1]=='A'){
            for(int j=i+2;j<n-1;j++){
                if(c[j]=='A' && c[j+1]=='B'){
                    printf("YES");
                    return 0;
                }
            }
        }
    }
    printf("NO");
}