#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    float location[n][2];
    for(int i=0;i<n;i++){
        scanf("%f %f",&location[i][0],&location[i][1]);
    }
    while(m--){
        float xup,yup,xdown,ydown;
        int sum=0;
        scanf("%f %f %f %f",&xup,&yup,&xdown,&ydown);
        for(int i=0;i<n;i++){
            if(location[i][0]>xup && location[i][0]<xdown && location[i][1]>ydown && location[i][1]<yup){
                sum++;
            }
        } 
        printf("%d\n",sum);
    }
}
