#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_SHOP 200003
#define SIZE_CUS 1007
#define MAX_ORDERS 100005
typedef struct CustomerNode {
    char idcust[11];
    long long consume;
    struct CustomerNode *next;
} CustomerNode;
typedef struct ShopNode {
    char idshop[11];
    long long revenue;
    CustomerNode *khach[SIZE_CUS];
    struct ShopNode *next;
} ShopNode;
typedef struct {
    int second;
    int price;
} Transaction;
ShopNode *shopTable[SIZE_SHOP];
Transaction orderList[MAX_ORDERS];
long long prefixSum[MAX_ORDERS];
int total_orders = 0;
long long total_revenue = 0;
unsigned int hash(char *s, int size) {
    unsigned int h = 0;
    while (*s) h = h * 31 + (*s++);
    return h % size;
}
int timeToSeconds(char *t) {
    int h, m, s;
    sscanf(t, "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}
ShopNode* getShop(char *sid) {
    unsigned int h = hash(sid, SIZE_SHOP);
    ShopNode *p = shopTable[h];
    while (p) {
        if (strcmp(p->idshop, sid) == 0) return p;
        p = p->next;
    }
    ShopNode *newNode = (ShopNode*)malloc(sizeof(ShopNode));
    strcpy(newNode->idshop, sid);
    newNode->revenue = 0;
    for (int i = 0; i < SIZE_CUS; i++) newNode->khach[i] = NULL;
    newNode->next = shopTable[h];
    shopTable[h] = newNode;
    return newNode;
}
CustomerNode* getCustomerInShop(ShopNode *s, char *cid) {
    unsigned int h = hash(cid, SIZE_CUS);
    CustomerNode *p = s->khach[h];
    while (p) {
        if (strcmp(p->idcust, cid) == 0) return p;
        p = p->next;
    }
    CustomerNode *newNode = (CustomerNode*)malloc(sizeof(CustomerNode));
    strcpy(newNode->idcust, cid);
    newNode->consume = 0;
    newNode->next = s->khach[h];
    s->khach[h] = newNode;
    return newNode;
}

int compareTime(const void *a, const void *b) {
    return ((Transaction*)a)->second - ((Transaction*)b)->second;
}
int findLower(int key) {
    int low = 0, high = total_orders - 1, ans = total_orders;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (orderList[mid].second >= key) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return ans;
}
int findUpper(int key) {
    int low = 0, high = total_orders - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (orderList[mid].second <= key) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    return ans;
}

int main() {
    char cid[11], pid[11], sid[11], time_str[10];
    int price;
    while (scanf("%s", cid) && cid[0] != '#') {
        scanf("%s %d %s %s", pid, &price, sid, time_str);
        total_revenue += price;
        orderList[total_orders].second = timeToSeconds(time_str);
        orderList[total_orders].price = price;
        total_orders++;
        ShopNode *s = getShop(sid);
        s->revenue += price;
        CustomerNode *c = getCustomerInShop(s, cid);
        c->consume += price;
    }
    if (total_orders > 0) {
        qsort(orderList, total_orders, sizeof(Transaction), compareTime);
        prefixSum[0] = orderList[0].price;
        for (int i = 1; i < total_orders; i++)
            prefixSum[i] = prefixSum[i - 1] + orderList[i].price;
    }
    char cmd[50];
    while (scanf("%s", cmd) && cmd[0] != '#') {
        if (strcmp(cmd, "?total_number_orders") == 0) {
            printf("%d\n", total_orders);
        } else if (strcmp(cmd, "?total_revenue") == 0) {
            printf("%lld\n", total_revenue);
        } else if (strcmp(cmd, "?revenue_of_shop") == 0) {
            scanf("%s", sid);
            ShopNode *s = getShop(sid);
            unsigned int h = hash(sid, SIZE_SHOP);
            ShopNode *p = shopTable[h];
            long long res = 0;
            while(p){ 
                if(strcmp(p->idshop, sid) == 0) { 
                    res = p->revenue; 
                    break; 
                } 
                p = p->next; 
            }
            printf("%lld\n", res);
        } else if (strcmp(cmd, "?total_consume_of_customer_shop") == 0) {
            scanf("%s %s", cid, sid);
            unsigned int h = hash(sid, SIZE_SHOP);
            ShopNode *ps = shopTable[h];
            long long res = 0;
            while(ps) {
                if(strcmp(ps->idshop, sid) == 0) {
                    unsigned int hc = hash(cid, SIZE_CUS);
                    CustomerNode *pc = ps->khach[hc];
                    while(pc){ 
                        if(strcmp(pc->idcust, cid) == 0){ 
                            res = pc->consume; break; 
                        } 
                        pc = pc->next; 
                    }
                    break;
                }
                ps = ps->next;
            }
            printf("%lld\n", res);
        } else if (strcmp(cmd, "?total_revenue_in_period") == 0) {
            char t1_s[10], t2_s[10];
            scanf("%s %s", t1_s, t2_s);
            int start_idx = findLower(timeToSeconds(t1_s));
            int end_idx = findUpper(timeToSeconds(t2_s));
            if (start_idx <= end_idx && start_idx < total_orders) {
                printf("%lld\n", prefixSum[end_idx] - (start_idx > 0 ? prefixSum[start_idx - 1] : 0));
            } else printf("0\n");
        }
    }
    return 0;
}