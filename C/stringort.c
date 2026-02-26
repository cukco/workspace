#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char **ds = (char **)malloc(n * sizeof(char *));
    char buffer[10001];
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        int len = strlen(buffer);
        ds[i] = (char *)malloc((len + 1) * sizeof(char));
        strcpy(ds[i], buffer);
    }

    qsort(ds, n, sizeof(char *), compare);
    for (int i = 0; i < n; i++) {
        printf("%s\n", ds[i]);
    }
    for (int i = 0; i < n; i++) {
        free(ds[i]); 
    }
    free(ds); 
    return 0;
}