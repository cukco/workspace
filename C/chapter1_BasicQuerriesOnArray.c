#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    char tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%c",&tmp);
    char query[100];
    getchar();
    while (1) {
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = 0;
        if (strcmp(query, "***") == 0) break;
        if (strcmp(query, "find-max") == 0) {
            int maxv = a[0];
            for (int i = 1; i < n; i++)
                if (a[i] > maxv) maxv = a[i];
            printf("%d\n", maxv);
        } 
        else if (strcmp(query, "find-min") == 0) {
            int minv = a[0];
            for (int i = 1; i < n; i++)
                if (a[i] < minv) minv = a[i];
            printf("%d\n", minv);
        } 
        else if (strcmp(query, "sum") == 0) {
            int s = 0;
            for (int i = 0; i < n; i++) s += a[i];
            printf("%d\n", s);
        } 
        else if (strncmp(query, "find-max-segment", 16) == 0) {
            int i, j;
            sscanf(query + 16, "%d %d", &i, &j);
            int maxv = a[i-1];
            for (int k = i; k <= j; k++) {
                if (a[k-1] > maxv) maxv = a[k-1];
            }
            printf("%d\n", maxv);
        }
        else if (strncmp(query, "find-min-segment", 16) == 0) {
            int i, j;
            sscanf(query + 16, "%d %d", &i, &j);
            int minv = a[i-1];
            for (int k = i; k <= j; k++) {
                if (a[k-1] < minv) minv = a[k-1];
            }
            printf("%d\n", minv);
        }
    }
    return 0;
}
