#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[20];
    char time[20];
} order;

order ds[100005];
int count = 0;
int compare(const void* a, const void* b) {
    order* orderA = (order*)a;
    order* orderB = (order*)b;
    return strcmp(orderA->time, orderB->time);
}
int binary_search_first_ge(char* key) {
    int low = 0, high = count - 1;
    int ans = count; 
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(ds[mid].time, key) >= 0) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int binary_search_first_gt(char* key) {
    int low = 0, high = count - 1;
    int ans = count;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(ds[mid].time, key) > 0) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    while (1) {
        char buffer[20];
        scanf("%s", buffer);
        if (strcmp(buffer, "#") == 0) break;
        
        strcpy(ds[count].id, buffer);
        scanf("%s", ds[count].time);
        count++;
    }
    qsort(ds, count, sizeof(order), compare);
    char cmd[50];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "###") == 0) break;

        if (strcmp(cmd, "?number_orders") == 0) {
            printf("%d\n", count);
        } 
        else if (strcmp(cmd, "?number_orders_in_period") == 0) {
            char start[20], end[20];
            scanf("%s %s", start, end);
            int p1 = binary_search_first_ge(start);
            int p2 = binary_search_first_gt(end);
            printf("%d\n", p2 - p1);
        } 
        else if (strcmp(cmd, "?number_orders_at_time") == 0) {
            char target[20];
            scanf("%s", target);
            int p1 = binary_search_first_ge(target);
            int p2 = binary_search_first_gt(target);
            
            printf("%d\n", p2 - p1);
        }
    }
    return 0;
}