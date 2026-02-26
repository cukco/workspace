#include<stdio.h>
#include<string.h>
struct sv{
    char id[8];
    int grade;
    int rank;
};
typedef struct sv sv;
int main(){
    int n;
    scanf("%d",&n);
    sv ds[1000];
    for(int i=0;i<n;i++){
        char str[10];
        scanf("%s",str);
        int index=str[6]-'0';
        ds[index].rank=index;
        strcpy(ds[index].id,str);
        scanf("%d",&ds[index].grade);
    }
    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i <n ; i++) {
            for(int j=i;j<=n;j++){
                if (ds[i].grade > ds[j].grade && ds[i].rank < ds[j].rank) {
                int temp = ds[i].rank;
                ds[i].rank= ds[j].rank;
                ds[j].rank= temp;
                swapped = 1;
                }else if (ds[i].grade < ds[j].grade && ds[i].rank > ds[j].rank) {
                int temp = ds[i].rank;
                ds[i].rank= ds[j].rank;
                ds[j].rank= temp;
                swapped = 1;
            }
            }
        }
    } while (swapped);
    for(int i=1;i<=n;i++){
        printf("%s %d\n",ds[i].id,ds[i].rank-1);
    }
}