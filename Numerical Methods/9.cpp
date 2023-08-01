#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double M, b0, d0, c1, d1;

	cout << "Nhap vao gia tri cua M: ";
	cin >> M;
	d0 = (3 * (M - 1) - M) / (2 * pow(M - 1, 3));
	b0 = 3 - 3 * (3 * (M - 1) - M) / (2 * pow(M - 1, 3)) * pow(M - 1, 2);
	c1 = 3 * (3 * (M - 1) - M) * (M - 1) / (2 * pow(M - 1, 3));
	d1 = -1 * 3 * ((3 * (M - 1) - M) * (M - 1)) / (9 * (2 * pow(M - 1, 3)));
	cout << d0 << endl;
	cout << b0 << endl;
	cout << c1 << endl;
	cout << d1 << endl;
	cout << "tổng d0+b0+c1+d1 là: " << d0 + b0 + c1 + d1 << endl;
	cout << " kết quả sau khi làm tròn:" << setprecision(4) << fixed << d0 + b0 + c1 + d1;

}

