#include <stdio.h>

int visited[20];
int min = 1000000000;
int cur = 0;

void check(int a[20][20], int n, int start, int step) {
    if (step == n) {
        cur += a[start][0]; 
        if (cur < min) min = cur;
        cur -= a[start][0]; 
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0) continue;
        cur += a[start][i];
        visited[i] = 1;
        check(a, n, i, step + 1);
        visited[i] = 0;
        cur -= a[start][i]; 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[0] = 1;
    check(a, n, 0, 1);

    printf("%d\n", min);
    return 0;
}
