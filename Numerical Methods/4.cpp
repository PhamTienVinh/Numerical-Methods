﻿#include <iostream>
#include <stdio.h>
#include <math.h>
#define eps 0.0001
using namespace std;
double tinh_ham(double M, double h)
{
	return 3.14 / 3 * h * h * (3 * M - h) - 5.4 * M;
}
double tinh_dao_ham(double M, double h)
{
	return 3.14 / 3 * (6 * M * h - 3 * h * h);
}
double tinh_dao_ham_2(double M, double h)
{
	return 3.14 / 3 * (6 * M - 6 * h);
}
int main()
{
	double M, y;
	double h = 2;
	printf_s("Nhập Mã sô M của bạn: \n");
	scanf_s("%lf", &M);
	for (int i = 0; i < 2; i++)
	{
		y = h;
		double t = tinh_ham(M, y) / tinh_dao_ham(M, y);
		h = y - t;
	}
	printf_s("nghiệm của pt lần lặp thứ 2 là : %.4lf", h);
	double saiso = tinh_ham(M, h) / (3.14 / 3 * (6 * M * 0.5 - 3 * pow(0.5, 2)));
	double lamtronlen = ceil(saiso * pow(10, 4)) / pow(10, 4);
	printf_s("\nsai số là: %.4lf", saiso);
	printf_s("\nsai số đã làm tròn lên là: %.4lf", lamtronlen);
}