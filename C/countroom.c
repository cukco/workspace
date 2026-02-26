#include <stdio.h>

int visited[1000][1000];
char c[1000][1000];
int n, m;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (c[i][j] == '#' || visited[i][j]) return;
    visited[i][j] = 1;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}
int main() {
    scanf("%d %d", &n, &m);
    getchar(); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &c[i][j]);
        }
        getchar();
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.' && !visited[i][j]) {
                sum++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
