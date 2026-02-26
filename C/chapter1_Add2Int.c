#include<stdio.h>
#include<string.h>
#define MAX 40
void addBigINT(char a[],char b[],char res[]){
    char tmp[MAX];
    int carry=0,k=0;
    int i=strlen(a)-1;
    int j=strlen(b)-1;
    while(i>=0 || j>=0 ||carry){
        int da=(i>=0 ? a[i]-'0' : 0);
        int db=(j>=0 ? b[j]-'0' : 0);
        int sum=da+db+carry;
        tmp[k++]=sum%10+'0';
        carry=sum/10;
        i--;
        j--;
    }
    for(int x=0;x<k;x++){
        res[x]=tmp[k-x-1];
    }
    res[k]='\0';
}
int main(){
    char a[MAX],b[MAX],c[MAX];
    scanf("%s %s",a,b);
    addBigINT(a,b,c);
    printf("%s",c);
}