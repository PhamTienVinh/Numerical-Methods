#include<iostream>
#include<iomanip>
using namespace std;
double tong(double M)
{
	double a = (0.125 - M / 5) / 0.25;
	double b = M / 5 - (0.5 / 0.25) * (0.125 - M / 5);
	double c = (0.75 - M / 10) / (M / 5 - 0.125);
	double d = 0.75 - M / 5 * (0.75 - M / 10) / (M / 5 - 0.125);
	return a + b + c + d;
}
int main()
{
	double a, b, c, d;
	double M;
	cout << "Nhập vào giá trị M: ";
	cin >> M;
	tong(M);
	cout << "tong a+b+c+d là: " << tong(M) << endl;
	cout << "sau khi đã làm tròn:" << setprecision(4) << fixed << tong(M);
}