#include<stdio.h>
#include<stdlib.h>
int n=81;
int X[82];
int dem=0;
int check(int v, int k) {
	for (int t = 1; t < k; t++) {
		if ((t - 1) / 9 == (k - 1) / 9 && X[t] == v) return 0;
		if ((t - k) % 9 == 0 && X[t] == v) return 0;
		int o1 = (k - 1) / 27, p1 = ((k - 1) % 9) / 3;
		int o2 = (t - 1) / 27, p2 = ((t - 1) % 9) / 3;
		if (o1 == o2 && p1 == p2 && X[t] == v) return 0;
	}
	return 1;
}
void Try(int k){
	if(k>n){
		dem++;
		return;
	}
	if(X[k]!=0){
		Try(k+1);
		return;
	}
	for (int y = 1; y <= 9; y++) {
		if (check(y, k)) {
			X[k] = y;
			Try(k + 1);
			X[k] = 0;
		}
	}
}
int main(){
	for (int i=1;i<82;i++) 
		scanf("%d",&X[i]);
	Try(1);
	printf("%d",dem);
}

 

