#include <stdio.h>
#include "traverse.h"
#include "lstack.h"

static int *value;
static int *left;
static int *middle;
static int *right;

void SetBT(int *V, int *L, int *R) {
    value = V;
    left = L;
    right = R;
}

void SetTT(int *V, int *L, int *M, int *R) {
    value = V;
    left = L;
    middle = M;
    right = R;
}

void inorder(int root) {
    if (left[root] != 0)inorder(left[root]);
    printf("%d ", value[root]);
    if (right[root] != 0)inorder(right[root]);
}

void preorder(int root) {
    printf("%d ", value[root]);
    if (left[root] != 0)preorder(left[root]);
    if (right[root] != 0)preorder(right[root]);
}

void postorder(int root) {
    if (left[root] != 0)postorder(left[root]);
    if (right[root] != 0)postorder(right[root]);
    printf("%d ", value[root]);
}

// принцип очереди
void levelorder(int root) {
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", value[current]);

        if (left[current] != 0) {
            queue[rear++] = left[current];
        }
        if (right[current] != 0) {
            queue[rear++] = right[current];
        }
    }
}

void inorderNR(int v) {
    LStack S;
    S = CreateStack();
    LT:
    while (left[v] != 0) {
        Push(v, S);
        v = left[v];
    }
    NODE:
    printf("%d ", value[v]);
    if (right[v] != 0) {
        v = right[v];
        goto LT;
    }
    if (!IsEmptyStack(S)) {
        v = Top(S);
        Pop(S);
        goto NODE;
    }
    RemoveStack(&S);
}

// принцип стека
void preorderNR(int v) {
    LStack S = CreateStack();
    Push(v, S);

    while (!IsEmptyStack(S)) {
        int current = Top(S);
        Pop(S);

        printf("%d ", value[current]);

        if (right[current] != 0) {
            Push(right[current], S);
        }
        if (left[current] != 0) {
            Push(left[current], S);
        }
    }
    RemoveStack(&S);
}

void preorderTT(int root) {
    if (root == 0) return;

    printf("%d ", value[root]);
    preorderTT(left[root]);
    preorderTT(middle[root]);
    preorderTT(right[root]);
}

void postorderTT(int root) {
    if (root == 0) return;

    postorderTT(left[root]);
    postorderTT(middle[root]);
    postorderTT(right[root]);
    printf("%d ", value[root]);
}