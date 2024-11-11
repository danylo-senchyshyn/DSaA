#include "binkoef.h"

int BinKoefDnC(int n, int k) {
    if (k == 0 || k == n)return 1;
    else return BinKoefDnC(n - 1, k - 1) + BinKoefDnC(n - 1, k);
}

int BinKoefDP(int n, int k) {
    int bk[n + 1][n + 1];
    int i, j;
    bk[0][0] = 1;
    for (i = 1; i <= n; i++) {
        bk[i][0] = 1;
        bk[i][i] = 1;
        for (j = 1; j < i; j++) {
            bk[i][j] = bk[i - 1][j - 1] + bk[i - 1][j];
        }
    }
    return bk[n][k];
}
