#include<stdio.h>
#include<string.h>
typedef struct
{ 
 char mssv[8];  
 char name[31]; 
 int grade;
 char classement;	 
} student;
int main(){
    student ds[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&ds[i].mssv);
        getchar();
        fgets(ds[i].name,sizeof(ds[i].name),stdin);
        ds[i].name[strcspn(ds[i].name,"\n")]='\0';
        scanf("%d",&ds[i].grade);
        getchar();
        if(ds[i].grade>=9 && ds[i].grade<=10){
            ds[i].classement='A';
        }else if(ds[i].grade>=8 && ds[i].grade<9){
            ds[i].classement='B';
        }else if(ds[i].grade>=6 && ds[i].grade<8){
             ds[i].classement='C';
        }else{
            ds[i].classement='D';
        }
    }
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (ds[i].grade < ds[i + 1].grade) {
                student temp = ds[i];
                ds[i] = ds[i + 1];
                ds[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
    for(int i=0;i<n;i++){
        printf("%c||%s||%s||%d\n",ds[i].classement,ds[i].mssv,ds[i].name,ds[i].grade);
    }
}