#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct huffman{
    char c;
    int freq;
    struct huffman *left;
    struct huffman *right;
};
typedef struct huffman* huffman;
huffman makenode(char a,int b){
    huffman tmp=(huffman)malloc(sizeof(struct huffman));
    tmp->c=a;
    tmp->freq=b;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
int compare(void const *a,void const *b){
    huffman kytu1=*(huffman*)a;
    huffman kytu2=*(huffman*)b;
    return (kytu2->freq - kytu1->freq);
}
int bit=0;
void preorder(huffman root,int currdepth) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        bit+=currdepth*(root->freq);
        return;
    }
    preorder(root->left,currdepth+1);
    preorder(root->right,currdepth+1);
}
int main(){
    char chuoi[1000];
    fgets(chuoi,sizeof(chuoi),stdin);
    chuoi[strcspn(chuoi,"\n")]='\0';
    int countfreq[256]={0};
    for(int i=0;i<strlen(chuoi);i++){
        countfreq[(int)chuoi[i]]++;
    }
    int countnode=0;
    for(int i=0;i<256;i++){
        if(countfreq[i]!=0) countnode++;
    }
    int tmp=0;
    huffman arr[countnode];
    for(int i=0;i<256;i++){
        if(countfreq[i]!=0){
            arr[tmp]=makenode((char)i,countfreq[i]);
            tmp++;
        }
    }
    while(countnode>1){
        qsort(arr,countnode,sizeof(huffman),compare);
        huffman left=arr[countnode-1];
        huffman right=arr[countnode-2];
        huffman parent=makenode('@',left->freq+right->freq);
        parent->left=left;
        parent->right=right;
        arr[countnode-2]=parent;
        countnode--;
    }
    huffman root=arr[0];
    preorder(root,0);
    printf("%d",bit);
}