#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;
const int N = 3;
int main() {
	double M;
	cout << "Nhập M= ";
	cin >> M;
	double y1, y2, y3;
	double matrix[3][4] = { {-2 * (M + 0.75) / pow(0.25,2) - 2 * pow(0.75,2),(M + 0.75) / pow(0.25,2) + log(0.75) / 0.5,0,-2.5 * ((M + 0.75) / pow(0.25,2) - log(0.75) / 0.5) + pow(0.75,2) * (0.75 - 1)},
		{(M + 1) / pow(0.25,2) - log(1) / 0.5,-2 * (M + 1) / pow(0.25,2) - 2 * pow(1,2),(M + 1) / pow(0.25,2) + log(1) / 0.5,pow(1,2) * (1 - 1)},
		{0,(M + 1.25) / pow(0.25,2) - log(1.25) / 0.5,-2 * (M + 1.25) / pow(0.25,2) - 2 * pow(1.25,2),M * (-log(1.25) / 0.5 - (M + 1.25) / pow(0.25,2)) + 1.25 * (1.25 - 1)} };
	for (int k = 0; k < N; k++) {
		for (int i = k + 1; i < N; i++) {
			double factor = matrix[i][k] / matrix[k][k];
			for (int j = k; j <= N; j++) {
				matrix[i][j] = matrix[i][j] - factor * matrix[k][j];
			}
		}
	}
	y3 = matrix[N - 1][N] / matrix[N - 1][N - 1];
	y2 = (matrix[1][N] - matrix[1][2] * y3) / matrix[1][1];
	y1 = (matrix[0][N] - matrix[0][1] * y2 - matrix[0][2] * y3) / matrix[0][0];
	cout << "y(0.75)+y(1)+y(1.25)= " << y1 + y2 + y3 << endl;
	cout << " đáp số là : " << setprecision(4) << fixed << y1 + y2 + y3;
}
