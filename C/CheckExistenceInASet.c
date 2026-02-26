#include<stdio.h>
#include<stdlib.h>
struct data{
    int key;
    int index;
    int check;
};
typedef struct data data;
int comparekey(const void *a,const void *b){
    data *so1=(data *)a;
    data *so2=(data *)b;
    return ( so1->key - so2->key);
}
int compareindex(const void *a,const void *b){
    data *so1=(data *)a;
    data *so2=(data *)b;
    return ( so1->index - so2->index);
}
int main(){
    int n;
    scanf("%d",&n);
    data arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].key);
        arr[i].index=i;
        arr[i].check=0;
    }
    qsort(arr,n,sizeof(data),comparekey);
    for(int i=1;i<n;i++){
        if(arr[i].key==arr[i-1].key){
            arr[i].check=1;
        }
    }
    qsort(arr,n,sizeof(data),compareindex);
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i].check);
    }

}