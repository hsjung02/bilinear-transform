// MathLibrary.h
#pragma once
#include<stdlib.h>
#include<stdint.h>

static double fact(int n);
static double comb(int i, int j);
static double fastpow(double base, int n);
//분모 차수, 분자 차수, 분모 계수, 분자 계수, 샘플링 주기, 결과 저장할 이차원 배열
void blt(int m, int n, double *a, double *b, double T, double** ret);