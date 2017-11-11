 /*
  * @file d283.c
  * @author Jason3e7
  * @algorithm matrix, fast power
  * @date 201711111023
  */ 
 
#include <stdio.h>

int matrixFastPowxer(int n) {
	int base[2][2] = {{1, 1}, {1, 0}};
	int r[2][2], temp[2][2], firstFlag = 1;
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
				r[0][0] = temp[0][0];
				r[0][1] = temp[0][1];
				r[1][0] = temp[1][0];
				r[1][1] = temp[1][1];
			}
		}
		temp[0][0] = base[0][0] * base[0][0] + base[0][1] * base[1][0];
		temp[0][1] = base[0][0] * base[0][1] + base[0][1] * base[1][1];
		temp[1][0] = base[1][0] * base[0][0] + base[1][1] * base[1][0];
		temp[1][1] = base[1][0] * base[0][1] + base[1][1] * base[1][1];
		base[0][0] = temp[0][0];
		base[0][1] = temp[0][1];
		base[1][0] = temp[1][0];
		base[1][1] = temp[1][1];
		n /= 2;
	}
	return r[0][0];
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {	
		if(n == 1) {
			printf("1\n");
			continue;
		}
		printf("%d\n", matrixFastPowxer(n - 1));
	}
	return 0;
}

