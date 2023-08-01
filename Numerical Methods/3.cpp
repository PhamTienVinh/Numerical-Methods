#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
const int N = 2;
int main() {
	double M;
	double y1, y2;
	for (double M = 1.3; M <= 4.9; M = M + 0.1)
	{
		double matrix[2][3] = { {(-2 * exp(0.75) / pow(0.25,2)) - sin(0.75), exp(0.75) / pow(0.25,2) + log(0.75) / 0.5, cos(0.75) - exp(0.75) * 2.5 / pow(0.25,2) + log(0.75) * 2.5 / 0.5}
		,{exp(1) / pow(0.25,2), -2 * exp(1) / pow(0.25,2) - sin(1), cos(1) - exp(1) * M / pow(0.25,2)} };
		for (int k = 0; k < N; k++) {
			for (int i = k + 1; i < N; i++) {
				double factor = matrix[i][k] / matrix[k][k];
				for (int j = k; j <= N; j++) {
					matrix[i][j] = matrix[i][j] - factor * matrix[k][j];
				}
			}
		}
		y2 = matrix[N - 1][N] / matrix[N - 1][N - 1];
		y1 = (matrix[0][N] - matrix[0][N - 1] * y2) / matrix[0][0];
		cout << "M=" << M << " thì y(0.75)= " << y1 << endl;
		cout << "y(1)= " << y2 << endl;
	}
}
