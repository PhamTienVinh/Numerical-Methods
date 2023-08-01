#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
double tinh_ham(double M, double t)
{
	double g = 9.8, k = 0.21;
	return sqrt(2 * 0.1 * M * t / k - 2 * pow(0.1 * M / k, 2) * (1 - exp(-k * t / (0.1 * M))));
}
double tinh_dao_ham(double M, double t)
{
	double g = 9.8, k = 0.21;
	return (0.1 * M / k - 0.1 * (M / k) * exp(-k * t / (0.1 * M))) / sqrt(2 * 0.1 * M * t / k - 2 * pow(0.1 * M / k, 2) * (1 - exp(-k * t / (0.1 * M))));
}
int main()
{
	double M, y1, y2;
	double g = 9.8;
	for (double M = 1.3; M <= 4.9; M = M + 0.1)
	{
		double t1 = sqrt(10 * M / g);
		double t2 = sqrt(10 * M / g);
		double t3 = sqrt(10 * M / g);
		for (int i = 0; i < 3; i++)
		{
			y1 = t3;
			t3 = tinh_ham(M, y1);
		}
		for (int i = 0; i < 1; i++)
		{
			y2 = t1;
			t1 = tinh_ham(M, y2);
		}
		double a = sqrt(10 * M / g) - 0.5;
		double b = sqrt(10 * M / g) + 0.5;
		double c1 = tinh_dao_ham(M, a);
		double c2 = tinh_dao_ham(M, b);
		double c3 = tinh_dao_ham(M, sqrt(10 * M / g));
		double max = c3;
		if (c1 > max)
		{
			max = c1;
		}
		if (c2 > max)
		{
			max = c2;
		}
		cout << "M= " << setprecision(1) << fixed << M << endl;
		cout << "nghiệm t3= " << setprecision(6) << fixed << t3 << endl;
		double saiso = pow(max, 3) * abs(t1 - sqrt(10 * M / g)) / (1 - max);
		double saisolamtron = ceil(pow(max, 3) * abs(t1 - sqrt(10 * M / g)) * 10000 / (1 - max)) / 10000;
		cout << "△t3= " << setprecision(4) << fixed << saisolamtron << endl;
	}
}