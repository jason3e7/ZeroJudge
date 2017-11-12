 /*
  * @file a451.c
  * @author Jason3e7
  * @algorithm matrix, fast power, bigint
  * @date 201711131029
  */ 
 
#include <stdio.h>

int matrixFastPowxer(int n, int m) {
	n--;
	unsigned long long int base[2][2] = {{1, 1}, {1, 0}}, r[2][2], temp[2][2]; 
	int firstFlag = 1;
	while(n != 0) {
		if(n % 2 == 1) {
			if(firstFlag == 1) {
				r[0][0] = base[0][0];
				r[0][1] = base[0][1];
				r[1][0] = base[1][0];
				r[1][1] = base[1][1];
				firstFlag = 0;
			} else {
				temp[0][0] = r[0][0] * base[0][0] + r[0][1] * base[1][0];
				temp[0][1] = r[0][0] * base[0][1] + r[0][1] * base[1][1];
				temp[1][0] = r[1][0] * base[0][0] + r[1][1] * base[1][0];
				temp[1][1] = r[1][0] * base[0][1] + r[1][1] * base[1][1];
				r[0][0] = temp[0][0] % m;
				r[0][1] = temp[0][1] % m;
				r[1][0] = temp[1][0] % m;
				r[1][1] = temp[1][1] % m;
			}
		}
		temp[0][0] = base[0][0] * base[0][0] + base[0][1] * base[1][0];
		temp[0][1] = base[0][0] * base[0][1] + base[0][1] * base[1][1];
		temp[1][0] = base[1][0] * base[0][0] + base[1][1] * base[1][0];
		temp[1][1] = base[1][0] * base[0][1] + base[1][1] * base[1][1];
		base[0][0] = temp[0][0] % m;
		base[0][1] = temp[0][1] % m;
		base[1][0] = temp[1][0] % m;
		base[1][1] = temp[1][1] % m;
		n /= 2;
	}
	return r[0][0];
}

int powIi(int a, int b) {
	int base = 1;
	while(b--) { 
		base *= a;
	}
	return base;
}

void test() {
	printf("1 = %d\n", matrixFastPowxer(2, powIi(2, 20)));
	printf("2 = %d\n", matrixFastPowxer(3, powIi(2, 20)));
	printf("3 = %d\n", matrixFastPowxer(4, powIi(2, 20)));
	printf("5 = %d\n", matrixFastPowxer(5, powIi(2, 20)));
	printf("1 = %d\n", matrixFastPowxer(2147483647, powIi(2, 1)));
	printf("325917 = %d\n", matrixFastPowxer(2147483647, powIi(2, 20)));
	printf("1 = %d\n", matrixFastPowxer(2, powIi(2, 1)));
	printf("1 = %d\n", matrixFastPowxer(2, powIi(2, 20)));
}

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {	
		if(n == 0 || m == 0) {
			printf("0\n");
			continue;
		}
		if(n == 1) {
			printf("1\n");
			continue;
		}
		printf("%d\n", matrixFastPowxer(n, powIi(2, m)));
	}
	return 0;
}

