#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "C2DLibrary.lib")
#include<stdio.h>
#include<stdint.h>
#include "C2DLibrary.h"


int main()
{
    int n, m;
    printf("�и��� ������ �Է��ϼ���: ");
    scanf("%d", &m);
    double* a;
    a = (double*)malloc((int64_t)sizeof(double) * (int64_t)(m + 1));
    printf("�и��� ����� ����׺��� �ְ����ױ��� ������� �Է��ϼ���: ");
    for (int i = 0; i <= m; i++)scanf("%lf", a + i);
    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &n);
    double* b;
    b = (double*)malloc((int64_t)sizeof(double) * (int64_t)(n + 1));
    printf("������ ����� ����׺��� �ְ����ױ��� ������� �Է��ϼ���: ");
    for (int i = 0; i <= n; i++)scanf("%lf", b + i);
    printf("���ø� �ֱ� T�� �Է��ϼ���: ");
    double T; scanf("%lf", &T);



    double** timedomain;
    timedomain = (double**)malloc((int64_t)sizeof(double*) * (int64_t)2);
    timedomain[0] = (double*)malloc((int64_t)sizeof(double) * (int64_t)(m + 1));
    timedomain[1] = (double*)malloc((int64_t)sizeof(double) * (int64_t)(m + 1));
    blt(m, n, a, b, T, timedomain);


    printf("\nTime Domain Difference Equation\n\n");
    printf("����(�ְ����׺���): ");
    for (int i = 0; i <= m; i++)printf("%f  ", timedomain[0][i]);
    printf("\n");
    printf("�и�(�ְ����׺���): ");
    for (int i = 0; i <= m; i++)printf("%f  ", timedomain[1][i]);
    printf("\n\n");
    
    free(a);
    free(b);
    free(timedomain[0]);
    free(timedomain[1]);
    free(timedomain);

    return 0;

}