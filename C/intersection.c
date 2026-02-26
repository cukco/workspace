#include<stdio.h>
#include<stdlib.h>
struct ds{
    int first;
    int last;
};
typedef struct ds ds;
ds array[1000000];
int compare(const void *a,const void *b){
    ds *so1=(ds *)a;
    ds *so2=(ds *)b;
    return ( so1->first - so2->first );
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&array[i].first,&array[i].last);
    }
    qsort(array,n,sizeof(ds),compare);
    for(int i=0;i<n-1;i++){
        if(array[i].last >= array[i+1].first && array[i].last<=array[i+1].last){
            printf("TRUE");
            return 0;
        }
    }
    printf("FALSE");
}