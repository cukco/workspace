#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ds{
    int day;
    char name[10];
    int change;
};
typedef struct ds ds;
int compare(const void *a,const void *b){
    const ds *ngay1=(const ds *)a;
    const ds *ngay2=(const ds *)b;
    return (ngay1->day - ngay2->day);
}
int main(){
    int n;
    scanf("%d",&n);
    ds mang[n];
    int count=0;;
    for(int i=0;i<n;i++){
        scanf("%d",&mang[i].day);
        scanf(" %s",mang[i].name);
        scanf("%d",&mang[i].change);
    }
    qsort(mang,n,sizeof(ds),compare);
    int Sind=9,Vang=9,Jersey=9;
    int curr=0,past=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(strcmp(mang[i].name,"Sind")==0){
            past=curr;
            curr=1;
            Sind+=mang[i].change;
            if(max < Sind && curr!=past) count++;
        }else if(strcmp(mang[i].name,"Vang")==0){
            past=curr;
            curr=2;
            Vang+=mang[i].change;
            if(max < Vang && curr!=past) count++;
        }else if(strcmp(mang[i].name,"Jersey")==0){
            past=curr;
            curr=3;
            Jersey+=mang[i].change;
            if(max < Jersey && curr!=past) count++;
        }
    }
    printf("%d",count);
}