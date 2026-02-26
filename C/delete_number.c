#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int K;
struct Node {
    int so;
    struct Node* next;
};
typedef struct Node* node;
node makenode(int x) {
    node tmp = (node)malloc(sizeof(struct Node));
    tmp->so = x;
    tmp->next = NULL;
    return tmp;
}
void addlast(node *a, int b) {
    node tmp = makenode(b);
    if (*a == NULL) {
        *a = tmp;
    } else {
        node p = *a;
        while (p->next != NULL)
            p = p->next;
        p->next = tmp;
    }
}
void pop(node *a) {
    if (*a == NULL) return;
    node p = *a, prev = NULL;
    if (p->next == NULL) {
        free(p);
        *a = NULL;
        return;
    }
    while (p->next != NULL) {
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    free(p);
}
int laycuoi(node a) {
    if (a == NULL) return -1;
    while (a->next != NULL)
        a = a->next;
    return a->so;
}
void inra(node a) {
    if (a == NULL) {
        printf("0");
        return;
    }
    while (a != NULL) {
        printf("%d", a->so);
        a = a->next;
    }
    printf("\n");
}
int main() {
    node head = NULL;
    char *x = (char*)malloc(120000 * sizeof(char));
    scanf("%s", x);
    scanf("%d", &K);
    int n = strlen(x);
    for (int i = 0; i < n; i++) {
        int digit = x[i] - '0';
        while (head != NULL && laycuoi(head) > digit && K > 0) {
            pop(&head);
            K--;
        }
        addlast(&head, digit);
    }

    while (K > 0 && head != NULL) {
        pop(&head);
        K--;
    }
    inra(head);
    free(x);
    return 0;
}
