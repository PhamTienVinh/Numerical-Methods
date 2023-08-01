#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double f(double x, float M) {
	if (x == 1) {
		return 0.25 * (1 + sin(x));
	}
	else if (x == 1.4)
	{
		return 2.31 * (1 + sin(x));
	}
	else if (x == 1.6)
	{
		return 1.12 * (1 + sin(x));
	}
	else if (x == 1.8)
	{
		return M * (1 + sin(x));
	}
	else if (x == 2)
	{
		return 2.14 * (1 + sin(x));
	}
	else if (x == 2.2)
	{
		return 4.45 * (1 + sin(x));
	}

}

int main()
{
	double a;
	float M;
	int n = 6;
	double x[] = { 1, 1.4, 1.6, 1.8, 2, 2.2 };
	double h = 0.2;
	for (float M = 1.3; M <= 4.9; M = M + 0.1)
	{
		double sum = f(x[0], M) + f(x[n - 1], M);
		for (int i = 1; i < n - 1; i = i + 1) {
			sum += 2 * f(x[i], M);
		}
		double area = h / 2 * sum;
		a = (5.2 - area) / (1 + sin(1.2));
		cout << "diện tích khi M= " << setprecision(2) << fixed << M << " là: S=";
		cout << setprecision(10) << fixed << area << endl;
		cout << "a= " << setprecision(10) << fixed << a << endl;
	}
	return 0;
}
