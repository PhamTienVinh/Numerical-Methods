#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int N = 2;

double m1, m2, m3, m4, m5;
double A, B;

double sin2(double x) {
	return pow(sin(x), 2);
}

double sin_ln(double x) {
	return sin(x) * log(1 / x);
}

double ln2(double x) {
	return pow(log(1 / x), 2);
}

double ln_y(double x, double y) {
	return log(1 / x) * y;
}

int main() {
	double M;
	cout << "Nhap M: ";
	cin >> M;

	double x[] = { 1, 1.5, 2.0, 2.5, 3, 3.2, 3.5, 4.3, 5 };
	double y[] = { M, 5.7, 4.0, 3.5, 4, 4, 5.0, 4.5, 4 };

	m1 = m2 = m3 = m4 = m5 = 0;
	for (int i = 0; i < 9; i++) {
		m1 += sin2(x[i]);
		m2 += sin_ln(x[i]);
		m3 += sin(x[i]) * y[i];
		m4 += ln2(x[i]);
		m5 += ln_y(x[i], y[i]);
	}


	double matrix[2][3] = { {m1, m2, m3},{m2, m4, m5} };
	for (int k = 0; k < N; k++) {
		for (int i = k + 1; i < N; i++) {
			double factor = matrix[i][k] / matrix[k][k];
			for (int j = k; j <= N; j++) {
				matrix[i][j] = matrix[i][j] - factor * matrix[k][j];
			}
		}
	}

	B = matrix[N - 1][N] / matrix[N - 1][N - 1];
	A = (matrix[0][N] - matrix[0][N - 1] * B) / matrix[0][0];
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "A+B là: " << A + B << endl;
	double C = A + B;
	cout << "số đã làm tròn : " << setprecision(4) << fixed << C;
}

