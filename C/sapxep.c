#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sinhvien{
    int id;
    char email[21];
};
typedef struct sinhvien sv;
int compareid(const void *a,const void *b){
    const sv *sv1=(const sv *)a;
    const sv *sv2=(const sv *)b;
    return (sv2->id-sv1->id);
}
int main(){
    int n;
    scanf("%d",&n);
    sv ds[n];
    for(int i=0;i<n;i++){
        scanf("%d",&ds[i].id);
        scanf(" %s",ds[i].email);
    }
    qsort(ds,n,sizeof(sv),compareid);
    for(int i=0;i<n;i++){
        printf("%d %s\n",ds[i].id,ds[i].email);
    }
}