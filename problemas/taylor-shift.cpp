// Um polinômio f(x) = a0 x^0 + a1 x^1 + ... + a_{N-1} x^{N-1} e um inteiro c é dado. Compute uma sequência b0, b1, ... , b_{N-1} satisfazendo f(x + c) = b0 + b1 x^1 + ... + x_{N-1}x^{N-1}, imprima cada elemento modulo 998244353.
// https://judge.yosupo.jp/problem/polynomial_taylor_shift

vector<mint> taylor_shift(vector<mint> &a, int c){
    int n = a.size();
    vector<mint> fat(n);
    fat[0] = 1;
    for (int i=1; i < n; i++){
        fat[i] = fat[i - 1] * i;
    }
    vector<mint> A(n), B(n);
    for (int i=0; i < n; i++){
        A[i] = a[i] * fat[i];
        B[i] = expbin(c, i) / fat[i];
    }
    reverse(all(A));
    auto retval = convolution(A, B);
    vector<mint> C(n);
    for (int i=0; i < n; i++){
        C[i] = retval[n - i - 1] / fat[i];
    }
    return C;
}
