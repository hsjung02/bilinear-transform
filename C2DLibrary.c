// MathLibrary.cpp
// compile with: cl /c /EHsc MathLibrary.cpp
// post-build command: lib MathLibrary.obj

#include "C2DLibrary.h"


double fact(int n){
    if (n == 0 || n == 1)return 1;
    return n * fact(n - 1);
}

double comb(int i, int j){
    return fact(i) / fact(i - j) / fact(j);
}

double fastpow(double base, int n) {
    if (base == -1) {
        if (n % 2 == 0)return 1;
        return -1;
    }
    if (n == 0)return 1;
    if (n == 1)return base;
    else {
        double k = fastpow(base, n / 2);
        double tmp = k * k;
        if (n % 2 == 0)return tmp;
        else return base * tmp;
    }
}

//분모 차수, 분자 차수, 분모 계수, 분자 계수, 샘플링 주기, 결과 저장할 이차원 배열
void blt(int m, int n, double *a, double *b, double T, double** ret){

    double K = 2 / T;
    double *c;
    int8_t sz = m;
    c = (double*)malloc((int64_t)sizeof(double) * (int64_t)(m + 1));
    double *d;
    d = (double*)malloc((int64_t)sizeof(double) * (int64_t)(n + 1));
 
    
    for (int t = 0; t <= n; t++) {
        double tm = 0;
        for (int i = 0; i <= n; i++) {
            double tmp = 0;
            for (int j = 0; j <= t; j++) {
                if (n - i < t - j)continue;
                if (i < j)continue;
                tmp += comb(i, j) * fastpow(-1, i - j) * comb(n - i, n - i - t + j);
            }
            tmp *= b[i] * fastpow(K,i);
            tm += tmp;
        }
        d[t] = tm;
    }

    for (int t = 0; t <= m; t++) {
        double tm = 0;
        for (int i = 0; i <= m; i++) {
            double tmp = 0;
            for (int j = 0; j <= t; j++) {
                if (n - i < t - j)continue;
                if (i < j)continue;
                tmp += comb(i, j) * fastpow(-1, i - j) * comb(n - i, n - i - t + j);
            }
            tmp *= a[i] * fastpow(K, i);
            tm += tmp;
        }
        c[t] = tm;
    }
    double *dnew;
    dnew = (double*)malloc((int64_t)sizeof(double) * (int64_t)(m + 1));
    for (int i = 0; i <= m; i++) {
        double tmp = 0;
        for (int j = 0; j <= i; j++) {
            if (m - n < i - j)continue;
            tmp += d[j] * comb(m - n, i - j);
        }
        dnew[i] = tmp;
    }


    for (int i = 0; i <= m; i++)ret[0][i] = dnew[m - i];
    for (int i = 0; i <= m; i++)ret[1][i] = c[m - i];

    free(c);
    free(d);


}