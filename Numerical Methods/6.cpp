#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x, double M) {
	if (x == 1) {
		return 0.8;
	}
	else if (x == 1.2)
	{
		return 0.9 * M;
	}
	else if (x == 1.4)
	{
		return 1;
	}
	else if (x == 1.6)
	{
		return 1.15;
	}
	else if (x == 1.8)
	{
		return 1.05;
	}
	else if (x == 2)
	{
		return 1.2;
	}
	else if (x == 2.2)
	{
		return 0.5 * M;
	}

}

double g(double x) {
	switch ((int)(x * 10)) {
	case 10: return 2.7;
	case 12: return 3.9;
	case 14: return 4.2;
	case 16: return 5.1;
	case 18: return 4.7;
	case 20: return 3.5;
	case 22: return 3.2;
	}
}
int main()
{
	double M;
	cout << "Nhap M: "; cin >> M;

	int n = 7;
	double x[] = { 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2 };
	double h = (x[n - 1] - x[0]) / (n - 1);
	double sum = (g(x[0]) - f(x[0], M)) + (g(x[n - 1]) - f(x[n - 1], M));
	for (int i = 2; i < n - 1; i += 2) {
		sum += 2 * (g(x[i]) - f(x[i], M));
	}
	for (int i = 1; i < n - 1; i += 2) {
		sum += 4 * (g(x[i]) - f(x[i], M));
	}
	double area = h / 3 * sum;

	cout << "Dien tich mieng phang giua hai do thi la: " << area << endl;
	cout << "làm tròn: " << setprecision(4) << fixed << area << endl;

	return 0;
}
