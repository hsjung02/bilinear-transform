// MathLibrary.h
#pragma once
#include<stdlib.h>
#include<stdint.h>

static double fact(int n);
static double comb(int i, int j);
static double fastpow(double base, int n);
//�и� ����, ���� ����, �и� ���, ���� ���, ���ø� �ֱ�, ��� ������ ������ �迭
void blt(int m, int n, double *a, double *b, double T, double** ret);