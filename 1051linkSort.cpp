/*
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include<cstdlib>

// ********** Definition of the structure **********
typedef struct Node {
    char value[100]; // 以字符串形式存贮的分数
    struct Node* next;
} NODE;

// 提取分子和分母
void getNumeratorAndDenominator(const char* str, int& numerator, int& denominator) {
    char temp[100];
    strcpy(temp, str);
    char* slash = strchr(temp, '/');
    if (slash == NULL) {
        numerator = atoi(temp);
        denominator = 1;
    }
    else {
        *slash = '\0';
        numerator = atoi(temp);
        denominator = atoi(slash + 1);
    }
}

// 比较两个分数的大小
bool compareFractions(const char* a, const char* b) {
    int num1, den1, num2, den2;
    getNumeratorAndDenominator(a, num1, den1);
    getNumeratorAndDenominator(b, num2, den2);

    // 通分比较
    long long val1 = (long long)num1 * den2;
    long long val2 = (long long)num2 * den1;

    if (val1 != val2) {
        return val1 < val2;
    }
    return num1 < num2;
}

// 交换两个节点的值
void swapNodes(NODE* a, NODE* b) {
    char temp[100];
    strcpy(temp, a->value);
    strcpy(a->value, b->value);
    strcpy(b->value, temp);
}

//****** Specification of SortRationalList ******
NODE* SortRationalList(NODE* h) {
    if (h == nullptr || h->next == nullptr) return h;

    int swapped;
    Node* ptr1;
    Node* ptr2 = nullptr;

    do {
        swapped = 0;
        ptr1 = h;

        while (ptr1->next != ptr2) {
            if (compareFractions(ptr1->next->value, ptr1->value)) {
                swapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
                ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
    return h;
}
*/
/***************************************************************/
/*                                                             */
/*  DON'T MODIFY following code anyway!                        */
/*                                                             */
/***************************************************************/
/*
static unsigned long next = 1;

int RND() {
    next = next * 1103515245 + 12345;
    return (unsigned)(next / 65536) % 32768;
}

void SETSEED(unsigned seed) { next = seed; }

void GENNUMBER(char* p, int len, int x) {
    int v;
    do v = RND() % 10; while (v == 0);
    if (x && RND() % 10) *p++ = '-';
    while (len--) {
        *p++ = v + '0';
        v = RND() % 10;
    }
    *p = 0;
}

void GENRATIONAL(char* p, int s) {
    int sign = RND() % 4, len1 = RND() % 8 + 1, len2 = RND() % 8 + 1;
    char s2[10];
    GENNUMBER(p, len1, 1);
    GENNUMBER(s2, len2, 0);
    if (sign && s2[0] - '1' && s2[1]) strcat(p, "/"), strcat(p, s2);
}

void solve() {
    int i, s;
    NODE* h = 0, * p;
    scanf("%d", &s);
    if (s < 10)
        for (i = 0; i < s; i++) {
            p = (NODE*)malloc(sizeof(NODE));
            scanf("%s", p->value);
            p->next = h;
            h = p;
        }
    else
        for (SETSEED(s <<= 1), i = 0; i < s; i++) {
            p = (NODE*)malloc(sizeof(NODE));
            GENRATIONAL(p->value, s);
            p->next = h;
            h = p;
        }
    h = SortRationalList(h);
    while (h) {
        p = h;
        h = h->next;
        printf(" %s", p->value);
        free(p);
    }
    printf("\n");
}

int main() {
    int i, t;
    scanf("%d\n", &t);
    for (i = 0; i < t; i++) {
        printf("case #%d:\n", i);
        solve();
    }
    return 0;
}
*/