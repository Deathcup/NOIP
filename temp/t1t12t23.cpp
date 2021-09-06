#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 103, MOD = 1e9 + 7;
struct Matrix {
    int n, mtx[N][N];
    Matrix() { n = 0, memset(mtx, 0, sizeof mtx); }
    Matrix operator*(const Matrix &b) const;
};
Matrix b, E;
int n;
long long k;

Matrix qpow(Matrix b, long long b);
void write(Matrix &res);

int main()
{
    cin >> n >> k;
    b.n = n;
    for (int i = 1; i <= b.n; ++i)
        for (int j = 1; j <= b.n; ++j)
            cin >> b.mtx[i][j];
    E.n = n;
    for (int i = 1; i <= E.n; ++i)
        for (int j = 1; j <= E.n; ++j)
            E.mtx[i][j] = (i == j ? 1 : 0);
    Matrix ans = qpow(b, k);
    write(ans);

    return 0;
}

Matrix Matrix::operator*(const Matrix &b) const
{
    Matrix c;
    c.n = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                c.mtx[i][j] = (c.mtx[i][j] + (long long)mtx[i][k] * b.mtx[k][j] % MOD) % MOD;
    return c;
}

Matrix qpow(Matrix b, long long b)
{
    Matrix ans = E;
    while (b > 0) {
        if (b & 1) ans = ans * b;
        b = b * b;
        b >>= 1;
    }
    return ans;
}

void write(Matrix &res)
{
    for (int i = 1; i <= res.n; ++i) {
        for (int j = 1; j <= res.n; ++j)
            cout << res.mtx[i][j] << " ";
        cout << "\n";
    }
}
