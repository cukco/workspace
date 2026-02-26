#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sv{
    char id[20];
    int score;
};
typedef struct sv sv;
int compare(const void *a,const void *b){
    const sv *sv1=(const sv *)a;
    const sv *sv2=(const sv *)b;
    return (sv2->score - sv1->score);
}
sv ds[100000];
int main(){
    int n=0;
    char buff[20];
    while(1){
        scanf(" %s",buff);
        if(strcmp(buff,"#")==0) break;
        else{
            strcpy(ds[n].id,buff);
            int k;
            scanf("%d",&k);
            ds[n].score=k;
            n++;
        }
    }
    qsort(ds,n,sizeof(sv),compare);
    for(int i=0;i<n;i++){
        printf("%s %d\n",ds[i].id,ds[i].score);
    }
}