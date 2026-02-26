#include<stdio.h>
#include<stdlib.h>
int n,m;
struct vector{
    int a[10];
};
typedef struct vector vector;
int compare(const void *a,const void *b){
    const vector *vt1=(const vector *)a;
    const vector *vt2=(const vector *)b;
    int i=0;
    while(1){
        if(vt1->a[i]==vt2->a[i]){
            i++;
            continue;
        }else{
            return (vt1->a[i] - vt2->a[i]);
        }
    }

}
int main(){
    scanf("%d %d",&n,&m);
    vector ds[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&ds[i].a[j]);
        }
    }
    qsort(ds,n,sizeof(vector),compare);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",ds[i].a[j]);
        }
        printf("\n");
    }


}